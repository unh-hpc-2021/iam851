
#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

#include <assert.h>

#define BOUNDS_CHECK

#include <vector>
#include <ostream>

class vector
{
public:
  vector(int n);

  int size() const;
  double operator()(int i) const;
  double& operator()(int i);

private:
  std::vector<double> data_;
};

bool operator==(const vector& x, const vector& y);
std::ostream& operator<<(std::ostream& os, const vector& v);
double dot(const vector& x, const vector& y);
vector operator+(const vector& x, const vector& y);

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
