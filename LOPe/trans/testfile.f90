Program PoissonMultigrid
Use MultiGrid, only : AddFourierMode
Use IO,        only : Textual_Output
Use MultiGrid, only : Restrict_1D, Prolongate_1D

Implicit None

Real, parameter :: w = (2.0/3.0)

Integer, parameter :: N      =  64
Integer, parameter :: fd     =  12

Integer :: t, i, device
Integer :: nsteps = 5

Real, allocatable, dimension(:), codimension[*] :: V1h, V2h, V4h, V8h, V16h, Buf

device = get_subimage(0)

Allocate(V1h(-1:N+1)[*])
Allocate(Buf(-1:N+1)[*])
Allocate(V2h(-1:N/2+1)[*])
Allocate(V4h(-1:N/4+1)[*])
Allocate(V8h(-1:N/8+1)[*])
Allocate(V16h(-1:N/16+1)[*])

if (device /= THIS_IMAGE()) then
  Allocate(V1h(-1:N+1)[*])    [[device]]
  Allocate(Buf(-1:N+1)[*])    [[device]]
  Allocate(V2h(-1:N/2+1)[*])  [[device]]
  Allocate(V4h(-1:N/4+1)[*])  [[device]]
  Allocate(V8h(-1:N/8+1)[*])  [[device]]
  Allocate(V16h(-1:N/16+1)[*])[[device]]
end if

open(unit=fd, file="error_time.dat")

!! Initialize
!
V1h = 0.0
Call AddFourierMode(N, V1h,  1)
Call AddFourierMode(N, V1h,  6)
Call AddFourierMode(N, V1h, 16)
V1h = (1./3.)*V1h

V1h[device] = V1h

!... Relax solution on 1h mesh
!    -------------------------
call Textual_Output(N, V1h, "1h_0")
do t = 1, nsteps
   call Relax_1D(N, V1h[device], Buf[device])  [[device]]
   call Exchange_Halo_1D(device, N, V1h)
end do
V1h = V1h[device]
write(fd, *) t, maxval(V1h)
call Textual_Output(N, V1h, "1h_mid")

!... Relax solution on 2h mesh
!    -------------------------
call Restrict_1D(N, V1h[device], V2h[device])    [[device]]
call Textual_Output(N/2, V2h, "2h_0")
do t = 1, nsteps
   call Relax_1D(N/2, V2h[device], Buf[device])  [[device]]
   call Exchange_Halo_1D(device, N/2, V2h)
end do
V2h = V2h[device]
write(fd, *) t, maxval(V2h)
call Textual_Output(N/2, V2h, "2h_mid")

!... Relax solution on 4h mesh
!    -------------------------
call Restrict_1D(N/2, V2h[device], V4h[device])  [[device]]
call Textual_Output(N/4, V4h, "4h_0")
do t = 1, nsteps
   call Relax_1D(N/4, V4h[device], Buf[device])  [[device]]
   call Exchange_Halo_1D(device, N/4, V4h)
end do
V4h = V4h[device]
write(fd, *) t, maxval(V4h)
call Textual_Output(N/4, V4h, "4h_mid")

!... Relax solution on 8h mesh
!    -------------------------
call Restrict_1D(N/4, V4h[device], V8h[device])  [[device]]
call Textual_Output(N/8, V8h, "8h_0")
do t = 1, nsteps
   call Relax_1D(N/8, V8h[device], Buf[device])  [[device]]
   call Exchange_Halo_1D(device, N/8, V8h)
end do
V8h = V8h[device]
write(fd, *) t, maxval(V8h)
call Textual_Output(N/8, V8h, "8h_mid")

!! IMPORTANT: this last step should be an exact solution on a smaller grid probably
!
! exact solution is 0, so just set to 0.
V16h = 0

V16h[device] = V16h
call Prolongate_1D(N/8, V8h[device], V16h[device])  [[device]]
do t = 1, nsteps
   call Relax_1D(N/8, V8h[device], Buf[device])    [[device]]
   call Exchange_Halo_1D(device, N/8, V8h)
end do
V8h = V8h[device]
write(fd, *) t, maxval(V8h)
call Textual_Output(N/8, V8h, "8h_end")

call Prolongate_1D(N/4, V4h[device], V8h[device])  [[device]]
do t = 1, nsteps
   call Relax_1D(N/4, V4h[device], Buf[device])    [[device]]
   call Exchange_Halo_1D(device, N/4, V4h)
end do
V4h = V4h[device]
write(fd, *) t, maxval(V4h)
call Textual_Output(N/4, V4h, "4h_end")

call Prolongate_1D(N/2, V2h[device], V4h[device])  [[device]]
do t = 1, nsteps
   call Relax_1D(N/2, V2h[device], Buf[device])    [[device]]
   call Exchange_Halo_1D(device, N/2, V2h)
end do
V2h = V2h[device]
write(fd, *) t, maxval(V2h)
call Textual_Output(N/2, V2h, "2h_end")

call Prolongate_1D(N, V1h[device], V2h[device])  [[device]]
do t = 1, nsteps
   call Relax_1D(N, V1h[device], Buf[device])    [[device]]
   call Exchange_Halo_1D(device, N, V1h)
end do
V1h = V1h[device]
write(fd, *) t, maxval(V1h)
call Textual_Output(N, V1h, "1h_end")

close(fd)

End Program PoissonMultigrid
