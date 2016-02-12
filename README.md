[This document is formatted with GitHub-Flavored Markdown.                      ]:#
[For better viewing, including hyperlinks, read it online at                    ]:#
[https://github.com/openfortranproject/ofp-sdf/blob/master/README.md]:#

#                Open Fortran Parser (OFP)               #
####              1.0.0 release candidate             ####
 
## Contents                                                               
* [Overview]
* [Installing OFP]
* [Documentation]
* [Getting Started]
* [Getting Help]
* [Directories]

## <a name="overview">Overview</a> ##

The Open Fortran Parser (OFP) project provides a Fortran 2008 compliant
parser and associated tools.  These tools provide an API for
actions that are called when parser rules are completed.  These actions
allow a parser user to build a custom Abstract Syntax Tree ([AST]).

If you need access to a complete source-to-source Fortran compiler
infrastructure incorporating OFP, please consider using [ROSE].
If you are specifically interested in coarray Fortran (CAF), please consider 
using the experimental support under development in [OpenCoarrays] for
for transforming CAF programs to extend the features of existing CAF compilers
as well as to support compilation with non-CAF compilers.

The OFP parser is based on the Syntax Definition Formalism [SDF2] used by [Stratego/XT].

## <a name="installing-ofp">Installing OFP</a>  ##

  - See the [INSTALL] file.

## <a name="documentation">Documentation</a>   ##

  - TBA 

## <a name="getting-started">Getting Started</a> ##

  - Ensure that the sglri is in your PATH
  - Build a parse table
```bash
  cd ofp-sdf/fortran/syntax
  make
  cd ../trans
  make
```
  - Run the tests, for example:
```bash
  cd ofp-sdf/tests
  make
``` 
## <a name="getting-help">Getting Help</a> ##

  - Please submit problem reports or feature requests via our [Issues] page.
  - Please send questions to fortran-parser-devel@lists.sourceforge.net.

## <a name="git-repository">git Repository</a>  ##

  - The public is free to clone the most recent copy of the [OFP] git repository
    repository and experiment with the tools.  To submit changes,
    please fork the repository; create a branch based on the master branch of your fork;
    add your suggested feature or bug fix on the new branch; and submit a pull request 
    against [OFP]

## <a name="directories">Directories</a>   ##

* [fortran/experimental]  
  -  sandbox to explore Fortran SDF grammar productions
* [fortran/syntax]        
  -  complete syntax specification for Fortran 2008
* [tests]                
  -  directories for testing Fortran parser
* [tests/rule-tests]      
  -  tests of the original Fortran 2003 syntax rules
* [tests/f08-tests]  
  -  tests of 2008 rule additions and modifications



[Hyperlinks]:#

[Contents]:#
[Overview]: #overview
[Installing OFP]: #installing-ofp
[Documentation]: #documentation
[Getting Started]: #getting-started
[Getting Help]: #getting-help
[Directories]: #directories


[Relative links]:#
[INSTALL]: ./INSTALL
[src]: ./src
[build]: ./build
[tests]: ./tests
[fortran/experimental]: ./fortran/experimental
[fortran/syntax]: ./fortran/syntax       
[tests]: ./tests               
[tests/rule-tests]: ./tests/rule-tests     
[tests/f08-tests]: ./tests/f08-tests  


[URLs]:#
[Issues]: https://github.com/openfortranproject/ofp-sdf/issues
[OFP]: https://github.com/openfortranproject/ofp-sdf/
[OpenCoarrays]: https://github.com/sourceryinstitute/opencoarrays/tree/caffeinate-opencoarrays
[SDF2]: http://releases.strategoxt.org/strategoxt-0.17/sdf2-bundle/sdf2-bundle-2.4pre212034-37nm9z7p/
[Stratego/XT]: http://strategoxt.org
[AST]: https://en.wikipedia.org/wiki/Abstract_syntax_tree
[ROSE]: http://www.rosecompiler.org/

