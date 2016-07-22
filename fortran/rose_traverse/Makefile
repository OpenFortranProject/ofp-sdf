include ../../make.inc

SDF_GRAMMAR_DIR = ../syntax

CC  = cc
CPC = c++

CLANG_ERROR_LIMIT = -ferror-limit=5

ERROR_LIMIT =

CFLAGS = $(ST_CFLAGS) -I ../syntax -I ../trans
LDFLAGS = $(ST_LDFLAGS) -la stratego-lib

#CFLAGS = -g $(ARCH) -I. -I$(ATERM_ROOT)/include $(ERROR_LIMIT)
#LIBS = -L$(ATERM_ROOT)/lib -lATerm

OBJS = ofp_builder.o

TRAVERSE_OBJS = UntypedNodes.o \
                OFPNodes.o OFPExpr.o OFPUnparser.o UntypedASTBuilder.o traversal.o ofp_traverse_productions.o

EXES = fast-to-rose build_classes build_includes build_traversals \
       traverse traverse_sig check_cons_name

%.o: %.cpp
	@echo 'Compiling file: $<'
	@$(CPC) -c $(CFLAGS) -o $@ $<

#all: $(OBJS) traverse

all : sg-const-folding

sg-const-folding : sg-const-folding.str
	$(ST_PATH)/strc -i sg-const-folding.str $(CFLAGS) $(LDFLAGS) --main io-sg-const-folding

fast-to-rose : fast-to-rose.str
	$(ST_PATH)/strc -i fast-to-rose.str $(CFLAGS) $(LDFLAGS) --main io-fast-to-rose

traverse: traverse.o $(TRAVERSE_OBJS)
	$(CPC) -o $@ $(ARCH) $< $(TRAVERSE_OBJS) $(LIBS)

traverse_sig: traverse_sig.o traversal_f.o $(OBJS)
	$(CC) -o $@ $(ARCH) $< traversal_f.o $(OBJS) $(LIBS)

build_includes: build_includes.o traverse_sig.o $(OBJS)
	$(CC) -o $@ $(ARCH) $< traverse_sig.o $(OBJS) $(LIBS)

build_classes: build_classes.o traverse_sig.o $(OBJS)
	$(CC) -o $@ $(ARCH) $< traverse_sig.o $(OBJS) $(LIBS)

build_traversals: build_traversals.o traverse_sig.o $(OBJS)
	$(CC) -o $@ $(ARCH) $< traverse_sig.o $(OBJS) $(LIBS)

build_list_traversals: build_list_traversals.o traverse_sig.o $(OBJS)
	$(CC) -o $@ $(ARCH) $< traverse_sig.o $(OBJS) $(LIBS)

build_productions: build_productions.o traverse_sig.o $(OBJS)
	$(CC) -o $@ $(ARCH) $< traverse_sig.o $(OBJS) $(LIBS)

check_cons_name: check_cons_name.o traverse_sig.o $(OBJS)
	$(CC) -o $@ $(ARCH) $< traverse_sig.o $(OBJS) $(LIBS)

support.o: support.c support.h
traversal.o: traversal.cpp traversal.hpp OFPNodes.hpp OFPExpr.hpp UntypedNodes.h ofp_traverse_productions.o OFPExpr.o \
             OFPUnparser.hpp OFPUnparser.cpp
ofp_traverse_productions.o: ofp_traverse_productions.cpp traversal.hpp OFPNodes.hpp UntypedNodes.h
OFPExpr.o: OFPExpr.cpp OFPExpr.hpp UntypedNodes.h
OFPNodes.o: OFPNodes.cpp traversal.hpp
OFPUnparser.o: OFPUnparser.cpp OFPUnparser.hpp
traversal_f.o: traversal_f.c traversal.hpp

check : fast-to-rose
	fast-to-rose -i testfile.f90.aterm | pp-aterm

check_traverse: traverse
	$(ST_PATH)/sglri -i testfile.f90 -p $(SDF_GRAMMAR_DIR)/Fortran.tbl | ../trans/ofp-simplify  -o testfile.f90.aterm
	traverse -i testfile.f90.aterm

clean:
	rm -f *.o fast-to-rose $(EXES) $(OBJS)
