# src/internal/instructions/CMakeLists.txt

add_library(internal_instructions STATIC
	snapshot.cpp
)

target_link_libraries(internal_instructions
	PRIVATE
		machinish_kernel_semantics
		machinish_headers
)

target_include_directories(internal_instructions
  PRIVATE
    ${PROJECT_SOURCE_DIR}/src
)

target_include_directories(internal_instructions 
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}
)
