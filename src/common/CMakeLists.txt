# src/common/CMakeLists.txt

add_library(machinish_headers INTERFACE)

target_include_directories(machinish_headers
	INTERFACE
		${PROJECT_SOURCE_DIR}/include
		${CMAKE_BINARY_DIR}/generated/include
)

get_target_property(RUNTIME_INCLUDE_DIRS machinish_headers INTERFACE_INCLUDE_DIRECTORIES)
message(STATUS "[Debug] machinish_headers includes: ${RUNTIME_INCLUDE_DIRS}")
