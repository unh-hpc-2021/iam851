
#include "linear_algebra.h"

#include <stdio.h>
#include <assert.h>

// ----------------------------------------------------------------------
// main
//
// test the vector_dot() function

int main(int argc, char** argv)
{
  double x[N] = {1., 2., 3.};
  double y[N] = {2., 3., 4.};

  assert(vector_dot(x, y) == 20);

  return 0;
}
