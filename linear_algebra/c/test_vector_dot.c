
#include "linear_algebra.h"

#include <stdio.h>
#include <assert.h>

// ----------------------------------------------------------------------
// main
//
// test the vector_dot() function

int main(int argc, char** argv)
{
  const int N = 3;
  struct vector x;
  vector_construct(&x, N);
  struct vector y;
  vector_construct(&y, N);

  for (int i = 0; i < N; i++) {
    VEC(&x, i) = 1. + i;
    VEC(&y, i) = 2. + i;
  }

  assert(vector_dot(&x, &y) == 20);

  vector_destruct(&x);
  vector_destruct(&y);

  return 0;
}
