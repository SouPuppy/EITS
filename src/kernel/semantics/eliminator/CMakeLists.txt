# src/kernel/runtime/CMakeLists.txt

file(GLOB SOURCE_CODE
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(machinish_kernel_semantics_eliminator STATIC
	${SOURCE_CODE}
)

target_link_libraries(machinish_kernel_semantics_eliminator
	PRIVATE
		logger
  PUBLIC
		machinish_headers
)
