#include <catch2/catch_test_macros.hpp>
#include <sstream>
#include "../Car.h"
#include "../../engine/Engine.h"
#include "../../gearBox/GearBox.h"
#include "../../suspension/Suspension.h"

TEST_CASE("initial state")
{
    auto engine = std::make_unique<Engine>();
    auto gearBox = std::make_unique<GearBox>();
    auto suspension = std::make_unique<Suspension>();
    auto car = std::make_unique<Car>(
            std::move(engine),
            std::move(gearBox),
            std::move(suspension)
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
    auto suspension = std::make_unique<Suspension>();
    auto car = std::make_unique<Car>(
            std::move(engine),
            std::move(gearBox),
            std::move(suspension)
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

TEST_CASE("set -1 speed at back gear")
{
    auto engine = std::make_unique<Engine>();
    auto gearBox = std::make_unique<GearBox>();
    auto suspension = std::make_unique<Suspension>();
    auto car = std::make_unique<Car>(
            std::move(engine),
            std::move(gearBox),
            std::move(suspension)
    );
    car->TurnOnEngine();
    car->SetGear(-1);

//    REQUIRE_THROWS_AS( //использовать её
//
//    );

    try
    {
        car->SetSpeed(-1);
        FAIL("Exception was not thrown");
    }
    catch (const std::runtime_error& e)
    {
        REQUIRE(std::string(e.what()) == "too slow");
    }
}

TEST_CASE("change speed at netral gear while moving back and check direction")
{
    auto engine = std::make_unique<Engine>();
    auto gearBox = std::make_unique<GearBox>();
    auto suspension = std::make_unique<Suspension>();
    auto car = std::make_unique<Car>(
            std::move(engine),
            std::move(gearBox),
            std::move(suspension)
    );

    car->TurnOnEngine();
    car->SetGear(-1);
    car->SetSpeed(10);
    car->SetGear(0);
    car->SetSpeed(9);

    std::ostringstream output;

    car->PrintState(output);

    std::string result = output.str();

    REQUIRE(result == "Engine: on\n"
                      "Direction: behind\n"
                      "Speed: 9\n"
                      "Gear: 0\n");

}