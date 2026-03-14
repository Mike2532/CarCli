#include <catch2/catch_test_macros.hpp>
#include "../GearBox.h"

TEST_CASE("success set neutral")
{
    auto gearBox =  std::make_unique<GearBox>();

    GearNum gearNum = 0;
    Speed speed = 0;
    Direction direction = Direction::NONE;

    gearBox->SetGear(gearNum, speed, direction);
}

TEST_CASE("success set back gear")
{
    auto gearBox = std::make_unique<GearBox>();

    GearNum gearNum = -1;
    Speed speed = 0;
    Direction direction = Direction::NONE;

    gearBox->SetGear(gearNum, speed, direction);
}

TEST_CASE("success set forward gear")
{
    auto gearBox = std::make_unique<GearBox>();

    GearNum gearNum = 1;
    Speed speed = 0;
    Direction direction = Direction::NONE;

    gearBox->SetGear(gearNum, speed, direction);
}

TEST_CASE("valid speed (rase at first gear)")
{
    auto gearBox = std::make_unique<GearBox>();

    GearNum gearNum = 1;
    Speed speed = 0;
    Direction direction = Direction::NONE;

    gearBox->SetGear(gearNum, speed, direction);

    Speed curSpeed = 0;
    Speed newSpeed = 10;

    gearBox->IsSpeedValid(curSpeed, newSpeed);
}

TEST_CASE("valid speed (slow at neutral)")
{
    auto gearBox = std::make_unique<GearBox>();

    Speed curSpeed = 10;
    Speed newSpeed = 5;

    gearBox->IsSpeedValid(curSpeed, newSpeed);
}

TEST_CASE("invalid speed (too fast)")
{
    auto gearBox = std::make_unique<GearBox>();

    GearNum gearNum = 1;
    Speed speed = 0;
    Direction direction = Direction::NONE;

    gearBox->SetGear(gearNum, speed, direction);

    Speed curSpeed = 0;
    Speed newSpeed = 40;

    try
    {
        gearBox->IsSpeedValid(curSpeed, newSpeed);
        FAIL("Exception was not thrown");
    }
    catch (const std::runtime_error& e)
    {
        REQUIRE(std::string(e.what()) == "too fast");
    }
}

TEST_CASE("invalid speed (too slow)")
{
    auto gearBox = std::make_unique<GearBox>();

    GearNum gearNum = 1;
    Speed speed = 0;
    Direction direction = Direction::NONE;

    gearBox->SetGear(gearNum, speed, direction);

    Speed curSpeed = 0;
    Speed newSpeed = -5;

    try
    {
        gearBox->IsSpeedValid(curSpeed, newSpeed);
        FAIL("Exception was not thrown");
    }
    catch (const std::runtime_error& e)
    {
        REQUIRE(std::string(e.what()) == "too slow");
    }
}

TEST_CASE("invalid speed (rase at neutral)")
{
    auto gearBox = std::make_unique<GearBox>();

    Speed curSpeed = 5;
    Speed newSpeed = 10;

    try
    {
        gearBox->IsSpeedValid(curSpeed, newSpeed);
        FAIL("Exception was not thrown");
    }
    catch (const std::runtime_error& e)
    {
        REQUIRE(std::string(e.what()) == "speed at neutral gear can not be more thar current");
    }
}

TEST_CASE("invalid gear (too small)")
{
    auto gearBox = std::make_unique<GearBox>();

    GearNum gearNum = -2;
    Speed speed = 0;
    Direction direction = Direction::NONE;

    try
    {
        gearBox->SetGear(gearNum, speed, direction);
        FAIL("Exception was not thrown");
    }
    catch (const std::runtime_error& e)
    {
        REQUIRE(std::string(e.what()) == "invalid gearNum");
    }
}

TEST_CASE("invalid gear (too big)")
{
    auto gearBox = std::make_unique<GearBox>();

    GearNum gearNum = 6;
    Speed speed = 0;
    Direction direction = Direction::NONE;

    try
    {
        gearBox->SetGear(gearNum, speed, direction);
        FAIL("Exception was not thrown");
    }
    catch (const std::runtime_error& e)
    {
        REQUIRE(std::string(e.what()) == "invalid gearNum");
    }
}

TEST_CASE("set back gear at speed")
{
    auto gearBox = std::make_unique<GearBox>();

    GearNum gearNum = -1;
    Speed speed = 50;
    Direction direction = Direction::FORWARD;

    try
    {
        gearBox->SetGear(gearNum, speed, direction);
        FAIL("Exception was not thrown");
    }
    catch (const std::runtime_error& e)
    {
        REQUIRE(std::string(e.what()) == "can not set back gear at not zero speed");
    }
}

TEST_CASE("set forward at speed driving back")
{
    auto gearBox = std::make_unique<GearBox>();

    GearNum gearNum = 1;
    Speed speed = 20;
    Direction direction = Direction::BEHIND;

    try
    {
        gearBox->SetGear(gearNum, speed, direction);
        FAIL("Exception was not thrown");
    }
    catch (const std::runtime_error& e)
    {
        REQUIRE(std::string(e.what()) == "can not set forward gear at not zero speed from back gear");
    }
}

TEST_CASE("set forward at too much speed")
{
    auto gearBox = std::make_unique<GearBox>();

    GearNum gearNum = 1;
    Speed speed = 200;
    Direction direction = Direction::FORWARD;

    try
    {
        gearBox->SetGear(gearNum, speed, direction);
        FAIL("Exception was not thrown");
    }
    catch (const std::runtime_error& e)
    {
        REQUIRE(std::string(e.what()) == "too fast");
    }
}

TEST_CASE("set forward at too low speed")
{
    auto gearBox = std::make_unique<GearBox>();

    GearNum gearNum = 5;
    Speed speed = 20;
    Direction direction = Direction::FORWARD;

    try
    {
        gearBox->SetGear(gearNum, speed, direction);
        FAIL("Exception was not thrown");
    }
    catch (const std::runtime_error& e)
    {
        REQUIRE(std::string(e.what()) == "too slow");
    }
}