//
// Created by Zeyad Osama on 11/14/19.
//

#ifndef TRAIN_AUTOMATION_TRAIN_H
#define TRAIN_AUTOMATION_TRAIN_H

#define HAS_TRAIN 1
#define NO_TRAIN 0

/**
 * @brief station struct definition.
 */
typedef struct {
    /**
     * informative variables.
     */
    int waiting_passengers;
    int available_seats;
    int has_train;

    /**
     * variables for mutual exclusion
     * and synchronization
     */
    pthread_mutex_t mutex_station;
    pthread_cond_t train_in;
    pthread_cond_t train_loaded;
    pthread_cond_t train_next;
} station;

/**
 * @brief train struct definition.
 */
typedef struct {
    station *station;
    int seats;
} train;

/**
 * @brief initialize inner variables of station struct.
 * @param station to be initialized.
 * @see station.
 */
void station_init(station *station);

/**
 * @brief invoked when a train arrives in the station and has opened its doors.
 * The function must not return until the train is satisfactorily loaded.
 * i.e. all passengers are in their seats, and either the train is full or all waiting passengers have boarded.
 *
 * @param station indicates current station.
 * @param count indicates how many seats are available on the train.
 */
void station_load_train(station *station, int count);

/**
 * @brief invoked when a passenger arrives in a station,
 * The function must not return until a train is in the station.
 * Once this function returns passenger will be moved to being on board.
 *
 * i.e.
 * a call to station_load_train is in progress
 * and there are enough free seats on the train for this passenger to sit down.
 *
 * @param station indicates current station.
 */
void station_wait_for_train(station *station);

/**
 * @brief invoked once the passenger is seated. Lets the train know that it's on board.
 * @param station indicates current station.
 */
void station_on_board(station *station);

#endif //TRAIN_AUTOMATION_TRAIN_H
