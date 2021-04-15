/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ProportionalController.hpp"
// Implementation of controlStep()
double ProportionalController::controlStep (const double plantOutput, double setpoint) {
    return setpoint + kc * (setpoint - plantOutput);
}