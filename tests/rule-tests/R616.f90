!! R615 type-param-inquiry
!    is designator % type-param-name
!
!  NOTE 6.8

z = a%kind
z = s%len
z = b(10)%kind
z = p%dim

a%kind = z
s%len = z
b(10)%kind = z
p%dim = z

end
