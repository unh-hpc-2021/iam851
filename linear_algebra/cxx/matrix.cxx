
#include "linear_algebra.h"

#include <stdio.h>
#include <stdlib.h>

void matrix_construct(matrix& A, int m, int n)
{
  A.data = (double*)calloc(m * n, sizeof(*A.data));
  A.m = m;
  A.n = n;
}

void matrix_destruct(matrix& A)
{
  free(A.data);
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
