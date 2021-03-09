
#include "linear_algebra.h"

#include <stdlib.h>

void vector_construct(struct vector *v, int n)
{
  v->data = calloc(n, sizeof(*v->data));
  v->n = n;
}

void vector_destruct(struct vector *v)
{
  free(v->data);
}
