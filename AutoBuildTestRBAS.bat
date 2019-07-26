@echo off
echo Building RulesBasedAlertingSystem solution.
"C:\Program Files (x86)\Microsoft Visual Studio 14.0\Common7\IDE\devenv.exe" RulesBasedAlertingSys.sln /build debug
echo Build succeeded.
echo Running application
"bin\RulesBasedAlertingSystem.exe"
