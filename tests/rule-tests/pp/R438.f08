TYPE GRID_TYPE
  REAL, ALLOCATABLE, CODIMENSION[:,:,:] :: GRID1(:,:,:)
  REAL, ALLOCATABLE :: GRID2(:,:,:)[:,:,:]
  INTEGER :: i = 13
END TYPE GRID_TYPE
TYPE nasty
  INTEGER :: truth, beauty, ugly, lies
  REAL :: foo(3,4,5:9)
  REAL, ALLOCATABLE :: bar[:]
  CHARACTER :: this*35, ridiculous(5,6)*12
  INTEGER :: that = 4
  REAL, ALLOCATABLE :: ridic(:,:)[:]
  REAL, POINTER :: ridicule(:) => null()
END TYPE
END PROGRAM
