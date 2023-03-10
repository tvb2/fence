#include <iostream>
#include "converterjson.h"
#include "vect.h"

int main(int, char**) {
    ConverterJSON json;
    Vect forest;
    forest.getTrees(json.getForest());
    forest.findMinMax();
    forest.printTrees();
    std::cout << "Hello, world!\n";
}
