
#include "linear_algebra.h"

#include <stdio.h>
#include <assert.h>

// ----------------------------------------------------------------------
// main
//
// test the vector_add() function

int main(int argc, char** argv)
{
  const int N = 4;
  struct vector x;
  vector_construct(&x, N);
  struct vector y;
  vector_construct(&y, N);
  struct vector z;
  vector_construct(&z, N);
  struct vector z_ref;
  vector_construct(&z_ref, N);

  for (int i = 0; i < N; i++) {
    VEC(&x, i) = 1. + i;
    VEC(&y, i) = 2. + i;
    VEC(&z_ref, i) = 3. + 2 * i;
  }

  vector_add(&x, &y, &z);
  assert(vector_is_equal(&z, &z_ref));

  printf("{");
  for (int i = 0; i < 4; i++) {
    printf(" %g", VEC(&z, i));
  }
  printf(" }\n");

  vector_destruct(&x);
  vector_destruct(&y);
  vector_destruct(&z);
  vector_destruct(&z_ref);

  return 0;
}
