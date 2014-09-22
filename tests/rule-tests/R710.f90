!! R710 level-3-expr
!    is [ level-3-expr concat-op ] level-2-expr
!
!  level-3-expr is a concat-op

character :: a(12)

a = 'AB' // 'BC'
a = 'Hell' // 'o' // ' world!'
end
