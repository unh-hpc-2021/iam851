
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

  for (int i = 0; i < N; i++) {
    VEC(&x, i) = 1. + i;
    VEC(&y, i) = 2. + i;
  }

  vector_add(&x, &y, &z);
  assert(VEC(&z, 0) == 3. && VEC(&z, 1) == 5. && VEC(&z, 2) == 7. &&
         VEC(&z, 3) == 9.);

  vector_destruct(&x);
  vector_destruct(&y);
  vector_destruct(&z);

  return 0;
}
