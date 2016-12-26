CHARACTER :: y
LOGICAL :: flag
10 SELECT CASE(n)
  11 CASE (1)
    x = 1
  CASE (2:3)
    x = 2
  CASE (5:8)
    x = 8
  CASE (10:12, 14:15, 22)
    x = 15
  CASE (33:)
    x = 33
  CASE DEFAULT
    x = 0
12 END SELECT
SELECT CASE(n)
  CASE (:3)
    i = 3
END SELECT
SELECT CASE('a')
  CASE ('a')
    y = 'a'
  CASE DEFAULT
    y = 'b'
END SELECT
SELECT CASE(x > 2)
  CASE (.TRUE.)
    flag = .TRUE.
  CASE DEFAULT
    flag = .FALSE.
END SELECT
my_case: SELECT CASE(x > 2)
  CASE (.TRUE.) my_case
    flag = .TRUE.
  CASE DEFAULT my_case
    flag = .FALSE.
END SELECT my_case
END PROGRAM
