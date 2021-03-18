
#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

struct vector
{
  double* data;
  int n;
};

#define VEC(v, i) ((v)->data[i])

void vector_construct(struct vector* v, int n);
void vector_destruct(struct vector* v);

struct matrix
{
  double* data;
  int m, n;
};

#define MAT(A, i, j) ((A)->data[i * (A)->n + j])

void matrix_construct(struct matrix* A, int m, int n);
void matrix_destruct(struct matrix* A);

double vector_dot(const struct vector* x, const struct vector* y);
void vector_add(const struct vector* x, const struct vector* y,
                const struct vector* z);
void matrix_vector_mul(const struct matrix* A, const struct vector* x,
                       struct vector* y);

#endif
