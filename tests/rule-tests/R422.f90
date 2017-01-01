!! R422 char-length
!    is ( type-param-value )
!￼￼￼￼or int-literal-constant

subroutine whoot(str_star)
integer, parameter :: a = 13

character*1    :: str1
character*2,      str2
character*(3)  :: str3
character*(a)  :: stra
character*(*)  :: str_star
character*(:), allocatable :: str_colon

end subroutine
