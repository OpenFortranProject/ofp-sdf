ATERM_ROOT = /usr/local/stratego-debug-32

# cc with Apple XCode uses clang which has unwelcome warning messages
#
CC  = gcc
CPC = g++

# -m32 flag used in antlr3 build (for XCode)
#
ARCH = -m32

CFLAGS = -g $(ARCH) -I. -I$(ATERM_ROOT)/include
LIBS = -L$(ATERM_ROOT)/lib -lATerm

OBJS = ofp_builder.o

TRAVERSE_OBJS = traversal.o ofp_traverse_productions.o OFPNodes.o

EXES = build_classes build_includes build_traversals \
       traverse traverse_sig check_cons_name

%.o: %.C
	@echo 'Compiling file: $<'
	@$(CPC) -c $(CFLAGS) -o $@ $<

%.o: %.c
	@echo 'Compiling file: $<'
	@$(CC) -c $(CFLAGS) -o $@ $<

all: $(OBJS) $(EXES)

traverse: traverse.o $(TRAVERSE_OBJS)
	$(CPC) -o $@ $(ARCH) $< $(TRAVERSE_OBJS) $(LIBS)

traverse_sig: traverse_sig.o traversal_f.o $(OBJS)
	$(CC) -o $@ $(ARCH) $< traversal_f.o $(OBJS) $(LIBS)

build_includes: build_includes.o traverse_sig.o $(OBJS)
	$(CC) -o $@ $(ARCH) $< traverse_sig.o $(OBJS) $(LIBS)

build_aliases: build_aliases.o traverse_sig.o $(OBJS)
	$(CC) -o $@ $(ARCH) $< traverse_sig.o $(OBJS) $(LIBS)

build_classes: build_classes.o traverse_sig.o $(OBJS)
	$(CC) -o $@ $(ARCH) $< traverse_sig.o $(OBJS) $(LIBS)

build_traversals: build_traversals.o traverse_sig.o $(OBJS)
	$(CC) -o $@ $(ARCH) $< traverse_sig.o $(OBJS) $(LIBS)

build_list_traversals: build_list_traversals.o traverse_sig.o $(OBJS)
	$(CC) -o $@ $(ARCH) $< traverse_sig.o $(OBJS) $(LIBS)

build_productions: build_productions.o traverse_sig.o $(OBJS)
	$(CC) -o $@ $(ARCH) $< traverse_sig.o $(OBJS) $(LIBS)

heck_cons_name: check_cons_name.o traverse_sig.o $(OBJS)
	$(CC) -o $@ $(ARCH) $< traverse_sig.o $(OBJS) $(LIBS)

support.o: support.c support.h
traversal.o: traversal.C traversal.h OFPNodes.h UntypedNodes.h
ofp_traverse_productions.o: ofp_traverse_productions.C traversal.h OFPNodes.h UntypedNodes.h
traversal_f.o: traversal_f.c traversal.h

check: traverse
	sglri -i testfile.f90 -p ../syntax/Fortran.tbl -o testfile.f90.aterm
	traverse testfile.f90.aterm

clean:
	rm -f *.o $(EXES) $(OBJS)
