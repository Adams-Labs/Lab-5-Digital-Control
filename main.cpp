// A program to demonstrate digital control algorithms that implement the Controller base class.
//
//  main.cpp
//
//  Created by Dale Shpak on 2019-09-02.
//  Copyright Â© 2019 Dale Shpak. All rights reserved.
//

#include <cstdlib>
#include <iostream>
#include <vector>

#include "Plant.hpp"
#include "ProportionalController.hpp"
#include "PID_Controller.hpp"

const int N_STEPS = 50;  // Number of time steps

using namespace std;

int main(int argc, const char * argv[]) {
    // Create a model of a digital plant that has a bit of resonance
    const double num[] = {0.023018459508916,   0.046036919017832,   0.023018459508916};
    const double den[] = {1.000000000000000,  -1.618519638615533,   0.710593476651197};
    Plant p(num, den, 2);  // Instantiate this plant
    
    Controller *controller;
    // You can comment out these two lines after you write your code. (But you don't have to)
    ProportionalController propController(0.3);
    controller = &propController;
    // Use these two lines after you write your code.
    PID_Controller pidController(0.5, 25, 2.5);
    controller = &pidController;  // make the pointer point at the object named pidController
    
    double y = p.plantResponse(0.0);  // Initial output of plant with input of zero
    // Set up the step input to the plant
    const double setpoint = 1.0;
    
    cout << "Y = [" << endl;  // Format output for pasting into MATLAB
    for (int t=0; t < N_STEPS; t++) {
        double plantInput = controller->controlStep(y, setpoint);
        y = p.plantResponse(plantInput);
        cout << plantInput << "  " << y << endl;
    }
    cout << "];" << endl;
    
    return EXIT_SUCCESS;
}