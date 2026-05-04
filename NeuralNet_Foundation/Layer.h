#pragma once

#include "Matrix.h"

class Layer {
private:
    Matrix weights;
    Matrix bias;
    Matrix lastInput;
    Matrix LastZ;

public:
    Layer(int inputSize, int outputSize);
    Matrix forward(const Matrix& input);
    Matrix backward(const Matrix& outputGradient, double learningRate);
};