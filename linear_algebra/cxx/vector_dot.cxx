
#include "linear_algebra.h"

#include <assert.h>

double vector_dot(const vector& x, const vector& y)
{
  assert(x.size() == y.size()); // can only dot vectors of same length

  double sum = 0.;
  for (int i = 0; i < x.size(); i++) {
    sum += x(i) * y(i);
  }
  return sum;
}
