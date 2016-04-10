10 BIND(C) :: i, j
BIND(C,NAME='binky') :: a
COMMON /common_block_name/ zztop
BIND(C) :: B, C, /common_block_name/
END PROGRAM
