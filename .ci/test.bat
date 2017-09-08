cd build

if NOT "%TOOLSET%"=="vc12" goto :test
if NOT "%CONFIGURATION%"=="Debug" goto :test
echo "Skipping tests on Visual Studio 2013 in Debug mode..."
goto :done

:test
ctest --verbose -C %CONFIGURATION% || exit /b

:done
cd ..
