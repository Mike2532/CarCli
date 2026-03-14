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

