#include "./days.hpp"

#include <vector>
#include <functional>
#include <memory>

#include "../errors.hpp"
#include "day_interface.hpp"
#include "day_01.hpp"
#include "day_02.hpp"
#include "day_03.hpp"

namespace rook::aoc::days {

    using namespace std;

    static vector<function<shared_ptr<DayInterface>()>> DAY_FACTORIES = {
        []() { return make_shared<Day01>(); },
        []() { return make_shared<Day02>(); },
        []() { return make_shared<Day03>(); },
    };

    shared_ptr<DayInterface> getDay(int dayNumber) {
        ulong idx = dayNumber - 1;

        if (idx >= DAY_FACTORIES.size()) {
            throw SolverException("Could not find day " + dayNumber);
        }

        return DAY_FACTORIES[idx]();
    }

    vector<shared_ptr<DayInterface>> getAllDays() {
        vector<shared_ptr<DayInterface>> days = vector<shared_ptr<DayInterface>>();

        for (auto factory : DAY_FACTORIES) {
            days.push_back(factory());
        }

        return days;
    }
}