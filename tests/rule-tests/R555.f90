!! R555 target-stmt
!    is TARGET [ :: ] target-decl-list
!
!  target-decl
!    is object-name [ ( array-spec ) ] [ lbracket co-array-spec rbracket ]

10 target :: i
TARGET j, A(10,20)
!TODO-F08 target    B(10)[:]

end
