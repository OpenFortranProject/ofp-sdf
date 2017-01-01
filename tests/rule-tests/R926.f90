!! R926 rewind-stmt
!    is  REWIND file-unit-number
!    or  REWIND ( position-spec-list )
!
! Not tested here: file-unit-number and position-spec-list.

integer unitnumber
11 REWIND(unitnumber)
rewind unitnumber
12 rewind 10
rewind (10, iostat=n, err=4)

4 end
