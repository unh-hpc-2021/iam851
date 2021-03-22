
#include "linear_algebra.h"

#include <stdio.h>

matrix::matrix(int _m, int _n) : data(new double[_m * _n]), m(_m), n(_n) {}

matrix::~matrix()
{
  delete[] data;
}

bool matrix_is_equal(const matrix& A, const matrix& B)
{
  if (A.m != B.m || A.n != B.n) {
    return false;
  }
  for (int i = 0; i < A.m; i++) {
    for (int j = 0; j < A.n; j++) {
      if (MAT(A, i, j) != MAT(B, i, j)) {
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
      printf(" %g", MAT(*this, i, j));
    }
    printf(" }\n");
  }
  printf("}\n");
}
