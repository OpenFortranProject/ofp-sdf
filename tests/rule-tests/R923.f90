!! R923 wait-spec
!    is [ UNIT = ] file-unit-number
!    or END = label
!    or EOR = label
!    or ERR = label
!    or ID = scalar-int-expr
!    or IOMSG = iomsg-variable
!    or IOSTAT = scalar-int-variable

CHARACTER :: cvar

10  wait (5, end=99)
    wait (iomsg=cvar, err=314,eor=99,end=10, UNIT=6)

314 CONTINUE
99  end
