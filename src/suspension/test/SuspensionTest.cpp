#include <catch2/catch_test_macros.hpp>
#include "../Suspension.h"

TEST_CASE("set positive speed and check direction")
{
    auto suspension = std::make_unique<Suspension>();

    auto gear = GearName::FIRST;
    Speed speed = 15;

    suspension->SetSpeed(gear, speed);
    REQUIRE(suspension->GetSpeed() == speed);
    REQUIRE(suspension->GetDirection() == Direction::FORWARD);
}

TEST_CASE("set zero speed and check direction")
{
    auto suspension = std::make_unique<Suspension>();

    auto gear = GearName::FIRST;
    Speed speed = 0;

    suspension->SetSpeed(gear, speed);
    REQUIRE(suspension->GetSpeed() == speed);
    REQUIRE(suspension->GetDirection() == Direction::NONE);
}

TEST_CASE("set reverse speed and check direction")
{
    auto suspension = std::make_unique<Suspension>();

    auto gear = GearName::REVERSE;
    Speed speed = 10;

    suspension->SetSpeed(gear, speed);
    REQUIRE(suspension->GetSpeed() == speed);
    REQUIRE(suspension->GetDirection() == Direction::BEHIND);
}