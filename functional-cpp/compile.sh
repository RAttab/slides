#! /usr/bin/env bash

set -o errexit -o nounset -o pipefail -o xtrace

declare -a SRC
SRC=(00.fib 01.constexpr 02.typedef 03.template 04.baby 05.tuple 06.list)

CXX=${CXX:-g++}
CXXFLAGS="-O3 -pipe -std=c++11 -Werror -Wall -Wextra -Weffc++"

mkdir build || true

for src in "${SRC[@]}"; do
    $CXX -o ./build/$src "$src.cpp" $CXXFLAGS
done

for src in "${SRC[@]}"; do
    "./build/$src"
done
