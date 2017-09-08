@ECHO OFF

REM Do Debug only on devel branch
set "TARGETS=Debug"
REM Do Debug+Release only on master branch
if "%APPVEYOR_REPO_BRANCH%"=="master" (set "TARGETS=Debug Release")

for %%i in (%TARGETS%) do  (
    if "%%i"=="Debug" (
        if "%TOOLSET%"=="vc12" (
            echo "Skipping Debug tests for Visual Studio 2013"
            goto :end
        )
    )
    echo "Testing %%i"
    cd build-%%i
    ctest --verbose -C %%i || exit /b
    cd ..
)

:end
