
#include "linear_algebra.h"

int main(int argc, char** argv)
{
  const int N = 20000;
  vector x = xt::arange(N);
  matrix A = xt::eye(N);

  vector y = dot(A, x);
}
