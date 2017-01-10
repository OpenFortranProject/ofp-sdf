!! R305 literal-constant
!    is int-literal-constant
!    or real-literal-constant
!    or complex-literal-constant
!    or logical-literal-constant
!    or char-literal-constant
!    or boz-literal-constant

  complex :: c
  logical :: l
  character(5) :: str

  i = 13
  i = 13_4

  r = 3.1415
  r = 3.1415_8

  c = (-1.0_4, +2.0_4)

  l = .TRUE.
  l = .FALSE._4

  str = "hello"
  str = 1_"hello"

  z = Z"abcdef"
  o = O'01234567'
  b = B'0110'

end
