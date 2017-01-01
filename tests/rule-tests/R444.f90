!! R444 private-components-stmt
!    is PRIVATE
!
! From Note 4.41
!
module whut

TYPE POINT
13  PRIVATE
    REAL :: X, Y
END TYPE POINT

14 type Whoot
  private
15 integer i,j,k
16 end type

17 contains

18 end module
