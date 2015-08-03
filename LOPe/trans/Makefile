include ../../make.inc
#include lope-lower.dep
#include lope-to-foropencl.dep

SYNTAX_DIR = ../../LOPe/syntax
TRANS_DIR  = ../../fortran/trans
PP_DIR     = ../../fortran/pp

TBL     = $(SYNTAX_DIR)/LOPe.tbl
TO_SIM  = $(TRANS_DIR)/ofp-simplify
TO_FAST = $(TRANS_DIR)/ofp2fast
TO_PP   = $(TRANS_DIR)/fast2pp
PP      = $(PP_DIR)/Fortran.pp

CFLAGS = $(ST_CFLAGS) -I ../syntax -I ../../fortran/syntax -I ../../fortran/trans
LDFLAGS = $(ST_LDFLAGS) -la stratego-lib

## Fortran targets
#  ---------------

FC = ifort
FCFLAGS = -I ForOpenCL

%.o: %.f90
	@echo 'Building for OS $(OSUPPER) file: $<'
	$(FC) -c $(FCFLAGS) -o $@ $<


all : lope-to-foropencl sg-const-folding

lope-lower : lope-lower.str
	$(ST_PATH)/strc -i lope-lower.str $(CFLAGS) $(LDFLAGS) --main io-lope-lower

sg-const-folding : sg-const-folding.str
	$(ST_PATH)/strc -i sg-const-folding.str $(CFLAGS) $(LDFLAGS) --main io-sg-const-folding

lope-to-foropencl : lope-to-foropencl.str
	$(ST_PATH)/strc -i lope-to-foropencl.str $(CFLAGS) $(LDFLAGS) --main io-lope-to-foropencl

check : lope-to-foropencl
	sglri -p $(TBL) -i testfile.f90 | $(TO_FAST) | lope-to-foropencl | $(TO_PP) | ast2text -p $(PP)

check-last : lope-to-foropencl
	sglri -p $(TBL) -i testfile.f90 | $(TO_FAST) | lope-to-foropencl | pp-aterm

check-lower : lope-lower
	sglri -p $(TBL) -i testfile.f90 | $(TO_FAST) | lope-lower | $(TO_PP) | ast2text -p $(PP)

clean :
	rm -f lope-lower lope-lower.c
	rm -f lope-to-foropencl lope-to-foropencl.c
	rm -f *.o *.lo *.dep
