# src/internal/uid/CMakeLists.txt

add_library(internal_uid STATIC
	uid.cpp
)

target_include_directories(internal_uid
  PRIVATE
    ${PROJECT_SOURCE_DIR}/src
)

target_include_directories(internal_uid PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
)
