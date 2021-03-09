
#include "linear_algebra.h"

#include <stdio.h>
#include <assert.h>

// ----------------------------------------------------------------------
// main
//
// test the vector_add() function

int main(int argc, char** argv)
{
  double x[N] = {1., 2., 3.};
  double y[N] = {2., 3., 4.};
  double z[N];

  vector_add(x, y, z, N);
  assert(z[0] == 3. && z[1] == 5. && z[2] == 7.);

  return 0;
}
