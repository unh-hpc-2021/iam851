
#define N 3
#define M 4

! ----------------------------------------------------------------------
program main
! ----------------------------------------------------------------------
  implicit none
  
  real*8 A(N, M)
  integer i, j
  
  do i = 1, N 
     do j = 1, M
        A(i, j) = i * 10 + j
     end do
  end do
  
  print *, 'print_matrix'
  call print_matrix(A)

  print *, 'print_matrix_linear'
  call print_matrix_linear(A)
  
end program main

