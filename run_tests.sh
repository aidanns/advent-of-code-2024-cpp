#!/usr/bin/env bash

SCRIPT_DIR=$(cd -P -- "$(dirname -- "$0")" && pwd -P)

cd ${SCRIPT_DIR} || exit 1

./build/advent_of_code_2024_cpp_test
