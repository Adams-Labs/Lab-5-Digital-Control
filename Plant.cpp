// Implement the functions in Plant.hpp
//
//  Plant.cpp
//  DigitalController
//
//  Created by Dale Shpak on 2019-09-02.
//  Copyright © 2019 Dale Shpak. All rights reserved.
//

#include "Plant.hpp"

double Plant::plantResponse (const double input) {
    double y = b[0]*input + state[0];  // Current output value
    
    // Update states.  (State vector has one extra zero-valued element).
    for (long k=0; k < order; k++) {
        state[k] = state[k+1] + input*b[k+1] - y*a[k+1];
    }
    
    return y;
}