#ifndef __RUNNER_HPP__
#define __RUNNER_HPP__

#include <string>
#include <functional>

namespace rook::aoc {
    void runProblem(int day, const char * part, std::function<std::string()> f);
}

#endif
