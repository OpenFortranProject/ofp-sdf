TYPE T
  INTEGER :: b
END TYPE
INTEGER :: a(2)
TYPE(T) :: c
a = 1
a(1) = 1
a(1:2) = 1
c%b = 1
END PROGRAM
