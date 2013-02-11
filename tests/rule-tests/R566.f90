!! R566 equivalence-object
!    is variable-name
!    or array-element
!    or substring

REAL, DIMENSION(10) :: B, Y, Z

equivalence (a,b(3))
equivalence (x,y(2),z(4))

end
