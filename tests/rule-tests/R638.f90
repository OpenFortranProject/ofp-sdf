!! R638 nullify-stmt
!    is  NULLIFY ( pointer-object-list )
!
! Tested separetly is: pointer-object-list (R639)

real, pointer :: a

13 nullify(a)
nullify(a%b)

end
