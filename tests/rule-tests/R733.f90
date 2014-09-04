!! R733 pointer-assignment-stmt
!    is data-pointer-object [ (bounds-spec-list) ] => data-target
!    or data-pointer-object (bounds-remapping-list ) => data-target
!    proc-pointer-object => proc-target

13 pointer_foo(3:4,7:8) => bar
   pointer => target
   pointer%pointer_name => target%target_name

end
