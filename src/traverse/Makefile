ATERM_ROOT = /usr/local/stratego-debug-32

# cc with Apple XCode uses clang which has unwelcome warning messages
#
CC = gcc

# -m32 flag used in antlr3 build (for XCode)
#
ARCH = -m32

CFLAGS = -g $(ARCH) -I. -I$(ATERM_ROOT)/include
LIBS = -L$(ATERM_ROOT)/lib -lATerm

OBJS = traverse.o      \
       traversal.o     \
       traverse_f.o    \
       traversal_f.o

EXES = traverse traverse_f

all: $(EXES) $(OBJS)

traverse.o: traverse.c
	$(CC) -c $< -o $@ $(CFLAGS)

traverse_f.o: traverse_f.c
	$(CC) -c $< -o $@ $(CFLAGS)

traverse: traverse.o $(OBJS)
	$(CC) -o $@ $(ARCH) $< traversal.o $(LIBS)

traverse_f: traverse_f.o $(OBJS)
	$(CC) -o $@ $(ARCH) $< traversal_f.o $(LIBS)

support.o: support.c support.h

traversal.o: traversal.c traversal.h ofp_traverse_productions.c
	$(CC) -c $(CFLAGS) $<

traversal_f.o: traversal_f.c traversal_f.h
	$(CC) -c $(CFLAGS) $<

check: traverse traverse_f
	traverse_f Fortran.f90.aterm
	sglri -i testfile.f90 -p ../syntax/Fortran.tbl -o testfile.f90.aterm
	traverse testfile.f90.aterm

clean:
	rm -f *.o $(EXES) $(OBJS)
