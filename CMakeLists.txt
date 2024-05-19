cmake_minimum_required(VERSION 3.4)

# Project name
project(Singleton)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)
set(VERSION_TWEAK 0)
set(VERSION\${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}.${VERSION_TWEAK})
set(VERSION_STRING "v${VERSION}")

option(BUILD_TESTS "Build tests" OFF)

add_executable(singleton singleton.cpp)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(third-party/gtest)
    file(GLOB tests "tests/*.cpp")
    foreach(test ${tests})
         add_executable(check ${test})
         target_link_libraries(check gtest_main gmock_main)
         add_test(NAME check COMMAND check)
    endforeach(test ${tests})
endif()

include(CPackConfig.cmake)
