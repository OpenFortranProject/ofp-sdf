!! R546 intent-stmt
!    is INTENT ( intent-spec ) [ :: ] dummy-arg-name-list

! intent-spec tested in R523

5 Subroutine Fibbed(a, b, c, d, e, f)

10 INTENT (IN) :: A, B, C
   intent (in out) :: d,e,f

15 End Subroutine Fibbed
