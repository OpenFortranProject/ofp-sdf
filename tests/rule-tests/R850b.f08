!! R850 exit-stmt
!   - F2008 addition
!   - EXIT can transfer control from more named executable constructs

loop_outer : do i = 1, 3
loop_inner : do ii = 1, 3
   exit loop_outer
end do loop_inner
end do loop_outer

loop_while : do while (.TRUE.)
   exit loop_while
end do loop_while

if_construct : if (.TRUE.) then
   exit if_construct
end if if_construct

END
