#include "Network.h"

Network::Network(int* layerSizes, int layerSize, double lr) {

    this->numLayers = layerSize - 1;
    this->learningRate = lr;
    this->layers=new Layer*[numLayers];
    for (int i=0; i<numLayers; i++) {
        this->layers[i]=new Layer(layerSizes[i],layerSizes[i+1]);
    }
    this->activations = new Matrix[numLayers + 1];
}

Network::~Network() {
    for (int i=0; i<numLayers; i++) {
        delete this->layers[i];
    }
    delete[] this->layers;
    delete[] this->activations;
}

Matrix Network::feedForward(const Matrix& input) {


}

void Network::backpropagate(const Matrix& input, const Matrix& target) {
}

void Network::train(const Matrix& input, const Matrix& target) {
}