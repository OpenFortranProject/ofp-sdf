!! R742 where-construct
!    is where-construct-stmt
!          [ where-body-construct ] ...
!       [ masked-elsewhere-stmt
!          [ where-body-construct ] ... ] ...
!       [ elsewhere-stmt
!          [ where-body-construct ] ... ]
!       end-where-stmt
!
!  R743 where-construct-stmt
!    is [where-construct-name :] WHERE ( mask-expr )
!
!  R744 where-body-construct
!    is where-assignment-stmt
!    or where-stmt
!    or where-construct
!
!  R745 where-assigment-stmt
!    is assignment-stmt
!
!  R746 masked-expression
!    is logical-expr
!
!  R747 masked-elsewhere-stmt
!    is ELSEWHERE (mask-expr ) [where-construct-name ]
!
!  R748 elsewhere-stmt
!    is ELSEWHERE [where-construct-name ]
!
!  R749 end-where-stmt
!    is END WHERE [where-construct-name ]
!

logical, dimension(10) :: IL1, ISay, HalfTrue
integer, dimension(10) :: IO1, IR5, ZEPS, ZERO

10 NoNoNo: WHERE (ISay)
  11 IO1 = IR5-IO1
  12 WHERE (IO1 < ZEPS) IO1 = ZERO
13 ELSE WHERE (HalfTrue) NoNoNo
  14 IO1 = IR5+IO1
15 ELSE WHERE NoNoNo
  16 IO1 = ZERO
17 END WHERE NoNoNo
WHERE (IL1)
END WHERE
END PROGRAM
