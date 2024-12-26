#include "parse_utils.hpp"

namespace rook::aoc {
    using namespace std;

    vector<string> splitChar(const string& src, char c) {
        size_t pos = 0;
        size_t npos;
        vector<string> items;

        while ((npos = src.find(c, pos)) != string::npos) {
            if (npos > pos) {
                items.push_back(src.substr(pos, npos - pos));
            }
            pos = npos + 1;
        }
        if (npos > pos) {
            items.push_back(src.substr(pos, npos - pos));
        }

        return items;
    }

    vector<int> readNumberList(const string& src, char c) {
        vector<int> nums;
        for (auto& s : splitChar(src, c)) {
            nums.push_back(stoi(s));
        }
        return nums;
    }

}