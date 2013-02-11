!! R501 type-declaration-stmt
!    is declaration-type-spec [ [ , attr-spec ] ... :: ] entity-decl-list

! intrinsic-type-spec, no attrs, w/ double colon
integer :: x
integer y
integer, pointer :: xptr
integer, pointer, allocatable :: yptr

! test entity_decl_list
real :: a,b

! intrinsic-type-spec with kind-selector
integer(kind=4) :: m

! intrinsic-type-spec with char-selector
10 Character(kind=1, len=10) :: string

end
