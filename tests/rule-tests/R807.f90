!! R807 block-construct
!    is block-stmt
!          [ specification-part ]
!          block
!       end-block-stmt
!
   named_block : block
      use, intrinsic :: ISO_C_BINDING, only : c_ptr
      use iso_c_binding
      volatile :: a
      integer :: b
      TYPE(c_ptr) :: c
      a = 3
   end block named_block

end
