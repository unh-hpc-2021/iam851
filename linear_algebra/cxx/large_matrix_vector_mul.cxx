
#include "linear_algebra.h"

int main(int argc, char** argv)
{
  const int N = 20000;

  double t1 = Wtime();
  vector x = xt::arange(N);
  matrix A = xt::eye(N);
  double t2 = Wtime();
  std::cout << "setup took " << t2 - t1 << " secs\n";

  double t3 = Wtime();
  vector y = dot(A, x);
  double t4 = Wtime();
  std::cout << "dot took " << t4 - t3 << " secs\n";
}
