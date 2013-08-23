!! R514 dimension-spec
!    is DIMENSION ( array-spec )
!
! From NOTE 5.12
SUBROUTINE EX (N, A, B)
   REAL, DIMENSION (N, 10) :: W
   REAL A (:), B (0:)
   REAL, POINTER :: D (:, :)
   REAL, DIMENSION (:), POINTER :: P
   REAL, ALLOCATABLE, DIMENSION (:) :: E  ! Allocatable array
   REAL, PARAMETER :: V(0:*) = [0.1, 1.1] ! Implied-shape array
END SUBROUTINE
