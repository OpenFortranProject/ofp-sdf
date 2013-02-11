!! R532 data-stmt
!    is DATA data-stmt-set [ [ , ] data-stmt-set ] ...

character(9) :: name
integer      :: miles(10)

data i /13/  j /14/, k /15/
data ii/16/, jj/17/  kk/18/

10 DATA bandaid /3/
data name / 'Mary Beth' /, MILES/10*1/

end
