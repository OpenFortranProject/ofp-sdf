!! R853 arithmetic-if-stmt
!    is  IF ( scalar-numeric-expr ) label, label, label
!
! Tested here: arithmetic-if-stmt
!
! Not tested here: scalar-numeric-expr and label.
if(x) 10, 20, 30

10 continue
20 CONTINUE
30 END

