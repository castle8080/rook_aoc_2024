#include "runner.hpp"

#include <iostream>
#include <string>
#include <chrono>

namespace rook::aoc {
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

}