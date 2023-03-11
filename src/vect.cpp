#include "vect.h"
#include <iostream>

    void Vect::makevect(vec const &p1, vec const &p2){}

    void Vect::getTrees(vecvec const &t){
        this->trees = t;
    }


    // find min route in the I area
    void Vect::findRouteI(double &cos,vec &current, vec &target) {
        vec next = target;
        bool foundV{false}, found{false};
        double cosTemp{0};
        std::map<int,int> buffer;
        for (auto tree:trees){
            if (tree[0] >= current[0] && tree[1] > current[1] && tree[0] <= target[0] && tree != target){
                if (tree[0] == current[0]){
                    buffer[tree[1]] = current[0];
                    foundV = true;
                }
                if (!foundV && tree != target){
                    cosTemp = cosVect(vecCoord(current,tree));
                    if (cosTemp <= cos){
                        cos = cosTemp;
                        next = tree;
                        found = true;
                    }
                }
            }
        }
        if (!buffer.empty()){
            for (auto it = buffer.begin(); it != buffer.end(); ++it){
                vec temp = {it->second, it->first};
                fenceMap.emplace(std::pair<std::vector<int>,int>(temp,1));
                next = temp;
            }
        }
        if (!foundV && !found)
            return;
        cos = cosVect(vecCoord(next,target));
        fenceMap.emplace(std::pair<std::vector<int>,int>(next,1));
        findRouteI(cos, next, target);
    }


    vecvec Vect::erectFence() {
        //if there are only three trees or less, then the fence will go through all of them
        if (trees.size() <= 3)
            return trees;

        //search route from xmin to xmax
        vec current  = minmax.xmin;
        vec target = minmax.ymax;
        fenceMap.emplace(std::pair<std::vector<int>,int>(current,1));
        if (current != target){
            fenceMap.emplace(std::pair<std::vector<int>,int>(target,1));
            vec direct = vecCoord(current,target);
            double maxCos = cosVect(direct);
            findRouteI(maxCos, current, target);
        }
        for (auto it = fenceMap.begin(); it != fenceMap.end(); ++it)
            std::cout << "map: " << it->first[0] << ", " << it->first[1] << "\n";
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

    double Vect::cosVect(vec const &vec) {
        double len = length(vec);
        if (len > 0) {
            return ((double)vec[0] / len);
        }
        return -1;
    }

    void Vect::printTrees(){
        for (auto item:this->trees)
            std::cout << "item: " << item[0] << ", " << item[1] << "\n";
    }
