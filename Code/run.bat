echo off
start "Sorting Server"  .\Sorting.exe

echo on
echo "Wait for some time until the web server completes the sorting and waits for connection"
timeout /T 45
echo off
start "Client Program"  .\SortingClient.exe

start "Running web browser" .\run_code.py

