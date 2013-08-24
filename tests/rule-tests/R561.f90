!! R561 implicit-spec
!    is declaration-type-spec ( letter-spec-list )

10 IMPLICIT integer(kind=4) (i)
Implicit TYPE(FooBar) (i)
implicit integer (i,j), real(k,l,m), TYPE(INTEGER)(s-w,z)
implicit real (a)

end
