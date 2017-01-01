!! R451 binding-attr
!    is PASS [ (arg-name ) ]
!    or NOPASS
!    or NON_OVERRIDABLE
!    or DEFERRED
!    or access-spec
! 
type truth
contains
  procedure, pass(beauty) :: foo
  procedure, pass, deferred ::boo
  procedure, non_overridable, private:: hoo
  procedure,public :: loo,doo=>goo
end type truth
end
