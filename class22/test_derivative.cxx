
#include "wave_equation.h"

#include <xtensor/xcsv.hpp>

#include <mpi.h>

#include <fstream>
#include <iostream>
#include <cassert>

int main(int argc, char** argv)
{
  const int N = 16;           // number of grid points
  const double L = 2. * M_PI; // total size of domain

  MPI_Init(&argc, &argv);
  mpi_domain domain(MPI_COMM_WORLD, N, L);

  // create coordinates [0, 2pi)
  auto x = domain.coords();

  // our original function f
  auto f = sin(x);

  // calculate derivative
  auto fprime = derivative(domain, f);

  std::ofstream out("f-" + std::to_string(domain.rank()) + ".csv");
  xt::dump_csv(out, xt::stack(xt::xtuple(x, f, fprime), 1));

  MPI_Finalize();
  return 0;
}
