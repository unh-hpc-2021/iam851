#ifndef WAVE_EQUATION_H
#define WAVE_EQUATION_H

#include <xtensor/xtensor.hpp>
#include <xtensor/xio.hpp>

xt::xtensor<double, 1> derivative(const xt::xtensor<double, 1>& f, double dx);

#endif