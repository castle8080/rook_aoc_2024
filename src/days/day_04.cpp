#include "day_04.hpp"

#include <vector>
#include <iterator>
#include <string>
#include <variant>

#include "../errors.hpp"
#include "../io_utils.hpp"

namespace {
    using namespace rook::aoc;
    using namespace std;

    static string TARGET_XMAS = string("XMAS");

    void count(const vector<string>& lines, int x, int y, ulong pos, int& totalFound) {
        int width = (int) lines[0].size();
        int height = (int) lines.size();

        // out of bounds.
        if (x < 0 || x >= width || y < 0 || y >= height) {
            return;
        }

        // The current position does not match
        if (TARGET_XMAS[pos] != lines[y].at(x)) {
            return;
        }
        else if (pos == TARGET_XMAS.size() - 1) {
            // made it to the end.
            totalFound++;
            return;
        }

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                // Don't look at same position.
                if (dx == 0 && dy == 0) {
                    break;
                }
                count(lines, x + dx, y + dy, pos + 1, totalFound);
            }
        }
    }

    int getXMASCounts(const vector<string>& lines) {
        int width = (int) lines[0].size();
        int height = (int) lines.size();

        int totalFound = 0;
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                count(lines, x, y, 0, totalFound);
            }
        }
        return totalFound;
    }
}

namespace rook::aoc::days {

    using namespace rook::aoc;
    using namespace std;


    string Day04::solvePart1(const string& input) {
        auto lines = ioReadLines(input);
        int counts = getXMASCounts(lines);

        return to_string(counts);
    }

    string Day04::solvePart2(const string& input) {
        (void) input;
        return "";
    }
}