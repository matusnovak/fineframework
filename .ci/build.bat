@ECHO OFF
mkdir install
set ABS_PATH=%CD%

SET PATH=%PATH:C:\Program Files\Git\usr\bin;=%
SET PATH=%PATH%;%MINGW_DIR_BIN%

REM Do Debug only on devel branch
set "TARGETS=Debug"
REM Do Debug+Release only on master branch
if "%APPVEYOR_REPO_BRANCH%"=="master" (set "TARGETS=Debug Release")

REM Which platform?
if "%MAKE%"=="MSBuild.exe" goto :msvc
if "%MAKE%"=="mingw32-make.exe" goto :mingw
REM Otherwise exit with error
exit /b

:msvc
echo "Building with Visual Studio"
REM Visual Studio
for %%i in (%TARGETS%) do  (
    echo "Building %%i..."
    mkdir build-%%i && cd build-%%i
    cmake .. -G %GENERATOR% -DCMAKE_LIBRARY_PATH="%ABS_PATH%\dependencies\%ARCH%-%TOOLSET%\lib" -DINCLUDE_DIRECTORIES="%ABS_PATH%\dependencies\%ARCH%-%TOOLSET%\include" -DCMAKE_INSTALL_PREFIX="..\install" || exit /b
    MSBuild.exe /p:Configuration=%%i "ALL_BUILD.vcxproj" /verbosity:minimal || exit /b
    cd ..
)

goto :end

:mingw
echo "Building with MinGW"
REM MinGW
for %%i in (%TARGETS%) do  (
    echo "Building %%i..."
    mkdir build-%%i && cd build-%%i
    cmake .. -G %GENERATOR% -DCMAKE_BUILD_TYPE="%%i" -DCMAKE_LIBRARY_PATH="%ABS_PATH%\dependencies\%ARCH%-%TOOLSET%\lib" -DINCLUDE_DIRECTORIES="%ABS_PATH%\dependencies\%ARCH%-%TOOLSET%\include" -DCMAKE_INSTALL_PREFIX="..\install" || exit /b
    mingw32-make.exe all
    cd ..
)

goto :end

:end

