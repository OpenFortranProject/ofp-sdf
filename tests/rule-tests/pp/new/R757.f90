!! R757 forall-assignment-stmt
!    is assignment-stmt
!    or pointer-assignment-stmt

integer :: A(10)

forall (i = 1:10)
  A(i) = 13
end forall

END
