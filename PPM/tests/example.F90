      subroutine FVsCsEs1 (rhogp5,pgp5,fvgp5,&

     &                     rhoairgp5,ceul2iairgp5,ceulgp5,gamma1gp5,&
     &                    rhocldtoair0,&
     &                    gammaair,gammacld,&
     &                    ifdebug,time,myrank,mythread,mbrick,&
     &                    icube,jbq,kbq,ipass,&
     &                    MyBrickX,MyBrickY,MyBrickZ,&
     &                    NXBricks,NYBricks,NZBricks,dbgfile,iu6)
!
!!DIR$ ATTRIBUTES FORCEINLINE :: FVsCsEs1
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
!     Input arrays:
!        rhogp5,pgp5,fvgp5
!
!     Output arrays:
!        rhoairgp5,ceul2iairgp5,ceulgp5,gamma1gp5
!
      character*14   dbgfile
!
!
!
!
!PPM$ LONGITUDINAL LOOP
      if (fvgp5 .lt. .000002)   fvgp5 = 0.
      if (fvgp5 .gt. .999998)   fvgp5 = 1.
      fvair = 1. - fvgp5
      rhoairbyrho = 1. / (fvair +  rhocldtoair0 * fvgp5)
      rhoairgp5 = rhogp5 * rhoairbyrho
      rhocld = rhocldtoair0 * rhoairgp5
      fmcld = rhocld * fvgp5
      fmair = rhoairgp5 * fvair
      facair = fmair * (1./(gammaair-1.))
      faccld = fmcld * (1./(gammacld-1.))
      pinv = 1. / pgp5
      ceul2iairgp5 = (1./gammaair) * rhoairgp5 * pinv
      ceul2icld = (1./gammacld) * rhocld * pinv
      w88 = rhoairbyrho * (facair * ceul2icld &
     &                  +  faccld * ceul2iairgp5)
      ceul2i = (facair  +  faccld * (1./rhocldtoair0))&
     &        * ceul2iairgp5 * ceul2icld / w88
      gm1inv = fvair * (1./(gammaair-1.))  +  fvgp5 * (1./(gammacld-1.))
      gamma1gp5 = 1. / gm1inv
      ceulgp5 = 1.  /  sqrt (ceul2i)
!
!#if 1 == 0

!
!      loopsfvscs1 = loopsfvscs1 + 1
!
!      ninloop = nssq * loopsfvscs1
!      oop = ninloop
!      rsqrts = rsqrts + oop
!      recips = recips + oop * 4.
!      cvmgms = cvmgms + oop * 2.
!      amults = amults + oop * 19.
!      adds = adds + oop * 7.
!
!
!
      return
      end

