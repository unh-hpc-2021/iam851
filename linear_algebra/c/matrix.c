
#include "linear_algebra.h"

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
