// Abstract base class for a digital controller.
// The required function that any controller must implement is a controlStep.
//
//  Controller.hpp
//
//  Created by Dale Shpak on 2019-09-02.
//  Copyright Â© 2019 Dale Shpak. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp

class Controller {
public:
    static constexpr double T = 1.0;  // Fix time step size for simplicity
  // If the compiler complains about the preceeding line, use the next line instead (different versions of C++)
  //  static const double deltaT = 1.0;  // Fix time step size for simplicity
    
    /**
     * Execute one iteration of the control algorithm.
     *
     * @param plantOutput most recent output from the plant
     * @param setpoint current setpoint for the plant
     *
     * @return the next input value for the plant
     */
    virtual double controlStep (double plantOutput, double setpoint) = 0;
};


#endif /* Controller_hpp */