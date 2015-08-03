include ../../make.inc

TEST_DIR = ../../tests/rule-tests

TestFiles = $(wildcard $(TEST_DIR)/*.f90)
ASTFiles  = $(wildcard $(TEST_DIR)/*.f90.ast)

SDF_FILES =  FortranLex.sdf           \
             FortranLexFixed.sdf      \
             FortranLexFree.sdf       \
             FortranFixed.sdf         \
             Main.sdf

%.tbl : %
	$(SDF2_PATH)/sdf2table -i $< -o $@

all : Fortran.tbl

FAST.def : FAST.sdf
	$(ST_PATH)/pack-sdf -i $< -o $@

#FAST.rtg : FAST.def
FAST.rtg :
	$(ST_PATH)/sdf2rtg -i FAST.def -m FAST -o FAST.rtg

FAST.str : FAST.rtg
	$(ST_PATH)/rtg2sig -i FAST.rtg -o FAST.str

Main.def : Main.sdf FortranLex.sdf FortranLexFree.sdf
	$(ST_PATH)/pack-sdf -i $< -o $@

FortranFixed.def : FortranFixed.sdf FortranLex.sdf FortranLexFixed.sdf
	$(ST_PATH)/pack-sdf -i $< -o $@

Fortran.tbl : Main.def
	$(SDF2_PATH)/sdf2table -i $< -o $@ -m Main

FortranFixed.tbl : FortranFixed.def
	$(SDF2_PATH)/sdf2table -i $< -o $@ -m FortranFixed

Fortran.def : Fortran.sdf FortranLex.sdf FortranLexFree.sdf
	$(ST_PATH)/pack-sdf -i $< -o $@

Main.rtg : Main.def Fortran.tbl
	$(ST_PATH)/sdf2rtg -i Main.def -m Main -o Main.rtg

Main.str : Main.rtg
	$(ST_PATH)/rtg2sig -i Main.rtg -o Main.str

check : Fortran.tbl
	@for File in $(TestFiles) ;\
           do \
              $(SDF2_PATH)/sglr -v -p Fortran.tbl -i $$File -o $$File.ast ; \
           done

pretty : Fortran.tbl
	@for File in $(ASTFiles) ;\
           do \
              echo "Pretty printing $$File..." ; \
              $(ST_PATH)/pp-aterm -i $$File -o $$File.pp ; \
           done

Fortran.sig.aterm : Main.sig
	$(SGLRI) -p $(STRATEGO_TBL) -i Main.sig | implode-asfix | pp-aterm -o Fortran.sig.aterm

junk : junk.f90 Fortran.tbl
	$(SGLRI) -i junk.f90 -p Fortran.tbl | implode-asfix | pp-aterm -o junk.f90.aterm

junkf : junk.f FortranFixed.tbl
	$(SGLRI) -i junk.f -p FortranFixed.tbl | implode-asfix | pp-aterm -o junk.f.aterm

junk.ptree : junk.f90 Fortran.tbl
	$(SGLRI) -i junk.f90 -p Fortran.tbl -o junk.ptree

junk.ast-info.pp : junk.f90 Fortran.tbl
	$(SDF2_PATH)/sglr -i junk.f90 -p Fortran.tbl | addPosInfo -p ./junk.f90 -m | implode-asfix | pp-aterm -o junk.ast-info.pp

clean :
	rm -f *.def *.tbl
	rm -f *.ast *.pp
	rm -f *.o *.mod
	rm -f $(TEST_DIR)/*.ast $(TEST_DIR)/*.ast.pp
