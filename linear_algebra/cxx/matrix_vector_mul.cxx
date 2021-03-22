
#include "linear_algebra.h"

#include <assert.h>

void matrix_vector_mul(const matrix& A, const vector& x, vector& y)
{
  assert(A.m == y.n);
  assert(A.n == x.n);

  for (int i = 0; i < y.n; i++) {
    VEC(y, i) = 0.;
    for (int j = 0; j < x.n; j++) {
      VEC(y, i) += A(i, j) * VEC(x, j);
    }
  }
}
