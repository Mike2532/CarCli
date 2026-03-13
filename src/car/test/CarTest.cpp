#include <catch2/catch_test_macros.hpp>
#include <sstream>
#include "../Car.h"
#include "../../engine/Engine.h"
#include "../../gearBox/GearBox.h"

TEST_CASE("initial state")
{
    auto engine = std::make_unique<Engine>();
    auto gearBox = std::make_unique<GearBox>();
    auto car = std::make_unique<Car>(
            std::move(engine),
            std::move(gearBox)
    );

    std::ostringstream output;

    car->PrintState(output);

    std::string result = output.str();

    REQUIRE(result == "Engine: off\n"
                      "Direction: none\n"
                      "Speed: 0\n"
                      "Gear: 0\n");
}

TEST_CASE("drive")
{
    auto engine = std::make_unique<Engine>();
    auto gearBox = std::make_unique<GearBox>();
    auto car = std::make_unique<Car>(
            std::move(engine),
            std::move(gearBox)
    );

    car->TurnOnEngine();
    car->SetGear(1);
    car->SetSpeed(10);

    std::ostringstream output;

    car->PrintState(output);

    std::string result = output.str();

    REQUIRE(result == "Engine: on\n"
                      "Direction: forward\n"
                      "Speed: 10\n"
                      "Gear: 1\n");
}