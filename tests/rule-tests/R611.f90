!! R611 data-ref
!    is part-ref [ % part-ref ] ...
!
type TB
  integer :: c
end type TB
type TA
  type(TB) :: b
end type TA

type(TA) :: lhs_a, a
type(TB) :: lhs_b
integer  :: lhs_c

lhs_a = a
lhs_b = a%b
lhs_c = a%b%c

end
