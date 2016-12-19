INTEGER, PARAMETER :: a = 3, x = 4, y = 13
TYPE ugly
  REAL, POINTER :: truth(:)
  REAL, POINTER :: beauty(:,:,:,:,:)
  INTEGER :: foo(2,3,4,a,x)
  REAL :: bar(y)
  REAL :: lies(8)
END TYPE
END PROGRAM
