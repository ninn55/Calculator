@echo off
cd ../../bin/debug/

if not exist test1.exe (
	echo Please build test1 first.
	pause
	exit
)

FOR /L %%A IN (1,1,50) DO (
	echo %%A :
	.\test1.exe
	echo .
)

pause