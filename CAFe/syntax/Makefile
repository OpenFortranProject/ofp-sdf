include ../../make.inc

TEST_DIR = ../../tests/rule-tests

STRATEGO_TBL = /usr/local/packages/strategoxt-0.17/stratego-front/syn/StrategoStratego.tbl

TestFiles = $(wildcard $(TEST_DIR)/*.f90)
ASTFiles  = $(wildcard $(TEST_DIR)/*.f90.ast)

FOR_ROOT = ../../fortran/syntax

all : CAFe.tbl

$(FOR_ROOT)/Main.def : $(FOR_ROOT)/Main.sdf
	cd $(FOR_ROOT); pack-sdf -i Main.sdf -o Main.def -I

CAFe.tbl : CAFe.def
	sdf2table -i $< -o $@ -m CAFe

CAFe.def : CAFe.sdf $(FOR_ROOT)/Main.def
	pack-sdf -i $< -o $@ -Idef $(FOR_ROOT)/Main.def

CAFe.rtg : CAFe.def
	$(ST_PATH)/sdf2rtg -i CAFe.def -m CAFe -o CAFe.rtg

CAFe.str : CAFe.rtg
	$(ST_PATH)/rtg2sig -i CAFe.rtg -o CAFe.str

convolve : convolve.lope CAFe.tbl
	sglri -i convolve.lope -p CAFe.tbl | implode-asfix | pp-aterm -o convolve.lope.aterm

stencil : stencil.lope CAFe.tbl
	sglri -i stencil.lope -p CAFe.tbl | implode-asfix | pp-aterm -o stencil.lope.aterm

clean :
	rm -f *.def *.tbl *.rtg *.sig
	rm -f *.aterm
	rm -f *.o *.mod
