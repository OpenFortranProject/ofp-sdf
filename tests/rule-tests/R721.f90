!! R721 equiv-op
!    is .EQV.
!    or .NEQV.
logical :: a, b, c, d

a = b .EQV. c
a = b.neqv.c
a = a .NEQV. b .eqv. c .and. d
a = b .AND. c .eqv. .not. d

end
