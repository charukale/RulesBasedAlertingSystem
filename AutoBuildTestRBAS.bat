@echo off
echo Building RulesBasedAlertingSystem solution.
echo Installing required package for building RulesBasedAlertingSystem solution.
NuGet.exe restore RulesBasedAlertingSys.sln > InstallPackage.txt
"C:\Program Files (x86)\Microsoft Visual Studio 14.0\Common7\IDE\devenv.exe" RulesBasedAlertingSys.sln /build "Debug|x86"
echo Build succeeded.
echo Running application
start /wait bin\RulesBasedAlertingSystem.exe
echo Starting Unit test case execution.
"C:\Program Files (x86)\Microsoft Visual Studio 14.0\Common7\IDE\CommonExtensions\Microsoft\TestWindow\vstest.console.exe" bin\TestAgent_RBAS.dll
pause