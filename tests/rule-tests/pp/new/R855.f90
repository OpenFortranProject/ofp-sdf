!! R855 stop-stmt
!    is  STOP [ stop-code ]
!  
!      stop-code  is  scalar-char-constant
!                 or  digit [ digit [ digit [ digit [ digit ] ] ] ] 
!
! Not tested here: scalar-char-constant

integer, parameter :: stop_code = 999
character, parameter :: char_stop = "stop please"

stop
13 stop 'end of program'
stop 1
stop stop_code
stop 123
stop 1234
stop char_stop

end
