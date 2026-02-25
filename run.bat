@echo off
g++ main.cpp -o main.exe

if errorlevel 1 (
    echo Compilation failed.
) else (
    echo Compilation successful. Running program...
    main.exe
)

pause