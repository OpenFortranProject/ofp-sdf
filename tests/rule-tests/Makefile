include ../../make.inc

SYNTAX = ../../fortran/syntax
TRANS  = ../../fortran/trans

all : check

$(SYNTAX)/Fortran.tbl :
	cd $(SYNTAX) ; make ; cd -

check : $(SYNTAX)/Fortran.tbl
	@for file in *.f90 ; do \
           echo "Running test $$file"; \
           $(SGLRI) -p $(SYNTAX)/Fortran.tbl -i $$file -o $$file.ast; \
           if test $$? != 0 ; then \
             echo $$file "		Parsing FAILED!"; \
           fi; \
           pp-aterm -i $$file.ast -o $$file.ast.trm; \
           diff $$file.ast.trm ast-aterms/$$file.ast.trm; \
           if test $$? != 0 ; then \
             echo $$file "		FAILED!"; \
             exit 1; \
           fi; \
           $(TRANS)/ofp2fast -i $$file.ast | pp-aterm -o $$file.fast.trm; \
           diff $$file.fast.trm ast-aterms/$$file.fast.trm; \
           if test $$? != 0 ; then \
             echo $$file "		FAST FAILED!"; \
             exit 1; \
           fi; \
        done;

junk : $(SYNTAX)/Fortran.tbl  $(TRANS)/ofp-simplify
	$(SGLRI) -p $(SYNTAX)/Fortran.tbl -i junk.f90 | $(TRANS)/ofp-simplify | pp-aterm

clean :
	rm -f *.ast *.ast.trm
	rm -f *.o *.mod
