13 TYPE person
  INTEGER :: age
  CHARACTER(50) :: name
14 END TYPE person
TYPE point
  REAL :: X, Y
END TYPE point
TYPE, EXTENDS(point) :: COLOR_POINT
  INTEGER :: color
END TYPE COLOR_POINT
TYPE(person) :: p
15 TYPE(point) :: PV = POINT(1.0,2.0)
TYPE(color_point) :: cp1, cp2, cp3
cp1 = COLOR_POINT(point=point(1,2),color=3)
cp2 = COLOR_POINT(point=PV,color=3)
cp3 = COLOR_POINT(1,2,3)
16 p = PERSON(21,'JOHN SMITH')
p = PERSON(NAME='JOHN SMITH',AGE=21)
END PROGRAM
