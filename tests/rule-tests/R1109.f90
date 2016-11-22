! Test use-stmt
!      use-stmt  is  USE [ [, module-nature ] :: ] module-name [, rename-list ]
!                or  USE [ [, module-nature ] :: ] module-name, 
!                      ONLY : [ only-list ]
!
!      module-nature  is  INTRINSIC
!                     or  NON_INTRINSIC
!
!      rename  is  local-name => use-name
!              or  OPERATOR(local-defined-operator) =>
!                    OPERATOR(use-defined-operator)
!
!      only  is  generic-spec
!            or  only-use-name
!            or  rename
!
!      only-use-name  is  use-name
!
!      local-defined-operator  is  defined-unary-op
!                              or  defined-binary-op
!
!      use-defined-operator  is  defined-unary-op
!                            or  defined-binary-op
!
! Not tested here: generic-spec, only-use-name, local-name, use-name,  
! defined-binary-op, and defined-unary-op.
!
!! modules for subsequent tests
!
MODULE A
  INTEGER :: b, c
  type :: aReal
    real :: zzz
  end type
  interface operator (.yourop.)
    integer function add_op(a,b)
      integer, intent(in) :: a, b
    end function
  end interface operator (.yourop.)
  interface operator (.yourotherop.)
    integer function neg_op(a)
      integer, intent(in) :: a
    end function
  end interface operator (.yourotherop.)
END MODULE
MODULE AA
  INTEGER :: b, c
END MODULE
MODULE AAA
  INTEGER :: m, n
END MODULE

! Test with none of the optional parts
USE a

! Include optional module nature
use, intrinsic :: iso_c_binding
use, non_intrinsic :: A

! Include optional rename-list
USE aa, d=>b, e=>c
use a, operator(.myop.)=>operator(.yourop.), integer => aReal, &
       b => c, operator(.myotherop.) =>operator(.yourotherop.)

! Include optional only clause
USE aaa, ONLY: m, f=>n

END
