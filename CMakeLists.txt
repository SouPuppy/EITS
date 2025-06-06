# CMakeLists.txt

cmake_minimum_required(VERSION 3.25.0)

include(cmake/ProjectVersion.cmake) 
project(Machinish VERSION ${PROJECT_VERSION} LANGUAGES C CXX)

include(cmake/BuildOptions.cmake)
include(cmake/Version.cmake)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Options
option(ENABLE_TESTING "Enable testing" ON)
option(BUILD_EXAMPLES "Build examples" ON)

# Libraries
add_subdirectory(lib/logger)
option(ENABLE_LOG_VERBOSE "Enable verbose logging" ON)

# Source Code
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
