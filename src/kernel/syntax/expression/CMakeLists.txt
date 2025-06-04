# src/kernel/CMakeLists.txt

add_library(machinish_expression STATIC
  expression.cpp
  term.cpp
  universe.cpp
  variable.cpp
)

target_include_directories(machinish_expression
	PUBLIC
		${PROJECT_SOURCE_DIR}/include
		${CMAKE_BINARY_DIR}/include
)

