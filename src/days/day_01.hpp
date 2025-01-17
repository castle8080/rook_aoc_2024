#ifndef __DAY_01_HPP__
#define __DAY_01_HPP__

#include <string>
#include "day_interface.hpp"

namespace rook::aoc::days {
    class Day01 : public rook::aoc::days::DayInterface {
    public:
        Day01() : DayInterface(1) {}
        
        std::string solvePart1(const std::string& input);
        std::string solvePart2(const std::string& input);
    };
};

#endif