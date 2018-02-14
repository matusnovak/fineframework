#!/bin/bash
set -e

# Do Debug only on devel branch
TARGETS=("Debug" "MinSizeRel")

for i in "${TARGETS[@]}"
do
    echo "Packaging $i..."
    cd "build-$i"
    make install
    cd ..
done

GCC_MACHINE=$(gcc -dumpmachine)
GCC_VERSION=$(gcc -dumpversion)

cd install
gcc -v &> compiler-version.txt
zip -r "../ffw-$GCC_MACHINE-$GCC_VERSION.zip" *
