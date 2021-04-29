#ifndef WAVE_EQUATION_H
#define WAVE_EQUATION_H

#include <xtensor/xtensor.hpp>
#include <xtensor/xio.hpp>

#include <mpi.h>

xt::xtensor<double, 1> derivative(const xt::xtensor<double, 1>& f, double dx);

class mpi_domain
{
public:
  mpi_domain(MPI_Comm comm, int N) : comm_(comm), N_(N)
  {
    MPI_Comm_rank(comm, &rank_);
    MPI_Comm_size(comm, &size_);
    // number of grid points must be divisible by number of procs
    // (this could be relaxed, but needs to be handled properly)
    assert(NGROUPS_MAX % size_ == 0);
    n_ = N_ / size_;
  }

  MPI_Comm comm() const { return comm_; }
  int rank() const { return rank_; }
  int size() const { return size_; }
  int N() const { return N_; }
  int n() const { return n_; }

private:
  MPI_Comm comm_;
  int rank_;
  int size_;
  int N_;
  int n_;
};

#endif