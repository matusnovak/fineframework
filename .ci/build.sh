#!/bin/bash
set -e
mkdir install
ABS_PATH=`pwd`

# Do Debug only on devel branch
TARGETS=("Debug")
# Do Debug+MinSizeRel only on master branch
if [ "$TRAVIS_BRANCH"=="master" ]; then
     TARGETS=("Debug" "MinSizeRel")
fi

for i in "${TARGETS[@]}"
do
    echo "Building $i..."
    mkdir "build-$i" && cd "build-$i"
    cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE="$i" -DCMAKE_LIBRARY_PATH="$ABS_PATH/dependencies/$ARCH-$TOOLSET/lib" -DINCLUDE_DIRECTORIES="$ABS_PATH/dependencies/$ARCH-$TOOLSET/include" -DCMAKE_INSTALL_PREFIX="../install"
    make all
    cd ..
done


