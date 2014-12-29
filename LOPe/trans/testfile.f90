program test_restrict
   implicit none
   integer, parameter :: L = 32, M = 64
   integer(cl_int) :: device, i, j
   real, allocatable, dimension(:,:), codimension[:] :: A, B, C

   device = get_subimage(0)

   !! Allocate memory on local and remote images
   !  ------------------------------------------
   allocate(A(L,M)[*],B(L,M)[*],C(L,M)[*])

   !! Allocate memory on subimage if available
   !  ----------------------------------------
   if (device /= THIS_IMAGE()) then
      allocate(A(L,M)[*],B(L,M)[*],C(L,M)[*])   [[device]]
   end if

   !! Initialize and transfer memory to device
   !  ----------------------------------------
   A = 1; A(2,1) = 2
   B = 2

   A[device] = A
   B[device] = B

   do concurrent (i=1:L, j=1:M)  [[device]]
      call elemental_add(A(i,j)[device], B(i,j)[device], C(i,j)[device])
   end do

   !! Copy calculated value from device
   !  ---------------------------------
   C = C[device]

   print *, A(1:5,1)
   print *, B(1:5,1)
   print *, C(1:5,1)

   !! Deallocate memory on all images (including subimages)
   !  -----------------------------------------------------

   deallocate(A, B, C)

   if (device /= THIS_IMAGE()) then
      deallocate(A, B, C)   [[device]]
   end if

end program
