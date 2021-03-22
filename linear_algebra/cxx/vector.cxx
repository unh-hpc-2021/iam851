
#include "linear_algebra.h"

#include <stdio.h>
#include <stdlib.h>

void vector_construct(vector* v, int n)
{
  v->data = (double*)calloc(n, sizeof(*v->data));
  v->n = n;
}

void vector_destruct(vector* v)
{
  free(v->data);
}

bool vector_is_equal(const vector* x, const vector* y)
{
  if (x->n != y->n) {
    return false;
  }

  for (int i = 0; i < x->n; i++) {
    if (VEC(x, i) != VEC(y, i)) {
      return false;
    }
  }

  return true;
}

void vector_print(const vector* v)
{
  printf("{");
  for (int i = 0; i < v->n; i++) {
    printf(" %g", VEC(v, i));
  }
  printf(" }\n");
}
