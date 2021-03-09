
#include "linear_algebra.h"

#include <stdio.h>
#include <assert.h>

// ----------------------------------------------------------------------
// main
//
// test the matrix_vector_mul() function

int main(int argc, char** argv)
{
  double x[N] = {1., 2., 3.};
  double A[N][N] = {{1., 1., 0.},
		    {0., 2., 0.},
		    {0., 0., 3.}};
  double y[N];

  matrix_vector_mul(N, A, x, y);
  assert(y[0] == 3. && y[1] == 4. && y[2] == 9.);

  return 0;
}
