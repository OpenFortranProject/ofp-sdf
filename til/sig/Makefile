%.tbl : %
	sdf2table -i $< -o $@

all : TIL.str

TIL.rtg : ../syn/TIL.def
	sdf2rtg -i $< -o $@ -m TIL

TIL.str : TIL.rtg
	rtg2sig -i $< -o $@

check : TIL.str

clean :
	rm -f *.rtg *.str
