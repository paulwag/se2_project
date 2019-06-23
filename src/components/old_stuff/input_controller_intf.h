#ifndef INPUT_CONTROLLER_INTF_H
#define INPUT_CONTROLLER_INTF_H

#include "controller_intf.h"

class input_controller_intf : public controller_intf
{
public:
     input_controller_intf(std::string name) : controller_intf(name) {}
     ~input_controller_intf() {}

    /**
     * @brief buttonPressed empfaengt Button Signale und verwertet diese
     */
    virtual void buttonPressed() = 0;
};

#endif