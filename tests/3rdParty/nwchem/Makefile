OFP_HOME = /Users/rasmus/ofp-sdf
NWCHEM_HOME = /usr/local/packages/nwchem/nwchem-6.6

INC_DIR = $(HOME)/ofp-tests/parser/nwchem/include
NWCHEM_INCS = -I $(NWCHEM_HOME)/src/tools/install/include -I $(NWCHEM_HOME)/src/include
INCLUDES = $(NWCHEM_INCS)

include $(OFP_HOME)/make.inc

SYNTAX_DIR = $(OFP_HOME)/fortran/syntax
TRANS_DIR  = $(OFP_HOME)/fortran/trans
PP_DIR     = $(OFP_HOME)/fortran/pp

TBL     = $(SYNTAX_DIR)/Fortran.tbl
TBL_F   = $(SYNTAX_DIR)/FixedForm.tbl
TO_SIM  = $(TRANS_DIR)/ofp-simplify
TO_FAST = $(TRANS_DIR)/ofp2fast
TO_FREE = $(TRANS_DIR)/fixed-to-free
TO_PP   = $(TRANS_DIR)/fast2pp
PP      = $(PP_DIR)/Fortran.pp
F_PP    = $(PP_DIR)/FreeForm.pp

TEST_DIR = $(NWCHEM_HOME)
OUT_DIR = /Users/rasmus/ofp-tests/parser/nwchem

SYNTAX = $(OFP_HOME)/fortran/syntax
TRANS  = $(OFP_HOME)/fortran/trans

SRC_DIRS =                                               \
     src/analyz

DIRS = $(SRC_DIRS)

all : check

check :
	@for dir in $(DIRS) ; do \
           cd $(NWCHEM_HOME)/$$dir; \
           echo "\nRunning tests in $(NWCHEM_HOME)/$$dir"; \
           echo "-------------------------------------------\n"; \
           for file in *.F ; do \
             echo "Running test $$file"; \
             gfortran -cpp $(INCLUDES) -E $(NWCHEM_HOME)/$$dir/$$file > $(OUT_DIR)/$$file.f ; \
             if test $$? != 0 ; then \
               echo $$file "		FAILED!"; \
               exit -1 ; \
             fi; \
             $(SGLRI) -p $(TBL_F) -i $(OUT_DIR)/$$file.f | $(TO_FREE) | ast2text -p $(F_PP) -o $(OUT_DIR)/$$file.f90; \
             $(SGLRI) -p $(TBL) -i $(OUT_DIR)/$$file.f90 | $(TO_FAST) | $(TO_PP) | ast2text -p $(PP) -o $(OUT_DIR)/tmp/$$file.f90 ; \
           done; \
        done;



junk : $(SYNTAX)/Fortran.tbl  $(TRANS)/ofp-simplify
	$(SGLRI) -p $(SYNTAX)/Fortran.tbl -i junk.f90 | $(TRANS)/ofp-simplify | pp-aterm

clean :
	rm -f *.F.f *.F.f90 tmp/*.f90
	rm -f *.o *.mod
