SYNTAX = ../../../fortran/syntax
TBL    = $(SYNTAX)/Fortran.tbl
TRANS  = ../../../fortran/trans/ofp-simplify
PP     = ../../../fortran/pp/Fortran.pp

all : check

$(TBL) :
	cd $(SYNTAX) ; make ; cd -

check : $(TBL)
	@for file in *.f90 ; do \
           echo "Running test $$file"; \
	   sglri -p $(TBL) -i $$file | $(TRANS) | ast2text -p $(PP) -o tmp/$$file; \
           diff $$file tmp/$$file; \
           if test $$? != 0 ; then \
             echo $$file "		FAILED!"; \
           fi; \
           gfortran -c tmp/$$file -o tmp/$$file.o; \
           if test $$? != 0 ; then \
             echo $$file "		FAILED!"; \
           fi; \
        done;

clean :
	rm -f tmp/*.f90 tmp/*.o
