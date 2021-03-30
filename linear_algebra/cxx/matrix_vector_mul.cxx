
#include "linear_algebra.h"

#include <assert.h>

vector dot(const matrix& A, const vector& x)
{
  assert(A.shape(1) == x.size());

  vector y = xt::zeros<double>({A.shape(0)});

  for (int i = 0; i < y.size(); i++) {
    for (int j = 0; j < x.size(); j++) {
      y(i) += A(i, j) * x(j);
    }
  }

  return y;
}
