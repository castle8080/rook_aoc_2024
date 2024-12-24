#include <iostream>

#include "days/day_interface.hpp"
#include "days/days.hpp"
#include "day_input.hpp"
#include "runner.hpp"

using namespace rook::aoc;
using namespace rook::aoc::days;
using namespace std;

int main() {
    try {
        string inputDir = string("../input");
        string datasetName("test");
        //string datasetName("");

        for (auto day : getAllDays()) {
            string input = getDayInputFile(inputDir, datasetName, day->getDay());
            runProblem(day->getDay(), "1", [day, input]() { return day->solvePart1(input); });
            runProblem(day->getDay(), "2", [day, input]() { return day->solvePart2(input); });
        }

        return 0;
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
        return 1;
    }
}