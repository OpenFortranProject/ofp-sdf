INTEGER :: a
named_block : BLOCK
  INTEGER :: b
  b = 3
END BLOCK named_block
BLOCK
  a = 13
END BLOCK
END PROGRAM
