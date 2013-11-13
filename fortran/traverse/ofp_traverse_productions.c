#include "traversal.h"

#define USE_FINISHED

/**                                                                                             
 * Section/Clause 2: Fortran concepts
 */

//========================================================================================
// R201 program
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_Program(ATerm term, pOFP_Traverse Program)
{
#ifdef DEBUG_PRINT
   printf("\nProgram: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse StartCommentBlock, ProgramUnit;
 if (ATmatch(term, "Program(<term>,<term>)", &StartCommentBlock.term, &ProgramUnit.term)) {

   if (ATmatch(StartCommentBlock.term, "Some(<term>)", &StartCommentBlock.term)) {
      if (ofp_traverse_StartCommentBlock(StartCommentBlock.term, &StartCommentBlock)) {
         // MATCHED StartCommentBlock
      } else return ATfalse;
   }

   ATermList ProgramUnit_tail = (ATermList) ATmake("<term>", ProgramUnit.term);
   while (! ATisEmpty(ProgramUnit_tail)) {
      ProgramUnit.term = ATgetFirst(ProgramUnit_tail);
      ProgramUnit_tail = ATgetNext (ProgramUnit_tail);
      if (ofp_traverse_ProgramUnit(ProgramUnit.term, &ProgramUnit)) {
         // MATCHED ProgramUnit
      } else return ATfalse;
   }

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R202 program-unit
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_ProgramUnit(ATerm term, pOFP_Traverse ProgramUnit)
{
#ifdef DEBUG_PRINT
   printf("\nProgramUnit: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse BlockData;
 if (ATmatch(term, "ProgramUnit_BD(<term>)", &BlockData.term)) {

      if (ofp_traverse_BlockData(BlockData.term, &BlockData)) {
         // MATCHED BlockData
      } else return ATfalse;

   // MATCHED ProgramUnit_BD

   return ATtrue;
 }

 OFP_Traverse Submodule;
 if (ATmatch(term, "ProgramUnit_S(<term>)", &Submodule.term)) {

      if (ofp_traverse_Submodule(Submodule.term, &Submodule)) {
         // MATCHED Submodule
      } else return ATfalse;

   // MATCHED ProgramUnit_S

   return ATtrue;
 }

 OFP_Traverse Module;
 if (ATmatch(term, "ProgramUnit_M(<term>)", &Module.term)) {

      if (ofp_traverse_Module(Module.term, &Module)) {
         // MATCHED Module
      } else return ATfalse;

   // MATCHED ProgramUnit_M

   return ATtrue;
 }

 OFP_Traverse ExternalSubprogram;
 if (ATmatch(term, "ProgramUnit_ES(<term>)", &ExternalSubprogram.term)) {

      if (ofp_traverse_ExternalSubprogram(ExternalSubprogram.term, &ExternalSubprogram)) {
         // MATCHED ExternalSubprogram
      } else return ATfalse;

   // MATCHED ProgramUnit_ES

   return ATtrue;
 }

 OFP_Traverse MainProgram;
 if (ATmatch(term, "ProgramUnit_MP(<term>)", &MainProgram.term)) {

      if (ofp_traverse_MainProgram(MainProgram.term, &MainProgram)) {
         // MATCHED MainProgram
      } else return ATfalse;

   // MATCHED ProgramUnit_MP

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R203 external-subprogram
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_ExternalSubprogram(ATerm term, pOFP_Traverse ExternalSubprogram)
{
#ifdef DEBUG_PRINT
   printf("ExternalSubprogram: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse SubroutineSubprogram;
 if (ATmatch(term, "ExternalSubprogram_SS(<term>)", &SubroutineSubprogram.term)) {

      if (ofp_traverse_SubroutineSubprogram(SubroutineSubprogram.term, &SubroutineSubprogram)) {
         // MATCHED SubroutineSubprogram
      } else return ATfalse;

   // MATCHED ExternalSubprogram_SS

   return ATtrue;
 }

 OFP_Traverse FunctionSubprogram;
 if (ATmatch(term, "ExternalSubprogram_FS(<term>)", &FunctionSubprogram.term)) {

      if (ofp_traverse_FunctionSubprogram(FunctionSubprogram.term, &FunctionSubprogram)) {
         // MATCHED FunctionSubprogram
      } else return ATfalse;

   // MATCHED ExternalSubprogram_FS

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R204 specification-part
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_SpecificationPart(ATerm term, pOFP_Traverse SpecificationPart)
{
#ifdef DEBUG_PRINT
   printf("\nSpecificationPart: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse UseStmt, ImportStmt, ImplicitPart, DeclarationConstruct;
 if (ATmatch(term, "SpecificationPart(<term>,<term>,<term>,<term>)", &UseStmt.term, &ImportStmt.term, &ImplicitPart.term, &DeclarationConstruct.term)) {

   ATermList UseStmt_tail = (ATermList) ATmake("<term>", UseStmt.term);
   while (! ATisEmpty(UseStmt_tail)) {
      UseStmt.term = ATgetFirst(UseStmt_tail);
      UseStmt_tail = ATgetNext (UseStmt_tail);
      if (ofp_traverse_UseStmt(UseStmt.term, &UseStmt)) {
         // MATCHED UseStmt
      } else return ATfalse;
   }

   ATermList ImportStmt_tail = (ATermList) ATmake("<term>", ImportStmt.term);
   while (! ATisEmpty(ImportStmt_tail)) {
      ImportStmt.term = ATgetFirst(ImportStmt_tail);
      ImportStmt_tail = ATgetNext (ImportStmt_tail);
#ifdef NOT_YET
      if (ofp_traverse_ImportStmt(ImportStmt.term, &ImportStmt)) {
         // MATCHED ImportStmt
      } else return ATfalse;
#endif
   }

   if (ATmatch(ImplicitPart.term, "Some(<term>)", &ImplicitPart.term)) {
      if (ofp_traverse_ImplicitPart(ImplicitPart.term, &ImplicitPart)) {
         // MATCHED ImplicitPart
      } else return ATfalse;
   }

   ATermList DeclarationConstruct_tail = (ATermList) ATmake("<term>", DeclarationConstruct.term);
   while (! ATisEmpty(DeclarationConstruct_tail)) {
      DeclarationConstruct.term = ATgetFirst(DeclarationConstruct_tail);
      DeclarationConstruct_tail = ATgetNext (DeclarationConstruct_tail);
      if (ofp_traverse_DeclarationConstruct(DeclarationConstruct.term, &DeclarationConstruct)) {
         // MATCHED DeclarationConstruct
      } else return ATfalse;
   }

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R205 implicit-part
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_ImplicitPart(ATerm term, pOFP_Traverse ImplicitPart)
{
#ifdef DEBUG_PRINT
   printf("ImplicitPart: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse ImplicitPartStmt, ImplicitStmt;
 if (ATmatch(term, "ImplicitPart(<term>,<term>)", &ImplicitPartStmt.term, &ImplicitStmt.term)) {

   ATermList ImplicitPartStmt_tail = (ATermList) ATmake("<term>", ImplicitPartStmt.term);
   while (! ATisEmpty(ImplicitPartStmt_tail)) {
      ImplicitPartStmt.term = ATgetFirst(ImplicitPartStmt_tail);
      ImplicitPartStmt_tail = ATgetNext (ImplicitPartStmt_tail);
      if (ofp_traverse_ImplicitPartStmt(ImplicitPartStmt.term, &ImplicitPartStmt)) {
         // MATCHED ImplicitPartStmt
      } else return ATfalse;
   }

#ifdef NOT_YET
      if (ofp_traverse_ImplicitStmt(ImplicitStmt.term, &ImplicitStmt)) {
         // MATCHED ImplicitStmt
      } else return ATfalse;
#endif

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R206 implicit-part-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_ImplicitPartStmt(ATerm term, pOFP_Traverse ImplicitPartStmt)
{
#ifdef DEBUG_PRINT
   printf("ImplicitPartStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse EntryStmt;
 if (ATmatch(term, "ImplicitPartStmt_ES(<term>)", &EntryStmt.term)) {

      if (ofp_traverse_EntryStmt(EntryStmt.term, &EntryStmt)) {
         // MATCHED EntryStmt
      } else return ATfalse;

   // MATCHED ImplicitPartStmt_ES

   return ATtrue;
 }

 OFP_Traverse FormatStmt;
 if (ATmatch(term, "ImplicitPartStmt_FS(<term>)", &FormatStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_FormatStmt(FormatStmt.term, &FormatStmt)) {
         // MATCHED FormatStmt
      } else return ATfalse;
#endif

   // MATCHED ImplicitPartStmt_FS

   return ATtrue;
 }

 OFP_Traverse ParameterStmt;
 if (ATmatch(term, "ImplicitPartStmt_PS(<term>)", &ParameterStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ParameterStmt(ParameterStmt.term, &ParameterStmt)) {
         // MATCHED ParameterStmt
      } else return ATfalse;
#endif

   // MATCHED ImplicitPartStmt_PS

   return ATtrue;
 }

 OFP_Traverse ImplicitStmt;
 if (ATmatch(term, "ImplicitPartStmt_IS(<term>)", &ImplicitStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ImplicitStmt(ImplicitStmt.term, &ImplicitStmt)) {
         // MATCHED ImplicitStmt
      } else return ATfalse;
#endif

   // MATCHED ImplicitPartStmt_IS

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R207 declaration-construct
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_DeclarationConstruct(ATerm term, pOFP_Traverse DeclarationConstruct)
{
#ifdef DEBUG_PRINT
   printf("\nDeclarationConstruct: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse StmtFunctionStmt;
 if (ATmatch(term, "DeclarationConstruct_SFS(<term>)", &StmtFunctionStmt.term)) {

      if (ofp_traverse_StmtFunctionStmt(StmtFunctionStmt.term, &StmtFunctionStmt)) {
         // MATCHED StmtFunctionStmt
      } else return ATfalse;

   // MATCHED DeclarationConstruct_SFS

   return ATtrue;
 }

 OFP_Traverse TypeDeclarationStmt;
 if (ATmatch(term, "DeclarationConstruct_TDS(<term>)", &TypeDeclarationStmt.term)) {

      if (ofp_traverse_TypeDeclarationStmt(TypeDeclarationStmt.term, &TypeDeclarationStmt)) {
         // MATCHED TypeDeclarationStmt
      } else return ATfalse;

   // MATCHED DeclarationConstruct_TDS

   return ATtrue;
 }

 OFP_Traverse OtherSpecificationStmt;
 if (ATmatch(term, "DeclarationConstruct_OSS(<term>)", &OtherSpecificationStmt.term)) {

      if (ofp_traverse_OtherSpecificationStmt(OtherSpecificationStmt.term, &OtherSpecificationStmt)) {
         // MATCHED OtherSpecificationStmt
      } else return ATfalse;

   // MATCHED DeclarationConstruct_OSS

   return ATtrue;
 }

 OFP_Traverse ProcedureDeclarationStmt;
 if (ATmatch(term, "DeclarationConstruct_PDS(<term>)", &ProcedureDeclarationStmt.term)) {

      if (ofp_traverse_ProcedureDeclarationStmt(ProcedureDeclarationStmt.term, &ProcedureDeclarationStmt)) {
         // MATCHED ProcedureDeclarationStmt
      } else return ATfalse;

   // MATCHED DeclarationConstruct_PDS

   return ATtrue;
 }

 OFP_Traverse ParameterStmt;
 if (ATmatch(term, "DeclarationConstruct_PS(<term>)", &ParameterStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ParameterStmt(ParameterStmt.term, &ParameterStmt)) {
         // MATCHED ParameterStmt
      } else return ATfalse;
#endif

   // MATCHED DeclarationConstruct_PS

   return ATtrue;
 }

 OFP_Traverse InterfaceBlock;
 if (ATmatch(term, "DeclarationConstruct_IB(<term>)", &InterfaceBlock.term)) {

      if (ofp_traverse_InterfaceBlock(InterfaceBlock.term, &InterfaceBlock)) {
         // MATCHED InterfaceBlock
      } else return ATfalse;

   // MATCHED DeclarationConstruct_IB

   return ATtrue;
 }

 OFP_Traverse FormatStmt;
 if (ATmatch(term, "DeclarationConstruct_FS(<term>)", &FormatStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_FormatStmt(FormatStmt.term, &FormatStmt)) {
         // MATCHED FormatStmt
      } else return ATfalse;
#endif

   // MATCHED DeclarationConstruct_FS

   return ATtrue;
 }

 OFP_Traverse EnumDef;
 if (ATmatch(term, "DeclarationConstruct_ED(<term>)", &EnumDef.term)) {

#ifdef NOT_YET
      if (ofp_traverse_EnumDef(EnumDef.term, &EnumDef)) {
         // MATCHED EnumDef
      } else return ATfalse;
#endif

   // MATCHED DeclarationConstruct_ED

   return ATtrue;
 }

 OFP_Traverse EntryStmt;
 if (ATmatch(term, "DeclarationConstruct_ES(<term>)", &EntryStmt.term)) {

      if (ofp_traverse_EntryStmt(EntryStmt.term, &EntryStmt)) {
         // MATCHED EntryStmt
      } else return ATfalse;

   // MATCHED DeclarationConstruct_ES

   return ATtrue;
 }

 OFP_Traverse DerivedTypeDef;
 if (ATmatch(term, "DeclarationConstruct_DTD(<term>)", &DerivedTypeDef.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DerivedTypeDef(DerivedTypeDef.term, &DerivedTypeDef)) {
         // MATCHED DerivedTypeDef
      } else return ATfalse;
#endif

   // MATCHED DeclarationConstruct_DTD

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================      
// R208 execution-part
//----------------------------------------------------------------------------------------      
ATbool ofp_traverse_ExecutionPart(ATerm term, pOFP_Traverse ExecutionPart)
{
#ifdef DEBUG_PRINT
   printf("\nExecutionPart: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse ExecutionPartConstruct;
 if (ATmatch(term, "ExecutionPart(<term>)", &ExecutionPartConstruct.term)) {

   ATermList ExecutionPartConstruct_tail = (ATermList) ATmake("<term>", ExecutionPartConstruct.term);
   while (! ATisEmpty(ExecutionPartConstruct_tail)) {
      ExecutionPartConstruct.term = ATgetFirst(ExecutionPartConstruct_tail);
      ExecutionPartConstruct_tail = ATgetNext (ExecutionPartConstruct_tail);
      if (ofp_traverse_ExecutionPartConstruct(ExecutionPartConstruct.term, &ExecutionPartConstruct)) {
         // MATCHED ExecutionPartConstruct
      } else return ATfalse;
   }

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================      
// R209 execution-part-construct
//----------------------------------------------------------------------------------------      
ATbool ofp_traverse_ExecutionPartConstruct(ATerm term, pOFP_Traverse ExecutionPartConstruct)
{
#ifdef DEBUG_PRINT
   printf("ExecutionPartConstruct: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse DataStmt;
 if (ATmatch(term, "ExecutionPartConstruct_DS(<term>)", &DataStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DataStmt(DataStmt.term, &DataStmt)) {
         // MATCHED DataStmt
      } else return ATfalse;
#endif

   // MATCHED ExecutionPartConstruct_DS

   return ATtrue;
 }

 OFP_Traverse EntryStmt;
 if (ATmatch(term, "ExecutionPartConstruct_ES(<term>)", &EntryStmt.term)) {

      if (ofp_traverse_EntryStmt(EntryStmt.term, &EntryStmt)) {
         // MATCHED EntryStmt
      } else return ATfalse;

   // MATCHED ExecutionPartConstruct_ES

   return ATtrue;
 }

 OFP_Traverse FormatStmt;
 if (ATmatch(term, "ExecutionPartConstruct_FS(<term>)", &FormatStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_FormatStmt(FormatStmt.term, &FormatStmt)) {
         // MATCHED FormatStmt
      } else return ATfalse;
#endif

   // MATCHED ExecutionPartConstruct_FS

   return ATtrue;
 }

 OFP_Traverse ExecutableConstruct;
 if (ATmatch(term, "ExecutionPartConstruct_EC(<term>)", &ExecutableConstruct.term)) {

      if (ofp_traverse_ExecutableConstruct(ExecutableConstruct.term, &ExecutableConstruct)) {
         // MATCHED ExecutableConstruct
      } else return ATfalse;

   // MATCHED ExecutionPartConstruct_EC

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================      
// R210 internal-subprogram-part
//----------------------------------------------------------------------------------------      
ATbool ofp_traverse_InternalSubprogramPart(ATerm term, pOFP_Traverse InternalSubprogramPart)
{
#ifdef DEBUG_PRINT
   printf("InternalSubprogramPart: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse ContainsStmt, InternalSubprogram;
 if (ATmatch(term, "InternalSubprogramPart(<term>,<term>)", &ContainsStmt.term, &InternalSubprogram.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ContainsStmt(ContainsStmt.term, &ContainsStmt)) {
         // MATCHED ContainsStmt
      } else return ATfalse;
#endif

   ATermList InternalSubprogram_tail = (ATermList) ATmake("<term>", InternalSubprogram.term);
   while (! ATisEmpty(InternalSubprogram_tail)) {
      InternalSubprogram.term = ATgetFirst(InternalSubprogram_tail);
      InternalSubprogram_tail = ATgetNext (InternalSubprogram_tail);
#ifdef NOT_YET
      if (ofp_traverse_InternalSubprogram(InternalSubprogram.term, &InternalSubprogram)) {
         // MATCHED InternalSubprogram
      } else return ATfalse;
#endif
   }

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================      
// R211 internal-subprogram
//----------------------------------------------------------------------------------------      
ATbool ofp_traverse_InternalSubprogram(ATerm term, pOFP_Traverse InternalSubprogram)
{
#ifdef DEBUG_PRINT
   printf("InternalSubprogram: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse SubroutineSubprogram;
 if (ATmatch(term, "InternalSubprogram(<term>)", &SubroutineSubprogram.term)) {

#ifdef NOT_YET
      if (ofp_traverse_SubroutineSubprogram(SubroutineSubprogram.term, &SubroutineSubprogram)) {
         // MATCHED SubroutineSubprogram
      } else return ATfalse;
#endif

   return ATtrue;
 }

 OFP_Traverse FunctionSubprogram;
 if (ATmatch(term, "InternalSubprogram(<term>)", &FunctionSubprogram.term)) {

#ifdef NOT_YET
      if (ofp_traverse_FunctionSubprogram(FunctionSubprogram.term, &FunctionSubprogram)) {
         // MATCHED FunctionSubprogram
      } else return ATfalse;
#endif

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================      
// R212 other-specification-stmt
//----------------------------------------------------------------------------------------      
ATbool ofp_traverse_OtherSpecificationStmt(ATerm term, pOFP_Traverse OtherSpecificationStmt)
{
#ifdef DEBUG_PRINT
   printf("OtherSpecificationStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse ValueStmt;
 if (ATmatch(term, "OtherSpecificationStmt_VS2(<term>)", &ValueStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ValueStmt(ValueStmt.term, &ValueStmt)) {
         // MATCHED ValueStmt
      } else return ATfalse;
#endif

   // MATCHED OtherSpecificationStmt_VS2

   return ATtrue;
 }

 OFP_Traverse VolatileStmt;
 if (ATmatch(term, "OtherSpecificationStmt_VS1(<term>)", &VolatileStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_VolatileStmt(VolatileStmt.term, &VolatileStmt)) {
         // MATCHED VolatileStmt
      } else return ATfalse;
#endif

   // MATCHED OtherSpecificationStmt_VS1

   return ATtrue;
 }

 OFP_Traverse TargetStmt;
 if (ATmatch(term, "OtherSpecificationStmt_TS(<term>)", &TargetStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_TargetStmt(TargetStmt.term, &TargetStmt)) {
         // MATCHED TargetStmt
      } else return ATfalse;
#endif

   // MATCHED OtherSpecificationStmt_TS

   return ATtrue;
 }

 OFP_Traverse SaveStmt;
 if (ATmatch(term, "OtherSpecificationStmt_SS(<term>)", &SaveStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_SaveStmt(SaveStmt.term, &SaveStmt)) {
         // MATCHED SaveStmt
      } else return ATfalse;
#endif

   // MATCHED OtherSpecificationStmt_SS

   return ATtrue;
 }

 OFP_Traverse ProtectedStmt;
 if (ATmatch(term, "OtherSpecificationStmt_PS2(<term>)", &ProtectedStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ProtectedStmt(ProtectedStmt.term, &ProtectedStmt)) {
         // MATCHED ProtectedStmt
      } else return ATfalse;
#endif

   // MATCHED OtherSpecificationStmt_PS2

   return ATtrue;
 }

 OFP_Traverse PointerStmt;
 if (ATmatch(term, "OtherSpecificationStmt_PS1(<term>)", &PointerStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_PointerStmt(PointerStmt.term, &PointerStmt)) {
         // MATCHED PointerStmt
      } else return ATfalse;
#endif

   // MATCHED OtherSpecificationStmt_PS1

   return ATtrue;
 }

 OFP_Traverse OptionalStmt;
 if (ATmatch(term, "OtherSpecificationStmt_OS(<term>)", &OptionalStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_OptionalStmt(OptionalStmt.term, &OptionalStmt)) {
         // MATCHED OptionalStmt
      } else return ATfalse;
#endif

   // MATCHED OtherSpecificationStmt_OS

   return ATtrue;
 }

 OFP_Traverse NamelistStmt;
 if (ATmatch(term, "OtherSpecificationStmt_NS(<term>)", &NamelistStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_NamelistStmt(NamelistStmt.term, &NamelistStmt)) {
         // MATCHED NamelistStmt
      } else return ATfalse;
#endif

   // MATCHED OtherSpecificationStmt_NS

   return ATtrue;
 }

 OFP_Traverse IntrinsicStmt;
 if (ATmatch(term, "OtherSpecificationStmt_IS2(<term>)", &IntrinsicStmt.term)) {

      if (ofp_traverse_IntrinsicStmt(IntrinsicStmt.term, &IntrinsicStmt)) {
         // MATCHED IntrinsicStmt
      } else return ATfalse;

   // MATCHED OtherSpecificationStmt_IS2

   return ATtrue;
 }

 OFP_Traverse IntentStmt;
 if (ATmatch(term, "OtherSpecificationStmt_IS1(<term>)", &IntentStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_IntentStmt(IntentStmt.term, &IntentStmt)) {
         // MATCHED IntentStmt
      } else return ATfalse;
#endif

   // MATCHED OtherSpecificationStmt_IS1

   return ATtrue;
 }

 OFP_Traverse ExternalStmt;
 if (ATmatch(term, "OtherSpecificationStmt_ES2(<term>)", &ExternalStmt.term)) {

      if (ofp_traverse_ExternalStmt(ExternalStmt.term, &ExternalStmt)) {
         // MATCHED ExternalStmt
      } else return ATfalse;

   // MATCHED OtherSpecificationStmt_ES2

   return ATtrue;
 }

 OFP_Traverse EquivalenceStmt;
 if (ATmatch(term, "OtherSpecificationStmt_ES1(<term>)", &EquivalenceStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_EquivalenceStmt(EquivalenceStmt.term, &EquivalenceStmt)) {
         // MATCHED EquivalenceStmt
      } else return ATfalse;
#endif

   // MATCHED OtherSpecificationStmt_ES1

   return ATtrue;
 }

 OFP_Traverse DimensionStmt;
 if (ATmatch(term, "OtherSpecificationStmt_DS2(<term>)", &DimensionStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DimensionStmt(DimensionStmt.term, &DimensionStmt)) {
         // MATCHED DimensionStmt
      } else return ATfalse;
#endif

   // MATCHED OtherSpecificationStmt_DS2

   return ATtrue;
 }

 OFP_Traverse DataStmt;
 if (ATmatch(term, "OtherSpecificationStmt_DS1(<term>)", &DataStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DataStmt(DataStmt.term, &DataStmt)) {
         // MATCHED DataStmt
      } else return ATfalse;
#endif

   // MATCHED OtherSpecificationStmt_DS1

   return ATtrue;
 }

 OFP_Traverse CommonStmt;
 if (ATmatch(term, "OtherSpecificationStmt_CS3(<term>)", &CommonStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_CommonStmt(CommonStmt.term, &CommonStmt)) {
         // MATCHED CommonStmt
      } else return ATfalse;
#endif

   // MATCHED OtherSpecificationStmt_CS3

   return ATtrue;
 }

 OFP_Traverse ContiguousStmt;
 if (ATmatch(term, "OtherSpecificationStmt_CS2(<term>)", &ContiguousStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ContiguousStmt(ContiguousStmt.term, &ContiguousStmt)) {
         // MATCHED ContiguousStmt
      } else return ATfalse;
#endif

   // MATCHED OtherSpecificationStmt_CS2

   return ATtrue;
 }

 OFP_Traverse CodimensionStmt;
 if (ATmatch(term, "OtherSpecificationStmt_CS1(<term>)", &CodimensionStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_CodimensionStmt(CodimensionStmt.term, &CodimensionStmt)) {
         // MATCHED CodimensionStmt
      } else return ATfalse;
#endif

   // MATCHED OtherSpecificationStmt_CS1

   return ATtrue;
 }

 OFP_Traverse BindStmt;
 if (ATmatch(term, "OtherSpecificationStmt_BS(<term>)", &BindStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_BindStmt(BindStmt.term, &BindStmt)) {
         // MATCHED BindStmt
      } else return ATfalse;
#endif

   // MATCHED OtherSpecificationStmt_BS

   return ATtrue;
 }

 OFP_Traverse AsynchronousStmt;
 if (ATmatch(term, "OtherSpecificationStmt_AS3(<term>)", &AsynchronousStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_AsynchronousStmt(AsynchronousStmt.term, &AsynchronousStmt)) {
         // MATCHED AsynchronousStmt
      } else return ATfalse;
#endif

   // MATCHED OtherSpecificationStmt_AS3

   return ATtrue;
 }

 OFP_Traverse AllocatableStmt;
 if (ATmatch(term, "OtherSpecificationStmt_AS2(<term>)", &AllocatableStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_AllocatableStmt(AllocatableStmt.term, &AllocatableStmt)) {
         // MATCHED AllocatableStmt
      } else return ATfalse;
#endif

   // MATCHED OtherSpecificationStmt_AS2

   return ATtrue;
 }

 OFP_Traverse AccessStmt;
 if (ATmatch(term, "OtherSpecificationStmt_AS1(<term>)", &AccessStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_AccessStmt(AccessStmt.term, &AccessStmt)) {
         // MATCHED AccessStmt
      } else return ATfalse;
#endif

   // MATCHED OtherSpecificationStmt_AS1

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================      
// R213 executable-construct
//----------------------------------------------------------------------------------------      
ATbool ofp_traverse_ExecutableConstruct(ATerm term, pOFP_Traverse ExecutableConstruct)
{
#ifdef DEBUG_PRINT
   printf("ExecutableConstruct: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse WhereConstruct;
 if (ATmatch(term, "ExecutableConstruct_WC(<term>)", &WhereConstruct.term)) {

#ifdef NOT_YET
      if (ofp_traverse_WhereConstruct(WhereConstruct.term, &WhereConstruct)) {
         // MATCHED WhereConstruct
      } else return ATfalse;
#endif

   // MATCHED ExecutableConstruct_WC

   return ATtrue;
 }

 OFP_Traverse SelectTypeConstruct;
 if (ATmatch(term, "ExecutableConstruct_STC(<term>)", &SelectTypeConstruct.term)) {

#ifdef NOT_YET
      if (ofp_traverse_SelectTypeConstruct(SelectTypeConstruct.term, &SelectTypeConstruct)) {
         // MATCHED SelectTypeConstruct
      } else return ATfalse;
#endif

   // MATCHED ExecutableConstruct_STC

   return ATtrue;
 }

 OFP_Traverse IfConstruct;
 if (ATmatch(term, "ExecutableConstruct_IC(<term>)", &IfConstruct.term)) {

#ifdef NOT_YET
      if (ofp_traverse_IfConstruct(IfConstruct.term, &IfConstruct)) {
         // MATCHED IfConstruct
      } else return ATfalse;
#endif

   // MATCHED ExecutableConstruct_IC

   return ATtrue;
 }

 OFP_Traverse ForallConstruct;
 if (ATmatch(term, "ExecutableConstruct_FC(<term>)", &ForallConstruct.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ForallConstruct(ForallConstruct.term, &ForallConstruct)) {
         // MATCHED ForallConstruct
      } else return ATfalse;
#endif

   // MATCHED ExecutableConstruct_FC

   return ATtrue;
 }

 OFP_Traverse CriticalConstruct;
 if (ATmatch(term, "ExecutableConstruct_CC2(<term>)", &CriticalConstruct.term)) {

#ifdef NOT_YET
      if (ofp_traverse_CriticalConstruct(CriticalConstruct.term, &CriticalConstruct)) {
         // MATCHED CriticalConstruct
      } else return ATfalse;
#endif

   // MATCHED ExecutableConstruct_CC2

   return ATtrue;
 }

 OFP_Traverse CaseConstruct;
 if (ATmatch(term, "ExecutableConstruct_CC1(<term>)", &CaseConstruct.term)) {

#ifdef NOT_YET
      if (ofp_traverse_CaseConstruct(CaseConstruct.term, &CaseConstruct)) {
         // MATCHED CaseConstruct
      } else return ATfalse;
#endif

   // MATCHED ExecutableConstruct_CC1

   return ATtrue;
 }

 OFP_Traverse BlockConstruct;
 if (ATmatch(term, "ExecutableConstruct_BC(<term>)", &BlockConstruct.term)) {

#ifdef NOT_YET
      if (ofp_traverse_BlockConstruct(BlockConstruct.term, &BlockConstruct)) {
         // MATCHED BlockConstruct
      } else return ATfalse;
#endif

   // MATCHED ExecutableConstruct_BC

   return ATtrue;
 }

 OFP_Traverse AssociateConstruct;
 if (ATmatch(term, "ExecutableConstruct_AC(<term>)", &AssociateConstruct.term)) {

#ifdef NOT_YET
      if (ofp_traverse_AssociateConstruct(AssociateConstruct.term, &AssociateConstruct)) {
         // MATCHED AssociateConstruct
      } else return ATfalse;
#endif

   // MATCHED ExecutableConstruct_AC

   return ATtrue;
 }

 OFP_Traverse ActionStmt;
 if (ATmatch(term, "ExecutableConstruct_AS(<term>)", &ActionStmt.term)) {

      if (ofp_traverse_ActionStmt(ActionStmt.term, &ActionStmt)) {
         // MATCHED ActionStmt
      } else return ATfalse;

   // MATCHED ExecutableConstruct_AS

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================      
// R214 action-stmt
//----------------------------------------------------------------------------------------      
ATbool ofp_traverse_ActionStmt(ATerm term, pOFP_Traverse ActionStmt)
{
#ifdef DEBUG_PRINT
   printf("ActionStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse EndDoStmt;
 if (ATmatch(term, "ActionStmt_EDS(<term>)", &EndDoStmt.term)) {

      if (ofp_traverse_EndDoStmt(EndDoStmt.term, &EndDoStmt)) {
         // MATCHED EndDoStmt
      } else return ATfalse;

   // MATCHED ActionStmt_EDS

   return ATtrue;
 }

 OFP_Traverse NonlabelDoStmt;
 if (ATmatch(term, "ActionStmt_NDS(<term>)", &NonlabelDoStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_NonlabelDoStmt(NonlabelDoStmt.term, &NonlabelDoStmt)) {
         // MATCHED NonlabelDoStmt
      } else return ATfalse;
#endif

   // MATCHED ActionStmt_NDS

   return ATtrue;
 }

 OFP_Traverse LabelDoStmt;
 if (ATmatch(term, "ActionStmt_LDS(<term>)", &LabelDoStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_LabelDoStmt(LabelDoStmt.term, &LabelDoStmt)) {
         // MATCHED LabelDoStmt
      } else return ATfalse;
#endif

   // MATCHED ActionStmt_LDS

   return ATtrue;
 }

 OFP_Traverse ComputedGotoStmt;
 if (ATmatch(term, "ActionStmt_CGS(<term>)", &ComputedGotoStmt.term)) {

      if (ofp_traverse_ComputedGotoStmt(ComputedGotoStmt.term, &ComputedGotoStmt)) {
         // MATCHED ComputedGotoStmt
      } else return ATfalse;

   // MATCHED ActionStmt_CGS

   return ATtrue;
 }

 OFP_Traverse ArithmeticIfStmt;
 if (ATmatch(term, "ActionStmt_AIS(<term>)", &ArithmeticIfStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ArithmeticIfStmt(ArithmeticIfStmt.term, &ArithmeticIfStmt)) {
         // MATCHED ArithmeticIfStmt
      } else return ATfalse;
#endif

   // MATCHED ActionStmt_AIS

   return ATtrue;
 }

 OFP_Traverse WriteStmt;
 if (ATmatch(term, "ActionStmt_WS3(<term>)", &WriteStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_WriteStmt(WriteStmt.term, &WriteStmt)) {
         // MATCHED WriteStmt
      } else return ATfalse;
#endif

   // MATCHED ActionStmt_WS3

   return ATtrue;
 }

 OFP_Traverse WhereStmt;
 if (ATmatch(term, "ActionStmt_WS2(<term>)", &WhereStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_WhereStmt(WhereStmt.term, &WhereStmt)) {
         // MATCHED WhereStmt
      } else return ATfalse;
#endif

   // MATCHED ActionStmt_WS2

   return ATtrue;
 }

 OFP_Traverse WaitStmt;
 if (ATmatch(term, "ActionStmt_WS1(<term>)", &WaitStmt.term)) {

      if (ofp_traverse_WaitStmt(WaitStmt.term, &WaitStmt)) {
         // MATCHED WaitStmt
      } else return ATfalse;

   // MATCHED ActionStmt_WS1

   return ATtrue;
 }

 OFP_Traverse UnlockStmt;
 if (ATmatch(term, "ActionStmt_US(<term>)", &UnlockStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_UnlockStmt(UnlockStmt.term, &UnlockStmt)) {
         // MATCHED UnlockStmt
      } else return ATfalse;
#endif

   // MATCHED ActionStmt_US

   return ATtrue;
 }

 OFP_Traverse SyncMemoryStmt;
 if (ATmatch(term, "ActionStmt_SMS(<term>)", &SyncMemoryStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_SyncMemoryStmt(SyncMemoryStmt.term, &SyncMemoryStmt)) {
         // MATCHED SyncMemoryStmt
      } else return ATfalse;
#endif

   // MATCHED ActionStmt_SMS

   return ATtrue;
 }

 OFP_Traverse SyncImagesStmt;
 if (ATmatch(term, "ActionStmt_SIS(<term>)", &SyncImagesStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_SyncImagesStmt(SyncImagesStmt.term, &SyncImagesStmt)) {
         // MATCHED SyncImagesStmt
      } else return ATfalse;
#endif

   // MATCHED ActionStmt_SIS

   return ATtrue;
 }

 OFP_Traverse SyncAllStmt;
 if (ATmatch(term, "ActionStmt_SAS(<term>)", &SyncAllStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_SyncAllStmt(SyncAllStmt.term, &SyncAllStmt)) {
         // MATCHED SyncAllStmt
      } else return ATfalse;
#endif

   // MATCHED ActionStmt_SAS

   return ATtrue;
 }

 OFP_Traverse StopStmt;
 if (ATmatch(term, "ActionStmt_SS(<term>)", &StopStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_StopStmt(StopStmt.term, &StopStmt)) {
         // MATCHED StopStmt
      } else return ATfalse;
#endif

   // MATCHED ActionStmt_SS

   return ATtrue;
 }

 OFP_Traverse RewindStmt;
 if (ATmatch(term, "ActionStmt_RS3(<term>)", &RewindStmt.term)) {

      if (ofp_traverse_RewindStmt(RewindStmt.term, &RewindStmt)) {
         // MATCHED RewindStmt
      } else return ATfalse;

   // MATCHED ActionStmt_RS3

   return ATtrue;
 }

 OFP_Traverse ReturnStmt;
 if (ATmatch(term, "ActionStmt_RS2(<term>)", &ReturnStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ReturnStmt(ReturnStmt.term, &ReturnStmt)) {
         // MATCHED ReturnStmt
      } else return ATfalse;
#endif

   // MATCHED ActionStmt_RS2

   return ATtrue;
 }

 OFP_Traverse ReadStmt;
 if (ATmatch(term, "ActionStmt_RS1(<term>)", &ReadStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ReadStmt(ReadStmt.term, &ReadStmt)) {
         // MATCHED ReadStmt
      } else return ATfalse;
#endif

   // MATCHED ActionStmt_RS1

   return ATtrue;
 }

 OFP_Traverse PrintStmt;
 if (ATmatch(term, "ActionStmt_PS1(<term>)", &PrintStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_PrintStmt(PrintStmt.term, &PrintStmt)) {
         // MATCHED PrintStmt
      } else return ATfalse;
#endif

   // MATCHED ActionStmt_PS1

   return ATtrue;
 }

 OFP_Traverse PointerAssignmentStmt;
 if (ATmatch(term, "ActionStmt_PAS(<term>)", &PointerAssignmentStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_PointerAssignmentStmt(PointerAssignmentStmt.term, &PointerAssignmentStmt)) {
         // MATCHED PointerAssignmentStmt
      } else return ATfalse;
#endif

   // MATCHED ActionStmt_PAS

   return ATtrue;
 }

 OFP_Traverse OpenStmt;
 if (ATmatch(term, "ActionStmt_OS(<term>)", &OpenStmt.term)) {

      if (ofp_traverse_OpenStmt(OpenStmt.term, &OpenStmt)) {
         // MATCHED OpenStmt
      } else return ATfalse;

   // MATCHED ActionStmt_OS

   return ATtrue;
 }

 OFP_Traverse NullifyStmt;
 if (ATmatch(term, "ActionStmt_NS(<term>)", &NullifyStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_NullifyStmt(NullifyStmt.term, &NullifyStmt)) {
         // MATCHED NullifyStmt
      } else return ATfalse;
#endif

   // MATCHED ActionStmt_NS

   return ATtrue;
 }

 OFP_Traverse LockStmt;
 if (ATmatch(term, "ActionStmt_LS(<term>)", &LockStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_LockStmt(LockStmt.term, &LockStmt)) {
         // MATCHED LockStmt
      } else return ATfalse;
#endif

   // MATCHED ActionStmt_LS

   return ATtrue;
 }

 OFP_Traverse InquireStmt;
 if (ATmatch(term, "ActionStmt_IS2(<term>)", &InquireStmt.term)) {

      if (ofp_traverse_InquireStmt(InquireStmt.term, &InquireStmt)) {
         // MATCHED InquireStmt
      } else return ATfalse;

   // MATCHED ActionStmt_IS2

   return ATtrue;
 }

 OFP_Traverse IfStmt;
 if (ATmatch(term, "ActionStmt_IS1(<term>)", &IfStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_IfStmt(IfStmt.term, &IfStmt)) {
         // MATCHED IfStmt
      } else return ATfalse;
#endif

   // MATCHED ActionStmt_IS1

   return ATtrue;
 }

 OFP_Traverse GotoStmt;
 if (ATmatch(term, "ActionStmt_GS(<term>)", &GotoStmt.term)) {

      if (ofp_traverse_GotoStmt(GotoStmt.term, &GotoStmt)) {
         // MATCHED GotoStmt
      } else return ATfalse;

   // MATCHED ActionStmt_GS

   return ATtrue;
 }

 OFP_Traverse ForallStmt;
 if (ATmatch(term, "ActionStmt_FS2(<term>)", &ForallStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ForallStmt(ForallStmt.term, &ForallStmt)) {
         // MATCHED ForallStmt
      } else return ATfalse;
#endif

   // MATCHED ActionStmt_FS2

   return ATtrue;
 }

 OFP_Traverse FlushStmt;
 if (ATmatch(term, "ActionStmt_FS1(<term>)", &FlushStmt.term)) {

      if (ofp_traverse_FlushStmt(FlushStmt.term, &FlushStmt)) {
         // MATCHED FlushStmt
      } else return ATfalse;

   // MATCHED ActionStmt_FS1

   return ATtrue;
 }

 OFP_Traverse ExitStmt;
 if (ATmatch(term, "ActionStmt_ES2(<term>)", &ExitStmt.term)) {

      if (ofp_traverse_ExitStmt(ExitStmt.term, &ExitStmt)) {
         // MATCHED ExitStmt
      } else return ATfalse;

   // MATCHED ActionStmt_ES2

   return ATtrue;
 }

 OFP_Traverse ErrorStopStmt;
 if (ATmatch(term, "ActionStmt_ESS2(<term>)", &ErrorStopStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ErrorStopStmt(ErrorStopStmt.term, &ErrorStopStmt)) {
         // MATCHED ErrorStopStmt
      } else return ATfalse;
#endif

   // MATCHED ActionStmt_ESS2

   return ATtrue;
 }

 OFP_Traverse EndfileStmt;
 if (ATmatch(term, "ActionStmt_ES1(<term>)", &EndfileStmt.term)) {

      if (ofp_traverse_EndfileStmt(EndfileStmt.term, &EndfileStmt)) {
         // MATCHED EndfileStmt
      } else return ATfalse;

   // MATCHED ActionStmt_ES1

   return ATtrue;
 }

 OFP_Traverse EndSubroutineStmt;
 if (ATmatch(term, "ActionStmt_ESS1(<term>)", &EndSubroutineStmt.term)) {

      if (ofp_traverse_EndSubroutineStmt(EndSubroutineStmt.term, &EndSubroutineStmt)) {
         // MATCHED EndSubroutineStmt
      } else return ATfalse;

   // MATCHED ActionStmt_ESS1

   return ATtrue;
 }

 OFP_Traverse EndProgramStmt;
 if (ATmatch(term, "ActionStmt_EPS(<term>)", &EndProgramStmt.term)) {

      if (ofp_traverse_EndProgramStmt(EndProgramStmt.term, &EndProgramStmt)) {
         // MATCHED EndProgramStmt
      } else return ATfalse;

   // MATCHED ActionStmt_EPS

   return ATtrue;
 }

 OFP_Traverse EndMpSubprogramStmt;
 if (ATmatch(term, "ActionStmt_EMSS(<term>)", &EndMpSubprogramStmt.term)) {

      if (ofp_traverse_EndMpSubprogramStmt(EndMpSubprogramStmt.term, &EndMpSubprogramStmt)) {
         // MATCHED EndMpSubprogramStmt
      } else return ATfalse;

   // MATCHED ActionStmt_EMSS

   return ATtrue;
 }

 OFP_Traverse EndFunctionStmt;
 if (ATmatch(term, "ActionStmt_EFS(<term>)", &EndFunctionStmt.term)) {

      if (ofp_traverse_EndFunctionStmt(EndFunctionStmt.term, &EndFunctionStmt)) {
         // MATCHED EndFunctionStmt
      } else return ATfalse;

   // MATCHED ActionStmt_EFS

   return ATtrue;
 }

 OFP_Traverse DeallocateStmt;
 if (ATmatch(term, "ActionStmt_DS(<term>)", &DeallocateStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DeallocateStmt(DeallocateStmt.term, &DeallocateStmt)) {
         // MATCHED DeallocateStmt
      } else return ATfalse;
#endif

   // MATCHED ActionStmt_DS

   return ATtrue;
 }

 OFP_Traverse CycleStmt;
 if (ATmatch(term, "ActionStmt_CS4(<term>)", &CycleStmt.term)) {

      if (ofp_traverse_CycleStmt(CycleStmt.term, &CycleStmt)) {
         // MATCHED CycleStmt
      } else return ATfalse;

   // MATCHED ActionStmt_CS4

   return ATtrue;
 }

 OFP_Traverse ContinueStmt;
 if (ATmatch(term, "ActionStmt_CS3(<term>)", &ContinueStmt.term)) {

      if (ofp_traverse_ContinueStmt(ContinueStmt.term, &ContinueStmt)) {
         // MATCHED ContinueStmt
      } else return ATfalse;

   // MATCHED ActionStmt_CS3

   return ATtrue;
 }

 OFP_Traverse CloseStmt;
 if (ATmatch(term, "ActionStmt_CS2(<term>)", &CloseStmt.term)) {

      if (ofp_traverse_CloseStmt(CloseStmt.term, &CloseStmt)) {
         // MATCHED CloseStmt
      } else return ATfalse;

   // MATCHED ActionStmt_CS2

   return ATtrue;
 }

 OFP_Traverse CallStmt;
 if (ATmatch(term, "ActionStmt_CS1(<term>)", &CallStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_CallStmt(CallStmt.term, &CallStmt)) {
         // MATCHED CallStmt
      } else return ATfalse;
#endif

   // MATCHED ActionStmt_CS1

   return ATtrue;
 }

 OFP_Traverse BackspaceStmt;
 if (ATmatch(term, "ActionStmt_BS(<term>)", &BackspaceStmt.term)) {

      if (ofp_traverse_BackspaceStmt(BackspaceStmt.term, &BackspaceStmt)) {
         // MATCHED BackspaceStmt
      } else return ATfalse;

   // MATCHED ActionStmt_BS

   return ATtrue;
 }

 OFP_Traverse AssignmentStmt;
 if (ATmatch(term, "ActionStmt_AS2(<term>)", &AssignmentStmt.term)) {

      if (ofp_traverse_AssignmentStmt(AssignmentStmt.term, &AssignmentStmt)) {
         // MATCHED AssignmentStmt
      } else return ATfalse;

   // MATCHED ActionStmt_AS2

   return ATtrue;
 }

 OFP_Traverse AllocateStmt;
 if (ATmatch(term, "ActionStmt_AS1(<term>)", &AllocateStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_AllocateStmt(AllocateStmt.term, &AllocateStmt)) {
         // MATCHED AllocateStmt
      } else return ATfalse;
#endif

   // MATCHED ActionStmt_AS1

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================      
// R215 keyword
//----------------------------------------------------------------------------------------      
ATbool ofp_traverse_Keyword(ATerm term, pOFP_Traverse Keyword)
{
#ifdef DEBUG_PRINT
   printf("Keyword: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Name;
 if (ATmatch(term, "Keyword(<term>)", &Name.term)) {

      if (ofp_traverse_Name(Name.term, &Name)) {
         // MATCHED Name
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}


/**                                                                                             
 * Section/Clause 3: Lexical tokens and source form
 */

//========================================================================================      
// R304 constant
//----------------------------------------------------------------------------------------      
ATbool ofp_traverse_Constant(ATerm term, pOFP_Traverse Constant)
{
#ifdef DEBUG_PRINT
   printf("Constant: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse LiteralConstant;
 if (ATmatch(term, "Constant_AMB(<term>)", &LiteralConstant.term)) {

      if (ofp_traverse_LiteralConstant(LiteralConstant.term, &LiteralConstant)) {
         // MATCHED LiteralConstant
      } else return ATfalse;

   // MATCHED Constant_AMB

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================      
// R305 literal-constant
//----------------------------------------------------------------------------------------      
ATbool ofp_traverse_LiteralConstant(ATerm term, pOFP_Traverse LiteralConstant)
{
#ifdef DEBUG_PRINT
   printf("LiteralConstant: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse BozLiteralConstant;
 if (ATmatch(term, "LiteralConstant(<term>)", &BozLiteralConstant.term)) {

#ifdef NOT_YET
      if (ofp_traverse_BozLiteralConstant(BozLiteralConstant.term, &BozLiteralConstant)) {
         // MATCHED BozLiteralConstant
      } else return ATfalse;
#endif

   return ATtrue;
 }

 OFP_Traverse CharLiteralConstant;
 if (ATmatch(term, "LiteralConstant(<term>)", &CharLiteralConstant.term)) {

#ifdef NOT_YET
      if (ofp_traverse_CharLiteralConstant(CharLiteralConstant.term, &CharLiteralConstant)) {
         // MATCHED CharLiteralConstant
      } else return ATfalse;
#endif

   return ATtrue;
 }

 OFP_Traverse LogicalLiteralConstant;
 if (ATmatch(term, "LiteralConstant(<term>)", &LogicalLiteralConstant.term)) {

#ifdef NOT_YET
      if (ofp_traverse_LogicalLiteralConstant(LogicalLiteralConstant.term, &LogicalLiteralConstant)) {
         // MATCHED LogicalLiteralConstant
      } else return ATfalse;
#endif

   return ATtrue;
 }

 OFP_Traverse ComplexLiteralConstant;
 if (ATmatch(term, "LiteralConstant(<term>)", &ComplexLiteralConstant.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ComplexLiteralConstant(ComplexLiteralConstant.term, &ComplexLiteralConstant)) {
         // MATCHED ComplexLiteralConstant
      } else return ATfalse;
#endif

   return ATtrue;
 }

 OFP_Traverse RealLiteralConstant;
 if (ATmatch(term, "LiteralConstant(<term>)", &RealLiteralConstant.term)) {

#ifdef NOT_YET
      if (ofp_traverse_RealLiteralConstant(RealLiteralConstant.term, &RealLiteralConstant)) {
         // MATCHED RealLiteralConstant
      } else return ATfalse;
#endif

   return ATtrue;
 }

 OFP_Traverse IntLiteralConstant;
 if (ATmatch(term, "LiteralConstant(<term>)", &IntLiteralConstant.term)) {

      if (ofp_traverse_IntLiteralConstant(IntLiteralConstant.term, &IntLiteralConstant)) {
         // MATCHED IntLiteralConstant
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================      
// R306 named-constant
//----------------------------------------------------------------------------------------      
ATbool ofp_traverse_NamedConstant(ATerm term, pOFP_Traverse NamedConstant)
{
#ifdef DEBUG_PRINT
   printf("NamedConstant: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Name;
 if (ATmatch(term, "NamedConstant(<term>)", &Name.term)) {

      if (ofp_traverse_Name(Name.term, &Name)) {
         // MATCHED Name
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}


/**                                                                                             
 * Section/Clause 4: Types                                                                      
 */

//========================================================================================      
// R403 declaration-type-spec                                                                   
//----------------------------------------------------------------------------------------      
ATbool ofp_traverse_DeclarationTypeSpec(ATerm term, pOFP_Traverse DeclarationTypeSpec)
{
#ifdef DEBUG_PRINT
   printf("DeclarationTypeSpec: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse IntrinsicTypeSpec;
 if (ATmatch(term, "DeclarationTypeSpec(<term>)", &IntrinsicTypeSpec.term)) {

      if (ofp_traverse_IntrinsicTypeSpec(IntrinsicTypeSpec.term, &IntrinsicTypeSpec)) {
         // MATCHED IntrinsicTypeSpec
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R404 intrinsic-type-spec
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_IntrinsicTypeSpec(ATerm term, pOFP_Traverse IntrinsicTypeSpec)
{
#ifdef DEBUG_PRINT
   printf("IntrinsicTypeSpec: %s\n", ATwriteToString(term));
#endif

 if (ATmatch(term, "IntrinsicTypeSpec_DOUBLE_COMPLEX")) {

   // MATCHED IntrinsicTypeSpec_DOUBLE_COMPLEX

   return ATtrue;
 }

 OFP_Traverse KindSelector;
 if (ATmatch(term, "IntrinsicTypeSpec_LOGICAL(<term>)", &KindSelector.term)) {

   if (ATmatch(KindSelector.term, "Some(<term>)", &KindSelector.term)) {
      if (ofp_traverse_KindSelector(KindSelector.term, &KindSelector)) {
         // MATCHED KindSelector
      } else return ATfalse;
   }

   // MATCHED IntrinsicTypeSpec_LOGICAL

   return ATtrue;
 }

 OFP_Traverse CharSelector;
 if (ATmatch(term, "IntrinsicTypeSpec_CHARACTER(<term>)", &CharSelector.term)) {

   if (ATmatch(CharSelector.term, "Some(<term>)", &CharSelector.term)) {
      if (ofp_traverse_CharSelector(CharSelector.term, &CharSelector)) {
         // MATCHED CharSelector
      } else return ATfalse;
   }

   // MATCHED IntrinsicTypeSpec_CHARACTER

   return ATtrue;
 }

 OFP_Traverse KindSelector1;
 if (ATmatch(term, "IntrinsicTypeSpec_COMPLEX(<term>)", &KindSelector1.term)) {

   if (ATmatch(KindSelector1.term, "Some(<term>)", &KindSelector1.term)) {
      if (ofp_traverse_KindSelector(KindSelector1.term, &KindSelector1)) {
         // MATCHED KindSelector
      } else return ATfalse;
   }

   // MATCHED IntrinsicTypeSpec_COMPLEX

   return ATtrue;
 }

 if (ATmatch(term, "IntrinsicTypeSpec_DOUBLE_PRECISION")) {

   // MATCHED IntrinsicTypeSpec_DOUBLE_PRECISION

   return ATtrue;
 }

 OFP_Traverse KindSelector2;
 if (ATmatch(term, "IntrinsicTypeSpec_REAL(<term>)", &KindSelector2.term)) {

   if (ATmatch(KindSelector2.term, "Some(<term>)", &KindSelector2.term)) {
      if (ofp_traverse_KindSelector(KindSelector2.term, &KindSelector2)) {
         // MATCHED KindSelector
      } else return ATfalse;
   }

   // MATCHED IntrinsicTypeSpec_REAL

   return ATtrue;
 }

 OFP_Traverse KindSelector3;
 if (ATmatch(term, "IntrinsicTypeSpec_INTEGER(<term>)", &KindSelector3.term)) {

   if (ATmatch(KindSelector3.term, "Some(<term>)", &KindSelector3.term)) {
      if (ofp_traverse_KindSelector(KindSelector3.term, &KindSelector3)) {
         // MATCHED KindSelector
      } else return ATfalse;
   }

   // MATCHED IntrinsicTypeSpec_INTEGER

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R420 char-selector
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_CharSelector(ATerm term, pOFP_Traverse CharSelector)
{
#ifdef DEBUG_PRINT
   printf("CharSelector: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Expr;
 if (ATmatch(term, "CharSelector_KIND(<term>)", &Expr.term)) {

      if (ofp_traverse_Expr(Expr.term, &Expr)) {
         // MATCHED Expr
      } else return ATfalse;

   // MATCHED CharSelector_KIND

   return ATtrue;
 }

 OFP_Traverse Expr1, TypeParamValue;
 if (ATmatch(term, "CharSelector_KIND_LEN(<term>,<term>)", &Expr1.term, &TypeParamValue.term)) {

      if (ofp_traverse_Expr(Expr1.term, &Expr1)) {
         // MATCHED Expr
      } else return ATfalse;

#ifdef NOT_YET
      if (ofp_traverse_TypeParamValue(TypeParamValue.term, &TypeParamValue)) {
         // MATCHED TypeParamValue
      } else return ATfalse;
#endif

   // MATCHED CharSelector_KIND_LEN

   return ATtrue;
 }

 OFP_Traverse TypeParamValue1, Expr2;
 if (ATmatch(term, "CharSelector_LEN_KIND(<term>,<term>)", &TypeParamValue1.term, &Expr2.term)) {

#ifdef NOT_YET
      if (ofp_traverse_TypeParamValue(TypeParamValue1.term, &TypeParamValue1)) {
         // MATCHED TypeParamValue
      } else return ATfalse;
#endif

      if (ofp_traverse_Expr(Expr2.term, &Expr2)) {
         // MATCHED Expr
      } else return ATfalse;

   // MATCHED CharSelector_LEN_KIND

   return ATtrue;
 }

 OFP_Traverse LengthSelector;
 if (ATmatch(term, "CharSelector_LS(<term>)", &LengthSelector.term)) {

      if (ofp_traverse_LengthSelector(LengthSelector.term, &LengthSelector)) {
         // MATCHED LengthSelector
      } else return ATfalse;

   // MATCHED CharSelector_LS

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R421 length-selector
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_LengthSelector(ATerm term, pOFP_Traverse LengthSelector)
{
#ifdef DEBUG_PRINT
   printf("LengthSelector: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse CharLength;
 if (ATmatch(term, "LengthSelector_STAR(<term>)", &CharLength.term)) {

#ifdef NOT_YET
      if (ofp_traverse_CharLength(CharLength.term, &CharLength)) {
         // MATCHED CharLength
      } else return ATfalse;
#endif

   // MATCHED LengthSelector_STAR

   return ATtrue;
 }

 OFP_Traverse TypeParamValue;
 if (ATmatch(term, "LengthSelector_LEN(<term>)", &TypeParamValue.term)) {

#ifdef NOT_YET
      if (ofp_traverse_TypeParamValue(TypeParamValue.term, &TypeParamValue)) {
         // MATCHED TypeParamValue
      } else return ATfalse;
#endif

   // MATCHED LengthSelector_LEN

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R472 ac-value
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_AcValue(ATerm term, pOFP_Traverse AcValue)
{
#ifdef DEBUG_PRINT
   printf("AcValue: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse AcImpliedDo;
 if (ATmatch(term, "AcValue(<term>)", &AcImpliedDo.term)) {

#ifdef NOT_YET
      if (ofp_traverse_AcImpliedDo(AcImpliedDo.term, &AcImpliedDo)) {
         // MATCHED AcImpliedDo
      } else return ATfalse;
#endif

   return ATtrue;
 }

 OFP_Traverse Expr;
 if (ATmatch(term, "AcValue(<term>)", &Expr.term)) {

      if (ofp_traverse_Expr(Expr.term, &Expr)) {
         // MATCHED Expr
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}


/**
 * Section/Clause 5: Attribute declarations and specifications
 */

//========================================================================================
// R501 type-declaration-stmt
//----------------------------------------------------------------------------------------
#ifdef USE_FINISHED
ATbool ofp_traverse_TypeDeclarationStmt(ATerm term, pOFP_Traverse TypeDeclarationStmt)
{
#ifdef DEBUG_PRINT
   printf("\nTypeDeclarationStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, DeclarationTypeSpec, AttrSpecList, EntityDeclList, EOS;
 if (ATmatch(term, "TypeDeclarationStmt(<term>,<term>,<term>,<term>,<term>)", &Label.term, &DeclarationTypeSpec.term, &AttrSpecList.term, &EntityDeclList.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_DeclarationTypeSpec(DeclarationTypeSpec.term, &DeclarationTypeSpec)) {
         // MATCHED DeclarationTypeSpec
      } else return ATfalse;

   if (ATmatch(AttrSpecList.term, "Some(<term>)", &AttrSpecList.term)) {
   if (ATmatch(AttrSpecList.term, "(Some(<term>))", &AttrSpecList.term)) {
   if (ATmatch(AttrSpecList.term, "(<term>)", &AttrSpecList.term)) {
      if (ofp_traverse_AttrSpecList(AttrSpecList.term, &AttrSpecList)) {
         // MATCHED AttrSpecList
      } else return ATfalse;
   }
   }
   }

      if (ofp_traverse_EntityDeclList(EntityDeclList.term, &EntityDeclList)) {
         // MATCHED EntityDeclList
      } else return ATfalse;

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}
#endif

//========================================================================================
// R502 attr-spec
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_AttrSpec(ATerm term, pOFP_Traverse AttrSpec)
{
#ifdef DEBUG_PRINT
   printf("AttrSpec: %s\n", ATwriteToString(term));
#endif

 if (ATmatch(term, "AttrSpec_VOLATILE")) {

   // MATCHED AttrSpec_VOLATILE

   return ATtrue;
 }

 if (ATmatch(term, "AttrSpec_VALUE")) {

   // MATCHED AttrSpec_VALUE

   return ATtrue;
 }

 if (ATmatch(term, "AttrSpec_TARGET")) {

   // MATCHED AttrSpec_TARGET

   return ATtrue;
 }

 if (ATmatch(term, "AttrSpec_SAVE")) {

   // MATCHED AttrSpec_SAVE

   return ATtrue;
 }

 if (ATmatch(term, "AttrSpec_PROTECTED")) {

   // MATCHED AttrSpec_PROTECTED

   return ATtrue;
 }

 if (ATmatch(term, "AttrSpec_POINTER")) {

   // MATCHED AttrSpec_POINTER

   return ATtrue;
 }

 if (ATmatch(term, "AttrSpec_PARAMETER")) {

   // MATCHED AttrSpec_PARAMETER

   return ATtrue;
 }

 if (ATmatch(term, "AttrSpec_OPTIONAL")) {

   // MATCHED AttrSpec_OPTIONAL

   return ATtrue;
 }

 OFP_Traverse LanguageBindingSpec;
 if (ATmatch(term, "AttrSpec_LBS(<term>)", &LanguageBindingSpec.term)) {

#ifdef NOT_YET
      if (ofp_traverse_LanguageBindingSpec(LanguageBindingSpec.term, &LanguageBindingSpec)) {
         // MATCHED LanguageBindingSpec
      } else return ATfalse;
#endif

   // MATCHED AttrSpec_LBS

   return ATtrue;
 }

 if (ATmatch(term, "AttrSpec_INTRINSIC")) {

   // MATCHED AttrSpec_INTRINSIC

   return ATtrue;
 }

 OFP_Traverse IntentSpec;
 if (ATmatch(term, "AttrSpec_INTENT(<term>)", &IntentSpec.term)) {

#ifdef NOT_YET
      if (ofp_traverse_IntentSpec(IntentSpec.term, &IntentSpec)) {
         // MATCHED IntentSpec
      } else return ATfalse;
#endif

   // MATCHED AttrSpec_INTENT

   return ATtrue;
 }

 if (ATmatch(term, "AttrSpec_EXTERNAL")) {

   // MATCHED AttrSpec_EXTERNAL

   return ATtrue;
 }

 OFP_Traverse ArraySpec;
 if (ATmatch(term, "AttrSpec_DIMENSION(<term>)", &ArraySpec.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ArraySpec(ArraySpec.term, &ArraySpec)) {
         // MATCHED ArraySpec
      } else return ATfalse;
#endif

   // MATCHED AttrSpec_DIMENSION

   return ATtrue;
 }

 if (ATmatch(term, "AttrSpec_CONTIGUOUS")) {

   // MATCHED AttrSpec_CONTIGUOUS

   return ATtrue;
 }

 OFP_Traverse CoarraySpec;
 if (ATmatch(term, "AttrSpec_CODIMENSION(<term>)", &CoarraySpec.term)) {

#ifdef NOT_YET
      if (ofp_traverse_CoarraySpec(CoarraySpec.term, &CoarraySpec)) {
         // MATCHED CoarraySpec
      } else return ATfalse;
#endif

   // MATCHED AttrSpec_CODIMENSION

   return ATtrue;
 }

 if (ATmatch(term, "AttrSpec_ASYNCHRONOUS")) {

   // MATCHED AttrSpec_ASYNCHRONOUS

   return ATtrue;
 }

 if (ATmatch(term, "AttrSpec_ALLOCATABLE")) {

   // MATCHED AttrSpec_ALLOCATABLE

   return ATtrue;
 }

 OFP_Traverse AccessSpec;
 if (ATmatch(term, "AttrSpec_AS(<term>)", &AccessSpec.term)) {

#ifdef NOT_YET
      if (ofp_traverse_AccessSpec(AccessSpec.term, &AccessSpec)) {
         // MATCHED AccessSpec
      } else return ATfalse;
#endif

   // MATCHED AttrSpec_AS

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R503 entity-decl
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_EntityDecl(ATerm term, pOFP_Traverse EntityDecl)
{
#ifdef DEBUG_PRINT
   printf("EntityDecl: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse ObjectName, ArraySpec, CoarraySpec, CharLength, Initialization;
 if (ATmatch(term, "EntityDecl(<term>,<term>,<term>,<term>,<term>)", &ObjectName.term, &ArraySpec.term, &CoarraySpec.term, &CharLength.term, &Initialization.term)) {

      if (ofp_traverse_ObjectName(ObjectName.term, &ObjectName)) {
         // MATCHED ObjectName
      } else return ATfalse;

   if (ATmatch(ArraySpec.term, "Some(<term>)", &ArraySpec.term)) {
   if (ATmatch(ArraySpec.term, "(<term>)", &ArraySpec.term)) {
#ifdef NOT_YET
      if (ofp_traverse_ArraySpec(ArraySpec.term, &ArraySpec)) {
         // MATCHED ArraySpec
      } else return ATfalse;
#endif
   }
   }

   if (ATmatch(CoarraySpec.term, "Some(<term>)", &CoarraySpec.term)) {
   if (ATmatch(CoarraySpec.term, "(<term>)", &CoarraySpec.term)) {
#ifdef NOT_YET
      if (ofp_traverse_CoarraySpec(CoarraySpec.term, &CoarraySpec)) {
         // MATCHED CoarraySpec
      } else return ATfalse;
#endif
   }
   }

   if (ATmatch(CharLength.term, "Some(<term>)", &CharLength.term)) {
   if (ATmatch(CharLength.term, "(<term>)", &CharLength.term)) {
#ifdef NOT_YET
      if (ofp_traverse_CharLength(CharLength.term, &CharLength)) {
         // MATCHED CharLength
      } else return ATfalse;
#endif
   }
   }

   if (ATmatch(Initialization.term, "Some(<term>)", &Initialization.term)) {
#ifdef NOT_YET
      if (ofp_traverse_Initialization(Initialization.term, &Initialization)) {
         // MATCHED Initialization
      } else return ATfalse;
#endif
   }

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R601 designator
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_Designator(ATerm term, pOFP_Traverse Designator)
{
#ifdef DEBUG_PRINT
   printf("Designator: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Substring;
 if (ATmatch(term, "Designator_AMB(<term>)", &Substring.term)) {

      if (ofp_traverse_Substring(Substring.term, &Substring)) {
         // MATCHED Substring
      } else return ATfalse;

   // MATCHED Designator_AMB

   return ATtrue;
 }

 OFP_Traverse DataRef;
 if (ATmatch(term, "Designator_AMB(<term>)", &DataRef.term)) {

      if (ofp_traverse_DataRef(DataRef.term, &DataRef)) {
         // MATCHED DataRef
      } else return ATfalse;

   // MATCHED Designator_AMB

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R602 variable
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_Variable(ATerm term, pOFP_Traverse Variable)
{
#ifdef DEBUG_PRINT
   printf("Variable: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Designator;
 if (ATmatch(term, "Variable(<term>)", &Designator.term)) {

      if (ofp_traverse_Designator(Designator.term, &Designator)) {
         // MATCHED Designator
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R603 variable-name
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_VariableName(ATerm term, pOFP_Traverse VariableName)
{
#ifdef DEBUG_PRINT
   printf("VariableName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "VariableName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R604 logical-variable
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_LogicalVariable(ATerm term, pOFP_Traverse LogicalVariable)
{
#ifdef DEBUG_PRINT
   printf("LogicalVariable: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Variable;
 if (ATmatch(term, "LogicalVariable(<term>)", &Variable.term)) {

      if (ofp_traverse_Variable(Variable.term, &Variable)) {
         // MATCHED Variable
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R605 char-variable
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_CharVariable(ATerm term, pOFP_Traverse CharVariable)
{
#ifdef DEBUG_PRINT
   printf("CharVariable: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Variable;
 if (ATmatch(term, "CharVariable(<term>)", &Variable.term)) {

      if (ofp_traverse_Variable(Variable.term, &Variable)) {
         // MATCHED Variable
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R606 default-char-variable
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_DefaultCharVariable(ATerm term, pOFP_Traverse DefaultCharVariable)
{
#ifdef DEBUG_PRINT
   printf("DefaultCharVariable: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Variable;
 if (ATmatch(term, "DefaultCharVariable(<term>)", &Variable.term)) {

      if (ofp_traverse_Variable(Variable.term, &Variable)) {
         // MATCHED Variable
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R607 int-variable
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_IntVariable(ATerm term, pOFP_Traverse IntVariable)
{
#ifdef DEBUG_PRINT
   printf("IntVariable: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Variable;
 if (ATmatch(term, "IntVariable(<term>)", &Variable.term)) {

      if (ofp_traverse_Variable(Variable.term, &Variable)) {
         // MATCHED Variable
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R608 substring
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_Substring(ATerm term, pOFP_Traverse Substring)
{
#ifdef DEBUG_PRINT
   printf("Substring: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse ParentString, SubstringRange;
 if (ATmatch(term, "Substring(<term>,<term>)", &ParentString.term, &SubstringRange.term)) {

      if (ofp_traverse_ParentString(ParentString.term, &ParentString)) {
         // MATCHED ParentString
      } else return ATfalse;

      if (ofp_traverse_SubstringRange(SubstringRange.term, &SubstringRange)) {
         // MATCHED SubstringRange
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R609 parent-string
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_ParentString(ATerm term, pOFP_Traverse ParentString)
{
#ifdef DEBUG_PRINT
   printf("ParentString: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Constant;
 if (ATmatch(term, "ParentString_C(<term>)", &Constant.term)) {

      if (ofp_traverse_Constant(Constant.term, &Constant)) {
         // MATCHED Constant
      } else return ATfalse;

   // MATCHED ParentString_C

   return ATtrue;
 }

 OFP_Traverse StructureComponent;
 if (ATmatch(term, "ParentString_SC(<term>)", &StructureComponent.term)) {

      if (ofp_traverse_StructureComponent(StructureComponent.term, &StructureComponent)) {
         // MATCHED StructureComponent
      } else return ATfalse;

   // MATCHED ParentString_SC

   return ATtrue;
 }

 OFP_Traverse CoindexedNamedObject;
 if (ATmatch(term, "ParentString_CNO(<term>)", &CoindexedNamedObject.term)) {

      if (ofp_traverse_CoindexedNamedObject(CoindexedNamedObject.term, &CoindexedNamedObject)) {
         // MATCHED CoindexedNamedObject
      } else return ATfalse;

   // MATCHED ParentString_CNO

   return ATtrue;
 }

 OFP_Traverse ArrayElement;
 if (ATmatch(term, "ParentString_AE(<term>)", &ArrayElement.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ArrayElement(ArrayElement.term, &ArrayElement)) {
         // MATCHED ArrayElement
      } else return ATfalse;
#endif

   // MATCHED ParentString_AE

   return ATtrue;
 }

 OFP_Traverse ScalarVariableName;
 if (ATmatch(term, "ParentString_SVN(<term>)", &ScalarVariableName.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ScalarVariableName(ScalarVariableName.term, &ScalarVariableName)) {
         // MATCHED ScalarVariableName
      } else return ATfalse;
#endif

   // MATCHED ParentString_SVN

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R610 substring-range
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_SubstringRange(ATerm term, pOFP_Traverse SubstringRange)
{
#ifdef DEBUG_PRINT
   printf("SubstringRange: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse IntExpr, IntExpr1;
 if (ATmatch(term, "SubstringRange(<term>,<term>)", &IntExpr.term, &IntExpr1.term)) {

   if (ATmatch(IntExpr.term, "Some(<term>)", &IntExpr.term)) {
#ifdef NOT_YET
      if (ofp_traverse_IntExpr(IntExpr.term, &IntExpr)) {
         // MATCHED IntExpr
      } else return ATfalse;
#endif
   }

   if (ATmatch(IntExpr1.term, "Some(<term>)", &IntExpr1.term)) {
#ifdef NOT_YET
      if (ofp_traverse_IntExpr(IntExpr1.term, &IntExpr1)) {
         // MATCHED IntExpr
      } else return ATfalse;
#endif
   }

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R611 data-ref
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_DataRef(ATerm term, pOFP_Traverse DataRef)
{
#ifdef DEBUG_PRINT
   printf("DataRef: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse PartRef;
 if (ATmatch(term, "DataRef(<term>)", &PartRef.term)) {

   ATermList PartRef_tail = (ATermList) ATmake("<term>", PartRef.term);
   while (! ATisEmpty(PartRef_tail)) {
      PartRef.term = ATgetFirst(PartRef_tail);
      PartRef_tail = ATgetNext (PartRef_tail);
      if (ofp_traverse_PartRef(PartRef.term, &PartRef)) {
         // MATCHED PartRef
      } else return ATfalse;
   }

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R612 part-ref
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_PartRef(ATerm term, pOFP_Traverse PartRef)
{
#ifdef DEBUG_PRINT
   printf("PartRef: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse PartName, SectionSubscriptList, ImageSelector;
 if (ATmatch(term, "PartRef(<term>,<term>,<term>)", &PartName.term, &SectionSubscriptList.term, &ImageSelector.term)) {

      if (ofp_traverse_PartName(PartName.term, &PartName)) {
         // MATCHED PartName
      } else return ATfalse;

   if (ATmatch(SectionSubscriptList.term, "Some(<term>)", &SectionSubscriptList.term)) {
   if (ATmatch(SectionSubscriptList.term, "(<term>)", &SectionSubscriptList.term)) {
#ifdef NOT_YET
      if (ofp_traverse_SectionSubscriptList(SectionSubscriptList.term, &SectionSubscriptList)) {
         // MATCHED SectionSubscriptList
      } else return ATfalse;
#endif
   }
   }

   if (ATmatch(ImageSelector.term, "Some(<term>)", &ImageSelector.term)) {
#ifdef NOT_YET
      if (ofp_traverse_ImageSelector(ImageSelector.term, &ImageSelector)) {
         // MATCHED ImageSelector
      } else return ATfalse;
#endif
   }

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R613 structure-component
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_StructureComponent(ATerm term, pOFP_Traverse StructureComponent)
{
#ifdef DEBUG_PRINT
   printf("StructureComponent: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse DataRef;
 if (ATmatch(term, "StructureComponent(<term>)", &DataRef.term)) {

      if (ofp_traverse_DataRef(DataRef.term, &DataRef)) {
         // MATCHED DataRef
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R614 coindexed-named-object
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_CoindexedNamedObject(ATerm term, pOFP_Traverse CoindexedNamedObject)
{
#ifdef DEBUG_PRINT
   printf("CoindexedNamedObject: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse DataRef;
 if (ATmatch(term, "CoindexedNamedObject(<term>)", &DataRef.term)) {

      if (ofp_traverse_DataRef(DataRef.term, &DataRef)) {
         // MATCHED DataRef
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R615 complex-part-designator
//----------------------------------------------------------------------------------------

//========================================================================================
// R616 type-param-inquiry
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_TypeParamInquiry(ATerm term, pOFP_Traverse TypeParamInquiry)
{
#ifdef DEBUG_PRINT
   printf("TypeParamInquiry: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Designator, TypeParamName;
 if (ATmatch(term, "TypeParamInquiry(<term>,<term>)", &Designator.term, &TypeParamName.term)) {

      if (ofp_traverse_Designator(Designator.term, &Designator)) {
         // MATCHED Designator
      } else return ATfalse;

      if (ofp_traverse_TypeParamName(TypeParamName.term, &TypeParamName)) {
         // MATCHED TypeParamName
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R801 block
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_Block(ATerm term, pOFP_Traverse Block)
{
#ifdef DEBUG_PRINT
   printf("Block: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse ExecutionPartConstruct;
 if (ATmatch(term, "Block(<term>)", &ExecutionPartConstruct.term)) {

   ATermList ExecutionPartConstruct_tail = (ATermList) ATmake("<term>", ExecutionPartConstruct.term);
   while (! ATisEmpty(ExecutionPartConstruct_tail)) {
      ExecutionPartConstruct.term = ATgetFirst(ExecutionPartConstruct_tail);
      ExecutionPartConstruct_tail = ATgetNext (ExecutionPartConstruct_tail);
      if (ofp_traverse_ExecutionPartConstruct(ExecutionPartConstruct.term, &ExecutionPartConstruct)) {
         // MATCHED ExecutionPartConstruct
      } else return ATfalse;
   }

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R802 associate-construct
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_AssociateConstruct(ATerm term, pOFP_Traverse AssociateConstruct)
{
#ifdef DEBUG_PRINT
   printf("AssociateConstruct: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse AssociateStmt, Block, EndAssociateStmt;
 if (ATmatch(term, "AssociateConstruct(<term>,<term>,<term>)", &AssociateStmt.term, &Block.term, &EndAssociateStmt.term)) {

      if (ofp_traverse_AssociateStmt(AssociateStmt.term, &AssociateStmt)) {
         // MATCHED AssociateStmt
      } else return ATfalse;

      if (ofp_traverse_Block(Block.term, &Block)) {
         // MATCHED Block
      } else return ATfalse;

      if (ofp_traverse_EndAssociateStmt(EndAssociateStmt.term, &EndAssociateStmt)) {
         // MATCHED EndAssociateStmt
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R803 associate-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_AssociateStmt(ATerm term, pOFP_Traverse AssociateStmt)
{
#ifdef DEBUG_PRINT
   printf("AssociateStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, AssociateConstructName, AssociationList, EOS;
 if (ATmatch(term, "AssociateStmt(<term>,<term>,<term>,<term>)", &Label.term, &AssociateConstructName.term, &AssociationList.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

   if (ATmatch(AssociateConstructName.term, "Some(<term>)", &AssociateConstructName.term)) {
   if (ATmatch(AssociateConstructName.term, "(<term>)", &AssociateConstructName.term)) {
      if (ofp_traverse_AssociateConstructName(AssociateConstructName.term, &AssociateConstructName)) {
         // MATCHED AssociateConstructName
      } else return ATfalse;
   }
   }

      if (ofp_traverse_AssociationList(AssociationList.term, &AssociationList)) {
         // MATCHED AssociationList
      } else return ATfalse;

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R804 association
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_Association(ATerm term, pOFP_Traverse Association)
{
#ifdef DEBUG_PRINT
   printf("Association: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse AssociateName, Selector;
 if (ATmatch(term, "Association(<term>,<term>)", &AssociateName.term, &Selector.term)) {

      if (ofp_traverse_AssociateName(AssociateName.term, &AssociateName)) {
         // MATCHED AssociateName
      } else return ATfalse;

      if (ofp_traverse_Selector(Selector.term, &Selector)) {
         // MATCHED Selector
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_AssociationList(ATerm term, pOFP_Traverse AssociationList)
{
#ifdef DEBUG_PRINT
   printf("AssociationList: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Association;
 if (ATmatch(term, "AssociationList(<term>)", &Association.term)) {

   ATermList Association_tail = (ATermList) ATmake("<term>", Association.term);
   while (! ATisEmpty(Association_tail)) {
      Association.term = ATgetFirst(Association_tail);
      Association_tail = ATgetNext (Association_tail);
      if (ofp_traverse_Association(Association.term, &Association)) {
         // MATCHED Association
      } else return ATfalse;
   }

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R805 selector
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_Selector(ATerm term, pOFP_Traverse Selector)
{
#ifdef DEBUG_PRINT
   printf("Selector: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Variable;
 if (ATmatch(term, "Selector_V(<term>)", &Variable.term)) {

      if (ofp_traverse_Variable(Variable.term, &Variable)) {
         // MATCHED Variable
      } else return ATfalse;

   // MATCHED Selector_V

   return ATtrue;
 }

 OFP_Traverse Expr;
 if (ATmatch(term, "Selector_E(<term>)", &Expr.term)) {

      if (ofp_traverse_Expr(Expr.term, &Expr)) {
         // MATCHED Expr
      } else return ATfalse;

   // MATCHED Selector_E

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R806 end-associate-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_EndAssociateStmt(ATerm term, pOFP_Traverse EndAssociateStmt)
{
#ifdef DEBUG_PRINT
   printf("EndAssociateStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, AssociateConstructName, EOS;
 if (ATmatch(term, "EndAssociateStmt(<term>,<term>,<term>)", &Label.term, &AssociateConstructName.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

   if (ATmatch(AssociateConstructName.term, "Some(<term>)", &AssociateConstructName.term)) {
      if (ofp_traverse_AssociateConstructName(AssociateConstructName.term, &AssociateConstructName)) {
         // MATCHED AssociateConstructName
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R807 block-construct
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_BlockConstruct(ATerm term, pOFP_Traverse BlockConstruct)
{
#ifdef DEBUG_PRINT
   printf("BlockConstruct: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse BlockStmt, SpecificationPart, Block, EndBlockStmt;
 if (ATmatch(term, "BlockConstruct(<term>,<term>,<term>,<term>)", &BlockStmt.term, &SpecificationPart.term, &Block.term, &EndBlockStmt.term)) {

      if (ofp_traverse_BlockStmt(BlockStmt.term, &BlockStmt)) {
         // MATCHED BlockStmt
      } else return ATfalse;

      if (ofp_traverse_SpecificationPart(SpecificationPart.term, &SpecificationPart)) {
         // MATCHED SpecificationPart
      } else return ATfalse;

      if (ofp_traverse_Block(Block.term, &Block)) {
         // MATCHED Block
      } else return ATfalse;

      if (ofp_traverse_EndBlockStmt(EndBlockStmt.term, &EndBlockStmt)) {
         // MATCHED EndBlockStmt
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R808 block-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_BlockStmt(ATerm term, pOFP_Traverse BlockStmt)
{
#ifdef DEBUG_PRINT
   printf("BlockStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, BlockConstructName, EOS;
 if (ATmatch(term, "BlockStmt(<term>,<term>,<term>)", &Label.term, &BlockConstructName.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

   if (ATmatch(BlockConstructName.term, "Some(<term>)", &BlockConstructName.term)) {
   if (ATmatch(BlockConstructName.term, "(<term>)", &BlockConstructName.term)) {
      if (ofp_traverse_BlockConstructName(BlockConstructName.term, &BlockConstructName)) {
         // MATCHED BlockConstructName
      } else return ATfalse;
   }
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R809 end-block-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_EndBlockStmt(ATerm term, pOFP_Traverse EndBlockStmt)
{
#ifdef DEBUG_PRINT
   printf("EndBlockStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, BlockConstructName, EOS;
 if (ATmatch(term, "EndBlockStmt(<term>,<term>,<term>)", &Label.term, &BlockConstructName.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

   if (ATmatch(BlockConstructName.term, "Some(<term>)", &BlockConstructName.term)) {
      if (ofp_traverse_BlockConstructName(BlockConstructName.term, &BlockConstructName)) {
         // MATCHED BlockConstructName
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R810 critical-construct
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_CriticalConstruct(ATerm term, pOFP_Traverse CriticalConstruct)
{
#ifdef DEBUG_PRINT
   printf("CriticalConstruct: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse CriticalStmt, Block, EndCriticalStmt;
 if (ATmatch(term, "CriticalConstruct(<term>,<term>,<term>)", &CriticalStmt.term, &Block.term, &EndCriticalStmt.term)) {

      if (ofp_traverse_CriticalStmt(CriticalStmt.term, &CriticalStmt)) {
         // MATCHED CriticalStmt
      } else return ATfalse;

      if (ofp_traverse_Block(Block.term, &Block)) {
         // MATCHED Block
      } else return ATfalse;

      if (ofp_traverse_EndCriticalStmt(EndCriticalStmt.term, &EndCriticalStmt)) {
         // MATCHED EndCriticalStmt
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R811 critical-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_CriticalStmt(ATerm term, pOFP_Traverse CriticalStmt)
{
#ifdef DEBUG_PRINT
   printf("CriticalStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, CriticalConstructName, EOS;
 if (ATmatch(term, "CriticalStmt(<term>,<term>,<term>)", &Label.term, &CriticalConstructName.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

   if (ATmatch(CriticalConstructName.term, "Some(<term>)", &CriticalConstructName.term)) {
   if (ATmatch(CriticalConstructName.term, "(<term>)", &CriticalConstructName.term)) {
      if (ofp_traverse_CriticalConstructName(CriticalConstructName.term, &CriticalConstructName)) {
         // MATCHED CriticalConstructName
      } else return ATfalse;
   }
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R812 end-critical-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_EndCriticalStmt(ATerm term, pOFP_Traverse EndCriticalStmt)
{
#ifdef DEBUG_PRINT
   printf("EndCriticalStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, CriticalConstructName, EOS;
 if (ATmatch(term, "EndCriticalStmt(<term>,<term>,<term>)", &Label.term, &CriticalConstructName.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

   if (ATmatch(CriticalConstructName.term, "Some(<term>)", &CriticalConstructName.term)) {
      if (ofp_traverse_CriticalConstructName(CriticalConstructName.term, &CriticalConstructName)) {
         // MATCHED CriticalConstructName
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R813 do-construct
//----------------------------------------------------------------------------------------

//========================================================================================
// R814 block-do-construct
//----------------------------------------------------------------------------------------

//========================================================================================
// R815 do-stmt
//----------------------------------------------------------------------------------------

//========================================================================================
// R816 label-do-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_LabelDoStmt(ATerm term, pOFP_Traverse LabelDoStmt)
{
#ifdef DEBUG_PRINT
   printf("LabelDoStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, DoConstructName, LblRef, LoopControl, EOS;
 if (ATmatch(term, "LabelDoStmt(<term>,<term>,<term>,<term>,<term>)", &Label.term, &DoConstructName.term, &LblRef.term, &LoopControl.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

   if (ATmatch(DoConstructName.term, "Some(<term>)", &DoConstructName.term)) {
   if (ATmatch(DoConstructName.term, "(<term>)", &DoConstructName.term)) {
      if (ofp_traverse_DoConstructName(DoConstructName.term, &DoConstructName)) {
         // MATCHED DoConstructName
      } else return ATfalse;
   }
   }

#ifdef NOT_YET
      if (ofp_traverse_LblRef(LblRef.term, &LblRef)) {
         // MATCHED LblRef
      } else return ATfalse;
#endif

   if (ATmatch(LoopControl.term, "Some(<term>)", &LoopControl.term)) {
      if (ofp_traverse_LoopControl(LoopControl.term, &LoopControl)) {
         // MATCHED LoopControl
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R817 non-label-do-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_NonlabelDoStmt(ATerm term, pOFP_Traverse NonlabelDoStmt)
{
#ifdef DEBUG_PRINT
   printf("NonlabelDoStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, DoConstructName, LoopControl, EOS;
 if (ATmatch(term, "NonlabelDoStmt(<term>,<term>,<term>,<term>)", &Label.term, &DoConstructName.term, &LoopControl.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

   if (ATmatch(DoConstructName.term, "Some(<term>)", &DoConstructName.term)) {
   if (ATmatch(DoConstructName.term, "(<term>)", &DoConstructName.term)) {
      if (ofp_traverse_DoConstructName(DoConstructName.term, &DoConstructName)) {
         // MATCHED DoConstructName
      } else return ATfalse;
   }
   }

   if (ATmatch(LoopControl.term, "Some(<term>)", &LoopControl.term)) {
      if (ofp_traverse_LoopControl(LoopControl.term, &LoopControl)) {
         // MATCHED LoopControl
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R818 loop-control
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_LoopControl(ATerm term, pOFP_Traverse LoopControl)
{
#ifdef DEBUG_PRINT
   printf("LoopControl: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse ForallHeader;
 if (ATmatch(term, "LoopControl_CONCURRENT(<term>)", &ForallHeader.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ForallHeader(ForallHeader.term, &ForallHeader)) {
         // MATCHED ForallHeader
      } else return ATfalse;
#endif

   // MATCHED LoopControl_CONCURRENT

   return ATtrue;
 }

 OFP_Traverse Expr;
 if (ATmatch(term, "LoopControl_WHILE(<term>)", &Expr.term)) {

      if (ofp_traverse_Expr(Expr.term, &Expr)) {
         // MATCHED Expr
      } else return ATfalse;

   // MATCHED LoopControl_WHILE

   return ATtrue;
 }

 OFP_Traverse DoVariable, Expr1, Expr2, Expr3;
 if (ATmatch(term, "LoopControl_DV(<term>,<term>,<term>,<term>)", &DoVariable.term, &Expr1.term, &Expr2.term, &Expr3.term)) {

      if (ofp_traverse_DoVariable(DoVariable.term, &DoVariable)) {
         // MATCHED DoVariable
      } else return ATfalse;

      if (ofp_traverse_Expr(Expr1.term, &Expr1)) {
         // MATCHED Expr
      } else return ATfalse;

      if (ofp_traverse_Expr(Expr2.term, &Expr2)) {
         // MATCHED Expr
      } else return ATfalse;

   if (ATmatch(Expr3.term, "Some(<term>)", &Expr3.term)) {
   if (ATmatch(Expr3.term, "(<term>)", &Expr3.term)) {
      if (ofp_traverse_Expr(Expr3.term, &Expr3)) {
         // MATCHED Expr
      } else return ATfalse;
   }
   }

   // MATCHED LoopControl_DV

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R819 do-variable
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_DoVariable(ATerm term, pOFP_Traverse DoVariable)
{
#ifdef DEBUG_PRINT
   printf("DoVariable: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse ScalarIntVariableName;
 if (ATmatch(term, "DoVariable(<term>)", &ScalarIntVariableName.term)) {

      if (ofp_traverse_ScalarIntVariableName(ScalarIntVariableName.term, &ScalarIntVariableName)) {
         // MATCHED ScalarIntVariableName
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R820 do-block
//----------------------------------------------------------------------------------------

//========================================================================================
// R821 end-do
//----------------------------------------------------------------------------------------

//========================================================================================
// R822 end-do-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_EndDoStmt(ATerm term, pOFP_Traverse EndDoStmt)
{
#ifdef DEBUG_PRINT
   printf("EndDoStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, DoConstructName, EOS;
 if (ATmatch(term, "EndDoStmt(<term>,<term>,<term>)", &Label.term, &DoConstructName.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

   if (ATmatch(DoConstructName.term, "Some(<term>)", &DoConstructName.term)) {
      if (ofp_traverse_DoConstructName(DoConstructName.term, &DoConstructName)) {
         // MATCHED DoConstructName
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_CycleStmt(ATerm term, pOFP_Traverse CycleStmt)
{
#ifdef DEBUG_PRINT
   printf("CycleStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, DoConstructName, EOS;
 if (ATmatch(term, "CycleStmt(<term>,<term>,<term>)", &Label.term, &DoConstructName.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

   if (ATmatch(DoConstructName.term, "Some(<term>)", &DoConstructName.term)) {
      if (ofp_traverse_DoConstructName(DoConstructName.term, &DoConstructName)) {
         // MATCHED DoConstructName
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_IfThenStmt(ATerm term, pOFP_Traverse IfThenStmt)
{
#ifdef DEBUG_PRINT
   printf("IfThenStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, IfConstructName, LogicalExpr, EOS;
 if (ATmatch(term, "IfThenStmt(<term>,<term>,<term>,<term>)", &Label.term, &IfConstructName.term, &LogicalExpr.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

   if (ATmatch(IfConstructName.term, "Some(<term>)", &IfConstructName.term)) {
   if (ATmatch(IfConstructName.term, "(<term>)", &IfConstructName.term)) {
      if (ofp_traverse_IfConstructName(IfConstructName.term, &IfConstructName)) {
         // MATCHED IfConstructName
      } else return ATfalse;
   }
   }

#ifdef NOT_YET
      if (ofp_traverse_LogicalExpr(LogicalExpr.term, &LogicalExpr)) {
         // MATCHED LogicalExpr
      } else return ATfalse;
#endif

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ElseIfStmt(ATerm term, pOFP_Traverse ElseIfStmt)
{
#ifdef DEBUG_PRINT
   printf("ElseIfStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, LogicalExpr, IfConstructName, EOS;
 if (ATmatch(term, "ElseIfStmt(<term>,<term>,<term>,<term>)", &Label.term, &LogicalExpr.term, &IfConstructName.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

#ifdef NOT_YET
      if (ofp_traverse_LogicalExpr(LogicalExpr.term, &LogicalExpr)) {
         // MATCHED LogicalExpr
      } else return ATfalse;
#endif

   if (ATmatch(IfConstructName.term, "Some(<term>)", &IfConstructName.term)) {
      if (ofp_traverse_IfConstructName(IfConstructName.term, &IfConstructName)) {
         // MATCHED IfConstructName
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ElseStmt(ATerm term, pOFP_Traverse ElseStmt)
{
#ifdef DEBUG_PRINT
   printf("ElseStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, IfConstructName, EOS;
 if (ATmatch(term, "ElseStmt(<term>,<term>,<term>)", &Label.term, &IfConstructName.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

   if (ATmatch(IfConstructName.term, "Some(<term>)", &IfConstructName.term)) {
      if (ofp_traverse_IfConstructName(IfConstructName.term, &IfConstructName)) {
         // MATCHED IfConstructName
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_EndIfStmt(ATerm term, pOFP_Traverse EndIfStmt)
{
#ifdef DEBUG_PRINT
   printf("EndIfStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, IfConstructName, EOS;
 if (ATmatch(term, "EndIfStmt(<term>,<term>,<term>)", &Label.term, &IfConstructName.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

   if (ATmatch(IfConstructName.term, "Some(<term>)", &IfConstructName.term)) {
      if (ofp_traverse_IfConstructName(IfConstructName.term, &IfConstructName)) {
         // MATCHED IfConstructName
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_IfStmt(ATerm term, pOFP_Traverse IfStmt)
{
#ifdef DEBUG_PRINT
   printf("IfStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, LogicalExpr, ActionStmt;
 if (ATmatch(term, "IfStmt(<term>,<term>,<term>)", &Label.term, &LogicalExpr.term, &ActionStmt.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

#ifdef NOT_YET
      if (ofp_traverse_LogicalExpr(LogicalExpr.term, &LogicalExpr)) {
         // MATCHED LogicalExpr
      } else return ATfalse;
#endif

      if (ofp_traverse_ActionStmt(ActionStmt.term, &ActionStmt)) {
         // MATCHED ActionStmt
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_SelectCaseStmt(ATerm term, pOFP_Traverse SelectCaseStmt)
{
#ifdef DEBUG_PRINT
   printf("SelectCaseStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, CaseConstructName, CaseExpr, EOS;
 if (ATmatch(term, "SelectCaseStmt(<term>,<term>,<term>,<term>)", &Label.term, &CaseConstructName.term, &CaseExpr.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

   if (ATmatch(CaseConstructName.term, "Some(<term>)", &CaseConstructName.term)) {
   if (ATmatch(CaseConstructName.term, "(<term>)", &CaseConstructName.term)) {
      if (ofp_traverse_CaseConstructName(CaseConstructName.term, &CaseConstructName)) {
         // MATCHED CaseConstructName
      } else return ATfalse;
   }
   }

      if (ofp_traverse_CaseExpr(CaseExpr.term, &CaseExpr)) {
         // MATCHED CaseExpr
      } else return ATfalse;

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_CaseStmt(ATerm term, pOFP_Traverse CaseStmt)
{
#ifdef DEBUG_PRINT
   printf("CaseStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, CaseSelector, CaseConstructName, EOS;
 if (ATmatch(term, "CaseStmt(<term>,<term>,<term>,<term>)", &Label.term, &CaseSelector.term, &CaseConstructName.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_CaseSelector(CaseSelector.term, &CaseSelector)) {
         // MATCHED CaseSelector
      } else return ATfalse;

   if (ATmatch(CaseConstructName.term, "Some(<term>)", &CaseConstructName.term)) {
      if (ofp_traverse_CaseConstructName(CaseConstructName.term, &CaseConstructName)) {
         // MATCHED CaseConstructName
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_EndSelectStmt(ATerm term, pOFP_Traverse EndSelectStmt)
{
#ifdef DEBUG_PRINT
   printf("EndSelectStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, CaseConstructName, EOS;
 if (ATmatch(term, "EndSelectStmt(<term>,<term>,<term>)", &Label.term, &CaseConstructName.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

   if (ATmatch(CaseConstructName.term, "Some(<term>)", &CaseConstructName.term)) {
      if (ofp_traverse_CaseConstructName(CaseConstructName.term, &CaseConstructName)) {
         // MATCHED CaseConstructName
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_CaseExpr(ATerm term, pOFP_Traverse CaseExpr)
{
#ifdef DEBUG_PRINT
   printf("CaseExpr: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Expr;
 if (ATmatch(term, "CaseExpr(<term>)", &Expr.term)) {

      if (ofp_traverse_Expr(Expr.term, &Expr)) {
         // MATCHED Expr
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_CaseSelector(ATerm term, pOFP_Traverse CaseSelector)
{
#ifdef DEBUG_PRINT
   printf("CaseSelector: %s\n", ATwriteToString(term));
#endif

 if (ATmatch(term, "CaseSelector_DEFAULT")) {

   // MATCHED CaseSelector_DEFAULT

   return ATtrue;
 }

 OFP_Traverse CaseValueRangeList;
 if (ATmatch(term, "CaseSelector_CVRL(<term>)", &CaseValueRangeList.term)) {

      if (ofp_traverse_CaseValueRangeList(CaseValueRangeList.term, &CaseValueRangeList)) {
         // MATCHED CaseValueRangeList
      } else return ATfalse;

   // MATCHED CaseSelector_CVRL

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_CaseValueRange(ATerm term, pOFP_Traverse CaseValueRange)
{
#ifdef DEBUG_PRINT
   printf("CaseValueRange: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse CaseValue, CaseValue1;
 if (ATmatch(term, "CaseValueRange_CVCV(<term>,<term>)", &CaseValue.term, &CaseValue1.term)) {

      if (ofp_traverse_CaseValue(CaseValue.term, &CaseValue)) {
         // MATCHED CaseValue
      } else return ATfalse;

      if (ofp_traverse_CaseValue(CaseValue1.term, &CaseValue1)) {
         // MATCHED CaseValue
      } else return ATfalse;

   // MATCHED CaseValueRange_CVCV

   return ATtrue;
 }

 OFP_Traverse CaseValue2;
 if (ATmatch(term, "CaseValueRange_CV(<term>)", &CaseValue2.term)) {

      if (ofp_traverse_CaseValue(CaseValue2.term, &CaseValue2)) {
         // MATCHED CaseValue
      } else return ATfalse;

   // MATCHED CaseValueRange_CV

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_CaseValueRangeList(ATerm term, pOFP_Traverse CaseValueRangeList)
{
#ifdef DEBUG_PRINT
   printf("CaseValueRangeList: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse CaseValueRange;
 if (ATmatch(term, "CaseValueRangeList(<term>)", &CaseValueRange.term)) {

   ATermList CaseValueRange_tail = (ATermList) ATmake("<term>", CaseValueRange.term);
   while (! ATisEmpty(CaseValueRange_tail)) {
      CaseValueRange.term = ATgetFirst(CaseValueRange_tail);
      CaseValueRange_tail = ATgetNext (CaseValueRange_tail);
      if (ofp_traverse_CaseValueRange(CaseValueRange.term, &CaseValueRange)) {
         // MATCHED CaseValueRange
      } else return ATfalse;
   }

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_CaseValue(ATerm term, pOFP_Traverse CaseValue)
{
#ifdef DEBUG_PRINT
   printf("CaseValue: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse ConstantExpr;
 if (ATmatch(term, "CaseValue(<term>)", &ConstantExpr.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ConstantExpr(ConstantExpr.term, &ConstantExpr)) {
         // MATCHED ConstantExpr
      } else return ATfalse;
#endif

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_SelectTypeStmt(ATerm term, pOFP_Traverse SelectTypeStmt)
{
#ifdef DEBUG_PRINT
   printf("SelectTypeStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse SelectConstructName, AssociateName, Selector, EOS;
 if (ATmatch(term, "SelectTypeStmt(<term>,<term>,<term>,<term>)", &SelectConstructName.term, &AssociateName.term, &Selector.term, &EOS.term)) {

   if (ATmatch(SelectConstructName.term, "Some(<term>)", &SelectConstructName.term)) {
   if (ATmatch(SelectConstructName.term, "(<term>)", &SelectConstructName.term)) {
      if (ofp_traverse_SelectConstructName(SelectConstructName.term, &SelectConstructName)) {
         // MATCHED SelectConstructName
      } else return ATfalse;
   }
   }

   if (ATmatch(AssociateName.term, "Some(<term>)", &AssociateName.term)) {
   if (ATmatch(AssociateName.term, "(<term>)", &AssociateName.term)) {
      if (ofp_traverse_AssociateName(AssociateName.term, &AssociateName)) {
         // MATCHED AssociateName
      } else return ATfalse;
   }
   }

      if (ofp_traverse_Selector(Selector.term, &Selector)) {
         // MATCHED Selector
      } else return ATfalse;

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_TypeGuardStmt(ATerm term, pOFP_Traverse TypeGuardStmt)
{
#ifdef DEBUG_PRINT
   printf("TypeGuardStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse SelectConstructName, EOS;
 if (ATmatch(term, "TypeGuardStmt_CLASS_DEF(<term>,<term>)", &SelectConstructName.term, &EOS.term)) {

   if (ATmatch(SelectConstructName.term, "Some(<term>)", &SelectConstructName.term)) {
      if (ofp_traverse_SelectConstructName(SelectConstructName.term, &SelectConstructName)) {
         // MATCHED SelectConstructName
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   // MATCHED TypeGuardStmt_CLASS_DEF

   return ATtrue;
 }

 OFP_Traverse DerivedTypeSpec, SelectConstructName1, EOS1;
 if (ATmatch(term, "TypeGuardStmt_CLASS(<term>,<term>,<term>)", &DerivedTypeSpec.term, &SelectConstructName1.term, &EOS1.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DerivedTypeSpec(DerivedTypeSpec.term, &DerivedTypeSpec)) {
         // MATCHED DerivedTypeSpec
      } else return ATfalse;
#endif

   if (ATmatch(SelectConstructName1.term, "Some(<term>)", &SelectConstructName1.term)) {
      if (ofp_traverse_SelectConstructName(SelectConstructName1.term, &SelectConstructName1)) {
         // MATCHED SelectConstructName
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS1.term, &EOS1)) {
         // MATCHED EOS
      } else return ATfalse;

   // MATCHED TypeGuardStmt_CLASS

   return ATtrue;
 }

 OFP_Traverse TypeSpec, SelectConstructName2, EOS2;
 if (ATmatch(term, "TypeGuardStmt_TYPE(<term>,<term>,<term>)", &TypeSpec.term, &SelectConstructName2.term, &EOS2.term)) {

#ifdef NOT_YET
      if (ofp_traverse_TypeSpec(TypeSpec.term, &TypeSpec)) {
         // MATCHED TypeSpec
      } else return ATfalse;
#endif

   if (ATmatch(SelectConstructName2.term, "Some(<term>)", &SelectConstructName2.term)) {
      if (ofp_traverse_SelectConstructName(SelectConstructName2.term, &SelectConstructName2)) {
         // MATCHED SelectConstructName
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS2.term, &EOS2)) {
         // MATCHED EOS
      } else return ATfalse;

   // MATCHED TypeGuardStmt_TYPE

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_EndSelectTypeStmt(ATerm term, pOFP_Traverse EndSelectTypeStmt)
{
#ifdef DEBUG_PRINT
   printf("EndSelectTypeStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse SelectConstructName, EOS;
 if (ATmatch(term, "EndSelectTypeStmt(<term>,<term>)", &SelectConstructName.term, &EOS.term)) {

   if (ATmatch(SelectConstructName.term, "Some(<term>)", &SelectConstructName.term)) {
      if (ofp_traverse_SelectConstructName(SelectConstructName.term, &SelectConstructName)) {
         // MATCHED SelectConstructName
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ExitStmt(ATerm term, pOFP_Traverse ExitStmt)
{
#ifdef DEBUG_PRINT
   printf("ExitStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, ConstructName, EOS;
 if (ATmatch(term, "ExitStmt(<term>,<term>,<term>)", &Label.term, &ConstructName.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

   if (ATmatch(ConstructName.term, "Some(<term>)", &ConstructName.term)) {
      if (ofp_traverse_ConstructName(ConstructName.term, &ConstructName)) {
         // MATCHED ConstructName
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_GotoStmt(ATerm term, pOFP_Traverse GotoStmt)
{
#ifdef DEBUG_PRINT
   printf("GotoStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, LblRef, EOS;
 if (ATmatch(term, "GotoStmt(<term>,<term>,<term>)", &Label.term, &LblRef.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

#ifdef NOT_YET
      if (ofp_traverse_LblRef(LblRef.term, &LblRef)) {
         // MATCHED LblRef
      } else return ATfalse;
#endif

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ComputedGotoStmt(ATerm term, pOFP_Traverse ComputedGotoStmt)
{
#ifdef DEBUG_PRINT
   printf("ComputedGotoStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, LabelList, Expr, EOS;
 if (ATmatch(term, "ComputedGotoStmt(<term>,<term>,<term>,<term>)", &Label.term, &LabelList.term, &Expr.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_LabelList(LabelList.term, &LabelList)) {
         // MATCHED LabelList
      } else return ATfalse;

      if (ofp_traverse_Expr(Expr.term, &Expr)) {
         // MATCHED Expr
      } else return ATfalse;

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ArithmeticIfStmt(ATerm term, pOFP_Traverse ArithmeticIfStmt)
{
#ifdef DEBUG_PRINT
   printf("ArithmeticIfStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, Expr, LblRef, LblRef1, LblRef2, EOS;
 if (ATmatch(term, "ArithmeticIfStmt(<term>,<term>,<term>,<term>,<term>,<term>)", &Label.term, &Expr.term, &LblRef.term, &LblRef1.term, &LblRef2.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_Expr(Expr.term, &Expr)) {
         // MATCHED Expr
      } else return ATfalse;

#ifdef NOT_YET
      if (ofp_traverse_LblRef(LblRef.term, &LblRef)) {
         // MATCHED LblRef
      } else return ATfalse;
#endif

#ifdef NOT_YET
      if (ofp_traverse_LblRef(LblRef1.term, &LblRef1)) {
         // MATCHED LblRef
      } else return ATfalse;
#endif

#ifdef NOT_YET
      if (ofp_traverse_LblRef(LblRef2.term, &LblRef2)) {
         // MATCHED LblRef
      } else return ATfalse;
#endif

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ContinueStmt(ATerm term, pOFP_Traverse ContinueStmt)
{
#ifdef DEBUG_PRINT
   printf("ContinueStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, EOS;
 if (ATmatch(term, "ContinueStmt(<term>,<term>)", &Label.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R901 io-unit
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_IoUnit(ATerm term, pOFP_Traverse IoUnit)
{
#ifdef DEBUG_PRINT
   printf("IoUnit: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse CharVariable;
 if (ATmatch(term, "IoUnit_IFV(<term>)", &CharVariable.term)) {

      if (ofp_traverse_CharVariable(CharVariable.term, &CharVariable)) {
         // MATCHED CharVariable
      } else return ATfalse;

   // MATCHED IoUnit_IFV

   return ATtrue;
 }

 if (ATmatch(term, "IoUnit_STAR")) {

   // MATCHED IoUnit_STAR

   return ATtrue;
 }

 OFP_Traverse IntExpr;
 if (ATmatch(term, "IoUnit_FUN(<term>)", &IntExpr.term)) {

#ifdef NOT_YET
      if (ofp_traverse_IntExpr(IntExpr.term, &IntExpr)) {
         // MATCHED IntExpr
      } else return ATfalse;
#endif

   // MATCHED IoUnit_FUN

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R902 file-unit-number
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_FileUnitNumber(ATerm term, pOFP_Traverse FileUnitNumber)
{
#ifdef DEBUG_PRINT
   printf("FileUnitNumber: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse IntExpr;
 if (ATmatch(term, "FileUnitNumber(<term>)", &IntExpr.term)) {

#ifdef NOT_YET
      if (ofp_traverse_IntExpr(IntExpr.term, &IntExpr)) {
         // MATCHED IntExpr
      } else return ATfalse;
#endif

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R903 internal-file-variable
//----------------------------------------------------------------------------------------

//========================================================================================
// R904 open-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_OpenStmt(ATerm term, pOFP_Traverse OpenStmt)
{
#ifdef DEBUG_PRINT
   printf("OpenStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, ConnectSpecList, EOS;
 if (ATmatch(term, "OpenStmt(<term>,<term>,<term>)", &Label.term, &ConnectSpecList.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_ConnectSpecList(ConnectSpecList.term, &ConnectSpecList)) {
         // MATCHED ConnectSpecList
      } else return ATfalse;

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R905 connect-spec
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_ConnectSpec(ATerm term, pOFP_Traverse ConnectSpec)
{
#ifdef DEBUG_PRINT
   printf("ConnectSpec: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse DefaultCharExpr;
 if (ATmatch(term, "ConnectSpec_STATUS(<term>)", &DefaultCharExpr.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr.term, &DefaultCharExpr)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED ConnectSpec_STATUS

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr1;
 if (ATmatch(term, "ConnectSpec_SIGN(<term>)", &DefaultCharExpr1.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr1.term, &DefaultCharExpr1)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED ConnectSpec_SIGN

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr2;
 if (ATmatch(term, "ConnectSpec_ROUND(<term>)", &DefaultCharExpr2.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr2.term, &DefaultCharExpr2)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED ConnectSpec_ROUND

   return ATtrue;
 }

 OFP_Traverse IntExpr;
 if (ATmatch(term, "ConnectSpec_RECL(<term>)", &IntExpr.term)) {

#ifdef NOT_YET
      if (ofp_traverse_IntExpr(IntExpr.term, &IntExpr)) {
         // MATCHED IntExpr
      } else return ATfalse;
#endif

   // MATCHED ConnectSpec_RECL

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr3;
 if (ATmatch(term, "ConnectSpec_POSITION(<term>)", &DefaultCharExpr3.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr3.term, &DefaultCharExpr3)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED ConnectSpec_POSITION

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr4;
 if (ATmatch(term, "ConnectSpec_PAD(<term>)", &DefaultCharExpr4.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr4.term, &DefaultCharExpr4)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED ConnectSpec_PAD

   return ATtrue;
 }

 OFP_Traverse IntVariable;
 if (ATmatch(term, "ConnectSpec_NEWUNIT(<term>)", &IntVariable.term)) {

      if (ofp_traverse_IntVariable(IntVariable.term, &IntVariable)) {
         // MATCHED IntVariable
      } else return ATfalse;

   // MATCHED ConnectSpec_NEWUNIT

   return ATtrue;
 }

 OFP_Traverse IntVariable1;
 if (ATmatch(term, "ConnectSpec_IOSTAT(<term>)", &IntVariable1.term)) {

      if (ofp_traverse_IntVariable(IntVariable1.term, &IntVariable1)) {
         // MATCHED IntVariable
      } else return ATfalse;

   // MATCHED ConnectSpec_IOSTAT

   return ATtrue;
 }

 OFP_Traverse IomsgVariable;
 if (ATmatch(term, "ConnectSpec_IOMSG(<term>)", &IomsgVariable.term)) {

      if (ofp_traverse_IomsgVariable(IomsgVariable.term, &IomsgVariable)) {
         // MATCHED IomsgVariable
      } else return ATfalse;

   // MATCHED ConnectSpec_IOMSG

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr5;
 if (ATmatch(term, "ConnectSpec_FORM(<term>)", &DefaultCharExpr5.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr5.term, &DefaultCharExpr5)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED ConnectSpec_FORM

   return ATtrue;
 }

 OFP_Traverse FileNameExpr;
 if (ATmatch(term, "ConnectSpec_FILE(<term>)", &FileNameExpr.term)) {

      if (ofp_traverse_FileNameExpr(FileNameExpr.term, &FileNameExpr)) {
         // MATCHED FileNameExpr
      } else return ATfalse;

   // MATCHED ConnectSpec_FILE

   return ATtrue;
 }

 OFP_Traverse LblRef;
 if (ATmatch(term, "ConnectSpec_ERR(<term>)", &LblRef.term)) {

#ifdef NOT_YET
      if (ofp_traverse_LblRef(LblRef.term, &LblRef)) {
         // MATCHED LblRef
      } else return ATfalse;
#endif

   // MATCHED ConnectSpec_ERR

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr6;
 if (ATmatch(term, "ConnectSpec_ENCODING(<term>)", &DefaultCharExpr6.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr6.term, &DefaultCharExpr6)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED ConnectSpec_ENCODING

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr7;
 if (ATmatch(term, "ConnectSpec_DELIM(<term>)", &DefaultCharExpr7.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr7.term, &DefaultCharExpr7)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED ConnectSpec_DELIM

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr8;
 if (ATmatch(term, "ConnectSpec_DECIMAL(<term>)", &DefaultCharExpr8.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr8.term, &DefaultCharExpr8)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED ConnectSpec_DECIMAL

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr9;
 if (ATmatch(term, "ConnectSpec_BLANK(<term>)", &DefaultCharExpr9.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr9.term, &DefaultCharExpr9)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED ConnectSpec_BLANK

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr10;
 if (ATmatch(term, "ConnectSpec_ASYNCHRONOUS(<term>)", &DefaultCharExpr10.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr10.term, &DefaultCharExpr10)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED ConnectSpec_ASYNCHRONOUS

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr11;
 if (ATmatch(term, "ConnectSpec_ACTION(<term>)", &DefaultCharExpr11.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr11.term, &DefaultCharExpr11)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED ConnectSpec_ACTION

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr12;
 if (ATmatch(term, "ConnectSpec_ACCESS(<term>)", &DefaultCharExpr12.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr12.term, &DefaultCharExpr12)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED ConnectSpec_ACCESS

   return ATtrue;
 }

 OFP_Traverse FileUnitNumber;
 if (ATmatch(term, "ConnectSpec_UNIT(<term>)", &FileUnitNumber.term)) {

      if (ofp_traverse_FileUnitNumber(FileUnitNumber.term, &FileUnitNumber)) {
         // MATCHED FileUnitNumber
      } else return ATfalse;

   // MATCHED ConnectSpec_UNIT

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ConnectSpecList(ATerm term, pOFP_Traverse ConnectSpecList)
{
#ifdef DEBUG_PRINT
   printf("ConnectSpecList: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse ConnectSpec;
 if (ATmatch(term, "ConnectSpecList(<term>)", &ConnectSpec.term)) {

   ATermList ConnectSpec_tail = (ATermList) ATmake("<term>", ConnectSpec.term);
   while (! ATisEmpty(ConnectSpec_tail)) {
      ConnectSpec.term = ATgetFirst(ConnectSpec_tail);
      ConnectSpec_tail = ATgetNext (ConnectSpec_tail);
      if (ofp_traverse_ConnectSpec(ConnectSpec.term, &ConnectSpec)) {
         // MATCHED ConnectSpec
      } else return ATfalse;
   }

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R906 file-name-expr
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_FileNameExpr(ATerm term, pOFP_Traverse FileNameExpr)
{
#ifdef DEBUG_PRINT
   printf("FileNameExpr: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse DefaultCharExpr;
 if (ATmatch(term, "FileNameExpr(<term>)", &DefaultCharExpr.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr.term, &DefaultCharExpr)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R907 io-msg-variable
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_IomsgVariable(ATerm term, pOFP_Traverse IomsgVariable)
{
#ifdef DEBUG_PRINT
   printf("IomsgVariable: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse DefaultCharExpr;
 if (ATmatch(term, "IomsgVariable(<term>)", &DefaultCharExpr.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr.term, &DefaultCharExpr)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R908 close-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_CloseStmt(ATerm term, pOFP_Traverse CloseStmt)
{
#ifdef DEBUG_PRINT
   printf("CloseStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, CloseSpecList, EOS;
 if (ATmatch(term, "CloseStmt(<term>,<term>,<term>)", &Label.term, &CloseSpecList.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_CloseSpecList(CloseSpecList.term, &CloseSpecList)) {
         // MATCHED CloseSpecList
      } else return ATfalse;

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R909 close-spec
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_CloseSpec(ATerm term, pOFP_Traverse CloseSpec)
{
#ifdef DEBUG_PRINT
   printf("CloseSpec: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse DefaultCharExpr;
 if (ATmatch(term, "CloseSpec_STATUS(<term>)", &DefaultCharExpr.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr.term, &DefaultCharExpr)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED CloseSpec_STATUS

   return ATtrue;
 }

 OFP_Traverse LblRef;
 if (ATmatch(term, "CloseSpec_ERR(<term>)", &LblRef.term)) {

#ifdef NOT_YET
      if (ofp_traverse_LblRef(LblRef.term, &LblRef)) {
         // MATCHED LblRef
      } else return ATfalse;
#endif

   // MATCHED CloseSpec_ERR

   return ATtrue;
 }

 OFP_Traverse IomsgVariable;
 if (ATmatch(term, "CloseSpec_IOMSG(<term>)", &IomsgVariable.term)) {

      if (ofp_traverse_IomsgVariable(IomsgVariable.term, &IomsgVariable)) {
         // MATCHED IomsgVariable
      } else return ATfalse;

   // MATCHED CloseSpec_IOMSG

   return ATtrue;
 }

 OFP_Traverse IntVariable;
 if (ATmatch(term, "CloseSpec_IOSTAT(<term>)", &IntVariable.term)) {

      if (ofp_traverse_IntVariable(IntVariable.term, &IntVariable)) {
         // MATCHED IntVariable
      } else return ATfalse;

   // MATCHED CloseSpec_IOSTAT

   return ATtrue;
 }

 OFP_Traverse FileUnitNumber;
 if (ATmatch(term, "CloseSpec_UNIT(<term>)", &FileUnitNumber.term)) {

      if (ofp_traverse_FileUnitNumber(FileUnitNumber.term, &FileUnitNumber)) {
         // MATCHED FileUnitNumber
      } else return ATfalse;

   // MATCHED CloseSpec_UNIT

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_CloseSpecList(ATerm term, pOFP_Traverse CloseSpecList)
{
#ifdef DEBUG_PRINT
   printf("CloseSpecList: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse CloseSpec;
 if (ATmatch(term, "CloseSpecList(<term>)", &CloseSpec.term)) {

   ATermList CloseSpec_tail = (ATermList) ATmake("<term>", CloseSpec.term);
   while (! ATisEmpty(CloseSpec_tail)) {
      CloseSpec.term = ATgetFirst(CloseSpec_tail);
      CloseSpec_tail = ATgetNext (CloseSpec_tail);
      if (ofp_traverse_CloseSpec(CloseSpec.term, &CloseSpec)) {
         // MATCHED CloseSpec
      } else return ATfalse;
   }

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R910 read-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_ReadStmt(ATerm term, pOFP_Traverse ReadStmt)
{
#ifdef DEBUG_PRINT
   printf("ReadStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, Format, InputItemList, EOS;
 if (ATmatch(term, "ReadStmt_F(<term>,<term>,<term>,<term>)", &Label.term, &Format.term, &InputItemList.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_Format(Format.term, &Format)) {
         // MATCHED Format
      } else return ATfalse;

   if (ATmatch(InputItemList.term, "Some(<term>)", &InputItemList.term)) {
   if (ATmatch(InputItemList.term, "(<term>)", &InputItemList.term)) {
      if (ofp_traverse_InputItemList(InputItemList.term, &InputItemList)) {
         // MATCHED InputItemList
      } else return ATfalse;
   }
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   // MATCHED ReadStmt_F

   return ATtrue;
 }

 OFP_Traverse Label1, IoControlSpecList, InputItemList1, EOS1;
 if (ATmatch(term, "ReadStmt_ICSL(<term>,<term>,<term>,<term>)", &Label1.term, &IoControlSpecList.term, &InputItemList1.term, &EOS1.term)) {

   if (ATmatch(Label1.term, "Some(<term>)", &Label1.term)) {
      if (ofp_traverse_Label(Label1.term, &Label1)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_IoControlSpecList(IoControlSpecList.term, &IoControlSpecList)) {
         // MATCHED IoControlSpecList
      } else return ATfalse;

   if (ATmatch(InputItemList1.term, "Some(<term>)", &InputItemList1.term)) {
      if (ofp_traverse_InputItemList(InputItemList1.term, &InputItemList1)) {
         // MATCHED InputItemList
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS1.term, &EOS1)) {
         // MATCHED EOS
      } else return ATfalse;

   // MATCHED ReadStmt_ICSL

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R911 write-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_WriteStmt(ATerm term, pOFP_Traverse WriteStmt)
{
#ifdef DEBUG_PRINT
   printf("WriteStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, IoControlSpecList, OutputItemList, EOS;
 if (ATmatch(term, "WriteStmt(<term>,<term>,<term>,<term>)", &Label.term, &IoControlSpecList.term, &OutputItemList.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_IoControlSpecList(IoControlSpecList.term, &IoControlSpecList)) {
         // MATCHED IoControlSpecList
      } else return ATfalse;

   if (ATmatch(OutputItemList.term, "Some(<term>)", &OutputItemList.term)) {
      if (ofp_traverse_OutputItemList(OutputItemList.term, &OutputItemList)) {
         // MATCHED OutputItemList
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R912 print-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_PrintStmt(ATerm term, pOFP_Traverse PrintStmt)
{
#ifdef DEBUG_PRINT
   printf("PrintStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, Format, OutputItemList, EOS;
 if (ATmatch(term, "PrintStmt(<term>,<term>,<term>,<term>)", &Label.term, &Format.term, &OutputItemList.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_Format(Format.term, &Format)) {
         // MATCHED Format
      } else return ATfalse;

   if (ATmatch(OutputItemList.term, "Some(<term>)", &OutputItemList.term)) {
   if (ATmatch(OutputItemList.term, "(<term>)", &OutputItemList.term)) {
      if (ofp_traverse_OutputItemList(OutputItemList.term, &OutputItemList)) {
         // MATCHED OutputItemList
      } else return ATfalse;
   }
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R913 io-control-spec
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_IoControlSpec(ATerm term, pOFP_Traverse IoControlSpec)
{
#ifdef DEBUG_PRINT
   printf("IoControlSpec: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse IntVariable;
 if (ATmatch(term, "IoControlSpec_SIZE(<term>)", &IntVariable.term)) {

      if (ofp_traverse_IntVariable(IntVariable.term, &IntVariable)) {
         // MATCHED IntVariable
      } else return ATfalse;

   // MATCHED IoControlSpec_SIZE

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr;
 if (ATmatch(term, "IoControlSpec_SIGN(<term>)", &DefaultCharExpr.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr.term, &DefaultCharExpr)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED IoControlSpec_SIGN

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr1;
 if (ATmatch(term, "IoControlSpec_ROUND(<term>)", &DefaultCharExpr1.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr1.term, &DefaultCharExpr1)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED IoControlSpec_ROUND

   return ATtrue;
 }

 OFP_Traverse Expr;
 if (ATmatch(term, "IoControlSpec_REC(<term>)", &Expr.term)) {

      if (ofp_traverse_Expr(Expr.term, &Expr)) {
         // MATCHED Expr
      } else return ATfalse;

   // MATCHED IoControlSpec_REC

   return ATtrue;
 }

 OFP_Traverse Expr1;
 if (ATmatch(term, "IoControlSpec_POS(<term>)", &Expr1.term)) {

      if (ofp_traverse_Expr(Expr1.term, &Expr1)) {
         // MATCHED Expr
      } else return ATfalse;

   // MATCHED IoControlSpec_POS

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr2;
 if (ATmatch(term, "IoControlSpec_PAD(<term>)", &DefaultCharExpr2.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr2.term, &DefaultCharExpr2)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED IoControlSpec_PAD

   return ATtrue;
 }

 OFP_Traverse IntVariable1;
 if (ATmatch(term, "IoControlSpec_IOSTAT(<term>)", &IntVariable1.term)) {

      if (ofp_traverse_IntVariable(IntVariable1.term, &IntVariable1)) {
         // MATCHED IntVariable
      } else return ATfalse;

   // MATCHED IoControlSpec_IOSTAT

   return ATtrue;
 }

 OFP_Traverse IomsgVariable;
 if (ATmatch(term, "IoControlSpec_IOMSG(<term>)", &IomsgVariable.term)) {

      if (ofp_traverse_IomsgVariable(IomsgVariable.term, &IomsgVariable)) {
         // MATCHED IomsgVariable
      } else return ATfalse;

   // MATCHED IoControlSpec_IOMSG

   return ATtrue;
 }

 OFP_Traverse IdVariable;
 if (ATmatch(term, "IoControlSpec_ID(<term>)", &IdVariable.term)) {

      if (ofp_traverse_IdVariable(IdVariable.term, &IdVariable)) {
         // MATCHED IdVariable
      } else return ATfalse;

   // MATCHED IoControlSpec_ID

   return ATtrue;
 }

 OFP_Traverse LblRef;
 if (ATmatch(term, "IoControlSpec_ERR(<term>)", &LblRef.term)) {

#ifdef NOT_YET
      if (ofp_traverse_LblRef(LblRef.term, &LblRef)) {
         // MATCHED LblRef
      } else return ATfalse;
#endif

   // MATCHED IoControlSpec_ERR

   return ATtrue;
 }

 OFP_Traverse LblRef1;
 if (ATmatch(term, "IoControlSpec_EOR(<term>)", &LblRef1.term)) {

#ifdef NOT_YET
      if (ofp_traverse_LblRef(LblRef1.term, &LblRef1)) {
         // MATCHED LblRef
      } else return ATfalse;
#endif

   // MATCHED IoControlSpec_EOR

   return ATtrue;
 }

 OFP_Traverse LblRef2;
 if (ATmatch(term, "IoControlSpec_END(<term>)", &LblRef2.term)) {

#ifdef NOT_YET
      if (ofp_traverse_LblRef(LblRef2.term, &LblRef2)) {
         // MATCHED LblRef
      } else return ATfalse;
#endif

   // MATCHED IoControlSpec_END

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr3;
 if (ATmatch(term, "IoControlSpec_DELIM(<term>)", &DefaultCharExpr3.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr3.term, &DefaultCharExpr3)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED IoControlSpec_DELIM

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr4;
 if (ATmatch(term, "IoControlSpec_DECIMAL(<term>)", &DefaultCharExpr4.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr4.term, &DefaultCharExpr4)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED IoControlSpec_DECIMAL

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr5;
 if (ATmatch(term, "IoControlSpec_BLANK(<term>)", &DefaultCharExpr5.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr5.term, &DefaultCharExpr5)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED IoControlSpec_BLANK

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr6;
 if (ATmatch(term, "IoControlSpec_ASYNCHRONOUS(<term>)", &DefaultCharExpr6.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr6.term, &DefaultCharExpr6)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED IoControlSpec_ASYNCHRONOUS

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr7;
 if (ATmatch(term, "IoControlSpec_ADVANCE(<term>)", &DefaultCharExpr7.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr7.term, &DefaultCharExpr7)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED IoControlSpec_ADVANCE

   return ATtrue;
 }

 OFP_Traverse NamelistGroupName;
 if (ATmatch(term, "IoControlSpec_NML(<term>)", &NamelistGroupName.term)) {

      if (ofp_traverse_NamelistGroupName(NamelistGroupName.term, &NamelistGroupName)) {
         // MATCHED NamelistGroupName
      } else return ATfalse;

   // MATCHED IoControlSpec_NML

   return ATtrue;
 }

 OFP_Traverse Format;
 if (ATmatch(term, "IoControlSpec_FMT(<term>)", &Format.term)) {

      if (ofp_traverse_Format(Format.term, &Format)) {
         // MATCHED Format
      } else return ATfalse;

   // MATCHED IoControlSpec_FMT

   return ATtrue;
 }

 OFP_Traverse IoUnit;
 if (ATmatch(term, "IoControlSpec_UNIT(<term>)", &IoUnit.term)) {

      if (ofp_traverse_IoUnit(IoUnit.term, &IoUnit)) {
         // MATCHED IoUnit
      } else return ATfalse;

   // MATCHED IoControlSpec_UNIT

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_IoControlSpecList(ATerm term, pOFP_Traverse IoControlSpecList)
{
#ifdef DEBUG_PRINT
   printf("IoControlSpecList: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse IoControlSpec;
 if (ATmatch(term, "IoControlSpecList(<term>)", &IoControlSpec.term)) {

   ATermList IoControlSpec_tail = (ATermList) ATmake("<term>", IoControlSpec.term);
   while (! ATisEmpty(IoControlSpec_tail)) {
      IoControlSpec.term = ATgetFirst(IoControlSpec_tail);
      IoControlSpec_tail = ATgetNext (IoControlSpec_tail);
      if (ofp_traverse_IoControlSpec(IoControlSpec.term, &IoControlSpec)) {
         // MATCHED IoControlSpec
      } else return ATfalse;
   }

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R914 id-variable
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_IdVariable(ATerm term, pOFP_Traverse IdVariable)
{
#ifdef DEBUG_PRINT
   printf("IdVariable: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse IntVariable;
 if (ATmatch(term, "IdVariable(<term>)", &IntVariable.term)) {

      if (ofp_traverse_IntVariable(IntVariable.term, &IntVariable)) {
         // MATCHED IntVariable
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R915 format
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_Format(ATerm term, pOFP_Traverse Format)
{
#ifdef DEBUG_PRINT
   printf("Format: %s\n", ATwriteToString(term));
#endif

 if (ATmatch(term, "Format_STAR")) {

   // MATCHED Format_STAR

   return ATtrue;
 }

 OFP_Traverse Label;
 if (ATmatch(term, "Format_L(<term>)", &Label.term)) {

      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;

   // MATCHED Format_L

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr;
 if (ATmatch(term, "Format_DCE(<term>)", &DefaultCharExpr.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr.term, &DefaultCharExpr)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED Format_DCE

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R916 input-item
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_InputItem(ATerm term, pOFP_Traverse InputItem)
{
#ifdef DEBUG_PRINT
   printf("InputItem: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse IoImpliedDo;
 if (ATmatch(term, "InputItem_IID(<term>)", &IoImpliedDo.term)) {

      if (ofp_traverse_IoImpliedDo(IoImpliedDo.term, &IoImpliedDo)) {
         // MATCHED IoImpliedDo
      } else return ATfalse;

   // MATCHED InputItem_IID

   return ATtrue;
 }

 OFP_Traverse Variable;
 if (ATmatch(term, "InputItem_V(<term>)", &Variable.term)) {

      if (ofp_traverse_Variable(Variable.term, &Variable)) {
         // MATCHED Variable
      } else return ATfalse;

   // MATCHED InputItem_V

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_InputItemList(ATerm term, pOFP_Traverse InputItemList)
{
#ifdef DEBUG_PRINT
   printf("InputItemList: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse InputItem;
 if (ATmatch(term, "InputItemList(<term>)", &InputItem.term)) {

   ATermList InputItem_tail = (ATermList) ATmake("<term>", InputItem.term);
   while (! ATisEmpty(InputItem_tail)) {
      InputItem.term = ATgetFirst(InputItem_tail);
      InputItem_tail = ATgetNext (InputItem_tail);
      if (ofp_traverse_InputItem(InputItem.term, &InputItem)) {
         // MATCHED InputItem
      } else return ATfalse;
   }

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R917 output-item
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_OutputItem(ATerm term, pOFP_Traverse OutputItem)
{
#ifdef DEBUG_PRINT
   printf("OutputItem: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse IoImpliedDo;
 if (ATmatch(term, "OutputItem_IID(<term>)", &IoImpliedDo.term)) {

      if (ofp_traverse_IoImpliedDo(IoImpliedDo.term, &IoImpliedDo)) {
         // MATCHED IoImpliedDo
      } else return ATfalse;

   // MATCHED OutputItem_IID

   return ATtrue;
 }

 OFP_Traverse Expr;
 if (ATmatch(term, "OutputItem_E(<term>)", &Expr.term)) {

      if (ofp_traverse_Expr(Expr.term, &Expr)) {
         // MATCHED Expr
      } else return ATfalse;

   // MATCHED OutputItem_E

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_OutputItemList(ATerm term, pOFP_Traverse OutputItemList)
{
#ifdef DEBUG_PRINT
   printf("OutputItemList: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse OutputItem;
 if (ATmatch(term, "OutputItemList(<term>)", &OutputItem.term)) {

   ATermList OutputItem_tail = (ATermList) ATmake("<term>", OutputItem.term);
   while (! ATisEmpty(OutputItem_tail)) {
      OutputItem.term = ATgetFirst(OutputItem_tail);
      OutputItem_tail = ATgetNext (OutputItem_tail);
      if (ofp_traverse_OutputItem(OutputItem.term, &OutputItem)) {
         // MATCHED OutputItem
      } else return ATfalse;
   }

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R918 io-implied-do
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_IoImpliedDo(ATerm term, pOFP_Traverse IoImpliedDo)
{
#ifdef DEBUG_PRINT
   printf("IoImpliedDo: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse IoImpliedDoObjectList, IoImpliedDoControl;
 if (ATmatch(term, "IoImpliedDo(<term>,<term>)", &IoImpliedDoObjectList.term, &IoImpliedDoControl.term)) {

      if (ofp_traverse_IoImpliedDoObjectList(IoImpliedDoObjectList.term, &IoImpliedDoObjectList)) {
         // MATCHED IoImpliedDoObjectList
      } else return ATfalse;

      if (ofp_traverse_IoImpliedDoControl(IoImpliedDoControl.term, &IoImpliedDoControl)) {
         // MATCHED IoImpliedDoControl
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R919 io-implied-do-object
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_IoImpliedDoObject(ATerm term, pOFP_Traverse IoImpliedDoObject)
{
#ifdef DEBUG_PRINT
   printf("IoImpliedDoObject: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse OutputItem;
 if (ATmatch(term, "IoImpliedDoObject_OI(<term>)", &OutputItem.term)) {

      if (ofp_traverse_OutputItem(OutputItem.term, &OutputItem)) {
         // MATCHED OutputItem
      } else return ATfalse;

   // MATCHED IoImpliedDoObject_OI

   return ATtrue;
 }

 OFP_Traverse InputItem;
 if (ATmatch(term, "IoImpliedDoObject_II(<term>)", &InputItem.term)) {

      if (ofp_traverse_InputItem(InputItem.term, &InputItem)) {
         // MATCHED InputItem
      } else return ATfalse;

   // MATCHED IoImpliedDoObject_II

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_IoImpliedDoObjectList(ATerm term, pOFP_Traverse IoImpliedDoObjectList)
{
#ifdef DEBUG_PRINT
   printf("IoImpliedDoObjectList: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse IoImpliedDoObject;
 if (ATmatch(term, "IoImpliedDoObjectList(<term>)", &IoImpliedDoObject.term)) {

   ATermList IoImpliedDoObject_tail = (ATermList) ATmake("<term>", IoImpliedDoObject.term);
   while (! ATisEmpty(IoImpliedDoObject_tail)) {
      IoImpliedDoObject.term = ATgetFirst(IoImpliedDoObject_tail);
      IoImpliedDoObject_tail = ATgetNext (IoImpliedDoObject_tail);
      if (ofp_traverse_IoImpliedDoObject(IoImpliedDoObject.term, &IoImpliedDoObject)) {
         // MATCHED IoImpliedDoObject
      } else return ATfalse;
   }

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R920 io-implied-do-control
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_IoImpliedDoControl(ATerm term, pOFP_Traverse IoImpliedDoControl)
{
#ifdef DEBUG_PRINT
   printf("IoImpliedDoControl: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse DoVariable, IntExpr, IntExpr1, IntExpr2;
 if (ATmatch(term, "IoImpliedDoControl(<term>,<term>,<term>,<term>)", &DoVariable.term, &IntExpr.term, &IntExpr1.term, &IntExpr2.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DoVariable(DoVariable.term, &DoVariable)) {
         // MATCHED DoVariable
      } else return ATfalse;
#endif

#ifdef NOT_YET
      if (ofp_traverse_IntExpr(IntExpr.term, &IntExpr)) {
         // MATCHED IntExpr
      } else return ATfalse;
#endif

#ifdef NOT_YET
      if (ofp_traverse_IntExpr(IntExpr1.term, &IntExpr1)) {
         // MATCHED IntExpr
      } else return ATfalse;
#endif

   if (ATmatch(IntExpr2.term, "Some(<term>)", &IntExpr2.term)) {
   if (ATmatch(IntExpr2.term, "(<term>)", &IntExpr2.term)) {
#ifdef NOT_YET
      if (ofp_traverse_IntExpr(IntExpr2.term, &IntExpr2)) {
         // MATCHED IntExpr
      } else return ATfalse;
#endif
   }
   }

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_WaitStmt(ATerm term, pOFP_Traverse WaitStmt)
{
#ifdef DEBUG_PRINT
   printf("WaitStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, WaitSpecList, EOS;
 if (ATmatch(term, "WaitStmt(<term>,<term>,<term>)", &Label.term, &WaitSpecList.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_WaitSpecList(WaitSpecList.term, &WaitSpecList)) {
         // MATCHED WaitSpecList
      } else return ATfalse;

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_WaitSpec(ATerm term, pOFP_Traverse WaitSpec)
{
#ifdef DEBUG_PRINT
   printf("WaitSpec: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse IntExpr;
 if (ATmatch(term, "WaitSpec_IOSTAT(<term>)", &IntExpr.term)) {

#ifdef NOT_YET
      if (ofp_traverse_IntExpr(IntExpr.term, &IntExpr)) {
         // MATCHED IntExpr
      } else return ATfalse;
#endif

   // MATCHED WaitSpec_IOSTAT

   return ATtrue;
 }

 OFP_Traverse IomsgVariable;
 if (ATmatch(term, "WaitSpec_IOMSG(<term>)", &IomsgVariable.term)) {

      if (ofp_traverse_IomsgVariable(IomsgVariable.term, &IomsgVariable)) {
         // MATCHED IomsgVariable
      } else return ATfalse;

   // MATCHED WaitSpec_IOMSG

   return ATtrue;
 }

 OFP_Traverse IntExpr1;
 if (ATmatch(term, "WaitSpec_ID(<term>)", &IntExpr1.term)) {

#ifdef NOT_YET
      if (ofp_traverse_IntExpr(IntExpr1.term, &IntExpr1)) {
         // MATCHED IntExpr
      } else return ATfalse;
#endif

   // MATCHED WaitSpec_ID

   return ATtrue;
 }

 OFP_Traverse LblRef;
 if (ATmatch(term, "WaitSpec_ERR(<term>)", &LblRef.term)) {

#ifdef NOT_YET
      if (ofp_traverse_LblRef(LblRef.term, &LblRef)) {
         // MATCHED LblRef
      } else return ATfalse;
#endif

   // MATCHED WaitSpec_ERR

   return ATtrue;
 }

 OFP_Traverse LblRef1;
 if (ATmatch(term, "WaitSpec_EOR(<term>)", &LblRef1.term)) {

#ifdef NOT_YET
      if (ofp_traverse_LblRef(LblRef1.term, &LblRef1)) {
         // MATCHED LblRef
      } else return ATfalse;
#endif

   // MATCHED WaitSpec_EOR

   return ATtrue;
 }

 OFP_Traverse LblRef2;
 if (ATmatch(term, "WaitSpec_END(<term>)", &LblRef2.term)) {

#ifdef NOT_YET
      if (ofp_traverse_LblRef(LblRef2.term, &LblRef2)) {
         // MATCHED LblRef
      } else return ATfalse;
#endif

   // MATCHED WaitSpec_END

   return ATtrue;
 }

 OFP_Traverse FileUnitNumber;
 if (ATmatch(term, "WaitSpec_UNIT(<term>)", &FileUnitNumber.term)) {

      if (ofp_traverse_FileUnitNumber(FileUnitNumber.term, &FileUnitNumber)) {
         // MATCHED FileUnitNumber
      } else return ATfalse;

   // MATCHED WaitSpec_UNIT

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_WaitSpecList(ATerm term, pOFP_Traverse WaitSpecList)
{
#ifdef DEBUG_PRINT
   printf("WaitSpecList: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse WaitSpec;
 if (ATmatch(term, "WaitSpecList(<term>)", &WaitSpec.term)) {

   ATermList WaitSpec_tail = (ATermList) ATmake("<term>", WaitSpec.term);
   while (! ATisEmpty(WaitSpec_tail)) {
      WaitSpec.term = ATgetFirst(WaitSpec_tail);
      WaitSpec_tail = ATgetNext (WaitSpec_tail);
      if (ofp_traverse_WaitSpec(WaitSpec.term, &WaitSpec)) {
         // MATCHED WaitSpec
      } else return ATfalse;
   }

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_BackspaceStmt(ATerm term, pOFP_Traverse BackspaceStmt)
{
#ifdef DEBUG_PRINT
   printf("BackspaceStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, PositionSpecList, EOS;
 if (ATmatch(term, "BackspaceStmt_PSL(<term>,<term>,<term>)", &Label.term, &PositionSpecList.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_PositionSpecList(PositionSpecList.term, &PositionSpecList)) {
         // MATCHED PositionSpecList
      } else return ATfalse;

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   // MATCHED BackspaceStmt_PSL

   return ATtrue;
 }

 OFP_Traverse Label1, FileUnitNumber, EOS1;
 if (ATmatch(term, "BackspaceStmt_FUN(<term>,<term>,<term>)", &Label1.term, &FileUnitNumber.term, &EOS1.term)) {

   if (ATmatch(Label1.term, "Some(<term>)", &Label1.term)) {
      if (ofp_traverse_Label(Label1.term, &Label1)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_FileUnitNumber(FileUnitNumber.term, &FileUnitNumber)) {
         // MATCHED FileUnitNumber
      } else return ATfalse;

      if (ofp_traverse_EOS(EOS1.term, &EOS1)) {
         // MATCHED EOS
      } else return ATfalse;

   // MATCHED BackspaceStmt_FUN

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_EndfileStmt(ATerm term, pOFP_Traverse EndfileStmt)
{
#ifdef DEBUG_PRINT
   printf("EndfileStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, PositionSpecList, EOS;
 if (ATmatch(term, "EndfileStmt_PSL(<term>,<term>,<term>)", &Label.term, &PositionSpecList.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_PositionSpecList(PositionSpecList.term, &PositionSpecList)) {
         // MATCHED PositionSpecList
      } else return ATfalse;

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   // MATCHED EndfileStmt_PSL

   return ATtrue;
 }

 OFP_Traverse Label1, FileUnitNumber, EOS1;
 if (ATmatch(term, "EndfileStmt_FUN(<term>,<term>,<term>)", &Label1.term, &FileUnitNumber.term, &EOS1.term)) {

   if (ATmatch(Label1.term, "Some(<term>)", &Label1.term)) {
      if (ofp_traverse_Label(Label1.term, &Label1)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_FileUnitNumber(FileUnitNumber.term, &FileUnitNumber)) {
         // MATCHED FileUnitNumber
      } else return ATfalse;

      if (ofp_traverse_EOS(EOS1.term, &EOS1)) {
         // MATCHED EOS
      } else return ATfalse;

   // MATCHED EndfileStmt_FUN

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_RewindStmt(ATerm term, pOFP_Traverse RewindStmt)
{
#ifdef DEBUG_PRINT
   printf("RewindStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, PositionSpecList, EOS;
 if (ATmatch(term, "RewindStmt_PSL(<term>,<term>,<term>)", &Label.term, &PositionSpecList.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_PositionSpecList(PositionSpecList.term, &PositionSpecList)) {
         // MATCHED PositionSpecList
      } else return ATfalse;

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   // MATCHED RewindStmt_PSL

   return ATtrue;
 }

 OFP_Traverse Label1, FileUnitNumber, EOS1;
 if (ATmatch(term, "RewindStmt_FUN(<term>,<term>,<term>)", &Label1.term, &FileUnitNumber.term, &EOS1.term)) {

   if (ATmatch(Label1.term, "Some(<term>)", &Label1.term)) {
      if (ofp_traverse_Label(Label1.term, &Label1)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_FileUnitNumber(FileUnitNumber.term, &FileUnitNumber)) {
         // MATCHED FileUnitNumber
      } else return ATfalse;

      if (ofp_traverse_EOS(EOS1.term, &EOS1)) {
         // MATCHED EOS
      } else return ATfalse;

   // MATCHED RewindStmt_FUN

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_PositionSpec(ATerm term, pOFP_Traverse PositionSpec)
{
#ifdef DEBUG_PRINT
   printf("PositionSpec: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse LblRef;
 if (ATmatch(term, "PositionSpec_ERR(<term>)", &LblRef.term)) {

#ifdef NOT_YET
      if (ofp_traverse_LblRef(LblRef.term, &LblRef)) {
         // MATCHED LblRef
      } else return ATfalse;
#endif

   // MATCHED PositionSpec_ERR

   return ATtrue;
 }

 OFP_Traverse IomsgVariable;
 if (ATmatch(term, "PositionSpec_IOMSG(<term>)", &IomsgVariable.term)) {

      if (ofp_traverse_IomsgVariable(IomsgVariable.term, &IomsgVariable)) {
         // MATCHED IomsgVariable
      } else return ATfalse;

   // MATCHED PositionSpec_IOMSG

   return ATtrue;
 }

 OFP_Traverse IntVariable;
 if (ATmatch(term, "PositionSpec_IOSTAT(<term>)", &IntVariable.term)) {

      if (ofp_traverse_IntVariable(IntVariable.term, &IntVariable)) {
         // MATCHED IntVariable
      } else return ATfalse;

   // MATCHED PositionSpec_IOSTAT

   return ATtrue;
 }

 OFP_Traverse FileUnitNumber;
 if (ATmatch(term, "PositionSpec_UNIT(<term>)", &FileUnitNumber.term)) {

      if (ofp_traverse_FileUnitNumber(FileUnitNumber.term, &FileUnitNumber)) {
         // MATCHED FileUnitNumber
      } else return ATfalse;

   // MATCHED PositionSpec_UNIT

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_PositionSpecList(ATerm term, pOFP_Traverse PositionSpecList)
{
#ifdef DEBUG_PRINT
   printf("PositionSpecList: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse PositionSpec;
 if (ATmatch(term, "PositionSpecList(<term>)", &PositionSpec.term)) {

   ATermList PositionSpec_tail = (ATermList) ATmake("<term>", PositionSpec.term);
   while (! ATisEmpty(PositionSpec_tail)) {
      PositionSpec.term = ATgetFirst(PositionSpec_tail);
      PositionSpec_tail = ATgetNext (PositionSpec_tail);
      if (ofp_traverse_PositionSpec(PositionSpec.term, &PositionSpec)) {
         // MATCHED PositionSpec
      } else return ATfalse;
   }

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_FlushStmt(ATerm term, pOFP_Traverse FlushStmt)
{
#ifdef DEBUG_PRINT
   printf("FlushStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, FlushSpecList, EOS;
 if (ATmatch(term, "FlushStmt_FSL(<term>,<term>,<term>)", &Label.term, &FlushSpecList.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_FlushSpecList(FlushSpecList.term, &FlushSpecList)) {
         // MATCHED FlushSpecList
      } else return ATfalse;

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   // MATCHED FlushStmt_FSL

   return ATtrue;
 }

 OFP_Traverse Label1, FileUnitNumber, EOS1;
 if (ATmatch(term, "FlushStmt_FUN(<term>,<term>,<term>)", &Label1.term, &FileUnitNumber.term, &EOS1.term)) {

   if (ATmatch(Label1.term, "Some(<term>)", &Label1.term)) {
      if (ofp_traverse_Label(Label1.term, &Label1)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_FileUnitNumber(FileUnitNumber.term, &FileUnitNumber)) {
         // MATCHED FileUnitNumber
      } else return ATfalse;

      if (ofp_traverse_EOS(EOS1.term, &EOS1)) {
         // MATCHED EOS
      } else return ATfalse;

   // MATCHED FlushStmt_FUN

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_FlushSpec(ATerm term, pOFP_Traverse FlushSpec)
{
#ifdef DEBUG_PRINT
   printf("FlushSpec: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse LblRef;
 if (ATmatch(term, "FlushSpec_ERR(<term>)", &LblRef.term)) {

#ifdef NOT_YET
      if (ofp_traverse_LblRef(LblRef.term, &LblRef)) {
         // MATCHED LblRef
      } else return ATfalse;
#endif

   // MATCHED FlushSpec_ERR

   return ATtrue;
 }

 OFP_Traverse IomsgVariable;
 if (ATmatch(term, "FlushSpec_IOMSG(<term>)", &IomsgVariable.term)) {

      if (ofp_traverse_IomsgVariable(IomsgVariable.term, &IomsgVariable)) {
         // MATCHED IomsgVariable
      } else return ATfalse;

   // MATCHED FlushSpec_IOMSG

   return ATtrue;
 }

 OFP_Traverse IntVariable;
 if (ATmatch(term, "FlushSpec_IOSTAT(<term>)", &IntVariable.term)) {

      if (ofp_traverse_IntVariable(IntVariable.term, &IntVariable)) {
         // MATCHED IntVariable
      } else return ATfalse;

   // MATCHED FlushSpec_IOSTAT

   return ATtrue;
 }

 OFP_Traverse FileUnitNumber;
 if (ATmatch(term, "FlushSpec_UNIT(<term>)", &FileUnitNumber.term)) {

      if (ofp_traverse_FileUnitNumber(FileUnitNumber.term, &FileUnitNumber)) {
         // MATCHED FileUnitNumber
      } else return ATfalse;

   // MATCHED FlushSpec_UNIT

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_FlushSpecList(ATerm term, pOFP_Traverse FlushSpecList)
{
#ifdef DEBUG_PRINT
   printf("FlushSpecList: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse FlushSpec;
 if (ATmatch(term, "FlushSpecList(<term>)", &FlushSpec.term)) {

   ATermList FlushSpec_tail = (ATermList) ATmake("<term>", FlushSpec.term);
   while (! ATisEmpty(FlushSpec_tail)) {
      FlushSpec.term = ATgetFirst(FlushSpec_tail);
      FlushSpec_tail = ATgetNext (FlushSpec_tail);
      if (ofp_traverse_FlushSpec(FlushSpec.term, &FlushSpec)) {
         // MATCHED FlushSpec
      } else return ATfalse;
   }

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_InquireStmt(ATerm term, pOFP_Traverse InquireStmt)
{
#ifdef DEBUG_PRINT
   printf("InquireStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, IntVariable, OutputItemList, EOS;
 if (ATmatch(term, "InquireStmt_IV(<term>,<term>,<term>,<term>)", &Label.term, &IntVariable.term, &OutputItemList.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_IntVariable(IntVariable.term, &IntVariable)) {
         // MATCHED IntVariable
      } else return ATfalse;

      if (ofp_traverse_OutputItemList(OutputItemList.term, &OutputItemList)) {
         // MATCHED OutputItemList
      } else return ATfalse;

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   // MATCHED InquireStmt_IV

   return ATtrue;
 }

 OFP_Traverse Label1, InquireSpecList, EOS1;
 if (ATmatch(term, "InquireStmt_ISL(<term>,<term>,<term>)", &Label1.term, &InquireSpecList.term, &EOS1.term)) {

   if (ATmatch(Label1.term, "Some(<term>)", &Label1.term)) {
      if (ofp_traverse_Label(Label1.term, &Label1)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_InquireSpecList(InquireSpecList.term, &InquireSpecList)) {
         // MATCHED InquireSpecList
      } else return ATfalse;

      if (ofp_traverse_EOS(EOS1.term, &EOS1)) {
         // MATCHED EOS
      } else return ATfalse;

   // MATCHED InquireStmt_ISL

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_InquireSpec(ATerm term, pOFP_Traverse InquireSpec)
{
#ifdef DEBUG_PRINT
   printf("InquireSpec: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse DefaultCharExpr;
 if (ATmatch(term, "InquireSpec_WRITE(<term>)", &DefaultCharExpr.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr.term, &DefaultCharExpr)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED InquireSpec_WRITE

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr1;
 if (ATmatch(term, "InquireSpec_UNFORMATTED(<term>)", &DefaultCharExpr1.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr1.term, &DefaultCharExpr1)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED InquireSpec_UNFORMATTED

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr2;
 if (ATmatch(term, "InquireSpec_STREAM(<term>)", &DefaultCharExpr2.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr2.term, &DefaultCharExpr2)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED InquireSpec_STREAM

   return ATtrue;
 }

 OFP_Traverse IntVariable;
 if (ATmatch(term, "InquireSpec_SIZE(<term>)", &IntVariable.term)) {

      if (ofp_traverse_IntVariable(IntVariable.term, &IntVariable)) {
         // MATCHED IntVariable
      } else return ATfalse;

   // MATCHED InquireSpec_SIZE

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr3;
 if (ATmatch(term, "InquireSpec_SIGN(<term>)", &DefaultCharExpr3.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr3.term, &DefaultCharExpr3)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED InquireSpec_SIGN

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr4;
 if (ATmatch(term, "InquireSpec_SEQUENTIAL(<term>)", &DefaultCharExpr4.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr4.term, &DefaultCharExpr4)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED InquireSpec_SEQUENTIAL

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr5;
 if (ATmatch(term, "InquireSpec_ROUND(<term>)", &DefaultCharExpr5.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr5.term, &DefaultCharExpr5)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED InquireSpec_ROUND

   return ATtrue;
 }

 OFP_Traverse IntVariable1;
 if (ATmatch(term, "InquireSpec_RECL(<term>)", &IntVariable1.term)) {

      if (ofp_traverse_IntVariable(IntVariable1.term, &IntVariable1)) {
         // MATCHED IntVariable
      } else return ATfalse;

   // MATCHED InquireSpec_RECL

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr6;
 if (ATmatch(term, "InquireSpec_READWRITE(<term>)", &DefaultCharExpr6.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr6.term, &DefaultCharExpr6)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED InquireSpec_READWRITE

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr7;
 if (ATmatch(term, "InquireSpec_READ(<term>)", &DefaultCharExpr7.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr7.term, &DefaultCharExpr7)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED InquireSpec_READ

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr8;
 if (ATmatch(term, "InquireSpec_POSITION(<term>)", &DefaultCharExpr8.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr8.term, &DefaultCharExpr8)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED InquireSpec_POSITION

   return ATtrue;
 }

 OFP_Traverse IntVariable2;
 if (ATmatch(term, "InquireSpec_POS(<term>)", &IntVariable2.term)) {

      if (ofp_traverse_IntVariable(IntVariable2.term, &IntVariable2)) {
         // MATCHED IntVariable
      } else return ATfalse;

   // MATCHED InquireSpec_POS

   return ATtrue;
 }

 OFP_Traverse LogicalVariable;
 if (ATmatch(term, "InquireSpec_PENDING(<term>)", &LogicalVariable.term)) {

      if (ofp_traverse_LogicalVariable(LogicalVariable.term, &LogicalVariable)) {
         // MATCHED LogicalVariable
      } else return ATfalse;

   // MATCHED InquireSpec_PENDING

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr9;
 if (ATmatch(term, "InquireSpec_PAD(<term>)", &DefaultCharExpr9.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr9.term, &DefaultCharExpr9)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED InquireSpec_PAD

   return ATtrue;
 }

 OFP_Traverse LogicalVariable1;
 if (ATmatch(term, "InquireSpec_OPENED(<term>)", &LogicalVariable1.term)) {

      if (ofp_traverse_LogicalVariable(LogicalVariable1.term, &LogicalVariable1)) {
         // MATCHED LogicalVariable
      } else return ATfalse;

   // MATCHED InquireSpec_OPENED

   return ATtrue;
 }

 OFP_Traverse IntVariable3;
 if (ATmatch(term, "InquireSpec_NUMBER(<term>)", &IntVariable3.term)) {

      if (ofp_traverse_IntVariable(IntVariable3.term, &IntVariable3)) {
         // MATCHED IntVariable
      } else return ATfalse;

   // MATCHED InquireSpec_NUMBER

   return ATtrue;
 }

 OFP_Traverse IntVariable4;
 if (ATmatch(term, "InquireSpec_NEXTREC(<term>)", &IntVariable4.term)) {

      if (ofp_traverse_IntVariable(IntVariable4.term, &IntVariable4)) {
         // MATCHED IntVariable
      } else return ATfalse;

   // MATCHED InquireSpec_NEXTREC

   return ATtrue;
 }

 OFP_Traverse LogicalVariable2;
 if (ATmatch(term, "InquireSpec_NAMED(<term>)", &LogicalVariable2.term)) {

      if (ofp_traverse_LogicalVariable(LogicalVariable2.term, &LogicalVariable2)) {
         // MATCHED LogicalVariable
      } else return ATfalse;

   // MATCHED InquireSpec_NAMED

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr10;
 if (ATmatch(term, "InquireSpec_NAME(<term>)", &DefaultCharExpr10.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr10.term, &DefaultCharExpr10)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED InquireSpec_NAME

   return ATtrue;
 }

 OFP_Traverse IntVariable5;
 if (ATmatch(term, "InquireSpec_IOSTAT(<term>)", &IntVariable5.term)) {

      if (ofp_traverse_IntVariable(IntVariable5.term, &IntVariable5)) {
         // MATCHED IntVariable
      } else return ATfalse;

   // MATCHED InquireSpec_IOSTAT

   return ATtrue;
 }

 OFP_Traverse IomsgVariable;
 if (ATmatch(term, "InquireSpec_IOMSG(<term>)", &IomsgVariable.term)) {

      if (ofp_traverse_IomsgVariable(IomsgVariable.term, &IomsgVariable)) {
         // MATCHED IomsgVariable
      } else return ATfalse;

   // MATCHED InquireSpec_IOMSG

   return ATtrue;
 }

 OFP_Traverse IntExpr;
 if (ATmatch(term, "InquireSpec_ID(<term>)", &IntExpr.term)) {

#ifdef NOT_YET
      if (ofp_traverse_IntExpr(IntExpr.term, &IntExpr)) {
         // MATCHED IntExpr
      } else return ATfalse;
#endif

   // MATCHED InquireSpec_ID

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr11;
 if (ATmatch(term, "InquireSpec_FORMATTED(<term>)", &DefaultCharExpr11.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr11.term, &DefaultCharExpr11)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED InquireSpec_FORMATTED

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr12;
 if (ATmatch(term, "InquireSpec_FORM(<term>)", &DefaultCharExpr12.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr12.term, &DefaultCharExpr12)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED InquireSpec_FORM

   return ATtrue;
 }

 OFP_Traverse LogicalVariable3;
 if (ATmatch(term, "InquireSpec_EXIST(<term>)", &LogicalVariable3.term)) {

      if (ofp_traverse_LogicalVariable(LogicalVariable3.term, &LogicalVariable3)) {
         // MATCHED LogicalVariable
      } else return ATfalse;

   // MATCHED InquireSpec_EXIST

   return ATtrue;
 }

 OFP_Traverse LblRef;
 if (ATmatch(term, "InquireSpec_ERR(<term>)", &LblRef.term)) {

#ifdef NOT_YET
      if (ofp_traverse_LblRef(LblRef.term, &LblRef)) {
         // MATCHED LblRef
      } else return ATfalse;
#endif

   // MATCHED InquireSpec_ERR

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr13;
 if (ATmatch(term, "InquireSpec_ENCODING(<term>)", &DefaultCharExpr13.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr13.term, &DefaultCharExpr13)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED InquireSpec_ENCODING

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr14;
 if (ATmatch(term, "InquireSpec_DIRECT(<term>)", &DefaultCharExpr14.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr14.term, &DefaultCharExpr14)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED InquireSpec_DIRECT

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr15;
 if (ATmatch(term, "InquireSpec_DELIM(<term>)", &DefaultCharExpr15.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr15.term, &DefaultCharExpr15)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED InquireSpec_DELIM

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr16;
 if (ATmatch(term, "InquireSpec_DECIMAL(<term>)", &DefaultCharExpr16.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr16.term, &DefaultCharExpr16)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED InquireSpec_DECIMAL

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr17;
 if (ATmatch(term, "InquireSpec_BLANK(<term>)", &DefaultCharExpr17.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr17.term, &DefaultCharExpr17)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED InquireSpec_BLANK

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr18;
 if (ATmatch(term, "InquireSpec_ASYNCHRONOUS(<term>)", &DefaultCharExpr18.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr18.term, &DefaultCharExpr18)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED InquireSpec_ASYNCHRONOUS

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr19;
 if (ATmatch(term, "InquireSpec_ACTION(<term>)", &DefaultCharExpr19.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr19.term, &DefaultCharExpr19)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED InquireSpec_ACTION

   return ATtrue;
 }

 OFP_Traverse DefaultCharExpr20;
 if (ATmatch(term, "InquireSpec_ACCESS(<term>)", &DefaultCharExpr20.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr20.term, &DefaultCharExpr20)) {
         // MATCHED DefaultCharExpr
      } else return ATfalse;
#endif

   // MATCHED InquireSpec_ACCESS

   return ATtrue;
 }

 OFP_Traverse FileNameExpr;
 if (ATmatch(term, "InquireSpec_FILE(<term>)", &FileNameExpr.term)) {

      if (ofp_traverse_FileNameExpr(FileNameExpr.term, &FileNameExpr)) {
         // MATCHED FileNameExpr
      } else return ATfalse;

   // MATCHED InquireSpec_FILE

   return ATtrue;
 }

 OFP_Traverse FileUnitNumber;
 if (ATmatch(term, "InquireSpec_UNIT(<term>)", &FileUnitNumber.term)) {

      if (ofp_traverse_FileUnitNumber(FileUnitNumber.term, &FileUnitNumber)) {
         // MATCHED FileUnitNumber
      } else return ATfalse;

   // MATCHED InquireSpec_UNIT

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_InquireSpecList(ATerm term, pOFP_Traverse InquireSpecList)
{
#ifdef DEBUG_PRINT
   printf("InquireSpecList: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse InquireSpec;
 if (ATmatch(term, "InquireSpecList(<term>)", &InquireSpec.term)) {

   ATermList InquireSpec_tail = (ATermList) ATmake("<term>", InquireSpec.term);
   while (! ATisEmpty(InquireSpec_tail)) {
      InquireSpec.term = ATgetFirst(InquireSpec_tail);
      InquireSpec_tail = ATgetNext (InquireSpec_tail);
      if (ofp_traverse_InquireSpec(InquireSpec.term, &InquireSpec)) {
         // MATCHED InquireSpec
      } else return ATfalse;
   }

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1101 main-program
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_MainProgram(ATerm term, pOFP_Traverse MainProgram)
{
#ifdef DEBUG_PRINT
   printf("\nMainProgram: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse ProgramStmt, SpecificationPart, ExecutionPart, InternalSubprogramPart, EndProgramStmt;
 if (ATmatch(term, "MainProgram(<term>,<term>,<term>,<term>,<term>)", &ProgramStmt.term, &SpecificationPart.term, &ExecutionPart.term, &InternalSubprogramPart.term, &EndProgramStmt.term)) {

   if (ATmatch(ProgramStmt.term, "Some(<term>)", &ProgramStmt.term)) {
      if (ofp_traverse_ProgramStmt(ProgramStmt.term, &ProgramStmt)) {
         // MATCHED ProgramStmt
      } else return ATfalse;
   }

      if (ofp_traverse_SpecificationPart(SpecificationPart.term, &SpecificationPart)) {
         // MATCHED SpecificationPart
      } else return ATfalse;

      if (ofp_traverse_ExecutionPart(ExecutionPart.term, &ExecutionPart)) {
         // MATCHED ExecutionPart
      } else return ATfalse;

   if (ATmatch(InternalSubprogramPart.term, "Some(<term>)", &InternalSubprogramPart.term)) {
      if (ofp_traverse_InternalSubprogramPart(InternalSubprogramPart.term, &InternalSubprogramPart)) {
         // MATCHED InternalSubprogramPart
      } else return ATfalse;
   }

      if (ofp_traverse_EndProgramStmt(EndProgramStmt.term, &EndProgramStmt)) {
         // MATCHED EndProgramStmt
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1102 program-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_ProgramStmt(ATerm term, pOFP_Traverse ProgramStmt)
{
#ifdef DEBUG_PRINT
   printf("\nProgramStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, ProgramName, EOS;
 if (ATmatch(term, "ProgramStmt(<term>,<term>,<term>)", &Label.term, &ProgramName.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_ProgramName(ProgramName.term, &ProgramName)) {
         // MATCHED ProgramName
      } else return ATfalse;

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1103 end-program-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_EndProgramStmt(ATerm term, pOFP_Traverse EndProgramStmt)
{
#ifdef DEBUG_PRINT
   printf("\nEndProgramStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, ProgramName, EOS;
 if (ATmatch(term, "EndProgramStmt(<term>,<term>,<term>)", &Label.term, &ProgramName.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

   if (ATmatch(ProgramName.term, "Some(<term>)", &ProgramName.term)) {
   if (ATmatch(ProgramName.term, "(Some(<term>))", &ProgramName.term)) {
      if (ofp_traverse_ProgramName(ProgramName.term, &ProgramName)) {
         // MATCHED ProgramName
      } else return ATfalse;
   }
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1104 module
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_Module(ATerm term, pOFP_Traverse Module)
{
#ifdef DEBUG_PRINT
   printf("\nModule: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse ModuleStmt, SpecificationPart, ModuleSubprogramPart, EndModuleStmt;
 if (ATmatch(term, "Module(<term>,<term>,<term>,<term>)", &ModuleStmt.term, &SpecificationPart.term, &ModuleSubprogramPart.term, &EndModuleStmt.term)) {

      if (ofp_traverse_ModuleStmt(ModuleStmt.term, &ModuleStmt)) {
         // MATCHED ModuleStmt
      } else return ATfalse;

      if (ofp_traverse_SpecificationPart(SpecificationPart.term, &SpecificationPart)) {
         // MATCHED SpecificationPart
      } else return ATfalse;

   if (ATmatch(ModuleSubprogramPart.term, "Some(<term>)", &ModuleSubprogramPart.term)) {
      if (ofp_traverse_ModuleSubprogramPart(ModuleSubprogramPart.term, &ModuleSubprogramPart)) {
         // MATCHED ModuleSubprogramPart
      } else return ATfalse;
   }

      if (ofp_traverse_EndModuleStmt(EndModuleStmt.term, &EndModuleStmt)) {
         // MATCHED EndModuleStmt
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1105 module-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_ModuleStmt(ATerm term, pOFP_Traverse ModuleStmt)
{
#ifdef DEBUG_PRINT
   printf("ModuleStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, ModuleName, EOS;
 if (ATmatch(term, "ModuleStmt(<term>,<term>,<term>)", &Label.term, &ModuleName.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_ModuleName(ModuleName.term, &ModuleName)) {
         // MATCHED ModuleName
      } else return ATfalse;

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1106 end-module-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_EndModuleStmt(ATerm term, pOFP_Traverse EndModuleStmt)
{
#ifdef DEBUG_PRINT
   printf("EndModuleStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, ModuleName, EOS;
 if (ATmatch(term, "EndModuleStmt(<term>,<term>,<term>)", &Label.term, &ModuleName.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

   if (ATmatch(ModuleName.term, "Some(<term>)", &ModuleName.term)) {
   if (ATmatch(ModuleName.term, "(Some(<term>))", &ModuleName.term)) {
      if (ofp_traverse_ModuleName(ModuleName.term, &ModuleName)) {
         // MATCHED ModuleName
      } else return ATfalse;
   }
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1107 module-subprogram-part
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_ModuleSubprogramPart(ATerm term, pOFP_Traverse ModuleSubprogramPart)
{
#ifdef DEBUG_PRINT
   printf("ModuleSubprogramPart: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse ContainsStmt, ModuleSubprogram;
 if (ATmatch(term, "ModuleSubprogramPart(<term>,<term>)", &ContainsStmt.term, &ModuleSubprogram.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ContainsStmt(ContainsStmt.term, &ContainsStmt)) {
         // MATCHED ContainsStmt
      } else return ATfalse;
#endif

   ATermList ModuleSubprogram_tail = (ATermList) ATmake("<term>", ModuleSubprogram.term);
   while (! ATisEmpty(ModuleSubprogram_tail)) {
      ModuleSubprogram.term = ATgetFirst(ModuleSubprogram_tail);
      ModuleSubprogram_tail = ATgetNext (ModuleSubprogram_tail);
      if (ofp_traverse_ModuleSubprogram(ModuleSubprogram.term, &ModuleSubprogram)) {
         // MATCHED ModuleSubprogram
      } else return ATfalse;
   }

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1108 module-subprogram
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_ModuleSubprogram(ATerm term, pOFP_Traverse ModuleSubprogram)
{
#ifdef DEBUG_PRINT
   printf("ModuleSubprogram: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse SeparateModuleSubprogram;
 if (ATmatch(term, "ModuleSubprogram_SMS(<term>)", &SeparateModuleSubprogram.term)) {

      if (ofp_traverse_SeparateModuleSubprogram(SeparateModuleSubprogram.term, &SeparateModuleSubprogram)) {
         // MATCHED SeparateModuleSubprogram
      } else return ATfalse;

   // MATCHED ModuleSubprogram_SMS

   return ATtrue;
 }

 OFP_Traverse SubroutineSubprogram;
 if (ATmatch(term, "ModuleSubprogram_SS(<term>)", &SubroutineSubprogram.term)) {

      if (ofp_traverse_SubroutineSubprogram(SubroutineSubprogram.term, &SubroutineSubprogram)) {
         // MATCHED SubroutineSubprogram
      } else return ATfalse;

   // MATCHED ModuleSubprogram_SS

   return ATtrue;
 }

 OFP_Traverse FunctionSubprogram;
 if (ATmatch(term, "ModuleSubprogram_FS(<term>)", &FunctionSubprogram.term)) {

      if (ofp_traverse_FunctionSubprogram(FunctionSubprogram.term, &FunctionSubprogram)) {
         // MATCHED FunctionSubprogram
      } else return ATfalse;

   // MATCHED ModuleSubprogram_FS

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1109 use-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_UseStmt(ATerm term, pOFP_Traverse UseStmt)
{
#ifdef DEBUG_PRINT
   printf("UseStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, ModuleNature, ModuleName, OnlyList, EOS;
 if (ATmatch(term, "UseStmt_OL(<term>,<term>,<term>,<term>,<term>)", &Label.term, &ModuleNature.term, &ModuleName.term, &OnlyList.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

   if (ATmatch(ModuleNature.term, "Some(<term>)", &ModuleNature.term)) {
   if (ATmatch(ModuleNature.term, "(Some(<term>))", &ModuleNature.term)) {
   if (ATmatch(ModuleNature.term, "(<term>)", &ModuleNature.term)) {
      if (ofp_traverse_ModuleNature(ModuleNature.term, &ModuleNature)) {
         // MATCHED ModuleNature
      } else return ATfalse;
   }
   }
   }

      if (ofp_traverse_ModuleName(ModuleName.term, &ModuleName)) {
         // MATCHED ModuleName
      } else return ATfalse;

   if (ATmatch(OnlyList.term, "Some(<term>)", &OnlyList.term)) {
      if (ofp_traverse_OnlyList(OnlyList.term, &OnlyList)) {
         // MATCHED OnlyList
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   // MATCHED UseStmt_OL

   return ATtrue;
 }

 OFP_Traverse Label1, ModuleNature1, ModuleName1, RenameList, EOS1;
 if (ATmatch(term, "UseStmt_RL(<term>,<term>,<term>,<term>,<term>)", &Label1.term, &ModuleNature1.term, &ModuleName1.term, &RenameList.term, &EOS1.term)) {

   if (ATmatch(Label1.term, "Some(<term>)", &Label1.term)) {
      if (ofp_traverse_Label(Label1.term, &Label1)) {
         // MATCHED Label
      } else return ATfalse;
   }

   if (ATmatch(ModuleNature1.term, "Some(<term>)", &ModuleNature1.term)) {
   if (ATmatch(ModuleNature1.term, "(Some(<term>))", &ModuleNature1.term)) {
   if (ATmatch(ModuleNature1.term, "(<term>)", &ModuleNature1.term)) {
      if (ofp_traverse_ModuleNature(ModuleNature1.term, &ModuleNature1)) {
         // MATCHED ModuleNature
      } else return ATfalse;
   }
   }
   }

      if (ofp_traverse_ModuleName(ModuleName1.term, &ModuleName1)) {
         // MATCHED ModuleName
      } else return ATfalse;

   if (ATmatch(RenameList.term, "Some(<term>)", &RenameList.term)) {
   if (ATmatch(RenameList.term, "(<term>)", &RenameList.term)) {
      if (ofp_traverse_RenameList(RenameList.term, &RenameList)) {
         // MATCHED RenameList
      } else return ATfalse;
   }
   }

      if (ofp_traverse_EOS(EOS1.term, &EOS1)) {
         // MATCHED EOS
      } else return ATfalse;

   // MATCHED UseStmt_RL

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1110 module-nature
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_ModuleNature(ATerm term, pOFP_Traverse ModuleNature)
{
#ifdef DEBUG_PRINT
   printf("ModuleNature: %s\n", ATwriteToString(term));
#endif

 if (ATmatch(term, "ModuleNature_NON_INTRINSIC")) {

   // MATCHED ModuleNature_NON_INTRINSIC

   return ATtrue;
 }

 if (ATmatch(term, "ModuleNature_INTRINSIC")) {

   // MATCHED ModuleNature_INTRINSIC

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1111 rename
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_Rename(ATerm term, pOFP_Traverse Rename)
{
#ifdef DEBUG_PRINT
   printf("Rename: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse LocalDefinedOperator, UseDefinedOperator;
 if (ATmatch(term, "Rename_OP(<term>,<term>)", &LocalDefinedOperator.term, &UseDefinedOperator.term)) {

      if (ofp_traverse_LocalDefinedOperator(LocalDefinedOperator.term, &LocalDefinedOperator)) {
         // MATCHED LocalDefinedOperator
      } else return ATfalse;

      if (ofp_traverse_UseDefinedOperator(UseDefinedOperator.term, &UseDefinedOperator)) {
         // MATCHED UseDefinedOperator
      } else return ATfalse;

   // MATCHED Rename_OP

   return ATtrue;
 }

 OFP_Traverse LocalName, UseName;
 if (ATmatch(term, "Rename_LN(<term>,<term>)", &LocalName.term, &UseName.term)) {

      if (ofp_traverse_LocalName(LocalName.term, &LocalName)) {
         // MATCHED LocalName
      } else return ATfalse;

      if (ofp_traverse_UseName(UseName.term, &UseName)) {
         // MATCHED UseName
      } else return ATfalse;

   // MATCHED Rename_LN

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_RenameList(ATerm term, pOFP_Traverse RenameList)
{
#ifdef DEBUG_PRINT
   printf("RenameList: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Rename;
 if (ATmatch(term, "RenameList(<term>)", &Rename.term)) {

   ATermList Rename_tail = (ATermList) ATmake("<term>", Rename.term);
   while (! ATisEmpty(Rename_tail)) {
      Rename.term = ATgetFirst(Rename_tail);
      Rename_tail = ATgetNext (Rename_tail);
      if (ofp_traverse_Rename(Rename.term, &Rename)) {
         // MATCHED Rename
      } else return ATfalse;
   }

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1112 only
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_Only(ATerm term, pOFP_Traverse Only)
{
#ifdef DEBUG_PRINT
   printf("Only: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Rename;
 if (ATmatch(term, "Only_R(<term>)", &Rename.term)) {

      if (ofp_traverse_Rename(Rename.term, &Rename)) {
         // MATCHED Rename
      } else return ATfalse;

   // MATCHED Only_R

   return ATtrue;
 }

 OFP_Traverse OnlyUseName;
 if (ATmatch(term, "Only_OUN(<term>)", &OnlyUseName.term)) {

      if (ofp_traverse_OnlyUseName(OnlyUseName.term, &OnlyUseName)) {
         // MATCHED OnlyUseName
      } else return ATfalse;

   // MATCHED Only_OUN

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_OnlyList(ATerm term, pOFP_Traverse OnlyList)
{
#ifdef DEBUG_PRINT
   printf("OnlyList: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Only;
 if (ATmatch(term, "OnlyList(<term>)", &Only.term)) {

   ATermList Only_tail = (ATermList) ATmake("<term>", Only.term);
   while (! ATisEmpty(Only_tail)) {
      Only.term = ATgetFirst(Only_tail);
      Only_tail = ATgetNext (Only_tail);
      if (ofp_traverse_Only(Only.term, &Only)) {
         // MATCHED Only
      } else return ATfalse;
   }

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1113 only-use-name
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_OnlyUseName(ATerm term, pOFP_Traverse OnlyUseName)
{
#ifdef DEBUG_PRINT
   printf("OnlyUseName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "OnlyUseName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1114 local-defined-operator
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_LocalDefinedOperator(ATerm term, pOFP_Traverse LocalDefinedOperator)
{
#ifdef DEBUG_PRINT
   printf("LocalDefinedOperator: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse DefinedBinaryOp;
 if (ATmatch(term, "LocalDefinedOperator_DBO(<term>)", &DefinedBinaryOp.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefinedBinaryOp(DefinedBinaryOp.term, &DefinedBinaryOp)) {
         // MATCHED DefinedBinaryOp
      } else return ATfalse;
#endif

   // MATCHED LocalDefinedOperator_DBO

   return ATtrue;
 }

 OFP_Traverse DefinedUnaryOp;
 if (ATmatch(term, "LocalDefinedOperator_DUO(<term>)", &DefinedUnaryOp.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefinedUnaryOp(DefinedUnaryOp.term, &DefinedUnaryOp)) {
         // MATCHED DefinedUnaryOp
      } else return ATfalse;
#endif

   // MATCHED LocalDefinedOperator_DUO

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1115 use-defined-operator
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_UseDefinedOperator(ATerm term, pOFP_Traverse UseDefinedOperator)
{
#ifdef DEBUG_PRINT
   printf("UseDefinedOperator: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse DefinedBinaryOp;
 if (ATmatch(term, "UseDefinedOperator_DBO(<term>)", &DefinedBinaryOp.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefinedBinaryOp(DefinedBinaryOp.term, &DefinedBinaryOp)) {
         // MATCHED DefinedBinaryOp
      } else return ATfalse;
#endif

   // MATCHED UseDefinedOperator_DBO

   return ATtrue;
 }

 OFP_Traverse DefinedUnaryOp;
 if (ATmatch(term, "UseDefinedOperator_DUO(<term>)", &DefinedUnaryOp.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefinedUnaryOp(DefinedUnaryOp.term, &DefinedUnaryOp)) {
         // MATCHED DefinedUnaryOp
      } else return ATfalse;
#endif

   // MATCHED UseDefinedOperator_DUO

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1116 submodule
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_Submodule(ATerm term, pOFP_Traverse Submodule)
{
#ifdef DEBUG_PRINT
   printf("\nSubmodule: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse SubmoduleStmt, SpecificationPart, ModuleSubprogramPart, EndSubmoduleStmt;
 if (ATmatch(term, "Submodule(<term>,<term>,<term>,<term>)", &SubmoduleStmt.term, &SpecificationPart.term, &ModuleSubprogramPart.term, &EndSubmoduleStmt.term)) {

      if (ofp_traverse_SubmoduleStmt(SubmoduleStmt.term, &SubmoduleStmt)) {
         // MATCHED SubmoduleStmt
      } else return ATfalse;

      if (ofp_traverse_SpecificationPart(SpecificationPart.term, &SpecificationPart)) {
         // MATCHED SpecificationPart
      } else return ATfalse;

   if (ATmatch(ModuleSubprogramPart.term, "Some(<term>)", &ModuleSubprogramPart.term)) {
      if (ofp_traverse_ModuleSubprogramPart(ModuleSubprogramPart.term, &ModuleSubprogramPart)) {
         // MATCHED ModuleSubprogramPart
      } else return ATfalse;
   }

      if (ofp_traverse_EndSubmoduleStmt(EndSubmoduleStmt.term, &EndSubmoduleStmt)) {
         // MATCHED EndSubmoduleStmt
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1117 submodule-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_SubmoduleStmt(ATerm term, pOFP_Traverse SubmoduleStmt)
{
#ifdef DEBUG_PRINT
   printf("SubmoduleStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, ParentIdentifier, SubmoduleName, EOS;
 if (ATmatch(term, "SubmoduleStmt(<term>,<term>,<term>,<term>)", &Label.term, &ParentIdentifier.term, &SubmoduleName.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_ParentIdentifier(ParentIdentifier.term, &ParentIdentifier)) {
         // MATCHED ParentIdentifier
      } else return ATfalse;

      if (ofp_traverse_SubmoduleName(SubmoduleName.term, &SubmoduleName)) {
         // MATCHED SubmoduleName
      } else return ATfalse;

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1118 parent-identifier
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_ParentIdentifier(ATerm term, pOFP_Traverse ParentIdentifier)
{
#ifdef DEBUG_PRINT
   printf("ParentIdentifier: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse AncestorModuleName, ParentSubmoduleName;
 if (ATmatch(term, "ParentIdentifier(<term>,<term>)", &AncestorModuleName.term, &ParentSubmoduleName.term)) {

      if (ofp_traverse_AncestorModuleName(AncestorModuleName.term, &AncestorModuleName)) {
         // MATCHED AncestorModuleName
      } else return ATfalse;

   if (ATmatch(ParentSubmoduleName.term, "Some(<term>)", &ParentSubmoduleName.term)) {
   if (ATmatch(ParentSubmoduleName.term, "(<term>)", &ParentSubmoduleName.term)) {
      if (ofp_traverse_ParentSubmoduleName(ParentSubmoduleName.term, &ParentSubmoduleName)) {
         // MATCHED ParentSubmoduleName
      } else return ATfalse;
   }
   }

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1119 end-submodule-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_EndSubmoduleStmt(ATerm term, pOFP_Traverse EndSubmoduleStmt)
{
#ifdef DEBUG_PRINT
   printf("EndSubmoduleStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, SubmoduleName, EOS;
 if (ATmatch(term, "EndSubmoduleStmt(<term>,<term>,<term>)", &Label.term, &SubmoduleName.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

   if (ATmatch(SubmoduleName.term, "Some(<term>)", &SubmoduleName.term)) {
   if (ATmatch(SubmoduleName.term, "(Some(<term>))", &SubmoduleName.term)) {
      if (ofp_traverse_SubmoduleName(SubmoduleName.term, &SubmoduleName)) {
         // MATCHED SubmoduleName
      } else return ATfalse;
   }
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1120 block-data
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_BlockData(ATerm term, pOFP_Traverse BlockData)
{
#ifdef DEBUG_PRINT
   printf("\nBlockData: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse BlockDataStmt, SpecificationPart, EndBlockDataStmt;
 if (ATmatch(term, "BlockData(<term>,<term>,<term>)", &BlockDataStmt.term, &SpecificationPart.term, &EndBlockDataStmt.term)) {

      if (ofp_traverse_BlockDataStmt(BlockDataStmt.term, &BlockDataStmt)) {
         // MATCHED BlockDataStmt
      } else return ATfalse;

      if (ofp_traverse_SpecificationPart(SpecificationPart.term, &SpecificationPart)) {
         // MATCHED SpecificationPart
      } else return ATfalse;

      if (ofp_traverse_EndBlockDataStmt(EndBlockDataStmt.term, &EndBlockDataStmt)) {
         // MATCHED EndBlockDataStmt
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1121 block-data-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_BlockDataStmt(ATerm term, pOFP_Traverse BlockDataStmt)
{
#ifdef DEBUG_PRINT
   printf("BlockDataStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, BlockDataName, EOS;
 if (ATmatch(term, "BlockDataStmt(<term>,<term>,<term>)", &Label.term, &BlockDataName.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

   if (ATmatch(BlockDataName.term, "Some(<term>)", &BlockDataName.term)) {
      if (ofp_traverse_BlockDataName(BlockDataName.term, &BlockDataName)) {
         // MATCHED BlockDataName
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1122 end-block-data-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_EndBlockDataStmt(ATerm term, pOFP_Traverse EndBlockDataStmt)
{
#ifdef DEBUG_PRINT
   printf("EndBlockDataStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, EOS;
 if (ATmatch(term, "EndBlockDataStmt(<term>,<term>)", &Label.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 OFP_Traverse Label1, BlockDataName, EOS1;
 if (ATmatch(term, "EndBlockDataStmt_BDN(<term>,<term>,<term>)", &Label1.term, &BlockDataName.term, &EOS1.term)) {

   if (ATmatch(Label1.term, "Some(<term>)", &Label1.term)) {
      if (ofp_traverse_Label(Label1.term, &Label1)) {
         // MATCHED Label
      } else return ATfalse;
   }

   if (ATmatch(BlockDataName.term, "Some(<term>)", &BlockDataName.term)) {
      if (ofp_traverse_BlockDataName(BlockDataName.term, &BlockDataName)) {
         // MATCHED BlockDataName
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS1.term, &EOS1)) {
         // MATCHED EOS
      } else return ATfalse;

   // MATCHED EndBlockDataStmt_BDN

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1201 interface-block
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_InterfaceBlock(ATerm term, pOFP_Traverse InterfaceBlock)
{
#ifdef DEBUG_PRINT
   printf("InterfaceBlock: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse InterfaceStmt, InterfaceSpecification, EndInterfaceStmt;
 if (ATmatch(term, "InterfaceBlock(<term>,<term>,<term>)", &InterfaceStmt.term, &InterfaceSpecification.term, &EndInterfaceStmt.term)) {

      if (ofp_traverse_InterfaceStmt(InterfaceStmt.term, &InterfaceStmt)) {
         // MATCHED InterfaceStmt
      } else return ATfalse;

   ATermList InterfaceSpecification_tail = (ATermList) ATmake("<term>", InterfaceSpecification.term);
   while (! ATisEmpty(InterfaceSpecification_tail)) {
      InterfaceSpecification.term = ATgetFirst(InterfaceSpecification_tail);
      InterfaceSpecification_tail = ATgetNext (InterfaceSpecification_tail);
      if (ofp_traverse_InterfaceSpecification(InterfaceSpecification.term, &InterfaceSpecification)) {
         // MATCHED InterfaceSpecification
      } else return ATfalse;
   }

      if (ofp_traverse_EndInterfaceStmt(EndInterfaceStmt.term, &EndInterfaceStmt)) {
         // MATCHED EndInterfaceStmt
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1202 interface-specification
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_InterfaceSpecification(ATerm term, pOFP_Traverse InterfaceSpecification)
{
#ifdef DEBUG_PRINT
   printf("InterfaceSpecification: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse ProcedureStmt;
 if (ATmatch(term, "InterfaceSpecification_PS(<term>)", &ProcedureStmt.term)) {

      if (ofp_traverse_ProcedureStmt(ProcedureStmt.term, &ProcedureStmt)) {
         // MATCHED ProcedureStmt
      } else return ATfalse;

   // MATCHED InterfaceSpecification_PS

   return ATtrue;
 }

 OFP_Traverse InterfaceBody;
 if (ATmatch(term, "InterfaceSpecification_IB(<term>)", &InterfaceBody.term)) {

      if (ofp_traverse_InterfaceBody(InterfaceBody.term, &InterfaceBody)) {
         // MATCHED InterfaceBody
      } else return ATfalse;

   // MATCHED InterfaceSpecification_IB

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1203 interface-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_InterfaceStmt(ATerm term, pOFP_Traverse InterfaceStmt)
{
#ifdef DEBUG_PRINT
   printf("InterfaceStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, EOS;
 if (ATmatch(term, "InterfaceStmt_AB(<term>,<term>)", &Label.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   // MATCHED InterfaceStmt_AB

   return ATtrue;
 }

 OFP_Traverse Label1, GenericSpec, EOS1;
 if (ATmatch(term, "InterfaceStmt_GS(<term>,<term>,<term>)", &Label1.term, &GenericSpec.term, &EOS1.term)) {

   if (ATmatch(Label1.term, "Some(<term>)", &Label1.term)) {
      if (ofp_traverse_Label(Label1.term, &Label1)) {
         // MATCHED Label
      } else return ATfalse;
   }

   if (ATmatch(GenericSpec.term, "Some(<term>)", &GenericSpec.term)) {
      if (ofp_traverse_GenericSpec(GenericSpec.term, &GenericSpec)) {
         // MATCHED GenericSpec
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS1.term, &EOS1)) {
         // MATCHED EOS
      } else return ATfalse;

   // MATCHED InterfaceStmt_GS

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1204 end-interface-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_EndInterfaceStmt(ATerm term, pOFP_Traverse EndInterfaceStmt)
{
#ifdef DEBUG_PRINT
   printf("EndInterfaceStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, GenericSpec, EOS;
 if (ATmatch(term, "EndInterfaceStmt(<term>,<term>,<term>)", &Label.term, &GenericSpec.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

   if (ATmatch(GenericSpec.term, "Some(<term>)", &GenericSpec.term)) {
      if (ofp_traverse_GenericSpec(GenericSpec.term, &GenericSpec)) {
         // MATCHED GenericSpec
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1205 interface-body
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_InterfaceBody(ATerm term, pOFP_Traverse InterfaceBody)
{
#ifdef DEBUG_PRINT
   printf("InterfaceBody: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse SubroutineStmt, SpecificationPart, EndSubroutineStmt;
 if (ATmatch(term, "InterfaceBody_SS(<term>,<term>,<term>)", &SubroutineStmt.term, &SpecificationPart.term, &EndSubroutineStmt.term)) {

      if (ofp_traverse_SubroutineStmt(SubroutineStmt.term, &SubroutineStmt)) {
         // MATCHED SubroutineStmt
      } else return ATfalse;

      if (ofp_traverse_SpecificationPart(SpecificationPart.term, &SpecificationPart)) {
         // MATCHED SpecificationPart
      } else return ATfalse;

      if (ofp_traverse_EndSubroutineStmt(EndSubroutineStmt.term, &EndSubroutineStmt)) {
         // MATCHED EndSubroutineStmt
      } else return ATfalse;

   // MATCHED InterfaceBody_SS

   return ATtrue;
 }

 OFP_Traverse FunctionStmt, SpecificationPart1, EndFunctionStmt;
 if (ATmatch(term, "InterfaceBody_FS(<term>,<term>,<term>)", &FunctionStmt.term, &SpecificationPart1.term, &EndFunctionStmt.term)) {

      if (ofp_traverse_FunctionStmt(FunctionStmt.term, &FunctionStmt)) {
         // MATCHED FunctionStmt
      } else return ATfalse;

      if (ofp_traverse_SpecificationPart(SpecificationPart1.term, &SpecificationPart1)) {
         // MATCHED SpecificationPart
      } else return ATfalse;

      if (ofp_traverse_EndFunctionStmt(EndFunctionStmt.term, &EndFunctionStmt)) {
         // MATCHED EndFunctionStmt
      } else return ATfalse;

   // MATCHED InterfaceBody_FS

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1206 procedure-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_ProcedureStmt(ATerm term, pOFP_Traverse ProcedureStmt)
{
#ifdef DEBUG_PRINT
   printf("ProcedureStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, ProcedureNameList, EOS;
 if (ATmatch(term, "ProcedureStmt_P(<term>,<term>,<term>)", &Label.term, &ProcedureNameList.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_ProcedureNameList(ProcedureNameList.term, &ProcedureNameList)) {
         // MATCHED ProcedureNameList
      } else return ATfalse;

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   // MATCHED ProcedureStmt_P

   return ATtrue;
 }

 OFP_Traverse Label1, ProcedureNameList1, EOS1;
 if (ATmatch(term, "ProcedureStmt_MP(<term>,<term>,<term>)", &Label1.term, &ProcedureNameList1.term, &EOS1.term)) {

   if (ATmatch(Label1.term, "Some(<term>)", &Label1.term)) {
      if (ofp_traverse_Label(Label1.term, &Label1)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_ProcedureNameList(ProcedureNameList1.term, &ProcedureNameList1)) {
         // MATCHED ProcedureNameList
      } else return ATfalse;

      if (ofp_traverse_EOS(EOS1.term, &EOS1)) {
         // MATCHED EOS
      } else return ATfalse;

   // MATCHED ProcedureStmt_MP

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ProcedureNameList(ATerm term, pOFP_Traverse ProcedureNameList)
{
#ifdef DEBUG_PRINT
   printf("ProcedureNameList: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse ProcedureName;
 if (ATmatch(term, "ProcedureNameList(<term>)", &ProcedureName.term)) {

   ATermList ProcedureName_tail = (ATermList) ATmake("<term>", ProcedureName.term);
   while (! ATisEmpty(ProcedureName_tail)) {
      ProcedureName.term = ATgetFirst(ProcedureName_tail);
      ProcedureName_tail = ATgetNext (ProcedureName_tail);
      if (ofp_traverse_ProcedureName(ProcedureName.term, &ProcedureName)) {
         // MATCHED ProcedureName
      } else return ATfalse;
   }

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1207 generic-spec
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_GenericSpec(ATerm term, pOFP_Traverse GenericSpec)
{
#ifdef DEBUG_PRINT
   printf("GenericSpec: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse DefinedIoGenericSpec;
 if (ATmatch(term, "GenericSpec_DIGS(<term>)", &DefinedIoGenericSpec.term)) {

      if (ofp_traverse_DefinedIoGenericSpec(DefinedIoGenericSpec.term, &DefinedIoGenericSpec)) {
         // MATCHED DefinedIoGenericSpec
      } else return ATfalse;

   // MATCHED GenericSpec_DIGS

   return ATtrue;
 }

 if (ATmatch(term, "GenericSpec_AS")) {

   // MATCHED GenericSpec_AS

   return ATtrue;
 }

 OFP_Traverse DefinedOperator;
 if (ATmatch(term, "GenericSpec_OP(<term>)", &DefinedOperator.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefinedOperator(DefinedOperator.term, &DefinedOperator)) {
         // MATCHED DefinedOperator
      } else return ATfalse;
#endif

   // MATCHED GenericSpec_OP

   return ATtrue;
 }

 OFP_Traverse GenericName;
 if (ATmatch(term, "GenericSpec_GN(<term>)", &GenericName.term)) {

      if (ofp_traverse_GenericName(GenericName.term, &GenericName)) {
         // MATCHED GenericName
      } else return ATfalse;

   // MATCHED GenericSpec_GN

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1208 defined-io-generic-spec
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_DefinedIoGenericSpec(ATerm term, pOFP_Traverse DefinedIoGenericSpec)
{
#ifdef DEBUG_PRINT
   printf("DefinedIoGenericSpec: %s\n", ATwriteToString(term));
#endif

 if (ATmatch(term, "DefinedIoGenericSpec_WU")) {

   // MATCHED DefinedIoGenericSpec_WU

   return ATtrue;
 }

 if (ATmatch(term, "DefinedIoGenericSpec_WF")) {

   // MATCHED DefinedIoGenericSpec_WF

   return ATtrue;
 }

 if (ATmatch(term, "DefinedIoGenericSpec_RU")) {

   // MATCHED DefinedIoGenericSpec_RU

   return ATtrue;
 }

 if (ATmatch(term, "DefinedIoGenericSpec_RF")) {

   // MATCHED DefinedIoGenericSpec_RF

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1209 import-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_ImportStmt(ATerm term, pOFP_Traverse ImportStmt)
{
#ifdef DEBUG_PRINT
   printf("ImportStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, EOS;
 if (ATmatch(term, "ImportStmt(<term>,<term>)", &Label.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 OFP_Traverse Label1, ImportNameList, EOS1;
 if (ATmatch(term, "ImportStmt_INL(<term>,<term>,<term>)", &Label1.term, &ImportNameList.term, &EOS1.term)) {

   if (ATmatch(Label1.term, "Some(<term>)", &Label1.term)) {
      if (ofp_traverse_Label(Label1.term, &Label1)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_ImportNameList(ImportNameList.term, &ImportNameList)) {
         // MATCHED ImportNameList
      } else return ATfalse;

      if (ofp_traverse_EOS(EOS1.term, &EOS1)) {
         // MATCHED EOS
      } else return ATfalse;

   // MATCHED ImportStmt_INL

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ImportNameList(ATerm term, pOFP_Traverse ImportNameList)
{
#ifdef DEBUG_PRINT
   printf("ImportNameList: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse ImportName;
 if (ATmatch(term, "ImportNameList(<term>)", &ImportName.term)) {

   ATermList ImportName_tail = (ATermList) ATmake("<term>", ImportName.term);
   while (! ATisEmpty(ImportName_tail)) {
      ImportName.term = ATgetFirst(ImportName_tail);
      ImportName_tail = ATgetNext (ImportName_tail);
      if (ofp_traverse_ImportName(ImportName.term, &ImportName)) {
         // MATCHED ImportName
      } else return ATfalse;
   }

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1210 external-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_ExternalStmt(ATerm term, pOFP_Traverse ExternalStmt)
{
#ifdef DEBUG_PRINT
   printf("ExternalStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, ExternalNameList, EOS;
 if (ATmatch(term, "ExternalStmt(<term>,<term>,<term>)", &Label.term, &ExternalNameList.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_ExternalNameList(ExternalNameList.term, &ExternalNameList)) {
         // MATCHED ExternalNameList
      } else return ATfalse;

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1211 procedure-declaration-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_ProcedureDeclarationStmt(ATerm term, pOFP_Traverse ProcedureDeclarationStmt)
{
#ifdef DEBUG_PRINT
   printf("ProcedureDeclarationStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, ProcInterface, ProcAttrSpecList, ProcDeclList, EOS;
 if (ATmatch(term, "ProcedureDeclarationStmt(<term>,<term>,<term>,<term>,<term>)", &Label.term, &ProcInterface.term, &ProcAttrSpecList.term, &ProcDeclList.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

   if (ATmatch(ProcInterface.term, "Some(<term>)", &ProcInterface.term)) {
      if (ofp_traverse_ProcInterface(ProcInterface.term, &ProcInterface)) {
         // MATCHED ProcInterface
      } else return ATfalse;
   }

   if (ATmatch(ProcAttrSpecList.term, "Some(<term>)", &ProcAttrSpecList.term)) {
   if (ATmatch(ProcAttrSpecList.term, "(Some(<term>))", &ProcAttrSpecList.term)) {
   if (ATmatch(ProcAttrSpecList.term, "(<term>)", &ProcAttrSpecList.term)) {
      if (ofp_traverse_ProcAttrSpecList(ProcAttrSpecList.term, &ProcAttrSpecList)) {
         // MATCHED ProcAttrSpecList
      } else return ATfalse;
   }
   }
   }

      if (ofp_traverse_ProcDeclList(ProcDeclList.term, &ProcDeclList)) {
         // MATCHED ProcDeclList
      } else return ATfalse;

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1212 proc-interface
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_ProcInterface(ATerm term, pOFP_Traverse ProcInterface)
{
#ifdef DEBUG_PRINT
   printf("ProcInterface: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse DeclarationTypeSpec;
 if (ATmatch(term, "ProcInterface_DTS(<term>)", &DeclarationTypeSpec.term)) {

      if (ofp_traverse_DeclarationTypeSpec(DeclarationTypeSpec.term, &DeclarationTypeSpec)) {
         // MATCHED DeclarationTypeSpec
      } else return ATfalse;

   // MATCHED ProcInterface_DTS

   return ATtrue;
 }

 OFP_Traverse InterfaceName;
 if (ATmatch(term, "ProcInterface_IN(<term>)", &InterfaceName.term)) {

      if (ofp_traverse_InterfaceName(InterfaceName.term, &InterfaceName)) {
         // MATCHED InterfaceName
      } else return ATfalse;

   // MATCHED ProcInterface_IN

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1213 proc-attr-spec
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_ProcAttrSpec(ATerm term, pOFP_Traverse ProcAttrSpec)
{
#ifdef DEBUG_PRINT
   printf("ProcAttrSpec: %s\n", ATwriteToString(term));
#endif

 if (ATmatch(term, "ProcAttrSpec_SAVE")) {

   // MATCHED ProcAttrSpec_SAVE

   return ATtrue;
 }

 if (ATmatch(term, "ProcAttrSpec_POINTER")) {

   // MATCHED ProcAttrSpec_POINTER

   return ATtrue;
 }

 if (ATmatch(term, "ProcAttrSpec_OPTIONAL")) {

   // MATCHED ProcAttrSpec_OPTIONAL

   return ATtrue;
 }

 OFP_Traverse IntentSpec;
 if (ATmatch(term, "ProcAttrSpec_INTENT(<term>)", &IntentSpec.term)) {

#ifdef NOT_YET
      if (ofp_traverse_IntentSpec(IntentSpec.term, &IntentSpec)) {
         // MATCHED IntentSpec
      } else return ATfalse;
#endif

   // MATCHED ProcAttrSpec_INTENT

   return ATtrue;
 }

 OFP_Traverse ProcLanguageBindingSpec;
 if (ATmatch(term, "ProcAttrSpec_PLBS(<term>)", &ProcLanguageBindingSpec.term)) {

      if (ofp_traverse_ProcLanguageBindingSpec(ProcLanguageBindingSpec.term, &ProcLanguageBindingSpec)) {
         // MATCHED ProcLanguageBindingSpec
      } else return ATfalse;

   // MATCHED ProcAttrSpec_PLBS

   return ATtrue;
 }

 OFP_Traverse AccessSpec;
 if (ATmatch(term, "ProcAttrSpec_AS(<term>)", &AccessSpec.term)) {

#ifdef NOT_YET
      if (ofp_traverse_AccessSpec(AccessSpec.term, &AccessSpec)) {
         // MATCHED AccessSpec
      } else return ATfalse;
#endif

   // MATCHED ProcAttrSpec_AS

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ProcAttrSpecList(ATerm term, pOFP_Traverse ProcAttrSpecList)
{
#ifdef DEBUG_PRINT
   printf("ProcAttrSpecList: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse ProcAttrSpec;
 if (ATmatch(term, "ProcAttrSpecList(<term>)", &ProcAttrSpec.term)) {

   ATermList ProcAttrSpec_tail = (ATermList) ATmake("<term>", ProcAttrSpec.term);
   while (! ATisEmpty(ProcAttrSpec_tail)) {
      ProcAttrSpec.term = ATgetFirst(ProcAttrSpec_tail);
      ProcAttrSpec_tail = ATgetNext (ProcAttrSpec_tail);
      if (ofp_traverse_ProcAttrSpec(ProcAttrSpec.term, &ProcAttrSpec)) {
         // MATCHED ProcAttrSpec
      } else return ATfalse;
   }

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1214 proc-decl
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_ProcDecl(ATerm term, pOFP_Traverse ProcDecl)
{
#ifdef DEBUG_PRINT
   printf("ProcDecl: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse ProcedureEntityName, ProcPointerInit;
 if (ATmatch(term, "ProcDecl(<term>,<term>)", &ProcedureEntityName.term, &ProcPointerInit.term)) {

      if (ofp_traverse_ProcedureEntityName(ProcedureEntityName.term, &ProcedureEntityName)) {
         // MATCHED ProcedureEntityName
      } else return ATfalse;

   if (ATmatch(ProcPointerInit.term, "Some(<term>)", &ProcPointerInit.term)) {
   if (ATmatch(ProcPointerInit.term, "(<term>)", &ProcPointerInit.term)) {
      if (ofp_traverse_ProcPointerInit(ProcPointerInit.term, &ProcPointerInit)) {
         // MATCHED ProcPointerInit
      } else return ATfalse;
   }
   }

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ProcDeclList(ATerm term, pOFP_Traverse ProcDeclList)
{
#ifdef DEBUG_PRINT
   printf("ProcDeclList: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse ProcDecl;
 if (ATmatch(term, "ProcDeclList(<term>)", &ProcDecl.term)) {

   ATermList ProcDecl_tail = (ATermList) ATmake("<term>", ProcDecl.term);
   while (! ATisEmpty(ProcDecl_tail)) {
      ProcDecl.term = ATgetFirst(ProcDecl_tail);
      ProcDecl_tail = ATgetNext (ProcDecl_tail);
      if (ofp_traverse_ProcDecl(ProcDecl.term, &ProcDecl)) {
         // MATCHED ProcDecl
      } else return ATfalse;
   }

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1215 interface-name
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_InterfaceName(ATerm term, pOFP_Traverse InterfaceName)
{
#ifdef DEBUG_PRINT
   printf("InterfaceName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "InterfaceName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1216 proc-pointer-init
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_ProcPointerInit(ATerm term, pOFP_Traverse ProcPointerInit)
{
#ifdef DEBUG_PRINT
   printf("ProcPointerInit: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse InitialProcTarget;
 if (ATmatch(term, "ProcPointerInit_IPT(<term>)", &InitialProcTarget.term)) {

      if (ofp_traverse_InitialProcTarget(InitialProcTarget.term, &InitialProcTarget)) {
         // MATCHED InitialProcTarget
      } else return ATfalse;

   // MATCHED ProcPointerInit_IPT

   return ATtrue;
 }

 OFP_Traverse NullInit;
 if (ATmatch(term, "ProcPointerInit_NI(<term>)", &NullInit.term)) {

#ifdef NOT_YET
      if (ofp_traverse_NullInit(NullInit.term, &NullInit)) {
         // MATCHED NullInit
      } else return ATfalse;
#endif

   // MATCHED ProcPointerInit_NI

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1217 initial-proc-target
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_InitialProcTarget(ATerm term, pOFP_Traverse InitialProcTarget)
{
#ifdef DEBUG_PRINT
   printf("InitialProcTarget: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse ProcedureName;
 if (ATmatch(term, "InitialProcTarget(<term>)", &ProcedureName.term)) {

      if (ofp_traverse_ProcedureName(ProcedureName.term, &ProcedureName)) {
         // MATCHED ProcedureName
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1218 intrinsic-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_IntrinsicStmt(ATerm term, pOFP_Traverse IntrinsicStmt)
{
#ifdef DEBUG_PRINT
   printf("IntrinsicStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, IntrinsicProcedureNameList, EOS;
 if (ATmatch(term, "IntrinsicStmt(<term>,<term>,<term>)", &Label.term, &IntrinsicProcedureNameList.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_IntrinsicProcedureNameList(IntrinsicProcedureNameList.term, &IntrinsicProcedureNameList)) {
         // MATCHED IntrinsicProcedureNameList
      } else return ATfalse;

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_IntrinsicProcedureNameList(ATerm term, pOFP_Traverse IntrinsicProcedureNameList)
{
#ifdef DEBUG_PRINT
   printf("IntrinsicProcedureNameList: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse IntrinsicProcedureName;
 if (ATmatch(term, "IntrinsicProcedureNameList(<term>)", &IntrinsicProcedureName.term)) {

   ATermList IntrinsicProcedureName_tail = (ATermList) ATmake("<term>", IntrinsicProcedureName.term);
   while (! ATisEmpty(IntrinsicProcedureName_tail)) {
      IntrinsicProcedureName.term = ATgetFirst(IntrinsicProcedureName_tail);
      IntrinsicProcedureName_tail = ATgetNext (IntrinsicProcedureName_tail);
      if (ofp_traverse_IntrinsicProcedureName(IntrinsicProcedureName.term, &IntrinsicProcedureName)) {
         // MATCHED IntrinsicProcedureName
      } else return ATfalse;
   }

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1219 function-reference
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_FunctionReference(ATerm term, pOFP_Traverse FunctionReference)
{
#ifdef DEBUG_PRINT
   printf("FunctionReference: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse ProcedureDesignator, ActualArgSpecList;
 if (ATmatch(term, "FunctionReference(<term>,<term>)", &ProcedureDesignator.term, &ActualArgSpecList.term)) {

      if (ofp_traverse_ProcedureDesignator(ProcedureDesignator.term, &ProcedureDesignator)) {
         // MATCHED ProcedureDesignator
      } else return ATfalse;

   if (ATmatch(ActualArgSpecList.term, "Some(<term>)", &ActualArgSpecList.term)) {
      if (ofp_traverse_ActualArgSpecList(ActualArgSpecList.term, &ActualArgSpecList)) {
         // MATCHED ActualArgSpecList
      } else return ATfalse;
   }

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1220 call-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_CallStmt(ATerm term, pOFP_Traverse CallStmt)
{
#ifdef DEBUG_PRINT
   printf("CallStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, ProcedureDesignator, ActualArgSpecList, EOS;
 if (ATmatch(term, "CallStmt(<term>,<term>,<term>,<term>)", &Label.term, &ProcedureDesignator.term, &ActualArgSpecList.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_ProcedureDesignator(ProcedureDesignator.term, &ProcedureDesignator)) {
         // MATCHED ProcedureDesignator
      } else return ATfalse;

   if (ATmatch(ActualArgSpecList.term, "Some(<term>)", &ActualArgSpecList.term)) {
   if (ATmatch(ActualArgSpecList.term, "(Some(<term>))", &ActualArgSpecList.term)) {
      if (ofp_traverse_ActualArgSpecList(ActualArgSpecList.term, &ActualArgSpecList)) {
         // MATCHED ActualArgSpecList
      } else return ATfalse;
   }
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1221 procedure-designator
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_ProcedureDesignator(ATerm term, pOFP_Traverse ProcedureDesignator)
{
#ifdef DEBUG_PRINT
   printf("ProcedureDesignator: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse DataRef, BindingName;
 if (ATmatch(term, "ProcedureDesignator_AMB(<term>,<term>)", &DataRef.term, &BindingName.term)) {

      if (ofp_traverse_DataRef(DataRef.term, &DataRef)) {
         // MATCHED DataRef
      } else return ATfalse;

      if (ofp_traverse_BindingName(BindingName.term, &BindingName)) {
         // MATCHED BindingName
      } else return ATfalse;

   // MATCHED ProcedureDesignator_AMB

   return ATtrue;
 }

 OFP_Traverse ProcedureName;
 if (ATmatch(term, "ProcedureDesignator_PN(<term>)", &ProcedureName.term)) {

      if (ofp_traverse_ProcedureName(ProcedureName.term, &ProcedureName)) {
         // MATCHED ProcedureName
      } else return ATfalse;

   // MATCHED ProcedureDesignator_PN

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1222 actual-arg-spec
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_ActualArgSpec(ATerm term, pOFP_Traverse ActualArgSpec)
{
#ifdef DEBUG_PRINT
   printf("ActualArgSpec: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Keyword, ActualArg;
 if (ATmatch(term, "ActualArgSpec(<term>,<term>)", &Keyword.term, &ActualArg.term)) {

   if (ATmatch(Keyword.term, "Some(<term>)", &Keyword.term)) {
   if (ATmatch(Keyword.term, "(<term>)", &Keyword.term)) {
      if (ofp_traverse_Keyword(Keyword.term, &Keyword)) {
         // MATCHED Keyword
      } else return ATfalse;
   }
   }

      if (ofp_traverse_ActualArg(ActualArg.term, &ActualArg)) {
         // MATCHED ActualArg
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ActualArgSpecList(ATerm term, pOFP_Traverse ActualArgSpecList)
{
#ifdef DEBUG_PRINT
   printf("ActualArgSpecList: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse ActualArgSpec;
 if (ATmatch(term, "ActualArgSpecList(<term>)", &ActualArgSpec.term)) {

   ATermList ActualArgSpec_tail = (ATermList) ATmake("<term>", ActualArgSpec.term);
   while (! ATisEmpty(ActualArgSpec_tail)) {
      ActualArgSpec.term = ATgetFirst(ActualArgSpec_tail);
      ActualArgSpec_tail = ATgetNext (ActualArgSpec_tail);
      if (ofp_traverse_ActualArgSpec(ActualArgSpec.term, &ActualArgSpec)) {
         // MATCHED ActualArgSpec
      } else return ATfalse;
   }

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1223 actual-arg
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_ActualArg(ATerm term, pOFP_Traverse ActualArg)
{
#ifdef DEBUG_PRINT
   printf("ActualArg: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse AltReturnSpec;
 if (ATmatch(term, "ActualArg(<term>)", &AltReturnSpec.term)) {

      if (ofp_traverse_AltReturnSpec(AltReturnSpec.term, &AltReturnSpec)) {
         // MATCHED AltReturnSpec
      } else return ATfalse;

   return ATtrue;
 }

 OFP_Traverse Expr;
 if (ATmatch(term, "ActualArg_AMB(<term>)", &Expr.term)) {

      if (ofp_traverse_Expr(Expr.term, &Expr)) {
         // MATCHED Expr
      } else return ATfalse;

   // MATCHED ActualArg_AMB

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1224 alt-return-spec
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_AltReturnSpec(ATerm term, pOFP_Traverse AltReturnSpec)
{
#ifdef DEBUG_PRINT
   printf("AltReturnSpec: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label;
 if (ATmatch(term, "AltReturnSpec(<term>)", &Label.term)) {

      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1225 prefix
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_Prefix(ATerm term, pOFP_Traverse Prefix)
{
#ifdef DEBUG_PRINT
   printf("Prefix: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse PrefixSpec;
 if (ATmatch(term, "Prefix(<term>)", &PrefixSpec.term)) {

   ATermList PrefixSpec_tail = (ATermList) ATmake("<term>", PrefixSpec.term);
   while (! ATisEmpty(PrefixSpec_tail)) {
      PrefixSpec.term = ATgetFirst(PrefixSpec_tail);
      PrefixSpec_tail = ATgetNext (PrefixSpec_tail);
      if (ofp_traverse_PrefixSpec(PrefixSpec.term, &PrefixSpec)) {
         // MATCHED PrefixSpec
      } else return ATfalse;
   }

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1226 prefix-spec
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_PrefixSpec(ATerm term, pOFP_Traverse PrefixSpec)
{
#ifdef DEBUG_PRINT
   printf("PrefixSpec: %s\n", ATwriteToString(term));
#endif

 if (ATmatch(term, "PrefixSpec_RECURSIVE")) {

   // MATCHED PrefixSpec_RECURSIVE

   return ATtrue;
 }

 if (ATmatch(term, "PrefixSpec_PURE")) {

   // MATCHED PrefixSpec_PURE

   return ATtrue;
 }

 if (ATmatch(term, "PrefixSpec_MODULE")) {

   // MATCHED PrefixSpec_MODULE

   return ATtrue;
 }

 if (ATmatch(term, "PrefixSpec_IMPURE")) {

   // MATCHED PrefixSpec_IMPURE

   return ATtrue;
 }

 if (ATmatch(term, "PrefixSpec_ELEMENTAL")) {

   // MATCHED PrefixSpec_ELEMENTAL

   return ATtrue;
 }

 OFP_Traverse DeclarationTypeSpec;
 if (ATmatch(term, "PrefixSpec_DTS(<term>)", &DeclarationTypeSpec.term)) {

      if (ofp_traverse_DeclarationTypeSpec(DeclarationTypeSpec.term, &DeclarationTypeSpec)) {
         // MATCHED DeclarationTypeSpec
      } else return ATfalse;

   // MATCHED PrefixSpec_DTS

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1227 function-subprogram
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_FunctionSubprogram(ATerm term, pOFP_Traverse FunctionSubprogram)
{
#ifdef DEBUG_PRINT
   printf("FunctionSubprogram: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse FunctionStmt, SpecificationPart, ExecutionPart, InternalSubprogramPart, EndFunctionStmt;
 if (ATmatch(term, "FunctionSubprogram(<term>,<term>,<term>,<term>,<term>)", &FunctionStmt.term, &SpecificationPart.term, &ExecutionPart.term, &InternalSubprogramPart.term, &EndFunctionStmt.term)) {

      if (ofp_traverse_FunctionStmt(FunctionStmt.term, &FunctionStmt)) {
         // MATCHED FunctionStmt
      } else return ATfalse;

      if (ofp_traverse_SpecificationPart(SpecificationPart.term, &SpecificationPart)) {
         // MATCHED SpecificationPart
      } else return ATfalse;

      if (ofp_traverse_ExecutionPart(ExecutionPart.term, &ExecutionPart)) {
         // MATCHED ExecutionPart
      } else return ATfalse;

   if (ATmatch(InternalSubprogramPart.term, "Some(<term>)", &InternalSubprogramPart.term)) {
      if (ofp_traverse_InternalSubprogramPart(InternalSubprogramPart.term, &InternalSubprogramPart)) {
         // MATCHED InternalSubprogramPart
      } else return ATfalse;
   }

      if (ofp_traverse_EndFunctionStmt(EndFunctionStmt.term, &EndFunctionStmt)) {
         // MATCHED EndFunctionStmt
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1228 function-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_FunctionStmt(ATerm term, pOFP_Traverse FunctionStmt)
{
#ifdef DEBUG_PRINT
   printf("FunctionStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, Prefix, FunctionName, DummyArgNameList, Suffix, EOS;
 if (ATmatch(term, "FunctionStmt(<term>,<term>,<term>,<term>,<term>,<term>)", &Label.term, &Prefix.term, &FunctionName.term, &DummyArgNameList.term, &Suffix.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

   if (ATmatch(Prefix.term, "Some(<term>)", &Prefix.term)) {
      if (ofp_traverse_Prefix(Prefix.term, &Prefix)) {
         // MATCHED Prefix
      } else return ATfalse;
   }

      if (ofp_traverse_FunctionName(FunctionName.term, &FunctionName)) {
         // MATCHED FunctionName
      } else return ATfalse;

   if (ATmatch(DummyArgNameList.term, "Some(<term>)", &DummyArgNameList.term)) {
      if (ofp_traverse_DummyArgNameList(DummyArgNameList.term, &DummyArgNameList)) {
         // MATCHED DummyArgNameList
      } else return ATfalse;
   }

   if (ATmatch(Suffix.term, "Some(<term>)", &Suffix.term)) {
      if (ofp_traverse_Suffix(Suffix.term, &Suffix)) {
         // MATCHED Suffix
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1229 proc-language-binding-spec
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_ProcLanguageBindingSpec(ATerm term, pOFP_Traverse ProcLanguageBindingSpec)
{
#ifdef DEBUG_PRINT
   printf("ProcLanguageBindingSpec: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse LanguageBindingSpec;
 if (ATmatch(term, "ProcLanguageBindingSpec(<term>)", &LanguageBindingSpec.term)) {

#ifdef NOT_YET
      if (ofp_traverse_LanguageBindingSpec(LanguageBindingSpec.term, &LanguageBindingSpec)) {
         // MATCHED LanguageBindingSpec
      } else return ATfalse;
#endif

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1230 dummy-arg-name
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_DummyArgName(ATerm term, pOFP_Traverse DummyArgName)
{
#ifdef DEBUG_PRINT
   printf("DummyArgName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "DummyArgName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1231 suffix
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_Suffix(ATerm term, pOFP_Traverse Suffix)
{
#ifdef DEBUG_PRINT
   printf("Suffix: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse ResultName, ProcLanguageBindingSpec;
 if (ATmatch(term, "Suffix_RP(<term>,<term>)", &ResultName.term, &ProcLanguageBindingSpec.term)) {

      if (ofp_traverse_ResultName(ResultName.term, &ResultName)) {
         // MATCHED ResultName
      } else return ATfalse;

   if (ATmatch(ProcLanguageBindingSpec.term, "Some(<term>)", &ProcLanguageBindingSpec.term)) {
      if (ofp_traverse_ProcLanguageBindingSpec(ProcLanguageBindingSpec.term, &ProcLanguageBindingSpec)) {
         // MATCHED ProcLanguageBindingSpec
      } else return ATfalse;
   }

   // MATCHED Suffix_RP

   return ATtrue;
 }

 OFP_Traverse ProcLanguageBindingSpec1, ResultName1;
 if (ATmatch(term, "Suffix_PR(<term>,<term>)", &ProcLanguageBindingSpec1.term, &ResultName1.term)) {

      if (ofp_traverse_ProcLanguageBindingSpec(ProcLanguageBindingSpec1.term, &ProcLanguageBindingSpec1)) {
         // MATCHED ProcLanguageBindingSpec
      } else return ATfalse;

   if (ATmatch(ResultName1.term, "Some(<term>)", &ResultName1.term)) {
   if (ATmatch(ResultName1.term, "(<term>)", &ResultName1.term)) {
      if (ofp_traverse_ResultName(ResultName1.term, &ResultName1)) {
         // MATCHED ResultName
      } else return ATfalse;
   }
   }

   // MATCHED Suffix_PR

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1232 end-function-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_EndFunctionStmt(ATerm term, pOFP_Traverse EndFunctionStmt)
{
#ifdef DEBUG_PRINT
   printf("EndFunctionStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, FunctionName, EOS;
 if (ATmatch(term, "EndFunctionStmt(<term>,<term>,<term>)", &Label.term, &FunctionName.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

   if (ATmatch(FunctionName.term, "Some(<term>)", &FunctionName.term)) {
   if (ATmatch(FunctionName.term, "(Some(<term>))", &FunctionName.term)) {
      if (ofp_traverse_FunctionName(FunctionName.term, &FunctionName)) {
         // MATCHED FunctionName
      } else return ATfalse;
   }
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1233 subroutine-subprogram
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_SubroutineSubprogram(ATerm term, pOFP_Traverse SubroutineSubprogram)
{
#ifdef DEBUG_PRINT
   printf("SubroutineSubprogram: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse SubroutineStmt, SpecificationPart, ExecutionPart, InternalSubprogramPart, EndSubroutineStmt;
 if (ATmatch(term, "SubroutineSubprogram(<term>,<term>,<term>,<term>,<term>)", &SubroutineStmt.term, &SpecificationPart.term, &ExecutionPart.term, &InternalSubprogramPart.term, &EndSubroutineStmt.term)) {

      if (ofp_traverse_SubroutineStmt(SubroutineStmt.term, &SubroutineStmt)) {
         // MATCHED SubroutineStmt
      } else return ATfalse;

      if (ofp_traverse_SpecificationPart(SpecificationPart.term, &SpecificationPart)) {
         // MATCHED SpecificationPart
      } else return ATfalse;

      if (ofp_traverse_ExecutionPart(ExecutionPart.term, &ExecutionPart)) {
         // MATCHED ExecutionPart
      } else return ATfalse;

   if (ATmatch(InternalSubprogramPart.term, "Some(<term>)", &InternalSubprogramPart.term)) {
      if (ofp_traverse_InternalSubprogramPart(InternalSubprogramPart.term, &InternalSubprogramPart)) {
         // MATCHED InternalSubprogramPart
      } else return ATfalse;
   }

      if (ofp_traverse_EndSubroutineStmt(EndSubroutineStmt.term, &EndSubroutineStmt)) {
         // MATCHED EndSubroutineStmt
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1234 subroutine-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_SubroutineStmt(ATerm term, pOFP_Traverse SubroutineStmt)
{
#ifdef DEBUG_PRINT
   printf("SubroutineStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, Prefix, SubroutineName, EOS;
 if (ATmatch(term, "SubroutineStmt(<term>,<term>,<term>,<term>)", &Label.term, &Prefix.term, &SubroutineName.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

   if (ATmatch(Prefix.term, "Some(<term>)", &Prefix.term)) {
      if (ofp_traverse_Prefix(Prefix.term, &Prefix)) {
         // MATCHED Prefix
      } else return ATfalse;
   }

      if (ofp_traverse_SubroutineName(SubroutineName.term, &SubroutineName)) {
         // MATCHED SubroutineName
      } else return ATfalse;

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 OFP_Traverse Label1, Prefix1, SubroutineName1, DummyArgList, ProcLanguageBindingSpec, EOS1;
 if (ATmatch(term, "SubroutineStmt_DAL(<term>,<term>,<term>,<term>,<term>,<term>)", &Label1.term, &Prefix1.term, &SubroutineName1.term, &DummyArgList.term, &ProcLanguageBindingSpec.term, &EOS1.term)) {

   if (ATmatch(Label1.term, "Some(<term>)", &Label1.term)) {
      if (ofp_traverse_Label(Label1.term, &Label1)) {
         // MATCHED Label
      } else return ATfalse;
   }

   if (ATmatch(Prefix1.term, "Some(<term>)", &Prefix1.term)) {
      if (ofp_traverse_Prefix(Prefix1.term, &Prefix1)) {
         // MATCHED Prefix
      } else return ATfalse;
   }

      if (ofp_traverse_SubroutineName(SubroutineName1.term, &SubroutineName1)) {
         // MATCHED SubroutineName
      } else return ATfalse;

   if (ATmatch(DummyArgList.term, "Some(<term>)", &DummyArgList.term)) {
      if (ofp_traverse_DummyArgList(DummyArgList.term, &DummyArgList)) {
         // MATCHED DummyArgList
      } else return ATfalse;
   }

   if (ATmatch(ProcLanguageBindingSpec.term, "Some(<term>)", &ProcLanguageBindingSpec.term)) {
      if (ofp_traverse_ProcLanguageBindingSpec(ProcLanguageBindingSpec.term, &ProcLanguageBindingSpec)) {
         // MATCHED ProcLanguageBindingSpec
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS1.term, &EOS1)) {
         // MATCHED EOS
      } else return ATfalse;

   // MATCHED SubroutineStmt_DAL

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1235 dummy-arg
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_DummyArg(ATerm term, pOFP_Traverse DummyArg)
{
#ifdef DEBUG_PRINT
   printf("DummyArg: %s\n", ATwriteToString(term));
#endif

 if (ATmatch(term, "DummyArg_STAR")) {

   // MATCHED DummyArg_STAR

   return ATtrue;
 }

 OFP_Traverse DummyArgName;
 if (ATmatch(term, "DummyArg_DAN(<term>)", &DummyArgName.term)) {

      if (ofp_traverse_DummyArgName(DummyArgName.term, &DummyArgName)) {
         // MATCHED DummyArgName
      } else return ATfalse;

   // MATCHED DummyArg_DAN

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_DummyArgList(ATerm term, pOFP_Traverse DummyArgList)
{
#ifdef DEBUG_PRINT
   printf("DummyArgList: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse DummyArg;
 if (ATmatch(term, "DummyArgList(<term>)", &DummyArg.term)) {

   ATermList DummyArg_tail = (ATermList) ATmake("<term>", DummyArg.term);
   while (! ATisEmpty(DummyArg_tail)) {
      DummyArg.term = ATgetFirst(DummyArg_tail);
      DummyArg_tail = ATgetNext (DummyArg_tail);
      if (ofp_traverse_DummyArg(DummyArg.term, &DummyArg)) {
         // MATCHED DummyArg
      } else return ATfalse;
   }

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1236 end-subroutine-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_EndSubroutineStmt(ATerm term, pOFP_Traverse EndSubroutineStmt)
{
#ifdef DEBUG_PRINT
   printf("EndSubroutineStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, SubroutineName, EOS;
 if (ATmatch(term, "EndSubroutineStmt(<term>,<term>,<term>)", &Label.term, &SubroutineName.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

   if (ATmatch(SubroutineName.term, "Some(<term>)", &SubroutineName.term)) {
   if (ATmatch(SubroutineName.term, "(Some(<term>))", &SubroutineName.term)) {
      if (ofp_traverse_SubroutineName(SubroutineName.term, &SubroutineName)) {
         // MATCHED SubroutineName
      } else return ATfalse;
   }
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1237 separate-module-subprogram
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_SeparateModuleSubprogram(ATerm term, pOFP_Traverse SeparateModuleSubprogram)
{
#ifdef DEBUG_PRINT
   printf("SeparateModuleSubprogram: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse MpSubprogramStmt, SpecificationPart, ExecutionPart, InternalSubprogramPart, EndMpSubprogramStmt;
 if (ATmatch(term, "SeparateModuleSubprogram(<term>,<term>,<term>,<term>,<term>)", &MpSubprogramStmt.term, &SpecificationPart.term, &ExecutionPart.term, &InternalSubprogramPart.term, &EndMpSubprogramStmt.term)) {

      if (ofp_traverse_MpSubprogramStmt(MpSubprogramStmt.term, &MpSubprogramStmt)) {
         // MATCHED MpSubprogramStmt
      } else return ATfalse;

      if (ofp_traverse_SpecificationPart(SpecificationPart.term, &SpecificationPart)) {
         // MATCHED SpecificationPart
      } else return ATfalse;

      if (ofp_traverse_ExecutionPart(ExecutionPart.term, &ExecutionPart)) {
         // MATCHED ExecutionPart
      } else return ATfalse;

   if (ATmatch(InternalSubprogramPart.term, "Some(<term>)", &InternalSubprogramPart.term)) {
      if (ofp_traverse_InternalSubprogramPart(InternalSubprogramPart.term, &InternalSubprogramPart)) {
         // MATCHED InternalSubprogramPart
      } else return ATfalse;
   }

      if (ofp_traverse_EndMpSubprogramStmt(EndMpSubprogramStmt.term, &EndMpSubprogramStmt)) {
         // MATCHED EndMpSubprogramStmt
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1238 mp-subprogram-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_MpSubprogramStmt(ATerm term, pOFP_Traverse MpSubprogramStmt)
{
#ifdef DEBUG_PRINT
   printf("MpSubprogramStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, ProcedureName, EOS;
 if (ATmatch(term, "MpSubprogramStmt(<term>,<term>,<term>)", &Label.term, &ProcedureName.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_ProcedureName(ProcedureName.term, &ProcedureName)) {
         // MATCHED ProcedureName
      } else return ATfalse;

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1239 end-mp-subprogram-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_EndMpSubprogramStmt(ATerm term, pOFP_Traverse EndMpSubprogramStmt)
{
#ifdef DEBUG_PRINT
   printf("EndMpSubprogramStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, ProcedureName, EOS;
 if (ATmatch(term, "EndMpSubprogramStmt(<term>,<term>,<term>)", &Label.term, &ProcedureName.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

   if (ATmatch(ProcedureName.term, "Some(<term>)", &ProcedureName.term)) {
   if (ATmatch(ProcedureName.term, "(Some(<term>))", &ProcedureName.term)) {
      if (ofp_traverse_ProcedureName(ProcedureName.term, &ProcedureName)) {
         // MATCHED ProcedureName
      } else return ATfalse;
   }
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1240 entry-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_EntryStmt(ATerm term, pOFP_Traverse EntryStmt)
{
#ifdef DEBUG_PRINT
   printf("EntryStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, EntryName, EOS;
 if (ATmatch(term, "EntryStmt(<term>,<term>,<term>)", &Label.term, &EntryName.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_EntryName(EntryName.term, &EntryName)) {
         // MATCHED EntryName
      } else return ATfalse;

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 OFP_Traverse Label1, EntryName1, DummyArgList, Suffix, EOS1;
 if (ATmatch(term, "EntryStmt_DAL(<term>,<term>,<term>,<term>,<term>)", &Label1.term, &EntryName1.term, &DummyArgList.term, &Suffix.term, &EOS1.term)) {

   if (ATmatch(Label1.term, "Some(<term>)", &Label1.term)) {
      if (ofp_traverse_Label(Label1.term, &Label1)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_EntryName(EntryName1.term, &EntryName1)) {
         // MATCHED EntryName
      } else return ATfalse;

   if (ATmatch(DummyArgList.term, "Some(<term>)", &DummyArgList.term)) {
      if (ofp_traverse_DummyArgList(DummyArgList.term, &DummyArgList)) {
         // MATCHED DummyArgList
      } else return ATfalse;
   }

   if (ATmatch(Suffix.term, "Some(<term>)", &Suffix.term)) {
      if (ofp_traverse_Suffix(Suffix.term, &Suffix)) {
         // MATCHED Suffix
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS1.term, &EOS1)) {
         // MATCHED EOS
      } else return ATfalse;

   // MATCHED EntryStmt_DAL

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1241 return-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_ReturnStmt(ATerm term, pOFP_Traverse ReturnStmt)
{
#ifdef DEBUG_PRINT
   printf("ReturnStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, Expr, EOS;
 if (ATmatch(term, "ReturnStmt(<term>,<term>,<term>)", &Label.term, &Expr.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

   if (ATmatch(Expr.term, "Some(<term>)", &Expr.term)) {
      if (ofp_traverse_Expr(Expr.term, &Expr)) {
         // MATCHED Expr
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1242 contains-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_ContainsStmt(ATerm term, pOFP_Traverse ContainsStmt)
{
#ifdef DEBUG_PRINT
   printf("ContainsStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, EOS;
 if (ATmatch(term, "ContainsStmt(<term>,<term>)", &Label.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1243 stmt-function-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_StmtFunctionStmt(ATerm term, pOFP_Traverse StmtFunctionStmt)
{
#ifdef DEBUG_PRINT
   printf("StmtFunctionStmt: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Label, FunctionName, DummyArgNameList, Expr, EOS;
 if (ATmatch(term, "StmtFunctionStmt(<term>,<term>,<term>,<term>,<term>)", &Label.term, &FunctionName.term, &DummyArgNameList.term, &Expr.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
      } else return ATfalse;
   }

      if (ofp_traverse_FunctionName(FunctionName.term, &FunctionName)) {
         // MATCHED FunctionName
      } else return ATfalse;

   if (ATmatch(DummyArgNameList.term, "Some(<term>)", &DummyArgNameList.term)) {
      if (ofp_traverse_DummyArgNameList(DummyArgNameList.term, &DummyArgNameList)) {
         // MATCHED DummyArgNameList
      } else return ATfalse;
   }

      if (ofp_traverse_Expr(Expr.term, &Expr)) {
         // MATCHED Expr
      } else return ATfalse;

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}


/** Identifier aliases
 */

ATbool ofp_traverse_AncestorModuleName(ATerm term, pOFP_Traverse AncestorModuleName)
{
#ifdef DEBUG_PRINT
   printf("AncestorModuleName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "AncestorModuleName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ArgName(ATerm term, pOFP_Traverse ArgName)
{
#ifdef DEBUG_PRINT
   printf("ArgName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "ArgName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_AssociateConstructName(ATerm term, pOFP_Traverse AssociateConstructName)
{
#ifdef DEBUG_PRINT
   printf("AssociateConstructName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "AssociateConstructName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_AssociateName(ATerm term, pOFP_Traverse AssociateName)
{
#ifdef DEBUG_PRINT
   printf("AssociateName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "AssociateName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_BindingName(ATerm term, pOFP_Traverse BindingName)
{
#ifdef DEBUG_PRINT
   printf("BindingName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "BindingName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_BlockConstructName(ATerm term, pOFP_Traverse BlockConstructName)
{
#ifdef DEBUG_PRINT
   printf("BlockConstructName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "BlockConstructName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_BlockDataName(ATerm term, pOFP_Traverse BlockDataName)
{
#ifdef DEBUG_PRINT
   printf("BlockDataName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "BlockDataName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_CaseConstructName(ATerm term, pOFP_Traverse CaseConstructName)
{
#ifdef DEBUG_PRINT
   printf("CaseConstructName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "CaseConstructName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ComponentName(ATerm term, pOFP_Traverse ComponentName)
{
#ifdef DEBUG_PRINT
   printf("ComponentName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "ComponentName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ConstructName(ATerm term, pOFP_Traverse ConstructName)
{
#ifdef DEBUG_PRINT
   printf("ConstructName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "ConstructName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_CriticalConstructName(ATerm term, pOFP_Traverse CriticalConstructName)
{
#ifdef DEBUG_PRINT
   printf("CriticalConstructName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "CriticalConstructName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_DoConstructName(ATerm term, pOFP_Traverse DoConstructName)
{
#ifdef DEBUG_PRINT
   printf("DoConstructName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "DoConstructName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_IfConstructName(ATerm term, pOFP_Traverse IfConstructName)
{
#ifdef DEBUG_PRINT
   printf("IfConstructName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "IfConstructName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_EntryName(ATerm term, pOFP_Traverse EntryName)
{
#ifdef DEBUG_PRINT
   printf("EntryName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "EntryName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ExternalName(ATerm term, pOFP_Traverse ExternalName)
{
#ifdef DEBUG_PRINT
   printf("ExternalName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "ExternalName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_FinalSubroutineName(ATerm term, pOFP_Traverse FinalSubroutineName)
{
#ifdef DEBUG_PRINT
   printf("FinalSubroutineName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "FinalSubroutineName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_FunctionName(ATerm term, pOFP_Traverse FunctionName)
{
#ifdef DEBUG_PRINT
   printf("FunctionName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "FunctionName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_GenericName(ATerm term, pOFP_Traverse GenericName)
{
#ifdef DEBUG_PRINT
   printf("GenericName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "GenericName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ImportName(ATerm term, pOFP_Traverse ImportName)
{
#ifdef DEBUG_PRINT
   printf("ImportName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "ImportName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_IntrinsicProcedureName(ATerm term, pOFP_Traverse IntrinsicProcedureName)
{
#ifdef DEBUG_PRINT
   printf("IntrinsicProcedureName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "IntrinsicProcedureName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_LocalName(ATerm term, pOFP_Traverse LocalName)
{
#ifdef DEBUG_PRINT
   printf("LocalName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "LocalName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ModuleName(ATerm term, pOFP_Traverse ModuleName)
{
#ifdef DEBUG_PRINT
   printf("ModuleName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "ModuleName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_Name(ATerm term, pOFP_Traverse Name)
{
#ifdef DEBUG_PRINT
   printf("Name: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "Name(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_NamelistGroupName(ATerm term, pOFP_Traverse NamelistGroupName)
{
#ifdef DEBUG_PRINT
   printf("NamelistGroupName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "NamelistGroupName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ObjectName(ATerm term, pOFP_Traverse ObjectName)
{
#ifdef DEBUG_PRINT
   printf("ObjectName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "ObjectName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ParentSubmoduleName(ATerm term, pOFP_Traverse ParentSubmoduleName)
{
#ifdef DEBUG_PRINT
   printf("ParentSubmoduleName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "ParentSubmoduleName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ParentTypeName(ATerm term, pOFP_Traverse ParentTypeName)
{
#ifdef DEBUG_PRINT
   printf("ParentTypeName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "ParentTypeName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_PartName(ATerm term, pOFP_Traverse PartName)
{
#ifdef DEBUG_PRINT
   printf("PartName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "PartName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ProcedureEntityName(ATerm term, pOFP_Traverse ProcedureEntityName)
{
#ifdef DEBUG_PRINT
   printf("ProcedureEntityName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "ProcedureEntityName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ProcedureName(ATerm term, pOFP_Traverse ProcedureName)
{
#ifdef DEBUG_PRINT
   printf("ProcedureName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "ProcedureName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ProgramName(ATerm term, pOFP_Traverse ProgramName)
{
#ifdef DEBUG_PRINT
   printf("ProgramName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "ProgramName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ResultName(ATerm term, pOFP_Traverse ResultName)
{
#ifdef DEBUG_PRINT
   printf("ResultName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "ResultName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ScalarIntConstantName(ATerm term, pOFP_Traverse ScalarIntConstantName)
{
#ifdef DEBUG_PRINT
   printf("ScalarIntConstantName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "ScalarIntConstantName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ScalarIntVariableName(ATerm term, pOFP_Traverse ScalarIntVariableName)
{
#ifdef DEBUG_PRINT
   printf("ScalarIntVariableName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "ScalarIntVariableName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_SelectConstructName(ATerm term, pOFP_Traverse SelectConstructName)
{
#ifdef DEBUG_PRINT
   printf("SelectConstructName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "SelectConstructName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_SubmoduleName(ATerm term, pOFP_Traverse SubmoduleName)
{
#ifdef DEBUG_PRINT
   printf("SubmoduleName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "SubmoduleName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_SubroutineName(ATerm term, pOFP_Traverse SubroutineName)
{
#ifdef DEBUG_PRINT
   printf("SubroutineName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "SubroutineName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_TypeName(ATerm term, pOFP_Traverse TypeName)
{
#ifdef DEBUG_PRINT
   printf("TypeName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "TypeName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_TypeParamName(ATerm term, pOFP_Traverse TypeParamName)
{
#ifdef DEBUG_PRINT
   printf("TypeParamName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "TypeParamName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_UseName(ATerm term, pOFP_Traverse UseName)
{
#ifdef DEBUG_PRINT
   printf("UseName: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse Ident;
 if (ATmatch(term, "UseName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
      } else return ATfalse;

   return ATtrue;
 }

 return ATfalse;
}


/** Lists
 */

ATbool ofp_traverse_DummyArgNameList(ATerm term, pOFP_Traverse DummyArgNameList)
{
#ifdef DEBUG_PRINT
   printf("DummyArgNameList: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse DummyArgName;
 if (ATmatch(term, "DummyArgNameList(<term>)", &DummyArgName.term)) {

   ATermList DummyArgName_tail = (ATermList) ATmake("<term>", DummyArgName.term);
   while (! ATisEmpty(DummyArgName_tail)) {
      DummyArgName.term = ATgetFirst(DummyArgName_tail);
      DummyArgName_tail = ATgetNext (DummyArgName_tail);
      if (ofp_traverse_DummyArgName(DummyArgName.term, &DummyArgName)) {
         // MATCHED DummyArgName
      } else return ATfalse;
   }

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ExternalNameList(ATerm term, pOFP_Traverse ExternalNameList)
{
#ifdef DEBUG_PRINT
   printf("ExternalNameList: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse ExternalName;
 if (ATmatch(term, "ExternalNameList(<term>)", &ExternalName.term)) {

   ATermList ExternalName_tail = (ATermList) ATmake("<term>", ExternalName.term);
   while (! ATisEmpty(ExternalName_tail)) {
      ExternalName.term = ATgetFirst(ExternalName_tail);
      ExternalName_tail = ATgetNext (ExternalName_tail);
      if (ofp_traverse_ExternalName(ExternalName.term, &ExternalName)) {
         // MATCHED ExternalName
      } else return ATfalse;
   }

   return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_LabelList(ATerm term, pOFP_Traverse LabelList)
{
#ifdef DEBUG_PRINT
   printf("LabelList: %s\n", ATwriteToString(term));
#endif

 OFP_Traverse LblRef;
 if (ATmatch(term, "LabelList(<term>)", &LblRef.term)) {

   ATermList LblRef_tail = (ATermList) ATmake("<term>", LblRef.term);
   while (! ATisEmpty(LblRef_tail)) {
      LblRef.term = ATgetFirst(LblRef_tail);
      LblRef_tail = ATgetNext (LblRef_tail);
#ifdef NOT_YET
      if (ofp_traverse_LblRef(LblRef.term, &LblRef)) {
         // MATCHED LblRef
      } else return ATfalse;
#endif
   }

   return ATtrue;
 }

 return ATfalse;
}

