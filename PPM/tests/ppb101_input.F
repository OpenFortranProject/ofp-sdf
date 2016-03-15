      subroutine ppb101(uxavl_1,uxavl_3,uxavlmod_1,uxavlmod_3,
     &                  fv_1,fvx_1,fvxx_1,fvyy_1,fvyz_1,fvzz_1,
     &                  fv_2,fvx_2,fvxx_2,
     &
     &                  dmom0l_1,dmom1l_1,dmom2l_1,
     &                  dmomy20l_1,dmomyz0l_1,dmomz20l_1,
     &
     &                  fvnu_1,fvxnu_1,fvxxnu_1,fvyynu_1,
     &                  fvyznu_1,fvzznu_1,fvavl_2,
     &                  sigmal_2,dchil1_2,d1_2,d2_2,
     &                  fupstrml_2,dchi0rel_1,f_1,
     &
     &                 fv001,dt,dx,courmx,iffirstcall,
     &             ifdebug,time,myrank,mythread,mbrick,
     &             icube,jbq,kbq,ipass,
     &             MyBrickX,MyBrickY,MyBrickZ,
     &             NXBricks,NYBricks,NZBricks,
     &             dbgfile,iu6)
c
c!DIR$ ATTRIBUTES FORCEINLINE :: ppb101
c
c     Glob 1:     rho,      p,     fv,     ux
c     Glob 2:      uy,     uz, difuse,   fvyz
c     Glob 3:     fvx,   fvxx,   fvyy,   fvzz 
c     Glob 4:     fvy,   fvxy,    fvz,   fvxz
c 
c     ppb101 cannot be called until glob 3 has arrived.
c     ppb102 cannot be called until glob 4 has arrived.
c
c
c
c                    **************************************************
c                    **************************************************
c                    **************************************************
c                    **************************************************
c                    *****                                        *****
c                    *****       THIS CODE WAS WRITTEN BY         *****
c                    *****                                        *****
c                    *****            PAUL R. WOODWARD            *****
c                    *****                                        *****
c                    *****               May, 1992                *****
c                    *****          Through  summer, 2013         *****
c                    *****       Spruced up  winter, 2013-14      *****
c                    *****                                        *****
c                    *****     All reservable rights reserved     *****
c                    *****                                        *****
c                    **************************************************
c                    **************************************************
c                    **************************************************
c                    **************************************************
c
c
c
c
      parameter (nsugar=4)
      parameter (nsugarsq=nsugar*nsugar)
      parameter (nssqhf=nsugarsq)
      parameter (nssq=nsugarsq*2)
c
c
c
c     Input arrays for PPB101:
c        uxavl_1,uxavl_3,uxavlmod_1,uxavlmod_3,
c        fv_1,fvx_1,fvxx_1,fv_2,fvx_2,fvxx_2,
c        fvyy_1,fvyz_1,fvzz_1,dmom0l_1,dmom1l_1,dmom2l_1,
c        dmomy20l_1,dmomyz0l_1,dmomz20l_1
c
c     Output arrays from PPB101:
c        fvnu_1,fvxnu_1,fvxxnu_1,fvyynu_1,fvyznu_1,fvzznu_1,
c        fvavl_2,sigmal_2,dchil1_2,d1_2,d2_2,
c        fupstrml_2,dchi0rel_1,f_1
c
c      In preparation for next call to this routine:
c        dmom0l_1,dmom1l_1,dmom2;_1,dmomy20l_1,dmomyz0l_1,
c        dmomz20l_1
c
c     Scratch arrays for PPB101:
c        uxavl_2,uxavlmod_2,fvyy_2,fvyz_2,fvzz_2,
c        dchil_1,dchil_2,dchilrel_1,dchilrel_2,sl_1,sl_2,
c        dmom0l_2,dmom1l_2,dmom2l_2,dmomy20l_2,dmomyz0l_2,
c        dmomz2l_2,fvupstrml_2,fvxupstrml_2,fvxxupstrml_2,
c        fvyyupstrml_2,fvzzupstrml_2
c
c     Declare implicit postfix for gp5 suffix
c
      implicit postfix real, dimension(nssq) ("_1")
      implicit postfix real, dimension(nssq) ("_2")
      implicit postfix real, dimension(nssq) ("_3")
c
      character*14   dbgfile
c
c
c
c
c
c      if (myhfcube .ge. 4)   then
c
c
c     6/29/11:
c     Note that for our formulae to be correct in the case of a moving
c     grid,  dtbyx  must refer to the value of  dx  at the beginning of
c     the time step.
c     See the document:  PPB10-and-PPM-formulae-4-23-06-and-4-6-11.docx
c
cPPM$ LONGITUDINAL LOOP
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
c
c     nrecips = nrecips + (nsugar+3)*2
c     ncvmgms = ncvmgms + (nsugar+3)*4
c     nmults = nmults + (nsugar+3)*20
c     nadds = nadds + (nsugar+3)*12
c
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
      fvavl_2 = fv0upstrmlzr  +  sl_2 * d1_2 * fv1upstrmlzr
     &                         +  d2_2 * fv2upstrmlzr
c
      dmm0r = sigmal_2 * fvavl_2
      dmm1r = sigmal_2 * (sl_2 * d1_2 * fv0upstrmlzr
     &      +  d2_2 * fv1upstrmlzr  +  sl_2 * d3zr * fv2upstrmlzr)
      dmm2r = sigmal_2 * (d2_2 * fv0upstrmlzr
     &      +  sl_2 * d3zr * fv1upstrmlzr  +  d4zr * fv2upstrmlzr)
      dmom0l_2 = fupstrml_2 * dmm0r
      fsqupstrmlzr = fupstrml_2 * fupstrml_2
      dchil1_2 = dchi0upstrmlzr - sl_2
      dmom1l_2 = fsqupstrmlzr * dmm1r  +  dchil1_2 * dmom0l_2
      dmom2l_2 = fupstrml_2 * fsqupstrmlzr * dmm2r
     &          +  dchil1_2 * (fsqupstrmlzr * dmm1r  +  dmom1l_2)
      enddo
c
c     nrecips = nrecips + (nsugar+3)*(2+0)
c     ncvmgms = ncvmgms + (nsugar+3)*(4+3)
c     nmults = nmults + (nsugar+3)*(20+24)
c     nadds = nadds + (nsugar+3)*(12+12)
c
c
c      loopsPPB102 = loopsPPB102 + 1
c      ninloop = nssq*(mynx+2*nbdy-7)*loopsPPB102
c      oop = ninloop
c      recips = recips + oop*2.
c      cvmgms = cvmgms + oop*7.
c      amults = amults + oop*44.
c      adds = adds + oop*24.
c
c
c
      if (iffirstcall .eq. 0)   then
c
c
c     It is only necessary to save one set of dual-grid-plane arrays of
c     moments around the cycle, not two.  Therefore, we make the arrays
c     dmom0r, dmom1r, and dmom2r have just one element each, and we
c     save dmom0l, dmom1l, dmom2l around the cycle and only these.
c     Below, we introduce into these saved arrays form the last call to
c     this routine the halves that have just been constructed above.
c     Before leaving this routine, we will insert into the bottom halves
c     of these arrays the top halves of dmom0r, dmom1r, and dmom2r for
c     use on the next round.
c
cPPM$ LONGITUDINAL LOOP
!DEC$ VECTOR ALWAYS
!DEC$ VECTOR ALIGNED
      do   jk = 1,nssqhf
      dmom0l_1(jk+nssqhf) = dmom0l_2(jk)
      dmom1l_1(jk+nssqhf) = dmom1l_2(jk)
      dmom2l_1(jk+nssqhf) = dmom2l_2(jk)
      enddo
c
c
c
c
c
c     6/29/11:
c     Note that for our formulae to be correct in the case of a moving
c     grid,  dtbyx  must refer to the value of  dx  at the beginning of
c     the time step.
c     See the document:  PPB10-and-PPM-formulae-4-23-06-and-4-6-11.docx
c
cPPM$ LONGITUDINAL LOOP
      do jk = 1,nssq
        dchil_1 = uxavl_1 * dtbydx
        dchilrel_1 = uxavlmod_1 * dtbydx
c        dchi0_ = 0.5 * (dchil_1 + dchil_2)
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
        totmom2nu = f_1 * fsq * fvxx_1
     &            +  dchi0rel_1 * (fsq * fvx_1  +  totmom1nu)
        sl_1 = 1.
        if (uxavlmod_1 .lt. 0.)   sl_1 = -1.
        fvnu_1 = totmom0nu + sl_1 * dmom0l_1
        fvxnu_1 = totmom1nu  +  sl_1 * dmom1l_1
        fvxxnu_1 = totmom2nu  +  sl_1 * dmom2l_1
c
c     nrecips = nrecips + (nsugar+2)*1
c     ncvmgms = ncvmgms + (nsugar+2)*1
c     nmults = nmults + (nsugar+2)*15
c     nadds = nadds + (nsugar+2)*12
c
c       if (uxavl_1 .lt. 0.)   then
c         fvxnu_1 = fvxnu_1 + dmom0l_1
c         fvxxnu_1 = fvxxnu_1
c      &               +  2. * dmom1l_1  -  dmom0l_1
c       endif
        uxrell = uxavlmod_1
        if (uxrell .lt. 0.)   fvxnu_1 = fvxnu_1 + dmom0l_1
        thyng = 2. * dmom1l_1  -  dmom0l_1
        if (uxrell .lt. 0.)   fvxxnu_1 = fvxxnu_1 + thyng
        fvnu_1 = fvnu_1  -  sl_2 * dmom0l_2
        if (fvnu_1 .lt. smallerfv)   fvnu_1 = 0.
        fvxnu_1 = fvxnu_1  -  sl_2 * dmom1l_2
        fvxxnu_1 = fvxxnu_1  -  sl_2 * dmom2l_2
c       if (uxavl_2 .gt. 0.)   then
c         fvxnu_1 = fvxnu_1 - dmom0l_2
c         fvxxnu_1 = fvxxnu_1
c     &                -  2. * dmom1l_2  -  dmom0l_2
c       endif
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
c
c     nrecips = nrecips + (nsugar+2)*(1+0)
c     ncvmgms = ncvmgms + (nsugar+2)*(1+9)
c     nmults = nmults + (nsugar+2)*(15+9)
c     nadds = nadds + (nsugar+2)*(12+12)
c
c     5/7/03:
c     The setting of the various results to zero in the loop above
c     avoids making the processor waste incredible amounts of time
c     "properly" handling "underflows" according to the IEEE standard.
c     If we don't do this, the entire routine runs slower by about
c     a factor of 6.  This is a scandal.  It greatly increases the
c     computational labor for an absolutely stupid reason.
c
c
c     ninloop = nssq*(mynx+2*nbdy-8) * loopsPPB103
c     nrecips = nrecips + ninloop*(1)
c     ncvmgms = ncvmgms + ninloop*(10)
c     nmults = nmults + ninloop*(24)
c     nadds = nadds + ninloop*(24)
c
c
      endif
c
c
c
c
c
c     It is only necessary to save one set of dual-grid-plane arrays of
c     moments around the cycle, not two.  Therefore, we make the arrays
c     dmom0r, dmom1r, and dmom2r have just one element each, and we
c     save dmom0l, dmom1l, dmom2l around the cycle and only these.
c     Before leaving this routine, we insert into the bottom halves
c     of these arrays the top halves of dmom0r, dmom1r, and dmom2r for
c     use on the next round.
c
c
cPPM$ LONGITUDINAL LOOP
!DEC$ VECTOR ALWAYS
!DEC$ VECTOR ALIGNED
      do   jk = 1,nssqhf
      dmom0l_1(jk) = dmom0l_2(jk+nssqhf)
      dmom1l_1(jk) = dmom1l_2(jk+nssqhf)
      dmom2l_1(jk) = dmom2l_2(jk+nssqhf)
      enddo
c
c
c
c
cPPM$ LONGITUDINAL LOOP
      do jk = 1,nssq
        thyng = (fv_2 - small) * (almost1 - fv_2)
        if ((fv_2 - small) .lt. 0.)   fvyy_2 = 0.
        if ((almost1 - fv_2) .lt. 0.)   fvyy_2 = twelth
c
        thyng = (fv_1 - small) * (almost1 - fv_1)
        if ((fv_1 - small) .lt. 0.)   fvyy_1 = 0.
        if ((almost1 - fv_1) .lt. 0.)   fvyy_1 = twelth
c
c
c
c
        fvyyupstrml_2 = fvyy_1
        if (uxavrmod(jk,0) .lt. 0.) fvyyupstrml_2 = fvyy_2
c       fvyy1upstrmlzr = fvxupstrml_2
        fvyy2upstrmlzr = 15. * (fvx2upstrml_2
     &               -  twelth * fvupstrml_2)
        fvyy0upstrmlzr = fvyyupstrml_2  -  twelth * fvyy2upstrmlzr
        thngy_ = sigmal_2 * (fvyy0upstrmlzr
     &          +  sl_2 * d1_2 * fvxupstrml_2
     &          +  d2_2 * fvyy2upstrmlzr)
        dmomy20l_2 = fupstrml_2 * thngy_
       enddo
c
c      loopsPPB102 = loopsPPB102 + 1
c      ninloop = nssq*(mynx+2*nbdy-7)*loopsPPB102
c      oop = ninloop
c      recips = recips + oop*(2.+0.)
c      cvmgms = cvmgms + oop*(7.+1.)
c      amults = amults + oop*(44.+8.)
c      adds = adds + oop*(24.+4.)
c
c
c
c
      if (iffirstcall .eq. 0)   then
c
cPPM$ LONGITUDINAL LOOP
!DEC$ VECTOR ALWAYS
!DEC$ VECTOR ALIGNED
      do   jk = 1,nssqhf
      dmomy20l_1(jk+nssqhf) = dmomy20l_2(jk)
      enddo
c
cPPM$ LONGITUDINAL LOOP
      do jk = 1, nssq
        fvyynu_1 = f_1 * fvyy_1  +  sl_1 * dmomy20l_1
     &                              -  sl_2 * dmomy20l_2
        thngy(jk) = 1.
        if (fvyynu_1 .lt. 0.)   thngy(jk) = -1.
        fvyynu_1 = thngy(jk) * fvyynu_1
        if (fvyynu_1 .lt. d2smallerfv)   fvyynu_1 = 0.
        fvyynu_1 = thngy(jk) * fvyynu_1
      enddo
c
c     ninloop = nssq*(mynx+2*nbdy-8) * loopsPPB103
c     nrecips = nrecips + ninloop*(1+0)
c     ncvmgms = ncvmgms + ninloop*(10+2)
c     nmults = nmults + ninloop*(24+5)
c     nadds = nadds + ninloop*(24+3)
c
      endif
c
c
c
c
c
cPPM$ LONGITUDINAL LOOP
!DEC$ VECTOR ALWAYS
!DEC$ VECTOR ALIGNED
      do   jk = 1,nssqhf
      dmomy20l_1(jk) = dmomy20l_2(jk+nssqhf)
      enddo
c
c
c
c
cPPM$ LONGITUDINAL LOOP
      do jk = 1, nssq
        thyng = (fv_2 - small) * (almost1 - fv_2)
        if (thyng .lt. 0.)   fvyz_2 = 0.
        if ((fv_2 - small) .lt. 0.)   fvzz_2 = 0.
        if ((almost1 - fv_2) .lt. 0.)   fvzz_2 = twelth
c
        thyng = (fv_1 - small) * (almost1 - fv_1)
        if (thyng .lt. 0.)   fvyz_1 = 0.
        if ((fv_1 - small) .lt. 0.)   fvzz_1 = 0.
        if ((almost1 - fv_1) .lt. 0.)   fvzz_1 = twelth
c
c
c
        uxrelr = uxavlmod_2
        fvzzupstrml_2 = fvzz_1
        if (uxrelr .lt. 0.) fvzzupstrml_2 = fvzz_2
c       fvzz1upstrmlzr = fvxupstrml_2
        fvzz2upstrmlzr = 15. * (fvxxupstrml_2 - twelth * fvupstrml_2)
        fvzz0upstrmlzr = fvzzupstrml_2  -  twelth * fvzz2upstrmlzr
        thngy_ = fvzz0upstrmlzr  +  sl_2 * d1_2 * fvxupstrml_2
     &                            +  d2_2 * fvzz2upstrmlzr
        dmomz20l_2 = fupstrml_2 * sigmal_2 * thngy_
c
        thngy_ = fvyz_1
        if (uxrelr .lt. 0.)   thngy_ = fvyz_2
c       fvyz1upstrmlzr = 0.
c       fvyz2upstrmlzr = 15. * (fvyzupstrml_2
c     &                      - fvyzupstrml_2) = 0.
c       fvyz0upstrmlzr = fvyzupstrml_2
        dmomyz0l_2 = fupstrml_2 * sigmal_2 * thngy_
      enddo
c
c      loopsPPB102 = loopsPPB102 + 1
c      ninloop = nssq*(mynx+2*nbdy-7)*loopsPPB102
c      oop = ninloop
c      recips = recips + oop*(2.+0.+0.)
c      cvmgms = cvmgms + oop*(7.+1.+2.)
c      amults = amults + oop*(44.+8.+9.)
c      adds = adds + oop*(24.+4.+4.)
c
c
c
c
c
      if (iffirstcall .eq. 0)   then
c
c
cPPM$ LONGITUDINAL LOOP
!DEC$ VECTOR ALWAYS
!DEC$ VECTOR ALIGNED
      do   jk = 1,nssqhf
      dmomz20l_1(jk+nssqhf) = dmomz20l_2(jk)
      dmomyz0l_1(jk+nssqhf) = dmomyz0l_2(jk)
      enddo
c
c
cPPM$ LONGITUDINAL LOOP
      do jk = 1, nssq
        fvyznu_1 = f_1 * fvyz_1  +  sl_1 * dmomyz0l_1
     &                              -  sl_2 * dmomyz0l_2
        thngy_ = 1.
        if (fvyznu_1 .lt. 0.)   thngy_ = -1.
        fvyznu_1 = thngy_ * fvyznu_1
        if (fvyznu_1 .lt. d2smallerfv)   fvyznu_1 = 0.
        fvyznu_1 = thngy_ * fvyznu_1
c
c       totmom0nu = f_1 * fvzz_1
        fvzznu_1 = f_1 * fvzz_1  +  sl_1 * dmomz20l_1
     &                              -  sl_2 * dmomz20l_2
        thngy_ = 1.
        if (fvzznu_1 .lt. 0.)   thngy_ = -1.
        fvzznu_1 = thngy_ * fvzznu_1
        if (fvzznu_1 .lt. d2smallerfv)   fvzznu_1 = 0.
        fvzznu_1 = thngy_ * fvzznu_1
      enddo
c
c     ninloop = nssq*(mynx+2*nbdy-8) * loopsPPB103
c     nrecips = nrecips + ninloop*(1+0+0)
c     ncvmgms = ncvmgms + ninloop*(10+2+4)
c     nmults = nmults + ninloop*(24+5+10)
c     nadds = nadds + ninloop*(24+3+6)
c
      endif
c
c
c
c
c
cPPM$ LONGITUDINAL LOOP
!DEC$ VECTOR ALWAYS
!DEC$ VECTOR ALIGNED
      do   jk = 1,nssqhf
      dmomz20l_1(jk) = dmomz20l_2(jk+nssqhf)
      dmomyz0l_1(jk) = dmomyz0l_2(jk+nssqhf)
      enddo
c
c
c
c
c      endif
c
c
c     PPB101 (myhfcube .ge. 4)
c      ninloop = nssq
c      oopm1 = ninloop * (2*nbqx + 4 - 3)
c      oopm2 = ninloop * (2*nbqx + 4 - 4)
c      recips = recips + oopm1 * 2.  + oopm2 * 1.
c      cvmgms = cvmgms + oopm1 * 10. + oopm2 * 16.
c      amults = amults + oopm1 * 61. + oopm2 * 39.
c      adds   = adds   + oopm1 * 32. + oopm2 * 33.
c
c
c
c
c
      return
      end
