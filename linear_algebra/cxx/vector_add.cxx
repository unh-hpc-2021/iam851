
#include "linear_algebra.h"

#include <assert.h>

void vector_add(const vector& x, const vector& y, vector& z)
{
  assert(x.n == y.n && x.n == z.n);

  for (int i = 0; i < x.n; i++) {
    z(i) = x(i) + y(i);
  }
}
