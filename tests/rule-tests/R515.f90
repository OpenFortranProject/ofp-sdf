!! R515 array-spec
!    is explicit-shape-spec-list
!    or assumed-shape-spec-list
!    or deferred-shape-spec-list
!    or assumed-size-spec
!    or implied-shape-spec -list

real x(314159)
integer y(31,41,59,2:6,5)
integer bar(2:6,5:*)
3 Real truth(31,41,*)
integer beauty(31:,41:)
integer ugly(:,:)

end
