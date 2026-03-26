#pragma once
#include "Layer.h"
#include "Matrix.h"

class Network {
private:
    Layer** layers;
    int numLayers;
    double learningRate;
    // מערך אובייקטים לשמירת התוצאות של כל שכבה (כולל הקלט)
    Matrix* activations;

public:
    Network(int* layerSizes, int layerSize, double lr);
    ~Network();

    Network(const Network&) = delete;
    Network& operator=(const Network&) = delete;

    Matrix feedForward(const Matrix& input);
    void backpropagate(const Matrix& input, const Matrix& target);
    void train(const Matrix& input, const Matrix& target);
};