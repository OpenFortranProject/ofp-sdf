include elim-main-range.dep

CFLAGS = -Xcc -m32
LDFLAGS = -Xlinker -m32 -la stratego-lib

all : elim-main-range

generate : generate.str
	strc -i generate.str $(CFLAGS) $(LDFLAGS)

term-to-python : term-to-python.str
	strc -i term-to-python.str $(CFLAGS) $(LDFLAGS)

term-to-adot : term-to-adot.str
	strc -i term-to-adot.str $(CFLAGS) $(LDFLAGS)

elim-main-range : elim-main-range.str
	strc --main elim-main-range -i elim-main-range.str $(CFLAGS) $(LDFLAGS)

check :
	sglri -i junk.f90 -p ../syntax/Fortran.tbl | implode-asfix | elim-main-range | pp-aterm

clean :
	rm elim-main-range
	rm -f *.o *.lo
	rm -rf .libs