
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

void matrix_vector_mul(const matrix& A, const vector& x, vector& y);
void matrix_matrix_mul(const matrix& A, const matrix& B, matrix& C);

// ----------------------------------------------------------------------

#include <stdio.h>

#define HERE                                                                   \
  fprintf(stderr, "HERE at %s:%d (%s)\n", __FILE__, __LINE__, __FUNCTION__)

#endif
