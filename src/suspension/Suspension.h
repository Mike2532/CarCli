#ifndef OOP_3_2_SUSPENSION_H
#define OOP_3_2_SUSPENSION_H

#include "./ISuspension.h"

class Suspension : public ISuspension
{
public:
    Direction GetDirection() override;
    Speed GetSpeed() override;
    void SetSpeed(GearName gearName, Speed newSpeed) override;
private:
    void UpdateDirection(GearName gearName);

    Direction direction = Direction::NONE;
    Speed speed = 0;
};

#endif//OOP_3_2_SUSPENSION_H
