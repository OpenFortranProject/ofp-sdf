include ../../../make.inc

SYNTAX = ../../syntax

all : check

$(SYNTAX)/Fortran.tbl :
	cd $(SYNTAX) ; make ; cd -

check : $(SYNTAX)/Fortran.tbl
	@for file in *.f90 ; do \
           echo "Running test $$file"; \
           $(ST_PATH)/sglri -p $(SYNTAX)/Fortran.tbl -i $$file -o $$file.aterm; \
           if test $$? != 0 ; then \
             echo $$file "		FAILED!"; \
           fi; \
           ../traverse -i $$file.aterm -o ofp_$$file; \
        done;

clean :
	rm -f *.aterm ofp_*.f90 *.o *.mod
