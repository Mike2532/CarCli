#include "Engine.h"

void Engine::TurnOnEngine()
{
    if (isTurningOn)
    {
        return;
    }

    isTurningOn = true;
}

void Engine::RequireEngineWorks()
{
    if (isTurningOn)
    {
        return;
    }
    throw std::runtime_error("error: inactive engine");
}

void Engine::TurnOffEngine(Speed speed, GearName curGear)
{
    if (!isTurningOn)
    {
        return;
    }

    RequireZeroSpeed(speed);
    RequireNeutralGear(curGear);

    isTurningOn = false;
}

bool Engine::IsEngineTurningOn()
{
    return isTurningOn;
}

void Engine::RequireZeroSpeed(Speed speed)
{
    if (speed == 0)
    {
        return;
    }
    throw std::runtime_error("can not turn on drive");
}

void Engine::RequireNeutralGear(GearName curGear)
{
    if (curGear == GearName::NEUTRAL)
    {
        return;
    }
    throw std::runtime_error("can not turn off engine non neutral gear");
}
