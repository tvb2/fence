#pragma once
#include "vect.h"

class Cosine{
    private:
        Vect mVect;
    public:
        // cos of angle between a vector and axis (cos)
    double cosVect(vec const &vec, char const axis) {
        double len = mVect.length(vec);
        if (len > 0) {
            switch (axis) {
            case 'X':
            return ((double)vec[0] / len);
            break;

            case 'Y':
            return ((double)vec[1] / len);
            break;
            }
        }
        return -1;
        }
    };