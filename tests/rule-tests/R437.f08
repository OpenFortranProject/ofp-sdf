!! R437 component-attr-spec
!    is access-spec
!    or ALLOCATABLE
!    or CODIMENSION lbracket coarray-spec rbracket
!    or CONTIGUOUS
!    or DIMENSION ( component-array-spec )
!    or POINTER
!
module boohoo
type woohoo
    integer, pointer, dimension(:) :: ugly
    integer, allocatable, codimension[:] ::bar 
    real, pointer :: lies1
    real, allocatable :: lies2(:,:)
    real, pointer, private :: foo
    integer, allocatable ::this(:)
    integer, allocatable, private :: that
end type
end module
