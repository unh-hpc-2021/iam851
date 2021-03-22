
#include "linear_algebra.h"

#include <stdio.h>

matrix::matrix(int _m, int _n) : data(new double[_m * _n]), m(_m), n(_n) {}

matrix::~matrix()
{
  delete[] data;
}

double matrix::operator()(int i, int j) const
{
#ifdef BOUNDS_CHECK
  assert(i >= 0 && i < m);
  assert(j >= 0 && j < n);
#endif
  return data[i * n + j];
}

double& matrix::operator()(int i, int j)
{
#ifdef BOUNDS_CHECK
  assert(i >= 0 && i < m);
  assert(j >= 0 && j < n);
#endif
  return data[i * n + j];
}

bool matrix_is_equal(const matrix& A, const matrix& B)
{
  if (A.m != B.m || A.n != B.n) {
    return false;
  }
  for (int i = 0; i < A.m; i++) {
    for (int j = 0; j < A.n; j++) {
      if (A(i, j) != B(i, j)) {
        return false;
      }
    }
  }

  return true;
}

void matrix::print() const
{
  printf("{\n");
  for (int i = 0; i < m; i++) {
    printf("{");
    for (int j = 0; j < n; j++) {
      printf(" %g", (*this)(i, j));
    }
    printf(" }\n");
  }
  printf("}\n");
}
