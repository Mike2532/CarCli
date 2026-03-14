#ifndef OOP_3_2_IENGINE_H
#define OOP_3_2_IENGINE_H

#include "../types.h"

class IEngine
{
public:
    virtual ~IEngine() = default;
    virtual void TurnOnEngine() = 0;
    virtual void TurnOffEngine(Speed speed, GearName curGear) = 0;
    virtual bool IsEngineTurningOn() = 0;
    virtual void RequireEngineWorks() = 0;
};

#endif//OOP_3_2_IENGINE_H
