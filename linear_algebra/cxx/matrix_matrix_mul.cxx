
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
  assert(A.n == B.m);
  assert(A.m == C.m);
  assert(B.n == C.n);

  for (int i = 0; i < C.m; i++) {
    for (int j = 0; j < C.n; j++) {
      C(i, j) = 0.;
      for (int k = 0; k < B.m; k++) {
        C(i, j) += A(i, k) * B(k, j);
      }
    }
  }
}
