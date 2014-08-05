#include elim-main-range.dep

CFLAGS = -I ../syntax -Xcc -m32 
CFLAGS += -Xcc -Wno-parentheses-equality
LDFLAGS = -Xlinker -m32 -la stratego-lib

all : ofp2fast fast2pp

ofp2fast : ofp2fast.str
	strc -i ofp2fast.str $(CFLAGS) $(LDFLAGS) --main io-ofp2fast

fast2pp : fast2pp.str
	strc -i fast2pp.str $(CFLAGS) $(LDFLAGS) --main io-fast2pp

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

check : ofp2fast
	sglri -i testfile.f90 -p ../syntax/Fortran.tbl | ofp2fast | pp-aterm

unparse : ofp2fast
	@echo "------------"
	@sglri -i testfile.f90 -p ../syntax/Fortran.tbl | ofp2fast | fast2pp | ast2text -p ../pp/Fortran.pp

test : ofp2fast
	sglri -i ../../tests/rule-tests-rose/R1101a.f90 -p ../syntax/Fortran.tbl | ofp2fast | pp-aterm

cafe : ofp2fast
	sglri -i cafe.f90 -p ../syntax/Fortran.tbl | ofp2fast | pp-aterm

rose : ofp-to-rose ofp2fast
	sglri -i testfile.f90 -p ../syntax/Fortran.tbl | ofp2fast | ofp-to-rose | pp-aterm

clean :
	rm -f ofp2fast ofp2fast.c ofp2fast.dep
	rm -f ofp-to-rose ofp-to-rose.c ofp-to-rose.dep
	rm -f *.o *.lo
