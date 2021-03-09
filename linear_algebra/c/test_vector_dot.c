
#include "linear_algebra.h"

#include <stdio.h>
#include <assert.h>

#define N (3)

// ----------------------------------------------------------------------
// main
//
// test the vector_dot() function

int main(int argc, char** argv)
{
  double x[N] = {1., 2., 3.};
  double y[N] = {2., 3., 4.};

  assert(vector_dot(x, y, N) == 20);

  return 0;
}
