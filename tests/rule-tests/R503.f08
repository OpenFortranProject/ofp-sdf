!! R503 entity-decl
!    is object-name [( array-spec )]
!                   [ lbracket co-array-spec rbracket ]
!                   [ * char-length ] [ initialization ]
!    or function-name [ * char-length ]

subroutine entities(what,ever,this,ridiculous)

integer, save :: i(13)[*]
integer what[*],ever[*]
CHARACTER :: this[*]*35, ridiculous(5,6)[*]*12

end subroutine

