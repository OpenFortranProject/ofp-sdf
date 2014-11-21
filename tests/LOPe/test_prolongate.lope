!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! Transformations needed:
!
!   1. Remove [device] and [[device]]
!   2. Add (j2h:j2h), for example
!

program test_prolongate
   use prolongation

   integer, parameter :: J = 8  ! r dimension
   real, parameter    :: S(2,0:1) = [[1.0, 0.0], [0.5, 0.5]]  ! stencil


   real :: U1h(0:J)               !  J-1   interior points, HALO(-1:*:1)
   real :: U2h(0:J/2)             !  J/2-1 interior points, HALO(-1:*:1)
   real :: error
   integer :: j1h, j2h, is

   do j2h = 0, J/2
      U2h(j2h) = 2*j2h
   end do

   do concurrent (j1h = 1:J-1)
      j2h = j1h/2
      is = mod(j1h, 2)
      call prolongate(U1h(j1h:j1h), U2h(j2h:j2h), S, is)
   end do

   do j1h = 1, J-1
      error = j1h - U1h(j1h)
      if (abs(error) > 1.e-6) then
         print *, "ERROR:", j1h, U1h(j1h)
      end if
   end do
         
   !! Test array assignment
   !
   call prolongate(U1h, U2h, [0.5, 1.0, 0.5], J, 0)

   do j1h = 1, J-1
      error = j1h - U1h(j1h)
      if (abs(error) > 1.e-6) then
         print *, "ERROR:", j1h, U1h(j1h)
      end if
   end do
         
end program
