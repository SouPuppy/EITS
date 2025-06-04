# src/kernel/basis/CMakeLists.txt

file(GLOB SOURCE_CODE
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(machinish_kernel_basis STATIC
	${SOURCE_CODE}
)

target_include_directories(machinish_kernel_basis
  PRIVATE
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(machinish_kernel_basis
  PUBLIC
    machinish_headers
)
