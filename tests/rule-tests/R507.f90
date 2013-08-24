!! R507 access-spec
!    is PUBLIC
!    or PRIVATE

TYPE, PUBLIC :: A
END TYPE
type, private :: a
end type

! From NOTE 5.3
REAL, PRIVATE :: X, Y, Z

end
