!! R757 forall-assignment-stmt
!    is assignment-stmt
!    or pointer-assignment-stmt

! NOTE 7.57

integer, parameter :: N=10
integer :: i, j, Y(10,10)
integer :: A(10,10), X(10), Z(10,10)

13 FORALL (I=1:N) A(I,I) = X(I)

forall (I = 1:N, J = 1:N)  Z(I,J) = 1.0 / REAL (I+J-1)

FORALL (I=1:N, J=1:N, Y(I,J) /= 0 .AND. I /= J)  Z(I,J) = 1.0 / Y(I,J)

END
