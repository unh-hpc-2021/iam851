
#include "linear_algebra.h"

void vector_add(const double* x, const double* y, double* z, int n)
{
  for (int i = 0; i < n; i++) {
    z[i] = x[i] + y[i];
  }
}
