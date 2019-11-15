//
// Created by Zeyad Osama on 11/14/19.
//

#include <stdio.h>
#include <pthread.h>
#include "train.h"

/**
 * @brief inner function for initializing informative variables of station
 * @param station
 */
void init_variables(station *station) {
    station->waiting_passengers = 0;
    station->available_seats = 0;
    station->has_train = NO_TRAIN;
}

/**
 * @brief inner function for initializing variables for mutual exclusion and synchronization of station
 * @param station
 */
void init_mutex(station *station) {
    pthread_mutex_init(&station->mutex_station, NULL);
    pthread_cond_init(&station->train_in, NULL);
    pthread_cond_init(&station->train_loaded, NULL);
    pthread_cond_init(&station->train_next, NULL);
}

void station_init(station *station) {
    init_variables(station);
    init_mutex(station);
}

void station_load_train(station *station, int count) {
    // station functionality is exclusively locked for current invocation.
    pthread_mutex_lock(&station->mutex_station);

    //While that the flag is held up ! (Another Train in Station)
    while (station->has_train == HAS_TRAIN)
        pthread_cond_wait(&(station->train_next), &(station->mutex_station));

    // keep track of entered train count.
    static int cnt_trains = 0;

    station->available_seats = count;
    station->has_train = HAS_TRAIN;
    cnt_trains++;
    printf("station:: train arrived:: %d\n", cnt_trains);

    // a train has arrived.
    // signal all waiting passengers.
    pthread_cond_broadcast(&(station->train_in));

    // wait while the station's available seats and waiting passengers count is not yet full.
    while ((station->available_seats > 0) && (station->waiting_passengers > 0))
        pthread_cond_wait(&(station->train_loaded), &station->mutex_station);

    station->has_train = NO_TRAIN;
    printf("train:: %d%s train leaving station with %d seats left.\n", cnt_trains,
           (cnt_trains == 1) ? "st" : (cnt_trains == 2) ? "nd" : (cnt_trains == 3) ? "rd" : "th",
           station->available_seats);

    // current train is satisfactory occupied.
    // send signal to next train to arrive.
    pthread_cond_signal(&(station->train_next));

    pthread_mutex_unlock(&station->mutex_station);
}

void station_wait_for_train(station *station) {
    // station functionality is exclusively locked for current invocation.
    // will be unlocked when passenger on board.
    pthread_mutex_lock(&station->mutex_station);

    // waiting passenger number increased,
    station->waiting_passengers++;
    printf("station:: passengers waiting count:: %d\n", station->waiting_passengers);

    // no train in station or no left seats.
    while (station->has_train == NO_TRAIN || station->available_seats == 0)
        pthread_cond_wait(&(station->train_in), &(station->mutex_station));

    if (station->waiting_passengers > 0)
        station->waiting_passengers--;
}

void station_on_board(station *station) {
    // passenger boarded.
    // available seats decreased.
    if (station->available_seats > 0)
        station->available_seats--;
    printf("train:: current remaining seats:: %d \n", station->available_seats);
    pthread_cond_signal(&(station->train_loaded));

    // previously locked when passenger was waiting for train.
    pthread_mutex_unlock(&station->mutex_station);
}
