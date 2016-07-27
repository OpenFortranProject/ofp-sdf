! Issue # 78: https://github.com/OpenFortranProject/open-fortran-parser/issues/78
!
! A goto statement in a labelled line fails to parse. Tested with current version from git.
! Example:
!
program test_goto
21 GO TO 90
90 CONTINUE
end program
