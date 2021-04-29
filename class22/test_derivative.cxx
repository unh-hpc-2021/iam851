
#include <xtensor/xcsv.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xpad.hpp>
#include <xtensor/xtensor.hpp>

#include <mpi.h>

#include <fstream>
#include <iostream>
#include <cassert>

xt::xtensor<double, 1> derivative(const xt::xtensor<double, 1>& f, double dx)
{
  const int G = 1;

  int n = f.shape(0);
  auto f_g = xt::pad(f, G);

  // fill ghosts
  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  int left = rank > 0 ? rank - 1 : size - 1;
  int right = rank < size - 1 ? rank + 1 : 0;
  MPI_Send(&f_g(G + 0), 1, MPI_DOUBLE, left, 123, MPI_COMM_WORLD);
  MPI_Recv(&f_g(G + n), 1, MPI_DOUBLE, right, 123, MPI_COMM_WORLD,
           MPI_STATUS_IGNORE);

  MPI_Send(&f_g(G + n - 1), 1, MPI_DOUBLE, right, 456, MPI_COMM_WORLD);
  MPI_Recv(&f_g(G + -1), 1, MPI_DOUBLE, left, 456, MPI_COMM_WORLD,
           MPI_STATUS_IGNORE);

#if 1
  auto fprime = xt::zeros_like(f);
  for (int i = 0; i < n; i++) {
    fprime(i) = (f_g(i + G + 1) - f_g(i + G - 1)) / (2. * dx);
  }

  return fprime;
#else
  // Python equivalent: return (f_g[2:] - f_g[:-2]) / (2. * dx);
  return (xt::view(f_g, xt::range(2, _)) - xt::view(f_g, xt::range(_, -2))) /
         (2. * dx);
#endif
}

int main(int argc, char** argv)
{
  const int N = 16; // number of grid points

  MPI_Init(&argc, &argv);
  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  assert(N % size == 0); // # grid points must be divisible by # procs
  int n = N / size;

  // create coordinates [0, 2pi)
  double L = 2. * M_PI; // total size of domain
  double dx = L / N;
  auto x = xt::arange<double>(rank * n, (rank + 1) * n) * dx;

  // our original function f
  auto f = sin(x);

  // calculate derivative
  auto fprime = derivative(f, dx);

  std::ofstream out("f-" + std::to_string(rank) + ".csv");
  xt::dump_csv(out, xt::stack(xt::xtuple(x, f, fprime), 1));

  MPI_Finalize();
  return 0;
}
