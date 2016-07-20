include ../../make.inc

TEST_DIR = ../xmpl

STRATEGO_TBL = /usr/local/packages/strategoxt-0.17/stratego-front/syn/StrategoStratego.tbl

SDF_FILES =  TIL-layout.sdf           \
             TIL-literals.sdf         \
             TIL-expressions.sdf      \
             TIL-statements.sdf       \
             TIL-calls.sdf            \
             TIL.sdf

%.tbl : %
	$(SDF2_PATH)/sdf2table -i $< -o $@

all : TIL.tbl

TIL.def : TIL.sdf
	$(ST_PATH)/pack-sdf -i $< -o $@

TIL.tbl : TIL.def
	$(SDF2_PATH)/sdf2table -i $< -o $@ -m TIL

TIL.rtg : TIL.def
	$(ST_PATH)/sdf2rtg -i $< -o $@ -m TIL

TIL.str : TIL.rtg
	$(ST_PATH)/rtg2sig -i $< -o $@

check : TIL.tbl
	$(ST_PATH)/sglri -p TIL.tbl -i ../xmpl/test1.til

pretty : TIL.tbl
	$(ST_PATH)/sglri -p TIL.tbl -i $(TEST_DIR)/test1.til | $(ST_PATH)/pp-aterm

clean :
	rm -f *.def *.tbl
