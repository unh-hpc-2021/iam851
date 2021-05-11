
cmake_minimum_required (VERSION 3.11)

project(LinearAlgebra LANGUAGES CXX Fortran)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(MPI REQUIRED)

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
  
add_executable(test_derivative test_derivative.cxx derivative.cxx)
target_link_libraries(test_derivative 
  PRIVATE MPI::MPI_CXX xtensor)

add_executable(wave_equation wave_equation.cxx derivative.cxx)
target_link_libraries(wave_equation
  PRIVATE MPI::MPI_CXX xtensor)

add_executable(kdv kdv.cxx derivative.cxx)
  target_link_libraries(kdv PRIVATE MPI::MPI_CXX xtensor)

add_executable(mpi_dl_test mpi_dl_test.cxx)
target_link_libraries(mpi_dl_test
  PRIVATE MPI::MPI_CXX xtensor)
