#include <iostream>
#include <ctime>
#include "Network.h"
#include "Matrix.h"

int main() {
    // 1. Set seed for reproducible results
    srand(static_cast<unsigned>(time(0)));

    // 2. Network setup: 2 inputs, 8 hidden neurons, 1 output
    int layerSizes[] = {2, 8, 1};
    Network net(layerSizes, 3, 0.1);

    // 3. XOR inputs
    Matrix inputs[4];
    for (int i = 0; i < 4; i++) inputs[i] = Matrix(2, 1);

    inputs[0](0, 0) = 0; inputs[0](1, 0) = 0;
    inputs[1](0, 0) = 0; inputs[1](1, 0) = 1;
    inputs[2](0, 0) = 1; inputs[2](1, 0) = 0;
    inputs[3](0, 0) = 1; inputs[3](1, 0) = 1;

    // 4. XOR targets
    Matrix targets[4];
    for (int i = 0; i < 4; i++) targets[i] = Matrix(1, 1);

    targets[0](0, 0) = 0;
    targets[1](0, 0) = 1;
    targets[2](0, 0) = 1;
    targets[3](0, 0) = 0;

    // 5. Train with more epochs for stability
    std::cout << "Starting training..." << std::endl;
    net.train(inputs, targets, 4, 20000);
    std::cout << "Training complete!\n" << std::endl;

    // 6. Test results
    std::cout << "Final Predictions:" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << "In: " << inputs[i](0, 0) << "," << inputs[i](1, 0) << " -> Out: ";
        Matrix prediction = net.feedForward(inputs[i]);
        prediction.print();
    }

    return 0;
}