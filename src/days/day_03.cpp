#include "day_03.hpp"

#include <regex>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <variant>

#include "../errors.hpp"
#include "../io_utils.hpp"

namespace {
    using namespace rook::aoc;
    using namespace std;

    struct MultiplierOp {
        int left;
        int right;

        MultiplierOp(int _left, int _right): left(_left), right(_right) { }
    };

    struct MultiplerEnableOp {
        bool enabled;

        MultiplerEnableOp(bool _enabled): enabled(_enabled) { }
    };

    using Operation = variant<MultiplierOp, MultiplerEnableOp>;

    static regex MUL_REGEX_N("(mul)\\((\\d{1,3}),(\\d{1,3})\\)|(do|don't)\\(\\)");

    void parseOperations(const vector<string>& lines, vector<Operation>& operations) {
        auto words_end = sregex_iterator();

        for (auto& line : lines) {
            auto words_begin = sregex_iterator(line.begin(), line.end(), MUL_REGEX_N);
            for (auto i = words_begin; i != words_end; ++i) {
                if (i->str(1) == "mul") {
                    operations.push_back(MultiplierOp(stoi(i->str(2)), stoi(i->str(3))));
                }
                else if (i->str(4) == "do") {
                    operations.push_back(MultiplerEnableOp(true));
                }
                else if (i->str(4) == "don't") {
                    operations.push_back(MultiplerEnableOp(false));
                }
            }
        }
    }

    string solve(const string& input, bool multiplierControlEnabled) {
        auto lines = ioReadLines(input);
        vector<Operation> operations;

        parseOperations(lines, operations);

        int total = 0;
        bool multiplierEnabled = true;

        for (auto& op : operations) {
            if (auto mop = std::get_if<MultiplierOp>(&op)) {
                if (multiplierEnabled) {
                    total += mop->left * mop->right;
                }
            }
            else if (auto meop = std::get_if<MultiplerEnableOp>(&op)) {
                if (multiplierControlEnabled) {
                    multiplierEnabled = meop->enabled;
                }
            }
        }

        return to_string(total);
    }
}

namespace rook::aoc::days {

    using namespace rook::aoc;
    using namespace std;


    string Day03::solvePart1(const string& input) {
        return solve(input, false);
    }

    string Day03::solvePart2(const string& input) {
        return solve(input, true);
    }
}