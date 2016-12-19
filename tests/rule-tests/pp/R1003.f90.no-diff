!! R1003 format-items
!     format-item [ [ , ] format-item ] ...
!
! NOTE 10.1
!
5     FORMAT (1PE12.4, I10)
9     FORMAT (I12, /, ' Dates: ', 2 (2I3, I5))

!! Optional comma
!
10 FORMAT    (I12, /  ' Dates: ', 2 (2I3, I5))
11 FORMAT    (I12  /,  ' Dates: ', 2 (2I3, I5))
12 FORMAT    (I12  /  ' Dates: ', 2 (2I3, I5))
13 FORMAT    (I12, :  ' Dates: ', 2 (2I3, I5))
14 FORMAT    (I12  :,  ' Dates: ', 2 (2I3, I5))
15 FORMAT    (I12  :  ' Dates: ', 2 (2I3, I5))

!
! NOTE 10.3
!
WRITE (6, 100) 2, 3
100 FORMAT (1X, I1, 1X, 'ISN''T', 1X, I1)
    WRITE (6, '(1X, I1, 1X, ''ISN''''T'', 1X, I1)') 2, 3
    WRITE (6, '(A)') ' 2 ISN''T 3'

end

