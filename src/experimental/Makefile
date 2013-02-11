## make with following:
#
#      make GRAMMAR=Fortran.def TEST=tests check
#

GRAMMAR  = Fortran.def
TEST_DIR = tests

Files = $(wildcard $(TEST_DIR)/*.f90)

%.tbl : %
	sdf2table -i $< -o $@

check : $(GRAMMAR).tbl
	@for File in $(Files) ;\
           do \
              sglr -v -p $(GRAMMAR).tbl -i $$File -o $$File.ast ; \
              pp-aterm -i $$File.ast -o $$File.acff ; \
           done

clean : 
	rm -f $(TEST_DIR)/*.ast $(TEST_DIR)/*.acff
	rm -f *.tbl
