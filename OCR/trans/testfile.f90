MODULE test_module

  USE global_module, ONLY: i_knd, r_knd, zero

  IMPLICIT NONE

  PUBLIC

  REAL(r_knd), ALLOCATABLE, DIMENSION(:) :: pop

  CONTAINS

  SUBROUTINE alloc ( ierr )
!-----------------------------------------------------------------------
!
! Allocate test_module arrays.
!
!-----------------------------------------------------------------------

    ALLOCATE( pop(ng), STAT=ierr )
    IF ( ierr /= 0 ) RETURN

    pop = zero

  END SUBROUTINE alloc

  SUBROUTINE dealloc
!-----------------------------------------------------------------------
!
! Deallocate test_module arrays.
!
!-----------------------------------------------------------------------

    DEALLOCATE( pop )

  END SUBROUTINE dealloc


END MODULE test_module
