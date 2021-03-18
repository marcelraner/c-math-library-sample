#!/usr/bin/env bash

set -o errexit
set -o nounset
set -o pipefail
# set -o xtrace

script_dir="$( cd "$(dirname "${BASH_SOURCE[0]}")" && pwd -P)"

pushd ${script_dir} > /dev/null

mkdir -p build
pushd build > /dev/null

mkdir -p ../bin
clang -Wall -o ../bin/test_math ../tests/test_math.c -L../lib -lmath

popd > /dev/null

pushd bin > /dev/null
./test_math
popd > /dev/null

popd > /dev/null
