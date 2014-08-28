[
   Comment                       -- _1,
   None                          -- ,
   REAL                          -- KW["REAL ::"],
   INTEGER                       -- KW["INTEGER ::"],
   CHARACTER                     -- KW["CHARACTER ::"],
   INTRINSIC                     -- KW["INTRINSIC ::"],
   NON_INTRINSIC                 -- KW["NON_INTRINSIC ::"],
  
   #R201 --,
   OfpProgram                    -- V vs=0 is=0 [_1 _2],
   OfpProgram.1:opt              -- ,

   #R204 --,
   OfpSpecPart                   -- V vs=0 is=0[_1],

   #R208 --,
   OfpExecPart                   -- V vs=0 is=2[_1],
   OfpFuncPart                   -- V vs=0 is=0[_1],

   #R303 --,
   OfpName                       -- H hs=1[_1],

   #R305 --,
   IntLiteralConstant            -- _1 _2,

   #R312 --,
   Label                         -- _1,

   #R404 --,
   OfpType                       -- H hs=1[_1 _2],
   
   #R407 --,
   PpLiteral                    -- H hs=1[_1],

   #R449 --,
   ProcDecl                      -- _1 _2,

   #R501 --,
   TypeDeclarationStmt           -- H hs=1[H hs=3[_1] _2 _3 _4 _5],

   #R502 --,
   Some                          -- _1,
   Some                          -- _1 _2,
   ALLOCATABLE                   -- KW["ALLOCATABLE ::"],

   
   #R503 --,
   EntityDecl                 -- _1 _2 _3 _4 _5,
   
   #R511 --,
   OfpExplicitCoshape            -- _1,

   #R517 --,
   OfpDimSpec                    -- _1 _2,

   #R519 --,
   OfpAssumedOrDeferredShape     -- _1,

   #R602 --,
   OfpVarDef                     -- _1,

   #R612 --,
   OfpVarRef                     -- _1,

   #R626 --,
   OfpAllocateStmt               -- H hs=1[_1 H hs=0[KW["ALLOCATE"] _2 "("_3")"] _4],
   OfpAllocateStmt.3:iter-sep    -- _1 ",",

   #R627 --,
   ERRMSG                        -- _1,
   MOLD                          -- _1,
   SOURCE                        -- _1,
   STAT                          -- _1,

   #R631 --,
   OfpAllocation                 -- _1 _2 _3,

   #Operators --,
   Minus                         -- _1,   

   #R732 --,
   AssignmentStmt             -- H hs=1[H hs=3[_1] _2 KW["="] _3 _4],
   AssignmentStmt.2:opt       -- ,

   #R851 --,
   GotoStmt                      -- H hs=1[_1 KW["GOTO"] _2 _3],

   #R852 --,
   ComputedGotoStmt              -- _1 _2 _3 _4,

   #R854 --,
   ContinueStmt                  -- _1 _2,

   #R900 --,
   IOMSG                         -- KW["IOMSG="]_1,
   UNIT                          -- KW["UNIT="]_1,
   ERR                           -- KW["ERR="]_1,
   IOSTAT                        -- KW["IOSTAT="]_1,

   #R924 --,
   BackspaceStmt                 -- H hs=0[_1 KW["BACKSPACE"] "("_2")" _3],
   BackspaceStmt.2:iter-sep      -- _1 ",",

   #R926 --,
   RewindStmt                    -- H hs=0[_1 KW["REWIND"] "("_2")" _3],
   RewindStmt.2:iter-sep         -- _1 ",",

   #R1101 --,
   PpMainProgram                -- V vs=0 [H[_1]],
   PpMainProgram.1:opt          -- ,

   ProgramStmt                -- _1 KW["PROGRAM"] _2 _3,
   EndProgramStmt             -- H hs=1[_1 "END PROGRAM" _2 _3],

   #R1104 --,
   PpModule                      -- _1,

   #R1105 --, 
   ModuleStmt                    -- H hs=1[_1 KW["MODULE"] _2 _3],
 
   #R1106 --, 
   EndModuleStmt                 -- H hs=1 [_1 KW["END MODULE"]_2 _3],

   #R1109 --,
   UseStmt                       -- _1 _2 _3 _4 _5,
   UseOnlyStmt                   -- _1 _2 _3 _4 _5,

   #R1111 --,
   Rename                        -- _1 _2,

   #R1120 --,
   BlockData                     -- _1 _2 _3,

   #R1121 --, 
   BlockDataStmt                 -- _1 KW["BLOCKDATA"] _2 _3,

   #R1122 --,
   EndBlockDataStmt              -- _1 _2 _3,

   #R1201 --,
   InterfaceBlock             -- V vs=0 [_1 _3 _2],
   InterfaceStmt              -- H hs=1 [_2 _1 KW["INTERFACE"] _3],
   EndInterfaceStmt           -- H hs=1 [_1 KW["END INTERFACE"] _2 _3],
   
   #R1203 --,
   AbstractInterfaceStmt      -- _1 _2,

   #R1205 --,
   OfpScope                      -- V vs=0 [H hs=1[_4] _1 _2 V vs=1 [_5 _3 _6]],
   InterfaceBody                 -- _1 _2 _3,

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

   #R1206 --,
   ProcedureStmt,                      -- _1 _2 _3,

    #R1207 --,
   OfpGenericSpec                      -- _1,

   #R1210 --,
   ExternalStmt                        -- H hs=0 [_1 KW["EXTERNAL"] _2 _3],
   ExternalStmt.2:iter-sep             -- _1 ",",

   #R1211 --,
   ProcedureDeclarationStmt         -- V vs=0 [H hs=1[_1 "PROCEDURE" _2 H hs=0["("_3")"] _4 _5]],

   #R1217 --,
   PpFunction                          -- _1,
   FunctionStmt                     -- _1 _4 "FUNCTION" H hs=0[ _2 "(" _3 ")"] _5 _6,
   EndFunctionStmt                  -- H hs=1[_1 KW["END FUNCTION"] _2 _3],

   #R1218 --,
   IntrinsicStmt                       -- _1 _2 _3,

   #R1220 --,
   OfpCallStmt                         -- _1 _2 _3,

   #R1221 --,
   OfpProcRef                          -- _1,

   #R1222 --,
   OfpArg                              -- _1 _2,

   #R1233 --,
   PpSubroutine                         -- _1,
   SubroutineStmt                    -- _1 _4 "SUBROUTINE" H hs=0[ _2  _3 "("_5")" _6],
   EndSubroutineStmt                 -- H hs=1[_1 "END SUBROUTINE" _2 _3],

   STAR                                -- "*",
   OfpArgList                          -- _1,
   OfpArgList.1:iter-star-sep          -- _1 ",",

   #R1242 --,
   ContainsStmt                     -- _1 KW["CONTAINS"] _2


]
