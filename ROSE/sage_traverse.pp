[
   Traversals                          -- V [_1],

   Traversal                           -- _1 
         "{"
                                          V is=2 [_2 _3 _4 _5 _6]
         "\n  return ATtrue;"
         "}\n",

   FunDecl                             -- H hs=0 [
         "//========================================================================================\n"
         "// " _1 "\n"
         "//----------------------------------------------------------------------------------------\n"
         "ATbool traverse_" _1 "(ATerm term, sage::" _1 "** " _1 ")"
                                                 ],

   Debug                              -- H hs=0 [
         "#ifdef DEBUG_PRINT\n"
         "  printf(\"" _1 " %s\\n\", ATwriteToString(term));\n"
         "#endif\n"                             ],

   TermDecls                           -- H hs=0 ["ATerm " _1 ";"],
   TermDecls.1:iter-sep                -- _1 ", ",
   no-decls                            --,

   ArgDecls                            -- _1,
   ArgDecl                             -- H hs=0 [_1 " " _2 ";"],

   MatchConstruct                      -- H hs=0
      [ 
           "\n  if (ATmatch(term, \"" _1 "(" _2 ")\", " _3 ")) {"
      ]
        _4 "} else return ATfalse;\n",

   MatchConstruct.2:iter-sep           -- _1 ",",
   MatchConstruct.3:iter-sep           -- _1 ",",

   TraverseArgs                        -- _1,
   TraverseArg                         -- H hs=0
      ["  if (traverse_"_1 "(" _2 ", &"_3 ")) {\n      // " _1 "\n    } else return ATfalse;"
      ],

   BuildStmt                           -- H hs=0 ["*"_1 " = new sage::" _1 "("_2 ");"],
   BuildStmt.2:iter-sep           -- _1 ",",

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

   TypePointer                         -- H hs=0 ["sage::" _1 "*"],

   Address                             -- H hs=0 ["&" _1],

   Int                                 -- "int",

   String                              -- "std::string",

   #end                                --
]
