
#include <gtest/gtest.h>

#include <algorithm>
#include <stdio.h>
#include <assert.h>

#include "linear_algebra.h"

TEST(LinearAlgebra, VectorDot)
{
  const int N = 3;
  vector x(N), y(N);

  for (int i = 0; i < N; i++) {
    x(i) = 1. + i;
    y(i) = 2. + i;
  }

  EXPECT_EQ(dot(x, y), 20);
}

TEST(LinearAlgebra, VectorAdd)
{
  const int N = 4;

  vector x(N), y(N), z_ref(N);

  for (int i = 0; i < N; i++) {
    x(i) = 1. + i;
    y(i) = 2. + i;
    z_ref(i) = 3. + 2 * i;
  }

  vector z = x + y;
  EXPECT_EQ(z, z_ref);
  // std::cout << z << "\n";
}

TEST(LinearAlgebra, MatrixVectorMul)
{
  const int N = 3;
  vector x(N), y(N), y_ref(N);
  matrix A(N, N);

  for (int i = 0; i < N; i++) {
    x(i) = 1. + i;
    A(i, i) = 1. + i;
    y_ref(i) = (1. + i) * (1. + i);
  }
  A(0, 1) = 1.; // make the matrix not purely diagonal
  y_ref(0) += 1. * x(1);

  matrix_vector_mul(A, x, y);
  EXPECT_EQ(y, y_ref);
  // std::cout << A << "\n";
}

// ----------------------------------------------------------------------
// setup_test_matrices
//
// initializes the two matrices A, B, and the reference solution C_ref

static void setup_test_matrices(matrix& A, matrix& B, matrix& C_ref)
{
  // the test matrices are diagonal, which isn't really good,
  // a more general test case would be better.

  // the matrices are initialized to zero, so we only set the non-zero elements
  // on the diagonal
  for (int i = 0; i < std::min(A.n_rows(), A.n_cols()); i++) {
    A(i, i) = i;
  }
  for (int i = 0; i < std::min(B.n_rows(), B.n_cols()); i++) {
    B(i, i) = i;
  }
  for (int i = 0; i < std::min({C_ref.n_rows(), C_ref.n_rows(), A.n_cols()});
       i++) {
    C_ref(i, i) = i * i;
  }
}

TEST(LinearAlgebra, MatrixMatrixMul)
{
  const int m = 500, n = 500, k = 200;

  matrix A(m, k), B(k, n), C(m, n), C_ref(m, n);

  // build a test matrix
  setup_test_matrices(A, B, C_ref);

  // calculate C = AB
  matrix_matrix_mul(A, B, C);

  // printf("C = ");
  // C.print();

  // the resulting vector for this test should equal our reference result
  EXPECT_TRUE(C == C_ref);
}
