# src/internal/instructions/CMakeLists.txt

add_library(internal_charutil STATIC
	subscript.cpp
)

target_include_directories(internal_charutil
  PRIVATE
    ${PROJECT_SOURCE_DIR}/src
)
