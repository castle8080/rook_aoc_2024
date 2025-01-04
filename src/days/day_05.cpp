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
        PageUpdates(const string& fileName) {
            parse(fileName);
        }

        const vector<vector<int>>& getReplacementLines() {
            return replacements;
        }

        const unordered_set<int>* getBeforesOf(int n) {
            auto it = rules.find(n);
            if (it == rules.end()) {
                return nullptr;
            }
            else {
                return &it->second;
            }
        }

        bool isValidReplacementLine(const vector<int>& replacementLine) {
            unordered_set<int> invalids;

            for (auto n : replacementLine) {
                if (invalids.find(n) != invalids.end()) {
                    return false;
                }
                else {
                    auto befores = getBeforesOf(n);
                    if (befores != nullptr) {
                        for (auto b : *befores) {
                            invalids.insert(b);
                        }
                    }
                }
            }

            return true;
        }

        int fixReplacementLine(vector<int>& replacementLine) {
            int changes = -1;
            int totalChanges = 0;
            int scans = 0;

            while (changes != 0) {
                if (scans > replacementLine.size()) {
                    throw SolverException("There is no solution for this line.");
                }
                changes = 0;
                for (int i = 0; i < replacementLine.size() - 1; i++) {
                    for (int j = i+1; j < replacementLine.size(); j++) {
                        if (!validateOrder(replacementLine[i], replacementLine[j])) {
                            int tmp = replacementLine[i];
                            replacementLine[i] = replacementLine[j];
                            replacementLine[j] = tmp;
                            changes++;
                            totalChanges++;
                        }
                    }
                }
                scans++;
            }

            return totalChanges;
        }

    private:
        unordered_map<int, unordered_set<int>> rules;
        vector<vector<int>> replacements;
        
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

        void parseRuleLine(const string& line) {
            auto rule = readNumberList(line, '|');
            if (rule.size() != 2) {
                throw SolverException("Invalid rule: " + line);
            }
            int bn = rule[0];
            int an = rule[1];

            auto it = rules.find(an);
            if (it != rules.end()) {
                it->second.insert(bn);
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

        bool validateOrder(int a, int b) {
            auto befores = getBeforesOf(a);
            if (befores != nullptr && befores->find(b) != befores->end()) {
                return false;
            }
            else {
                return true;
            }
        }
    };

    int getMiddleValue(const vector<int>& replacementLine) {
        return replacementLine[replacementLine.size() / 2];
    }
}

namespace rook::aoc::days {
    using namespace rook::aoc;
    using namespace std;

    string Day05::solvePart1(const string& input) {
        PageUpdates updates(input);

        int total = 0;
        for (auto replacementLine : updates.getReplacementLines()) {
            if (updates.isValidReplacementLine(replacementLine)) {
                total += getMiddleValue(replacementLine);
            }
        }

        return to_string(total);
    }

    string Day05::solvePart2(const string& input) {
        PageUpdates updates(input);
        
        int total = 0;
        for (auto replacementLine : updates.getReplacementLines()) {
            vector<int> newLine(replacementLine);
            if (updates.fixReplacementLine(newLine) != 0) {
                total += getMiddleValue(newLine);
            }
        }

        return to_string(total);
    }
}