mkdir dependencies
curl --fail --insecure -L -O https://github.com/matusnovak/fineframework/releases/download/v0.2.5-deps/%ARCH%-%TOOLSET%.zip || exit /b
7z x %ARCH%-%TOOLSET%.zip -odependencies > nul || exit /b