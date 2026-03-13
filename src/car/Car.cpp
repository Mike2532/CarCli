#include "Car.h"
#include <string>

void Car::TurnOnEngine()
{
    engine->TurnOnEngine();
}

void Car::TurnOffEngine()
{
    auto gear = gearBox->GetCurGearName();
    engine->TurnOffEngine(gear);
}

void Car::SetSpeed(Speed speed)
{
    engine->ValidateStateToSpeedChange();

    auto curSpeed = engine->GetSpeed();
    gearBox->IsSpeedValid(curSpeed, speed);

    auto curGear = gearBox->GetCurGearName();
    engine->SetSpeed(curGear, speed);
}

void Car::SetGear(GearNum gearNum)
{
    auto speed = engine->GetSpeed();
    auto direction = engine->GetDirection();
    gearBox->SetGear(gearNum, speed, direction);
}

void Car::PrintState(std::ostream& output)
{
    output << "Engine: " << GetEngineState() << std::endl <<
            "Direction: " << GetDirectionState() << std::endl <<
            "Speed: " << engine->GetSpeed() << std::endl <<
            "Gear: " << GetGearBoxState() << std::endl;
}

std::string Car::GetEngineState()
{
    return (engine->IsEngineTurningOn())
                   ? "on"
                   : "off";
}

std::string Car::GetDirectionState()
{
    auto direction = engine->GetDirection();
    switch (direction)
    {
        case Direction::BEHIND:
            return "behind";
        case Direction::NONE:
            return "none";
        case Direction::FORWARD:
            return "forward";
        default:
            return "unknown";
    }
}

GearNum Car::GetGearBoxState()
{
    auto gear = gearBox->GetCurGearName();
    return static_cast<GearNum>(gear);
}