!! R438 component-decl
!    is component-name
!           [ ( component-array-spec ) ]
!           [ lbracket coarray-spec rbracket ]
!           [ * char-length ] [ component-initialization ]
!
! from NOTE 4.30
   TYPE GRID_TYPE 
      REAL, ALLOCATABLE, CODIMENSION[:,:,:] :: GRID1(:,:,:) 
      real, ALLOCATABLE :: GRID2(:,:,:)[:,:,:]
      Type(integer) :: i = 13
   END TYPE GRID_TYPE 

type nasty
	integer truth, beauty, ugly, lies
	real foo(3,4,5:9)
	real, allocatable :: bar[:]
	character this*35, ridiculous(5,6)*12
        integer :: that =4
	real, allocatable :: ridic(:,:)[:]
	real, pointer :: ridicule(:) => null()
end type

end
