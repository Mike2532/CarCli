#ifndef OOP_3_2_TYPES_H
#define OOP_3_2_TYPES_H

#include <utility>
#include <unordered_map>

enum class Direction {FORWARD, BEHIND, NONE};

enum class GearName
{
    Reverse = -1,
    Neutral = 0,
    First = 1,
    Second,
    Third,
    Fourth,
    Fifth,
    FirstElem = Reverse,
    LastElem = Fifth
};

using Speed = unsigned int;
using GearNum = int;
using Gear = std::pair<Speed, Speed>;
using GearList = std::unordered_map<GearName, Gear>;

#endif//OOP_3_2_TYPES_H
