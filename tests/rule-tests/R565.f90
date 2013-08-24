!! R565 equivalence-stmt
!    is EQUIVALENCE equivalence-set-list
!
!! R566 equivalence-set
!    is ( equivalence-object , equivalence-object-list )
!
REAL, DIMENSION(10) :: B, Y, Z
CHARACTER (LEN = 4) :: A, B
CHARACTER (LEN = 3) :: C (2)

10 EQUIVALENCE (a,b(3)), (x,y(2),z(4))

! From NOTE 5.42
EQUIVALENCE (A, C (1)), (B, C (2))

end
