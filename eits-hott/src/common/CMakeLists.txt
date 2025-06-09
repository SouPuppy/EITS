# eits-hott/src/common/CMakeLists.txt

add_library(eits_hott_headers INTERFACE)

target_include_directories(eits_hott_headers
	INTERFACE
    ../../include
		${CMAKE_BINARY_DIR}/eits-hott/generated/include
)

get_target_property(RUNTIME_INCLUDE_DIRS eits_hott_headers INTERFACE_INCLUDE_DIRECTORIES)
message(STATUS "[Debug] eits_hott_headers includes: ${RUNTIME_INCLUDE_DIRS}")
