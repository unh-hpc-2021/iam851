
#include "linear_algebra.h"

#include <stdio.h>
#include <assert.h>

static inline int min(int i, int j)
{
  if (i < j) {
    return i;
  } else {
    return j;
  }
}

// ----------------------------------------------------------------------
// setup_test_matrices
//
// initializes the two matrices A, B, and the reference solution C_ref

static void setup_test_matrices(struct matrix* A, struct matrix* B,
                                struct matrix* C_ref)
{
  // the test matrices are diagonal, which isn't really good,
  // a more general test case would be better.

  // the matrices are initialized to zero, so we only set the non-zero elements
  // on the diagonal
  for (int i = 0; i < min(A->m, A->n); i++) {
    MAT(A, i, i) = i;
  }
  for (int i = 0; i < min(B->m, B->n); i++) {
    MAT(B, i, i) = i;
  }
  for (int i = 0; i < min(min(C_ref->m, C_ref->n), A->n); i++) {
    MAT(C_ref, i, i) = i * i;
  }
}

// ----------------------------------------------------------------------
// main
//
// test the mat_vec_mul() function

int main(int argc, char** argv)
{
  const int m = 5, n = 5, k = 5;

  struct matrix A, B, C, C_ref;
  matrix_construct(&C, m, n);
  matrix_construct(&C_ref, m, n);
  matrix_construct(&A, m, k);
  matrix_construct(&B, k, n);

  // build a test matrix
  setup_test_matrices(&A, &B, &C_ref);

  // calculate C = AB
  matrix_matrix_mul(&A, &B, &C);

  printf("C = ");
  matrix_print(&C);

  // the resulting vector for this test should equal our reference result
  // FIXME, matrix_is_equal() is missing
  //  assert(matrix_is_equal(C, C_ref));

  // clean up
  matrix_destruct(&A);
  matrix_destruct(&B);
  matrix_destruct(&C);
  matrix_destruct(&C_ref);

  return 0;
}
