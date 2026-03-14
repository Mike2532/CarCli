#ifndef OOP_3_2_TYPES_H
#define OOP_3_2_TYPES_H

#include <utility>
#include <unordered_map>

enum class Direction {FORWARD, BEHIND, NONE};

enum class GearName
{
    REVERSE = -1,
    NEUTRAL = 0,
    FIRST = 1,
    SECOND,
    THIRD,
    FOURTH,
    FIFTH,
    FIRST_ELEM = REVERSE,
    LAST_ELEM = FIFTH
};

using Speed = unsigned int;
using GearNum = int;
using Gear = std::pair<Speed, Speed>;
using GearList = std::unordered_map<GearName, Gear>;

#endif//OOP_3_2_TYPES_H
