!! R552 save-stmt
!    is POINTER [ :: ] pointer-decl-list

!TODO - fix Ambiguity in common-stmt
!common /common_block_name/a

10 save :: i, j
save k, /common_block_name/

end
