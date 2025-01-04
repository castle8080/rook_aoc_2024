#ifndef __DAY_06_HPP__
#define __DAY_06_HPP__

#include <string>
#include "day_interface.hpp"

namespace rook::aoc::days {
    class Day06 : public rook::aoc::days::DayInterface {
    public:
        Day06() : DayInterface(6) {}

        std::string solvePart1(const std::string& input);
        std::string solvePart2(const std::string& input);
    };
};

#endif