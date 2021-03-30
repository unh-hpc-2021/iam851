
#include <gtest/gtest.h>

#include <algorithm>
#include <xtensor/xio.hpp>

#include "linear_algebra.h"

TEST(LinearAlgebra, VectorDot)
{
  const int N = 3;
  vector x = {1., 2., 3.};
  vector y = {2., 3., 4.};

  EXPECT_EQ(dot(x, y), 20.);
}

TEST(LinearAlgebra, VectorAdd)
{
  const int N = 4;

  vector x = {1., 2., 3., 4.};
  vector y = {2., 3., 4., 5.};

  vector z = x + y;
  EXPECT_EQ(z, vector({3., 5., 7., 9.}));
  // std::cout << z << "\n";
}

TEST(LinearAlgebra, MatrixVectorMul)
{
  vector x = {1., 2., 3.};
  vector y_ref = {3., 4., 9.};
  matrix A = {{1., 1., 0.}, {0., 2., 0.}, {0., 0., 3.}};

  vector y = dot(A, x);
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
  for (int i = 0; i < std::min(A.shape(0), A.shape(1)); i++) {
    A(i, i) = i;
  }
  for (int i = 0; i < std::min(B.shape(0), B.shape(1)); i++) {
    B(i, i) = i;
  }
  for (int i = 0; i < std::min({C_ref.shape(0), C_ref.shape(1), A.shape(1)});
       i++) {
    C_ref(i, i) = i * i;
  }
}

TEST(LinearAlgebra, MatrixMatrixMul)
{
  const int m = 500, n = 500, k = 200;

  matrix A = xt::zeros<double>({m, k});
  matrix B = xt::zeros<double>({k, n});
  matrix C = xt::zeros<double>({m, n});
  matrix C_ref = xt::zeros<double>({m, n});

  // build a test matrix
  setup_test_matrices(A, B, C_ref);

  // calculate C = AB
  matrix_matrix_mul(A, B, C);

  // std::cout << " C = " << C << "\n";

  // the resulting vector for this test should equal our reference result
  EXPECT_EQ(C, C_ref);
}
