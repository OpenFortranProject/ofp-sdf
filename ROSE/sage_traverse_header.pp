[
   RTG                                 -- V [ "#ifndef TRAVERSE_SG_UNTYPED_NODES_HPP"
                                              "#define TRAVERSE_SG_UNTYPED_NODES_HPP\n"
                                              "#include <aterm2.h>"
                                              "#include \"SgUntypedNodes.hpp\"\n"

                                              _1 _2

                                              "#endif // TRAVERSE_SG_UNTYPED_NODES_HPP"],

   Start                               -- _1,

   Nonterm                             -- _1,

   Classes                             -- _1 "" _2 "" _3,

   ClassDecl                           -- H hs=0 ["ATbool traverse_" _1
                                                  "(ATerm, sage::" _1 "**);"],

   ClassDef                            -- _1 _2 _3,

   Constructor                         -- H hs=0 ["    " _1 "(" _2 ");"],
   Constructor.2:iter-sep              -- _1 ", ",

   Parent                              -- H [": " _1],
   no-parent                           -- ,

   Macro                               -- H ["#define" _1],

   Ref                                 -- _1,

   Term                                -- _1,

   Int                                 -- "int",

   String                              -- "std::string",

   #end                                --
]
