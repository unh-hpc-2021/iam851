
#include <gtest/gtest.h>

#include <stdio.h>
#include <assert.h>

#include "linear_algebra.h"

TEST(LinearAlgebra, VectorDot)
{
  double x[N] = {1., 2., 3.};
  double y[N] = {2., 3., 4.};

  EXPECT_EQ(vector_dot(x, y), 20);
}

TEST(LinearAlgebra, VectorAdd)
{
  double x[N] = {1., 2., 3.};
  double y[N] = {2., 3., 4.};
  double z[N];

  vector_add(x, y, z);
  EXPECT_TRUE(z[0] == 3. && z[1] == 5. && z[2] == 7.);
}

TEST(LinearAlgebra, MatrixVectorMul)
{
  double x[N] = {1., 2., 3.};
  double A[N][N] = {{1., 1., 0.},
		    {0., 2., 0.},
		    {0., 0., 3.}};
  double y[N];

  matrix_vector_mul(A, x, y);
  EXPECT_TRUE(y[0] == 3. && y[1] == 4. && y[2] == 9.);
}
