# eits-hott/cmake/BuildOptions.cmake

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
option(EITS_ENABLE_DEBUG "Enable EITS debug mode" ON)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang|AppleClang")
	if(CMAKE_BUILD_TYPE STREQUAL "Release")
		add_compile_options(-Wall -Wextra -Werror -Wpedantic)
	endif()
elseif (MSVC)
	if(CMAKE_BUILD_TYPE STREQUAL "Release")
		add_compile_options(/W4 /WX)
	endif()
endif()

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
	set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the build type." FORCE)
endif()

message(STATUS "[EITS] Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "[EITS] Supported build types: Debug, Release, RelWithDebInfo, MinSizeRel")

set(TEMPLATE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/cmake/template")

configure_file(
  "${TEMPLATE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/eits-hott/generated/include/EITS/common.h"
  @ONLY
)
