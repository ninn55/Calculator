project(test1)

include(../../PrecompiledHeader.cmake)
add_compile_options(-bigobj)

add_executable(test1 test1.cpp pch.cpp)
target_link_libraries(test1 Gen)
add_precompiled_header(test1 pch.h SOURCE_CXX pch.cpp FORCEINCLUDE)