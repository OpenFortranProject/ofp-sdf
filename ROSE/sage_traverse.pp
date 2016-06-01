[
   Traversals                          -- V [
                                               "#include \"rosePublicConfig.h\""
                                               "#include \"sage3basic.h\"\n"
                                               "#include \"aterm2.h\"\n"
                                               "#include \"traverse_SgUntypedNodes.hpp\""
                                               "#include \"build_SgUntypedNodes.hpp\"\n"
                                               _1
                                            ],

   Traversal                           -- _1 
         "{"
                                          V is=2 [_2 _3 _4 _5 _6]
         "\n  return ATtrue;"
         "}\n",

   FunDecl                             -- H hs=0 [
         "//========================================================================================\n"
         "// " _1 "\n"
         "//----------------------------------------------------------------------------------------\n"
         "ATbool traverse_" _1 "(ATerm term, " _1 "** var_" _1 ")"
                                                 ],

   Debug                              -- H hs=0 [
         "#ifdef DEBUG_PRINT\n"
         "  printf(\"... traverse_" _1 ": %s\\n\", ATwriteToString(term));\n"
         "#endif\n"                             ],

   TermDecls                           -- H hs=0 ["ATerm " _1 ";"],
   TermDecls.1:iter-sep                -- _1 ", ",
   no-decls                            --,

   ArgDecls                            -- _1,
   ArgDecl                             -- H hs=0 [_1 " " _2 ";"],

   MatchConstruct                      -- H hs=0
      [ 
           "\n  *var_" _1 " = NULL;"
           "\n  if (ATmatch(term, \"" _1 "(" _2 ")\", " _3 ")) {"
      ]
        _4 "} else return ATfalse;\n",

   MatchConstruct.2:iter-sep           -- _1 ",",
   MatchConstruct.3:iter-sep           -- _1 ",",

   MatchList                           -- H hs=0
      [ 
           "\n  *var_" _1 " = NULL;"
           "\n  if (ATmatch(term, \"" _1 "(" _2 ")\", " _3 ")) {"
           "\n     " _1 "* plist = new " _1 "();"
           "\n"
           "\n     ATermList tail = (ATermList) ATmake(\"<term>\", term1);"
           "\n     while (! ATisEmpty(tail)) {"
           "\n        ATerm head = ATgetFirst(tail);"
           "\n        tail = ATgetNext(tail);"
      ]
        _4  H hs=0
      [
           "   }"
           "\n     *var_" _1 " = plist;"
      ]
           "}\n  else return ATfalse;",

   MatchList.2:iter-sep                -- _1 ",",
   MatchList.3:iter-sep                -- _1 ",",

   TraverseArgs                        -- _1,
   TraverseArg                         -- H hs=0
      ["  if (traverse_"_1 "(" _2 ", &"_3 ")) {\n      // " _1 "\n    } else return ATfalse;"
      ],

   ListArgs                            -- _1,
   ListArg                             -- H hs=0
      [
           "      {"
           "\n           " _1 "* arg;"
           "\n           if (traverse_"_1 "(head, &arg)) {"
           "\n              // " _1
           "\n              plist->get_" _2 "_list().push_back(arg);"
           "\n           }"
           "\n           else {"
           "\n              delete plist;"
           "\n              return ATfalse;"
           "\n           }"
           "\n        }"
      ],

   BuildStmt                           -- H hs=0 ["*var_"_1 " = new " _1 "("_2 ");"],
   BuildStmt.2:iter-sep                -- _1 ",",
   no-build                            -- H hs=0 ["// turn on build functions (using BuildStmt) in sage-to-traverse.str"],

   TypeRef                             -- _1,

   Nonterm                             -- _1,

   ClassDef                            -- _1 _2 _3,

   Constructor                         -- H hs=0 ["    " _1 "(" _2 ");"],
   Constructor.2:iter-sep              -- _1 ", ",

   Parent                              -- H [": " _1],
   no-parent                           -- ,

   Macro                               -- H ["#define" _1],

   Ref                                 -- _1,

   Term                                -- _1,

   TypePointer                         -- H hs=0 [_1 "*"],

   Address                             -- H hs=0 ["&" _1],

   Int                                 -- "int",

   String                              -- "std::string",

   #end                                --
]
