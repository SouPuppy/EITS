# src/internal/uid/CMakeLists.txt

add_library(internal_uid STATIC
        uid.cpp
)

target_include_directories(internal_uid
  PRIVATE
        ../..
)

target_include_directories(internal_uid 
	PUBLIC
        .
)
