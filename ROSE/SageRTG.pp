[
   RTG                                 -- V [ "#ifndef SG_UNTYPED_NODES_HPP"
                                              "#define SG_UNTYPED_NODES_HPP\n"
                                              "#include <string>"
                                              "#include <list>\n"
                                              "namespace sage {\n"

                                              _1 _2

                                              "} // namespace sage" "\n#endif // SG_UNTYPED_NODES_HPP"],

   Start                               -- _1,

   Nonterm                             -- _1,

   Classes                             -- _1 "" _2 "" _3,

   ClassDecl                           -- H hs=0 ["class " _1 ";"],

   ClassDef                            -- H ["class" _1 _2] "{" _3 "};\n",

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
