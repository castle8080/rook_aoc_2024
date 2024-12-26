#include "day_05.hpp"

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iterator>
#include <string>
#include <variant>

#include "../errors.hpp"
#include "../io_utils.hpp"
#include "../parse_utils.hpp"

namespace {
    using namespace rook::aoc;
    using namespace std;

    class PageUpdates {
    public:
        void parse(const string& fileName) {
            auto lines = ioReadLines(fileName);

            for (auto& line : lines) {
                if (line.find('|') != string::npos) {
                    parseRuleLine(line);
                }
                else if (line.find(',') != string::npos) {
                    parseReplacementLine(line);
                }
                else if (line.size() == 0) {
                    ; // skip
                }
                else {
                    throw SolverException("Invalid line: " + line);
                }
            }
        }

        const vector<vector<int>>& getReplacementLines() {
            return replacements;
        }

        const vector<int>* getBeforesOf(int n) {
            auto it = rules.find(n);
            if (it == rules.end()) {
                return nullptr;
            }
            else {
                return &it->second;
            }
        }

    private:
        unordered_map<int, vector<int>> rules;
        vector<vector<int>> replacements;

        void parseRuleLine(const string& line) {
            auto rule = readNumberList(line, '|');
            if (rule.size() != 2) {
                throw SolverException("Invalid rule: " + line);
            }
            int bn = rule[0];
            int an = rule[1];

            auto it = rules.find(an);
            if (it != rules.end()) {
                it->second.push_back(bn);
            }
            else {
                rules[an] = { bn };
            }
        }

        void parseReplacementLine(const string& line) {
            auto replacementLine = readNumberList(line, ',');
            if (replacementLine.size() > 0) {
                replacements.push_back(move(replacementLine));
            }
        }
    };

    bool isValidReplacementLine(PageUpdates& updates, const vector<int>& replacementLine) {
        unordered_set<int> invalids;

        for (auto n : replacementLine) {
            if (invalids.find(n) != invalids.end()) {
                return false;
            }
            else {
                auto befores = updates.getBeforesOf(n);
                if (befores != nullptr) {
                    for (auto b : *befores) {
                        invalids.insert(b);
                    }
                }
            }
        }

        return true;
    }

    int getMiddleValue(const vector<int>& replacementLine) {
        return replacementLine[replacementLine.size() / 2];
    }
}

namespace rook::aoc::days {
    using namespace rook::aoc;
    using namespace std;

    string Day05::solvePart1(const string& input) {
        PageUpdates updates;
        updates.parse(input);

        int total = 0;
        for (auto replacementLine : updates.getReplacementLines()) {
            if (isValidReplacementLine(updates, replacementLine)) {
                total += getMiddleValue(replacementLine);
            }
        }

        return to_string(total);
    }

    string Day05::solvePart2(const string& input) {
        (void)input;

        return "";
    }
}