!! R432 type-param-decl
!    is type-param-name [ = scalar-int-initialization-expr ]

TYPE big_deal(k, d, l)
   INTEGER, KIND :: k = kind(0.0), d = 13
   INTEGER (KIND=4), LEN :: l = 13
end type

end
