
cmake_minimum_required (VERSION 3.11)

project(Bowling)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)
enable_testing()

add_executable(bowling bowling.cxx)
target_link_libraries(bowling GTest::GTest GTest::Main)
