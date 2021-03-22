
#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

#include <assert.h>

#define BOUNDS_CHECK

#include <vector>

class vector
{
public:
  vector(int n);

  int size() const;
  double operator()(int i) const;
  double& operator()(int i);

  void print() const;

private:
  std::vector<double> data_;
};

bool operator==(const vector& x, const vector& y);

class matrix
{
public:
  matrix(int m, int n);

  void print() const;

  double operator()(int i, int j) const;
  double& operator()(int i, int j);

  int m, n;

private:
  std::vector<double> data_;
};

bool operator==(const matrix& A, const matrix& B);
double dot(const vector& x, const vector& y);
vector vector_add(const vector& x, const vector& y);
void matrix_vector_mul(const matrix& A, const vector& x, vector& y);
void matrix_matrix_mul(const matrix& A, const matrix& B, matrix& C);

// ----------------------------------------------------------------------

#include <stdio.h>

#define HERE                                                                   \
  fprintf(stderr, "HERE at %s:%d (%s)\n", __FILE__, __LINE__, __FUNCTION__)

#endif
