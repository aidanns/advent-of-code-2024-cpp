#!/usr/bin/env bash

SCRIPT_DIR=$(cd -P -- "$(dirname -- "$0")" && pwd -P)

cd ${SCRIPT_DIR} || exit 1

rm -rf ./build
rm -rf ./cmake-build-*
