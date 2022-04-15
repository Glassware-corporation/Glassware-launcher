@echo off

:start
cls
echo conpileing...
g++ main.cpp fixgwsffile.cpp exit.cpp -o bin/out
echo ===start===
bin\out.exe
echo ===end===
rm NULL