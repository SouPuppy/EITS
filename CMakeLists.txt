# CMakeLists.txt

cmake_minimum_required(VERSION 3.25.0)

project(EITS LANGUAGES C CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/eits-hott/cmake")

add_subdirectory(eits-hott)
add_subdirectory(eits-repl)

# Options
option(ENABLE_TESTING "Enable testing" ON)
option(BUILD_EXAMPLES "Build examples" ON)

## Examples
if(BUILD_EXAMPLES)
	add_subdirectory(examples)
endif()

# Testing
if(ENABLE_TESTING)
	enable_testing()
  add_subdirectory(test)
endif()
