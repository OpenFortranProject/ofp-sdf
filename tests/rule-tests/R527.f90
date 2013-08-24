!! R527 allocatable-decl
!    is object-name [ ( array-spec ) ] [ lbracket co-array-spec rbracket ]

   ALLOCATABLE coscalar[*]
   allocatable :: coarray[5,3:7,*]
   allocatable :: combo(:,:)[*]

end
