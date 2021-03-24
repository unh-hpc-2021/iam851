
add_library(linalgcxx
  matrix.cxx
  vector_dot.cxx
  matrix_vector_mul.cxx
  matrix_matrix_mul.cxx
  )
target_link_libraries(linalgcxx PUBLIC xtensor)

add_executable(test_linear_algebra test_linear_algebra.cxx)
target_link_libraries(test_linear_algebra linalgcxx GTest::GTest GTest::Main)

gtest_discover_tests(test_linear_algebra)
