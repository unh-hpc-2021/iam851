
#include <iostream>
#include <mpi.h>

int main(int argc, char** argv)
{
  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  std::cout << "Hi there " << rank << "/" << size << "\n";
  return 0;
}