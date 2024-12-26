#ifndef __PARSE_UTILS_HPP__
#define __PARSE_UTILS_HPP__

#include <string>
#include <vector>

namespace rook::aoc {
    std::vector<std::string> splitChar(const std::string& src, char c);
    std::vector<int> readNumberList(const std::string& src, char c);
}

#endif