

all : FixedForm.tbl FreeForm.tbl

FixedForm.def : FixedForm.sdf
	pack-sdf -i $< -o $@

FixedForm.tbl : FixedForm.def
	sdf2table -i $< -o $@ -m FixedForm

FreeForm.def : FreeForm.sdf
	pack-sdf -i $< -o $@

FreeForm.tbl : FreeForm.def
	sdf2table -i $< -o $@ -m FreeForm

check : FixedForm.tbl
	sglri -p FixedForm.tbl -i testfile.til | pp-aterm

clean :
	rm -f *.def *.tbl
