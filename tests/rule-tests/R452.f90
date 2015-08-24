!! R452 final-procedure-stmt
!    is FINAL [ :: ] final-subroutine-name-list

9 module myjunk

type point
contains
13 FINAL foo, bar
   final :: binky
end type

contains

SUBROUTINE foo(arg)
TYPE(point) :: arg(1)
END SUBROUTINE

SUBROUTINE bar(arg)
TYPE(point) :: arg(1,1)
END SUBROUTINE

SUBROUTINE binky(arg)
TYPE(point) :: arg
END SUBROUTINE

15 end module
