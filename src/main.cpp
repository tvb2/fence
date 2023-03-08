#include <iostream>
#include "converterjson.h"

int main(int, char**) {
    ConverterJSON json;
    json.getData();
    json.getForest();
    std::cout << "Hello, world!\n";
}
