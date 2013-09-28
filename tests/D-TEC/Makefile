SYNTAX = ../../fortran/syntax

all : check

$(SYNTAX)/Fortran.tbl :
	cd $(SYNTAX) ; make ; cd -

$(SYNTAX)/FortranFixed.tbl :
	cd $(SYNTAX) ; make ; cd -

check : $(SYNTAX)/Fortran.tbl $(SYNTAX)/FortranFixed.tbl
	@for file in *.f90 ; do \
           echo "Running test $$file"; \
           sglri -p $(SYNTAX)/Fortran.tbl -i $$file -o $$file.ast; \
           if test $$? != 0 ; then \
             echo $$file "		FAILED!"; \
           fi; \
        done;
	@for file in *.f ; do \
           echo "Running test $$file"; \
           sglri -p $(SYNTAX)/FortranFixed.tbl -i $$file -o $$file.ast; \
           if test $$? != 0 ; then \
             echo $$file "		FAILED!"; \
           fi; \
        done;

junk :
	sglri -p $(SYNTAX)/Fortran.tbl -i junk.f90 -o junk.f90.ast
	implode-asfix -i junk.f90.ast | pp-aterm

clean :
	rm -f *.ast *.ast.aterm
	rm -f *.o *.mod
