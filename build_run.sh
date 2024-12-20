#!/bin/bash

if [ ! -d build ]; then
    mkdir build
fi

cd build

cmake .. || exit 1;
make || exit 1;

exec ./rook_aoc_2024
