#include <iostream>
#include <memory>
#include <chrono>
#include <functional>

#include "days/day_interface.hpp"
#include "days/days.hpp"
#include "day_input.hpp"

using namespace rook::aoc;
using namespace rook::aoc::days;
using namespace std;

void runProblem(int day, const char * part, function<string()> f) {
    cout << "Problem: " << day << " - Part: " << part << endl;
    auto start = chrono::high_resolution_clock::now();
    try {
        auto answer = f();
        cout << "Answer: " << answer << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);
    auto ms = ((double) duration.count()) / 1000.0;
    cout << "Execution Time: " << ms << " milliseconds." << endl;
}

int main() {
    try {
        string inputDir = string("../input");

        for (auto day : getAllDays()) {
            string input = getDayInputFile(inputDir, "", day->getDay());
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