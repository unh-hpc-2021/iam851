
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

  assert(N % size == 0);
  int n = N / size;
  int ib = rank * n;
  int ie = (rank + 1) * n;

  double sum = 0.;
  double dx = 1. / N;
  double t1 = MPI_Wtime();
  for (int i = ib; i < ie; i++) {
    sum += .5 * dx * (f(i * dx) + f((i + 1) * dx));
  }
  // std::cout << "partial sum  is " << sum << "\n";
  if (rank == 0) {
    double total_sum = sum;
    for (int r = 1; r < size; r++) {
      MPI_Recv(&sum, 1, MPI_DOUBLE, r, 123, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      total_sum += sum;
    }
    std::cout << "integral is approximately " << total_sum << "\n";
  } else {
    MPI_Send(&sum, 1, MPI_DOUBLE, 0, 123, MPI_COMM_WORLD);
  }
  double t2 = MPI_Wtime();
  std::cout << "took " << t2 - t1 << " secs.\n";

  MPI_Finalize();
  return 0;
}
