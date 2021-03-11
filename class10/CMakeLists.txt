
cmake_minimum_required (VERSION 3.10)

project(DataLayout)
enable_language(Fortran)

add_executable(test_data_layout test_data_layout.c)
add_executable(test_data_layout_fortran test_data_layout_fortran.F90)
