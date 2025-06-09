# src/kernel/basis/CMakeLists.txt

file(GLOB SOURCE_CODE
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(eits_hott_kernel_basis STATIC
	${SOURCE_CODE}
)

target_include_directories(eits_hott_kernel_basis
  PRIVATE
        ../..
)

target_link_libraries(eits_hott_kernel_basis
  PUBLIC
    eits_hott_headers
)
