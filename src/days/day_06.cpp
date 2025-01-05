#include "day_06.hpp"

#include <string>
#include <unordered_set>

#include "../errors.hpp"
#include "../io_utils.hpp"
#include "../parse_utils.hpp"

namespace {
    using namespace rook::aoc;
    using namespace std;


    // Define a custom hash function for tuple<int, int>
    struct TwoTupleIntHash {
        size_t operator()(const std::tuple<int, int>& t) const {
            size_t h1 = std::hash<int>{}(std::get<0>(t));
            size_t h2 = std::hash<int>{}(std::get<1>(t));
            return h1 ^ (h2 << 1);
        }
    };

    struct GuardPosition {
        int x;
        int y;
        int dx;
        int dy;

        GuardPosition(): GuardPosition(0, 0, 0, 0) {
        }

        GuardPosition(int _x, int _y, int _dx, int _dy)
            : x(_x), y(_y), dx(_dx), dy(_dy)
        {
        }

        void turnRight() {
            if (dx == 0) {
                if (dy == -1) {
                    dx = 1;
                    dy = 0;
                }
                else {
                    dx = -1;
                    dy = 0;
                }
            }
            else if (dx == -1) {
                dy = -1;
                dx = 0;
            }
            else {
                dy = 1;
                dx = 0;
            }
        }

        friend std::ostream& operator<<(std::ostream& os, const GuardPosition& gp) {
            os << "GuardPosition { x: " << gp.x << ", y: " << gp.y << ", dx: " << gp.dx << ", dy: " << gp.dy << " }";
            return os;
        }
    };

    enum GuardSimulationPositionStatus {
        ON_BOARD = 0,
        OFF_BOARD,
        BLOCKED
    };

    class GuardSimulation {
    private:
        vector<string> map;
        int height = 0;
        int width = 0;
        GuardPosition pos;

    public:
        GuardSimulation(const string& input) {
            parse(input);
        }

        GuardPosition& getGuardPosition() {
            return pos;
        }

        int getWidth() {
            return width;
        }

        int getHeight() {
            return height;
        }

        bool move() {
            for (int i = 0; i < 3; i++) {
                int nx = pos.x + pos.dx;
                int ny = pos.y + pos.dy;
                switch (getPositionStatus(nx, ny)) {
                case GuardSimulationPositionStatus::OFF_BOARD:
                    pos.x = nx;
                    pos.y = ny;
                    return false;
                case GuardSimulationPositionStatus::ON_BOARD:
                    pos.x = nx;
                    pos.y = ny;
                    return true;
                case GuardSimulationPositionStatus::BLOCKED:
                    pos.turnRight();
                    break;
                }
            }

            // They are blocked off.
            return false;
        }

        GuardSimulationPositionStatus getPositionStatus(int x, int y) {
            if (x < 0 || x >= width || y < 0 && y >= height) {
                return GuardSimulationPositionStatus::OFF_BOARD;
            }
            else if (map[y][x] == '#') {
                return GuardSimulationPositionStatus::BLOCKED;
            }
            else {
                return GuardSimulationPositionStatus::ON_BOARD;
            }
        }

        friend std::ostream& operator<<(std::ostream& os, const GuardSimulation& gs) {
            os << "GuardSimulation { width: " << gs.width << ", height: " << gs.height << ", pos: " << gs.pos << " }";
            return os;
        }

    private:
        bool setGuardPosition(int x, int y, char c) {
            switch (c) {
            case '^':
                pos = GuardPosition(x, y, -1, 0);
                return true;
            case 'v':
                pos = GuardPosition(x, y, 1, 0);
                return true;
            case '<':
                pos = GuardPosition(x, y, 0, -1);
                return true;
            case '>':
                pos = GuardPosition(x, y, 0, 1);
                return true;
            default:
                return false;
            }
        }

        void parse(const string& input) {
            map = ioReadLines(input);
            height = (int) map.size();

            if (height == 0) {
                throw SolverException("Invalid map with zero height.");
            }

            width = (int) map[0].size();
            if (width == 0) {
                throw SolverException("Invalid map with zero width.");
            }

            bool foundGuardPosition = false;
            for (int y = 0; y < height; y++) {
                if ((int)map[y].size() != width) {
                    throw SolverException("Invalid map with non-uniform width.");
                }
                for (int x = 0; x < width; x++) {
                    if (setGuardPosition(x, y, map[y][x])) {
                        if (foundGuardPosition) {
                            throw SolverException("More than 1 guard position found.");
                        }
                        else {
                            foundGuardPosition = true;
                        }
                    }
                }
            }
        }
    };

}

namespace rook::aoc::days {
    using namespace rook::aoc;
    using namespace std;

    string Day06::solvePart1(const string& input) {
        GuardSimulation gs(input);

        unordered_set<tuple<int, int>, TwoTupleIntHash> positions;
        do {
            auto& pos = gs.getGuardPosition();
            positions.insert(tuple(pos.x, pos.y));
        } while (gs.move());

        
        return to_string(positions.size());
    }

    string Day06::solvePart2(const string& input) {
        (void)input;
        return "";
    }
}