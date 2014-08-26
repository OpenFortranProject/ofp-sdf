! R1211 procedure-declaration-stmt
!                      is  PROCEDURE ( [ proc-interface ] ) 
!                                        [ [ , proc-attr-spec ] ... :: ] 
!                                        proc-decl-list
!
!      proc-interface  is  interface-name
!                      or  declaration-type-spec
!
!      proc-attr-spec  is  access-spec
!                      or  proc-language-binding-spec
!                      or  INTENT ( intent-spec )
!                      or  OPTIONAL
!                      or  POINTER
!                      or  SAVE
!
!      proc-decl  is  procedure-entity-name [ => null-init ]
!
!      interface-name  is  name
!
! Not tested here: name, declaration-type-spec, access-spec, 
! proc-language-binding-spec, intent-spec, procedure-entity-name, and 
! null-init.

! Test with no optional parts.
13 PROCEDURE() a1
PROCEDURE() a2, b2

! Test with optional proc-interface.
PROCEDURE(c) a3
PROCEDURE(c) a4, b4
PROCEDURE(INTEGER(4)) a5

! Test with optional ::
PROCEDURE(c) :: a6

! Test with optional proc-attr-spec
PROCEDURE(c), BIND(C), PUBLIC, POINTER :: a7, b7

! Test with optional null-init
PROCEDURE(c), POINTER :: func_ptr=>NULL(), b8

END
