!! R1240 entry-stmt
!      is ENTRY entry-name [ ( [ dummy-arg-list ] ) [ suffix ] ]

function E_STMT(x)
11 ENTRY binky
   ENTRY bonky (a, b, c)
   ENTRY pop(y) RESULT(z)
END FUNCTION
