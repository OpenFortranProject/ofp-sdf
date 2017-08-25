!! R808 block-stmt
!    is [ block-construct-name : ] BLOCK
!
integer :: a
10 named_block : BLOCK
  INTEGER :: b
  b = 3
11 end BLOCK named_block
12 block
  a = 13
13 END block

END program
