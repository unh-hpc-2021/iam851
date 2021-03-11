
#define N 3
#define M 4

! ----------------------------------------------------------------------
subroutine print_matrix(A)
! ----------------------------------------------------------------------
  implicit none
  
  real*8 A(N, M)
  integer i, j
  
  do i = 1, N 
     do j = 1, M
        write(*, ' (F4.0)', advance='no') A(i, j) ! this is Fortran90
     end do
     write(*, *)
  end do
  
end subroutine print_matrix

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
  
end program main

