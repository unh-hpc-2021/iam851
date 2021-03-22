
#include "linear_algebra.h"

#include <assert.h>

vector operator+(const vector& x, const vector& y)
{
  assert(x.size() == y.size());
  vector z(x.size());

  for (int i = 0; i < x.size(); i++) {
    z(i) = x(i) + y(i);
  }

  return z;
}
