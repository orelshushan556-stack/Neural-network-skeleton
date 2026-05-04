#pragma once
#include "Layer.h"
#include "Matrix.h"

class Network {
private:
    Layer** layers;
    int numLayers;
    double learningRate;


public:
    Network(int* layerSizes, int layerSize, double lr);
    ~Network();

    Network(const Network&) = delete;
    Network& operator=(const Network&) = delete;

    Matrix feedForward(const Matrix& input);
    void backpropagate(const Matrix& input, const Matrix& target);
    void train(Matrix* inputs, Matrix* targets, int numSamples, int epochs);
};