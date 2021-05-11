
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
  const int N = 128;          // number of grid points
  const double L = 2. * M_PI; // total size of domain
  const int n_timesteps = 100000;
  const int output_every = 1000;

  MPI_Init(&argc, &argv);
  mpi_domain domain(MPI_COMM_WORLD, N, L);

  // create coordinates [0, 2pi)
  auto x = domain.coords();

// our initial condition
#if 1
  xt::xtensor<double, 1> u = sin(x);
#else
  double c = 3.;
  xt::xtensor<double, 1> u =
    -.5 * c / xt::pow(xt::cosh(.5 * std::sqrt(c) * (x - M_PI)), 2);
#endif

  // a very stringent CLF condition
  double dt = .1 * std::pow(domain.dx(), 3);

  for (int n = 0; n < n_timesteps; n++) {
    if (n % output_every == 0) {
      std::ofstream out("u-" + std::to_string(n) + "-" +
                        std::to_string(domain.rank()) + ".csv");
      xt::dump_csv(out, xt::stack(xt::xtuple(x, u), 1));
      std::cout << "writing output " << n << "\n";
    }

    // advance one timestep
    auto k1 = rhs(domain, u);
    auto k2 = rhs(domain, u + .5 * dt * k1);
    auto k3 = rhs(domain, u + .5 * dt * k2);
    auto k4 = rhs(domain, u + dt * k3);
    u += (1. / 6.) * dt * (k1 + 2. * k2 + 2. * k3 + k4);
  }

  MPI_Finalize();
  return 0;
}
