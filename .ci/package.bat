cd build

REM Do Debug only on devel branch
set "TARGETS=Debug"
REM Do Debug+MinSizeRel only on master branch
if "%APPVEYOR_REPO_BRANCH%"=="master" (set "TARGETS=Debug MinSizeRel")

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
goto :end

:end
echo "Building archive..."
7z.exe a "ffw-%ARCH%-%TOOLSET%.zip" .\install\* || exit /b
