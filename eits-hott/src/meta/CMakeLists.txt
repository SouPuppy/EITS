# src/meta/CMakeLists.txt

add_library(eits_hott_meta STATIC
  version.cpp
)

target_link_libraries(eits_hott_meta PUBLIC eits_hott_headers)
