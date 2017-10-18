/**
 * @file fire_manager.h
 * @brief Header file for class and method definitions of the Fire and FireManager classes.
 *
 * We have a fire class to manage the characteristics of a fire pertaining to how it interaction with a city.
 * We then have a fire manager class that defines methods for - wait for it - managing the fire.
 * Or rather, it is charged with managing the state of the fire.
 *
 * @author: Sam Gomena
 * Class: CS202 Fall 2017
 * Instructor: Karla Fant
 */

#ifndef FIRE_H
#define FIRE_H

#include "fire_suppression.h"

class Fire {
    public:
        Fire();
        ~Fire();
        float get_size();
        int get_severity();
        void update_size(float);
        void update_severity(int);
    protected:
        float size;
        int severity;
};

class FireManager : public Fire {
    public:
        FireManager();
        ~FireManager();
        float get_size();
    protected:
        FireSuppression *fs;
        void determine_suppression(int, int);
};

#endif
