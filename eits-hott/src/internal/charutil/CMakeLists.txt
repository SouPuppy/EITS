# src/internal/instructions/CMakeLists.txt

file(GLOB SOURCE_CODE
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(internal_charutil STATIC
  ${SOURCE_CODE}
)

target_include_directories(internal_charutil
  PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}
)
