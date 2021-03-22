
#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

#include <assert.h>

#define BOUNDS_CHECK
#include <stdbool.h>

struct vector
{
  void print() const;

  double* data;
  int n;
};

#ifdef BOUNDS_CHECK
#define VEC(v, i)                                                              \
  (*({                                                                         \
    assert(i >= 0 && i < (v).n);                                               \
    &(v).data[i];                                                              \
  }))
#else
#define VEC(v, i) ((v).data[i])
#endif

void vector_construct(vector& v, int n);
void vector_destruct(vector& v);

struct matrix
{
  void print() const;

  double* data;
  int m, n;
};

#ifdef BOUNDS_CHECK
#define MAT(A, i, j)                                                           \
  (*({                                                                         \
    assert(i >= 0 && i < (A).m);                                               \
    assert(j >= 0 && j < (A).n);                                               \
    &(A).data[i * (A).n + j];                                                  \
  }))
#else
#define MAT(A, i, j) ((A).data[i * (A).n + j])
#endif

void matrix_construct(matrix& A, int m, int n);
void matrix_destruct(matrix& A);

bool matrix_is_equal(const matrix& A, const matrix& B);
bool vector_is_equal(const vector& x, const vector& y);
double vector_dot(const vector& x, const vector& y);
void vector_add(const vector& x, const vector& y, vector& z);
void matrix_vector_mul(const matrix& A, const vector& x, vector& y);
void matrix_matrix_mul(const matrix& A, const matrix& B, matrix& C);

// ----------------------------------------------------------------------

#include <stdio.h>

#define HERE                                                                   \
  fprintf(stderr, "HERE at %s:%d (%s)\n", __FILE__, __LINE__, __FUNCTION__)

#endif
