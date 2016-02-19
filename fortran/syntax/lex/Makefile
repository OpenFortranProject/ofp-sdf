TEST_DIR = ../xmpl

STRATEGO_TBL = /usr/local/packages/strategoxt-0.17/stratego-front/syn/StrategoStratego.tbl

SDF_FILES =  TIL-layout.sdf           \
             TIL-literals.sdf         \
             TIL-expressions.sdf      \
             TIL-statements.sdf       \
             TIL-calls.sdf            \
             TIL.sdf

%.tbl : %
	sdf2table -i $< -o $@

all : TIL.tbl

TIL.def : TIL.sdf
	pack-sdf -i $< -o $@

TIL.tbl : TIL.def
	sdf2table -i $< -o $@ -m TIL

TIL.rtg : TIL.def
	sdf2rtg -i $< -o $@ -m TIL

TIL.str : TIL.rtg
	rtg2sig -i $< -o $@

check : TIL.tbl
	sglri -p TIL.tbl -i testfile.til | pp-aterm

pretty : TIL.tbl
	sglri -p TIL.tbl -i $(TEST_DIR)/test1.til | pp-aterm

clean :
	rm -f *.def *.tbl
