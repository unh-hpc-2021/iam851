
add_library(linalgcxx vector_dot.cxx vector_add.cxx matrix_vector_mul.cxx)

link_libraries(linalgcxx)

add_executable(test_vector_dot_cxx test_vector_dot.cxx) 
add_executable(test_vector_add_cxx test_vector_add.cxx) 
add_executable(test_matrix_vector_mul_cxx test_matrix_vector_mul.cxx) 

add_test(TestVectorDotCXX test_vector_dot_cxx)
add_test(TestVectorAddCXX test_vector_add_cxx)
add_test(TestMatrixVectorMulCXX test_matrix_vector_mul_cxx)
