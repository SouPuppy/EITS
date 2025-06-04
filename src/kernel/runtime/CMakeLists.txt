# src/kernel/runtime/CMakeLists.txt

file(GLOB SOURCE_CODE
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(machinish_kernel_runtime STATIC
	${SOURCE_CODE}
)

target_include_directories(machinish_kernel_runtime
  PRIVATE
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(machinish_kernel_runtime
  PUBLIC
    machinish_headers
)
