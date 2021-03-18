
#include "linear_algebra.h"

#include <stdlib.h>

void vector_construct(struct vector* v, int n)
{
  v->data = calloc(n, sizeof(*v->data));
  v->n = n;
}

void vector_destruct(struct vector* v)
{
  free(v->data);
}

bool vector_is_equal(const struct vector* x, const struct vector* y)
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