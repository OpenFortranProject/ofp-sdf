!! R701 primary
!    is  constant
!    or  designator
!    or  array-constructor
!    or  structure-constructor
!    or  function-reference
!    or  type-param-inquiry
!    or  type-param-name
!    or  ( expr )
!
! Each alternative is tested separately in the corresponding rule tests.
! primary is tested as an rhs.
type atype
  integer dim
end type

real :: x(2)
type(atype) :: z

a = 3
a = a
x = (/3,3/)
a = y(3,2,1)
a = func(1)
a = z%dim
a = (3)

end

