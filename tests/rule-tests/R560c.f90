!! R560 implicit-stmt
!
! From NOTE 5.38
!
PROGRAM MAIN
     IMPLICIT TYPE(BLOB) (A)
       TYPE BLOB
         INTEGER :: I
       END TYPE BLOB
       TYPE(BLOB) :: B
       CALL STEVE
     CONTAINS
       SUBROUTINE STEVE
         INTEGER :: BLOB
         !..
         AA = B
         !..
       END SUBROUTINE STEVE
     END PROGRAM MAIN
