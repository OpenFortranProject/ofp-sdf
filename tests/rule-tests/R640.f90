!! R640 deallocate-stmt
!    is  DEALLOCATE ( allocate-object-list [, dealloc-opt-list] )
!
! Tested separately is: allocate-object-list (R632).
INTEGER, ALLOCATABLE :: a, B, X
CHARACTER(3) :: m = "err"

13 DEALLOCATE(a)
deallocate(a,stat=i)
deallocate(a, stat=i, errmsg=m)

! NOTE 6.22
DEALLOCATE (X, B)

end
