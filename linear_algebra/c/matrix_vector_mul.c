
#include "linear_algebra.h"

void matrix_vector_mul(const double A[N][N], const double* x, double *y)
{
  for (int j = 0; j < N; j++) {
    y[j] = 0.;
    for (int i = 0; i < N; i++) {
      y[j] += A[j][i] * x[i];
    }
  }
}
