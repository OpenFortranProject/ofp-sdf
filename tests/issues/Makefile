FC = gfortran

SYNTAX_DIR = ../../fortran/syntax
TRANS_DIR  = ../../fortran/trans

TBL     = $(SYNTAX_DIR)/Fortran.tbl
TBL_F   = $(SYNTAX_DIR)/FixedForm.tbl
TO_SIM  = $(TRANS_DIR)/ofp-simplify
TO_FAST = $(TRANS_DIR)/ofp2fast
TO_FREE = $(TRANS_DIR)/fixed-to-free
TO_PP   = $(TRANS_DIR)/fast2pp
PP      = ../../fortran/pp/Fortran.pp
PP_F    = ../../fortran/pp/FreeForm.pp

all : check

check : $(TBL)
	@for file in *.f90 ; do \
           echo "Running test $$file"; \
	   sglri -p $(TBL) -i $$file | $(TO_FAST) | $(TO_PP) | ast2text -p $(PP) -o tmp/$$file; \
           diff $$file tmp/$$file; \
           if test $$? != 0 ; then \
             echo $$file "		FAILED!"; \
           fi; \
        done;
	@for file in *.f90.no-diff ; do \
           echo "Running test $$file"; \
	   sglri -p $(TBL) -i $$file | $(TO_FAST) | $(TO_PP) | ast2text -p $(PP) -o tmp/$$file.f90; \
           if test $$? != 0 ; then \
             echo $$file "		FAILED!"; \
           fi; \
        done;
	@for file in *.for.no-diff ; do \
           echo "Running test $$file"; \
	   sglri -p $(TBL_F) -i $$file | $(TO_FREE) | ast2text -p $(PP_F) | sglri -p $(TBL) | $(TO_FAST) | $(TO_PP) | ast2text -p $(PP) -o tmp/$$file.f90; \
           if test $$? != 0 ; then \
             echo $$file "		FAILED!"; \
           fi; \
        done;

check-f90 : $(TBL)
	@for file in *.f90 ; do \
           echo "Running test $$file"; \
	   sglri -p $(TBL) -i $$file | $(TO_FAST) | $(TO_PP) | ast2text -p $(PP) -o tmp/$$file; \
           diff $$file tmp/$$file; \
           if test $$? != 0 ; then \
             echo $$file "		FAILED!"; \
           fi; \
           $(FC) -c tmp/$$file -o tmp/$$file.o; \
           if test $$? != 0 ; then \
             echo $$file "		FAILED!"; \
           fi; \
        done;

clean :
	rm -f *.mod *.o
	rm -f tmp/*.f90 tmp/*.f77 tmp/*.f08 tmp/*.fxx tmp/*.o
	rm -f tmp-simple/*.aterm
	rm -f tmp-fast/*.aterm
