!! R458 enum-def
!    is enum-def-stmt enumerator-def-stmt
!            [ enumerator-def-stmt ] ... end-enum-stmt
!
! NOTE 4.67

10 ENUM, BIND(C)
11   ENUMERATOR :: RED = 4, BLUE = 9
     ENUMERATOR YELLOW
12 END ENUM

end
