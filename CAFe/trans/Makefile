include ../../make.inc

SYNTAX_DIR = ../../CAFe/syntax
TRANS_DIR  = ../../fortran/trans
PP_DIR     = ../../fortran/pp

TBL     = $(SYNTAX_DIR)/CAFe.tbl
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


all : cafe-lower cafe-to-foropencl cafe-to-ocr 

cafe-lower : cafe-lower.str
	$(ST_PATH)/strc -i cafe-lower.str $(CFLAGS) $(LDFLAGS) --main io-cafe-lower

cafe-to-foropencl : cafe-to-foropencl.str
	$(ST_PATH)/strc -i cafe-to-foropencl.str $(CFLAGS) $(LDFLAGS) --main io-cafe-to-foropencl

cafe-to-ocr : cafe-to-ocr.str
	$(ST_PATH)/strc -i cafe-to-ocr.str $(CFLAGS) $(LDFLAGS) --main io-cafe-to-ocr

check : cafe-to-foropencl
	$(ST_PATH)/sglri -p $(TBL) -i testfile.f90 | $(TO_FAST) | cafe-to-foropencl | $(TO_PP) | $(ST_PATH)/ast2text -p $(PP)

check-orig : cafe-to-foropencl
	$(ST_PATH)/sglri -p $(TBL) -i testfile.f90.orig | $(TO_FAST) | cafe-to-foropencl | $(TO_PP) | $(ST_PATH)/ast2text -p $(PP)

check-fast :
	$(ST_PATH)/sglri -p $(TBL) -i testfile.f90 | $(TO_FAST) | $(ST_PATH)/pp-aterm

check-cast : cafe-to-foropencl
	$(ST_PATH)/sglri -p $(TBL) -i testfile.f90 | $(TO_FAST) | cafe-to-foropencl | $(ST_PATH)/pp-aterm

check-lower : cafe-lower
	$(ST_PATH)/sglri -p $(TBL) -i testfile.f90 | $(TO_FAST) | cafe-lower | $(TO_PP) | $(ST_PATH)/ast2text -p $(PP)

clean :
	rm -f cafe-lower cafe-lower.c
	rm -f cafe-to-foropencl cafe-to-foropencl.c
	rm -f cafe-to-ocr cafe-to-ocr.c
	rm -f *.o *.lo *.dep
