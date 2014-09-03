!! R913 io-control-spec
!    is [ UNIT = ] io-unit
!    or [FMT=]format
!    or [ NML = ] namelist-group-name
!    or ADVANCE = scalar-default-char-expr
!    or ASYNCHRONOUS = scalar-char-initialization-expr
!    or BLANK = scalar-default-char-expr
!    or DECIMAL = scalar-default-char-expr
!    or DELIM = scalar-default-char-expr
!    or END = label
!    or EOR = label
!    or ERR = label
!    or ID = scalar-int-variable
!    or IOMSG = iomsg-variable
!    or IOSTAT = scalar-int-variable
!    or PAD = scalar-default-char-expr
!    or POS = scalar-int-expr
!    or REC = scalar-int-expr
!    or ROUND = scalar-default-char-expr
!    or SIGN = scalar-default-char-expr
!    or SIZE = scalar-int-variable

13 write (*,*) a
write (6,*) b
write (10,fmt=*) c 
write (unit=n,fmt=*,iostat=ios) d
write (*,err=999) e
write (10,size=i,err=999,iostat=i, advance="yes", rec=2) f

10 format(i3)

999 end

