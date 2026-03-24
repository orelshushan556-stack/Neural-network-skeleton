#pragma once

#include "Matrix.h"

class Layer {
private:
    Matrix weights;
    Matrix bias;

public:
    Layer(int inputSize, int outputSize);
    Matrix forward(const Matrix& input);
};