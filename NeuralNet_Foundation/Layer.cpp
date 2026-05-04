#include "Layer.h"

#include <stdexcept>

#include <cmath> // בשביל sqrt

Layer::Layer(int inputSize, int outputSize) : weights(outputSize, inputSize), bias(outputSize, 1) {
    if (inputSize <= 0 || outputSize <= 0) {
        throw std::invalid_argument("Input or output size must be positive");
    }

    // Initialize weights and bias to break symmetry
    double range = 1.0 / std::sqrt(inputSize);
    weights.randomize(-range, range);
    bias.randomize(-0.01, 0.01);
}

Matrix Layer::forward(const Matrix& input) {

    if (input.getRows() != weights.getCols()) {
        throw std::invalid_argument("Input size does not match weights size");
    }
    this->lastInput = input;
    Matrix res=(weights*input)+bias;
    this->LastZ = res;
    res.applyReLU();
    return res;

}
Matrix Layer::backward(const Matrix& outputGradient, double learningRate) {
    // 1. Local error
    Matrix localError = outputGradient.hadamard(LastZ.reluDerivative());

    // 2. Error for the previous layer
    Matrix errorToPassBack = weights.transpose() * localError;

    // 3. Weight gradients
    Matrix weightGradients = localError * lastInput.transpose();

    // 4. Update weights and bias
    weights = weights - (weightGradients * learningRate);
    bias = bias - (localError * learningRate);

    return errorToPassBack;
}