!! R909 close-spec
!    is [ UNIT = ] file-unit-number
!    or IOSTAT = scalar-int-variable
!    or IOMSG = iomsg-variable
!    or ERR = label
!    or STATUS = scalar-default-char-expr

character :: msg

close(10)
close(UNIT=10)
close(unit=20, status='keep', err=1235)
1235 CLOSE(10, IOSTAT=ivar, IOMSG = msg)
end
