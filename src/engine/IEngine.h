#ifndef OOP_3_2_IENGINE_H
#define OOP_3_2_IENGINE_H

#include "../types.h"

class IEngine
{
public:
    virtual ~IEngine() = default;
    virtual void TurnOnEngine() = 0;
    virtual void TurnOffEngine(GearName curGear) = 0;
    virtual bool IsEngineTurningOn() = 0;
    virtual Direction GetDirection() = 0;
    virtual Speed GetSpeed() = 0;
    virtual void SetSpeed(GearName gearName, Speed newSpeed) = 0;
    virtual void ValidateStateToSpeedChange() = 0;
};

#endif//OOP_3_2_IENGINE_H
