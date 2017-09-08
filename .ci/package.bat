cd build
if "%MAKE%"=="MSBuild.exe" (
    MSBuild.exe /p:Configuration=%CONFIGURATION% "INSTALL.vcxproj" /verbosity:minimal || exit /b
)
cd ..
7z.exe a "ffw-%ARCH%-%TOOLSET%.zip" .\install\* || exit /b

:done