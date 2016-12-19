!! R440 proc-component-def-stmt
!    is PROCEDURE ( [ proc-interface ] ) ,
!            proc-component-attr-spec-list :: proc-decl-list
!                                                                                         
module whut

  type point
     integer :: x,y
  end type point

  type, extends(point) :: feeble
     procedure (), pointer, nopass :: foible
     procedure (bob), pass(a), private, pointer :: foo => bar
     procedure (bob), pass, public, pointer :: foo => bar
end type

interface
   function bob(a)
     import feeble
     type(feeble) :: a
   end function bob
end interface

contains

  function boo(a)
    type(point) :: a
  end function boo

end module whut
