!! R546 optional-stmt
!    is OPTIONAL [ :: ] dummy-arg-name-list

subroutine foo(A, b, C, d)
10 OPTIONAL a, B
   optional :: c, D
end subroutine
