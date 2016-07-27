! Issue # 96: https://github.com/OpenFortranProject/open-fortran-parser/issues/96
!
! prefix-spec was not updated for F2008 syntax. For example
!
!
impure subroutine impure_proc
end subroutine

ELEMENTAL subroutine elemental_proc
end subroutine

MODULE subroutine module_proc
end subroutine

PURE subroutine pure_proc
end subroutine

RECURSIVE subroutine recursive_proc
end subroutine
