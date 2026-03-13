#ifndef OOP_3_2_IGEARBOX_H
#define OOP_3_2_IGEARBOX_H

#include "../types.h"

class IGearBox
{
public:
    virtual ~IGearBox() = default;
    virtual void SetGear(GearNum gearNum, Speed speed, Direction direction) = 0;
    virtual void IsSpeedValid( Speed curSpeed, Speed newSpeed) = 0;
    virtual GearName GetCurGearName() = 0;
};


#endif//OOP_3_2_IGEARBOX_H
