# CMakeLists.txt
cmake_minimum_required(VERSION 3.25.0)

include(cmake/ProjectVersion.cmake) 
project(Machinish VERSION ${PROJECT_VERSION} LANGUAGES C CXX)

include(cmake/BuildOptions.cmake)
include(cmake/Version.cmake)

# Options
option(ENABLE_TESTING "Enable testing" ON)
option(BUILD_EXAMPLES "Build examples" ON)

# Subdirectories

## Source File
add_subdirectory(src)

## Examples
if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

# Testing
if(ENABLE_TESTING)
    enable_testing()
    add_subdirectory(test)
endif()

# Install


message(STATUS "[Machinish] Build type: ${CMAKE_BUILD_TYPE}")
