INCLUDE 'file.h'
PROGRAM test_include
INCLUDE 'file.h'
IMPLICIT NONE
INCLUDE 'file.h'
PRIVATE 
SAVE
x = 1
INCLUDE 'file.h'
BLOCK
  INCLUDE 'file.h'
  INTEGER :: i
  i = 1
  INCLUDE 'file.h'
END BLOCK
str = 'file.h'
END PROGRAM test_include
INCLUDE 'file.h'
