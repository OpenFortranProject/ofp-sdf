!! R755 forall-triplet-spec
!    is index-name = subscript : subscript [ : stride]

forall (ii = 1:10, jj = 1:10, kk=4:8)
end forall
forall (ii = 1:nn)
end forall
forall (ii = 1:nn:5)
end forall
forall (ii = 1:30:N, jj=K:5:3)
end forall

end
