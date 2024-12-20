#include "day_input.hpp"

#include <iostream>
#include <iomanip>

namespace rook::aoc {

    using namespace std;

    string getDayInputFile(const string& inputDir, const string& datasetName, int day) {
        std::ostringstream oss;

        oss << inputDir << "/day_" << setw(2) << setfill('0') << day;
        if (datasetName.size() > 0) {
            oss << "." << datasetName;
        }

        oss << ".txt";

        return oss.str();
    }

}