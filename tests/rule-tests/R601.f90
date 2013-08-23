!! R601 designator
!    is  object-name
!    or  array-element
!    or  array-section
!    or  complex-part-designator
!    or  structure-component
!    or  substring
! 
! Full tests for each of the alternatives is done separately.  
!
! designator tested as part of a variable (R602), which is used as part of 
! an assignment-stmt (R732).

a = 1
a(1) = 1
a(1:2) = 1
a%b = 1

end

