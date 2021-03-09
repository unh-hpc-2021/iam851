
add_library(linalgcxx vector_dot.cxx vector_add.cxx matrix_vector_mul.cxx)

add_executable(test_linear_algebra test_linear_algebra.cxx)
target_link_libraries(test_linear_algebra linalgcxx GTest::GTest GTest::Main)

add_test(TestLinearAlgebra test_linear_algebra)
