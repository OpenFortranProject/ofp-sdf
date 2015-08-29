!! R839 cycle-stmt
!      cycle-stmt  is  CYCLE [ do-construct-name ]

do i = 1, 10
20 CYCLE
end do 

my_do: do i = 1, 10
   cycle my_do
end do my_do

end

