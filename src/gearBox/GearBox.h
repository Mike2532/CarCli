#ifndef OOP_3_2_GEARBOX_H
#define OOP_3_2_GEARBOX_H

#include "./IGearBox.h"

class GearBox : public IGearBox
{
public:
    void SetGear(GearNum gearNum, Speed speed, Direction direction) override;
    void IsSpeedValid(Speed curSpeed, Speed newSpeed) override;
    GearName GetCurGearName() override;
private:
    GearName curGear = GearName::Neutral;
    const GearList gears = {
            {GearName::Reverse, {0, 20}},
            {GearName::First, {0, 30}},
            {GearName::Second, {20, 50}},
            {GearName::Third, {30, 60}},
            {GearName::Fourth, {40, 90}},
            {GearName::Fifth, {50, 150}}
    };

    void ValidateGearNum(GearNum gearNum);
    void CheckSpeedValid(GearName gearName, Speed speed);
    void UpdateCurGear(GearNum gearNum);
    void ForwardGearValidate(Speed speed, Direction direction);
    void SetForwardGear(GearNum gearNum, Speed speed, Direction direction);
    void SetBackGear(Speed speed);
};

#endif//OOP_3_2_GEARBOX_H
