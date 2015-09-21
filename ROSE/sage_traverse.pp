[
   Traversals                          -- V [_1],

   Traversal                           -- _1 V is=2 [
                   "{"
                        "#ifdef DEBUG_PRINT"
                        "  printf(\"SgUntypedGlobalScope: %s\\n\", ATwriteToString(term));"
                        "#endif\n"
                        _2 _3 _4]
                   "}\n",

   FunDecl                             -- H hs=0 ["ATbool traverse_" _1
                                                  "(ATerm term, sage::" _1 "** " _1 ")"],

   TermDecls                           -- H hs=0 ["ATerm " _1 ";"],
   TermDecls.1:iter-sep                -- _1 ", ",
   no-decls                            --,

   ArgDecls                            -- _1,
   ArgDecl                             -- H hs=0 [_1 " " _2 ";"],

   MatchStmt                           -- "\n" _1,

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

   Int                                 -- "int",

   String                              -- "std::string",

   #end                                --
]
