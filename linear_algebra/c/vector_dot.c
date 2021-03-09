
#include "linear_algebra.h"

#include <assert.h>

double vector_dot(const struct vector* x, const struct vector* y)
{
  assert(x->n == y->n); // can only dot vectors of same length
  
  double sum = 0.;
  for (int i = 0; i < x->n; i++) {
    sum += VEC(x, i) * VEC(y, i);
  }
  return sum;
}
