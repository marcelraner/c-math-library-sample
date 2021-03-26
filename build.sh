#!/usr/bin/env bash

set -o errexit
set -o nounset
set -o pipefail
# set -o xtrace

script_dir="$( cd "$(dirname "${BASH_SOURCE[0]}")" && pwd -P)"

pushd ${script_dir} > /dev/null

mkdir -p build
pushd build > /dev/null

clang \
    -c \
    -Wall \
    -o mymath.o \
    -I ../include \
    ../src/mymath.c

mkdir -p ../lib
ar \
    rc ../lib/libmymath.a \
    mymath.o

popd > /dev/null
popd > /dev/null
