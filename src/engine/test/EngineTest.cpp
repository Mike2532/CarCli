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

    auto gear = GearName::Neutral;

    engine->TurnOffEngine(gear);
    REQUIRE(!engine->IsEngineTurningOn());
}

TEST_CASE("failed stop engine (not neutral gear)")
{
    auto engine = std::make_unique<Engine>();
    engine->TurnOnEngine();

    auto gear = GearName::First;

    try
    {
        engine->TurnOffEngine(gear);
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

    auto gear = GearName::First;

    engine->SetSpeed(gear, 10);

    try
    {
        engine->TurnOffEngine(gear);
        FAIL("Exception was not thrown");
    }
    catch (const std::runtime_error& e)
    {
        REQUIRE(std::string(e.what()) == "can not turn on drive");
    }
}

TEST_CASE("change speed of incative engine")
{
    auto engine = std::make_unique<Engine>();

    auto gear = GearName::First;
    Speed speed = 15;

    try
    {
        engine->SetSpeed(gear, speed);
        FAIL("Exception was not thrown");
    }
    catch (const std::runtime_error& e)
    {
        REQUIRE(std::string(e.what()) == "can not change speed of inactive engine");
    }
}


TEST_CASE("set positive speed and check direction")
{
    auto engine = std::make_unique<Engine>();
    engine->TurnOnEngine();

    auto gear = GearName::First;

    Speed speed = 15;

    engine->SetSpeed(gear, speed);
    REQUIRE(engine->GetSpeed() == speed);
    REQUIRE(engine->GetDirection() == Direction::FORWARD);
}

TEST_CASE("set zero speed and check direction")
{
    auto engine = std::make_unique<Engine>();
    engine->TurnOnEngine();

    auto gear = GearName::First;

    Speed speed = 0;

    engine->SetSpeed(gear, speed);
    REQUIRE(engine->GetSpeed() == speed);
    REQUIRE(engine->GetDirection() == Direction::NONE);
}

TEST_CASE("set reverse speed and check direction")
{
    auto engine = std::make_unique<Engine>();
    engine->TurnOnEngine();

    auto gear = GearName::Reverse;

    Speed speed = 10;

    engine->SetSpeed(gear, speed);
    REQUIRE(engine->GetSpeed() == speed);
    REQUIRE(engine->GetDirection() == Direction::BEHIND);
}
