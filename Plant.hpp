// A linear ARMA model for a plant to be controlled.
//
//  Plant.hpp
//
//  Created by Dale Shpak on 2019-09-02.
//  Copyright © 2019 Dale Shpak. All rights reserved.
//

#ifndef Plant_hpp
#define Plant_hpp

#include <iostream>
#include <vector>  // We will look more at the STL vector class later.

class Plant {
private:
    const long order;  // The order of the system
    std::vector<double> b;  // Numerator polynomial coefficients
    std::vector<double> a;  // Denominator polynomial cofficients
    std::vector<double> state;  // We'll initialize this as a vector of zeros
    
public:
    /**
     * Constructor copies the plant coefficients and initializes the state vector.
     *
     * @param num Array of numerator coefficient
     * @param den Array of denominator coefficients
     * @param order Plant system order
     *
     */
    Plant (const double num[], const double den[], const int order) : b(order+1), a(order+1), state(order+1), order(order) {
        // Copy the coefficients into the coefficient vectors
        for (int k=0; k < order+1; k++) {
            b[k] = num[k];
            a[k] = den[k];
        }
        
        // State vector has one extra element to simplify computation.
        // Initialize it to zeros
        state.assign(state.size(), 0);
    }
    
    /**
     * Compute the current output value from the plant based on the current input
     * and its current state.
     *
     * The plant is implemented as a direct-form II transpose digital filter.
     * See: https://www.dsprelated.com/freebooks/filters/Transposed_Direct_Forms.html
     *
     * @param input Current input value
     *
     * @return Current output value
     **/
    double plantResponse (const double input);
    
};


#endif /* Plant_hpp */