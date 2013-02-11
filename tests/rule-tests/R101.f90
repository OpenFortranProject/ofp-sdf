!! R101 xyz-list (generic-name-list)
!
!    xyz-list  is xyz [ , xyz ] ...
!    xyz-name  is name
!

! Check for generic name list. Using parameterized derived type.
type :: coolguy (k1, k2)
	integer, KIND :: k1, k2
end TYPE coolguy

end
