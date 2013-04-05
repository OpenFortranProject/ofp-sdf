include elim-main-range.dep

CFLAGS = -Xcc -m32
LDFLAGS = -Xlinker -m32 -la stratego-lib

all : elim-main-range

elim-main-range : elim-main-range.str
	strc -i elim-main-range.str $(CFLAGS) $(LDFLAGS)

check :
	sglri -i junk.f90 -p ../syntax/Fortran.tbl | implode-asfix | elim-main-range | pp-aterm

clean :
	rm elim-main-range
	rm -f *.o *.lo
	rm -rf .libs