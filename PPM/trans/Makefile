include ../../make.inc

SYNTAX_DIR = ../../PPM/syntax
TRANS_DIR  = ../../fortran/trans
PP_DIR     = ../../fortran/pp

TBL     = $(SYNTAX_DIR)/PPM.tbl
TO_SIM  = $(TRANS_DIR)/ofp-simplify
TO_FAST = $(TRANS_DIR)/ofp2fast
TO_PP   = $(TRANS_DIR)/fast2pp
PP      = $(PP_DIR)/Fortran.pp

CFLAGS = $(ST_CFLAGS) -I ../syntax -I ../../fortran/syntax -I ../../fortran/trans
LDFLAGS = $(ST_LDFLAGS) -la stratego-lib

## Fortran targets
#  ---------------

FC = ifort
FCFLAGS = -g -I $(FOR_OCL_DIR)

%.o: %.f90
	@echo 'Building for OS $(OSUPPER) file: $<'
	$(FC) -c $(FCFLAGS) -o $@ $<


all : ppm-to-fast

ppm-lower : ppm-lower.str
	$(ST_PATH)/strc -i ppm-lower.str $(CFLAGS) $(LDFLAGS) --main io-ppm-lower

ppm-to-fast : ppm-to-fast.str
	$(ST_PATH)/strc -i ppm-to-fast.str $(CFLAGS) $(LDFLAGS) --main io-ppm-to-fast

check :
	sglri -p $(TBL) -i testfile.f90 | pp-aterm

check-fast : ppm-to-fast
	@sglri -p $(TBL) -i testfile.f90 | $(TO_FAST) | ppm-to-fast | $(TO_PP) | ast2text -p $(PP)

check-orig : ppm-to-fast
	@sglri -p $(TBL) -i testfile.f90.orig | $(TO_FAST) | ppm-to-fast | $(TO_PP) | ast2text -p $(PP)

check-fast :
	sglri -p $(TBL) -i testfile.f90 | $(TO_FAST) | pp-aterm

check-last : ppm-to-fast
	sglri -p $(TBL) -i testfile.f90 | $(TO_FAST) | ppm-to-fast | pp-aterm

check-lower : ppm-lower
	sglri -p $(TBL) -i testfile.f90 | $(TO_FAST) | ppm-lower | $(TO_PP) | ast2text -p $(PP)

clean :
	rm -f ppm-lower ppm-lower.c
	rm -f ppm-to-fast ppm-to-fast.c
	rm -f *.o *.lo *.dep
