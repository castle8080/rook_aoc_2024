#!/bin/bash

if [ ! -d build ]; then
    mkdir build
fi

cd build

cmake -DCMAKE_BUILD_TYPE=Release .. || exit 1;
make || exit 1;

exec ./rook_aoc_2024
