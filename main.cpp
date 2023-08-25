#include <iostream>
#include "model/parser.h"

int main() {
    Parser parser;
    parser.ParseFile("/Users/oznakban/CLionProjects/3DViewer_CPP_2.0/cube.obj");
    std::cout << "finish";
}
