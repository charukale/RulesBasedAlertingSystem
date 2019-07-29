@echo off
echo Building RulesBasedAlertingSystem solution.
"C:\Program Files (x86)\Microsoft Visual Studio 14.0\Common7\IDE\devenv.exe" RulesBasedAlertingSys.sln /build debug
echo Build succeeded.
echo Running application
start /wait bin\RulesBasedAlertingSystem.exe
echo Starting Unit test case execution.
"C:\Program Files (x86)\Microsoft Visual Studio 14.0\Common7\IDE\CommonExtensions\Microsoft\TestWindow\vstest.console.exe" bin\UnitTest2.dll
pause