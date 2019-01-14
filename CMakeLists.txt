cmake_minimum_required (VERSION 2.8)

project(Calculator)

add_subdirectory(src/Gen)

add_executable(Calculator main.cpp)

target_link_libraries(Calculator Gen)