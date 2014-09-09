## Define paths to various stratego tools
#
SDF2_PATH = /opt/sdf2-bundle/v2.4/bin
ST_PATH = /opt/strategoxt/v0.17/bin

## Define extra flags for compiling strategies
#
ST_CFLAGS = -Xcc -m32
ST_LDFLAGS = -Xlinker -m32

## Turns off warning messages for clang compiler
# ST_CFLAGS += -Xcc -Wno-parentheses-equality

## parse table for parsing signature files
#
STRATEGO_TBL = /usr/local/packages/strategoxt-0.17/stratego-front/syn/StrategoStratego.tbl
