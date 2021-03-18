
#include "linear_algebra.h"

#include <stdio.h>
#include <assert.h>

// ----------------------------------------------------------------------
// main
//
// test the matrix_vector_mul() function

int main(int argc, char** argv)
{
  const int N = 3;
  struct vector x;
  vector_construct(&x, N);
  struct vector y;
  vector_construct(&y, N);
  struct vector y_ref;
  vector_construct(&y_ref, N);
  struct matrix A;
  matrix_construct(&A, N, N);

  for (int i = 0; i < N; i++) {
    VEC(&x, i) = 1. + i;
    MAT(&A, i, i) = 1. + i;
    VEC(&y_ref, i) = (1. + i) * (1. + i);
  }
  MAT(&A, 0, 1) = 1.; // make the matrix not purely diagonal
  VEC(&y_ref, 0) += 1. * VEC(&x, 1);

  matrix_vector_mul(&A, &x, &y);
  assert(vector_is_equal(&y, &y_ref));

  vector_destruct(&x);
  vector_destruct(&y);
  matrix_destruct(&A);

  return 0;
}
