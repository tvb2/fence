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

void TestMinMaxFuncionality(const vecvec &expected){
    std::string filename = "./cases/minmax.json";
    ConverterJSON json(filename);
    Vect forest;
    forest.getTrees(json.getForest());
    forest.findMinMax();
    MinMax minmax = forest.minmax;
    vecvec result = {minmax.xmin, minmax.ymax, minmax.xmax, minmax.ymin};
    
ASSERT_EQ(result, expected);
}


TEST(TestMinMax, MinMax) {
    MinMax minmax;
    minmax.xmin[0] = 2;
    minmax.xmin[1] = 5;

    minmax.ymax[0] = 9;
    minmax.ymax[1] = 8;

    minmax.xmax[0] = 12;
    minmax.xmax[1] = 4;

    minmax.ymin[0] = 6;
    minmax.ymin[1] = 1;
    vecvec expected {minmax.xmin, minmax.ymax, minmax.xmax, minmax.ymin};
	TestMinMaxFuncionality(expected);
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
        {2,5},
        {3,5},
        {4,5}
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
        //expect empty result since xmin == ymax
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

TEST(TestVect, Test151) {
    std::string filename = "./cases/1-5-1.json";
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
        {3,5}
    };
	TestVectFunctionality(result, expected);
}

