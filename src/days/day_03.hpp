#ifndef __DAY_03_HPP__
#define __DAY_03_HPP__

#include <string>
#include "day_interface.hpp"

namespace rook::aoc::days {
    class Day03 : public rook::aoc::days::DayInterface {
    public:
        Day03() : DayInterface(3) {}
        
        std::string solvePart1(const std::string& input);
        std::string solvePart2(const std::string& input);
    };
};

#endif