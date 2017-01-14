OFP_HOME = /Users/rasmus/ofp-sdf
CESM_HOME = /usr/local/packages/cesm/cesm1_2_2
OUT_DIR = /Users/rasmus/ofp-tests/parser/CESM

include $(OFP_HOME)/make.inc

SYNTAX = $(OFP_HOME)/fortran/syntax
TRANS  = $(OFP_HOME)/fortran/trans

all : check
check : check-junk

check-junk : $(SYNTAX)/Fortran.tbl
	TEST_DIR=$(CESM_HOME)/models/atm/cam/src/advection/slt
	echo "test_dir is $(TEST_DIR)"
	$(SGLRI) -p $(SYNTAX)/Fortran.tbl -i $(TEST_DIR)/junk.f90 -o $(OUT_DIR)/junk.f90.ast

check-atm : $(SYNTAX)/Fortran.tbl
	echo "pwd is $(OUT_DIR)"
	for file in $(CESM_HOME)/models/atm/cam/src/advection/slt/*.f90 ; do \
           echo "Running test $$file"; \
           $(SGLRI) -p $(SYNTAX)/Fortran.tbl -i $$file -o $(OUT_DIR)/$$file.ast; \
           if test $$? != 0 ; then \
             echo $$file "		FAILED!"; \
           fi; \
           pp-aterm -i ./$$file.ast -o ./$$file.ast.trm; \
        done;

check-ofp : $(SYNTAX)/Fortran.tbl
	@for file in *.f90 ; do \
           echo "Running test $$file"; \
           $(SGLRI) -p $(SYNTAX)/Fortran.tbl -i $$file -o $$file.ast; \
           if test $$? != 0 ; then \
             echo $$file "		FAILED!"; \
           fi; \
           pp-aterm -i $$file.ast -o $$file.ast.trm; \
        done;

junk : $(SYNTAX)/Fortran.tbl  $(TRANS)/ofp-simplify
	$(SGLRI) -p $(SYNTAX)/Fortran.tbl -i junk.f90 | $(TRANS)/ofp-simplify | pp-aterm

clean :
	rm -f *.ast *.ast.trm
	rm -f *.o *.mod
