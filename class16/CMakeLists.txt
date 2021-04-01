
cmake_minimum_required (VERSION 3.11)

project(LinearAlgebra LANGUAGES CXX Fortran)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(cmake/CPM.cmake)

CPMAddPackage(
  NAME xtl
  GITHUB_REPOSITORY xtensor-stack/xtl
  GIT_TAG 0.7.2
  VERSION 0.7.2
)

CPMAddPackage(
  NAME xtensor
  GITHUB_REPOSITORY xtensor-stack/xtensor
  GIT_TAG 0.23.4
  VERSION 0.23.4
)
  
add_executable(test_integration test_integration.cxx)

add_executable(test_average test_average.cxx)
target_link_libraries(test_average xtensor)

add_executable(test_average_fortran test_average_fortran.F90)
