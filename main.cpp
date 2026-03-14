#include "./src/engine/Engine.h"
#include "./src/gearBox/GearBox.h"
#include "./src/car/Car.h"
#include "./src/cli/CLI.h"

std::unique_ptr<Car> GetCar();

int main() {
    auto car = GetCar();

    auto cli = std::make_unique<CLI>(std::move(car));

    cli->ServeApp();
    return 0;
}

std::unique_ptr<Car> GetCar()
{
    auto engine = std::make_unique<Engine>();
    auto gearBox = std::make_unique<GearBox>();
    auto car = std::make_unique<Car>(
            std::move(engine),
            std::move(gearBox)
    );

    return car;
}

//cli не обработал ошибку парсинга числа

//Info
//Engine: on
//Direction: none
//Speed: 0
//Gear: -1
//SetSpeed -1
//too fast

//Info
//Engine: on
//Direction: behind
//Speed: 10
//Gear: -1
//SetGear 0
//can not set forward gear at not zero speed from back gear
//Info
//Engine: on
//Direction: behind
//Speed: 10
//Gear: 0
//SetSpeed 9
//Info
//Engine: on
//Direction: forward
//Speed: 9
//Gear: 0
//Set

