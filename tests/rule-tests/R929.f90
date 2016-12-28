!! R928 flush-spec
!    is [UNIT =] file-unit-number
!    or IOSTAT = scalar-int-variable
!    or IOMSG = iomsg-variable
!    or ERR = label

character :: cvar

11 flush(unit=5)
12 flush(6, iostat=ifoo, err=13, iomsg=cvar)

13 end
