!! R309 intrinsic-operator
!    is power-op     **
!    or mult-op       * | /
!    or add-op        + | -
!    or concat-op    //
!    or rel-op       .EQ. | .NE. | .LT. | ...
!    or not-op       .NOT.
!    or and-op       .AND.
!    or or-op        .OR.
!    or equiv-op

interface operator(**)
end interface operator(*)
interface operator(/)
end interface operator(+)
interface operator(-)
end interface operator(//)
interface operator(.eq.)
end interface operator(==)
interface operator(.ne.)
end interface operator(/=)
interface operator(.lt.)
end interface operator(<)
interface operator(.le.)
end interface operator(<=)
interface operator(.gt.)
end interface operator(>)
interface operator(.ge.)
end interface operator(>=)
interface operator(.NOT.)
end interface operator(.and.)
interface operator(.or.)
end interface operator(.OR.)
interface operator(.EQV.)
end interface operator(.neqv.)
end
