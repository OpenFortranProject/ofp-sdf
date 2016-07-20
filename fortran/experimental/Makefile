include ../../make.inc

TEST_DIR = tests

SDF_FILES =  Fortran.sdf              \
             Fortran-layout.sdf       \
             Fortran-literals.sdf     \
             Fortran-expressions.sdf  \
             Fortran-statements.sdf   \
             Fortran-types.sdf        \
             Fortran-calls.sdf

Files = $(wildcard $(TEST_DIR)/*.f90)

all : Fortran.tbl Fortran.rtg Fortran.pp for-parenthesize.str

Fortran.tbl : Fortran.def
	$(SDF2_PATH)/sdf2table -i $< -o $@ -m Fortran

Fortran.def : $(SDF_FILES)
	$(ST_PATH)/pack-sdf -i $< -o $@

Fortran.rtg : Fortran.def
	$(ST_PATH)/sdf2rtg -i Fortran.def -o Fortran.rtg -m Fortran

## generate pretty-print table from syntax definition
Fortran.pp : Fortran.def
	$(ST_PATH)/ppgen -i $< -o $@

## generate program to insert parentheses
for-parenthesize.str : Fortran.def
	$(ST_PATH)/sdf2parenthesize -i $< -o $@ -m Fortran --lang Fortran

check : Fortran.tbl
	@for File in $(Files) ;\
           do \
              echo "   parsing $$File ..." ; \
              $(ST_PATH)/sglri -p Fortran.tbl -i $$File -o $$File.ast ; \
              $(ST_PATH)/pp-aterm -i $$File.ast -o $$File.pp ; \
           done

pipeline : Fortran.tbl Fortran.rtg
	$(ST_PATH)/sglri -p Fortran.tbl -i tests/test1.f90 -o tests/test1.ast
	$(ST_PATH)/pp-aterm -i tests/test1.ast -o tests/test1.af90
	$(ST_PATH)/format-check --rtg Fortran.rtg -i tests/test1.af90 -s Program > tests/test1.af90.fc

clean : 
	rm -f $(TEST_DIR)/*.ast $(TEST_DIR)/*.pp
	rm -f Fortran.def *.tbl *.rtg *.pp *.str
