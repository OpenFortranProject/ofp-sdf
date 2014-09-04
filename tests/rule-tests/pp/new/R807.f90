!! R807 block-construct
!    is block-stmt
!          [ specification-part ]
!          block
!       end-block-stmt
!
   named_block : block
      use MPI3
      import MPI3
      volatile :: a
      integer :: b
      TYPE(Z) :: c
      a = 3
   end block named_block

end
