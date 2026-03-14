#include "GearBox.h"

GearName GearBox::GetCurGearName()
{
    return curGear;
}

void GearBox::SetGear(GearNum gearNum, Speed speed, Direction direction) //схопнуть проверки на скорость и нулевую передачу
{
    ValidateGearNum(gearNum);

    if (gearNum == -1)
    {
        SetBackGear(speed);
    }

    if (gearNum == 0)
    {
        UpdateCurGear(gearNum);
    }

    SetForwardGear(gearNum, speed, direction);
}

void GearBox::IsSpeedValid(Speed curSpeed, Speed newSpeed)
{
    if (curGear == GearName::NEUTRAL)
    {
        if (newSpeed <= curSpeed)
        {
            return;
        }
        throw std::runtime_error("speed at neutral gear can not be more thar current");
    }
    CheckSpeedValid(curGear, newSpeed);
}

void GearBox::SetForwardGear(GearNum gearNum, Speed speed, Direction direction)
{
    ForwardGearValidate(speed, direction);
    CheckSpeedValid(static_cast<GearName>(gearNum), speed);
    UpdateCurGear(gearNum);
}

void GearBox::SetBackGear(Speed speed)
{
    if (speed != 0)
    {
        throw std::runtime_error("can not set back gear at not zero speed");
    }
    UpdateCurGear(0);
}


void GearBox::ValidateGearNum(GearNum gearNum)
{
    auto min = static_cast<GearNum>(GearName::FIRST_ELEM);
    auto max = static_cast<GearNum>(GearName::LAST_ELEM);

    if (gearNum < min || gearNum > max)
    {
        throw std::runtime_error("invalid gearNum");
    }
}

void GearBox::ForwardGearValidate(Speed speed, Direction direction)
{
    if (curGear == GearName::NEUTRAL && speed != 0 && direction == Direction::BEHIND)
    {
        throw std::runtime_error("can not set forward gear at not zero speed from back gear");
    }
}

void GearBox::CheckSpeedValid(GearName gearName, Speed speed)
{
    if (gearName == GearName::NEUTRAL)
    {
        return;
    }

    auto limits = gears.at(gearName);
    if (speed < limits.first)
    {
        throw std::runtime_error("too slow");
    }
    if (speed > limits.second)
    {
        throw std::runtime_error("too fast");
    }
}

void GearBox::UpdateCurGear(GearNum gearNum)
{
    curGear = static_cast<GearName>(gearNum);
}