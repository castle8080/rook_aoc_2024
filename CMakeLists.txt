cmake_minimum_required(VERSION 3.15) # Minimum CMake version
project(rook_aoc_2024 VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCES_MAIN "src/*.cpp")
file(GLOB SOURCES_DAYS "src/days/*.cpp")

# Combine the results into a single variable
set(SOURCES ${SOURCES_MAIN} ${SOURCES_DAYS})

add_executable(rook_aoc_2024 ${SOURCES})
