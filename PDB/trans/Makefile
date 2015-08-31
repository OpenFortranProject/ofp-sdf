OFP_ROOT = ../..

CFLAGS = -I $(OFP_ROOT)/fortran/syntax -I $(OFP_ROOT)/fortran/trans
LDFLAGS = -la stratego-lib

## for clang Mac OS X
CFLAGS  += -Xcc -m32 -Xcc -Wno-parentheses-equality
LDFLAGS += -Xlinker -m32

FSYN   = $(OFP_ROOT)/fortran/syntax
FTRANS = $(OFP_ROOT)/fortran/trans

all : fast-to-pdb PDB.str

fast-to-pdb : fast-to-pdb.str PDB.str
	strc -i fast-to-pdb.str $(CFLAGS) $(LDFLAGS)

PDB.str : PDB.rtg
	rtg2sig -i PDB.rtg -o PDB.str

check : fast-to-pdb
	fast-to-pdb -n R1101c.f90 -i testfile.f90.aterm | pp-aterm

check-fast :
	sglri -i testfile.f90 -p $(FSYN)/Fortran.tbl | $(FTRANS)/ofp2fast | pp-aterm

unparse : fast-to-pdb
	@echo "----------------"
	@sglri -i testfile.f90 -p $(FSYN)/Fortran.tbl | $(FTRANS)/ofp2fast | fast-to-pdb -n "R1101c.f90" | ast2text -p ../pp/PDBFile.pp

pp : fast-to-pdb
	sglri -i testfile.f90 -p $(FSYN)/Fortran.tbl | $(FTRANS)/ofp2fast | fast-to-pdb -n "R1101c.f90"

term : $(FTRANS)/ofp2fast $(FSYN)/Fortran.tbl
	sglri -i testfile.f90 -p $(FSYN)/Fortran.tbl | $(FTRANS)/ofp2fast | pp-aterm -o testfile.f90.aterm

clean :
	rm -f fast-to-pdb fast-to-pdb.c fast-to-pdb.dep
	rm -f *.o *.lo
