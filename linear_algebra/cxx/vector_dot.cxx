
#include "linear_algebra.h"

#include <assert.h>

double vector_dot(const vector& x, const vector& y)
{
  assert(x.n == y.n); // can only dot vectors of same length

  double sum = 0.;
  for (int i = 0; i < x.n; i++) {
    sum += x(i) * y(i);
  }
  return sum;
}
