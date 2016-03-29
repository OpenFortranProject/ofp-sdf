      subroutine ppb101(uxavl_1,uxavl_3,uxavlmod_1,uxavlmod_3,&
     &                  fv_1,fvx_1,fvxx_1,fvyy_1,fvyz_1,fvzz_1,&
     &                  fv_2,fvx_2,fvxx_2,&
     &&
     &                  dmom0l_1,dmom1l_1,dmom2l_1,&
     &                  dmomy20l_1,dmomyz0l_1,dmomz20l_1,&
     &&
     &                  fvnu_1,fvxnu_1,fvxxnu_1,fvyynu_1,&
     &                  fvyznu_1,fvzznu_1,fvavl_2,&
     &                  sigmal_2,dchil1_2,d1_2,d2_2,&
     &                  fupstrml_2,dchi0rel_1,f_1,&
     &&
     &                 fv001,dt,dx,courmx,iffirstcall,&
     &             ifdebug,time,myrank,mythread,mbrick,&
     &             icube,jbq,kbq,ipass,&
     &             MyBrickX,MyBrickY,MyBrickZ,&
     &             NXBricks,NYBricks,NZBricks,&
     &             dbgfile,iu6)
!
!!DIR$ ATTRIBUTES FORCEINLINE :: ppb101
!
!     Glob 1:     rho,      p,     fv,     ux
!     Glob 2:      uy,     uz, difuse,   fvyz
!     Glob 3:     fvx,   fvxx,   fvyy,   fvzz 
!     Glob 4:     fvy,   fvxy,    fvz,   fvxz
! 
!     ppb101 cannot be called until glob 3 has arrived.
!     ppb102 cannot be called until glob 4 has arrived.
!
!
!
!                    **************************************************
!                    **************************************************
!                    **************************************************
!                    **************************************************
!                    *****                                        *****
!                    *****       THIS CODE WAS WRITTEN BY         *****
!                    *****                                        *****
!                    *****            PAUL R. WOODWARD            *****
!                    *****                                        *****
!                    *****               May, 1992                *****
!                    *****          Through  summer, 2013         *****
!                    *****       Spruced up  winter, 2013-14      *****
!                    *****                                        *****
!                    *****     All reservable rights reserved     *****
!                    *****                                        *****
!                    **************************************************
!                    **************************************************
!                    **************************************************
!                    **************************************************
!
!
!
!
      parameter (nsugar=4)
      parameter (nsugarsq=nsugar*nsugar)
      parameter (nssqhf=nsugarsq)
      parameter (nssq=nsugarsq*2)
!
!
!
!     Input arrays for PPB101:
!        uxavl_1,uxavl_3,uxavlmod_1,uxavlmod_3,
!        fv_1,fvx_1,fvxx_1,fv_2,fvx_2,fvxx_2,
!        fvyy_1,fvyz_1,fvzz_1,dmom0l_1,dmom1l_1,dmom2l_1,
!        dmomy20l_1,dmomyz0l_1,dmomz20l_1
!
!     Output arrays from PPB101:
!        fvnu_1,fvxnu_1,fvxxnu_1,fvyynu_1,fvyznu_1,fvzznu_1,
!        fvavl_2,sigmal_2,dchil1_2,d1_2,d2_2,
!        fupstrml_2,dchi0rel_1,f_1
!
!      In preparation for next call to this routine:
!        dmom0l_1,dmom1l_1,dmom2;_1,dmomy20l_1,dmomyz0l_1,
!        dmomz20l_1
!
!     Scratch arrays for PPB101:
!        uxavl_2,uxavlmod_2,fvyy_2,fvyz_2,fvzz_2,
!        dchil_1,dchil_2,dchilrel_1,dchilrel_2,sl_1,sl_2,
!        dmom0l_2,dmom1l_2,dmom2l_2,dmomy20l_2,dmomyz0l_2,
!        dmomz2l_2,fvupstrml_2,fvxupstrml_2,fvxxupstrml_2,
!        fvyyupstrml_2,fvzzupstrml_2
!
!     Declare implicit postfix for gp5 suffix
!
      implicit postfix real, dimension(nssq) ("_1")
      implicit postfix real, dimension(nssq) ("_2")
      implicit postfix real, dimension(nssq) ("_3")
!
      character*14   dbgfile
!
!
!
!
!
!      if (myhfcube .ge. 4)   then
!
!
!     6/29/11:
!     Note that for our formulae to be correct in the case of a moving
!     grid,  dtbyx  must refer to the value of  dx  at the beginning of
!     the time step.
!     See the document:  PPB10-and-PPM-formulae-4-23-06-and-4-6-11.docx
!
!PPM$ LONGITUDINAL LOOP
      do jk = 1, nssq
      dchil_2 = uxavl_2 * dtbydx
      dchilrel_2 = uxavlmod_2 * dtbydx
      uxavlfarzr_ = uxavl_1
      if (uxavlmod_2 .lt. 0.)   uxavlfarzr_ = uxavl_3
      dchilfarzr = uxavlfarzr_ * dtbydx
      uxavlrelfarzr_ = uxavlmod_1
      if (uxavlmod_2 .lt. 0.)   uxavlrelfarzr_ = uxavlmod_3
      dchilrelfarzr = uxavlrelfarzr_ * dtbydx
      dchi0upstrmlzr = .5 * (dchilrel_2 + dchilrelfarzr)
      sl_2 = 1.
      if (uxavlmod_2 .lt. 0.)   sl_2 = -1.
      ddchirelupstrmlzr = sl_2 * (dchilrel_2 - dchilrelfarzr)
      ddchiupstrmlzr = sl_2 * (dchil_2 - dchilfarzr)
      fupstrml_2 = 1.  +  .5 * ddchiupstrmlzr
      deenom = fupstrml_2 - ddchirelupstrmlzr
      deenom = max (deenom, small)
      thyng = 1. / deenom
      fupstrml_2 = fupstrml_2 * thyng
      dchi0upstrmlzr = dchi0upstrmlzr * thyng
      uxrelr = uxavlmod_2
      enddo
#if isnodivby0
      do jk = 1,nssq
      if (fupstrml_2(jk) .eq. 0.)   then
      write (6,*) 'About to divide by 0. in PPB101.  Myrank =',myrank
      write (6,*) 'jk,i, fupstrml_2 =',jk,i, fupstrml_2(jk)
      write (6,*) 'deenom, thyng, small =',deenom,thyng,small
      endif
      enddo
#endif
      do jk = 1,nssq
      xir = (sl_2 * .5  -  dchi0upstrmlzr) / fupstrml_2
      sxir = sl_2 * xir
      sigmal_2 = .5 - sxir
      d1_2 = .25  +  .5 * sxir
      d2_2 = twelth  +  twothd * sxir * d1_2
      d3zr = .03125  +  .75 * sxir * d2_2
      d4zr = .0125  +  .8 * sxir * d3zr
      enddo
!
!     nrecips = nrecips + (nsugar+3)*2
!     ncvmgms = ncvmgms + (nsugar+3)*4
!     nmults = nmults + (nsugar+3)*20
!     nadds = nadds + (nsugar+3)*12
!
      do jk = 1,nssq
      fvupstrml_2 = fv_1
      if (uxrelr .lt. 0.)   fvupstrml_2 = fv_2
      fvxupstrml_2 = fvx_1
      if (uxrelr .lt. 0.)   fvxupstrml_2 = fvx_2
      fvxxupstrml_2 = fvxx_1
      if (uxrelr .lt. 0.)   fvxxupstrml_2 = fvxx_2
      fv1upstrmlzr = 12. * fvxupstrml_2
      fv2upstrmlzr = 15. * (12. * fvxxupstrml_2  -  fvupstrml_2)
      fv0upstrmlzr = fvupstrml_2  -  twelth * fv2upstrmlzr
      fvavl_2 = fv0upstrmlzr  +  sl_2 * d1_2 * fv1upstrmlzr&
     &                         +  d2_2 * fv2upstrmlzr
!
      dmm0r = sigmal_2 * fvavl_2
      dmm1r = sigmal_2 * (sl_2 * d1_2 * fv0upstrmlzr&
     &      +  d2_2 * fv1upstrmlzr  +  sl_2 * d3zr * fv2upstrmlzr)
      dmm2r = sigmal_2 * (d2_2 * fv0upstrmlzr&
     &      +  sl_2 * d3zr * fv1upstrmlzr  +  d4zr * fv2upstrmlzr)
      dmom0l_2 = fupstrml_2 * dmm0r
      fsqupstrmlzr = fupstrml_2 * fupstrml_2
      dchil1_2 = dchi0upstrmlzr - sl_2
      dmom1l_2 = fsqupstrmlzr * dmm1r  +  dchil1_2 * dmom0l_2
      dmom2l_2 = fupstrml_2 * fsqupstrmlzr * dmm2r&
     &          +  dchil1_2 * (fsqupstrmlzr * dmm1r  +  dmom1l_2)
      enddo
!
!     nrecips = nrecips + (nsugar+3)*(2+0)
!     ncvmgms = ncvmgms + (nsugar+3)*(4+3)
!     nmults = nmults + (nsugar+3)*(20+24)
!     nadds = nadds + (nsugar+3)*(12+12)
!
!
!      loopsPPB102 = loopsPPB102 + 1
!      ninloop = nssq*(mynx+2*nbdy-7)*loopsPPB102
!      oop = ninloop
!      recips = recips + oop*2.
!      cvmgms = cvmgms + oop*7.
!      amults = amults + oop*44.
!      adds = adds + oop*24.
!
!
!
      if (iffirstcall .eq. 0)   then
!
!
!     It is only necessary to save one set of dual-grid-plane arrays of
!     moments around the cycle, not two.  Therefore, we make the arrays
!     dmom0r, dmom1r, and dmom2r have just one element each, and we
!     save dmom0l, dmom1l, dmom2l around the cycle and only these.
!     Below, we introduce into these saved arrays form the last call to
!     this routine the halves that have just been constructed above.
!     Before leaving this routine, we will insert into the bottom halves
!     of these arrays the top halves of dmom0r, dmom1r, and dmom2r for
!     use on the next round.
!
!PPM$ LONGITUDINAL LOOP
!DEC$ VECTOR ALWAYS
!DEC$ VECTOR ALIGNED
      do   jk = 1,nssqhf
      dmom0l_1(jk+nssqhf) = dmom0l_2(jk)
      dmom1l_1(jk+nssqhf) = dmom1l_2(jk)
      dmom2l_1(jk+nssqhf) = dmom2l_2(jk)
      enddo
!
!
!
!
!
!     6/29/11:
!     Note that for our formulae to be correct in the case of a moving
!     grid,  dtbyx  must refer to the value of  dx  at the beginning of
!     the time step.
!     See the document:  PPB10-and-PPM-formulae-4-23-06-and-4-6-11.docx
!
!PPM$ LONGITUDINAL LOOP
      do jk = 1,nssq
        dchil_1 = uxavl_1 * dtbydx
        dchilrel_1 = uxavlmod_1 * dtbydx
!        dchi0_ = 0.5 * (dchil_1 + dchil_2)
        dchi0rel_1 = 0.5 * (dchilrel_1 + dchilrel_2)
        ddchirel = dchilrel_2 - dchilrel_1
        ddchi = dchil_2 - dchil_1
        f_1 = 1.  +  (.5 * ddchi)
        deenom = f_1 - ddchirel
        deenom = max (deenom, small)
        thyng = 1. / deenom
        f_1 = f_1 * thyng
        dchi0rel_1 = dchi0rel_1 * thyng
        fsq = f_1 * f_1
        totmom0nu = f_1 * fv_1
        totmom1nu = fsq * fvx_1  + dchi0rel_1 * totmom0nu
        totmom2nu = f_1 * fsq * fvxx_1&
     &            +  dchi0rel_1 * (fsq * fvx_1  +  totmom1nu)
        sl_1 = 1.
        if (uxavlmod_1 .lt. 0.)   sl_1 = -1.
        fvnu_1 = totmom0nu + sl_1 * dmom0l_1
        fvxnu_1 = totmom1nu  +  sl_1 * dmom1l_1
        fvxxnu_1 = totmom2nu  +  sl_1 * dmom2l_1
!
!     nrecips = nrecips + (nsugar+2)*1
!     ncvmgms = ncvmgms + (nsugar+2)*1
!     nmults = nmults + (nsugar+2)*15
!     nadds = nadds + (nsugar+2)*12
!
!       if (uxavl_1 .lt. 0.)   then
!         fvxnu_1 = fvxnu_1 + dmom0l_1
!         fvxxnu_1 = fvxxnu_1
!      &               +  2. * dmom1l_1  -  dmom0l_1
!       endif
        uxrell = uxavlmod_1
        if (uxrell .lt. 0.)   fvxnu_1 = fvxnu_1 + dmom0l_1
        thyng = 2. * dmom1l_1  -  dmom0l_1
        if (uxrell .lt. 0.)   fvxxnu_1 = fvxxnu_1 + thyng
        fvnu_1 = fvnu_1  -  sl_2 * dmom0l_2
        if (fvnu_1 .lt. smallerfv)   fvnu_1 = 0.
        fvxnu_1 = fvxnu_1  -  sl_2 * dmom1l_2
        fvxxnu_1 = fvxxnu_1  -  sl_2 * dmom2l_2
!       if (uxavl_2 .gt. 0.)   then
!         fvxnu_1 = fvxnu_1 - dmom0l_2
!         fvxxnu_1 = fvxxnu_1
!     &                -  2. * dmom1l_2  -  dmom0l_2
!       endif
        uxrell = uxavlmod_2
        if (uxrell .gt. 0.)  fvxnu_1 = fvxnu_1 - dmom0l_2
        thyng = 2. * dmom1l_2  +  dmom0l_2
        if (uxrell .gt. 0.)   fvxxnu_1 = fvxxnu_1 - thyng
        thngy_ = 1.
        if (fvxnu_1 .lt. 0.)   thngy_ = -1.
        fvxnu_1 = thngy_ * fvxnu_1
        if (fvxnu_1 .lt. dsmallerfv)  fvxnu_1 = 0.
        fvxnu_1 = thngy_ * fvxnu_1
        thngy_ = 1.
        if (fvxxnu_1 .lt. 0.)   thngy_ = -1.
        fvxxnu_1 = thngy_ * fvxxnu_1
        if (fvxxnu_1 .lt. d2smallerfv)   fvxxnu_1 = 0.
        fvxxnu_1 = thngy_ * fvxxnu_1
       enddo
!
!     nrecips = nrecips + (nsugar+2)*(1+0)
!     ncvmgms = ncvmgms + (nsugar+2)*(1+9)
!     nmults = nmults + (nsugar+2)*(15+9)
!     nadds = nadds + (nsugar+2)*(12+12)
!
!     5/7/03:
!     The setting of the various results to zero in the loop above
!     avoids making the processor waste incredible amounts of time
!     "properly" handling "underflows" according to the IEEE standard.
!     If we don't do this, the entire routine runs slower by about
!     a factor of 6.  This is a scandal.  It greatly increases the
!     computational labor for an absolutely stupid reason.
!
!
!     ninloop = nssq*(mynx+2*nbdy-8) * loopsPPB103
!     nrecips = nrecips + ninloop*(1)
!     ncvmgms = ncvmgms + ninloop*(10)
!     nmults = nmults + ninloop*(24)
!     nadds = nadds + ninloop*(24)
!
!
      endif
!
!
!
!
!
!     It is only necessary to save one set of dual-grid-plane arrays of
!     moments around the cycle, not two.  Therefore, we make the arrays
!     dmom0r, dmom1r, and dmom2r have just one element each, and we
!     save dmom0l, dmom1l, dmom2l around the cycle and only these.
!     Before leaving this routine, we insert into the bottom halves
!     of these arrays the top halves of dmom0r, dmom1r, and dmom2r for
!     use on the next round.
!
!
!PPM$ LONGITUDINAL LOOP
!DEC$ VECTOR ALWAYS
!DEC$ VECTOR ALIGNED
      do   jk = 1,nssqhf
      dmom0l_1(jk) = dmom0l_2(jk+nssqhf)
      dmom1l_1(jk) = dmom1l_2(jk+nssqhf)
      dmom2l_1(jk) = dmom2l_2(jk+nssqhf)
      enddo
!
!
!
!
!PPM$ LONGITUDINAL LOOP
      do jk = 1,nssq
        thyng = (fv_2 - small) * (almost1 - fv_2)
        if ((fv_2 - small) .lt. 0.)   fvyy_2 = 0.
        if ((almost1 - fv_2) .lt. 0.)   fvyy_2 = twelth
!
        thyng = (fv_1 - small) * (almost1 - fv_1)
        if ((fv_1 - small) .lt. 0.)   fvyy_1 = 0.
        if ((almost1 - fv_1) .lt. 0.)   fvyy_1 = twelth
!
!
!
!
        fvyyupstrml_2 = fvyy_1
        if (uxavrmod(jk,0) .lt. 0.) fvyyupstrml_2 = fvyy_2
!       fvyy1upstrmlzr = fvxupstrml_2
        fvyy2upstrmlzr = 15. * (fvx2upstrml_2&
     &               -  twelth * fvupstrml_2)
        fvyy0upstrmlzr = fvyyupstrml_2  -  twelth * fvyy2upstrmlzr
        thngy_ = sigmal_2 * (fvyy0upstrmlzr&
     &          +  sl_2 * d1_2 * fvxupstrml_2&
     &          +  d2_2 * fvyy2upstrmlzr)
        dmomy20l_2 = fupstrml_2 * thngy_
       enddo
!
!      loopsPPB102 = loopsPPB102 + 1
!      ninloop = nssq*(mynx+2*nbdy-7)*loopsPPB102
!      oop = ninloop
!      recips = recips + oop*(2.+0.)
!      cvmgms = cvmgms + oop*(7.+1.)
!      amults = amults + oop*(44.+8.)
!      adds = adds + oop*(24.+4.)
!
!
!
!
      if (iffirstcall .eq. 0)   then
!
!PPM$ LONGITUDINAL LOOP
!DEC$ VECTOR ALWAYS
!DEC$ VECTOR ALIGNED
      do   jk = 1,nssqhf
      dmomy20l_1(jk+nssqhf) = dmomy20l_2(jk)
      enddo
!
!PPM$ LONGITUDINAL LOOP
      do jk = 1, nssq
        fvyynu_1 = f_1 * fvyy_1  +  sl_1 * dmomy20l_1&
     &                              -  sl_2 * dmomy20l_2
        thngy(jk) = 1.
        if (fvyynu_1 .lt. 0.)   thngy(jk) = -1.
        fvyynu_1 = thngy(jk) * fvyynu_1
        if (fvyynu_1 .lt. d2smallerfv)   fvyynu_1 = 0.
        fvyynu_1 = thngy(jk) * fvyynu_1
      enddo
!
!     ninloop = nssq*(mynx+2*nbdy-8) * loopsPPB103
!     nrecips = nrecips + ninloop*(1+0)
!     ncvmgms = ncvmgms + ninloop*(10+2)
!     nmults = nmults + ninloop*(24+5)
!     nadds = nadds + ninloop*(24+3)
!
      endif
!
!
!
!
!
!PPM$ LONGITUDINAL LOOP
!DEC$ VECTOR ALWAYS
!DEC$ VECTOR ALIGNED
      do   jk = 1,nssqhf
      dmomy20l_1(jk) = dmomy20l_2(jk+nssqhf)
      enddo
!
!
!
!
!PPM$ LONGITUDINAL LOOP
      do jk = 1, nssq
        thyng = (fv_2 - small) * (almost1 - fv_2)
        if (thyng .lt. 0.)   fvyz_2 = 0.
        if ((fv_2 - small) .lt. 0.)   fvzz_2 = 0.
        if ((almost1 - fv_2) .lt. 0.)   fvzz_2 = twelth
!
        thyng = (fv_1 - small) * (almost1 - fv_1)
        if (thyng .lt. 0.)   fvyz_1 = 0.
        if ((fv_1 - small) .lt. 0.)   fvzz_1 = 0.
        if ((almost1 - fv_1) .lt. 0.)   fvzz_1 = twelth
!
!
!
        uxrelr = uxavlmod_2
        fvzzupstrml_2 = fvzz_1
        if (uxrelr .lt. 0.) fvzzupstrml_2 = fvzz_2
!       fvzz1upstrmlzr = fvxupstrml_2
        fvzz2upstrmlzr = 15. * (fvxxupstrml_2 - twelth * fvupstrml_2)
        fvzz0upstrmlzr = fvzzupstrml_2  -  twelth * fvzz2upstrmlzr
        thngy_ = fvzz0upstrmlzr  +  sl_2 * d1_2 * fvxupstrml_2&
     &                            +  d2_2 * fvzz2upstrmlzr
        dmomz20l_2 = fupstrml_2 * sigmal_2 * thngy_
!
        thngy_ = fvyz_1
        if (uxrelr .lt. 0.)   thngy_ = fvyz_2
!       fvyz1upstrmlzr = 0.
!       fvyz2upstrmlzr = 15. * (fvyzupstrml_2
!     &                      - fvyzupstrml_2) = 0.
!       fvyz0upstrmlzr = fvyzupstrml_2
        dmomyz0l_2 = fupstrml_2 * sigmal_2 * thngy_
      enddo
!
!      loopsPPB102 = loopsPPB102 + 1
!      ninloop = nssq*(mynx+2*nbdy-7)*loopsPPB102
!      oop = ninloop
!      recips = recips + oop*(2.+0.+0.)
!      cvmgms = cvmgms + oop*(7.+1.+2.)
!      amults = amults + oop*(44.+8.+9.)
!      adds = adds + oop*(24.+4.+4.)
!
!
!
!
!
      if (iffirstcall .eq. 0)   then
!
!
!PPM$ LONGITUDINAL LOOP
!DEC$ VECTOR ALWAYS
!DEC$ VECTOR ALIGNED
      do   jk = 1,nssqhf
      dmomz20l_1(jk+nssqhf) = dmomz20l_2(jk)
      dmomyz0l_1(jk+nssqhf) = dmomyz0l_2(jk)
      enddo
!
!
!PPM$ LONGITUDINAL LOOP
      do jk = 1, nssq
        fvyznu_1 = f_1 * fvyz_1  +  sl_1 * dmomyz0l_1&
     &                              -  sl_2 * dmomyz0l_2
        thngy_ = 1.
        if (fvyznu_1 .lt. 0.)   thngy_ = -1.
        fvyznu_1 = thngy_ * fvyznu_1
        if (fvyznu_1 .lt. d2smallerfv)   fvyznu_1 = 0.
        fvyznu_1 = thngy_ * fvyznu_1
!
!       totmom0nu = f_1 * fvzz_1
        fvzznu_1 = f_1 * fvzz_1  +  sl_1 * dmomz20l_1&
     &                              -  sl_2 * dmomz20l_2
        thngy_ = 1.
        if (fvzznu_1 .lt. 0.)   thngy_ = -1.
        fvzznu_1 = thngy_ * fvzznu_1
        if (fvzznu_1 .lt. d2smallerfv)   fvzznu_1 = 0.
        fvzznu_1 = thngy_ * fvzznu_1
      enddo
!
!     ninloop = nssq*(mynx+2*nbdy-8) * loopsPPB103
!     nrecips = nrecips + ninloop*(1+0+0)
!     ncvmgms = ncvmgms + ninloop*(10+2+4)
!     nmults = nmults + ninloop*(24+5+10)
!     nadds = nadds + ninloop*(24+3+6)
!
      endif
!
!
!
!
!
!PPM$ LONGITUDINAL LOOP
!DEC$ VECTOR ALWAYS
!DEC$ VECTOR ALIGNED
      do   jk = 1,nssqhf
      dmomz20l_1(jk) = dmomz20l_2(jk+nssqhf)
      dmomyz0l_1(jk) = dmomyz0l_2(jk+nssqhf)
      enddo
!
!
!
!
!      endif
!
!
!     PPB101 (myhfcube .ge. 4)
!      ninloop = nssq
!      oopm1 = ninloop * (2*nbqx + 4 - 3)
!      oopm2 = ninloop * (2*nbqx + 4 - 4)
!      recips = recips + oopm1 * 2.  + oopm2 * 1.
!      cvmgms = cvmgms + oopm1 * 10. + oopm2 * 16.
!      amults = amults + oopm1 * 61. + oopm2 * 39.
!      adds   = adds   + oopm1 * 32. + oopm2 * 33.
!
!
!
!
!
      return
      end

