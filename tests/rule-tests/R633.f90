!! R630 allocate-shape-spec
!    is [ lower-bound-expr : ] upper-bound-expr

! parses as section-subscript, this means that there is no stride and if hasUpperBound
! is false, hasLowerBound must be true and is the upper-bound-expr

    allocate(x(3))    ! 3 must be converted to upper-bound-expr
    allocate(x(3:5))  ! 3 is lower-bound-expr and 5 is upper-bound-expr
end
