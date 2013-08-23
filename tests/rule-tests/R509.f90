!! R509 coarray-spec
!    is deferred-coshape-spec-list
!    or explicit-coshape-spec
!
! From NOTE 5.7
REAL    :: A(N)[*], B(N)

! from NOTE 5.8
REAL  W(100,100)[0:2,*]
REAL, CODIMENSION[*] :: X
REAL, CODIMENSION[3,*] :: Y(:)

real :: x[3,*]

end
