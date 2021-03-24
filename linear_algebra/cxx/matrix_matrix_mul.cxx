
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
  assert(A.n_cols() == B.n_rows());
  assert(A.n_rows() == C.n_rows());
  assert(B.n_cols() == C.n_cols());

  for (int i = 0; i < C.n_rows(); i++) {
    for (int j = 0; j < C.n_cols(); j++) {
      C(i, j) = 0.;
      for (int k = 0; k < B.n_rows(); k++) {
        C(i, j) += A(i, k) * B(k, j);
      }
    }
  }
}
