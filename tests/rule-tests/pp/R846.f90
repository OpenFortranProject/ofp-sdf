TYPE point
  REAL :: X, Y
END TYPE point
TYPE, EXTENDS(point) :: point_3d
  REAL :: Z
END TYPE point_3d
CLASS(POINT), POINTER :: p
10 SELECT TYPE (a => p)
  11 CLASS IS (point)
    x = 1
  12 TYPE IS (point_3d)
    x = 2
  13 CLASS DEFAULT
    x = 3
14 END SELECT
SELECT TYPE (p)
  CLASS IS (point)
    x = 1
  TYPE IS (point_3d)
    x = 2
  CLASS DEFAULT
    x = 3
END SELECT
my_select: SELECT TYPE (p)
  CLASS IS (point) my_select
    x = 1
  TYPE IS (point_3d) my_select
    x = 2
  CLASS DEFAULT my_select
    x = 3
END SELECT my_select
END PROGRAM
