/* 
 * File:   PID_Controller.hpp
 * This is the header file for the PID Controller. Contains 
 * the object declaration for the PID Controller. 
 * 
 * Author: Adam Claxton
 *
 * Created on October 16, 2020, 3:19 PM
 */

#ifndef PID_CONTROLLER_HPP
#define PID_CONTROLLER_HPP

#include "Controller.hpp" // include the base controller header file

class PID_Controller : public Controller { // make a class that inherits the controller class  
private: // private variables only used by PID_Controller
    const double kc; // The proportional gain
    const double ti; // Integral Gain 
    const double td; // Derivative Gain 
    double qPrev = 0; // double to hold the q((n-1)T) value
    double prevPlantOutput = 0; // double to hold y((n-1)T) value
    
public:
    
    //function prototype of PID_COntroller that gets passes K, Ti and Td so they can be used by ControlStep
    PID_Controller (const double propGain, const double integralGain, const double derGain) : kc(propGain), ti(integralGain), td(derGain){}; 
    
    // Our promise to implement the function from the abstract base class
    double controlStep (double plantOutput, double setpoint);
};

#endif /* PID_CONTROLLER_HPP */

