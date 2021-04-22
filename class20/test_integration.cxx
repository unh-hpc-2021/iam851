
#include <cmath>
#include <iostream>
#include <cassert>

#include <mpi.h>

double f(double x)
{
  return std::sqrt(1. - x * x);
}

int main(int argc, char** argv)
{
  MPI_Init(&argc, &argv);

  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  const int N = 100000000;

  int ib, ie;
  assert(size == 2);
  if (rank == 0) {
    ib = 0;
    ie = N / 2;
  } else {
    ib = N / 2;
    ie = N;
  }
  double sum = 0.;
  double dx = 1. / N;
  double t1 = MPI_Wtime();
  for (int i = ib; i < ie; i++) {
    sum += .5 * dx * (f(i * dx) + f((i + 1) * dx));
  }
  double t2 = MPI_Wtime();
  std::cout << "took " << t2 - t1 << " secs.\n";
  std::cout << "integral is approximately " << sum << "\n";

  MPI_Finalize();
  return 0;
}
