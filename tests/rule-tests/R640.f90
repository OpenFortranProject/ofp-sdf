!! R640 deallocate-stmt
!    is  DEALLOCATE ( allocate-object-list [, dealloc-opt-list] )
!
! Tested separately is: allocate-object-list (R632).

13 DEALLOCATE(a)
deallocate(a,stat=i)
deallocate(a, stat=i, errmsg=m)

end
