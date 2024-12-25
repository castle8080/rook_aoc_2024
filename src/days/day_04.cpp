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

    int countWithDirection(const vector<string>& lines, int x, int y, int dx, int dy) {
        if (lines.size() == 0) {
            return 0;
        }

        int width = (int) lines[0].size();
        int height = (int) lines.size();

        for (int i = 0; i < (int)TARGET_XMAS.size(); i++) {
            int xp = x + i * dx;
            int yp = y + i * dy;
            if (xp < 0 || xp >= width || yp < 0 || yp >= height) {
                return 0;
            }
            else if (TARGET_XMAS[i] != lines[yp][xp]) {
                return 0;
            }
        }

        return 1;
    }

    int countAtSpot(const vector<string>& lines, int x, int y) {
        if (y < 0 || y >= lines.size() || x < 0 || x > lines[0].size()) {
            return 0;
        }
        if (lines[y].at(x) != TARGET_XMAS.at(0)) {
            return 0;
        }
        return
            countWithDirection(lines, x, y, -1, -1) +
            countWithDirection(lines, x, y, -1, 0) +
            countWithDirection(lines, x, y, -1, 1) +
            countWithDirection(lines, x, y, 0, -1) +
            countWithDirection(lines, x, y, 0, 1) +
            countWithDirection(lines, x, y, 1, -1) +
            countWithDirection(lines, x, y, 1, 0) +
            countWithDirection(lines, x, y, 1, 1);
    }

    int getXMASCounts(const vector<string>& lines) {
        int width = (int) lines[0].size();
        int height = (int) lines.size();

        int totalFound = 0;
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                totalFound += countAtSpot(lines, x, y);
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