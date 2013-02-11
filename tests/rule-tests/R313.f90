!! R313 label
!    is digit [digit [digit [digit [digit ]]]]
!
! Test label_list with a list of length 1,2,3.
!
GOTO (555) iblah
GO TO (555,666) iblah
goto (314,15,9), iblah

9   continue
15  continue
314 continue
555 continue

666 end
