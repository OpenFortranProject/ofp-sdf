!! R506 null-init
!    is  function-reference
!
! Function reference must be a reference to the NULL intrinsic function with
! no arguments (C506).
!
! null-init is tested as part of an initialization (R505), which is part of 
! an entity-decl (R503), which is part of a type-declaration-stmt (R501).

integer, pointer :: a => NULL()

end

