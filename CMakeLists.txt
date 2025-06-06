cmake_minimum_required(VERSION 3.25)
project(logger VERSION 0.1.0 LANGUAGES C CXX)

# Generate config.h from template
configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/include/config.h.in
  ${CMAKE_CURRENT_BINARY_DIR}/include/config.h
)

# Create the logger library
add_library(logger src/logger.cpp)

# Include directories for public and private use
target_include_directories(logger PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_include_directories(logger PRIVATE
  ${CMAKE_CURRENT_BINARY_DIR}/include
)

# Build example only in non-Release builds
if(NOT CMAKE_BUILD_TYPE STREQUAL "Release")
  message(STATUS "Building example")
  add_subdirectory(example)
else()
  message(STATUS "Skipping example build in Release mode")
endif()
