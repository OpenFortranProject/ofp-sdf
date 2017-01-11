!! R503 entity-decl
!    is object-name [( array-spec )]
!                   [ lbracket co-array-spec rbracket ]
!                   [ * char-length ] [ initialization ]
!    or function-name [ * char-length ]

integer :: i(13)
integer x,y,z,what,ever
real truth, beauty
CHARACTER :: this*35, ridiculous(5,6)*12
character, parameter :: p1*(*) = "x", p2*(*) = "y"

end
