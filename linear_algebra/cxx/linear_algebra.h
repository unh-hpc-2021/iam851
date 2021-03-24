
#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

#define BOUNDS_CHECK

#include <xtensor/xtensor.hpp>

#include <cassert>
#include <vector>
#include <ostream>

using vector = xt::xtensor<double, 1>;

double dot(const vector& x, const vector& y);

class matrix
{
public:
  matrix(int n_rows, int n_cols);

  double operator()(int i, int j) const;
  double& operator()(int i, int j);

  int n_rows() const { return m_; }
  int n_cols() const { return n_; }

private:
  int m_, n_;
  std::vector<double> data_;
};

bool operator==(const matrix& A, const matrix& B);
std::ostream& operator<<(std::ostream& os, const matrix& A);

void matrix_vector_mul(const matrix& A, const vector& x, vector& y);
void matrix_matrix_mul(const matrix& A, const matrix& B, matrix& C);

// ----------------------------------------------------------------------

#include <stdio.h>

#define HERE                                                                   \
  fprintf(stderr, "HERE at %s:%d (%s)\n", __FILE__, __LINE__, __FUNCTION__)

#endif
