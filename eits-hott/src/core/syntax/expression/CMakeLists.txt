# src/kernel/CMakeLists.txt

file(GLOB SOURCE_CODE
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/type/*.cpp
)

add_library(eits_hott_expression STATIC
  ${SOURCE_CODE}
)

target_include_directories(eits_hott_expression
  PRIVATE
        ../../..
)

target_link_libraries(eits_hott_expression
	PRIVATE
		internal_charutil
		eits_hott_kernel_basis
)

target_link_libraries(eits_hott_expression
	PUBLIC
		eits_hott_headers
)
