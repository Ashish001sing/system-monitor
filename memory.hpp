
#include <windows.h>
#include <iostream>

void printMemoryStats() {
    MEMORYSTATUSEX memInfo{};
    memInfo.dwLength = sizeof(memInfo);

    if (GlobalMemoryStatusEx(&memInfo)) {
        DWORDLONG total = memInfo.ullTotalPhys;
        DWORDLONG avail = memInfo.ullAvailPhys;

        std::cout << "[Memory]\n";
        std::cout << "  Total RAM:     " << total / (1024 * 1024) << " MB\n";
        std::cout << "  Available RAM: " << avail / (1024 * 1024) << " MB\n\n";
    }
    else {
        std::cerr << "[Memory] Failed to retrieve stats.\n\n";
    }
}