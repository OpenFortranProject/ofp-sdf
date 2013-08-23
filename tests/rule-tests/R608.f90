!! R608 substring
!    is  parent-string ( substring-range )
!
! Tested separately are: R609 (parent-string) and R610 (substring-range).
!
! substring tested as part of a designator, which can be part of a primary, 
! so tested as a rhs to an assignment-stmt.

a = my_string(2:3)

end

