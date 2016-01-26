include ../../make.inc

TEST_DIR = ../../tests/rule-tests

STRATEGO_TBL = /usr/local/packages/strategoxt-0.17/stratego-front/syn/StrategoStratego.tbl

TestFiles = $(wildcard $(TEST_DIR)/*.f90)
ASTFiles  = $(wildcard $(TEST_DIR)/*.f90.ast)

FOR_ROOT = ../../fortran/syntax

all : PPM.tbl

$(FOR_ROOT)/Main.def : $(FOR_ROOT)/Main.sdf
	cd $(FOR_ROOT); pack-sdf -i Main.sdf -o Main.def -I

PPM.tbl : PPM.def
	sdf2table -i $< -o $@ -m PPM

PPM.def : PPM.sdf $(FOR_ROOT)/Main.def
	pack-sdf -i $< -o $@ -Idef $(FOR_ROOT)/Main.def

PPM.rtg : PPM.def
	$(ST_PATH)/sdf2rtg -i PPM.def -m PPM -o PPM.rtg

PPM.str : PPM.rtg
	$(ST_PATH)/rtg2sig -i PPM.rtg -o PPM.str

convolve : convolve.lope PPM.tbl
	sglri -i convolve.lope -p PPM.tbl | implode-asfix | pp-aterm -o convolve.lope.aterm

stencil : stencil.lope PPM.tbl
	sglri -i stencil.lope -p PPM.tbl | implode-asfix | pp-aterm -o stencil.lope.aterm

clean :
	rm -f *.def *.tbl *.rtg *.sig
	rm -f *.aterm
	rm -f *.o *.mod
	rm -f *~
