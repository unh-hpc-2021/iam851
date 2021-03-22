
#include <gtest/gtest.h>

#include <stdio.h>
#include <assert.h>

#include "linear_algebra.h"

TEST(LinearAlgebra, VectorDot)
{
  const int N = 3;
  vector x(N), y(N);

  for (int i = 0; i < N; i++) {
    VEC(x, i) = 1. + i;
    VEC(y, i) = 2. + i;
  }

  EXPECT_EQ(vector_dot(x, y), 20);

  vector_destruct(x);
  vector_destruct(y);
}

TEST(LinearAlgebra, VectorAdd)
{
  const int N = 4;

  vector x(N), y(N), z(N), z_ref(N);

  for (int i = 0; i < N; i++) {
    VEC(x, i) = 1. + i;
    VEC(y, i) = 2. + i;
    VEC(z_ref, i) = 3. + 2 * i;
  }

  vector_add(x, y, z);
  EXPECT_TRUE(vector_is_equal(z, z_ref));
  // z.print();

  vector_destruct(x);
  vector_destruct(y);
  vector_destruct(z);
  vector_destruct(z_ref);
}

TEST(LinearAlgebra, MatrixVectorMul)
{
  const int N = 3;
  vector x(N), y(N), y_ref(N);
  matrix A(N, N);

  for (int i = 0; i < N; i++) {
    VEC(x, i) = 1. + i;
    MAT(A, i, i) = 1. + i;
    VEC(y_ref, i) = (1. + i) * (1. + i);
  }
  MAT(A, 0, 1) = 1.; // make the matrix not purely diagonal
  VEC(y_ref, 0) += 1. * VEC(x, 1);

  matrix_vector_mul(A, x, y);
  EXPECT_TRUE(vector_is_equal(y, y_ref));

  vector_destruct(x);
  vector_destruct(y);
  matrix_destruct(A);
}

static inline int min(int i, int j)
{
  if (i < j) {
    return i;
  } else {
    return j;
  }
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
  for (int i = 0; i < min(A.m, A.n); i++) {
    MAT(A, i, i) = i;
  }
  for (int i = 0; i < min(B.m, B.n); i++) {
    MAT(B, i, i) = i;
  }
  for (int i = 0; i < min(min(C_ref.m, C_ref.n), A.n); i++) {
    MAT(C_ref, i, i) = i * i;
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
  EXPECT_TRUE(matrix_is_equal(C, C_ref));

  // clean up
  matrix_destruct(A);
  matrix_destruct(B);
  matrix_destruct(C);
  matrix_destruct(C_ref);
}
