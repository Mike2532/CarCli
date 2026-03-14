#ifndef OOP_3_2_ENGINE_H
#define OOP_3_2_ENGINE_H

#include "./IEngine.h"

class Engine : public IEngine
{
public:
    void TurnOnEngine() override;
    void TurnOffEngine(Speed speed, GearName curGear) override;
    bool IsEngineTurningOn() override;
    void RequireEngineWorks() override;
private:
    void RequireZeroSpeed(Speed speed);
    void RequireNeutralGear(GearName curGear);

    bool isTurningOn = false;
};

#endif//OOP_3_2_ENGINE_H
