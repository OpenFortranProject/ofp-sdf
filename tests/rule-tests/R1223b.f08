!! R1223 actual-arg
!   - F2008 addition
!   - actual argument with TARGET atribute can correspond to a dummy pointer

program target_as_actual
  INTERFACE
     SUBROUTINE SUB(X)
       REAL, pointer :: X
     END SUBROUTINE SUB
  END INTERFACE

  REAL, target  :: A

  CALL SUB(A)

end program
