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
       traversal.o

all: traverse $(OBJS)

traverse.o: traverse.c
	$(CC) -c $< -o $@ $(CFLAGS)

traverse: traverse.o $(OBJS)
	$(CC) -o $@ $(ARCH) $(OBJS) $(LIBS)

support.o: support.c support.h

traversal.o: traversal.c traversal.h
	$(CC) -c $(CFLAGS) $<

check: traverse
	sglri -i testfile.f90 -p ../syntax/Fortran.tbl -o testfile.f90.aterm
	traverse testfile.f90.aterm

clean:
	rm -f *.o traverse $(OBJS)
	rm -f *.aterm
