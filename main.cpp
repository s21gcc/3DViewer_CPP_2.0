#include <iostream>
#include "model/model.h"

int main() {
    Model _3d_obj;
    _3d_obj.ParseObj("/Users/oznakban/CLionProjects/3DViewer_CPP_2.0/cube.obj");
    _3d_obj.RotateZ(10);
    _3d_obj.PrintV();
}
