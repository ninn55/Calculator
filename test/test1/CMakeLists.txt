project(test1)

add_compile_options(-bigobj)

add_executable(test1 pch.cpp test1.cpp pch.h)
target_link_libraries(test1 Gen)
set_target_properties(test1 PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "pch.h")
cotire(test1)