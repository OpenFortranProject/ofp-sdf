all : check

# pretty-print the AST
#           pp-aterm -i $$file.ast -o $$file.acff; \

check :
	@for file in *.f90 ; do \
           echo "Running test $$file"; \
           sglri -p ../../syntax/Fortran.tbl -i $$file -o $$file.ast; \
           if test $$? != 0 ; then \
             echo $$file "		FAILED!"; \
           fi; \
           pp-aterm -i $$file.ast -o $$file.acff; \
        done;

junk :
	sglri -p ../../syntax/Fortran.tbl -i junk.f90 -o junk.f90.ast
	pp-aterm -i junk.f90.ast -o junk.f90.acff

clean :
	rm -f *.ast *.acff
	rm -f *.o *.mod
