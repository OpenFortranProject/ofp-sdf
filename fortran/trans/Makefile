CFLAGS = -I ../syntax
LDFLAGS = -la stratego-lib

## add these flags for the clang compiler (Mac OS X)
#CFLAGS  += -Xcc -m32 -Xcc -Wno-parentheses-equality
#LDFLAGS += -Xlinker -m32 -la stratego-lib

all : ofp-simplify ofp2fast fast2pp no-to-none

ofp-simplify : ofp-simplify.str
	strc -i ofp-simplify.str $(CFLAGS) $(LDFLAGS) --main io-ofp-simplify

no-to-none : no-to-none.str
	strc -i no-to-none.str $(CFLAGS) $(LDFLAGS)

ofp2fast : ofp2fast.str ofp-simplify no-to-none
	strc -i ofp2fast.str $(CFLAGS) $(LDFLAGS)

fast2pp : fast2pp.str no-to-none
	strc -i fast2pp.str $(CFLAGS) $(LDFLAGS)

check : ofp-simplify ofp2fast
	sglri -i testfile.f90 -p ../syntax/Fortran.tbl | ofp2fast | pp-aterm

unparse : ofp-simplify ofp2fast
	@echo "------------"
	@sglri -i testfile.f90 -p ../syntax/Fortran.tbl | ofp2fast | fast2pp | ast2text -p ../pp/Fortran.pp

test : ofp-simplify ofp2fast
	sglri -i ../../tests/rule-tests-rose/R1101a.f90 -p ../syntax/Fortran.tbl | ofp2fast | pp-aterm

cafe : ofp-simplify ofp2fast
	sglri -i cafe.f90 -p ../syntax/Fortran.tbl | ofp2fast | pp-aterm

clean :
	rm -f ofp2fast ofp2fast.c
	rm -f ofp-simplify ofp-simplify.c
	rm -f fast2pp fast2pp.c
	rm -f *.o *.lo *.dep
