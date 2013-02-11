!! R641 dealloc-opt
!    is STAT = stat-variable
!    or ERRMSG = errmsg-variable

deallocate (this, stat=test)
deallocate (that, stat=test, errmsg=whatever)
end
