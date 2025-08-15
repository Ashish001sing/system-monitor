<!-- Uploading "systemdesign - main.cpp - Microsoft Visual Studio 2025-08-15 22-19-10.mp4"... -->
 
 # 🛡️ ResilienceMonitor

A native Windows CLI tool for disaster diagnostics. Built in C++ using WinAPI, it reports system health metrics to ensure field devices are operational and responsive.

## Features
- RAM availability via `GlobalMemoryStatusEx`
- Disk space via `GetDiskFreeSpaceEx`
- CPU load via `GetSystemTimes`
- Modular design for easy extension

## Build

```bash
mkdir build && cd build
cmake ..
cmake --build .
