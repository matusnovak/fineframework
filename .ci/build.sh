#!/bin/bash
set -e
mkdir install
ABS_PATH=`pwd`

# Do Debug only on devel branch
TARGETS=("Debug" "MinSizeRel")

for i in "${TARGETS[@]}"
do
    echo "Building $i..."
    mkdir "build-$i" && cd "build-$i"
    cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE="$i" -DCMAKE_INSTALL_PREFIX="../install"
    make all
    cd ..
done
