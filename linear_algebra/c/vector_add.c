
#include "linear_algebra.h"

void vector_add(const double* x, const double* y, double *z)
{
  for (int i = 0; i < N; i++) {
    z[i] = x[i] + y[i];
  }
}
