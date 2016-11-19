!! R1001 format-stmt
!     is  FORMAT format-specification
!   
!! R1002 format-specification
!     is  ( [ format-item-list ] )
!     or  ( [ format-items, ] unlimited-format-item )
!
! Not [completely] tested here: format-item-list.
!
! Duplicate statements occur to test unparsing. These duplicates
! should be symantically the same (needs to be checked) and
! should unparse the same way.
!
0010 FORMAT (I12, i1)
0011 FORMAT(I12,I1)
0020 format (1pe12.4)
0021 FORMAT(1P,E12.4)
0030 format (1PE12.4, I10)
0031 FORMAT(1P,E12.4,I10)
0040 format (I12 / 'Dates:', 22I3)
0041 format (I12,/,'Dates:',22I3)
0050 format(//)
0051 format(/,/)
0060 format(:)
0070 format(:::)
0071 format(:,:,:)
0080  format(::)
0081 format(:,:)
0090 format(I12,/,' Dates: ', 2(2I3,I5))
0100 format (I12 / 'Dates:', (2I3, I5))
0101 FORMAT(I12,/,'Dates:', (2I3, I5))
0111 format (I12 / 'Dates:', 2(2I3, I5))
0112 FORMAT(I12,/,'Dates:', 2(2I3,I5))
0121 format (1x, i1, 1x, 'isn''t', 1x, i1)
0122 FORMAT(1X,I1,1X,'isn''t',1X,I1)
0131 format(1x, 2(f10.3, i5))
0132 FORMAT(1X,2(F10.3,I5))
0141 format (1x, f10.3, i5, f10.3, i5, f10.3, i5)
0142 FORMAT(1X,F10.3,I5,F10.3,I5,F10.3,I5)

end

