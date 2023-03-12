#include "vect.h"
#include <iostream>
#include <functional>
#include "predicates.h"

    void Vect::makevect(vec const &p1, vec const &p2){}

    void Vect::getTrees(vecvec const &t){
        this->trees = t;
    }

    // find min route in each area (I, II, III and IV)
    void Vect::findRoute(
        double &cos,
        vec &starting, 
        vec &target, 
        bool (*isValidTree)(const vec &tree, const vec &starting, const vec &target),
        bool (*isBetterCosine)(const double &cos, const double &cosTemp)
        ){
        vec next = target;
        bool foundBetter{false}, foundEqual{false};
        double cosTemp{0};
        std::map<int,int> path;
        for (auto tree:trees){
            if (isValidTree(tree, starting, target)){
                if (tree != starting){
                    cosTemp = cosVect(vecCoord(starting,tree));
                    if (isBetterCosine(cos, cosTemp)){//cosTemp is better than cos
                        cos = cosTemp;
                        next = tree;
                        path.clear();
                        path[tree[0]] = tree[1];
                        foundBetter = true;
                        foundEqual = false;
                    }
                    else if(std::fabs(cos - cosTemp) < std::numeric_limits<double>::epsilon()){//cosTemp is equal to cos
                        foundEqual = true;
                        cos = cosTemp;
                        next = tree;
                        path[tree[0]] = tree[1];
                    }
                }
            }
        }
        if (!foundBetter && !foundEqual)
            return;
        if (!path.empty()){
            for (auto it = path.begin(); it != path.end(); ++it){
                vec temp = {it->first, it->second};
                fenceMap.emplace(std::pair<std::vector<int>,int>(temp,1));
                next = temp;
            }
        }
        cos = cosVect(vecCoord(next,target));
        findRoute(cos, next, target, (*isValidTree), (*isBetterCosine));
    }

    vecvec Vect::erectFence() {
        //if there are only three trees or less, then the fence will go through all of them
        if (trees.size() <= 3)
            return trees;
        std::vector<std::vector<std::vector<int>>> pairs = {
            {minmax.xmin, minmax.ymax},
            {minmax.ymax, minmax.xmax},
            {minmax.xmax, minmax.ymin},
            {minmax.ymin, minmax.xmin}
        };
        int quadrant = 0;
        for (auto pair:pairs){
            ++quadrant;
            vec starting  = {pair[0]},target = {pair[1]};
            fenceMap.emplace(std::pair<std::vector<int>,int>(starting,1));
            if (starting != target){
                fenceMap.emplace(std::pair<std::vector<int>,int>(target,1));
                vec direct = vecCoord(starting,target);
                double cosInit = cosVect(direct);
                switch (quadrant)
                {
                case 1://quadrant I
                    findRoute(cosInit, starting, target, validTreeI, isBetterCosine12);                    
                    break;
                case 2://quadrant IV
                    findRoute(cosInit, starting, target,validTreeIV, isBetterCosine34);
                    break;
                case 3://quadrant III
                    findRoute(cosInit, starting, target,validTreeIII, isBetterCosine34);
                    break;
                case 4://quadrant II
                    findRoute(cosInit, starting, target,validTreeII, isBetterCosine12);
                    break;
                default:
                    break;
                }
            }
        };
        // std::cout << "after Q-II pass: \n";
        // for (auto it = fenceMap.begin(); it != fenceMap.end(); ++it)
        //     std::cout << "\tmap: " << it->first[0] << ", " << it->first[1] << "\n";
        for (auto it = fenceMap.begin(); it != fenceMap.end(); ++it)
            // vec temp = {it->first, it->second};
            fence.emplace_back(it->first);
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
            else if (tree[0] == minmax.xmin[0]){//choosing xmin with maximum Y
                if (tree[1] > minmax.xmin[1]){
                    minmax.xmin[1] = tree[1];
                }
            }
            if (tree[1] < minmax.ymin[1]) {
                minmax.ymin[1] = tree[1];
                minmax.ymin[0] = tree[0];
            }
            else if (tree[1] == minmax.ymin[1]){//choosing ymin with maximum X
                if (tree[0] < minmax.ymin[0]){
                    minmax.ymin[0] = tree[0];
                }
            }
            if (tree[0] > minmax.xmax[0]) {
                minmax.xmax[0] = tree[0];
                minmax.xmax[1] = tree[1];
            }
            else if (tree[0] == minmax.xmax[0]){//choosing xmax with minimum Y
                if (tree[1] < minmax.xmax[1]){
                    minmax.xmax[1] = tree[1];
                }
            }
            if (tree[1] > minmax.ymax[1]) {
                minmax.ymax[1] = tree[1];
                minmax.ymax[0] = tree[0];
            }
            else if (tree[1] == minmax.ymax[1]){//choosing ymax with maximum X
                if (tree[0] > minmax.ymax[0]){
                    minmax.ymax[0] = tree[0];
                }
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
