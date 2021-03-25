
#include "linear_algebra.h"

#include <assert.h>

void matrix_vector_mul(const matrix& A, const vector& x, vector& y)
{
  assert(A.shape(0) == y.size());
  assert(A.shape(1) == x.size());

  for (int i = 0; i < y.size(); i++) {
    y(i) = 0.;
    for (int j = 0; j < x.size(); j++) {
      y(i) += A(i, j) * x(j);
    }
  }
}
