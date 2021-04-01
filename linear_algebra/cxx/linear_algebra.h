
#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

#define BOUNDS_CHECK

#include <xtensor/xtensor.hpp>

#include <cassert>
#include <vector>
#include <ostream>

using vector = xt::xtensor<double, 1>;
using matrix = xt::xtensor<double, 2>;

double dot(const vector& x, const vector& y);
vector dot(const matrix& A, const vector& x);

void matrix_matrix_mul(const matrix& A, const matrix& B, matrix& C);

// ----------------------------------------------------------------------
// other useful stuff

#include <sys/time.h>
#include <stdlib.h>

static inline double Wtime(void)
{
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec + tv.tv_usec / 1e6;
}

// ----------------------------------------------------------------------

#include <stdio.h>

#define HERE                                                                   \
  fprintf(stderr, "HERE at %s:%d (%s)\n", __FILE__, __LINE__, __FUNCTION__)

#endif
