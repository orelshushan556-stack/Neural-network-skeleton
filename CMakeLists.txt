cmake_minimum_required(VERSION 3.14)
project(NeuralNetProject)

set(CMAKE_CXX_STANDARD 14)

# Header search path
include_directories(NeuralNet_Foundation)

# Test 1: Matrix
add_executable(FirstTest
        NeuralNet_Foundation/FirstTest.cpp
        NeuralNet_Foundation/Matrix.cpp
)

# Test 2: Layer
add_executable(LayerTest
        NeuralNet_Foundation/secondtest.cpp
        NeuralNet_Foundation/Matrix.cpp
        NeuralNet_Foundation/Layer.cpp
)

# Test 3: Network (XOR)
add_executable(NetworkTarget
        NeuralNet_Foundation/Main_Matrix_Run.cpp
        NeuralNet_Foundation/Network.cpp
        NeuralNet_Foundation/Layer.cpp
        NeuralNet_Foundation/Matrix.cpp
)