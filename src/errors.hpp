#ifndef __ERRORS_HPP__
#define __ERRORS_HPP__

#include <exception>
#include <stdexcept>

namespace rook::aoc {
    class SolverException : public std::exception {
    public:
        SolverException(const std::string& message) : message_(message) {}

        virtual const char* what() const noexcept override {
            return message_.c_str();
        }

    private:
        std::string message_;
    };
}

#endif