#ifndef __DAY_02_HPP__
#define __DAY_02_HPP__

#include <string>
#include "day_interface.hpp"

namespace rook::aoc::days {
    class Day02 : public rook::aoc::days::DayInterface {
    public:
        Day02() : DayInterface(2) {}
        
        std::string solvePart1(const std::string& input);
        std::string solvePart2(const std::string& input);
    };
};

#endif