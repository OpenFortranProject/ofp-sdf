Module Prolongation

Contains

!!!!!
! This version will require "loop" fusion to optimize so there is
! only one kernel to run.
!
Subroutine interp_1D_deconvolve(U1h, U2h, S, device)
  real, intent(out) :: U1h(1:N-1)   ! fine grid
  real, intent(in ) :: U2h(1:N/2-1) ! coarse grid
  real, intent(out) :: S(3)         ! stencil
  integer           :: device       ! execution device

  U1h(1:N-3:2)[device] = S(1)*U2h(1:N/2-1)[device]  [[device]]   ! take right
  U1h(2:N-2:2)[device] = S(2)*U2h(1:N/2-1)[device]  [[device]]   ! take center
  U1h(3:N-1:2)[device] = S(3)*U2h(1:N/2-1)[device]  [[device]]   ! take left

End Subroutine Deconvolve_1D_array_assign


Pure CONCURRENT Subroutine(U1h, U2h, S, is)
  real, intent(out), HALO(:) :: U1h       ! fine grid
  real, intent(in ), HALO(:) :: U2h       ! coarse grid
  real, intent(out)          :: S(2,2)    ! stencil
  integer, intent(in)        :: is        ! stencil selector (odd=1, even=2)
  
  U1h(0) = sum( S(:,is)*Uh2(0:1) )

End Subroutine


End Module Prolongation
