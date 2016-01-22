      subroutine test1
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
      do jk = 1,nssq
      cournogp1(jk) = 0.
      cournogp3(jk) = 0.
      enddo
      end
c
ccccccccccccccccccccccccccccccccccccccccccccccccccccccc
c Transformation from OFP should insert the following declaration
c
c     dimension cournogp1(nssq)
c     dimension cournogp3(nssq)
c
