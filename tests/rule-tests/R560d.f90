!! R560 implicit-stmt
!
! From NOTE 5.39
!
! Implicit typing is not affected by BLOCK constructs. For example, in
!
!TODO - very AMBIGUOS

     SUBROUTINE S(N)
       !...
       IF (N>0) THEN
         BLOCK
           NSQP = CEILING(SQRT(DBLE(N)))
         END BLOCK
       END IF
!...
       IF (N>0) THEN
         BLOCK
           PRINT *,NSQP
         END BLOCK
       END IF
     END SUBROUTINE
!
! even if the only two appearances of NSQP are within the BLOCK constructs,
! the scope of NSQP is the whole subroutine S.
