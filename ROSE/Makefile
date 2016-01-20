include ../make.inc

CC  = cc
CPC = c++

CLANG_ERROR_LIMIT = -ferror-limit=5


CFLAGS = -g -m32 -I/opt/aterm/v2.5/include
LDFLAGS = -m32

LIBS = -L$(ATERM_ROOT)/lib -lATerm


all : SgUntyped.str sage2pp sage-to-traverse traverse

traverse : traverse_main.o traverse_SgUntypedNodes.o SgUntypedNodes.o
	c++ -o traverse $(LDFLAGS) traverse_main.o traverse_SgUntypedNodes.o SgUntypedNodes.o $(LIBS)

traverse_main.o : traverse_main.cpp SgUntypedNodes.hpp
	c++ -c traverse_main.cpp $(CFLAGS)

traverse_SgUntypedNodes.o : traverse_SgUntypedNodes.cpp SgUntypedNodes.hpp
	c++ -c traverse_SgUntypedNodes.cpp $(CFLAGS)

SgUntypedNodes.o : SgUntypedNodes.cpp SgUntypedNodes.hpp
	c++ -c SgUntypedNodes.cpp $(CFLAGS)

SgUntyped.str : SgUntyped.rtg
	rtg2sig -i SgUntyped.rtg -o SgUntyped.str

SgUntyped.rtg.aterm : SgUntyped.rtg
	parse-rtg -i SgUntyped.rtg | pp-aterm -o SgUntyped.rtg.aterm

pp : SageRTG.pp SgUntyped.rtg.aterm
	ast2text -p SageRTG.pp -i SgUntyped.rtg.aterm

sage2pp : sage2pp.str
	$(ST_PATH)/strc -i sage2pp.str $(ST_CFLAGS) $(ST_LDFLAGS) -la stratego-lib

sage-to-traverse : sage-to-traverse.str
	$(ST_PATH)/strc -i sage-to-traverse.str $(ST_CFLAGS) $(ST_LDFLAGS) -la stratego-lib

check : sage-to-traverse
	sage-to-traverse -i SgUntyped.rtg.aterm | pp-aterm

check-pp : sage-to-traverse SgUntyped.rtg.aterm
	@sage-to-traverse -i SgUntyped.rtg.aterm | ast2text -p sage_traverse.pp

check-pp-header : sage-to-traverse SgUntyped.rtg.aterm
	@sage-to-traverse -i SgUntyped.rtg.aterm | ast2text -p sage_traverse_header.pp

check-traverse : sage2pp
	@sage2pp -i SgUntyped.rtg.aterm | ast2text -p sage_traverse.pp

check-traversal: traverse
	traverse -i testfile.f90.aterm

clean :
	rm -f traverse sage-to-traverse
	rm -f sage-traverse sage-to-traverse.c
	rm -f sage2pp sage2pp.c
	rm -f *.o *.dep *.lo
