ofp-sdf
=======

SDF grammar and tests for Fortran 2008.

Directories

   fortran/experimental  -  sandbox to explore Fortran SDF grammar productions
   fortran/syntax        -  complete syntax specification for Fortran 2008
   
   tests/                -  directories for testing Fortran parser
   tests/rule-tests      -  tests of the original Fortran 2003 syntax rules
   tests/rule-f08-tests  -  tests of 2008 rule additions and modifications


Steps to use OFP:
-----------------

1. Edit $(OFP_HOME)/make.inc so that your paths to the stratego tools to reflect your installation
2. cd $(OFP_HOME)/fortran/syntax; make
3. cd $(OFP_HOME)/fortran/trans; make


You can then test the parser on the file, testfile.f90, by:

    cd $(OFP_HOME)/fortran/trans
    make check                      # this produces a Fortran Abstract Syntax Tree (AST) as an ATerm
    make unparse                    # this unparses the Fortran AST
