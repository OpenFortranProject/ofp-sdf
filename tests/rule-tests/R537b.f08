!! R537 data-implied-do
!    is ( data-i-do-object-list, data-i-do-variable
!       = scalar-int-constant-expr, scalar-int-constant-expr [ , scalar-int-constant-expr ] )
!
!   - F2008 addition
!   - subscripts and nested implied-do limits inside a data-implied-do
!     can be any constant expression
!
program data_implied_do

   integer, parameter :: begin=2, end=100, stride=1
   integer :: k
   real, dimension (100, 100) :: Skew

   data ((Skew (k, j), j = k + 1, end), k = begin-1, end-1, stride) / 4950 * 1.0 /

end program

