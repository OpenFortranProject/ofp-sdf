!! R807 block-construct
!    is block-stmt
!          [ specification-part ]
!          block
!       end-block-stmt
!
   named_block : block
      integer :: b
      a = 3
   end block named_block

   BLOCK
     c = 13
   END BLOCK

   block
   end block

end
