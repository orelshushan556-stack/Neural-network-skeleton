#include "Network.h"

Network::Network(int* layerSizes, int layerSize, double lr) {

    this->numLayers = layerSize - 1;
    this->learningRate = lr;
    this->layers=new Layer*[numLayers];
    for (int i=0; i<numLayers; i++) {
        this->layers[i]=new Layer(layerSizes[i],layerSizes[i+1]);
    }

}

Network::~Network() {
    for (int i=0; i<numLayers; i++) {
        delete this->layers[i];
    }
    delete[] this->layers;

}

Matrix Network::feedForward(const Matrix& input) {
    Matrix currentSignal = input;
    for (int i=0; i<numLayers; i++) {
        currentSignal = layers[i]->forward(currentSignal);
    }
    return currentSignal;



}

void Network::backpropagate(const Matrix& input, const Matrix& target) {
    // 1. Forward pass to record the internal states (lastInput, lastZ) of each layer
    Matrix prediction = feedForward(input);

    // 2. Calculate the initial error at the output layer (Prediction - Target)
    Matrix currentError = prediction - target;

    // 3. Propagate the error backward through the network
    for (int i = numLayers - 1; i >= 0; i--) {
        currentError = layers[i]->backward(currentError, learningRate);
    }
}

void Network::train(Matrix* inputs, Matrix* targets, int numSamples, int epochs) {
    for (int e = 0; e < epochs; e++) {
        // Train on all samples
        for (int i = 0; i < numSamples; i++) {
            backpropagate(inputs[i], targets[i]);
        }

        // Print prediction for the first sample every 1000 epochs
        if (e % 1000 == 0) {
            Matrix prediction = feedForward(inputs[0]);
            prediction.print();
        }
    }
}