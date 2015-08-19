SYNTAX_DIR = ../../../fortran/syntax
TRANS_DIR  = ../../../fortran/trans

TBL     = $(SYNTAX_DIR)/Fortran.tbl
TO_FAST = $(TRANS_DIR)/ofp2fast
TO_SAGE = $(TRANS_DIR)/fast2sage

CHECK_LIST = R1101a.f90

all : check

$(TBL) :
	cd $(SYNTAX) ; make ; cd -

check : $(TBL)
	@for file in $(CHECK_LIST) ; do \
           echo "Running test $$file"; \
	   sglri -p $(TBL) -i ../pp/$$file | $(TO_FAST) | $(TO_SAGE) -o tmp/$$file.aterm; \
           diff sage-terms/$$file.aterm tmp/$$file.aterm; \
           if test $$? != 0 ; then \
             echo $$file "		FAILED!"; \
           fi; \
        done;

clean :
	rm -f tmp/*.aterm
