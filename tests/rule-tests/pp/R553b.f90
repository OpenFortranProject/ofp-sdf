COMMON /common_block_name/ aa
COMMON /blocka/ bb
10 SAVE :: i, j
SAVE :: k, /common_block_name/
SAVE :: A, B, C, /BLOCKA/, D
END PROGRAM
