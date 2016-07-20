include ../../make.inc

%.tbl : %
	$(SDF2_PATH)/sdf2table -i $< -o $@

all : TIL.str

TIL.rtg : ../syn/TIL.def
	$(ST_PATH)/sdf2rtg -i $< -o $@ -m TIL

TIL.str : TIL.rtg
	$(ST_PATH)/rtg2sig -i $< -o $@

check : TIL.str

clean :
	rm -f *.rtg *.str
