#ifndef OOP_3_2_ICAR_H
#define OOP_3_2_ICAR_H

#include <fstream>
#include <iostream>
#include "../types.h"

class ICar
{
public:
    virtual void TurnOnEngine() = 0;
    virtual void TurnOffEngine() = 0;
    virtual void SetSpeed(Speed speed) = 0;
    virtual void SetGear(GearNum gearNum) = 0;
    virtual void PrintState(std::ostream& output = std::cout) = 0;
};

#endif//OOP_3_2_ICAR_H
