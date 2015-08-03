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

CLC = /System/Library/Frameworks/OpenCL.framework/Versions/Current/Libraries/openclc

FOR_OCL_DIR = /Users/rasmus/ofp-research/opencl/ForOpenCL

CFLAGS = $(ST_CFLAGS) -I ../syntax -I ../../fortran/syntax -I ../../fortran/trans
LDFLAGS = $(ST_LDFLAGS) -la stratego-lib

## Fortran targets
#  ---------------

FC = ifort
FCFLAGS = -g -I $(FOR_OCL_DIR)

%.o: %.f90
	@echo 'Building for OS $(OSUPPER) file: $<'
	$(FC) -c $(FCFLAGS) -o $@ $<


all : lope-to-foropencl sg-const-folding

elemental_add_1d : elemental_add_1d.f90
	$(FC) elemental_add_1d.f90 -o elemental_add_1d $(FCFLAGS) -Wl,-no_pie -L$(FOR_OCL_DIR) -lforopencl -framework OpenCL

elemental_add_2d : elemental_add_2d.f90
	$(FC) elemental_add_2d.f90 -o elemental_add_2d $(FCFLAGS) -Wl,-no_pie -L$(FOR_OCL_DIR) -lforopencl -framework OpenCL

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
