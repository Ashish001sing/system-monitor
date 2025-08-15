cmake_minimum_required(VERSION 3.10)
project(ResilienceMonitor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ResilienceMonitor
    main.cpp
    memory.cpp
    disk.cpp
    cpu.cpp
)