#include "vect.h"
#include <iostream>

    void Vect::makevect(vec const &p1, vec const &p2){}

    void Vect::getTrees(vecvec const &t){
        this->trees = t;
    }

    vecvec Vect::erectFence() {
        //if there are only three trees or less, then the fence will go through all of them
        if (trees.size() <= 3)
            return trees;
        

        return fence;
    }

    /**
     * @brief define outstanding trees (xmin, xmax, ymin and ymax)
     * 
     */
    void Vect::findMinMax(){
        for (auto tree:trees){
            if (tree[0] < minmax.xmin[0]) {
                minmax.xmin[0] = tree[0];
                minmax.xmin[1] = tree[1];
            }
            if (tree[1] < minmax.ymin[1]) {
                minmax.ymin[1] = tree[1];
                minmax.ymin[0] = tree[0];
            }
            if (tree[0] > minmax.xmax[0]) {
                minmax.xmax[0] = tree[0];
                minmax.xmax[1] = tree[1];
            }
            if (tree[1] > minmax.ymax[1]) {
                minmax.ymax[1] = tree[1];
                minmax.ymax[0] = tree[0];
            }
        }
    }

    // vector coordinates given two points
    vec Vect::vecCoord(vec const &p1, vec const &p2) {
        vec output(2);
        for (int i = 0; i < p1.size(); ++i) {
            output[i] = p2[i] - p1[i];
        }
        return output;
    }

    // scalar product of vectors a and b
    int Vect::scalarProduct(vec const &a, vec const &b) {
        return (a[0] * b[0] + a[1] * b[1]);
    }

    // calculate length of vector given by two coordinates
    double Vect::length(vec const &vec) {
        return sqrt(pow((double)vec[1], 2) + pow((double)vec[0], 2));
    }

    void Vect::printTrees(){
        for (auto item:this->trees)
            std::cout << "item: " << item[0] << ", " << item[1] << "\n";
    }
