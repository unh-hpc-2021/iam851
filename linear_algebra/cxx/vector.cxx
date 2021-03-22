
#include "linear_algebra.h"

#include <stdio.h>

vector::vector(int _n) : data(new double[_n]), n(_n) {}

vector::~vector()
{
  delete[] data;
}

double vector::operator()(int i) const
{
#ifdef BOUNDS_CHECK
  assert(i >= 0 && i < n);
#endif
  return data[i];
}

double& vector::operator()(int i)
{
#ifdef BOUNDS_CHECK
  assert(i >= 0 && i < n);
#endif
  return data[i];
}

bool vector_is_equal(const vector& x, const vector& y)
{
  if (x.n != y.n) {
    return false;
  }

  for (int i = 0; i < x.n; i++) {
    if (x(i) != y(i)) {
      return false;
    }
  }

  return true;
}

void vector::print() const
{
  printf("{");
  for (int i = 0; i < n; i++) {
    printf(" %g", (*this)(i));
  }
  printf(" }\n");
}
