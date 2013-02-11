!! R564 equivalence-stmt
!    is EQUIVALENCE equivalence-set-list
!
!  equivalence-set
!    is ( equivalence-object , equivalence-object-list )

REAL, DIMENSION(10) :: B, Y, Z

10 EQUIVALENCE (a,b(3)), (x,y(2),z(4))

end
