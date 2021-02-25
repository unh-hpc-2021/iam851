
cmake_minimum_required (VERSION 3.16)

project(Hello)

enable_testing()

add_library(stuff greeting.cxx factorial.cxx)

add_executable(hello hello.cxx)
target_link_libraries(hello stuff)

add_executable(test_factorial test_factorial.cxx)
target_link_libraries(test_factorial stuff)
add_test(FactorialTest test_factorial)
