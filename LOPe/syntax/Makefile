include ../../make.inc

TEST_DIR = ../../tests/rule-tests

STRATEGO_TBL = /usr/local/packages/strategoxt-0.17/stratego-front/syn/StrategoStratego.tbl

TestFiles = $(wildcard $(TEST_DIR)/*.f90)
ASTFiles  = $(wildcard $(TEST_DIR)/*.f90.ast)

FOR_ROOT = ../../fortran/syntax

all : LOPe.tbl

$(FOR_ROOT)/Main.def : $(FOR_ROOT)/Main.sdf
	cd $(FOR_ROOT); pack-sdf -i Main.sdf -o Main.def -I

LOPe.tbl : LOPe.def
	sdf2table -i $< -o $@ -m LOPe

LOPe.def : LOPe.sdf $(FOR_ROOT)/Main.def
	pack-sdf -i $< -o $@ -Idef $(FOR_ROOT)/Main.def

LOPe.rtg : LOPe.def
	$(ST_PATH)/sdf2rtg -i LOPe.def -m LOPe -o LOPe.rtg

LOPe.str : LOPe.rtg
	$(ST_PATH)/rtg2sig -i LOPe.rtg -o LOPe.str

convolve : convolve.lope LOPe.tbl
	sglri -i convolve.lope -p LOPe.tbl | implode-asfix | pp-aterm -o convolve.lope.aterm

stencil : stencil.lope LOPe.tbl
	sglri -i stencil.lope -p LOPe.tbl | implode-asfix | pp-aterm -o stencil.lope.aterm

clean :
	rm -f *.def *.tbl *.rtg *.sig
	rm -f *.aterm
	rm -f *.o *.mod
