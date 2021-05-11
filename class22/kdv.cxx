
#include "mpi_domain.h"

#include <xtensor/xcsv.hpp>
#include <xtensor/xpad.hpp>

#include <fstream>
#include <iostream>

xt::xtensor<double, 1> rhs(const mpi_domain& domain,
                           const xt::xtensor<double, 1>& u)
{
  const int G = 2;

  auto u_g = xt::pad(u, G);
  domain.fill_ghosts(u_g);

  double dx3i = 1. / (2 * std::pow(domain.dx(), 3));
  double dxi = 1. / (2. * domain.dx());

  auto rhs = xt::zeros_like(u);
  for (int i = 0; i < rhs.shape(0); i++) {
    rhs(i) = (u_g(G + i + 2) - 2 * u_g(G + i + 1) + 2 * u_g(G + i - 1) -
              u_g(G + i - 2)) *
               dx3i -
             6 * u_g(i + G) * (u_g(i + G + 1) - u_g(i + G - 1)) * dxi;
  }

  return rhs;
}

int main(int argc, char** argv)
{
  const int N = 16;           // number of grid points
  const double L = 2. * M_PI; // total size of domain
  const int n_timesteps = 100;
  const int output_every = 1;

  MPI_Init(&argc, &argv);
  mpi_domain domain(MPI_COMM_WORLD, N, L);

  // create coordinates [0, 2pi)
  auto x = domain.coords();

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
    auto k1 = rhs(domain, u);
    auto k2 = rhs(domain, u + .5 * dt * k1);
    u += dt * k2;
  }

  MPI_Finalize();
  return 0;
}
