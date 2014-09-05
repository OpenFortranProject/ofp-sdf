!! R526 allocatable-stmt
!    is ALLOCATABLE [ :: ] allocatable-decl-list
!
!  allocatable-decl
!    is object-name [ ( array-spec ) ] [ lbracket co-array-spec rbracket ]

!TODO-F08 add co-array-spec

10  ALLOCATABLE a
Allocatable :: B( :,  :), C(:), scalar

end
