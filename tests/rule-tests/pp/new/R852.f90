!! R852 computed-goto-stmt
!    is GO TO ( label-list ) [ , ] scalar-int-expr

!R313 test for label and label-list

  goto  (1, 20, 12345) -5
  GO TO (1, 20, 12345), 5

1  continue
20 continue

12345 end
