include ../../make.inc

TEST_DIR = ../../tests/rule-tests

STRATEGO_TBL = /usr/local/packages/strategoxt-0.17/stratego-front/syn/StrategoStratego.tbl

TestFiles = $(wildcard $(TEST_DIR)/*.f90)
ASTFiles  = $(wildcard $(TEST_DIR)/*.f90.ast)

FOR_ROOT = ../../fortran/syntax

all : CAFe.tbl

$(FOR_ROOT)/Main.def : $(FOR_ROOT)/Main.sdf
	cd $(FOR_ROOT); $(ST_PATH)/pack-sdf -i Main.sdf -o Main.def -I

CAFe.tbl : CAFe.def
	$(SDF2_PATH)/sdf2table -i $< -o $@ -m CAFe

CAFe.def : CAFe.sdf $(FOR_ROOT)/Main.def
	$(ST_PATH)/pack-sdf -i $< -o $@ -Idef $(FOR_ROOT)/Main.def

CAFe.rtg : CAFe.def
	$(ST_PATH)/sdf2rtg -i CAFe.def -m CAFe -o CAFe.rtg

CAFe.str : CAFe.rtg
	$(ST_PATH)/rtg2sig -i CAFe.rtg -o CAFe.str

convolve : convolve.lope CAFe.tbl
	$(ST_PATH)/sglri -i convolve.lope -p CAFe.tbl | $(ST_PATH)/implode-asfix | $(ST_PATH)/pp-aterm -o convolve.lope.aterm

stencil : stencil.lope CAFe.tbl
	$(ST_PATH)/sglri -i stencil.lope -p CAFe.tbl | $(ST_PATH)/implode-asfix | $(ST_PATH)/pp-aterm -o stencil.lope.aterm

clean :
	rm -f *.def *.tbl *.rtg *.sig
	rm -f *.aterm
	rm -f *.o *.mod
