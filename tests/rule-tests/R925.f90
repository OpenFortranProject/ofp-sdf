!! R925 endfile-stmt
!    is  ENDFILE file-unit-number
!    or  ENDFILE ( position-spec-list )
!
! Not tested here: file-unit-number and position-spec-list.
13 end file 10
endfile(10)
endfile (unit=10, iostat=n, err=4)

4 end
