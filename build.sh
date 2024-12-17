#!/usr/bin/env bash

SCRIPT_DIR=$(cd -P -- "$(dirname -- "$0")" && pwd -P)

cd ${SCRIPT_DIR} || exit 1

cmake -S . -B build
cmake --build build
