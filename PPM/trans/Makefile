include ../../make.inc
#include ppm-lower.dep
#include ppm-to-foropencl.dep

SYNTAX_DIR = ../../PPM/syntax
TRANS_DIR  = ../../fortran/trans
PP_DIR     = ../../fortran/pp

TBL     = $(SYNTAX_DIR)/PPM.tbl
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


all : ppm-to-ocr ppm-to-foropencl #sg-const-folding

elemental_add_1d : elemental_add_1d.f90
	$(FC) elemental_add_1d.f90 -o elemental_add_1d $(FCFLAGS) -Wl,-no_pie -L$(FOR_OCL_DIR) -lforopencl -framework OpenCL

elemental_add_2d : elemental_add_2d.f90
	$(FC) elemental_add_2d.f90 -o elemental_add_2d $(FCFLAGS) -Wl,-no_pie -L$(FOR_OCL_DIR) -lforopencl -framework OpenCL

ppm-lower : ppm-lower.str
	$(ST_PATH)/strc -i ppm-lower.str $(CFLAGS) $(LDFLAGS) --main io-ppm-lower

sg-const-folding : sg-const-folding.str
	$(ST_PATH)/strc -i sg-const-folding.str $(CFLAGS) $(LDFLAGS) --main io-sg-const-folding

ppm-to-foropencl : ppm-to-foropencl.str
	$(ST_PATH)/strc -i ppm-to-foropencl.str $(CFLAGS) $(LDFLAGS) --main io-ppm-to-foropencl

ppm-to-ocr : ppm-to-ocr.str
	$(ST_PATH)/strc -i ppm-to-ocr.str $(CFLAGS) $(LDFLAGS) --main io-ppm-to-ocr

check :
	sglri -p $(TBL) -i testfile.f90 | pp-aterm

check-foropencl : ppm-to-foropencl
	@sglri -p $(TBL) -i testfile.f90 | $(TO_FAST) | ppm-to-foropencl | $(TO_PP) | ast2text -p $(PP)

check-orig : ppm-to-foropencl
	@sglri -p $(TBL) -i testfile.f90.orig | $(TO_FAST) | ppm-to-foropencl | $(TO_PP) | ast2text -p $(PP)

check-fast :
	sglri -p $(TBL) -i testfile.f90 | $(TO_FAST) | pp-aterm

check-last : ppm-to-foropencl
	sglri -p $(TBL) -i testfile.f90 | $(TO_FAST) | ppm-to-foropencl | pp-aterm

check-lower : ppm-lower
	sglri -p $(TBL) -i testfile.f90 | $(TO_FAST) | ppm-lower | $(TO_PP) | ast2text -p $(PP)

clean :
	rm -f ppm-lower ppm-lower.c
	rm -f ppm-to-foropencl ppm-to-foropencl.c
	rm -f *.o *.lo *.dep
