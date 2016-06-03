include ../../make.inc

CFLAGS = -I ../../ROSE -I ../syntax $(ST_CFLAGS)
LDFLAGS = $(ST_LDFLAGS) -la stratego-lib

all : fixed-to-free ofp-simplify ofp2fast fast2pp strip-final-lf

fixed-to-free : fixed-to-free.str
	$(ST_PATH)/strc -i fixed-to-free.str $(CFLAGS) $(LDFLAGS) --main io-fixed-to-free

ofp-simplify : ofp-simplify.str
	$(ST_PATH)/strc -i ofp-simplify.str $(CFLAGS) $(LDFLAGS) --main io-ofp-simplify

ofp2fast : ofp2fast.str ofp-simplify ../syntax/FAST.str
	$(ST_PATH)/strc -i ofp2fast.str $(CFLAGS) $(LDFLAGS)

fast2pp : fast2pp.str
	$(ST_PATH)/strc -i fast2pp.str $(CFLAGS) $(LDFLAGS)

strip-final-lf : strip-final-lf.c
	$(CC) -o strip-final-lf strip-final-lf.c

# OBSOLETE
no-to-none : no-to-none.str
	$(ST_PATH)/strc -i no-to-none.str $(CFLAGS) $(LDFLAGS)

# OBSOLETE
fast2sage : fast2sage.str
	$(ST_PATH)/strc -i fast2sage.str $(CFLAGS) $(LDFLAGS)

# OBSOLETE
check-sage : fast2sage
	$(SGLRI) -i testfile.f90 -p ../syntax/Fortran.tbl | ./ofp2fast | ./fast2sage | pp-aterm

check : ofp-simplify ofp2fast
	$(SGLRI) -i testfile.f90 -p ../syntax/Fortran.tbl | ./ofp2fast | pp-aterm

check-ofp : ofp-simplify
	$(SGLRI) -i testfile.f90 -p ../syntax/Fortran.tbl | ./ofp-simplify | pp-aterm

check-pp : ofp-simplify ofp2fast fast2pp
	$(SGLRI) -i testfile.f90 -p ../syntax/Fortran.tbl | ./ofp2fast | ./fast2pp | pp-aterm

check-fixed :
	@$(SGLRI) -i testfile.for -p ../syntax/FixedForm.tbl | pp-aterm

check-ftf : fixed-to-free strip-final-lf
	@$(SGLRI) -i testfile.for -p ../syntax/FixedForm.tbl | ./fixed-to-free | ast2text -p ../pp/FreeForm.pp | strip-final-lf

check-ftf-ast : fixed-to-free strip-final-lf
	@$(SGLRI) -i testfile.for -p ../syntax/FixedForm.tbl | ./fixed-to-free | pp-aterm

unparse : ofp-simplify ofp2fast fast2pp
	@echo "------------"
	@$(SGLRI) -i testfile.f90 -p ../syntax/Fortran.tbl | ./ofp2fast | ./fast2pp | ast2text -p ../pp/Fortran.pp

test : ofp-simplify ofp2fast
	$(SGLRI) -i ../../tests/rule-tests-rose/R1101a.f90 -p ../syntax/Fortran.tbl | ./ofp2fast | pp-aterm

cafe : ofp-simplify ofp2fast
	$(SGLRI) -i cafe.f90 -p ../syntax/Fortran.tbl | ./ofp2fast | pp-aterm

clean :
	rm -f ofp2fast ofp2fast.c
	rm -f fixed-to-free fixed-to-free.c
	rm -f ofp-simplify ofp-simplify.c
	rm -f fast2pp fast2pp.c
	rm -f strip-final-lf
	rm -f *.o *.lo *.dep
