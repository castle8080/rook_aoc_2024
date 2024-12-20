#include "day_01.hpp"

#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>

#include "../errors.hpp"
#include "../io_utils.hpp"

namespace {
    using namespace rook::aoc;
    using namespace std;

    void parseFile(vector<int>& list1, vector<int>& list2, const string& input) {
        auto lineRegex = regex("^(\\d+)\\s+(\\d+)");
        smatch m;

        for (auto& line : ioReadLines(input)) {
            if (regex_search(line, m, lineRegex)) {
                int i1 = stoi(m[1].str());
                int i2 = stoi(m[2].str());
                list1.push_back(i1);
                list2.push_back(i2);
            }
            else {
                throw SolverException("Invalid line: " + line);
            }
        }
    }

    void getNumberCounts(const vector<int>& numbers, map<int, int>& counts) {
        for (int n : numbers) {
            auto m = counts.find(n);
            if (m != counts.end()) {
                m->second += 1;
            }
            else {
                counts[n] = 1;
            }
        }
    }
}

namespace rook::aoc::days {
    using namespace rook::aoc;
    using namespace std;

    string Day01::solvePart1(const string& input) {
        vector<int> list1;
        vector<int> list2;

        parseFile(list1, list2, input);
        std::sort(list1.begin(), list1.end());
        std::sort(list2.begin(), list2.end());

        int total = 0;
        for (ulong i = 0; i < list1.size(); i++) {
            total += abs(list1[i] - list2[i]);
        }

        return to_string(total);
    }

    string Day01::solvePart2(const string& input) {
        vector<int> list1;
        vector<int> list2;

        parseFile(list1, list2, input);

        map<int, int> counts2 = map<int, int>();
        getNumberCounts(list2, counts2);

        int total = 0;
        for (int n : list1) {
            auto m = counts2.find(n);
            int times = (m != counts2.end()) ? m->second : 0;
            total += n * times;
        }

        return to_string(total);
    }
}