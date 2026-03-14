#include "Suspension.h"

Direction Suspension::GetDirection()
{
    return direction;
}

Speed Suspension::GetSpeed()
{
    return speed;
}

void Suspension::SetSpeed(GearName gearName, Speed newSpeed)
{
    speed = newSpeed;
    UpdateDirection(gearName);
}

void Suspension::UpdateDirection(GearName gearName)
{
    if (gearName == GearName::NEUTRAL)
    {
        return;
    }
    if (speed == 0)
    {
        direction = Direction::NONE;
        return;
    }
    if (gearName == GearName::REVERSE)
    {
        direction = Direction::BEHIND;
        return;
    }
    direction = Direction::FORWARD;
}
