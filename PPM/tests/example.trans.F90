SUBROUTINE FVsCsEs1(nssq,rhogp5,pgp5,fvgp5,rhoairgp5,ceul2iairgp5,ceulgp5,gamma1gp5, &
                 rhocldtoair0,gammaair,gammacld,ifdebug,time,myrank,mythread,mbrick, &
                 icube,jbq,kbq,ipass,MyBrickX,MyBrickY,MyBrickZ,NXBricks,NYBricks,NZBricks,dbgfile,iu6)
CHARACTER(14) :: dbgfile
REAL, DIMENSION(nssq) :: ceulgp5
REAL, DIMENSION(nssq) :: gamma1gp5
REAL, DIMENSION(nssq) :: ceul2iairgp5
REAL, DIMENSION(nssq) :: rhoairgp5
REAL, DIMENSION(nssq) :: fvgp5
IF (fvgp5 < .000002) fvgp5 = 0.
IF (fvgp5 > .999998) fvgp5 = 1.
fvair = 1.-fvgp5
rhoairbyrho = 1./(fvair+rhocldtoair0*fvgp5)
rhoairgp5 = rhogp5*rhoairbyrho
rhocld = rhocldtoair0*rhoairgp5
fmcld = rhocld*fvgp5
fmair = rhoairgp5*fvair
facair = fmair*(1./(gammaair-1.))
faccld = fmcld*(1./(gammacld-1.))
pinv = 1./pgp5
ceul2iairgp5 = (1./gammaair)*rhoairgp5*pinv
ceul2icld = (1./gammacld)*rhocld*pinv
w88 = rhoairbyrho*(facair*ceul2icld+faccld*ceul2iairgp5)
ceul2i = (facair+faccld*(1./rhocldtoair0))*ceul2iairgp5*ceul2icld/w88
gm1inv = fvair*(1./(gammaair-1.))+fvgp5*(1./(gammacld-1.))
gamma1gp5 = 1./gm1inv
ceulgp5 = 1./sqrt(ceul2i)
RETURN
END SUBROUTINE

