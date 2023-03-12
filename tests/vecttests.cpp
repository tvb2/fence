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

TEST(TestVect, Test15) {
    std::string filename = "./cases/1-5.json";
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

TEST(TestVect, Test16) {
    std::string filename = "./cases/1-6.json";
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
        {2,1},
        {3,1}
    };
	TestVectFunctionality(result, expected);
}

TEST(TestVect, Test17) {
    std::string filename = "./cases/1-7.json";
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
        {3,5},
        {4,6}
    };
	TestVectFunctionality(result, expected);
}

TEST(TestVect, Test41) {
    std::string filename = "./cases/4-1.json";
    ConverterJSON json(filename);
    Vect forest;
    forest.getTrees(json.getForest());
    forest.findMinMax();
    vec current  = forest.minmax.ymax;
    vec target = forest.minmax.xmax;
    vec direct = forest.vecCoord(current,target);
    double minCos = forest.cosVect(direct);

    forest.findRouteIV(minCos,current,target);
    std::map<std::vector<int>, int> fence = forest.getFenceMap();
    vecvec result;
    for (auto it = fence.begin(); it != fence.end(); ++it){
        vec temp = {it->first[0], it->first[1]};
        result.emplace_back(temp);
    }
    vecvec expected = {//except the first and last trees
        {5,4},
        {6,3},
        {7,2}
    };
	TestVectFunctionality(result, expected);
}

TEST(TestVect, Test42) {
    std::string filename = "./cases/4-2.json";
    ConverterJSON json(filename);
    Vect forest;
    forest.getTrees(json.getForest());
    forest.findMinMax();
    vec current  = forest.minmax.ymax;
    vec target = forest.minmax.xmax;
    vec direct = forest.vecCoord(current,target);
    double minCos = forest.cosVect(direct);

    forest.findRouteIV(minCos,current,target);
    std::map<std::vector<int>, int> fence = forest.getFenceMap();
    vecvec result;
    for (auto it = fence.begin(); it != fence.end(); ++it){
        vec temp = {it->first[0], it->first[1]};
        result.emplace_back(temp);
    }
    vecvec expected = {//except the first and last trees
        {7,3},
        {7,4}
    };
	TestVectFunctionality(result, expected);
}

TEST(TestVect, Test43) {
    std::string filename = "./cases/4-3.json";
    ConverterJSON json(filename);
    Vect forest;
    forest.getTrees(json.getForest());
    forest.findMinMax();
    vec current  = forest.minmax.ymax;
    vec target = forest.minmax.xmax;
    vec direct = forest.vecCoord(current,target);
    double minCos = forest.cosVect(direct);

    forest.findRouteIV(minCos,current,target);
    std::map<std::vector<int>, int> fence = forest.getFenceMap();
    vecvec result;
    for (auto it = fence.begin(); it != fence.end(); ++it){
        vec temp = {it->first[0], it->first[1]};
        result.emplace_back(temp);
    }
    vecvec expected = {//except the first and last trees
        {5,4},
        {6,3}
    };
	TestVectFunctionality(result, expected);
}

TEST(TestVect, Test44) {
    std::string filename = "./cases/4-4.json";
    ConverterJSON json(filename);
    Vect forest;
    forest.getTrees(json.getForest());
    forest.findMinMax();
    vec current  = forest.minmax.ymax;
    vec target = forest.minmax.xmax;
    vec direct = forest.vecCoord(current,target);
    double minCos = forest.cosVect(direct);

    forest.findRouteIV(minCos,current,target);
    std::map<std::vector<int>, int> fence = forest.getFenceMap();
    vecvec result;
    for (auto it = fence.begin(); it != fence.end(); ++it){
        vec temp = {it->first[0], it->first[1]};
        result.emplace_back(temp);
    }
    vecvec expected = {//except the first and last trees
        {6,4}
    };
	TestVectFunctionality(result, expected);
}

TEST(TestVect, Test31) {
    std::string filename = "./cases/3-1.json";
    ConverterJSON json(filename);
    Vect forest;
    forest.getTrees(json.getForest());
    forest.findMinMax();
    vec current  = forest.minmax.xmax;
    vec target = forest.minmax.ymin;
    vec direct = forest.vecCoord(current,target);
    double minCos = forest.cosVect(direct);

    forest.findRouteIII(minCos,current,target);
    std::map<std::vector<int>, int> fence = forest.getFenceMap();
    vecvec result;
    for (auto it = fence.begin(); it != fence.end(); ++it){
        vec temp = {it->first[0], it->first[1]};
        result.emplace_back(temp);
    }
    vecvec expected = {//except the first and last trees
        {4,1}
    };
	TestVectFunctionality(result, expected);
}

TEST(TestVect, Test32) {
    std::string filename = "./cases/3-2.json";
    ConverterJSON json(filename);
    Vect forest;
    forest.getTrees(json.getForest());
    forest.findMinMax();
    vec current  = forest.minmax.xmax;
    vec target = forest.minmax.ymin;
    vec direct = forest.vecCoord(current,target);
    double minCos = forest.cosVect(direct);

    forest.findRouteIII(minCos,current,target);
    std::map<std::vector<int>, int> fence = forest.getFenceMap();
    vecvec result;
    for (auto it = fence.begin(); it != fence.end(); ++it){
        vec temp = {it->first[0], it->first[1]};
        result.emplace_back(temp);
    }
    vecvec expected = {//except the first and last trees
        {3,2},
        {4,3}
    };
	TestVectFunctionality(result, expected);
}

TEST(TestVect, Test33) {
    std::string filename = "./cases/3-3.json";
    ConverterJSON json(filename);
    Vect forest;
    forest.getTrees(json.getForest());
    forest.findMinMax();
    vec current  = forest.minmax.xmax;
    vec target = forest.minmax.ymin;
    vec direct = forest.vecCoord(current,target);
    double minCos = forest.cosVect(direct);

    forest.findRouteIII(minCos,current,target);
    std::map<std::vector<int>, int> fence = forest.getFenceMap();
    vecvec result;
    for (auto it = fence.begin(); it != fence.end(); ++it){
        vec temp = {it->first[0], it->first[1]};
        result.emplace_back(temp);
    }
    vecvec expected = {//except the first and last trees
        {3,1},
        {4,3}
    };
	TestVectFunctionality(result, expected);
}

TEST(TestVect, Test21) {
    std::string filename = "./cases/2-1.json";
    ConverterJSON json(filename);
    Vect forest;
    forest.getTrees(json.getForest());
    forest.findMinMax();
    vec current  = forest.minmax.ymin;
    vec target = forest.minmax.xmin;
    vec direct = forest.vecCoord(current,target);
    double maxCos = forest.cosVect(direct);

    forest.findRouteII(maxCos,current,target);
    std::map<std::vector<int>, int> fence = forest.getFenceMap();
    vecvec result;
    for (auto it = fence.begin(); it != fence.end(); ++it){
        vec temp = {it->first[0], it->first[1]};
        result.emplace_back(temp);
    }
    vecvec expected = {//except the first and last trees
        {1,3},
        {2,2}
    };
	TestVectFunctionality(result, expected);
}

TEST(TestVect, Test22) {
    std::string filename = "./cases/2-2.json";
    ConverterJSON json(filename);
    Vect forest;
    forest.getTrees(json.getForest());
    forest.findMinMax();
    vec current  = forest.minmax.ymin;
    vec target = forest.minmax.xmin;
    vec direct = forest.vecCoord(current,target);
    double maxCos = forest.cosVect(direct);

    forest.findRouteII(maxCos,current,target);
    std::map<std::vector<int>, int> fence = forest.getFenceMap();
    vecvec result;
    for (auto it = fence.begin(); it != fence.end(); ++it){
        vec temp = {it->first[0], it->first[1]};
        result.emplace_back(temp);
    }
    vecvec expected = {//except the first and last trees
        {2,3},
        {3,2}
    };
	TestVectFunctionality(result, expected);
}

TEST(TestVect, Test23) {
    std::string filename = "./cases/2-3.json";
    ConverterJSON json(filename);
    Vect forest;
    forest.getTrees(json.getForest());
    forest.findMinMax();
    vec current  = forest.minmax.ymin;
    vec target = forest.minmax.xmin;
    vec direct = forest.vecCoord(current,target);
    double maxCos = forest.cosVect(direct);

    forest.findRouteII(maxCos,current,target);
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

