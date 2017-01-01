!! R928 flush-stmt
!    is  FLUSH file-unit-number
!    or  FLUSH ( flush-spec-list )
!
! Not tested here: file-unit-number.

character :: cvar

13 flush 5
flush(5)
flush (5, iostat=n, iomsg=cvar, err=10)
flush (unit=5, iostat=n, iomsg=cvar, err=10)

10 end

