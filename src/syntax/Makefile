TEST_DIR = ../../tests/rule-tests

TestFiles = $(wildcard $(TEST_DIR)/*.f90)

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
              pp-aterm -i $$File.ast -o $$File.acff ; \
           done

clean :
	rm -f *.def *.tbl
	rm -f *.ast *.acff
	rm -f *.o *.mod
