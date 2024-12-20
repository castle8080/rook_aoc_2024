#ifndef __DAYS__HPP__
#define __DAYS__HPP__

#include <memory>
#include <vector>

#include "day_interface.hpp"

namespace rook::aoc::days {

    std::shared_ptr<DayInterface> getDay(int dayNumber);

    std::vector<std::shared_ptr<DayInterface>> getAllDays();
}

#endif