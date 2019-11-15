///
/// main.c
/// Train Automation
///
/// @author Zeyad Osama.
/// @date 2019-11-14.
/// @copyright © 2019 Zeyad Osama. All rights reserved.
///

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>
#include "train.h"

/**
 * @brief passenger threading function.
 */
void *pthread_passenger(void *args);

/**
 * @brief train threading function.
 */
void *pthread_train(void *args);

/**
 * @brief utility function to scan int from stdin with overflow prevention.
 * @return scanned int value.
 */
int scan_stdin();

int main() {
    // initialize station.
    station station;
    station_init(&station);

    // get passengers count.
    printf("> enter number of passengers: ");
    int cnt_passengers = scan_stdin();
    // get trains count.
    printf("> enter number of trains: ");
    int cnt_trains = scan_stdin();

    // initialize trains.
    int total_seats = 0;
    train trains[cnt_trains];
    for (int i = 1; i < cnt_trains + 1; i++) {
        printf("> enter number of seats for %d%s train: ", i,
               (i == 1) ? "st" : (i == 2) ? "nd" : (i == 3) ? "rd" : "th");
        trains[i - 1].seats = scan_stdin();
        trains[i - 1].station = &station;
        total_seats += trains[i - 1].seats;
    }

    // error handling.
    if (total_seats < cnt_passengers) {
        fprintf(stderr, "error:: total number of seats will not satisfy all passengers.\n");
        fprintf(stderr, "risk:: a batch of %d passenger will only be taken.\n", total_seats);
        cnt_passengers = total_seats;
    }

    // initialize threads variables.
    pthread_t pthread_t_train[cnt_trains];
    pthread_t pthread_t_passenger[cnt_passengers];

    // threads creation.
    for (int i = 0; i < cnt_passengers; ++i)
        pthread_create(&pthread_t_passenger[i], NULL, pthread_passenger, &station);
    for (int i = 0; i < cnt_trains; ++i)
        pthread_create(&pthread_t_train[i], NULL, pthread_train, &trains[i]);

    // threads joining.
    for (int i = 0; i < cnt_passengers; ++i)
        pthread_join(pthread_t_passenger[i], NULL);
    for (int i = 0; i < cnt_trains; ++i)
        pthread_join(pthread_t_train[i], NULL);

    return 0;
}

void *pthread_passenger(void *args) {
    station *station = args;
    station_wait_for_train(station);
    station_on_board(station);
    pthread_exit(NULL);
}

void *pthread_train(void *args) {
    train *train = args;
    station_load_train(train->station, train->seats);
    pthread_exit(NULL);
}

int scan_stdin() {
    const int INPUT_SIZE = 30;
    char *ptr;
    int ret;
    char str[INPUT_SIZE];
    fgets(str, INPUT_SIZE, stdin);
    ret = (int) strtol(str, &ptr, 10);
    if (ret == INT_MAX || ret == INT_MIN)
        perror("error");
    return ret;
}
