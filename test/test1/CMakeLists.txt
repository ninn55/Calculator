project(test1)

add_compile_options(-bigobj)

add_executable(test1 test1.cpp)
target_link_libraries(test1 Gen)