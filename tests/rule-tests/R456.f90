!! R456 component-spec
!   is [ keyword = ] component-data-source

13 type person
   integer age
   character (LEN = 50) name
14 END TYPE person

type point                            ! A base type
  REAL :: X, Y
END TYPE POINT
TYPE, EXTENDS(POINT) :: COLOR_POINT   ! An extension of TYPE(POINT)
  ! Components X and Y, and component name POINT, inherited from parent
  INTEGER :: COLOR
END TYPE COLOR_POINT

type(person) p

!! NOTE 4.59
!
15 type(point) :: PV = POINT(1.0, 2.0)
type(color_point) :: cp1, cp2, cp3

cp1 = COLOR_POINT( point=point(1,2), color=3)
cp2 = COLOR_POINT( point=PV, color=3)
cp3 = COLOR_POINT(1 , 2, 3)

!! NOTE 4.60
!
16 p = PERSON (21, 'JOHN SMITH')
! This could also be written as
p = PERSON (NAME = 'JOHN SMITH', AGE = 21)

end
