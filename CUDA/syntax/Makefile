include ../../make.inc

TEST_DIR = ../../tests/rule-tests

STRATEGO_TBL = /usr/local/packages/strategoxt-0.17/stratego-front/syn/StrategoStratego.tbl

TestFiles = $(wildcard $(TEST_DIR)/*.f90)
ASTFiles  = $(wildcard $(TEST_DIR)/*.f90.ast)

FOR_ROOT = ../../fortran/syntax

all : CUDA.tbl

CUDA.tbl : CUDA.def
	sdf2table -i $< -o $@ -m CUDA

CUDA.def : CUDA.sdf
	pack-sdf -i $< -o $@ -Idef $(FOR_ROOT)/Main.def

clean :
	rm -f *.def *.tbl
	rm -f *.aterm
	rm -f *.o *.mod
