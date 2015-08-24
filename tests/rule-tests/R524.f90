!! R524 access-stmt
!    is access-spec [ [ :: ] access-id-list ]

module ex
10  private
    PUBLIC boo, assignment(=)
    public :: binky, bonky, operator (+)

INTERFACE ASSIGNMENT ( = )
   SUBROUTINE LOGICAL_TO_NUMERIC (N, B)
      INTEGER, INTENT (OUT) :: N
      LOGICAL, INTENT (IN)  :: B
   END SUBROUTINE LOGICAL_TO_NUMERIC
END INTERFACE ASSIGNMENT ( = )

INTERFACE OPERATOR ( + )
   LOGICAL FUNCTION LOGICAL_ADD (N, B)
      LOGICAL, INTENT (IN) :: N
      LOGICAL, INTENT (IN)  :: B
   END FUNCTION LOGICAL_ADD
END INTERFACE OPERATOR ( + )

end module ex
