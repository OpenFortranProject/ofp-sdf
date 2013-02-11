!! R523 intent-spec
!    is  IN
!    or  OUT
!    or  INOUT
!
! Tested as part of attr-spec (R502), which is part of a 
! type-declaration-stmt (R501).

Subroutine FooBar(a,b,c,D)

integer, intent(in) :: a
integer, intent(out) :: b
integer, intent(INOUT) :: c
20 integer, intent(in OUT) :: d

10 END subroutine

