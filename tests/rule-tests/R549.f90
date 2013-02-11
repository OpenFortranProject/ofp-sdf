!! R549 pointer-stmt
!    is POINTER [ :: ] pointer-decl-list
!
!  pointer-decl-list
!    is object-name [ ( deferred-shape-spec-list ) ]
!    or proc-entity-name

pointer :: this, that, theother
10 POINTER A(:,:)

end
