      subroutine test2
      parameter (nsugar=4)
      parameter (nsugarsq=nsugar*nsugar)
      parameter (nsugarcubed=nsugarsq*nsugar)
      parameter (nbdy=4)
      parameter (nbdy1=nbdy+nsugar-1)
      parameter (nghostcubes=(nbdy1/nsugar))
      parameter (nghostcells=nghostcubes*nsugar)
      parameter (mynx=nsugar)
      parameter (myny=nsugar)
      parameter (mynz=nsugar)
      parameter (nyy=myny)
      parameter (nzz=mynz)
      parameter (nssqhf=nyy*nzz)
      parameter (nssq=nyy*nzz*2)
      parameter (nssqbq=myny*mynz)
c
      cournogp1 = 0.
      cournogp3 = 0.
      end
c
ccccccccccccccccccccccccccccccccccccccccccccccccccccccc
c Transformation from OFP should insert the following declaration & computation
c
c     dimension cournogp1(nssq)
c     dimension cournogp3(nssq)
c
c     do jk = 1,nssq
c     cournogp1(jk) = 0.
c     cournogp3(jk) = 0.
c     enddo
c     
c Or in the following F90 style
c
c     real, dimension(nssq) :: cournogp1, cournogp3
c
c     cournogp1(:) = 0.
c     cournogp3(:) = 0.
c     
c
