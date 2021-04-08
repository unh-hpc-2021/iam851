
#include "wtime.h"

#include <xtensor/xio.hpp>
#include <xtensor/xtensor.hpp>

#include <cmath>
#include <fstream>
#include <iostream>

// ugh, global variables are ugly

const size_t N = 100000000;
const double dx = 2. * M_PI / N;

xt::xtensor<double, 1> make_func_nc()
{
  auto f_nc = xt::empty<double>({N + 1});

  for (int i = 0; i <= N; i++) {
    double x = i * dx;
    f_nc(i) = sin(x) + (1. / 3.) * sin(3 * x);
  }

  return f_nc;
}

xt::xtensor<double, 1> avg(const xt::xtensor<double, 1>& f_nc)
{
  auto f_cc = xt::empty<double>({N});

#pragma omp parallel for
  for (int i = 0; i < N; i++) {
    f_cc(i) = .5 * (f_nc(i) + f_nc(i + 1));
  }

  return f_cc;
}

void write_nc(const xt::xtensor<double, 1>& f, const std::string& filename)
{
  std::ofstream of(filename);
  for (int i = 0; i < f.shape(0); i++) {
    of << i * dx << "\t" << f(i) << "\n";
  }
}

void write_cc(const xt::xtensor<double, 1>& f, const std::string& filename)
{
  std::ofstream of(filename);
  for (int i = 0; i < f.shape(0); i++) {
    of << (i + .5) * dx << "\t" << f(i) << "\n";
  }
}

int main(int argc, char** argv)
{
  auto f_nc = make_func_nc();
  // write_nc(f_nc, "f_nc.asc");

  for (int i = 0; i < 5; i++) {
    double tb = Wtime();
    auto f_cc = avg(f_nc);
    double te = Wtime();
    std::cout << "took " << te - tb << "\n";
  }
  // write_cc(f_cc, "f_cc.asc");
}
