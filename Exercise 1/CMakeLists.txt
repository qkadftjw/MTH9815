# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(Exercise1 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set Export Compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Specify the GCC compiler
set(CMAKE_CXX_COMPILER "/usr/bin/g++-13")
set(CMAKE_C_COMPILER "/usr/bin/gcc-13")

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/src)

# Source files
set(SRC_FILES
    src/LinkedList.cpp
    src/ListIterator.cpp
    src/ListNode.cpp
)

# Add main test executable
add_executable(test_linkedlist
    ${SRC_FILES}
    src/test_linkedlist.cpp
)