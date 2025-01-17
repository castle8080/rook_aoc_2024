#include <iostream>
#include <filesystem>

#include "days/day_interface.hpp"
#include "days/days.hpp"
#include "day_input.hpp"
#include "runner.hpp"
#include "errors.hpp"

using namespace rook::aoc;
using namespace rook::aoc::days;
using namespace std;

std::string getInputDirectory() {
    filesystem::path curDir = filesystem::current_path();

    while (!curDir.empty()) {
        auto inputDir = curDir / "input";
        if (filesystem::is_directory(inputDir)) {
            return inputDir.string();
        }
        if (curDir == curDir.parent_path()) {
            break;
        }
        curDir = curDir.parent_path();
    }

    throw SolverException("Could not find input directory.");
}

int main() {
    try {
        string inputDir = getInputDirectory();

        //string datasetName("test");
        string datasetName("");

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