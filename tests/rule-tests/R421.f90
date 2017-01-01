!! R421 length-selector
!    is ( [ LEN = ] type-param-value )
!    or * char-length [ , ]

character*1    :: str1
character*2,      str2
character(len=3)  str3
character(:), allocatable :: str_colon

end
