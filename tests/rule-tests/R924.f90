!! R924 backspace-stmt
!    is  BACKSPACE file-unit-number
!    or  BACKSPACE ( position-spec-list )
!
! Not tested here: file-unit-number and position-spec-list.
integer :: unitnumber
11 backspace 10
backspace (10)
backspace (unit=unitnumber, iostat=n)

end
