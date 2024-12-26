#ifndef __DAY_05_HPP__
#define __DAY_05_HPP__

#include <string>
#include "day_interface.hpp"

namespace rook::aoc::days {
    class Day05 : public rook::aoc::days::DayInterface {
    public:
        Day05() : DayInterface(5) {}

        std::string solvePart1(const std::string& input);
        std::string solvePart2(const std::string& input);
    };
};

#endif