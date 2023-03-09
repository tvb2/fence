#include <iostream>
#include "converterjson.h"

int main(int, char**) {
    ConverterJSON json;
    // json.getData();
    // json.getForest();
    std::vector<int> t{43,78};
    json.addtree(t);
    std::cout << "Hello, world!\n";
}
