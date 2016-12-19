!! R312 label
!    is digit [digit [digit [digit [digit ]]]]
!
! Test label_list with a list of length 1,2,3.
!
GOTO (0555) iblah
GO TO (550,01234) iblah
goto (0314,15,9), iblah

9   continue
15  continue
0314 continue
0555 continue
550  continue

01234 end
