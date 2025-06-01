# cmake/BuildOptions.cmake

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
option(MACHINISH_ENABLE_DEBUG "Enable Machinish debug mode" ON)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang|AppleClang")
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
elseif (MSVC)
    add_compile_options(/W4 /WX)
endif()

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the build type." FORCE)
endif()

message(STATUS "[Machinish] Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "[Machinish] Supported build types: Debug, Release, RelWithDebInfo, MinSizeRel")

# Configure config.h from template
configure_file(
  "${CMAKE_SOURCE_DIR}/cmake/template/config.h.in"
  "${PROJECT_BINARY_DIR}/generated/include/Machinish/common.h"
  @ONLY
)
