#ifndef OOP_3_2_ENGINE_H
#define OOP_3_2_ENGINE_H

#include "./IEngine.h"

class Engine : public IEngine
{
public:
    void TurnOnEngine() override;
    void TurnOffEngine(GearName curGear) override;
    bool IsEngineTurningOn() override;
    Direction GetDirection() override;
    Speed GetSpeed() override;
    void SetSpeed(GearName gearName, Speed newSpeed) override;
    void ValidateStateToSpeedChange() override;
private:
    Direction direction = Direction::NONE;
    Speed speed = 0;
    bool isTurningOn = false;

    void UpdateDirection(GearName gearName);
};

#endif//OOP_3_2_ENGINE_H
