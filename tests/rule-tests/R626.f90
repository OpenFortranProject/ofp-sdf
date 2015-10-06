!! R626 allocate-stmt
!    is  ALLOCATE ( [ type-spec :: ] allocation-list [, alloc-opt-list ] )
!
! Tested separately are: type-spec (R402) and allocation-list (R631).

INTEGER, ALLOCATABLE :: a, b, X(:), Y(:,:)
CHARACTER(4) :: blah = "blah"

10 ALLOCATE(a,b)
allocate(integer::a,b)
allocate(a,stat=i, errmsg=blah, source=k)

! NOTE 6.19
ALLOCATE (X (N), B (-3 : M, 0:9), STAT = IERR_ALLOC)

end

