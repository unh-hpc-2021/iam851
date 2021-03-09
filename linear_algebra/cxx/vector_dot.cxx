
#include "linear_algebra.h"

double vector_dot(double* x, double* y)
{
  double sum = 0.f;
  for (int i = 0; i < N; i++) {
    sum += x[i] * y[i];
  }
  return sum;
}
