cmake_minimum_required (VERSION 2.8)

project(Calculator)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

#set output location
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src/Gen)

add_executable(Calculator src/main.cpp)

target_link_libraries(Calculator Gen)