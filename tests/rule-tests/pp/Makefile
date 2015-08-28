FC = ifort

SYNTAX_DIR = ../../../fortran/syntax
TRANS_DIR  = ../../../fortran/trans

TBL     = $(SYNTAX_DIR)/Fortran.tbl
TO_SIM  = $(TRANS_DIR)/ofp-simplify
TO_FAST = $(TRANS_DIR)/ofp2fast
TO_PP   = $(TRANS_DIR)/fast2pp
PP      = ../../../fortran/pp/Fortran.pp

CHECK_LIST = R1101a.f90 R1101b.f90 R1101c.f90 R1101d.f90 R1101e.f90 R1101f.f90 R1101g.f90\
             R404.f90 R426.fxx R452.f90 \
             R524.f90 R526.f90 \
             R611.f90 R620.f90 \
             R701.f90 R702.fxx R704.f90 R705.f90 R706.f90 R710.f90 R713.f90 R719.f90 \
             R720.f90 R721.f90 R722.fxx R723.fxx R733.fxx \
             R807.f90 R854.f90 \
             R1203.f90 R1206.f90 R1209.f90 R1210.f90 R1214.f90 R1218.f90 R1220.fxx \
             R1234.f90 R1237.fxx

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

check-all : $(TBL)
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
	rm -f *.mod
	rm -f tmp/*.f90 tmp/*.f77 tmp/*.f08 tmp/*.fxx tmp/*.o
	rm -f tmp-simple/*.aterm
	rm -f tmp-fast/*.aterm
