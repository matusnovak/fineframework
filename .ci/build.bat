mkdir build
mkdir install
set ABS_PATH=%CD%
cd build

SET PATH=%PATH:C:\Program Files\Git\usr\bin;=%
SET PATH=%PATH%;%MINGW_DIR_BIN%

if "%MAKE%"=="MSBuild.exe" (
    cmake .. -G %GENERATOR% -DCMAKE_LIBRARY_PATH="%ABS_PATH%\dependencies\%ARCH%-%TOOLSET%\lib" -DINCLUDE_DIRECTORIES="%ABS_PATH%\dependencies\%ARCH%-%TOOLSET%\include" -DCMAKE_INSTALL_PREFIX="..\install" || exit /b
    MSBuild.exe /p:Configuration=%CONFIGURATION% "ALL_BUILD.vcxproj" /verbosity:minimal || exit /b
)

cd ..