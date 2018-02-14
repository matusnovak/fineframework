@ECHO OFF
mkdir install
set ABS_PATH=%CD%

SET PATH=%PATH:C:\Program Files\Git\usr\bin;=%
SET PATH=%PATH%;%MINGW_DIR_BIN%

REM Do Debug only on devel branch
set "TARGETS=Debug MinSizeRel"

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
    cmake .. -G %GENERATOR% -DCMAKE_INSTALL_PREFIX="..\install" || exit /b
    MSBuild.exe /p:Configuration=%%i "ALL_BUILD.vcxproj" /nologo /verbosity:minimal /consoleloggerparameters:summar || exit /b
    cd ..
)

goto :end

:mingw
echo "Building with MinGW"
REM MinGW
for %%i in (%TARGETS%) do  (
    echo "Building %%i..."
    mkdir build-%%i && cd build-%%i
    cmake .. -G %GENERATOR% -DCMAKE_BUILD_TYPE="%%i" -DCMAKE_INSTALL_PREFIX="..\install" || exit /b
    mingw32-make.exe all
    cd ..
)

goto :end

:end
