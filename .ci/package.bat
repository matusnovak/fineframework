cd build

REM Do Debug only on devel branch
set "TARGETS=Debug MinSizeRel"

REM Which platform?
if "%MAKE%"=="MSBuild.exe" goto :msvc
if "%MAKE%"=="mingw32-make.exe" goto :mingw
REM Otherwise exit with error
exit /b

:msvc
echo "Packaging with Visual Studio"
REM Visual Studio
for %%i in (%TARGETS%) do  (
    echo "Packaging %%i..."
    cd build-%%i
    MSBuild.exe /p:Configuration=%%i "INSTALL.vcxproj" /verbosity:minimal || exit /b
    cd ..
)

echo "Building archive..."
7z.exe a "ffw-%ARCH%-%TOOLSET%.zip" .\install\* || exit /b

goto :end

:mingw
echo "Packaging with MinGW"
REM MinGW
for %%i in (%TARGETS%) do  (
    echo "Packaging %%i..."
    cd build-%%i
    mingw32-make.exe install
    cd ..
)

for /f %%i in ('gcc -dumpmachine') do set GCC_MACHINE=%%i
for /f %%i in ('gcc -dumpversion') do set GCC_VERSION=%%i

echo "Building archive..."
gcc -v > .\install\compiler-version.txt 2>&1
7z.exe a "ffw-%GCC_MACHINE%-%GCC_VERSION%.zip" .\install\* || exit /b

goto :end

:end

