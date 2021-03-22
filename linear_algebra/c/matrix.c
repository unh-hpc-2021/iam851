
#include "linear_algebra.h"

#include <stdio.h>
#include <stdlib.h>

void matrix_construct(struct matrix* A, int m, int n)
{
  A->data = calloc(m * n, sizeof(*A->data));
  A->m = m;
  A->n = n;
}

void matrix_destruct(struct matrix* A)
{
  free(A->data);
}

bool matrix_is_equal(const struct matrix* A, const struct matrix *B)
{
  if (A->m != B->m || A->n != B->n) {
    return false;
  }
  for (int i = 0; i < A->m; i++) {
    for (int j = 0; j < A->n; j++) {
      if (MAT(A, i, j) != MAT(B, i,j)) {
        return false;
      }
    }
  }

  return true;
}

void matrix_print(const struct matrix* A)
{
  printf("{\n");
  for (int i = 0; i < A->m; i++) {
    printf("{");
    for (int j = 0; j < A->n; j++) {
      printf(" %g", MAT(A, i, j));
    }
    printf(" }\n");
  }
  printf("}\n");
}
