!! R1237 separate-module-subprogram
!     is mp-subprogram-stmt
!           [ specification-part ]
!           [ execution-part ]
!           [ internal-subprogram-part ]
!        end-mp-subprogram-stmt
!
module mod
contains
   MODULE PROCEDURE modproc
      integer :: i
      i = 3
   ENDPROCEDURE modproc
end module mod

