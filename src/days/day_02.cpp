#include "day_02.hpp"

#include <regex>
#include <vector>
#include <algorithm>
#include <iterator>

#include "../errors.hpp"
#include "../io_utils.hpp"

namespace rook::aoc::days {

    using namespace rook::aoc;
    using namespace std;

    bool isValidPairs(const vector<int>& report, bool canSkip, function<bool(int, int)> validator) {
        if (report.size() <= 1) {
            return true;
        }

        int v_idx = 0;
        bool skipped = false;

        while (v_idx < report.size() - 1) {
            if (!validator(report[v_idx], report[v_idx + 1])) {
                if (skipped || !canSkip) {
                    return false;
                }
                else if (v_idx == report.size() - 2) {
                    // Can skip the last
                    skipped = true;
                    v_idx += 2;
                }
                else if (validator(report[v_idx], report[v_idx + 2])) {
                    // Try skipping the right
                    skipped = true;
                    v_idx += 2;
                }
                else if (v_idx == 0) {
                    // The left first can be skipped
                    skipped = true;
                    v_idx++;
                }
                else if (validator(report[v_idx-1], report[v_idx+1])) {
                    // The left could be skipped and be valid.
                    skipped = true;
                    v_idx++;
                }
                else {
                    return false;
                }
            }
            else {
                v_idx++;
            }
        }

        return true;
    }

    bool isIncreasing(int v, int next_v) {
        return next_v > v;
    }

    bool isDecreasing(int v, int next_v) {
        return next_v < v;
    }

    bool isSafeDelta(int v, int next_v) {
        int delta = abs(next_v - v);
        return delta >= 1 && delta <= 3;
    }

    bool isSafe(const vector<int>& report, bool canSkip) {
        return
            isValidPairs(report, canSkip, [](int v, int next_v) { return isIncreasing(v, next_v) && isSafeDelta(v, next_v); }) ||
            isValidPairs(report, canSkip, [](int v, int next_v) { return isDecreasing(v, next_v) && isSafeDelta(v, next_v); });
    }

    void parseFile(vector<vector<int>>& reports, const string& input) {
        for (auto line : ioReadLines(input)) {
            istringstream stream(line);
            vector<int> report;
            int num;

            while (stream >> num) {
                report.push_back(num);
            }

            reports.push_back(report);
        }
    }

    string solve(const string& input, bool canSkip) {
        vector<vector<int>> reports;        
        parseFile(reports, input);

        int safeCount = 0;
        for (auto& report : reports) {
            if (isSafe(report, canSkip)) {
                safeCount++;
            }
        }

        return to_string(safeCount);
    }

    string Day02::solvePart1(const string& input) {
        return solve(input, false);
    }

    string Day02::solvePart2(const string& input) {
        return solve(input, true);
    }
}