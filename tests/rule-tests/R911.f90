!! R911 write-stmt
!    is  WRITE ( io-control-spec-list ) [ output-item-list ]
!
! Not tested here: io-control-spec-list and output-item-list.
write(5)
write(6,10)
write(6,10, ASYNCHRONOUS="YES") i
write(5, decimal="point", ERR=12, fmt=10) a, b, c
write(err=12, unit=5)

10 format(i5)
12 end
