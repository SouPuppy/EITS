# eits-repl/CMakeLists.txt

add_executable(eits_repl main.cpp
)

target_link_libraries(eits_repl
	PRIVATE
		logger
)
