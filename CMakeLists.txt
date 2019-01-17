cmake_minimum_required (VERSION 3.0)

set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")
include(cotire)

project(Calculator)

#set_property(GLOBAL PROPERTY USE_FOLDERS ON)

#set output location
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#add project Gen generate random expresion
add_subdirectory(src/Gen)
#add project tinyexpr as a standard
add_subdirectory(include/tinyexpr)
#add test project 1
add_subdirectory(test/test1)
#add test project 2
add_subdirectory(test/test2)

#compile the main program
add_executable(Calculator src/main.cpp)

target_link_libraries(Calculator Gen)

enable_testing()
add_test (test_run1 test1)
set_tests_properties(test_run1 PROPERTIES PASS_REGULAR_EXPRESSION "Check")

add_test (test_run2 test2)
set_tests_properties(test_run2 PROPERTIES PASS_REGULAR_EXPRESSION "Check")
