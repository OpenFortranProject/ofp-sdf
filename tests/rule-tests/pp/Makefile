SYNTAX_DIR = ../../../fortran/syntax
TRANS_DIR  = ../../../fortran/trans

TBL    = $(SYNTAX_DIR)/Fortran.tbl
TO_AST = $(TRANS_DIR)/ofp2fast
TO_PP  = $(TRANS_DIR)/fast2pp
PP     = ../../../fortran/pp/Fortran.pp

all : check

$(TBL) :
	cd $(SYNTAX) ; make ; cd -

check : $(TBL)
	@for file in *.f90 ; do \
           echo "Running test $$file"; \
	   sglri -p $(TBL) -i $$file | $(TO_AST) | $(TO_PP) | ast2text -p $(PP) -o tmp/$$file; \
           diff $$file tmp/$$file; \
           if test $$? != 0 ; then \
             echo $$file "		FAILED!"; \
           fi; \
           gfortran -c tmp/$$file -o tmp/$$file.o; \
           if test $$? != 0 ; then \
             echo $$file "		FAILED!"; \
           fi; \
        done;

junk :
	sglri -p $(TBL) -i junk.f90 | $(TO_AST) | $(TO_PP) | ast2text -p $(PP)

clean :
	rm -f tmp/*.f90 tmp/*.o
