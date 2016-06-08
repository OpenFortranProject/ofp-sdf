FC = gfortran

SYNTAX_DIR = ../../../fortran/syntax
TRANS_DIR  = ../../../fortran/trans

TBL     = $(SYNTAX_DIR)/Fortran.tbl
TO_SIM  = $(TRANS_DIR)/ofp-simplify
TO_FAST = $(TRANS_DIR)/ofp2fast
TO_PP   = $(TRANS_DIR)/fast2pp
PP      = ../../../fortran/pp/Fortran.pp

CHECK_LIST = R432.f90

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

check-unparse : $(TBL)
	@for file in *.f90 ; do \
           echo "Running test $$file"; \
	   sglri -p $(TBL) -i $$file | $(TO_FAST) | $(TO_PP) | ast2text -p $(PP) -o tmp/$$file; \
           diff $$file tmp/$$file; \
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
	@for file in *.fxx ; do \
           echo "Running test $$file"; \
	   sglri -p $(TBL) -i $$file | $(TO_FAST) | $(TO_PP) | ast2text -p $(PP) -o tmp/$$file; \
           diff $$file tmp/$$file; \
           if test $$? != 0 ; then \
             echo $$file "		FAILED!"; \
           fi; \
        done;

check : $(TBL)
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
           $(FC) -c -fcoarray=single tmp/$$file -o tmp/$$file.o; \
           if test $$? != 0 ; then \
             echo $$file "		FAILED!"; \
           fi; \
        done;
	@for file in *.fxx ; do \
           echo "Running test $$file"; \
	   sglri -p $(TBL) -i $$file | $(TO_FAST) | $(TO_PP) | ast2text -p $(PP) -o tmp/$$file; \
           diff $$file tmp/$$file; \
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

check-f77 : $(TBL)
	@for file in *.f77 ; do \
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

check-f08 : $(TBL)
	@for file in *.f08 ; do \
           echo "Running test $$file"; \
	   sglri -p $(TBL) -i $$file | $(TO_FAST) | $(TO_PP) | ast2text -p $(PP) -o tmp/$$file; \
           diff $$file tmp/$$file; \
           if test $$? != 0 ; then \
             echo $$file "		FAILED!"; \
           fi; \
        done;

check-fxx : $(TBL)
	@for file in *.fxx ; do \
           echo "Running test $$file"; \
	   sglri -p $(TBL) -i $$file | $(TO_FAST) | $(TO_PP) | ast2text -p $(PP) -o tmp/$$file; \
           diff $$file tmp/$$file; \
           if test $$? != 0 ; then \
             echo $$file "		FAILED!"; \
           fi; \
        done;

check-list : $(TBL)
	@for file in $(CHECK_LIST) ; do \
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


test :
	sglri -p $(TBL) -i testfile.f90 | $(TO_FAST) | $(TO_PP) | ast2text -p $(PP)
check-fast :
	sglri -p $(TBL) -i testfile.f90 | $(TO_FAST) | pp-aterm
check-pp :
	sglri -p $(TBL) -i testfile.f90 | $(TO_FAST) | $(TO_PP) | pp-aterm

clean :
	rm -f *.mod *.o
	rm -f tmp/*.f90 tmp/*.f77 tmp/*.f08 tmp/*.fxx tmp/*.o
	rm -f tmp-simple/*.aterm
	rm -f tmp-fast/*.aterm
