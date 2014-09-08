!! R563 namelist-stmt
!    is NAMELIST
!         / namelist-group-name / namelist-group-object-list
!         [ [ , ] / namelist-group-name / namelist-group-object-list ] ...

11 NAMELIST /Name1/ i,j, /Name2/k,l /Name3/m, /Name4/n,o,p
namelist /namelistname/ a,b,c

end
