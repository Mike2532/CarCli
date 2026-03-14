#ifndef OOP_3_2_ISUSPENSION_H
#define OOP_3_2_ISUSPENSION_H

#include "../types.h"

class ISuspension
{
public:
    virtual ~ISuspension() = default;
    virtual Direction GetDirection() = 0;
    virtual Speed GetSpeed() = 0;
    virtual void SetSpeed(GearName gearName, Speed newSpeed) = 0;
};

#endif//OOP_3_2_ISUSPENSION_H
