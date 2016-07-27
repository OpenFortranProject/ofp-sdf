! Issue # 98: https://github.com/OpenFortranProject/open-fortran-parser/issues/98
!
! A multiplication with a negative number which is not enclosed by round brackets fails to parse.
!
! WARNING from gfortran (ifort ok)
! Warning: Extension: Unary operator following arithmetic operator (use parentheses) at (1)
!
! Example:
!
PROGRAM multiply_by_negative
INTEGER :: i
i = 1*-1

END PROGRAM
