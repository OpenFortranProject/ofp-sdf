!! R463 boz-literal-constant
!   is binary-constant
!   or octal-constant
!   or hex-constant

    INTEGER(KIND=16), PARAMETER :: ieee64_two = Z'4000000000000000'

    b = B"0110"
    b = b'100100'
    o = o'01234567'
    o = O"01234567"
    z = Z'0123456789' + z'abcdefABCDEF'
    z = z"0123456789" + Z"abcdefABCDEF"

end
