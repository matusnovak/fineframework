#!/bin/bash
set -e

# Do Debug only on devel branch
TARGETS=("Debug" "MinSizeRel")

for i in "${TARGETS[@]}"
do
    echo "Testing $i..."
    cd "build-$i"
    ctest --verbose -C %%i || exit /b
    cd ..
done

