
#include "linear_algebra.h"

#include <assert.h>

void vector_add(const vector& x, const vector& y, vector& z)
{
  assert(x.size() == y.size() && x.size() == z.size());

  for (int i = 0; i < x.size(); i++) {
    z(i) = x(i) + y(i);
  }
}
