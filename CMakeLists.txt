cmake_minimum_required(VERSION 4.1)
project(Projects)

set(CMAKE_CXX_STANDARD 14)

include_directories(NeuralNet_Foundation)

add_executable(Projects
        NeuralNet_Foundation/FirstTest.cpp
        NeuralNet_Foundation/Main_Matrix_Run.cpp
        NeuralNet_Foundation/Matrix.cpp
        NeuralNet_Foundation/Matrix.h
        NeuralNet_Foundation/README.md)
