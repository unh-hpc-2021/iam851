
#ifndef HEAT_EQN_H
#define HEAT_EQN_H

#include "mpi_domain.h"

#include <xtensor/xcsv.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xpad.hpp>
#include <xtensor/xtensor.hpp>

namespace heat_eqn
{

// ----------------------------------------------------------------------
// calculate the r.h.s of the heat equation
//
// u_t = kappa u_xx

inline xt::xtensor<double, 1> calc_rhs(const mpi_domain& domain,
                                       const xt::xtensor<double, 1>& f,
                                       double kappa)
{
  const int G = 1;

  auto f_g = xt::pad(f, G);
  domain.fill_ghosts(f_g);

  // Python equivalent: return kappa * (f_g[2:] - 2 * f_g[1;-1] + f_g[:-2]) /
  // (dx^2);
  double dx = domain.dx();
  return kappa *
         (xt::view(f_g, xt::range(2, _)) -
          2. * xt::view(f_g, xt::range(1, -1)) +
          xt::view(f_g, xt::range(_, -2))) /
         (dx * dx);
}

} // namespace heat_eqn

#endif
