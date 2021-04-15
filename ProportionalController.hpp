//
//  ProportionalController.hpp
//  DigitalController
//
//  Created by Dale Shpak on 2019-09-02.
//  Copyright © 2019 Dale Shpak. All rights reserved.
//

#ifndef ProportionalController_hpp
#define ProportionalController_hpp

#include "Controller.hpp"

class ProportionalController : public Controller {
private:
    const double kc;  // The proportional gain
public:
    /**
     * Constructor just copies the gain.
     *
     * @param gain The proportional gain
     */
    ProportionalController (const double gain) : kc(gain) {   };
    
    // Our promise to implement the function from the abstract base class
    double controlStep (double plantOutput, double setpoint);
};


#endif /* ProportionalController_hpp */