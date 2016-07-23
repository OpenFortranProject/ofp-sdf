include ../../../make.inc

CFLAGS = -I ../../syntax/lex $(ST_CFLAGS)
LDFLAGS = $(ST_LDFLAGS) -la stratego-lib


all : FixedForm.tbl FreeForm.tbl fixed-to-free

FixedForm.def : FixedForm.sdf
	pack-sdf -i $< -o $@

FixedForm.tbl : FixedForm.def
	sdf2table -i $< -o $@ -m FixedForm

FreeForm.def : FreeForm.sdf
	pack-sdf -i $< -o $@

FreeForm.tbl : FreeForm.def
	sdf2table -i $< -o $@ -m FreeForm

FixedForm.rtg : FixedForm.def
	$(ST_PATH)/sdf2rtg -i FixedForm.def -m FixedForm -o FixedForm.rtg

FixedForm.str : FixedForm.rtg
	$(ST_PATH)/rtg2sig -i FixedForm.rtg -o FixedForm.str

fixed-to-free : fixed-to-free.str
	$(ST_PATH)/strc -i fixed-to-free.str $(CFLAGS) $(LDFLAGS) --main io-fixed-to-free

check : FixedForm.tbl
	$(ST_PATH)/sglri -p FixedForm.tbl -i testfile.F | pp-aterm

check-free : FixedForm.tbl fixed-to-free
	$(ST_PATH)/sglri -i testfile.F -p FixedForm.tbl | ./fixed-to-free | pp-aterm

check-pp : FixedForm.tbl fixed-to-free
	@$(ST_PATH)/sglri -i testfile.F -p FixedForm.tbl | ./fixed-to-free | ast2text -p FreeForm.pp

clean :
	rm -f *.def *.tbl
	rm -f *.o fixed-to-free fixed-to-free.c fixed-to-free.lo fixed-to-free.dep
