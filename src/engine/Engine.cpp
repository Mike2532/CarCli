#include "Engine.h"

void Engine::UpdateDirection(GearName gearName)
{
    if (speed == 0)
    {
        direction = Direction::NONE;
        return;
    }
    if (gearName == GearName::NEUTRAL)
    {
        return;
    }
    if (gearName == GearName::REVERSE)
    {
        direction = Direction::BEHIND;
        return;
    }
    direction = Direction::FORWARD;
}

void Engine::SetSpeed(GearName gearName, Speed newSpeed)
{
    if (!isTurningOn)
    {
        throw std::runtime_error("can not change speed of inactive engine");
    }

    speed = newSpeed;
    UpdateDirection(gearName);
}

bool Engine::IsEngineTurningOn()
{
    return isTurningOn;
}

Direction Engine::GetDirection()
{
    return direction;
}

Speed Engine::GetSpeed()
{
    return speed;
}

void Engine::TurnOnEngine()
{
    if (isTurningOn)
    {
        return;
    }

    isTurningOn = true;
}

void Engine::TurnOffEngine(GearName curGear)
{
    if (!isTurningOn)
    {
        return;
    }

    if (speed != 0)
    {
        throw std::runtime_error("can not turn on drive");
    }

    if (curGear != GearName::NEUTRAL)
    {
        throw std::runtime_error("can not turn off engine non neutral gear");
    }

    isTurningOn = false;
}

void Engine::ValidateStateToSpeedChange()
{
    if (!isTurningOn)
    {
        throw std::runtime_error("can not change speed of inactive engine");
    }
}