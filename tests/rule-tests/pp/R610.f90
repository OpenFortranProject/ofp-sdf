CHARACTER(3) :: a, b(3)
a = b(3)(:)
a = b(3)(1:)
a = b(3)(:2)
a = b(3)(1:2)
END PROGRAM
