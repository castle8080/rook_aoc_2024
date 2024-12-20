cmake_minimum_required(VERSION 3.15) # Minimum CMake version
project(rook_aoc_2024 VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCES_MAIN "src/*.cpp")
file(GLOB SOURCES_DAYS "src/days/*.cpp")

# Combine the results into a single variable
set(SOURCES ${SOURCES_MAIN} ${SOURCES_DAYS})

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # GCC/Clang: Enable all warnings and treat them as errors
    set(STRICT_WARNING_FLAGS -Wall -Wextra -Wpedantic -Werror)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # MSVC: Enable all warnings and treat them as errors
    set(STRICT_WARNING_FLAGS /W4 /WX)
endif()

add_compile_options(${STRICT_WARNING_FLAGS})

add_executable(rook_aoc_2024 ${SOURCES})
