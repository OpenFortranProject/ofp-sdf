      program int_expr
         implicit none
         integer zero, one, two, a, b, c, d

         zero = 0
         one  = 1
         two  = 2

         if (zero .ne. 0 .or. one .ne. 1 .or. two .ne. 2) goto 99

         zero = zero**zero + (-one/one)
         if (zero .ne. 0) goto 99

         one = +one*one + 0 + zero*one + one - 1
         if (one .ne. 1) goto 99

         one = one**one + one**two/4
         if (one .ne. 1) goto 99

         two = two**two/two+zero+two**zero-one
         if (two .ne. 2) goto 99

         a = one*(one - 2)
         if (a .ne. -1) goto 99

         b = -a
         if (b .ne. 1) goto 99

         c = 13*a/4
         d = 13*b/4
         if (c .ne. -3 .or. d .ne. 3) goto 99

         c = +1.01*one
         d = +1.99*one

         if (c .ne. 1 .or. d .ne. 1) goto 99

         c = -1.01*two
         d = -1.99*two

         if (c .ne. -2 .or. d .ne. -3) goto 99

C These tests passes
         goto 100

C These tests failed
99       stop 1

100   end program
