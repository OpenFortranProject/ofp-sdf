!! R529 bind-stmt

10  bind(c) i, j
    bind(C, name='binky') zztop

COMMON /common_block_name/ zztop
BIND(C) :: B, C, /common_block_name/

end
