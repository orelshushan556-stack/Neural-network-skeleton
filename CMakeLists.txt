cmake_minimum_required(VERSION 3.14)
project(Projects)

set(CMAKE_CXX_STANDARD 14)

include_directories(NeuralNet_Foundation)

# התוכנית הראשונה שלך (הטסט של המטריצות בלבד)
add_executable(MatrixTest
        NeuralNet_Foundation/Main_Matrix_Run.cpp
        NeuralNet_Foundation/Matrix.cpp
)

# התוכנית השנייה שלנו (הטסט של השכבה שכתבנו עכשיו)
add_executable(LayerTest
        NeuralNet_Foundation/secondtest.cpp
        NeuralNet_Foundation/Matrix.cpp
        NeuralNet_Foundation/Layer.cpp
)
add_executable(new_target NeuralNet_Foundation/Network.h
        NeuralNet_Foundation/Network.cpp)
