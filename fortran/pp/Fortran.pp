[
   Comment                       -- _1,

   eos                           -- _1,

   no-label                      -- ,
   no-name                       -- ,

   append-colon                  -- _1 ": ",
   append-ptr-assign             -- _1 " => ",

   no-list                       -- ,
   opt-list                      -- ", " _1,
   opt-list.1:iter-sep           -- _1 ",",
   no-comma-opt-list             -- " " _1,
   no-comma-opt-list.1:iter-sep  -- _1 ",",

   CONCURRENT                    -- "CONCURRENT",
   Halo                          -- ", " "HALO" "(" _1 ")",
   HaloAlloc                     -- ", " "HALO" "=" _1,
   HaloExplicitShapeSpec         -- _1 ":*:" _2,
   AssumedShape                  -- ":",
   ConcurrentExecControl         -- " " "CONCURRENT" _1 _2,
   ImageExecStmt                 -- H hs=1[_1 "CALL" H hs=0[_2 "("_3")"] _4 _5],
   ImageExecStmt.3:iter-sep      -- _1 ",",
   ImageExecutionSelector        -- " [[" _1 "]]",

   CoAllocateStmt                -- H hs=1 [_1 H hs=0["ALLOCATE" "("_2 _3 _4")" _5 _6]],
   CoAllocateStmt.3:iter-sep     -- _1 ",",
   CoAllocateStmt.4:iter-sep     -- _1 ", ",
   CoDeallocateStmt              -- H hs=1 [_1 H hs=0["DEALLOCATE" "("_2 _3")" _4 _5]],
   CoDeallocateStmt.2:iter-sep   -- _1 ",",

   clMemObject                   -- "clMemObject(" _1 ")",

   INTRINSIC                     -- "INTRINSIC",
   NON_INTRINSIC                 -- "NON_INTRINSIC",
   PARAMETER                     -- "PARAMETER",

   %% R201
   Program                       -- V vs=0 is=0 [_1],
   Program.1:opt                 -- ,

   %% R204
   SpecPart                      -- V vs=0 is=0[_1],
   ExecPart                      -- V vs=0 is=0[_1],
   FuncPart                      -- V ["\nCONTAINS\n" _1],

   %% R305
   IntLiteralConstant            -- _1 _2,

   %% R312
   Label                         -- _1,

   %% R401
   COLON                         -- ":",

   %% R402
   no-type-spec                  -- ,

   KIND                          -- "KIND",
   LEN                           -- "LEN",

   Kind                          -- H hs=0 ["(" "KIND=" _1 ")"],
   ppLiteralKind                 -- H hs=0 ["_" _1],
   no-kind                       -- ,

   IntVal                        -- _1,
   IntVal                        -- H hs=0[_1 _2],
   RealVal                       -- _1,
   RealVal                       -- H hs=0[_1 _2],

   %% R403
   IntrinsicType                 -- _1,
     %%TODO - fix second arg, type-param-spec-list
   Class                         -- "CLASS" "(" _1 _2 ")",
   AssumedClass                  -- "CLASS(*)",
   AssumedType                   -- "TYPE(*)",

   %% R404
   Type                          -- H hs=1[_1 _2],
   INTEGER                       -- "INTEGER",
   INTEGER                       -- "INTEGER" _1,
   REAL                          -- "REAL",
   REAL                          -- "REAL" _1,
   DOUBLEPRECISION               -- "DOUBLE PRECISION",
   LOGICAL                       -- "LOGICAL",
   LOGICAL                       -- "LOGICAL" _1,
   COMPLEX                       -- "COMPLEX",
   COMPLEX                       -- "COMPLEX" _1,
   DOUBLECOMPLEX                 -- "DOUBLE COMPLEX",

   CHARACTER                     -- "CHARACTER",
   CHARACTER                     -- "CHARACTER" "(" _1 ")",
   CHARACTER                     -- "CHARACTER" "(" _1 ",KIND=" _2 ")",
   ppCharNoLen                   -- "CHARACTER" "(" "KIND=" _1 ")",
   no-length-selector            --,

   %% R406
   SignedIntLiteralConstant      -- _1 _2,

   ppArrayType                   -- _1,
   ppArrayType                   -- _1 _2,
   ppArrayType.1:iter-sep        -- _1 ",",
   ppArrayType.2:iter-sep        -- _1 ",",

   ppCoarrayType                 -- _1,
   ppCoarrayType.1:iter-sep      -- _1 ",",

   ppRange                       -- _1,
   Range                         -- _1 ":" _2,
   no-lower-bound                -- ,
   no-upper-bound                -- ,

   %% R423
   SignedRealLiteralConstant     -- _1 _2,
   ComplexLiteralConstant        -- "(" _1 "," _2 ")",
   CharLiteralConstant           -- _1 _2,

   %% R424
   TRUE                          -- ".TRUE.",
   FALSE                         -- ".FALSE.",
   TRUE                          -- H hs=0[".TRUE."  "_" _1],
   FALSE                         -- H hs=0[".FALSE." "_" _1],

   %% R425
   DerivedTypeDef                -- V vs=0 is=2[_1 _2 _3 _4] _5 _6,
   DerivedTypeStmt               -- H hs=1[_1 "TYPE," H hs=0[_2 " :: " _3 "(" _4 ")"]],
   DerivedTypeStmt.2:iter-sep    -- _1 ", ",
   DerivedTypeStmt.4:iter-sep    -- _1 ",",

   ppDerivedTypeStmt             -- H hs=1[_1 "TYPE" _2],

   ppDerivedTypeStmt_attrs              -- H hs=1[_1 "TYPE," H hs=0[_2 " :: " _3]],
   ppDerivedTypeStmt_attrs.2:iter-sep   -- _1 ", ",

   ppDerivedTypeStmt_params             -- H hs=1[_1 "TYPE" H hs=0[":: " _2 "(" _3 ")"]],
   ppDerivedTypeStmt_params.3:iter-sep  -- _1 ",",


   EndTypeStmt                   -- H hs=1[_1 H hs=0["END TYPE"] _2],

   %% R427
   ABSTRACT                      -- "ABSTRACT",
   Extends                       -- "EXTENDS" "(" _1 ")",
   BIND                          -- "BIND(C)",

   %% R430
   SequenceStmt                  -- H hs=1 [_1 H hs=0["SEQUENCE"]],

   %% R431
   TypeParamDefStmt              -- H hs=1 [_1 H hs=0["INTEGER" H hs=0 [_2 ", " _3 " :: " _4]]],
   TypeParamDefStmt.4:iter-sep   -- _1 ", ",

   %% R432
   TypeParamDecl                 -- _1 " = " _2,
 ppTypeParamDecl                 -- _1,

   DataComponentDefStmt             -- H hs=1[_1 H hs=0[_2 ", " _3 " :: " _4]],
   DataComponentDefStmt.3:iter-sep  -- _1 ", ",
   DataComponentDefStmt.4:iter-sep  -- _1 ", ",
 ppDataComponentDefStmt             -- H hs=1[_1 H hs=0[_2         " :: " _3]],
 ppDataComponentDefStmt.3:iter-sep  -- _1 ", ",
   no-type-bound-procedure-part     --,

   %% R437
   Codimension                   -- "CODIMENSION" "["_1"]",
   Codimension.1:iter-sep        -- _1 ",",

   %% R438
   ComponentDecl                 -- _1 _2 _3 _4 _5,

   %% R440
   ProcComponentDefStmt          -- H hs=1[_1 H hs=0["PROCEDURE" "("_2")" ", " _3 " :: " _4]],
   ProcComponentDefStmt.3:iter-sep   -- _1 ", ",

   %% R441
   POINTER                       -- "POINTER",
   PASS                          -- "PASS",
   NOPASS                        -- "NOPASS",

   %% R445
   TypeBoundProcPart             -- "CONTAINS" _1 _2,

   BindingPrivateStmt            -- H hs=1 [_1 "PRIVATE"],
   no-binding-private-stmt       --,

   %% R448
   TypeBoundProcedureStmt             -- H hs=1[H hs=0[_1 "PROCEDURE" ", " _2 " :: " _3]],
 ppTypeBoundProcedureStmt             -- H hs=1[H hs=0[_1 "PROCEDURE"         " :: " _2]],
   TypeBoundProcedureStmt.2:iter-sep  -- _1 ", ",
   TypeBoundProcedureStmt.3:iter-sep  -- _1 ", ",
 ppTypeBoundProcedureStmt.2:iter-sep  -- _1 ", ",

   TypeBoundProcedureInterfaceStmt    -- H hs=1[_1 H hs=0["PROCEDURE" "(" _2 "), " _3 " :: " _4]],
   TypeBoundProcedureInterfaceStmt.3:iter-sep  -- _1 ", ",
   TypeBoundProcedureInterfaceStmt.4:iter-sep  -- _1 ", ",

   %% R449
   TypeBoundProcDecl             -- _1 " => " _2,
 ppTypeBoundProcDecl             -- _1,

   %% R451
   Pass                          -- "PASS" "(" _1 ")",
   NON_OVERRIDABLE               -- "NON_OVERRIDABLE",
   DEFERRED                      -- "DEFERRED",
   no-arg-name                   --,

   %% R452
   FinalProcedureStmt            -- H hs=1[_1 "FINAL ::" H hs=0[_2]],
   FinalProcedureStmt.2:iter-sep -- _1 ", ",

   %% R453
   DerivedTypeSpec               -- _1 _2,
 ppDerivedType                   -- "TYPE" "("_1            ")",
   DerivedType                   -- "TYPE" "("_1 "(" _2 ")" ")",
   DerivedType.2:iter-sep        -- _1 ",",

   %% R454
   TypeParamSpec                 -- _1 "=" _2,
 ppTypeParamSpec                 -- _1,

   %% R455
   StructureConstructor          -- _1 "("_2")",
%%   StructureConstructor.2:iter-sep   -- _1 ", ",

   %% R458
   EnumDef                       -- V vs=0 is=2 [_1 _2] _3,

   %% R459
   EnumDefStmt                   -- H hs=1[_1 H hs=0["ENUM" ", " "BIND(C)"]],

   %% R460
   EnumeratorDefStmt             -- H hs=1[_1 "ENUMERATOR" "::" H hs=0[_2]],
   EnumeratorDefStmt.2:iter-sep  -- _1 ", ",

   %% R461
   Enumerator                    -- _1 "=" _2,
 ppEnumerator                    -- _1,

   %% R462
   EndEnumStmt                   -- H hs=1[_1 "END ENUM"],

   %% R463
   BozLiteralConstant_BC         -- H hs=0[_1],
   BozLiteralConstant_OC         -- H hs=0[_1],
   BozLiteralConstant_HC         -- H hs=0[_1],

   %% R468
   ArrayConstructor              -- H hs=0["[" _1 "]"],

   %% R469
   AcSpec                        -- _1 _2,
   AcSpec.2:iter-sep             -- _1 ",",

   %% R473
   AcImpliedDo                   -- "("_1 ", " _2")",

   %% R474
   AcImpliedDoControl            -- _1 "=" _2 ", " _3 _4,

   %% R501
   TypeDeclarationStmt               -- H hs=1 [_1 H hs=0[_2 ", " _3 " :: " _4]],
   TypeDeclarationStmt.3:iter-sep    -- _1 ", ",
   TypeDeclarationStmt.4:iter-sep    -- _1 ", ",

   ppTypeDeclarationStmt             -- H hs=1 [_1 H hs=0[_2 " :: " _3]],
   ppTypeDeclarationStmt.3:iter-sep  -- _1 ", ",

   %% R502
   ALLOCATABLE                   -- "ALLOCATABLE",
   ASYNCHRONOUS                  -- "ASYNCHRONOUS",
   CONTIGUOUS                    -- "CONTIGUOUS",
   EXTERNAL                      -- "EXTERNAL",
   OPTIONAL                      -- "OPTIONAL",
   PROTECTED                     -- "PROTECTED",
   SAVE                          -- "SAVE",
   TARGET                        -- "TARGET",
   VALUE                         -- "VALUE",
   VOLATILE                      -- "VOLATILE",
   Intent                        -- "INTENT" "("_1")",
   Dimension                     -- "DIMENSION" "("_1")",
   Dimension.1:iter-sep          -- _1 ",",

   IN                            -- "IN",
   OUT                           -- "OUT",
   INOUT                         -- "INOUT",

   %% R503
   ppVar                         -- _1 _2,
   ppVarLen                      -- _1 "*" _2 _3,
   ppArrayVar                    -- _1 _2 _3,
   ppArrayVarLen                 -- _1 _2 "*" _3 _4,

   %% R505
   Init                          -- " = " _1,
   PointerInit                   -- " => " _1,
   no-init                       -- ,

   %% R507
   PRIVATE                       -- "PRIVATE",
   PUBLIC                        -- "PUBLIC",
   
   %% R508
   LanguageBinding               -- H hs=0["BIND(C" _1 ")"],
   BindingName                   -- ",NAME=" _1,
   no-language-binding           -- ,
   no-binding-name               -- ,
   
   %% R509
   CoarraySpec                   -- "[" _1 "]",
   CoarraySpec.1:iter-sep        -- _1 ",",

   %% R515
   ArraySpec                     -- "(" _1 ")",
   ArraySpec.1:iter-sep          -- _1 ",",

   %% R523
   IN                            -- "IN",

   %% R524
   AccessStmt                    -- H hs=1[_1 _2 H hs=0[_3]],
   AccessStmt.3:iter-sep         -- _1 ", ",

   %% 526
   AllocatableStmt               -- H hs=1[_1 "ALLOCATABLE ::" H hs=0[_2]],
   AllocatableStmt.2:iter-sep    -- _1 ", ",

   %% R529
   BindStmt                      -- H hs=1[_1 _2 "::" H hs=0[_3]],
   BindStmt.3:iter-sep           -- _1 ", ",

   %% R531
   CodimensionStmt               -- H hs=1[_1 "CODIMENSION ::" H hs=0[_2 _3]],
   CodimensionStmt.2:iter-sep    -- _1 ", ",

   %% R532
   CodimensionDecl               -- _1 "["_2"]",
   CodimensionDecl.2:iter-sep    -- _1 ", ",

   %% R533
   ContiguousStmt                -- H hs=1 [_1 H hs=0["CONTIGUOUS :: " _2]],
   ContiguousStmt.2:iter-sep     -- _1 ", ",

   %% R534
   DataStmt                      -- H hs=1[_1 "DATA" H hs=0[_2]],
   DataStmt.2:iter-sep           -- _1 ", ",

   %% R535
   DataStmtSet                   -- H hs=0[_1 "/"_2"/"],
   DataStmtSet.1:iter-sep        -- _1 ", ",
   DataStmtSet.2:iter-sep        -- _1 ",",

   %% R537
   DataImpliedDo                 -- "("_1 ", " _2 "=" _3 "," _4 _5")",
   DataImpliedDo.1:iter-sep      -- _1 ", ",

   %% R539
   DataIDoVariable               -- _1,

   %% R540
   DataStmtValue                 -- _1 _2,
   DataStmtRepeat                -- _1 "*",

   no-repeat                     -- ,

   %% R545
   DimensionStmt                 -- H hs=1 [_1 H hs=0["DIMENSION :: " _2]],
   DimensionStmt.2:iter-sep      -- _1 ", ",

   ArrayNameSpec                 -- _1 "(" _2 ")",
   ArrayNameSpec.2:iter-sep      -- _1 ",",

   %% R546
   IntentStmt                    -- H hs=1 [_1 H hs=0["INTENT(" _2 ") :: " _3]],
   IntentStmt.3:iter-sep         -- _1 ", ",

   %% R547
   OptionalStmt                  -- H hs=1 [_1 H hs=0["OPTIONAL :: " _2]],
   OptionalStmt.2:iter-sep       -- _1 ", ",

   %% R548
   ParameterStmt                 -- H hs=1 [_1 H hs=0["PARAMETER(" _2 ")"]],
   ParameterStmt.2:iter-sep      -- _1 ", ",

   NamedConstantDef              -- _1 "=" _2,

   %% R550
   PointerStmt                   -- H hs=1 [_1 H hs=0["POINTER :: " _2]],
   PointerStmt.2:iter-sep        -- _1 ", ",

   CrayPointerStmt               -- H hs=1 [_1 H hs=0["POINTER(" _2 "," _3 ")"]],

   %% R551
   PointerDecl                   -- _1 "(" _2 ")",
   PointerDecl.2:iter-sep        -- _1 ",",

   %% R552
   ProtectedStmt                 -- H hs=1 [_1 H hs=0["PROTECTED :: " _2]],
   ProtectedStmt.2:iter-sep      -- _1 ", ",

   %% R553
   ppSaveStmt                    -- H hs=1[_1 "SAVE"],
   SaveStmt                      -- H hs=1[_1 "SAVE ::" H hs=0[_2]],
   SaveStmt.2:iter-sep           -- _1 ", ",

   %% R554
   SavedEntity                   -- _1,
   SavedEntity_CBN               -- _1,

   %% R556
   TargetStmt                    -- H hs=1 [_1 H hs=0["TARGET :: " _2]],
   TargetStmt.2:iter-sep         -- _1 ", ",

   %% R557
   ppTargetDecl                  -- _1 _2 _3,
   ppTargetDecl.2:iter-sep       -- _1 ", ",
   ppTargetDecl.3:iter-sep       -- _1 ", ",
   ppArraySpec                   -- "(" _1 ")",
   ppCorraySpec                  -- "[" _1 "]",

   %% R558
   ValueStmt                     -- H hs=1 [_1 H hs=0["VALUE :: " _2]],
   ValueStmt.2:iter-sep          -- _1 ", ",

   %% R559
   VolatileStmt                  -- H hs=1 [_1 H hs=0["VOLATILE :: " _2]],
   VolatileStmt.2:iter-sep       -- _1 ", ",

   %% R560
   ppImplicitStmt                -- H hs=1[_1 "IMPLICIT NONE"],
   ImplicitStmt                  -- H hs=1[_1 "IMPLICIT" H hs=1[_2 _3]],
   ImplicitStmt.2:iter-sep       -- _1 ", ",

   %% R561
   ImplicitSpec                  -- _1 "("_2")",
   ImplicitSpec.2:iter-sep       -- _1 ", ",

   %% R562
   LetterSpec                    -- _1 _2,
   ppLetterSpec                  -- _1,
   ppLetterSpec                  -- _1 "-" _2,

   %% R563
   NamelistStmt                  -- H hs=1[_1 "NAMELIST" H hs=0[_2]],
   NamelistEntry                 -- "/"_1"/ " _2,
   NamelistEntry.2:iter-sep      -- _1 ", ",

   %% R565
   EquivalenceStmt               -- H hs=1[_1 "EQUIVALENCE" H hs=0[_2]],
   EquivalenceStmt.2:iter-sep    -- _1 ", ",

   %% R566
   EquivalenceSet                -- "("_1")",
   EquivalenceSet.1:iter-sep     -- _1 ", ",

   %% R568
   CommonStmt                    -- H hs=1[_1 "COMMON" H hs=0[ _2]],
   CommonStmt.2:iter-sep         -- _1 ", ",
   CommonBlockEntry              -- "/" _1 "/ " _2,
   CommonBlockEntry.2:iter-sep   -- _1 ", ",
   CommonBlockName               -- "/" _1 "/",

   %% R569
   CommonBlockObject             -- _1 _2,

   %% R608
   Substring                     -- H hs=0 [_1 _2],

   %% R610
   SubstringRange                -- H hs=0 ["(" _1 ":" _2 ")"],

   %% R611
   DataRef                       -- H hs=0 [_1],
   DataRef.1:iter-sep            -- _1 "%",

   %% R612
   VarDef                           -- _1,
   VarRef                           -- _1,
   ppPartRef                        -- H hs=0[_1 _2 _3],
   ppSectionSubscripts              -- "(" _1 ")",
   ppSectionSubscripts.1:iter-sep   -- _1 ",",
   ppImageSelector                  -- "[" _1 "]",
   ppImageSelector.1:iter-sep       -- _1 ",",
   no-section-subscripts            -- ,
   no-image-selector                -- ,

   ppTriplet                        -- _1 ":" _2 _3 _4,
   no-subscript                     -- ,
   no-stride                        -- ,

   %% R626
   ppAllocateStmt                -- H hs=1 [_1 H hs=0["ALLOCATE" "("_2 _3         ")"]],
   ppAllocateStmt                -- H hs=1 [_1 H hs=0["ALLOCATE" "("_2 _3 ", " _4 ")"]],
   ppAllocateStmt.3:iter-sep     -- _1 ",",
   ppAllocateStmt.4:iter-sep     -- _1 ", ",

   ppTypeSpec                    -- _1 ":: ",

   ERRMSG                        -- "ERRMSG=" _1,
   MOLD                          --           _1,
   SOURCE                        -- "SOURCE=" _1,
   STAT                          -- "STAT="   _1,

   ppDeallocateStmt              -- H hs=1 [_1 H hs=0["DEALLOCATE" "("_2         ")"]],
   ppDeallocateStmt              -- H hs=1 [_1 H hs=0["DEALLOCATE" "("_2 ", " _3 ")"]],
   ppDeallocateStmt.2:iter-sep   -- _1 ",",
   ppDeallocateStmt.3:iter-sep   -- _1 ", ",

   Allocation                    -- _1 "("_2")" "["_3"]",
   Allocation.2:iter-sep         -- _1 ",",
   Allocation.3:iter-sep         -- _1 ",",
 ppAllocation                    -- _1,
 ppAllocationShape               -- _1 "("_2")",
 ppAllocationShape.2:iter-sep    -- _1 ",",
 ppAllocationCoshape             -- _1 "["_2"]",
 ppAllocationCoshape.2:iter-sep  -- _1 ",",
   Triplet                       -- _1 ":" _2 _3,

   %% R638
   NullifyStmt                   -- H hs=1 [_1 H hs=0 ["NULLIFY" "("_2")" _3]],
   NullifyStmt.2:iter-sep        -- _1 ", ",

   %% R640
   DeallocateStmt                -- H hs=1 [_1 H hs=0 ["DEALLOCATE" "("_2 _3")" _4]],
   DeallocateStmt.2:iter-sep     -- _1 ",",

   %% Operators (unary and binary)
   UnaryMinus                    -- H hs=0["-" _1],
   UnaryPlus                     -- H hs=0["+" _1],
   Minus                         -- H hs=0[_1 "-" _2],
   NOT                           -- H hs=0[".NOT. " _1],
   Plus                          -- H hs=0[_1 "+" _2],
   GT                            -- H hs=0[_1 " > " _2],
   LT                            -- H hs=0[_1 " < " _2],
   NE                            -- H hs=0[_1 " /= " _2],
   EQ                            -- H hs=0[_1 " == " _2],
   LE                            -- H hs=0[_1 " <= " _2],
   GE                            -- H hs=0[_1 " >= " _2],
   AND                           -- H hs=0[_1 " .AND. " _2],
   OR                            -- H hs=0[_1 " .OR. " _2],
   EQV                           -- H hs=0[_1 " .EQV. " _2],
   NEQV                          -- H hs=0[_1 " .NEQV. " _2],
   DefUnaryExpr                  -- H hs=1[_1 _2],
   DefBinExpr                    -- H hs=0[_1 " " _2 " " _3],
   Power                         -- H hs=0[H hs=0[_1] "**" _2],
   Mult                          -- H hs=0[_1 "*" _2],
   Div                           -- H hs=0[_1 "/" _2],
   Concat                        -- H hs=1[_1 "//" _2],

   Parens                        -- H hs=0["(" _1 ")"],

   %% R707
   PowerOp                       -- "**",

   %% R708 MultOp
   TIMES                         -- "*",
   DIV                           -- "/",

   %% R709 AddOp
   PLUS                          -- "+",
   MINUS                         -- "-",

   %% R711
   ConcatOp                      -- "//",

   %% RelOp
   RelOp_EQ                      -- "==",
   RelOp_NE                      -- "/=",
   RelOp_LT                      -- "<",
   RelOp_LE                      -- "<=",
   RelOp_GT                      -- ">",
   RelOp_GE                      -- ">=",

   %% R718
   NotOp                         -- ".NOT.",

   %% R719
   AndOp                         -- ".AND.",

   %% R720
   OrOp                          -- ".OR.",

   %% R720 EquivOp
   EquivOp_EQV                   -- ".EQV.",
   EquivOp_NEQV                  -- ".NEQV.",

   %% R732
   AssignmentStmt                -- H hs=1[_1 H hs=0[_2          " = "  _3]],

   ppPointerAssignmentStmt       -- H hs=1[_1 H hs=0[_2          " => " _3]],
   ppPointerAssignmentStmt       -- H hs=1[_1 H hs=0[_2 "("_3")" " => " _4]],
   ppPointerAssignmentStmt.3:iter-sep  -- _1 ",",

   ppDataPointerObject           -- _1,
     DataPointerObject           -- _1 "%" _2,

   %% R739
   ProcComponentRef              --  _1 "%" _2,

   %% R741
   WhereStmt                     -- H hs=1[_1 "WHERE" H hs=0["("_2")"] _3],

   %% R742
   WhereConstruct                -- V vs=0 is=2 [_1 _2 ] _3 _4 _5,
   ElsewhereClause               -- V vs=0 is=2 [_1 _2],
   no-elsewhere-clause           -- ,

   %% R743
   WhereConstructStmt            -- H hs=1[_1 H hs=0[_2 ": " "WHERE" " " "(" _3 ")"]],
 ppWhereConstructStmt            -- H hs=1[_1 H hs=0[        "WHERE" " " "(" _2 ")"]],

   %% R747
   MaskedElsewhereClause         -- V vs=0 is=2 [_1 _2],
   MaskedElsewhereStmt           -- H hs=1[_1 H hs=0["ELSE WHERE" " " "(" _2 ")"] _3],

   %% R748
   ElsewhereStmt                 -- H hs=1[_1 H hs=0["ELSE WHERE"] _2],

   %% R749
   EndWhereStmt                  -- H hs=1[_1 H hs=0["END WHERE"] _2],
   ElsewhereClause               -- V vs=0 is=2 [_1 _2],

   %% R750
   ForallConstruct               -- _1 _2 _3,

   ForallConstructStmt           -- H hs=1[_1 _2 "FORALL" H hs=0[_3]],

   ForallHeader                  -- "("_1 _2 _3")",
   ForallHeader.2:iter-sep       -- _1 ", ",
   no-mask-expr                  -- ,

   ForallTripletSpec             -- _1 "=" _2 ":" _3 _4,
   no-forall-step                -- ,

   EndForallStmt                 -- H hs=1[_1 "END FORALL" H hs=0[_2]],

   %% R801
   AssociateConstruct            -- _1 _2 _3,

   AssociateStmt                 -- H hs=1[_1 H hs=0[_2 "ASSOCIATE" "("_3")"]],
   AssociateStmt.3:iter-sep      -- _1 ", ",
   EndAssociateStmt              -- H hs=1 [_1 "END ASSOCIATE" H hs=0[_2]],

   Association                   -- _1 "=>" _2,

   Block                         -- H [_1 _2 ":" "BLOCK"] _3 _4,
   ppBlock                       -- H [_1 "BLOCK"] _2 _3,
   EndBlockStmt                  -- H [_1 "END BLOCK" _2],

   %% R814
   BlockDoConstruct              -- V is=2 [_1 _2] _3,

   %% R816
   LabelDoStmt                   -- H hs=1[_1 _2 "DO" H hs=0[_3] H hs=0[_4]],

   %% R817
   NonlabelDoStmt                -- H hs=1[_1 H hs=0[_2 ": DO" _3]],
   ppNonlabelDoStmt              -- H hs=1[_1 H hs=0["DO" _2]],

   %% R818
   LoopControl                   -- H hs=0[" " _1 " = " H hs=0[_2 ", " _3 _4]],
   LoopWhileControl              -- "WHILE" "("_1")",
   LoopConcurrentControl         -- " " "CONCURRENT" _1,
   no-loop-control               -- ,

   %% R822
   EndDoStmt                     -- H hs=1 [_1 "END DO" H hs=0[_2]],

   %% R831
   CycleStmt                     -- H hs=1 [_1 "CYCLE" H hs=0[_2]],

   %% R832
   IfConstruct                   -- V vs=0 is=2 [_1 _2] _3 _4 _5,
   ElseIfStmtBlock               -- V vs=0 is=2 [_1 _2],
   ElseStmtBlock                 -- V vs=0 is=2 [_1 _2],

   %% R833
   ppIfThenStmt                  -- H hs=1 [_1 H hs=0[_2 "IF" " (" _3 ")"] "THEN"],

   %% R834
   ElseIfStmt                    -- H hs=1 [_1 "ELSE IF" H hs=0["(" _2 ")"] "THEN" _3],

   %% R835
   ElseStmt                      -- H hs=1 [_1 "ELSE" _2],

   %% R836
   EndIfStmt                     -- H hs=1 [_1 "END IF" _2],

   %% R837
   IfStmt                        -- H hs=1 [_1 "IF" H hs=0["(" _2 ")"] _3],

   no-else-stmt                  -- ,

   %% R838
   CaseConstruct                 -- V vs=0 is=2 [_1 _2] _3,
   CaseStmtBlock                 -- V vs=0 is=2 [_1 _2],

   %% R839
 ppSelectCaseStmt                -- H hs=1[_1 H hs=0 [_2 "SELECT CASE" "("_3")"]],

   %% R840
   CaseStmt                      -- H hs=1[_1 "CASE" H hs=0["("_2")"] _3],
 ppDefaultCaseStmt               -- H hs=1[_1 "CASE" "DEFAULT" _2],
   CaseStmt.2:iter-sep           -- _1 ", ",

   %% R841
   EndSelectStmt                 -- H hs=1[_1 "END SELECT" _2],

   %% R843
   DEFAULT                       -- "DEFAULT",

   %% R844
   CaseValueRange                -- _1 ":" _2,
   no-low                        --,
   no-high                       --,

   %% R845
   CaseValue                     -- _1,

   %% R846
   SelectTypeConstruct           -- V is=2 [_1 _2] _3,
   TypeGuardStmtBlock            -- V is=2 [_1 _2],

   %% R847
   ppSelectTypeStmt              -- H hs=1[_1 H hs=0[_2 "SELECT TYPE"] H hs=0["("_3 _4")"]],

   %% R848
   TypeGuardStmt                 -- H hs=1[_1 "TYPE IS"  H hs=0["(" _2 ")"] _3],
   ClassGuardStmt                -- H hs=1[_1 "CLASS IS" H hs=0["(" _2 ")"] _3],
   DefaultGuardStmt              -- H hs=1[_1 "CLASS DEFAULT" _2],

   %% R849
   EndSelectTypeStmt             -- H hs=1 [_1 "END SELECT" _2],

   %% R850
   ExitStmt                      -- H hs=1 [_1 "EXIT" H hs=0[_2]],

   GotoStmt                      -- H hs=1 [_1 "GO TO" _2],

   ComputedGotoStmt              -- H hs=1 [_1 "GO TO" H hs=0["("_2")"] H hs=0[_3]],
   ComputedGotoStmt.2:iter-sep   -- _1 ", ",

   ArithmeticIfStmt              -- H hs=1 [H hs=0[_1 "IF" "("_2")"] H hs=0 [_3 ", " _4 ", " _5]],
     
   ContinueStmt                  -- H hs=1 [_1 "CONTINUE"],

   StopStmt                      -- H hs=1 [_1 "STOP" _2],
   no-stop-code                  -- ,

   ErrorStopStmt                 -- H hs=1 [_1 "ERROR STOP" _2],

   PauseStmt                     -- H hs=1 [_1 "PAUSE" H hs=0 [_2]],

   SyncAllStmt                   -- H hs=1 [_1 "SYNC ALL" H hs=0 ["(" _2 ")"]],
   SyncAllStmt.2:iter-sep        -- _1 ", ",

   %% R860
   SyncImagesStmt                -- H hs=1 [_1 "SYNC IMAGES" H hs=0 ["(" _2 _3 ")"]],
   SyncImagesStmt.3:iter-sep     -- _1 ", ",
 
   SyncMemoryStmt                -- H hs=1 [_1 "SYNC MEMORY" H hs=0 ["("_2")"]],
   SyncMemoryStmt.2:iter-sep     -- _1 ", ",

   LockStmt                      -- H hs=1 [_1 "LOCK" H hs=0 ["("_2 _3")"]],
   LockStmt.3:iter-sep           -- _1 ", ",

   ACQUIRED_LOCK                 -- "ACQUIRED_LOCK=" _1,

   UnlockStmt                    -- H hs=1 [_1 "UNLOCK" H hs=0 ["("_2 _3")"]],

   %% R900
   IOMSG                         -- "IOMSG="  _1,
   UNIT                          -- "UNIT="   _1,
   ERR                           -- "ERR="    _1,
   IOSTAT                        -- "IOSTAT=" _1,
   END                           -- "END="    _1,
   EOR                           -- "EOR="    _1,

   OpenStmt                      -- H hs=1 [_1 H hs=0["OPEN"  "(" _2 ")"]],
   OpenStmt.2:iter-sep           -- _1 ", ",

   ACCESS                        -- "ACCESS="       _1,
   ACTION                        -- "ACTION="       _1,
   ASYNCHRONOUS                  -- "ASYNCHRONOUS=" _1,
   BLANK                         -- "BLANK="        _1,
   DECIMAL                       -- "DECIMAL="      _1,
   DELIM                         -- "DELIM="        _1,
   ENCODING                      -- "ENCODING="     _1,
   FILE                          -- "FILE="         _1,
   FORM                          -- "FORM="         _1,
   NEWUNIT                       -- "NEWUNIT="      _1,
   PAD                           -- "PAD="          _1,
   POSITION                      -- "POSITION="     _1,
   RECL                          -- "RECL="         _1,
   ROUND                         -- "ROUND="        _1,
   SIGN                          -- "SIGN="         _1,
   STATUS                        -- "STATUS="       _1,
   TEAM                          -- "TEAM="         _1,

   %% R908
   CloseStmt                     -- H hs=1 [_1 H hs=0["CLOSE" "(" _2 ")"]],
   CloseStmt.2:iter-sep          -- _1 ", ",

   %% R910
   ppReadStmt                    -- H hs=1 [_1 H hs=0["READ" "(" _2 ")" _3]],
   ppReadStmt.2:iter-sep         -- _1 ",",

   ppReadFMTStmt                 -- H hs=1 [_1 H hs=0["READ " _2 _3]],

   %% R911
   ppWriteStmt                   -- H hs=1 [_1 H hs=0["WRITE" "("_2")" _3]],
   ppWriteStmt.2:iter-sep        -- _1 ",",

   %% R912
   ppPrintStmt                   -- H hs=1 [_1 "PRINT" H hs=0[_2 _3]],

   FMT-or-NML                    --            _1,
   FMT                           -- "FMT="     _1,
   SIZE                          -- "SIZE="    _1,
   ADVANCE                       -- "ADVANCE=" _1,
   REC                           -- "REC="     _1,

   Format_STAR                   -- "*",
   Format                        -- _1,

   %% R917
   OutputItem                    -- _1,

   %% R918
   IoImpliedDo                   -- "("_1 ", " _2")",
   IoImpliedDo.1:iter-sep        -- _1 ", ",

   %% R919
   IoImpliedDoObjectList         -- _1,

   %% R920
   IoImpliedDoControl            -- _1 "=" _2 "," _3 "," _4,
   ppIoImpliedDoControl          -- _1 "=" _2 "," _3,

   %% R922
   WaitStmt                      -- H hs=1 [_1 "WAIT" H hs=0["("_2")"]],
   WaitStmt.2:iter-sep           -- _1 ", ",

   %% R924
   BackspaceStmt                 -- H hs=1 [_1 "BACKSPACE" H hs=0 ["("_2")"]],
   BackspaceStmt.2:iter-sep      -- _1 ", ",

   %% R926
   RewindStmt                    -- H hs=1 [_1 "REWIND" H hs=0["("_2")"]],
   RewindStmt.2:iter-sep         -- _1 ", ",

   %% R928
   FlushStmt                     -- H hs=1 [_1 "FLUSH" H hs=0["("_2")"]],
   FlushStmt.2:iter-sep          -- _1 ", ",

   %% R930
   InquireStmt                   -- H hs=1 [_1 "INQUIRE" H hs=0["("_2")"]],
   InquireStmt.2:iter-sep        -- _1 ", ",
   InquireLengthStmt             -- H hs=1 [_1 "INQUIRE" H hs=0["(" "IOLENGTH=" _2 ")"] H hs=0[_3]],
   InquireLengthStmt.3:iter-sep  -- _1 ", ",

   %% R1001
   FormatStmt                    -- H hs=1[_1 H hs=0 ["FORMAT" "("_2")"]],
   FormatStmt.2:iter-sep         -- _1 ",",

   FormatSpec                    -- _1 _2,
   FormatSpec.1:iter-sep         -- _1 ",",

   %% R1005
   UnlimitedFormatItem              -- "*" "(" _1 ")",
   UnlimitedFormatItem.1:iter-sep   -- _1 ",",

   %% R1006
   R                             -- _1 "("_2")",
   R.2:iter-sep                  -- _1 ",",

   %% R1007
   I                             -- _1 "I" _2 _3,
   B                             -- _1 "B" _2 _3,
   O                             -- _1 "O" _2 _3,
   Z                             -- _1 "Z" _2 _3,

   F                             -- _1 "F"  _2 "." _3,
   E                             -- _1 "E"  _2 "." _3 _4,
   EN                            -- _1 "EN" _2 "." _3 _4,
   ES                            -- _1 "ES" _2 "." _3 _4,
   G                             -- _1 "G"  _2 "." _3 _4,
   GnoDnoE                       -- _1 "G"  _2,

   L                             -- _1 "L" _2,
   A                             -- _1 "A" _2,

   D                             -- _1 "D"  _2 "." _3,
   DT                            -- _1 "DT" _2     _3,

   VEditDescList                 -- "(" _1 ")",
   VEditDescList.1:iter-sep      -- _1 ",",

   opt-e                         -- "E" _1,

%% R1008
   opt-w                         -- _1,
   no-w                          -- ,

%% R1009
   opt-m                         -- "." _1,
   no-m                          -- ,

%% R1011
   no-e                          -- ,

%% R1013
   SLASH                         -- _1 "/",
   no-r                          -- ,
   COLON_ED                      -- ":",
   P                             -- _1 "P",

%% R1015
   T                             -- "T"  _1,
   TL                            -- "TL" _1,
   TR                            -- "TR" _1,
   X                             -- _1 "X",

%% R1017
   SS                            -- "SS",
   SP                            -- "SP",
   S                             -- "S" ,

%% R1018
  BN                            -- "BN",
  BZ                            -- "BZ",

%% R1019
  RU                            -- "RU",
  RD                            -- "RD",
  RZ                            -- "RZ",
  RN                            -- "RN",
  RC                            -- "RC",
  RP                            -- "RP",

%% R1020
  DC                            -- "DC",
  DP                            -- "DP",

%% R1021
   CS                            -- _1,

   %% R1101
   MainProgram                   -- V [_1 _2 _3],
   MainProgram.1:opt             -- ,

   ProgramStmt                   -- H [_1     "PROGRAM" _2],
   EndProgramStmt                -- H [_1 "END PROGRAM" _2],
   no-program-stmt               -- ,
   no-program-name               -- ,

   %% R1104
   Module                        -- V vs=0 [_1 _2 _3],

   ModuleStmt                    -- H hs=1 [_1     "MODULE" _2],
   EndModuleStmt                 -- H hs=1 [_1 "END MODULE" _2],
   no-module-name                -- ,

   %% R1109
   ppUseStmt                     -- H hs=1 [_1 "USE" H hs=0[_2 _3]],
   UseStmt                       -- H hs=1 [_1 "USE" H hs=0[_2 _3 ", " _4]],
   UseStmt.4:iter-sep            -- _1 ", ",
   UseOnlyStmt                   -- H hs=1 [_1 "USE" H hs=0[_2 _3 ", ONLY: " _4]],
   OnlyList                      -- _1,
   OnlyList.1:iter-sep           -- _1 ", ",

   %% R1110
   ModuleNature                  -- ", " _1 " :: ",
   no-module-nature              --,

   %% R1111
   Rename                        -- H hs=0[_1 "=>" _2],
   RenameOp                      -- H hs=0["OPERATOR" "(" _1 ")" "=>" "OPERATOR" "(" _2 ")"],

   %% R1116
   Submodule                     -- V vs=0 [_1 _2 _3],

   SubmoduleStmt                 -- H hs=1 [_1 "SUBMODULE" H hs=0["("_2")"] _3],
   EndSubmoduleStmt              -- H hs=1 [_1 "END SUBMODULE" H hs=0[_2]],
   no-parent-submodule-name      -- ,

   ParentIdentifier              -- _1 _2,

   %% R1120
   BlockData                     -- V vs=0 is=2 [_1 _2] _3,

   BlockDataStmt                 -- H hs=1 [_1 "BLOCK DATA" _2],
   EndBlockDataStmt              -- H hs=1 [_1 "END BLOCK DATA" _2],
   no-block-data-name            -- ,

   %% R1201
   InterfaceBlock             -- V vs=0 [_1 _2 _3],
   InterfaceStmt              -- H hs=1 [_1 "INTERFACE" _2],
   AbstractInterfaceStmt      -- H hs=1 [_1 "ABSTRACT INTERFACE"],
   EndInterfaceStmt           -- H hs=1 [_1 "END INTERFACE" _2],
   InterfaceBody              -- _1 _2 _3,
   no-generic-spec            --,

   %% R1205
   ppScope                       -- _1 _2,
   ppScope                       -- _1 _2 _3,

   ELEMENTAL                           -- "ELEMENTAL",
   IMPURE                              -- "IMPURE",
   MODULE                              -- "MODULE",
   PURE                                -- "PURE",
   RECURSIVE                           -- "RECURSIVE",

   %% R1206
   ProcedureStmt                       -- H hs=1[_1 "PROCEDURE ::" H hs=0[_2]],
   ProcedureStmt.2:iter-sep            -- _1 ", ",
   ModuleProcedureStmt                 -- H hs=1[_1 "MODULE PROCEDURE ::" H hs=0[_2]],
   ModuleProcedureStmt.2:iter-sep      -- _1 ", ",

   %% R1207
   OfpGenericSpec                      -- _1,
   ASSIGNMENT                          -- "ASSIGNMENT(=)",
   OPERATOR                            -- H hs=0[ "OPERATOR" "(" _1 ")" ],

   %% R1209
   ImportStmt                          -- H hs=1[_1 "IMPORT" H hs=0[_2]],
   ImportStmt.2:iter-sep               -- _1 ", ",

   %% R1210
   ExternalStmt                        -- H hs=1[_1 "EXTERNAL ::" H hs=0[_2]],
   ExternalStmt.2:iter-sep             -- _1 ", ",

   %% R1211
   ProcedureDeclarationStmt            --H hs=1[_1 "PROCEDURE" _2 H hs=0["("_3")"] H hs=0[_4]],
   ProcedureDeclarationStmt.4:iter-sep -- _1 ", ",
   no-proc-interface                   -- ,
  
   %% R1214
   ProcDecl                            -- _1 "=>" _2,
 ppProcDecl                            -- _1,

   %% R1217
   Function                            -- V vs=0 [_1 _2 _3],
   FunctionStmt                        -- H hs=1[_1 _2 "FUNCTION" H hs=0[_3 "("_4")" _5 _6]],
   FunctionStmt.4:iter-sep             -- _1 ",",
   EndFunctionStmt                     -- H hs=1[_1 "END FUNCTION" _2],
   no-function-name                    -- ,
   Result                              -- " RESULT(" _1 ")",
   no-result                           -- ,

   %% R1218
   IntrinsicStmt                       -- H hs=1[_1 "INTRINSIC ::" H hs=0[_2]],
   IntrinsicStmt.2:iter-sep            -- _1 ", ",

   %% R1219
   FunctionReference                   -- H hs=0[_1 "("_2")"],
   FunctionReference.2:iter-sep        -- _1 ",",

   %% R1220
   CallStmt                            -- H hs=1[_1 "CALL" H hs=0[_2 "("_3")"]],
   CallStmt.3:iter-sep                 -- _1 ",",

   %% R1222

   %%TODO - fix this in ofp2fast (is a FunctionReference rather than PartRef)
   KeywordArgSpec                      -- _1 "=" _2,

   Arg                                 -- _1,
   Arg                                 -- _1 "=" _2,
   ppArg                               -- _1,
   AltReturn                           -- "*" _1,
   AltReturnSpec                       -- "*" _1,
   no-keyword                          -- ,

   %% R1231
   Suffix                              -- _1 _2,

   %% R1233
   Subroutine                          -- V [_1 _2 _3],
   SubroutineStmt                      -- H [_1 _2 "SUBROUTINE" H hs=0[_3 "("_4")"] _5],
   SubroutineStmt.4:iter-sep           -- _1 ",",
   EndSubroutineStmt                   -- H hs=0 [H hs=1[_1 "END SUBROUTINE" _2] "\n"],

   STAR                                -- "*",

   no-prefix                           -- ,
   no-subroutine-name                  -- ,

   %% R1237
   MpSubprogram                        -- _1 _2 _3,
   MpSubprogramStmt                    -- H hs=1 [_1 "MODULE PROCEDURE" _2],
   EndMpSubprogramStmt                 -- H hs=1 [_1 "END PROCEDURE" _2],
   no-procedure-name                   -- ,

   ReturnStmt                          -- H hs=1 [_1 "RETURN" _2],
   no-expr                             --,

   %% R1240
   EntryStmt                           -- H hs=1 [_1 "ENTRY" H hs=0 [_2 "(" _3 ")" _4]],
   EntryStmt.3:iter-sep                -- _1 ",",
   no-suffix                           --

]
