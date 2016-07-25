include ../../make.inc

all : test1.atil

test1.atil : ../syn/TIL.tbl test1.til
	$(ST_PATH)/sglri -p ../syn/TIL.tbl -i test1.til -o test1.atil

test1.atil.fc : ../syn/TIL.rtg test1.atil
	$(ST_PATH)/format-check --rtg ../syn/TIL.rtg -i test1.atil -s Program> test1.atil.fc

test1-wrong.atil.fc : ../syn/TIL.rtg test1-wrong.atil
	$(ST_PATH)/format-check --rtg ../syn/TIL.rtg -i test1-wrong.atil -s Program> test1-wrong.atil.fc

test1.txt1 : ../pp/TIL.pp test1.atil
	$(ST_PATH)/ast2text -p ../pp/TIL.pp -i test1.atil -o test1.txt1

test1.txt2 : ../pp/TIL.pp test1.atil
	$(ST_PATH)/ast2text -p ../pp/TIL-pretty.pp -i test1.atil -o test1.txt2

test1.atxt1 : ../syn/TIL.tbl test1.txt1
	$(ST_PATH)/sglri -p ../syn/TIL.tbl -i test1.txt1 | $(ST_PATH)/pp-aterm -o test1.atxt1

unparse : ../syn/TIL.tbl test1.atil
	$(ST_PATH)/ast2text -p ../pp/TIL.pp -i test1.atil

check : test1.atil test1.atxt1 test1.txt2 test1.atil.fc
	$(ST_PATH)/pp-aterm -i test1.atil -o test1.atil.pp
	diff test1.atxt1 test1.atil.pp

check-wrong : test1-wrong.atil.fc

clean :
	rm -f *.def *.tbl *.fc *.pp test1.atil test1.atxt1 test1.txt2
