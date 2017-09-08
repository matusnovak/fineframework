@ECHO OFF
SETLOCAL

for /f %%i in ('git rev-parse HEAD') do SET LATEST_COMMIT_HASH=%%i
echo "Hash: %LATEST_COMMIT_HASH%"

git describe --abbrev=0 --tags --exact-match %LATEST_COMMIT_HASH% || goto :increment
goto :usecurrent

:increment
echo "Incrementing tag..."

for /f %%i in ('git describe --abbrev^=0 --tags') do SET LATEST_TAG=%%i

echo "Latest tag: %LATEST_TAG%"

for /F "tokens=1,2,3 delims=.-" %%a in ("%LATEST_TAG%") do (
   SET MAJOR=%%a
   SET MINOR=%%b
   SET PATCH=%%c
)

set /A PATCH+=1
set GITHUB_RELEASE_TAG=%MAJOR%.%MINOR%.%PATCH%
echo "GitHub Release tag: %GITHUB_RELEASE_TAG%"

goto :end

:usecurrent
echo "Using the same tag..."

for /f %%i in ('git describe --abbrev^=0 --tags') do SET LATEST_TAG=%%i

echo "Latest tag: %LATEST_TAG%"
set GITHUB_RELEASE_TAG=%LATEST_TAG%
echo "GitHub Release tag: %GITHUB_RELEASE_TAG%"

:end
appveyor SetVariable -Name APPVEYOR_REPO_TAG_NAME -Value %GITHUB_RELEASE_TAG%
echo "End!"