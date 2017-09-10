#!/bin/bash
set -e

LATEST_COMMIT_HASH=`git rev-parse HEAD`
echo "Hash: $LATEST_COMMIT_HASH"

if git describe --abbrev=0 --tags --exact-match $LATEST_COMMIT_HASH ; then
echo "Using the same tag..."

LATEST_TAG=`git describe --abbrev=0 --tags`
GITHUB_RELEASE_TAG="$LATEST_TAG"

else
echo "Incrementing tag..."

LATEST_TAG=`git describe --abbrev=0 --tags`
echo "Latest tag: $LATEST_TAG"

tokens=(${LATEST_TAG//./ })

MAJOR=${tokens[0]}
MINOR=${tokens[1]}
PATCH=${tokens[2]}

PATCH=$((PATCH+1))

GITHUB_RELEASE_TAG="$MAJOR.$MINOR.$PATCH"
echo "GitHub Release tag: $GITHUB_RELEASE_TAG"
git tag -a "$GITHUB_RELEASE_TAG" -m "$GITHUB_RELEASE_TAG"

fi
export GITHUB_RELEASE_TAG=$GITHUB_RELEASE_TAG
# Set tag
echo "End!"
