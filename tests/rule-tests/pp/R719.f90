LOGICAL :: a, b, c
a = .TRUE.
a = .NOT. b
a = b .AND. c
a = a .AND. b .AND. c
a = .NOT. a .AND. b .AND. .NOT. c
END PROGRAM
