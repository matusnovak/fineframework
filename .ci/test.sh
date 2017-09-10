#!/bin/bash
set -e

# Do Debug only on devel branch
TARGETS=("Debug")
# Do Debug+MinSizeRel only on master branch
if [ "$TRAVIS_BRANCH"=="master" ]; then
     TARGETS=("Debug" "MinSizeRel")
fi

for i in "${TARGETS[@]}"
do
    echo "Testing $i..."
    cd "build-$i"
    ctest --verbose -C %%i || exit /b
    cd ..
done

