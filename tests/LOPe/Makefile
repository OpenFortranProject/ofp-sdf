SYNTAX_DIR = ../../LOPe/syntax
TRANS_DIR  = ../../fortran/trans
PP_DIR     = ../../fortran/pp

TBL     = $(SYNTAX_DIR)/LOPe.tbl
TO_SIM  = $(TRANS_DIR)/ofp-simplify
TO_FAST = $(TRANS_DIR)/ofp2fast
TO_PP   = $(TRANS_DIR)/fast2pp
PP      = $(PP_DIR)/Fortran.pp

all : check

$(SYNTAX)/Fortran.tbl :
	cd $(SYNTAX) ; make ; cd -

check : $(TBL) $(TO_FAST) $(TO_PP) $(PP)
	sglri -p $(TBL) -i testfile.f90 | $(TO_FAST) | $(TO_PP) | ast2text -p $(PP)

clean :
	rm -f *.ast *.ast.aterm
	rm -f *.o *.mod
