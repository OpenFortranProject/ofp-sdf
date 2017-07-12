## Add -m32 for 32 bit builds
#
ARCH = -m32

## Define paths to various stratego tools
#
SDF2_PATH = /opt/sdf2-bundle/v2.4/bin
ST_PATH = /opt/strategoxt/v0.17/bin
#ATERM_ROOT = /usr/local/stratego-debug-32
ATERM_ROOT = /opt/aterm/v2.5
SGLRI = $(ST_PATH)/sglri

## Define extra flags for compiling strategies
#
ST_CFLAGS = -Xcc $(ARCH)
ST_LDFLAGS = -Xlinker $(ARCH)

## Turns off warning messages for clang compiler
ST_CFLAGS += -Xcc -Wno-parentheses-equality

## parse table for parsing signature files
#
STRATEGO_TBL = /usr/local/packages/strategoxt-0.17/stratego-front/syn/StrategoStratego.tbl
