#ifndef __DAY_INTERFACE_HPP__
#define __DAY_INTERFACE_HPP__

#include <string>

namespace rook::aoc::days {
    /**
     * @class DayInterface
     * @brief Interface for Advent of Code Day Problems.
     */
    class DayInterface {
    public:

        DayInterface(int day): m_day(day) {
        }

        int getDay() {
            return m_day;
        }

        virtual std::string solvePart1(const std::string& input) = 0;

        virtual std::string solvePart2(const std::string& input) = 0;

    private:
        int m_day;
    };
}

#endif