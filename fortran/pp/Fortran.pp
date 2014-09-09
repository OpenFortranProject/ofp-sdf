[
   Comment                       -- _1,
   None                          -- ,

   append-colon                  -- _1 KW[": "],

   opt-list                      -- KW[", "] _1,
   opt-list.1:iter-sep           -- _1 ", ",

   INTRINSIC                     -- KW["INTRINSIC :: "],
   NON_INTRINSIC                 -- KW["NON_INTRINSIC :: "],
   PARAMETER                     -- KW["PARAMETER :: "],

   #R201 --,
   OfpProgram                    -- V vs=1 is=0 [_1 _2],
   OfpProgram.1:opt              -- ,

   #R204 --,
   OfpSpecPart                   -- V vs=0 is=0[_1],
   
   #R208 --,
   OfpExecPart                   -- V vs=0 is=0[_1],
   OfpFuncPart                   -- V vs=1 is=0[_1],

   #R303 --,
   OfpName                       -- H hs=1[_1],

   #R305 --,
   IntLiteralConstant            -- _1 _2,

   #R312 --,
   Label                         -- _1,

   #R401 --,
   COLON                         -- KW[":"],

   #R403 --,
   IntrinsicType                 -- _1,

   #R404 --,
   OfpType                       -- H hs=1[_1 _2],
   INTEGER                       -- KW["INTEGER :: "] _1,
   REAL                          -- KW["REAL :: "] _1,
   CHARACTER                     -- KW["CHARACTER :: "] _1,
   LOGICAL                       -- KW["LOGICAL :: "] _1,
   COMPLEX                       -- KW["COMPLEX :: "] _1,

   #R403 --,
   Class                         -- _1 KW["CLASS"] "("_2")",

   #R405 --,
   KindSelector                  -- "(" KW["KIND="] _1")",
   
   #R407 --,
   PpLiteral                     -- H hs=1[_1],

   #R413 --,
   RealLiteralConstant           -- _1 _2,

   #R423 --,
   CharLiteralConstant           -- _1 _2,

   #R424 --,
   TRUE                          -- KW[".TRUE."] _1,

   FALSE                         -- KW[".FALSE."] _1,

   #R425 --,
   DerivedTypeDef                -- _1 _2 _3 _4 _5 _6,

   #R426 --,
   DerivedTypeStmt               -- H hs=1[_1 KW["TYPE"] H hs=0[_2 _3 "("_4")" _5]],
   DerivedTypeStmt.2:iter-sep    -- _1 ", ",
   DerivedTypeStmt.4:iter-sep    -- _1 ", ",

   #R427 --,
   ABSTRACT                      -- KW["ABSTRACT"],
   Extends                       -- KW["EXTENDS"] _1,
   BIND                          -- KW["BIND(C)"],

   #R429 --,
   EndTypeStmt                   -- H hs=1[_1 KW["END TYPE"] H hs=0[_2 _3]],

   #R431 --,
   TypeParamDefStmt              -- H hs=1[_1 KW["INTEGER"] H hs=0[_2 KW[", "] _3 KW[" :: "] _4 _5]],

   #R432 --,
   TypeParamDecl                 -- _1 KW[" = "] _2,

   #R433 --,
   KIND                          -- KW["KIND"],
   LEN                           -- KW["LEN"],

   #R436 --,
   DataComponentDefStmt          -- H hs=1[_1 H hs=0[_2 _3 _4 _5]],
   DataComponentDefStmt.4:iter-sep   -- _1 ", ",

   #R437 --,
   Codimension                   -- KW["CODIMENSION"] _1,
   Codimension.1:iter-sep        -- _1 ",",

   #R438 --,
   ComponentDecl                 -- _1 _2 _3 _4 _5,

   #R440 --,
   ProcComponentDefStmt          -- H hs=1[_1 KW["PROCEDURE"] H hs=0["("_2")" KW[", "] _3 KW[" :: "] _4 _5]],
   ProcComponentDefStmt.3:iter-sep   -- _1 ", ",

   #R441 --,
   POINTER                       -- KW["POINTER"],
   PASS                          -- KW["PASS"],

   #R442 --,
   ComponentInit                 -- _1,

   #R445 --,
   TypeBoundProcedurePart        -- _1 _2 _3,

   #R448 --,
   TypeBoundProcedureStmt        -- H hs=1[H hs=0[_1 KW["PROCEDURE"] KW[", "] _2 KW[" :: "] _3 _4]],

   #R449 --,
   TypeBoundProcDecl             -- _1 KW[" => "] _2,

   #R451 --,
   Pass                          -- KW["PASS"] _1,

   #R453 --,
   DerivedTypeSpec               -- _1 _2,

   #R468 --,
   ArrayConstructor              -- "(/"_1"/)",

   #R469 --,
   AcSpec                        -- _1 _2,
   AcSpec.2:iter-sep             -- _1 ",",

   #R501 --,
   TypeDeclarationStmt           -- H hs=0[H hs=3[_1] _2 _3 _4 _5],
   TypeDeclarationStmt.4:iter-sep    -- _1 ", ",

   #R502 --,
   Some                          -- _1,
   Some                          -- _1 _2,
   ALLOCATABLE                   -- KW["ALLOCATABLE :: "],
   Intent                        -- KW["INTENT"] _1,
   
   #R503 --,
   EntityDecl                    -- _1 _2 _3 _4 _5,

   #R505 --,
   Initialization                -- KW[" = "] _1,
   Init                          -- KW[" = "] _1,

   #R507 --,
   PRIVATE                       -- KW["PRIVATE"],
   PUBLIC                        -- KW["PUBLIC"],
   
   #R508 --, 
   LanguageBindingSpec           -- _1 KW[" BIND(C)"],
   
   #R511 --,
   OfpExplicitCoshape            -- _1,

   #R517 --,
   DimSpec                    -- _1 _2,

   #R519 --,
   OfpAssumedOrDeferredShape     -- _1,

   #R523 --,
   IN                            -- KW["IN"],

   #R524 --,
   AccessStmt                    -- H hs=1[_1 _2 H hs=0[_3 _4]],
   AccessStmt.3:iter-sep         -- _1 ", ",

   #R526 --,
   AllocatableStmt               -- H hs=1[_1 KW["ALLOCATABLE ::"] H hs=0[_2 _3]],
   AllocatableStmt.2:iter-sep    -- _1 ", ",

   #R527 --,
   AllocatableDecl               -- _1 "("_2")" _3,
   AllocatableDecl.2:iter-sep    -- _1 ", ",

   #R529 --,
   BindStmt                      -- H hs=1[_1 H hs=0[_2 KW[" :: "] _3 _4]],
   BindStmt.3:iter-sep           -- _1 ", ",

   #R553 --,
   SaveStmt                      -- H hs=1[_1 KW["SAVE ::"] H hs=0[_2 _3]],
   SaveStmt.2:iter-sep           -- _1 ", ",

   #R554 --,
   SavedEntity                   -- _1,
   SavedEntity_CBN               -- _1,

   #R560 --,
   ImplicitNoneStmt              -- H hs=1[_1 KW["IMPLICIT NONE"] _2],
   ImplicitStmt                  -- H hs=1[_1 KW["IMPLICIT"] H hs=0[_2 _3]],
   ImplicitStmt.2:iter-sep       -- _1 ", ",

   #R561 --,
   ImplicitSpec                  -- _1 "("_2")",
   ImplicitSpec.2:iter-sep       -- _1 ", ",

   #R562 --,
   LetterSpec                    -- _1 _2,
   PpLetterSpec                  -- _1,
   PpLetterSpec                  -- _1 KW["-"] _2,

   #R568 --,
   CommonStmt                    -- H hs=1[_1 KW["COMMON"] H hs=0[ _2 _3]],
   CommonBlockEntry              -- _1 _2,
   CommonBlockName               -- "/"_1"/",

   #R569 --,
   CommonBlockObject             -- _1 _2,

   #R602 --,
   OfpVarDef                     -- _1,

   #R611 --,
   DataRef                       -- _1,
   DataRef.1:iter-sep            -- _1 "%",

   #R612 --,
   OfpVarRef                     -- _1,
   PartRef                       -- _1 "("_2")" _3,
   PartRef.2:iter-sep            -- _1 ",",

   #R626 --,
   AllocateStmt                  -- H hs=1[_1 H hs=0[KW["ALLOCATE"] "("_2 _3 _4")" _5]],
   AllocateStmt.3:iter-sep       -- _1 ",",
   AllocateStmt.4:iter-sep       -- _1 ", ",

   #R627 --,
   ERRMSG                        -- KW["ERRMSG="] _1,
   MOLD                          -- _1,
   SOURCE                        -- KW["SOURCE="] _1,
   STAT                          -- KW["STAT="] _1,

   #R631 --,
   Allocation                    -- _1 "("_2 _3")",
   Allocation.2:iter-sep         -- _1 ", ",
   Triplet                       -- _1 KW[":"] _2 _3,

   #R633 --,
   AllocateShapeSpec             -- _1 KW[":"] _2,

   #Operators --,
   Minus                         -- KW["-"] _1,
   Minus                         -- _1 KW[" - "] _2,
   NOT                           -- KW[".NOT."] _1,
   Plus                          -- _1 KW[" + "] _2,
   Plus                          -- KW["+"] _1,
   GT                            -- _1 KW[" > "] _2,
   LT                            -- _1 KW[" .LT. "] _2,
   NE                            -- _1 KW[" /= "] _2,
   EQ                            -- _1 KW[" ==  "] _2,
   LE                            -- _1 KW[" .LE. "] _2,
   GE                            -- _1 KW[" .GE. "] _2,
   AND                           -- _1 KW[" .AND. "] _2,
   OR                            -- _1 KW[" .OR. "] _2,
   EQV                           -- _1 KW[" .EQV. "] _2,
   NEQV                          -- _1 KW[" .NEQV. "] _2,
   DefUnaryExpr                  -- H hs=1[_1 _2],
   DefBinExpr                    -- _1 _2 _3,
   Power                         -- H hs=1[H hs=0["("_1")"] KW["**"] _2],
   Mult                          -- _1 KW[" * "] _2,
   Div                           -- _1 KW[" / "] _2,
   Concat                        -- _1 KW[" // "] _2,

   #R709 --,
   PLUS                          -- KW ["+"],

   #R732 --,
   AssignmentStmt                -- H hs=0 [_1 _2 KW[" = "] _3 _4],
   AssignmentStmt.2:opt          -- ,

   #R733 --,
   PointerAssignmentStmt         -- H hs=1[_1 H hs=0[_2 "("_3")" KW["=>"] _4 _5]],
   PointerAssignmentStmt.3:iter-sep  -- _1 ", ",

   #R734 --,
   DataPointerObject             -- _1 KW["%"] _2,

   #R736 --,
   BoundsRemapping               -- _1 KW[":"] _2,

   #R750 --,
   ForallConstruct               -- _1 _2 _3,

   #R801 --,
   Block                         -- _1,

   #R817 --,
   PpNonlabelDoStmt              -- H hs=1[_1 H hs=0 [_2 KW["DO"]] H hs=1[_3] _4],

   #R818 --,
   LoopControl                   -- H hs=1[_1 KW["="] H hs=0[_2 KW[", "] _3 _4]],

   #R822 --,
   EndDoStmt                     -- H hs=1[_1 KW["END DO"] H hs=0[_2 _3]],

   #R831 --,
   CycleStmt                     -- H hs=1[_1 KW["CYCLE"] H hs=0[_2 _3]],

   #R837 --,
   IfStmt                        -- H hs=1[_1 KW["IF"] H hs=0["("_2")"] _3],

   #R838 --,
   CaseConstruct                 -- _1 _2 _3,
   CaseStmtBlock                 -- _1 _2,

   #R839 --,
   PpSelectCaseStmt                -- H hs=1[_1 H hs=0 [_2 KW["SELECT CASE"] "("_3")" _4]],

   #R840 --,
   CaseStmt                      -- H hs=1[_1 KW["CASE"] H hs=0["("_2")"] H hs=0[_3 _4]],
   CaseStmt.2:iter-sep           -- _1 ", ",

   #R841 --,
   EndSelectStmt                 -- H hs=1[_1 KW["END SELECT"] H hs=0[_2 _3]],

   #R843 --,
   DEFAULT                       -- KW["DEFAULT"],

   #R844 --,
   CaseValueRange                -- _1 KW[":"] _2,

   #R845 --,
   CaseValue                     -- _1,

   #R846 --,
   SelectTypeConstruct           -- _1 _2 _3,
   TypeGuardStmtBlock            -- _1 _2,

   #R847 --,
   SelectTypeStmt                -- H hs=1[_1 KW["SELECT TYPE"] H hs=0["("_2 KW[" => "] _3")" _4]],
   SelectTypeStmt                -- H hs=1[H hs=0[_2 _1 KW["SELECT TYPE"]] H hs=0[_3 "("_4")" _5]],

   #R848 --,
   ClassGuardStmt                -- H hs=1[_1 KW["CLASS IS"] "("_2")" H hs=0[_3 _4]],
   TypeGuardStmt                 -- H hs=1[_1 KW["TYPE IS"] H hs=0["("_2")"] H hs=0[_3 _4]],
   DefaultGuardStmt              -- H hs=1[_1 KW["CLASS DEFAULT"] H hs=0[_2 _3]],

   #R849 --,
   EndSelectTypeStmt             -- H hs=1[_1 KW["END SELECT"] H hs=0[_2 _3]],

   #R850 --,
   ExitStmt                      -- H hs=1[_1 KW["EXIT"] H hs=0[_2 _3]],

   #R851 --,
   GotoStmt                      -- H hs=1[_1 KW["GO TO"] _2 _3],

   #R852 --,
   ComputedGotoStmt              -- H hs=1[_1 KW["GO TO"] H hs=0["("_2")"] H hs=0[_3] _4],
   ComputedGotoStmt.2:iter-sep   -- _1 ", ",

   R#853 --,
   ArithmeticIfStmt              -- H hs=1[H hs=0[_1 KW["IF"] "("_2")"] H hs=0 [_3 KW[", "] _4 KW[", "] _5 _6]],
     
   #R854 --,
   ContinueStmt                  -- H hs=1[_1 KW["CONTINUE"] _2],

   #R855 --,
   StopStmt                      -- H hs=1[_1 KW["STOP"] _2 _3],

   #R856 --,
   ErrorStopStmt                 -- H hs=1[_1 KW["ERROR STOP"] _2 _3],

   #R858 --,
   SyncAllStmt                   -- H hs=1[_1 KW["SYNC ALL"] H hs=0 ["("_2 _3")"]],
   SyncAllStmt.2:iter-sep        -- _1 ", ",

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

   #R866 --,
   PauseStmt                     -- H hs=1[_1 KW["PAUSE"] H hs=0 [_2 _3]],

   #R900 --,
   IOMSG                         -- KW["IOMSG="]_1,
   UNIT                          -- KW["UNIT="]_1,
   ERR                           -- KW["ERR="]_1,
   IOSTAT                        -- KW["IOSTAT="]_1,
   END                           -- KW["END="]_1,
   EOR                           -- KW["EOR="]_1,

   #R910 --,
   ReadStmt                      -- H hs=1[_1 KW["READ"] H hs=0["("_2")" KW[", "] _3 _4]],
   ReadStmt.3:iter-sep           -- _1 ", ",

   #R911 --,
   WriteStmt                     -- H hs=1[_1 KW["WRITE"] H hs=0 ["("_2")"] H hs=0[_3 _4]],
   WriteStmt.2:iter-sep          -- _1 ", ",
   WriteStmt.3:iter-sep          -- _1 ", ",

   #R912 --,
   PrintStmt                     -- H hs=1[_1 KW["PRINT"] H hs=0[_2 _3 _4]],

   #R913 --,
   FMT                           -- KW["FMT="] _1,
   DECIMAL                       -- KW["DECIMAL="] _1,
   SIZE                          -- KW["SIZE="] _1,
   ADVANCE                       -- KW["ADVANCE="] _1,
   REC                           -- KW["REC="] _1,

   #R915 --,
   Format_STAR                   -- KW["*"],
   Format                        -- _1,

   #R917 --,
   OutputItem                    -- _1,

   #R918 --,
   IoImpliedDo                   -- "("_1 KW[", "] _2")",
   IoImpliedDo.1:iter-sep        -- _1 ", ",

   #R919 --,
   IoImpliedDoObjectList         -- _1,

   #R920 --,
   IoImpliedDoControl            -- _1 KW["="] _2 KW[","] _3 KW[","] _4,

   #R922 --,
   WaitStmt                      -- H hs=1[_1 KW["WAIT"] H hs=0["("_2")"] _3],
   WaitStmt.2:iter-sep           -- _1 ", ",

   #R924 --,
   BackspaceStmt                 -- H hs=1[_1 KW["BACKSPACE"] H hs=0 ["("_2")" _3]],
   BackspaceStmt.2:iter-sep      -- _1 ", ",

   #R926 --,
   RewindStmt                    -- H hs=1[_1 KW["REWIND"] H hs=0["("_2")" _3]],
   RewindStmt.2:iter-sep         -- _1 ", ",

   #R928 --,
   FlushStmt                     -- H hs=1[_1 KW["FLUSH"] H hs=0["("_2")" _3]],
   FlushStmt.2:iter-sep          -- _1 ", ",

   #R930 --,
   InquireStmt                   -- H hs=1[_1 KW["INQUIRE"] H hs=0["("_2")" _3]],
   InquireStmt.2:iter-sep        -- _1 ", ",
   InquireLengthStmt             -- H hs=1[_1 KW["INQUIRE"] H hs=0["("KW["IOLENGTH="] _2")"] H hs=0[_3 _4]],
   InquireLengthStmt.3:iter-sep  -- _1 ", ",

   #R931 --,
   FILE                          -- KW ["FILE="] _1,
   BLANK                         -- KW ["BLANK="] _1,
   ENCODING                      -- KW ["ENCODING="] _1,
   ACCESS                        -- KW ["ACCESS="] _1,
   ACTION                        -- KW ["ACTION="] _1,
   ASYNCHRONOUS                  -- KW ["ASYNCHRONOUS="] _1,

   #R1001 --,
   FormatStmt                    -- H hs=1[_1 KW["FORMAT"] H hs=0 ["("_2")" _3]],

   FormatStmt.1:iter-sep         -- _1 ", ",

   R#1002 --,
   FormatSpec                    -- _1 _2,
   FormatSpec.1:iter-sep         -- _1 ", ",

   R#1004 --,
   R                             -- _1 "("_2")",
   R.2:iter-sep                  -- _1 ", ",

   R#1007 --,
   I                             -- _1 KW["I"] _2 _3,
   E                             -- _1 KW["E"] _2 KW["."] _3 _4,
   F                             -- _1 KW["F"] _2 KW["."] _3,

   #R1013 --,
   P                             -- _1 KW["P"],
   SLASH                         -- KW ["/ "] _1,
   COLON_ED                      -- KW[":"],

   #R1015 --,
   X                             -- _1 KW["X"],

   #R1021 --,
   CS                            -- _1,


   #R1101 --,
   PpMainProgram                 -- V vs=0 [_1],
   PpMainProgram.1:opt           -- ,

   ProgramStmt                   -- _1 KW["PROGRAM"] _2 _3,
   EndProgramStmt                -- H hs=1[_1 "END PROGRAM" _2 _3],

   #R1104 --,
   PpModule                      -- _1,

   #R1105 --, 
   ModuleStmt                    -- H hs=1[_1 KW["MODULE"] _2 _3],
 
   #R1106 --, 
   EndModuleStmt                 -- H hs=1 [_1 KW["END MODULE"]_2 _3],

   #R1109 --,
   UseStmt                       -- H hs=1[_1 KW["USE"] H hs=0[_2 _3 _4 _5]],
   UseOnlyStmt                   -- H hs=1[_1 KW["USE"] H hs=0[_2 _3 ", ONLY: " _4 _5]],
   OnlyList                      -- _1,

   #R1110 --,
   ModuleNature                  -- KW[", "] _1,

   #R1111 --,
   Rename                        -- KW[", "] H hs=0[_1 KW["=>"] _2],

   #R1116 --,
   OfpSubmodule                  -- _1 _2,

   #R1117 --,
   SubmoduleStmt                 -- H hs=1[_1 KW["SUBMODULE"] H hs=0["("_2")"] _3 _4],

   #R1118 --,
   ParentIdentifier              -- _1 _2,

   #R1119 --,
   EndSubmoduleStmt              -- H hs=1[_1 KW["END SUBMODULE"] H hs=0[_2 _3]],

   #R1120 --,
   BlockData                     -- _1 _2 _3,

   #R1121 --, 
   BlockDataStmt                 -- _1 KW["BLOCK DATA"] _2 _3,

   #R1122 --,
   EndBlockDataStmt              -- _1 KW["END BLOCK DATA"] _2 _3,

   #R1201 --,
   InterfaceBlock             -- V vs=0 [_1 _2 _3],
   InterfaceStmt              -- H hs=1 [_1 KW["INTERFACE"] _2 _3],
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

   OfpResultName                       -- "RESULT" _1,
   OfpSuffix                           -- _1,
   OfpSuffix.1:iter-star               -- _1,

   #R1206 --,
   ProcedureStmt                       -- H hs=1[_1 KW["PROCEDURE ::"] H hs=0[_2 _3]],
   ProcedureStmt.2:iter-sep            -- _1 ", ",
   ModuleProcedureStmt                 -- H hs=1[_1 KW["MODULE PROCEDURE ::"] H hs=0[_2 _3]],
   ModuleProcedureStmt.2:iter-sep            -- _1 ", ",

   #R1207 --,
   OfpGenericSpec                      -- _1,
   ASSIGNMENT                          -- KW["ASSIGNMENT(=)"],
   OPERATOR                            -- H hs=1[KW ["OPERATOR"] H hs=0 ["("_1")"]],

   #R1210 --,
   ExternalStmt                        -- H hs=1[_1 KW["EXTERNAL ::"] H hs=0[_2 _3]],
   ExternalStmt.2:iter-sep             -- _1 ", ",

   #R1211 --,
   ProcedureDeclarationStmt            --H hs=1[_1 "PROCEDURE" _2 H hs=0["("_3")"] H hs=0[_4 _5]],
   ProcedureDeclarationStmt.4:iter-sep    -- _1 ", ",
  
   #R1214 --,
   ProcDecl                            -- _1 _2,

   #R1217 --,
   PpFunction                          -- _1,
   FunctionStmt                        -- H hs=1[_1 "FUNCTION" H hs=0[_2 _3 "("_4")" _5 _6]],
   FunctionStmt.4:iter-sep             -- _1 ", ",
   EndFunctionStmt                     -- H hs=1[_1 KW["END FUNCTION"] _2 _3],

   #R1218 --,
   IntrinsicStmt                       -- H hs=1[_1 KW["INTRINSIC ::"] H hs=0[_2 _3]],
   IntrinsicStmt.2:iter-sep            -- _1 ", ",

   #R1220 --,
   CallStmt                            -- H hs=1[_1 KW["CALL"] H hs=0[_2 "("_3")" _4]],
   CallStmt.3:iter-sep                 -- _1 ",",

   #R1221 --,
   OfpProcRef                          -- _1,
   ProcedureDesignator                 -- _1,

   #R1222 --,
   OfpArg                              -- _1 _2,
   ActualArgSpec                       -- _1 KW["="] _2,

   #R1224 --,
   AltReturnSpec                       -- KW["*"] _1,

   #R1233 --,
   PpSubroutine                        -- _1,
   SubroutineStmt                      -- H hs=1[_2 _1 KW["SUBROUTINE"] H hs=0[_3 "("_4")" _5 _6]],
   SubroutineStmt.4:iter-sep           -- _1 ",",
   EndSubroutineStmt                   -- H hs=1[_1 "END SUBROUTINE" _2 _3],

   STAR                                -- "*",
   OfpArgList                          -- _1,
   OfpArgList.1:iter-star-sep          -- _1 ",",

   #R1241 --,
   ReturnStmt                          -- H hs=1[_1 KW["RETURN"] _2 _3],

   #R1242 --,
   ContainsStmt                        -- H hs=1[_1 KW["CONTAINS"] _2]


]
