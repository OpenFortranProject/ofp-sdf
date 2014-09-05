!! R557 target-decl
!    is object-name [ ( array-spec ) ]
!       [ lbracket coarray-spec rbracket ]
!
13  TARGET :: A (1000, 1000)[1000,*], B
   target A[*]
   target    B(10)[:]

end
