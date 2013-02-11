TEST_DIR = ../../tests/rule-tests

TestFiles = $(wildcard $(TEST_DIR)/*.f90)
ASTFiles  = $(wildcard $(TEST_DIR)/*.f90.ast)

%.tbl : %
	sdf2table -i $< -o $@

all : Fortran.tbl

Fortran.def : Fortran.sdf
	pack-sdf -i $< -o $@

Fortran.tbl : Fortran.def
	sdf2table -i $< -o $@ -m Fortran

check : Fortran.tbl
	@for File in $(TestFiles) ;\
           do \
              sglr -v -p Fortran.tbl -i $$File -o $$File.ast ; \
           done

pretty : Fortran.tbl
	@for File in $(ASTFiles) ;\
           do \
              echo "Pretty printing $$File..." ; \
              pp-aterm -i $$File -o $$File.pp ; \
           done

clean :
	rm -f *.def *.tbl
	rm -f *.ast *.pp
	rm -f *.o *.mod
	rm -f $(TEST_DIR)/*.ast $(TEST_DIR)/*.ast.pp
