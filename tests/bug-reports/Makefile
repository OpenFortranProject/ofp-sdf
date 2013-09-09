SYNTAX = ../../src/syntax

all : check

$(SYNTAX)/Fortran.tbl :
	cd $(SYNTAX) ; make ; cd -

check : $(SYNTAX)/Fortran.tbl
	@for file in *.f90 ; do \
           echo "Running test $$file"; \
           sglri -p $(SYNTAX)/Fortran.tbl -i $$file -o $$file.ast; \
           if test $$? != 0 ; then \
             echo $$file "		FAILED!"; \
           fi; \
           pp-aterm -i $$file.ast -o $$file.ast.aterm; \
        done;

junk :
	sglri -p $(SYNTAX)/Fortran.tbl -i junk.f90 -o junk.f90.ast
	pp-aterm -i junk.f90.ast -o junk.f90.aterm

clean :
	rm -f *.ast *.ast.aterm
	rm -f *.o *.mod
