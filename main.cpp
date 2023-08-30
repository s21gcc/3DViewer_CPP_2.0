#include <iostream>
#include "model/parser/parser.h"
#include "model/transformer/affine_transformer.h"

int main() {
    Parser parser;
    parser.ParseFile("/Users/oznakban/CLionProjects/3DViewer_CPP_2.0/cube.obj");
    std::cout << "finish";
}
