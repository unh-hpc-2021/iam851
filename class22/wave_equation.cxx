
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
  const int n_timesteps = 100;
  const int output_every = 1;

  MPI_Init(&argc, &argv);
  mpi_domain domain(MPI_COMM_WORLD, N, L);

  // create coordinates [0, 2pi)
  auto x = xt::arange<double>(domain.rank() * domain.n(),
                              (domain.rank() + 1) * domain.n()) *
           domain.dx();

  // our initial condition
  xt::xtensor<double, 1> u = sin(x);

  double dt = domain.dx();
  for (int n = 0; n < n_timesteps; n++) {
    if (n % output_every == 0) {
      std::ofstream out("u-" + std::to_string(n) + "-" +
                        std::to_string(domain.rank()) + ".csv");
      xt::dump_csv(out, xt::stack(xt::xtuple(x, u), 1));
    }

    // advance one timestep
    auto k1 = derivative(domain, u);
    auto k2 = derivative(domain, u + .5 * dt * k1);
    u += dt * k2;
  }

  MPI_Finalize();
  return 0;
}
