/* 
 * File:   PID_Controller.cpp
 * 
 * This is the .cpp file for the PID Controller. Contains 
 * the function for control step using the PID Controller. 
 * 
 * Author: Adam Claxton
 *
 * Created on October 16, 2020, 3:19 PM
 */

#include "PID_Controller.hpp" // include the PID header file 

// Implementation of controlStep() with PID Controller 
double PID_Controller::controlStep (const double plantOutput, double setpoint) {
    
    double e = (setpoint - plantOutput); // find the e(nT) part of the PID Equation
    double qCurrent = (0.9*qPrev) + (0.1*e); // find the q(nT) term of the PID Equation
    // implements the PID Equation: x(nT) = s(nT) + kc*(e(nT) + (T/ti)*q(nT) - (td/T)*(y(nT) - y((n-1)T)))
    double output = setpoint + kc*(e + ((T/ti)*qCurrent) - ((td/T)*(plantOutput - prevPlantOutput)));
    prevPlantOutput = plantOutput; // save the current Plant Output as the prev Plant Output for the next iteration as y((n-1)T) 
    qPrev = qCurrent; // save the current q(nT) for the next iteration to be q((n-1)T) 
    return output; // return the PID Controller output
}