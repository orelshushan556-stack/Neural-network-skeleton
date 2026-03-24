#include "Layer.h"

#include <stdexcept>

#include <cmath> // בשביל sqrt

Layer::Layer(int inputSize, int outputSize) : weights(outputSize, inputSize), bias(outputSize, 1) {
    if (inputSize <= 0 || outputSize <= 0) {
        throw std::invalid_argument("Input or output size must be positive");
    }


    double range = 1.0 / std::sqrt(inputSize);


    weights.randomize(-range, range);


    bias.randomize(-0.01, 0.01);
}

Matrix Layer::forward(const Matrix& input) {
    if (input.getRows() != weights.getCols()) {
        throw std::invalid_argument("Input size does not match weights size");
    }
    Matrix res=(weights*input)+bias;
    res.applyReLU();
    return res;

}