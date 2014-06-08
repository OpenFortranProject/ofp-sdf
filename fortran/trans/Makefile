#include elim-main-range.dep

CFLAGS = -Xcc -m32 -I ../syntax
LDFLAGS = -Xlinker -m32 -la stratego-lib

all : ofp-simplify

ofp-simplify : ofp-simplify.str
	strc -i ofp-simplify.str $(CFLAGS) $(LDFLAGS) --main io-ofp-simplify

ofp-to-rose : ofp-to-rose.str
	strc -i ofp-to-rose.str $(CFLAGS) $(LDFLAGS) --main io-ofp-to-rose

generate : generate.str
	strc -i generate.str $(CFLAGS) $(LDFLAGS)

term-to-python : term-to-python.str
	strc -i term-to-python.str $(CFLAGS) $(LDFLAGS)

term-to-adot : term-to-adot.str
	strc -i term-to-adot.str $(CFLAGS) $(LDFLAGS)

elim-main-range : elim-main-range.str
	strc --main elim-main-range -i elim-main-range.str $(CFLAGS) $(LDFLAGS)

check : ofp-simplify
	sglri -i testfile.f90 -p ../syntax/Fortran.tbl | ofp-simplify | pp-aterm

unparse : ofp-simplify
	@echo "------------"
	@sglri -i testfile.f90 -p ../syntax/Fortran.tbl | ofp-simplify | pp-aterm | ast2text -p ../pp/Fortran.pp

test : ofp-simplify
	sglri -i ../../tests/rule-tests-rose/R1101a.f90 -p ../syntax/Fortran.tbl | ofp-simplify | pp-aterm

rose : ofp-to-rose ofp-simplify
	sglri -i testfile.f90 -p ../syntax/Fortran.tbl | ofp-simplify | ofp-to-rose | pp-aterm

clean :
	rm -f ofp-simplify ofp-simplify.c ofp-simplify.dep
	rm -f ofp-to-rose ofp-to-rose.c ofp-to-rose.dep
	rm -f *.o *.lo
