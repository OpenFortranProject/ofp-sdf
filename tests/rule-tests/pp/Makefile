SYNTAX_DIR = ../../../fortran/syntax
TRANS_DIR  = ../../../fortran/trans

TBL     = $(SYNTAX_DIR)/Fortran.tbl
TO_SIM  = $(TRANS_DIR)/ofp-simplify
TO_FAST = $(TRANS_DIR)/ofp2fast
TO_PP   = $(TRANS_DIR)/fast2pp
PP      = ../../../fortran/pp/Fortran.pp

all : check

$(TBL) :
	cd $(SYNTAX) ; make ; cd -

simple : $(TBL)
	@for file in *.f90 ; do \
           echo "Running test $$file"; \
	   sglri -p $(TBL) -i $$file | $(TO_SIM) | pp-aterm -o tmp-simple/$$file.aterm; \
        done;

fast : $(TBL)
	@for file in *.f90 ; do \
           echo "Running test $$file"; \
	   sglri -p $(TBL) -i $$file | $(TO_FAST) | pp-aterm -o tmp-fast/$$file.aterm; \
        done;

check : $(TBL)
	@for file in *.f90 ; do \
           echo "Running test $$file"; \
	   sglri -p $(TBL) -i $$file | $(TO_FAST) | $(TO_PP) | ast2text -p $(PP) -o tmp/$$file; \
           diff $$file tmp/$$file; \
           if test $$? != 0 ; then \
             echo $$file "		FAILED!"; \
           fi; \
           gfortran -c tmp/$$file -o tmp/$$file.o; \
           if test $$? != 0 ; then \
             echo $$file "		FAILED!"; \
           fi; \
        done;
	@for file in *.f77 ; do \
           echo "Running test $$file"; \
	   sglri -p $(TBL) -i $$file | $(TO_FAST) | $(TO_PP) | ast2text -p $(PP) -o tmp/$$file; \
           diff $$file tmp/$$file; \
           if test $$? != 0 ; then \
             echo $$file "		FAILED!"; \
           fi; \
        done;
	@for file in *.f08 ; do \
           echo "Running test $$file"; \
	   sglri -p $(TBL) -i $$file | $(TO_FAST) | $(TO_PP) | ast2text -p $(PP) -o tmp/$$file; \
           diff $$file tmp/$$file; \
           if test $$? != 0 ; then \
             echo $$file "		FAILED!"; \
           fi; \
        done;

junk :
	sglri -p $(TBL) -i junk.f90 | $(TO_FAST) | $(TO_PP) | ast2text -p $(PP)

clean :
	rm -f *.mod
	rm -f tmp/*.f90 tmp/*.f77 tmp/*.f08 tmp/*.o
	rm -f tmp-simple/*.aterm
	rm -f tmp-fast/*.aterm
