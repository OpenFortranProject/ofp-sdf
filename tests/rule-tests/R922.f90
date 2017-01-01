!! R922 wait-stmt
!    is  WAIT ( wait-spec-list )
!
! Not tested here: wait-spec-list

character cvar

10 wait (5, end=99)
wait (iomsg=cvar, err=314, eor=99, end=10, unit=6)

314 continue

99 end
