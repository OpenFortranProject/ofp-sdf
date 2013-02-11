!! R471 ac-value
!    is expr
!    or ac-implied-do

! Test of expr in ac_value_list
x = [ REAL :: 3.1, 4.1, 5.9265 ]

! Test of ac-implied-do
A = (/ (I, I = 1, 1075) /)
B = [ TYPE(Z) :: 3.6, (3.6 / I, I = 1, N, 2) ]

end
