## Add -m32 for 32 bit builds
#
ARCH = 

## Define paths to various stratego tools
#
SDF2_PATH = /opt/sdf2-bundle/v2.4/bin
ST_PATH = /opt/strategoxt/v0.17/bin
SGLRI = /opt/strategoxt/v0.17/bin/sglri

## Define extra flags for compiling strategies
#
#ST_CFLAGS = -Xcc $(ARCH)
#ST_LDFLAGS = -Xlinker $(ARCH)

## Turns off warning messages for clang compiler
#ST_CFLAGS += -Xcc -Wno-parentheses-equality

## parse table for parsing signature files
#
STRATEGO_TBL = /usr/local/packages/strategoxt-0.17/stratego-front/syn/StrategoStratego.tbl
