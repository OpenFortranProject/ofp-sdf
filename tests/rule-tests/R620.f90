!! R620 section-subscript
!    is [ subscript ] : [ subscript ] [ : stride ]

subroutine foo(A,B)

real :: A(:), B(:,:), array(10), arr(10,10)
integer :: int_array(10)

a = array(1)		! subscript
a = array(:)		! subscript-triplet
a = array(1:)		! subscript-triplet
a = array(:2)		! subscript-triplet
a = array(1:2)		! subscript-triplet
a = array(::3)		! subscript-triplet
a = array(1::3)		! subscript-triplet
a = array(:2:3)		! subscript-triplet
a = array(1:2:3)	! subscript-triplet
B = arr  (1:2:3,5:10:2)	! subscript-triplet
a = array(int_array)	! vector-subscript

end subroutine
