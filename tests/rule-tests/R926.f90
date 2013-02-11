!! R926 position-spec
!    is  [ UNIT = ] file-unit-number
!    or  IOMSG = iomsg-variable
!    or  IOSTAT = scalar-int-variable
!    or  ERR = label

character cvar

backspace (iomsg=CVAR, unit=5)
rewind (5, iomsg=cvar,err=314,iostat=iugly)

314 end
