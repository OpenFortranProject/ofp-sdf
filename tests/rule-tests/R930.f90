!! R930 inquire-stmt
!    is  INQUIRE ( inquire-spec-list )
!    or  INQUIRE ( IOLENGTH = scalar-int-variable ) output-item-list
!
! Not tested here: inquire-spec-list, scalar-int-variable, and
!  output-item-list.

character :: cvar

inquire(10)
inquire(file='foo.txt', blank=cvar)
inquire(10, blank=cvar)
inquire(ENCODING=cvar, unit=10)
inquire(iolength=ix) a, b, c

end
