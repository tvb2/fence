#include <iostream>
#include "converterjson.h"
#include "vect.h"

int main(int, char**) {
    std::string file = "config.json";
    ConverterJSON json(file);
    Vect forest;
    forest.getTrees(json.getForest());
    forest.findMinMax();
    forest.erectFence();
    // forest.printTrees();
    std::cout << "Hello, world!\n";
}
