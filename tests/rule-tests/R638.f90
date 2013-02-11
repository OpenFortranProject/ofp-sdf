!! R638 nullify-stmt
!    is  NULLIFY ( pointer-object-list )
!
! Tested separetly is: pointer-object-list (R639)

real, pointer :: a

nullify(a)
nullify(a%b)

end
