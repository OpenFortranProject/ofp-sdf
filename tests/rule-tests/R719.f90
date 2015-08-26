!! R719 and-op
!    is .AND.

logical :: a, b, c

a = .true.
a = .TRUE._4
b = .FALSE.
b = .false._1
a = .not. b
a = b .and. c
a = a.and.b.and.c
a = .not.a .and. b.and..not.c

end
