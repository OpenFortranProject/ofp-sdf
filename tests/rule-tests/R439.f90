!! R439 component-array-spec
!    is explicit-shape-spec-list
!    or deferred-shape-spec-list
!
INTEGER, PARAMETER :: a = 3, x = 4, y = 13
type ugly
  REAL, pointer :: truth(:)
  REAL, POINTER :: beauty(:,:,:,:,:)
  integer :: foo(2,3,4,a,x)
  REAL :: bar(y)
  real lies(8)
END TYPE
END PROGRAM
