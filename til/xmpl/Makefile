all : test1.atil

test1.atil : ../syn/TIL.tbl test1.til
	sglri -p ../syn/TIL.tbl -i test1.til -o test1.atil

test1.atil.fc : ../syn/TIL.rtg test1.atil
	format-check --rtg ../syn/TIL.rtg -i test1.atil -s Program> test1.atil.fc

test1-wrong.atil.fc : ../syn/TIL.rtg test1-wrong.atil
	format-check --rtg ../syn/TIL.rtg -i test1-wrong.atil -s Program> test1-wrong.atil.fc

test1.txt1 : ../pp/TIL.pp test1.atil
	ast2text -p ../pp/TIL.pp -i test1.atil -o test1.txt1

test1.txt2 : ../pp/TIL.pp test1.atil
	ast2text -p ../pp/TIL-pretty.pp -i test1.atil -o test1.txt2

test1.atxt1 : ../syn/TIL.tbl test1.txt1
	sglri -p ../syn/TIL.tbl -i test1.txt1 | pp-aterm -o test1.atxt1

unparse : ../syn/TIL.tbl test1.atil
	ast2text -p ../pp/TIL.pp -i test1.atil

check : test1.atil test1.atxt1 test1.txt2 test1.atil.fc
	pp-aterm -i test1.atil -o test1.atil.pp
	diff test1.atxt1 test1.atil.pp

check-wrong : test1-wrong.atil.fc

clean :
	rm -f *.def *.tbl *.fc *.pp test1.atil test1.atxt1 test1.txt2
