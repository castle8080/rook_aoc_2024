#ifndef __DAY_04_HPP__
#define __DAY_04_HPP__

#include <string>
#include "day_interface.hpp"

namespace rook::aoc::days {
    class Day04 : public rook::aoc::days::DayInterface {
    public:
        Day04() : DayInterface(4) {}
        
        std::string solvePart1(const std::string& input);
        std::string solvePart2(const std::string& input);
    };
};

#endif