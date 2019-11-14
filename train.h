//
// Created by Zeyad Osama on 11/14/19.
//

#ifndef TRAIN_AUTOMATION_TRAIN_H
#define TRAIN_AUTOMATION_TRAIN_H

#define FLAG_UP 1
#define FLAG_DOWN 0

/**
 * station struct definition.
 */
typedef struct {

} station;

void station_init(station *station);

void station_load_train(station *station, int count);

void station_wait_for_train(station *station);

void station_on_board(station *station);

#endif //TRAIN_AUTOMATION_TRAIN_H
