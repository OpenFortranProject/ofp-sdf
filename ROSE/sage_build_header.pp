[
   Traversals                          -- V [
                                               "#include \"rosePublicConfig.h\""
                                               "#include \"sage3basic.h\"\n"
                                               _1
                                            ],

   Traversal                           -- _1,

   FunDecl                             -- H hs=0 [
                                                     _1 "* build_" _1 "(" _2 ");\n"
                                                 ],

   ArgDecls                            -- _1,
   ArgDecls.1:iter-sep                 -- _1 ", ",
   ArgDecl                             -- H hs=0 [_1 " " _2],
   no-args                             --,

   TypeRef                             -- _1,

   Nonterm                             -- _1,

   Constructor                         -- H hs=0 ["    " _1 "(" _2 ");"],
   Constructor.2:iter-sep              -- _1 ", ",

   Parent                              -- H [": " _1],
   no-parent                           -- ,

   Ref                                 -- _1,

   Term                                -- _1,

   TypePointer                         -- H hs=0 [_1 "*"],

   Address                             -- H hs=0 ["&" _1],

   Int                                 -- "int",

   String                              -- "std::string",

   #end                                --
]
