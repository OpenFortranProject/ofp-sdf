!! R540 data-stmt-value
! [ data-stmt-repeat * ] data-stmt-constant
!
! TODO- Fix AMBIGUITIES
!
CHARACTER (LEN = 10)  NAME
INTEGER, DIMENSION (0:9) :: MILES

data truth, beauty, ugly / 3.14159,2.81828,6 /
data foo / 3 /
data bar, this, that, theother / 2*3,2*7.6 /

! From NOTE 5.29
DATA NAME / "JOHN DOE" /, MILES / 10 * 0 /

end
