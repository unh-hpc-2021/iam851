
#include "linear_algebra.h"

void matrix_vector_mul(int n, const double A[n][n], const double* x, double* y)
{
  for (int j = 0; j < n; j++) {
    y[j] = 0.;
    for (int i = 0; i < n; i++) {
      y[j] += A[j][i] * x[i];
    }
  }
}
