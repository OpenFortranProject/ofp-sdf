!! R1005 unlimited-format-item
!     is * ( format-items )
!
! Use with G0 to create CSV output
!
program G0
  integer :: I(3) = [1,2,3]

  write (*, "(*(G0:','))") I
  write (*, fmt="(*(g0:','))") 12,1.34,"abc","defe", 45
end program
