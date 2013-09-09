!! R1002 format-specification
!     is  ( [ format-item-list ] )
!     or  ( [ format-items, ] unlimited-format-item )
!
! Not [completely] tested here: format-item-list.
!
001 FORMAT (*(I12, i1))
002 format (1PE12.4, *(I10))
003 format (I12, *( / 'Dates:', 22I3))
009 format(I12, /, ' Dates: ', * (2I3, I5))
010 format (I12 / 'Dates:', *(2I3, I5))
011 format (I12 / 'Dates:', *(2I3, I5))
012 format (1x, i1, 1x, 'isn''t', *(1x, i1))
013 format(1x, *(f10.3, i5))
014 format (1x, f10.3, *(i5, f10.3, i5, f10.3, i5))

end

