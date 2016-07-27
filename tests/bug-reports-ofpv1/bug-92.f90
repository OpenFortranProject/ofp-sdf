! Issue # 92: https://github.com/OpenFortranProject/open-fortran-parser/issues/92
!
! When a function is declared with an initial type of 'character()', the parser gives the following error message:
! no viable alternative at input 'f'
! Such a declaration is legal -- see Fortran 90 Specification (N692) 5.1.1.5 rule R509, list item (3).
! 
! If the alternative syntax 'character(len=*)' is used, the function parses correctly.
!
character(*) function name()
   name = "kindness"
end function
