#include <catch2/catch_test_macros.hpp>
#include "../Engine.h"

TEST_CASE("success start engine")
{
    auto engine = std::make_unique<Engine>();

    engine->TurnOnEngine();
    REQUIRE(engine->IsEngineTurningOn());
}

TEST_CASE("success stop engine")
{
    auto engine = std::make_unique<Engine>();

    auto gear = GearName::NEUTRAL;
    Speed speed = 0;

    engine->TurnOffEngine(speed, gear);
    REQUIRE(!engine->IsEngineTurningOn());
}

TEST_CASE("failed stop engine (not neutral gear)")
{
    auto engine = std::make_unique<Engine>();
    engine->TurnOnEngine();

    auto gear = GearName::FIRST;
    Speed speed = 0;

    try
    {
        engine->TurnOffEngine(speed, gear);
        FAIL("Exception was not thrown");
    }
    catch (const std::runtime_error& e)
    {
        REQUIRE(std::string(e.what()) == "can not turn off engine non neutral gear");
    }
}

TEST_CASE("failed stop engine (on drive)")
{
    auto engine = std::make_unique<Engine>();
    engine->TurnOnEngine();

    auto gear = GearName::FIRST;
    Speed speed = 15;

    try
    {
        engine->TurnOffEngine(speed, gear);
        FAIL("Exception was not thrown");
    }
    catch (const std::runtime_error& e)
    {
        REQUIRE(std::string(e.what()) == "can not turn on drive");
    }
}