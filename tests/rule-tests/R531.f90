!! R531 codimension-stmt
!    is CODIMENSION [ :: ] codimension-decl-list
!
!! R532 codimension-decl
!    is coarray-name lbracket coarray-spec rbracket
!
! from NOTE 5.28
   CODIMENSION :: a[*]
   13 codimension b[3,*], c[:]

end
