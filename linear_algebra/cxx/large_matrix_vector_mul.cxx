
#include "linear_algebra.h"

int main(int argc, char** argv)
{
  vector x = {1., 2., 3.};
  // clang-format off
  matrix A = {{1., 2., 3.},
      	      {3., 4., 5.}};
  // clang-format on

  vector y = dot(A, x);
}
