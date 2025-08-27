

set /p username="Enter the username (domain\username or .\username for local): "
if not defined username (
    echo You must enter a username.
    echo.
    goto Username
)


:Password
echo.
set "password="
set /p password="Enter the password (input will be visible): "
if not defined password (
    echo You must enter a password or a space if none.
    echo.
    goto Password
)


echo.
echo Attempting to assign the network drive...
net use %NetworkDrive%: /delete >nul 2>&1
net use %NetworkDrive%: "%networkPath%" /user:"%username%" "%password%" /persistent:yes
if %errorlevel% == 0 (
    echo Network drive %NetworkDrive%: has been successfully assigned.
) else (
    echo Failed to assign the network drive.
)
echo.
pause
goto main




:quit
cls
color 7
exit /b
