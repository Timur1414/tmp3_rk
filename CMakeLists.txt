cmake_minimum_required(VERSION 3.10)

# Project name
project(Singleton)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(${PROJECT_SOURCE_DIR})

# Add source files
set(SOURCES
    singleton.cpp
)

# Add executable
add_executable(Singleton ${SOURCES})

enable_testing()

add_subdirectory(tests)
