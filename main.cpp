#include "memory.hpp"
#include "disk.hpp"
#include "cpu.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include <string>


int main() {
    std::cout << "=== ResilienceMonitor ===\n\n";

    printMemoryStats();
    printDiskStats();

    std::cout << "[CPU]\n";
    std::cout << "  Measuring CPU usage...\n";
    std::this_thread::sleep_for(std::chrono::seconds(1)); // allow time delta
    double cpu = calculateCpuUsage();
    std::cout << "  CPU Usage:     " << cpu << " %\n\n";

    std::cout << "Diagnostics complete.\n";
    return 0;
}