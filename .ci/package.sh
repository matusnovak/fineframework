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
    echo "Packaging $i..."
    cd "build-$i"
    make install
    cd ..
done

cd install
zip -r "../ffw-$ARCH-$TOOLSET.zip" *
