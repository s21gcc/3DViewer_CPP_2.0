cmake_minimum_required(VERSION 3.25)
project(3DViewer_CPP_2_0)

set(CMAKE_CXX_STANDARD 23)

add_executable(3DViewer_CPP_2_0 main.cpp
        model/obj/obj.cc
        model/obj/obj.h
        model/transformer/affine_transformer.cc
        model/transformer/affine_transformer.h
        model/model.cc model/model.h)

