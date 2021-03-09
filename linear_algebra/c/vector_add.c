
#include "linear_algebra.h"

void vector_add(double* x, double* y, double *z)
{
  for (int i = 0; i < N; i++) {
    z[i] = x[i] + y[i];
  }
}
