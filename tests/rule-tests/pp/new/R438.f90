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
end
