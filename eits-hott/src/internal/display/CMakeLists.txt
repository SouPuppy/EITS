# src/internal/instructions/CMakeLists.txt

# file(GLOB SOURCE_CODE
# 	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
# )

# add_library(internal_display STATIC
#   ${SOURCE_CODE}
# )

add_library(internal_display INTERFACE)

target_include_directories(internal_display
  INTERFACE
		${CMAKE_CURRENT_SOURCE_DIR}
)
