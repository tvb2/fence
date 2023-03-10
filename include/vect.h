#pragma once
#include <vector>
#include <cmath>
#include <string>

typedef std::vector<std::vector<int>> vecvec;
typedef std::vector<int> vec;

//forest boundaries (most outstanding trees)
//per taask, 0 < Xi, Yi < 100
struct MinMax {
  vec xmin = {100, 0};
  vec xmax = {0, 0};
  vec ymin = {0, 100};
  vec ymax = {0, 0};
};

class Vect{
    private:
        vecvec trees;
        MinMax minmax;
        vecvec fence;
        char quadrant = 'I';
    public:

    void makevect(vec const &p1, vec const &p2);

    void getTrees(vecvec const &t);

    vecvec erectFence();

    /**
     * @brief define outstanding trees (xmin, xmax, ymin and ymax)
     * 
     */
    void findMinMax();

    // vector coordinates given two points
    vec vecCoord(vec const &p1, vec const &p2);

    // scalar product of vectors a and b
    int scalarProduct(vec const &a, vec const &b);

    // calculate length of vector given by two coordinates
    double length(vec const &vec);

    // cos of angle between a vector and axis (cos)
    double cosVect(vec const &vec);

    void printTrees();

};