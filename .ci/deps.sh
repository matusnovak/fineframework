#!/bin/bash
set -e
mkdir dependencies
curl --fail --insecure -L -O https://github.com/matusnovak/fineframework/releases/download/v0.2.5-deps/$ARCH-$TOOLSET.zip
unzip $ARCH-$TOOLSET.zip -d dependencies
