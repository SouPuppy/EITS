# eits-repl/CMakeLists.txt

add_executable(eits_repl main.cpp
	editor.cpp
)

target_link_libraries(eits_repl
	PRIVATE
		logger
)
