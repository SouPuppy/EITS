# src/kernel/runtime/CMakeLists.txt

file(GLOB SOURCE_CODE
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(eits_hott_kernel_runtime STATIC
	${SOURCE_CODE}
)

target_include_directories(eits_hott_kernel_runtime
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../..
)

target_link_libraries(eits_hott_kernel_runtime
	PRIVATE
		logger
  PUBLIC
		internal_instructions
		eits_hott_headers
)
