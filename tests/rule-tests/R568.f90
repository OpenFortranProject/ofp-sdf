!! R568 common-stmt
!    is COMMON [       / [ common-block-name ] / ] common-block-object-list
!              [ [ , ] / [ common-block-name ] /   common-block-object-list ] ...
common i
common /name1/ i1, i2
10 COMMON   // i2
common i3 / / j
common /name1/ i4, /name2/ j1 /name3/ k, // l
end
