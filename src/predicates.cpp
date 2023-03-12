#include "predicates.h"

bool validTreeI(const std::vector<int> &tree, const std::vector<int> &starting, const std::vector<int> &target){
    return tree[0] > starting[0] && tree[1] >= starting[1] && tree[0] < target[0] && tree != target;
}
bool validTreeII(const std::vector<int> &tree, const std::vector<int> &starting, const std::vector<int> &target){
    return tree[0] <= starting[0] && tree[1] > starting[1] && tree[1] < target[1] && tree != target;
}
bool validTreeIII(const std::vector<int> &tree, const std::vector<int> &starting, const std::vector<int> &target){
    return tree[0] < starting[0] && tree[1] <= starting[1] && tree[0] > target[0] && tree != target;
}
bool validTreeIV(const std::vector<int> &tree, const std::vector<int> &starting, const std::vector<int> &target){
    return tree[0] >= starting[0] && tree[1] > target[1] && tree[1] < starting[1] && tree != target;
}

bool isBetterCosine12(const double &cos, const double &cosTemp){
    return ((cos - cosTemp) > std::numeric_limits<double>::epsilon());
}
bool isBetterCosine34(const double &cos, const double &cosTemp){
        return ((cosTemp - cos) > std::numeric_limits<double>::epsilon());
    }
