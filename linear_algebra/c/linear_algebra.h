
#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

// vector length (fixed)
#define N (3)

double vector_dot(const double* x, const double* y);
void vector_add(const double* x, const double* y, double *z);
void matrix_vector_mul(const double A[N][N], const double* x, double *y);

#endif
