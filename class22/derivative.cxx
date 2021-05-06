
#include "wave_equation.h"

#include <xtensor/xpad.hpp>

xt::xtensor<double, 1> derivative(const mpi_domain& domain,
                                  const xt::xtensor<double, 1>& f)
{
  const int G = 1;

  auto f_g = xt::pad(f, G);
  domain.fill_ghosts(f_g);

  auto fprime = xt::zeros_like(f);
  for (int i = 0; i < fprime.shape(0); i++) {
    fprime(i) = (f_g(i + G + 1) - f_g(i + G - 1)) / (2. * domain.dx());
  }

  return fprime;
}
