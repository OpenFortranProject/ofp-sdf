[
   Comment                       -- _1,
   None                          -- ,

   opt-list                      -- KW[", "] _1,
   opt-list.1:iter-sep           -- _1 ", ",

   REAL                          -- KW["REAL :: "],
   INTEGER                       -- KW["INTEGER :: "],
   CHARACTER                     -- KW["CHARACTER :: "],
   INTRINSIC                     -- KW["INTRINSIC :: "],
   NON_INTRINSIC                 -- KW["NON_INTRINSIC :: "],
   PARAMETER                     -- KW["PARAMETER :: "],
   LOGICAL                       -- KW["LOGICAL :: "],
   COMPLEX                       -- KW["COMPLEX :: "],

   #R201 --,
   OfpProgram                    -- V vs=0 is=0 [_1 _2],
   OfpProgram.1:opt              -- ,

   #R204 --,
   OfpSpecPart                   -- V vs=0 is=0[_1],
   
   #R208 --,
   OfpExecPart                   -- V vs=0 is=0[_1],
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

   #R413 --,
   RealLiteralConstant          -- _1 _2,

   #R423 --,
   CharLiteralConstant          -- _1 _2,

   #R449 --,
   ProcDecl                      -- _1 _2,

   #R501 --,
   TypeDeclarationStmt           -- H hs=0[H hs=3[_1] _2 _3 _4 _5],
   TypeDeclarationStmt.4:iter-sep    -- _1 ", ",

   #R502 --,
   Some                          -- _1,
   Some                          -- _1 _2,
   ALLOCATABLE                   -- KW["ALLOCATABLE :: "],

   
   #R503 --,
   EntityDecl                 -- _1 _2 _3 _4 _5,

   #R505 --,
   Initialization                -- _1,

   #R508 --, 
   LanguageBindingSpec           -- _1 KW["BIND"],
   
   #R511 --,
   OfpExplicitCoshape            -- _1,

   #R517 --,
   OfpDimSpec                    -- _1 _2,

   #R519 --,
   OfpAssumedOrDeferredShape     -- _1,

   #R560 --,
   ImplicitNoneStmt              -- H hs=1[_1 KW["IMPLICIT NONE"] _2],
   ImplicitStmt                  -- H hs=1[_1 KW["IMPLICIT"] _2 _3],

   #R561 --,
   ImplicitSpec                  -- _1 "("_2")",
   ImplicitSpec.2:iter-sep       -- _1 ",",

   #R562 --,
   LetterSpec                    -- _1 _2,

   #R602 --,
   OfpVarDef                     -- _1,

   #R611 --,
   DataRef                       -- _1,

   #R612 --,
   OfpVarRef                     -- _1,

   #R626 --,
   OfpAllocateStmt               -- H hs=1[_1 H hs=0[KW["ALLOCATE"] _2 "("_3")"] _4],
   OfpAllocateStmt.3:iter-sep    -- _1 ",",

   #R627 --,
   ERRMSG                        -- KW["ERRMSG="] _1,
   MOLD                          -- _1,
   SOURCE                        -- _1,
   STAT                          -- KW["STAT="] _1,

   #R631 --,
   OfpAllocation                 -- _1 _2 _3,

   #Operators --,
   Minus                         -- _1,
   NOT                           -- KW[".NOT."] _1,
   Plus                          -- _1 KW["+"] _2,

   #R732 --,
   AssignmentStmt             -- H hs=1[H hs=3[_1] _2 KW["="] _3 _4],
   AssignmentStmt.2:opt       -- ,

   #R851 --,
   GotoStmt                      -- H hs=1[_1 KW["GOTO"] _2 _3],

   #R852 --,
   ComputedGotoStmt              -- H hs=1[_1 KW["GOTO"] H hs=0["("_2")"] _3 _4],
   ComputedGotoStmt.2:iter-sep   -- _1 ",",

   R#853 --,
   ArithmeticIfStmt              -- H hs=1[H hs=0 [_1 KW["IF"] "("_2")"] _3 _4 _5 _6],
  
   #R854 --,
   ContinueStmt                  -- H hs=1[_1 KW["CONTINUE"] _2],

   #R855 --,
   StopStmt                      -- H hs=1[_1 KW["STOP"] _2 _3],

   #R856 --,
   ErrorStopStmt                 -- H hs=1[_1 KW["ERROR STOP"] _2 _3],

   #R858 --,
   SyncAllStmt                   -- H hs=1[_1 KW["SYNC ALL"] _2 "("_3")"],

   #R860 --,
   SyncImagesStmt                -- H hs=1[_1 KW["SYNC IMAGES"] H hs=0["("_2 _3")"] _4],
   SyncImagesStmt.3:iter-sep     -- _1 ", ",
 
   #R862 --,
   SyncMemoryStmt                -- H hs=1[_1 KW["SYNC MEMORY"] H hs=0["("_2")"] _3],
   SyncMemoryStmt.2:iter-sep     -- _1 ", ",

   #R863 --,
   LockStmt                      -- H hs=1[_1 KW["LOCK"] H hs=0["("_2 _3")"] _4],

   #R864 --,
   ACQUIRED_LOCK                 -- KW["ACQUIRED_LOCK="] _1,

   #R865 --,
   UnlockStmt                    -- H hs=1[_1 KW["UNLOCK"] H hs=0["("_2 _3")"] _4],

   #R900 --,
   IOMSG                         -- KW["IOMSG="]_1,
   UNIT                          -- KW["UNIT="]_1,
   ERR                           -- KW["ERR="]_1,
   IOSTAT                        -- KW["IOSTAT="]_1,
   END                           -- KW["END="]_1,
   EOR                           -- KW["EOR="]_1,

   #R922 --,
   WaitStmt                      -- H hs=1[_1 KW["WAIT"] H hs=0["("_2")"] _3],
   WaitStmt.2:iter-sep           -- _1 ", ",

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
   UseStmt                       -- H hs=1[_1 KW["USE"] H hs=0[_2 _3 _4 _5]],
   UseOnlyStmt                   -- H hs=1[_1 KW["USE"] H hs=0[_2 _3 KW["ONLY: "]_4 _5]],

   #R1111 --,
   Rename                        -- H hs=0[_1 KW["=>"] _2],

   #R1120 --,
   BlockData                     -- _1 _2 _3,

   #R1121 --, 
   BlockDataStmt                 -- _1 KW["BLOCK DATA"] _2 _3,

   #R1122 --,
   EndBlockDataStmt              -- _1 KW["END BLOCK DATA"] _2 _3,

   #R1201 --,
   InterfaceBlock             -- V vs=0 [_1 _3 _2],
   InterfaceStmt              -- H hs=1 [_2 _1 KW["INTERFACE"] _3],
   EndInterfaceStmt           -- H hs=1 [_1 KW["END INTERFACE"] _2 _3],
   
   #R1203 --,
   AbstractInterfaceStmt      -- _1 KW["ABSTRACT INTERFACE"] _2,

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
   ExternalStmt                        -- H hs=1[_1 KW["EXTERNAL :: "] H hs=0[_2] _3],
   ExternalStmt.2:iter-sep             -- _1 ", ",

   #R1211 --,
   ProcedureDeclarationStmt            --H hs=1[_1 "PROCEDURE" _2 H hs=0["("_3")"] H hs=0[_4 _5]],
   ProcedureDeclarationStmt.4:iter-sep    -- _1 ", ",
  
   #R1217 --,
   PpFunction                          -- _1,
   FunctionStmt                     -- _1 _4 "FUNCTION" H hs=0[ _2 "(" _3 ")"] _5 _6,
   EndFunctionStmt                  -- H hs=1[_1 KW["END FUNCTION"] _2 _3],

   #R1218 --,
   IntrinsicStmt                       -- H hs=1[_1 KW["INTRINSIC :: "] H hs=0[_2 _3]],
   IntrinsicStmt.2:iter-sep            -- _1 ", ",

   #R1220 --,
   CallStmt                            -- H hs=1[_1 KW["CALL"] H hs=0[_2 "("_3")" _4]],
   CallStmt.3:iter-sep                 -- _1 ",",

   #R1221 --,
   OfpProcRef                          -- _1,
   ProcedureDesignator                 -- _1,

   #R1222 --,
   OfpArg                              -- _1 _2,
   ActualArgSpec                       -- _1 _2,

   #R1224 --,
   AltReturnSpec                       -- _1,

   #R1233 --,
   PpSubroutine                         -- _1,
   SubroutineStmt                    -- _2 _1 KW["SUBROUTINE"] H hs=0[_3 "("_4")" _5 _6],
   SubroutineStmt.4:iter-sep         -- _1 ",",
   EndSubroutineStmt                 -- H hs=1[_1 "END SUBROUTINE" _2 _3],

   STAR                                -- "*",
   OfpArgList                          -- _1,
   OfpArgList.1:iter-star-sep          -- _1 ",",

   #R1241 --,
   ReturnStmt                          -- H hs=1[_1 KW["RETURN"] _2 _3],

   #R1242 --,
   ContainsStmt                     -- _1 KW["CONTAINS"] _2


]
