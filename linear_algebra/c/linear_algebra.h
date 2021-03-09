
#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

struct vector {
  double *data;
  int n;
};

#define VEC(v, i) ((v)->data[i])

void vector_construct(struct vector *v, int n);
void vector_destruct(struct vector *v);

double vector_dot(const double* x, const double* y, int n);
void vector_add(const double* x, const double* y, double *z, int n);
void matrix_vector_mul(int n, const double A[n][n], const double* x, double *y);

#endif
