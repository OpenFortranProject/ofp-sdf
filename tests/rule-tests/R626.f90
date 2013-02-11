!! R626 allocate-stmt
!    is  ALLOCATE ( [ type-spec :: ] allocation-list [, alloc-opt-list ] )
!
! Tested separately are: type-spec (R402) and allocation-list (R631).

10 ALLOCATE(a,b)
allocate(integer::a,b)
allocate(a,stat=i, errmsg=blah, source=k)

end

