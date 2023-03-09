#pragma once
#include <vector>
#include <cmath>

typedef std::vector<std::vector<int>> vecvec;
typedef std::vector<int> vec;

class Vect{
    private:
        vecvec trees;
    public:
    void makevect(vec const &p1, vec const &p2);

    void getTrees(vecvec const &t);

    vecvec outerTrees(vecvec& trees);

    // vector coordinates given two points
    vec vecCoord(vec const &p1, vec const &p2);

    // scalar product of vectors a and b
    int scalarProduct(vec const &a, vec const &b);

    // calculate length of vector given by two coordinates
    double length(vec const &vec);

    void printTrees();

};