# eits-hott/CMakeLists.txt

set(CMAKE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR} CACHE INTERNAL "" FORCE)
set(CMAKE_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR} CACHE INTERNAL "" FORCE)

include(BuildOptions)
include(Version)

# Libraries
add_subdirectory(lib/logger)
option(ENABLE_LOG_VERBOSE "Enable verbose logging" ON)

# Source Code
add_subdirectory(src)

# Install
message(STATUS "[EITS] Build type: ${CMAKE_BUILD_TYPE}")
