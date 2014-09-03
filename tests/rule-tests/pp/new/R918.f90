!! R918 io-implied-do
!      io-implied-do  is  ( io-implied-do-object-list, io-implied-do-control )
!
! Not tested here: io-implied-do-object-list and io-implied-do-control.
!
! io-implied-do tested as an output-itemt for a print-stmt.

print *, (a, b, c, i=1,2)
read  *, (a, b, c, i=1,10,2)

end
