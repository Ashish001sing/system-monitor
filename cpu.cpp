#include "cpu.hpp"
#include <windows.h>

double calculateCpuUsage() {
    FILETIME idleTime, kernelTime, userTime;
    if (!GetSystemTimes(&idleTime, &kernelTime, &userTime)) return -1.0;

    ULARGE_INTEGER idle, kernel, user;
    idle.LowPart = idleTime.dwLowDateTime;     idle.HighPart = idleTime.dwHighDateTime;
    kernel.LowPart = kernelTime.dwLowDateTime; kernel.HighPart = kernelTime.dwHighDateTime;
    user.LowPart = userTime.dwLowDateTime;     user.HighPart = userTime.dwHighDateTime;

    static ULARGE_INTEGER prevIdle = idle, prevKernel = kernel, prevUser = user;

    ULONGLONG idleDiff = idle.QuadPart - prevIdle.QuadPart;
    ULONGLONG kernelDiff = kernel.QuadPart - prevKernel.QuadPart;
    ULONGLONG userDiff = user.QuadPart - prevUser.QuadPart;

    prevIdle = idle; prevKernel = kernel; prevUser = user;

    ULONGLONG total = kernelDiff + userDiff;
    return total ? (100.0 * (total - idleDiff) / total) : 0.0;
}