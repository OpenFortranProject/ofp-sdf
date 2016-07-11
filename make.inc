OS = $(shell uname -s)

# Variables for OSX
ifeq '${OS}' 'Darwin'
     ## Add -m32 for 32 bit builds
     ARCH = -m32

     ## Define paths to various stratego tools
     SDF2_PATH = /opt/sdf2-bundle/v2.4/bin
     ST_PATH = /opt/strategoxt/v0.17/bin
     ATERM_PATH = /usr/local/stratego-debug-32

     ## Define extra flags for compiling strategies
     ST_CFLAGS = -Xcc $(ARCH)
     ST_LDFLAGS = -Xlinker $(ARCH)

     ## Turns off warning messages for clang compiler
     ST_CFLAGS += -Xcc -Wno-parentheses-equality

     ## parse table for parsing signature files
     STRATEGO_TBL = /usr/local/packages/strategoxt-0.17/stratego-front/syn/StrategoStratego.tbl
endif

# Variables for Linux
ifeq '$(OS)' 'Linux1'
     ## Define paths to various stratego tools
     SDF2_BIN_DIR=$(shell which sdf2table)
     SDF2_PATH=$(shell dirname ${SDF2_BIN_DIR})

     ST_BIN_DIR=$(shell which sglri)
     ST_PATH = $(shell dirname ${ST_BIN_DIR})

     ATERM_BIN_DIR=$(shell which baffle)
     ATERM_PATH=$(shell dirname ${ATERM_BIN_DIR})

     ## parse table for parsing signature files
     STRATEGO_TBL = ${ST_PATH}/share/sdf/stratego-front/
endif

SDF2_PATH=${HOME}/tstbuild64NEWPACKAGETEST/sdf2/bin/
ST_PATH=${HOME}/tstbuild64NEWPACKAGETEST/stratego/bin/
ATERM_PATH=${HOME}/tstbuild64NEWPACKAGETEST/aterm/bin/
SGLRI=${HOME}/tstbuild64NEWPACKAGETEST/stratego/bin/sglri
