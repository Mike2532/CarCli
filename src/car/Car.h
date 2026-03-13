#ifndef OOP_3_2_CAR_H
#define OOP_3_2_CAR_H

#include "./ICar.h"
#include "../engine/IEngine.h"
#include "../gearBox/IGearBox.h"

class Car : public ICar
{
public:
    Car(
        std::unique_ptr<IEngine> engine,
        std::unique_ptr<IGearBox> gearBox
    )
    {
        this->engine = std::move(engine);
        this->gearBox = std::move(gearBox);
    };

    void TurnOnEngine() override;
    void TurnOffEngine() override;
    void SetSpeed(Speed speed) override;
    void SetGear(GearNum gearNum) override;
    void PrintState(std::ostream& output = std::cout) override;
private:
    std::string GetEngineState();
    std::string GetDirectionState();
    GearNum GetGearBoxState();
    std::unique_ptr<IEngine>  engine;
    std::unique_ptr<IGearBox> gearBox;
};


#endif//OOP_3_2_CAR_H
