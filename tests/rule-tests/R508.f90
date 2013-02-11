!! R508 language-binding-spec
! is BIND (C [, NAME = scalar-char-initialization-expr ])

module R508

integer, BIND(C) :: i
10 integer, bind ( c , name = "cint" ) :: j

end module
