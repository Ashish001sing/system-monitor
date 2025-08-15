#include "disk.hpp"
#include <windows.h>
#include <iostream>

void printDiskStats(const std::wstring& drive) {
    ULARGE_INTEGER freeBytesAvailable, totalBytes, totalFreeBytes;

    if (GetDiskFreeSpaceExW(drive.c_str(), &freeBytesAvailable, &totalBytes, &totalFreeBytes)) {
        std::wcout << L"[Disk]\n";
        std::wcout << L"  Drive:         " << drive << L"\n";
        std::wcout << L"  Total Space:   " << totalBytes.QuadPart / (1024 * 1024 * 1024) << L" GB\n";
        std::wcout << L"  Free Space:    " << totalFreeBytes.QuadPart / (1024 * 1024 * 1024) << L" GB\n\n";
    }
    else {
        std::wcerr << L"[Disk] Failed to retrieve stats.\n\n";
    }
}