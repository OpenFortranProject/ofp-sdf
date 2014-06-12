[
   Comment                       -- _1,
   None                          -- ,
   Label                         -- _1,
   REAL                          -- KW["REAL ::"],
   INTEGER                       -- KW["INTEGER ::"],

   #R201 --,
   OfpProgram                    -- V vs=0 is=0 [_1 _2],
   OfpProgram.1:opt              -- ,

   #R204 --,
   OfpSpecPart                   -- V vs=1[_1],

   #R208 --,
   OfpExecPart                   -- H hs=0[_1],
   OfpFuncPart                   -- H hs=0[_1],

   #R303 --,
   OfpName                       -- H hs=1[_1],

   #R404 --,
   OfpType                       -- H hs=1[_1 _2],

   #R407 --,
   PpLiteral                    -- H hs=1[_1],

   #R501 --,
   OfpTypeDeclarationStmt        -- H hs=1[H hs=3[_1] _2 _3 _4],

   #R502 --,
   Some                          -- _1,
   Some                          -- _1 _2,
   
   #R503 --,
   OfpEntityDecl                 -- _1 _2 _3 _4 _5,

   #R602 --,
   OfpVarDef                     -- _1,

   #R732 --,
   OfpAssignmentStmt             -- H hs=1[H hs=3[_1] _2 KW["="] _3],
   OfpAssignmentStmt.2:opt       -- ,

   #R1101 --,
   PpMainProgram                -- V vs=0 [H[_1]],
   PpMainProgram.1:opt          -- ,

   OfpProgramStmt                -- _1 KW["PROGRAM"] _2,
   OfpEndProgramStmt             -- H hs=1[_1 "END PROGRAM" _2],

   #R1104 --,
   PpModule                      -- _1,

   #R1201 --,
   OfpInterfaceBlock             -- V vs=0 [_1 _3 _2],
   OfpInterfaceStmt              -- H hs=1 [_2 _1 KW["INTERFACE"] _3],
   OfpEndInterfaceStmt           -- H hs=1 [_1 KW["END INTERFACE"] _2],
   
   #R1205 --,
   OfpScope                      -- V vs=0 [H hs=1[_4] _1 _2 V vs=1 [_5 _3 _6]],


   OfpPrefix                           -- _1,
   OfpPrefix.1:iter-star               -- _1,

   ELEMENTAL                           -- "ELEMENTAL",
   IMPURE                              -- "IMPURE",
   MODULE                              -- "MODULE",
   PURE                                -- "PURE",
   RECURSIVE                           -- "RECURSIVE",

   OfpLanguageBinding                  -- "BIND(C" _1 ")",
   OfpResultName                       -- "RESULT" _1,
   OfpSuffix                           -- _1,
   OfpSuffix.1:iter-star               -- _1,

   #R1217 --,
   PpFunction                          -- _1,
   OfpFunctionStmt                     -- _1 _4 KW["FUNCTION"] _2 "(" _3 ")" _5,
   OfpEndFunctionStmt                  -- H hs=1[_1 KW["END FUNCTION"] _2],

   #R1233 --,
   PpSubroutine                         -- _1,
   OfpSubroutineStmt                    -- _1 _4 "SUBROUTINE" H hs=0[ _2 "(" _3 ")"] _5,
   OfpEndSubroutineStmt                 -- H hs=1[_1 "END SUBROUTINE" _2],

   STAR                                -- "*",
   OfpArgList                          -- _1,
   OfpArgList.1:iter-star-sep          -- _1 ",",

   #R1242 --,
   OfpContainsStmt                     -- _1 KW["CONTAINS"]


]
