
#include "linear_algebra.h"

// ----------------------------------------------------------------------
// matrix_matrix_mul
//
// performs the matrix-matrix multiplication C = A B
// A: 1st input matrix (m x k matrix)
// B: 2nd input matrix (k x n matrix)
// C: result (m x n matrix)

void matrix_matrix_mul(const matrix& A, const matrix& B, matrix& C)
{
  // make sure the dimensions all match as needed for matrix-matrix
  // multiplication
  assert(A.shape(1) == B.shape(0));
  assert(A.shape(0) == C.shape(0));
  assert(B.shape(1) == C.shape(1));

  for (int i = 0; i < C.shape(0); i++) {
    for (int j = 0; j < C.shape(1); j++) {
      C(i, j) = 0.;
      for (int k = 0; k < B.shape(0); k++) {
        C(i, j) += A(i, k) * B(k, j);
      }
    }
  }
}
