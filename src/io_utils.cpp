#include "io_utils.hpp"

#include <fstream>
#include "errors.hpp"

namespace rook::aoc {

    using namespace std;

    vector<string> ioReadLines(const string& fileName) {
        ifstream file(fileName);

        if (!file.is_open()) {
            throw SolverException("Could not open file: " + fileName);
        }

        vector<string> lines = vector<string>();

        string line;
        while (getline(file, line)) {
            if (line.length() > 0) {
                lines.push_back(line);
            }
        }

        return lines;
    }

}
