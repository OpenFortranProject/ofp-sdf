!! R720 or-op
!    is  .OR.
logical :: a, b

a = .true. .OR. .false.
a = a .OR. b .OR. .NOT. .FALSE.

end
