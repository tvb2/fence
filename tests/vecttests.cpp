#include <vector>
#include <string>
#include "vect.h"
#include "converterjson.h"
#include "gtest/gtest.h"
#include <sstream>
#include <filesystem>

void TestVectFunctionality(const vecvec &result, const vecvec &expected) {

ASSERT_EQ(result, expected);
}


TEST(TestVect, Test11) {
    std::string filename = "./cases/1-1.json";
    ConverterJSON json(filename);
    Vect forest;
    forest.getTrees(json.getForest());
    forest.findMinMax();
    vec current  = forest.minmax.xmin;
    vec target = forest.minmax.ymax;
    vec direct = forest.vecCoord(current,target);
    double maxCos = forest.cosVect(direct);

    forest.findRouteI(maxCos,current,target);
    std::map<std::vector<int>, int> fence = forest.getFenceMap();
    vecvec result;
    for (auto it = fence.begin(); it != fence.end(); ++it){
        vec temp = {it->first[0], it->first[1]};
        result.emplace_back(temp);
    }
    vecvec expected = {//except the first and last trees
        {1,2},
        {1,3},
        {3,4}
    };
	TestVectFunctionality(result, expected);
}

TEST(TestVect, Test12) {
    std::string filename = "./cases/1-2.json";
    ConverterJSON json(filename);
    Vect forest;
    forest.getTrees(json.getForest());
    forest.findMinMax();
    vec current  = forest.minmax.xmin;
    vec target = forest.minmax.ymax;
    vec direct = forest.vecCoord(current,target);
    double maxCos = forest.cosVect(direct);

    forest.findRouteI(maxCos,current,target);
    std::map<std::vector<int>, int> fence = forest.getFenceMap();
    vecvec result;
    for (auto it = fence.begin(); it != fence.end(); ++it){
        vec temp = {it->first[0], it->first[1]};
        result.emplace_back(temp);
    }
    vecvec expected = {//except the first and last trees
        {1,2},
        {1,3}
    };
	TestVectFunctionality(result, expected);
}

TEST(TestVect, Test13) {
    std::string filename = "./cases/1-3.json";
    ConverterJSON json(filename);
    Vect forest;
    forest.getTrees(json.getForest());
    forest.findMinMax();
    vec current  = forest.minmax.xmin;
    vec target = forest.minmax.ymax;
    vec direct = forest.vecCoord(current,target);
    double maxCos = forest.cosVect(direct);

    forest.findRouteI(maxCos,current,target);
    std::map<std::vector<int>, int> fence = forest.getFenceMap();
    vecvec result;
    for (auto it = fence.begin(); it != fence.end(); ++it){
        vec temp = {it->first[0], it->first[1]};
        result.emplace_back(temp);
    }
    vecvec expected = {//except the first and last trees
        {2,2},
        {3,3}
    };
	TestVectFunctionality(result, expected);
}

TEST(TestVect, Test14) {
    std::string filename = "./cases/1-4.json";
    ConverterJSON json(filename);
    Vect forest;
    forest.getTrees(json.getForest());
    forest.findMinMax();
    vec current  = forest.minmax.xmin;
    vec target = forest.minmax.ymax;
    vec direct = forest.vecCoord(current,target);
    double maxCos = forest.cosVect(direct);

    forest.findRouteI(maxCos,current,target);
    std::map<std::vector<int>, int> fence = forest.getFenceMap();
    vecvec result;
    for (auto it = fence.begin(); it != fence.end(); ++it){
        vec temp = {it->first[0], it->first[1]};
        result.emplace_back(temp);
    }
    vecvec expected = {//except the first and last trees
        {2,4},
        {3,5}
    };
	TestVectFunctionality(result, expected);
}
