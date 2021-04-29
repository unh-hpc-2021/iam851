#ifndef WAVE_EQUATION_H
#define WAVE_EQUATION_H

#include <xtensor/xtensor.hpp>
#include <xtensor/xio.hpp>

#include <mpi.h>

#include <cassert>

class mpi_domain
{
public:
  mpi_domain(MPI_Comm comm, int N, double L) : comm_(comm), N_(N), L_(L)
  {
    MPI_Comm_rank(comm, &rank_);
    MPI_Comm_size(comm, &size_);
    // number of grid points must be divisible by number of procs
    // (this could be relaxed, but needs to be handled properly)
    assert(NGROUPS_MAX % size_ == 0);
    n_ = N_ / size_;
    dx_ = L_ / N_;
  }

  MPI_Comm comm() const { return comm_; }
  int rank() const { return rank_; }
  int size() const { return size_; }
  int N() const { return N_; }
  int n() const { return n_; }
  double dx() const { return dx_; }

  auto coords() const
  {
    return xt::arange<double>(rank() * n(), (rank() + 1) * n()) * dx();
  }

  void fill_ghosts(xt::xtensor<double, 1>& f_g) const
  {
    // assume f_g has exactly one ghost point
    const int G = 1;
    assert(f_g.shape(0) == n_ + 2 * G);

    int rank_left = rank_ < size_ - 1 ? rank_ + 1 : 0;
    int rank_right = rank_ > 0 ? rank_ - 1 : size_ - 1;

    MPI_Send(&f_g(G + 0), 1, MPI_DOUBLE, rank_left, 123, comm());
    MPI_Recv(&f_g(G + n_), 1, MPI_DOUBLE, rank_right, 123, comm(),
             MPI_STATUS_IGNORE);

    MPI_Send(&f_g(G + n_ - 1), 1, MPI_DOUBLE, rank_right, 456, comm());
    MPI_Recv(&f_g(G + -1), 1, MPI_DOUBLE, rank_left, 456, comm(),
             MPI_STATUS_IGNORE);
  }

private:
  MPI_Comm comm_;
  int rank_;
  int size_;
  int N_;
  int n_;
  double L_;
  double dx_;
};

xt::xtensor<double, 1> derivative(const mpi_domain& domain,
                                  const xt::xtensor<double, 1>& f);

#endif