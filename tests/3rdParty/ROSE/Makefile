OFP_HOME=/Users/rasmus/ofp-sdf

include $(OFP_HOME)/make.inc

SYNTAX = $(OFP_HOME)/fortran/syntax
TRANS  = $(OFP_HOME)/fortran/trans

all : check

$(SYNTAX)/Fortran.tbl :
	cd $(SYNTAX) ; make ; cd -

check : $(SYNTAX)/Fortran.tbl
	@for file in *.f90 ; do \
           echo "Running test $$file"; \
           $(SGLRI) -p $(SYNTAX)/Fortran.tbl -i $$file -o $$file.ast; \
           if test $$? != 0 ; then \
             echo $$file "		FAILED!"; \
           fi; \
           pp-aterm -i $$file.ast -o $$file.ast.trm; \
           if test $$? != 0 ; then \
             echo $$file "    unparsing FAILED!"; \
           fi; \
        done;

junk : $(SYNTAX)/Fortran.tbl  $(TRANS)/ofp-simplify
	$(SGLRI) -p $(SYNTAX)/Fortran.tbl -i junk.f90 | $(TRANS)/ofp-simplify | pp-aterm

clean :
	rm -f *.ast *.ast.trm
	rm -f *.o *.mod
