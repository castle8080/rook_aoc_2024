#include "day_04.hpp"

#include <vector>
#include <map>
#include <iterator>
#include <string>
#include <variant>

#include "../errors.hpp"
#include "../io_utils.hpp"

namespace {
    using namespace rook::aoc;
    using namespace std;

    static vector<tuple<int, int>> STANDARD_DIRS = {
        {-1, -1},
        {-1, 0},
        {-1, 1},
        {0, -1},
        {0, 1},
        {1, -1},
        {1, 0},
        {1, 1}
    };

    static vector<tuple<int, int>> DIAG_DIRS = {
        {-1, -1},
        {-1, 1},
        {1, -1},
        {1, 1},
    };

    bool existsAtWithDirection(const string& s, const vector<string>& lines, int x, int y, int dx, int dy) {
        if (lines.size() == 0) {
            return false;
        }

        int width = (int)lines[0].size();
        int height = (int)lines.size();

        if (x < 0 || x >= width || y < 0 || y >= height) {
            return false;
        }

        for (int i = 0; i < (int)s.size(); i++) {
            int xp = x + i * dx;
            int yp = y + i * dy;
            if (xp < 0 || xp >= width || yp < 0 || yp >= height) {
                return false;
            }
            else if (s[i] != lines[yp][xp]) {
                return false;
            }
        }

        return true;
    }

    void getExistingDirections(string& tgt, const vector<tuple<int, int>>& possibleDirs,
        const vector<string>& lines, int x, int y, vector<tuple<int, int>>& vecs)
    {
        if (y < 0 || y >= lines.size() || x < 0 || x > lines[0].size()) {
            return;
        }
        if (lines[y].at(x) != tgt.at(0)) {
            return;
        }

        for (auto& dir : possibleDirs) {
            if (existsAtWithDirection(tgt, lines, x, y, get<0>(dir), get<1>(dir))) {
                vecs.push_back(dir);
            }
        }
    }

    int getXMASCountsPart1(const vector<string>& lines) {
        int width = (int) lines[0].size();
        int height = (int) lines.size();

        string tgt("XMAS");
        int totalFound = 0;

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                vector<tuple<int, int>> dirs;
                getExistingDirections(tgt, STANDARD_DIRS, lines, x, y, dirs);
                totalFound += (int) dirs.size();
            }
        }

        return totalFound;
    }

    int getXMASCountsPart2(const vector<string>& lines) {
        int width = (int)lines[0].size();
        int height = (int)lines.size();

        string tgt("MAS");
        map<tuple<int, int>, int> aSpots;
        int totalFound = 0;

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                vector<tuple<int, int>> dirs;
                getExistingDirections(tgt, DIAG_DIRS, lines, x, y, dirs);
                for (auto& dir : dirs) {
                    int ax = x + get<0>(dir);
                    int ay = y + get<1>(dir);
                    tuple<int, int> pos(ax, ay);

                    auto it = aSpots.find(pos);
                    if (it != aSpots.end()) {
                        aSpots[pos] = it->second + 1;
                    }
                    else {
                        aSpots[pos] = 1;
                    }
                }
            }
        }

        for (auto& it : aSpots) {
            if (it.second == 2) {
                totalFound++;
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
        int counts = getXMASCountsPart1(lines);

        return to_string(counts);
    }

    string Day04::solvePart2(const string& input) {
        auto lines = ioReadLines(input);
        int counts = getXMASCountsPart2(lines);

        return to_string(counts);
    }
}