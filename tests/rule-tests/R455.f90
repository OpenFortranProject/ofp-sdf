!! R455 structure-constructor
!    is derived-type-spec ( [ component-spec-list ] )

TYPE point
  INTEGER :: i, j
END TYPE

TYPE(POINT) :: PV = POINT(1.0, 2.0)

end
