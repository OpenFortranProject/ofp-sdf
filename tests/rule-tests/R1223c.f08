!! R1223 actual-arg
!   - F2008 addition
!   - a null pointer or unallocated allocatable can be used to denote
!     absence of optional argument
!
program absent_optional
  INTERFACE
     SUBROUTINE SUB(X)
       REAL, optional :: X
     END SUBROUTINE SUB
  END INTERFACE

  real, allocatable :: unallocd
  real, pointer     :: aptr => NULL()

  call sub(unallocd)
  call sub(aptr)

end program
