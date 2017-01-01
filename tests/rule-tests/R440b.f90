module points
TYPE POINT
  REAL :: X, Y

CONTAINS
procedure, PASS :: LENGTH => POINT_LENGTH
END TYPE POINT

type, extends (point) :: POINT_3D
  REAL :: Z
CONTAINS
procedure, PASS :: LENGTH => POINT_3D_LENGTH
END type   POINT_3D

contains

REAL FUNCTION POINT_LENGTH( A, B )
CLASS(POINT), INTENT(IN) :: A, B
POINT_LENGTH = SQRT((A%X - B%X)**2 + (A%Y - B%Y)**2)
END FUNCTION POINT_LENGTH
REAL FUNCTION POINT_3D_LENGTH(A, B)
CLASS (POINT_3D), INTENT (IN) :: A
class(point), intent (in) :: B
SELECT TYPE (B)
  CLASS is (POINT_3D)
END select
END FUNCTION point_3d_length
END module points
