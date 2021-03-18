
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
