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

 ATbool matched = ATfalse;
 OFP_Traverse StartCommentBlock, ProgramUnit;
 if (ATmatch(term, "Program(<term>,<term>)", &StartCommentBlock.term, &ProgramUnit.term)) {

   if (ATmatch(StartCommentBlock.term, "Some(<term>)", &StartCommentBlock.term)) {
      if (ofp_traverse_StartCommentBlock(StartCommentBlock.term, &StartCommentBlock)) {
         // MATCHED StartCommentBlock
         matched = ATtrue;
      } else return ATfalse;
   }

   ATermList ProgramUnit_tail = (ATermList) ATmake("<term>", ProgramUnit.term);
   if (ATisEmpty(ProgramUnit_tail)) matched = ATtrue;
   while (! ATisEmpty(ProgramUnit_tail)) {
      ProgramUnit.term = ATgetFirst(ProgramUnit_tail);
      ProgramUnit_tail = ATgetNext (ProgramUnit_tail);
      if (ofp_traverse_ProgramUnit(ProgramUnit.term, &ProgramUnit)) {
         // MATCHED ProgramUnit
         matched = ATtrue;
      } else return ATfalse;
   }

   if (matched) return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R202 program-unit
//----------------------------------------------------------------------------------------
#ifdef USE_FINISHED
ATbool ofp_traverse_ProgramUnit(ATerm term, pOFP_Traverse ProgramUnit)
{
#ifdef DEBUG_PRINT
   printf("\nProgramUnit: %s\n", ATwriteToString(term));
#endif

 ATbool matched = ATfalse;
 OFP_Traverse BlockData;
 if (ATmatch(term, "ProgramUnit(<term>)", &BlockData.term)) {

      if (ofp_traverse_BlockData(BlockData.term, &BlockData)) {
         // MATCHED BlockData
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
 }

 OFP_Traverse Submodule;
 if (ATmatch(term, "ProgramUnit(<term>)", &Submodule.term)) {

#ifdef NOT_YET
      if (ofp_traverse_Submodule(Submodule.term, &Submodule)) {
         // MATCHED Submodule
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse Module;
 if (ATmatch(term, "ProgramUnit(<term>)", &Module.term)) {

#ifdef NOT_YET
      if (ofp_traverse_Module(Module.term, &Module)) {
         // MATCHED Module
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse ExternalSubprogram;
 if (ATmatch(term, "ProgramUnit(<term>)", &ExternalSubprogram.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ExternalSubprogram(ExternalSubprogram.term, &ExternalSubprogram)) {
         // MATCHED ExternalSubprogram
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse MainProgram;
 if (ATmatch(term, "ProgramUnit(<term>)", &MainProgram.term)) {

      if (ofp_traverse_MainProgram(MainProgram.term, &MainProgram)) {
         // MATCHED MainProgram
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
 }

 return ATfalse;
}
#endif

//========================================================================================
// R203 external-subprogram
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_ExternalSubprogram(ATerm term, pOFP_Traverse ExternalSubprogram)
{
#ifdef DEBUG_PRINT
   printf("ExternalSubprogram: %s\n", ATwriteToString(term));
#endif

 ATbool matched = ATfalse;

 OFP_Traverse SubroutineSubprogram;
 if (ATmatch(term, "ExternalSubprogram(<term>)", &SubroutineSubprogram.term)) {

#ifdef NOT_YET
      if (ofp_traverse_SubroutineSubprogram(SubroutineSubprogram.term, &SubroutineSubprogram)) {
         // MATCHED SubroutineSubprogram
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse FunctionSubprogram;
 if (ATmatch(term, "ExternalSubprogram(<term>)", &FunctionSubprogram.term)) {

#ifdef NOT_YET
      if (ofp_traverse_FunctionSubprogram(FunctionSubprogram.term, &FunctionSubprogram)) {
         // MATCHED FunctionSubprogram
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
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

 ATbool matched = ATfalse;
 OFP_Traverse UseStmt, ImportStmt, ImplicitPart, DeclarationConstruct;
 if (ATmatch(term, "SpecificationPart(<term>,<term>,<term>,<term>)", &UseStmt.term, &ImportStmt.term, &ImplicitPart.term, &DeclarationConstruct.term)) {

   ATermList UseStmt_tail = (ATermList) ATmake("<term>", UseStmt.term);
   if (ATisEmpty(UseStmt_tail)) matched = ATtrue;
   while (! ATisEmpty(UseStmt_tail)) {
      UseStmt.term = ATgetFirst(UseStmt_tail);
      UseStmt_tail = ATgetNext (UseStmt_tail);
      if (ofp_traverse_UseStmt(UseStmt.term, &UseStmt)) {
         // MATCHED UseStmt
         matched = ATtrue;
      } else return ATfalse;
   }

   ATermList ImportStmt_tail = (ATermList) ATmake("<term>", ImportStmt.term);
   if (ATisEmpty(ImportStmt_tail)) matched = ATtrue;
   while (! ATisEmpty(ImportStmt_tail)) {
      ImportStmt.term = ATgetFirst(ImportStmt_tail);
      ImportStmt_tail = ATgetNext (ImportStmt_tail);
#ifdef NOT_YET
      if (ofp_traverse_ImportStmt(ImportStmt.term, &ImportStmt)) {
         // MATCHED ImportStmt
         matched = ATtrue;
      } else return ATfalse;
#endif
   }

   if (ATmatch(ImplicitPart.term, "Some(<term>)", &ImplicitPart.term)) {
      if (ofp_traverse_ImplicitPart(ImplicitPart.term, &ImplicitPart)) {
         // MATCHED ImplicitPart
         matched = ATtrue;
      } else return ATfalse;
   }

   ATermList DeclarationConstruct_tail = (ATermList) ATmake("<term>", DeclarationConstruct.term);
   if (ATisEmpty(DeclarationConstruct_tail)) matched = ATtrue;
   while (! ATisEmpty(DeclarationConstruct_tail)) {
      DeclarationConstruct.term = ATgetFirst(DeclarationConstruct_tail);
      DeclarationConstruct_tail = ATgetNext (DeclarationConstruct_tail);
      if (ofp_traverse_DeclarationConstruct(DeclarationConstruct.term, &DeclarationConstruct)) {
         // MATCHED DeclarationConstruct
         matched = ATtrue;
      } else return ATfalse;
   }

   if (matched) return ATtrue;
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

 ATbool matched = ATfalse;

 OFP_Traverse ImplicitPartStmt, ImplicitStmt;
 if (ATmatch(term, "ImplicitPart(<term>,<term>)", &ImplicitPartStmt.term, &ImplicitStmt.term)) {

   ATermList ImplicitPartStmt_tail = (ATermList) ATmake("<term>", ImplicitPartStmt.term);
   if (ATisEmpty(ImplicitPartStmt_tail)) matched = ATtrue;
   while (! ATisEmpty(ImplicitPartStmt_tail)) {
      ImplicitPartStmt.term = ATgetFirst(ImplicitPartStmt_tail);
      ImplicitPartStmt_tail = ATgetNext (ImplicitPartStmt_tail);
      if (ofp_traverse_ImplicitPartStmt(ImplicitPartStmt.term, &ImplicitPartStmt)) {
         // MATCHED ImplicitPartStmt
         matched = ATtrue;
      } else return ATfalse;
   }

#ifdef NOT_YET
      if (ofp_traverse_ImplicitStmt(ImplicitStmt.term, &ImplicitStmt)) {
         // MATCHED ImplicitStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
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

 ATbool matched = ATfalse;

 OFP_Traverse EntryStmt;
 if (ATmatch(term, "ImplicitPartStmt(<term>)", &EntryStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_EntryStmt(EntryStmt.term, &EntryStmt)) {
         // MATCHED EntryStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse FormatStmt;
 if (ATmatch(term, "ImplicitPartStmt(<term>)", &FormatStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_FormatStmt(FormatStmt.term, &FormatStmt)) {
         // MATCHED FormatStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse ParameterStmt;
 if (ATmatch(term, "ImplicitPartStmt(<term>)", &ParameterStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ParameterStmt(ParameterStmt.term, &ParameterStmt)) {
         // MATCHED ParameterStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse ImplicitStmt;
 if (ATmatch(term, "ImplicitPartStmt(<term>)", &ImplicitStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ImplicitStmt(ImplicitStmt.term, &ImplicitStmt)) {
         // MATCHED ImplicitStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
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

 ATbool matched = ATfalse;
 OFP_Traverse StmtFunctionStmt;
 if (ATmatch(term, "DeclarationConstruct(<term>)", &StmtFunctionStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_StmtFunctionStmt(StmtFunctionStmt.term, &StmtFunctionStmt)) {
         // MATCHED StmtFunctionStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse TypeDeclarationStmt;
 if (ATmatch(term, "DeclarationConstruct(<term>)", &TypeDeclarationStmt.term)) {

      if (ofp_traverse_TypeDeclarationStmt(TypeDeclarationStmt.term, &TypeDeclarationStmt)) {
         // MATCHED TypeDeclarationStmt
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
 }

 OFP_Traverse OtherSpecificationStmt;
 if (ATmatch(term, "DeclarationConstruct(<term>)", &OtherSpecificationStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_OtherSpecificationStmt(OtherSpecificationStmt.term, &OtherSpecificationStmt)) {
         // MATCHED OtherSpecificationStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse ProcedureDeclarationStmt;
 if (ATmatch(term, "DeclarationConstruct(<term>)", &ProcedureDeclarationStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ProcedureDeclarationStmt(ProcedureDeclarationStmt.term, &ProcedureDeclarationStmt)) {
         // MATCHED ProcedureDeclarationStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse ParameterStmt;
 if (ATmatch(term, "DeclarationConstruct(<term>)", &ParameterStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ParameterStmt(ParameterStmt.term, &ParameterStmt)) {
         // MATCHED ParameterStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse InterfaceBlock;
 if (ATmatch(term, "DeclarationConstruct(<term>)", &InterfaceBlock.term)) {

#ifdef NOT_YET
      if (ofp_traverse_InterfaceBlock(InterfaceBlock.term, &InterfaceBlock)) {
         // MATCHED InterfaceBlock
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse FormatStmt;
 if (ATmatch(term, "DeclarationConstruct(<term>)", &FormatStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_FormatStmt(FormatStmt.term, &FormatStmt)) {
         // MATCHED FormatStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse EnumDef;
 if (ATmatch(term, "DeclarationConstruct(<term>)", &EnumDef.term)) {

#ifdef NOT_YET
      if (ofp_traverse_EnumDef(EnumDef.term, &EnumDef)) {
         // MATCHED EnumDef
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse EntryStmt;
 if (ATmatch(term, "DeclarationConstruct(<term>)", &EntryStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_EntryStmt(EntryStmt.term, &EntryStmt)) {
         // MATCHED EntryStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse DerivedTypeDef;
 if (ATmatch(term, "DeclarationConstruct(<term>)", &DerivedTypeDef.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DerivedTypeDef(DerivedTypeDef.term, &DerivedTypeDef)) {
         // MATCHED DerivedTypeDef
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 return ATfalse;
}

//========================================================================================      
// R208 execution-part
//----------------------------------------------------------------------------------------      
ATbool ofp_traverse_ExecutionPart(ATerm term, pOFP_Traverse ExecutionPart)
{
#ifdef DEBUG_PRINT
   printf("ExecutionPart: %s\n", ATwriteToString(term));
#endif

 ATbool matched = ATfalse;

 OFP_Traverse ExecutionPartConstruct;
 if (ATmatch(term, "ExecutionPart(<term>)", &ExecutionPartConstruct.term)) {

   ATermList ExecutionPartConstruct_tail = (ATermList) ATmake("<term>", ExecutionPartConstruct.term);
   if (ATisEmpty(ExecutionPartConstruct_tail)) matched = ATtrue;
   while (! ATisEmpty(ExecutionPartConstruct_tail)) {
      ExecutionPartConstruct.term = ATgetFirst(ExecutionPartConstruct_tail);
      ExecutionPartConstruct_tail = ATgetNext (ExecutionPartConstruct_tail);
      if (ofp_traverse_ExecutionPartConstruct(ExecutionPartConstruct.term, &ExecutionPartConstruct)) {
         // MATCHED ExecutionPartConstruct
         matched = ATtrue;
      } else return ATfalse;
   }

   if (matched) return ATtrue;
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

 ATbool matched = ATfalse;

 OFP_Traverse DataStmt;
 if (ATmatch(term, "ExecutionPartConstruct(<term>)", &DataStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DataStmt(DataStmt.term, &DataStmt)) {
         // MATCHED DataStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse EntryStmt;
 if (ATmatch(term, "ExecutionPartConstruct(<term>)", &EntryStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_EntryStmt(EntryStmt.term, &EntryStmt)) {
         // MATCHED EntryStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse FormatStmt;
 if (ATmatch(term, "ExecutionPartConstruct(<term>)", &FormatStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_FormatStmt(FormatStmt.term, &FormatStmt)) {
         // MATCHED FormatStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse ExecutableConstruct;
 if (ATmatch(term, "ExecutionPartConstruct(<term>)", &ExecutableConstruct.term)) {

      if (ofp_traverse_ExecutableConstruct(ExecutableConstruct.term, &ExecutableConstruct)) {
         // MATCHED ExecutableConstruct
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
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

 ATbool matched = ATfalse;

 OFP_Traverse ContainsStmt, InternalSubprogram;
 if (ATmatch(term, "InternalSubprogramPart(<term>,<term>)", &ContainsStmt.term, &InternalSubprogram.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ContainsStmt(ContainsStmt.term, &ContainsStmt)) {
         // MATCHED ContainsStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   ATermList InternalSubprogram_tail = (ATermList) ATmake("<term>", InternalSubprogram.term);
   if (ATisEmpty(InternalSubprogram_tail)) matched = ATtrue;
   while (! ATisEmpty(InternalSubprogram_tail)) {
      InternalSubprogram.term = ATgetFirst(InternalSubprogram_tail);
      InternalSubprogram_tail = ATgetNext (InternalSubprogram_tail);
#ifdef NOT_YET
      if (ofp_traverse_InternalSubprogram(InternalSubprogram.term, &InternalSubprogram)) {
         // MATCHED InternalSubprogram
         matched = ATtrue;
      } else return ATfalse;
#endif
   }

   if (matched) return ATtrue;
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

 ATbool matched = ATfalse;

 OFP_Traverse SubroutineSubprogram;
 if (ATmatch(term, "InternalSubprogram(<term>)", &SubroutineSubprogram.term)) {

#ifdef NOT_YET
      if (ofp_traverse_SubroutineSubprogram(SubroutineSubprogram.term, &SubroutineSubprogram)) {
         // MATCHED SubroutineSubprogram
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse FunctionSubprogram;
 if (ATmatch(term, "InternalSubprogram(<term>)", &FunctionSubprogram.term)) {

#ifdef NOT_YET
      if (ofp_traverse_FunctionSubprogram(FunctionSubprogram.term, &FunctionSubprogram)) {
         // MATCHED FunctionSubprogram
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
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

 ATbool matched = ATfalse;

 OFP_Traverse ValueStmt;
 if (ATmatch(term, "OtherSpecificationStmt(<term>)", &ValueStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ValueStmt(ValueStmt.term, &ValueStmt)) {
         // MATCHED ValueStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse VolatileStmt;
 if (ATmatch(term, "OtherSpecificationStmt(<term>)", &VolatileStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_VolatileStmt(VolatileStmt.term, &VolatileStmt)) {
         // MATCHED VolatileStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse TargetStmt;
 if (ATmatch(term, "OtherSpecificationStmt(<term>)", &TargetStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_TargetStmt(TargetStmt.term, &TargetStmt)) {
         // MATCHED TargetStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse SaveStmt;
 if (ATmatch(term, "OtherSpecificationStmt(<term>)", &SaveStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_SaveStmt(SaveStmt.term, &SaveStmt)) {
         // MATCHED SaveStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse ProtectedStmt;
 if (ATmatch(term, "OtherSpecificationStmt(<term>)", &ProtectedStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ProtectedStmt(ProtectedStmt.term, &ProtectedStmt)) {
         // MATCHED ProtectedStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse PointerStmt;
 if (ATmatch(term, "OtherSpecificationStmt(<term>)", &PointerStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_PointerStmt(PointerStmt.term, &PointerStmt)) {
         // MATCHED PointerStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse OptionalStmt;
 if (ATmatch(term, "OtherSpecificationStmt(<term>)", &OptionalStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_OptionalStmt(OptionalStmt.term, &OptionalStmt)) {
         // MATCHED OptionalStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse NamelistStmt;
 if (ATmatch(term, "OtherSpecificationStmt(<term>)", &NamelistStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_NamelistStmt(NamelistStmt.term, &NamelistStmt)) {
         // MATCHED NamelistStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse IntrinsicStmt;
 if (ATmatch(term, "OtherSpecificationStmt(<term>)", &IntrinsicStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_IntrinsicStmt(IntrinsicStmt.term, &IntrinsicStmt)) {
         // MATCHED IntrinsicStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse IntentStmt;
 if (ATmatch(term, "OtherSpecificationStmt(<term>)", &IntentStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_IntentStmt(IntentStmt.term, &IntentStmt)) {
         // MATCHED IntentStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse ExternalStmt;
 if (ATmatch(term, "OtherSpecificationStmt(<term>)", &ExternalStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ExternalStmt(ExternalStmt.term, &ExternalStmt)) {
         // MATCHED ExternalStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse EquivalenceStmt;
 if (ATmatch(term, "OtherSpecificationStmt(<term>)", &EquivalenceStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_EquivalenceStmt(EquivalenceStmt.term, &EquivalenceStmt)) {
         // MATCHED EquivalenceStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse DimensionStmt;
 if (ATmatch(term, "OtherSpecificationStmt(<term>)", &DimensionStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DimensionStmt(DimensionStmt.term, &DimensionStmt)) {
         // MATCHED DimensionStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse DataStmt;
 if (ATmatch(term, "OtherSpecificationStmt(<term>)", &DataStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DataStmt(DataStmt.term, &DataStmt)) {
         // MATCHED DataStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse CommonStmt;
 if (ATmatch(term, "OtherSpecificationStmt(<term>)", &CommonStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_CommonStmt(CommonStmt.term, &CommonStmt)) {
         // MATCHED CommonStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse ContiguousStmt;
 if (ATmatch(term, "OtherSpecificationStmt(<term>)", &ContiguousStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ContiguousStmt(ContiguousStmt.term, &ContiguousStmt)) {
         // MATCHED ContiguousStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse CodimensionStmt;
 if (ATmatch(term, "OtherSpecificationStmt(<term>)", &CodimensionStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_CodimensionStmt(CodimensionStmt.term, &CodimensionStmt)) {
         // MATCHED CodimensionStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse BindStmt;
 if (ATmatch(term, "OtherSpecificationStmt(<term>)", &BindStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_BindStmt(BindStmt.term, &BindStmt)) {
         // MATCHED BindStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse AsynchronousStmt;
 if (ATmatch(term, "OtherSpecificationStmt(<term>)", &AsynchronousStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_AsynchronousStmt(AsynchronousStmt.term, &AsynchronousStmt)) {
         // MATCHED AsynchronousStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse AllocatableStmt;
 if (ATmatch(term, "OtherSpecificationStmt(<term>)", &AllocatableStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_AllocatableStmt(AllocatableStmt.term, &AllocatableStmt)) {
         // MATCHED AllocatableStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse AccessStmt;
 if (ATmatch(term, "OtherSpecificationStmt(<term>)", &AccessStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_AccessStmt(AccessStmt.term, &AccessStmt)) {
         // MATCHED AccessStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
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

 ATbool matched = ATfalse;

 OFP_Traverse WhereConstruct;
 if (ATmatch(term, "ExecutableConstruct(<term>)", &WhereConstruct.term)) {

#ifdef NOT_YET
      if (ofp_traverse_WhereConstruct(WhereConstruct.term, &WhereConstruct)) {
         // MATCHED WhereConstruct
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse SelectTypeConstruct;
 if (ATmatch(term, "ExecutableConstruct(<term>)", &SelectTypeConstruct.term)) {

#ifdef NOT_YET
      if (ofp_traverse_SelectTypeConstruct(SelectTypeConstruct.term, &SelectTypeConstruct)) {
         // MATCHED SelectTypeConstruct
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse IfConstruct;
 if (ATmatch(term, "ExecutableConstruct(<term>)", &IfConstruct.term)) {

#ifdef NOT_YET
      if (ofp_traverse_IfConstruct(IfConstruct.term, &IfConstruct)) {
         // MATCHED IfConstruct
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse ForallConstruct;
 if (ATmatch(term, "ExecutableConstruct(<term>)", &ForallConstruct.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ForallConstruct(ForallConstruct.term, &ForallConstruct)) {
         // MATCHED ForallConstruct
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse CriticalConstruct;
 if (ATmatch(term, "ExecutableConstruct(<term>)", &CriticalConstruct.term)) {

#ifdef NOT_YET
      if (ofp_traverse_CriticalConstruct(CriticalConstruct.term, &CriticalConstruct)) {
         // MATCHED CriticalConstruct
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse CaseConstruct;
 if (ATmatch(term, "ExecutableConstruct(<term>)", &CaseConstruct.term)) {

#ifdef NOT_YET
      if (ofp_traverse_CaseConstruct(CaseConstruct.term, &CaseConstruct)) {
         // MATCHED CaseConstruct
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse BlockConstruct;
 if (ATmatch(term, "ExecutableConstruct(<term>)", &BlockConstruct.term)) {

#ifdef NOT_YET
      if (ofp_traverse_BlockConstruct(BlockConstruct.term, &BlockConstruct)) {
         // MATCHED BlockConstruct
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse AssociateConstruct;
 if (ATmatch(term, "ExecutableConstruct(<term>)", &AssociateConstruct.term)) {

#ifdef NOT_YET
      if (ofp_traverse_AssociateConstruct(AssociateConstruct.term, &AssociateConstruct)) {
         // MATCHED AssociateConstruct
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse ActionStmt;
 if (ATmatch(term, "ExecutableConstruct(<term>)", &ActionStmt.term)) {

      if (ofp_traverse_ActionStmt(ActionStmt.term, &ActionStmt)) {
         // MATCHED ActionStmt
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
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

 ATbool matched = ATfalse;

 OFP_Traverse EndDoStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &EndDoStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_EndDoStmt(EndDoStmt.term, &EndDoStmt)) {
         // MATCHED EndDoStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse NonlabelDoStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &NonlabelDoStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_NonlabelDoStmt(NonlabelDoStmt.term, &NonlabelDoStmt)) {
         // MATCHED NonlabelDoStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse LabelDoStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &LabelDoStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_LabelDoStmt(LabelDoStmt.term, &LabelDoStmt)) {
         // MATCHED LabelDoStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse ComputedGotoStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &ComputedGotoStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ComputedGotoStmt(ComputedGotoStmt.term, &ComputedGotoStmt)) {
         // MATCHED ComputedGotoStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse ArithmeticIfStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &ArithmeticIfStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ArithmeticIfStmt(ArithmeticIfStmt.term, &ArithmeticIfStmt)) {
         // MATCHED ArithmeticIfStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse WriteStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &WriteStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_WriteStmt(WriteStmt.term, &WriteStmt)) {
         // MATCHED WriteStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse WhereStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &WhereStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_WhereStmt(WhereStmt.term, &WhereStmt)) {
         // MATCHED WhereStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse WaitStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &WaitStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_WaitStmt(WaitStmt.term, &WaitStmt)) {
         // MATCHED WaitStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse UnlockStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &UnlockStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_UnlockStmt(UnlockStmt.term, &UnlockStmt)) {
         // MATCHED UnlockStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse SyncMemoryStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &SyncMemoryStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_SyncMemoryStmt(SyncMemoryStmt.term, &SyncMemoryStmt)) {
         // MATCHED SyncMemoryStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse SyncImagesStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &SyncImagesStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_SyncImagesStmt(SyncImagesStmt.term, &SyncImagesStmt)) {
         // MATCHED SyncImagesStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse SyncAllStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &SyncAllStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_SyncAllStmt(SyncAllStmt.term, &SyncAllStmt)) {
         // MATCHED SyncAllStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse StopStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &StopStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_StopStmt(StopStmt.term, &StopStmt)) {
         // MATCHED StopStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse RewindStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &RewindStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_RewindStmt(RewindStmt.term, &RewindStmt)) {
         // MATCHED RewindStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse ReturnStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &ReturnStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ReturnStmt(ReturnStmt.term, &ReturnStmt)) {
         // MATCHED ReturnStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse ReadStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &ReadStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ReadStmt(ReadStmt.term, &ReadStmt)) {
         // MATCHED ReadStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse PrintStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &PrintStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_PrintStmt(PrintStmt.term, &PrintStmt)) {
         // MATCHED PrintStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse PointerAssignmentStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &PointerAssignmentStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_PointerAssignmentStmt(PointerAssignmentStmt.term, &PointerAssignmentStmt)) {
         // MATCHED PointerAssignmentStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse OpenStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &OpenStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_OpenStmt(OpenStmt.term, &OpenStmt)) {
         // MATCHED OpenStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse NullifyStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &NullifyStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_NullifyStmt(NullifyStmt.term, &NullifyStmt)) {
         // MATCHED NullifyStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse LockStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &LockStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_LockStmt(LockStmt.term, &LockStmt)) {
         // MATCHED LockStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse InquireStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &InquireStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_InquireStmt(InquireStmt.term, &InquireStmt)) {
         // MATCHED InquireStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse IfStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &IfStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_IfStmt(IfStmt.term, &IfStmt)) {
         // MATCHED IfStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse GotoStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &GotoStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_GotoStmt(GotoStmt.term, &GotoStmt)) {
         // MATCHED GotoStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse ForallStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &ForallStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ForallStmt(ForallStmt.term, &ForallStmt)) {
         // MATCHED ForallStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse FlushStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &FlushStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_FlushStmt(FlushStmt.term, &FlushStmt)) {
         // MATCHED FlushStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse ExitStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &ExitStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ExitStmt(ExitStmt.term, &ExitStmt)) {
         // MATCHED ExitStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse ErrorStopStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &ErrorStopStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ErrorStopStmt(ErrorStopStmt.term, &ErrorStopStmt)) {
         // MATCHED ErrorStopStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse EndfileStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &EndfileStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_EndfileStmt(EndfileStmt.term, &EndfileStmt)) {
         // MATCHED EndfileStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse EndSubroutineStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &EndSubroutineStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_EndSubroutineStmt(EndSubroutineStmt.term, &EndSubroutineStmt)) {
         // MATCHED EndSubroutineStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse EndProgramStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &EndProgramStmt.term)) {

      if (ofp_traverse_EndProgramStmt(EndProgramStmt.term, &EndProgramStmt)) {
         // MATCHED EndProgramStmt
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
 }

 OFP_Traverse EndMpSubprogramStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &EndMpSubprogramStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_EndMpSubprogramStmt(EndMpSubprogramStmt.term, &EndMpSubprogramStmt)) {
         // MATCHED EndMpSubprogramStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse EndFunctionStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &EndFunctionStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_EndFunctionStmt(EndFunctionStmt.term, &EndFunctionStmt)) {
         // MATCHED EndFunctionStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse DeallocateStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &DeallocateStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DeallocateStmt(DeallocateStmt.term, &DeallocateStmt)) {
         // MATCHED DeallocateStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse CycleStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &CycleStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_CycleStmt(CycleStmt.term, &CycleStmt)) {
         // MATCHED CycleStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse ContinueStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &ContinueStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ContinueStmt(ContinueStmt.term, &ContinueStmt)) {
         // MATCHED ContinueStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse CloseStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &CloseStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_CloseStmt(CloseStmt.term, &CloseStmt)) {
         // MATCHED CloseStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse CallStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &CallStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_CallStmt(CallStmt.term, &CallStmt)) {
         // MATCHED CallStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse BackspaceStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &BackspaceStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_BackspaceStmt(BackspaceStmt.term, &BackspaceStmt)) {
         // MATCHED BackspaceStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse AssignmentStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &AssignmentStmt.term)) {

      if (ofp_traverse_AssignmentStmt(AssignmentStmt.term, &AssignmentStmt)) {
         // MATCHED AssignmentStmt
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
 }

 OFP_Traverse AllocateStmt;
 if (ATmatch(term, "ActionStmt(<term>)", &AllocateStmt.term)) {

#ifdef NOT_YET
      if (ofp_traverse_AllocateStmt(AllocateStmt.term, &AllocateStmt)) {
         // MATCHED AllocateStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
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

 ATbool matched = ATfalse;

 OFP_Traverse Name;
 if (ATmatch(term, "Keyword(<term>)", &Name.term)) {

      if (ofp_traverse_Name(Name.term, &Name)) {
         // MATCHED Name
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
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

 ATbool matched = ATfalse;

 OFP_Traverse LiteralConstant;
 if (ATmatch(term, "Constant_AMB(<term>)", &LiteralConstant.term)) {

      if (ofp_traverse_LiteralConstant(LiteralConstant.term, &LiteralConstant)) {
         // MATCHED LiteralConstant
         matched = ATtrue;
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

 ATbool matched = ATfalse;

 OFP_Traverse BozLiteralConstant;
 if (ATmatch(term, "LiteralConstant(<term>)", &BozLiteralConstant.term)) {

#ifdef NOT_YET
      if (ofp_traverse_BozLiteralConstant(BozLiteralConstant.term, &BozLiteralConstant)) {
         // MATCHED BozLiteralConstant
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse CharLiteralConstant;
 if (ATmatch(term, "LiteralConstant(<term>)", &CharLiteralConstant.term)) {

#ifdef NOT_YET
      if (ofp_traverse_CharLiteralConstant(CharLiteralConstant.term, &CharLiteralConstant)) {
         // MATCHED CharLiteralConstant
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse LogicalLiteralConstant;
 if (ATmatch(term, "LiteralConstant(<term>)", &LogicalLiteralConstant.term)) {

#ifdef NOT_YET
      if (ofp_traverse_LogicalLiteralConstant(LogicalLiteralConstant.term, &LogicalLiteralConstant)) {
         // MATCHED LogicalLiteralConstant
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse ComplexLiteralConstant;
 if (ATmatch(term, "LiteralConstant(<term>)", &ComplexLiteralConstant.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ComplexLiteralConstant(ComplexLiteralConstant.term, &ComplexLiteralConstant)) {
         // MATCHED ComplexLiteralConstant
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse RealLiteralConstant;
 if (ATmatch(term, "LiteralConstant(<term>)", &RealLiteralConstant.term)) {

#ifdef NOT_YET
      if (ofp_traverse_RealLiteralConstant(RealLiteralConstant.term, &RealLiteralConstant)) {
         // MATCHED RealLiteralConstant
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse IntLiteralConstant;
 if (ATmatch(term, "LiteralConstant(<term>)", &IntLiteralConstant.term)) {

      if (ofp_traverse_IntLiteralConstant(IntLiteralConstant.term, &IntLiteralConstant)) {
         // MATCHED IntLiteralConstant
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
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

 ATbool matched = ATfalse;

 OFP_Traverse Name;
 if (ATmatch(term, "NamedConstant(<term>)", &Name.term)) {

      if (ofp_traverse_Name(Name.term, &Name)) {
         // MATCHED Name
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
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

 ATbool matched = ATfalse;
 OFP_Traverse IntrinsicTypeSpec;
 if (ATmatch(term, "DeclarationTypeSpec(<term>)", &IntrinsicTypeSpec.term)) {

      if (ofp_traverse_IntrinsicTypeSpec(IntrinsicTypeSpec.term, &IntrinsicTypeSpec)) {
         // MATCHED IntrinsicTypeSpec
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
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

 ATbool matched = ATfalse;

 if (ATmatch(term, "IntrinsicTypeSpec_DOUBLE_COMPLEX")) {

   // MATCHED IntrinsicTypeSpec_DOUBLE_COMPLEX

   return ATtrue;
 }

 OFP_Traverse KindSelector;
 if (ATmatch(term, "IntrinsicTypeSpec_LOGICAL(<term>)", &KindSelector.term)) {

   if (ATmatch(KindSelector.term, "Some(<term>)", &KindSelector.term)) {
      if (ofp_traverse_KindSelector(KindSelector.term, &KindSelector)) {
         // MATCHED KindSelector
         matched = ATtrue;
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
         matched = ATtrue;
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
         matched = ATtrue;
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
         matched = ATtrue;
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
         matched = ATtrue;
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

 ATbool matched = ATfalse;

 OFP_Traverse Expr;
 if (ATmatch(term, "CharSelector_KIND(<term>)", &Expr.term)) {

      if (ofp_traverse_Expr(Expr.term, &Expr)) {
         // MATCHED Expr
         matched = ATtrue;
      } else return ATfalse;

   // MATCHED CharSelector_KIND

   return ATtrue;
 }

 OFP_Traverse Expr1, TypeParamValue;
 if (ATmatch(term, "CharSelector_KIND_LEN(<term>,<term>)", &Expr1.term, &TypeParamValue.term)) {

      if (ofp_traverse_Expr(Expr1.term, &Expr1)) {
         // MATCHED Expr
         matched = ATtrue;
      } else return ATfalse;

#ifdef NOT_YET
      if (ofp_traverse_TypeParamValue(TypeParamValue.term, &TypeParamValue)) {
         // MATCHED TypeParamValue
         matched = ATtrue;
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
         matched = ATtrue;
      } else return ATfalse;
#endif

      if (ofp_traverse_Expr(Expr2.term, &Expr2)) {
         // MATCHED Expr
         matched = ATtrue;
      } else return ATfalse;

   // MATCHED CharSelector_LEN_KIND

   return ATtrue;
 }

 OFP_Traverse LengthSelector;
 if (ATmatch(term, "CharSelector_LS(<term>)", &LengthSelector.term)) {

      if (ofp_traverse_LengthSelector(LengthSelector.term, &LengthSelector)) {
         // MATCHED LengthSelector
         matched = ATtrue;
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

 ATbool matched = ATfalse;

 OFP_Traverse CharLength;
 if (ATmatch(term, "LengthSelector_STAR(<term>)", &CharLength.term)) {

#ifdef NOT_YET
      if (ofp_traverse_CharLength(CharLength.term, &CharLength)) {
         // MATCHED CharLength
         matched = ATtrue;
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
         matched = ATtrue;
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

 ATbool matched = ATfalse;

 OFP_Traverse AcImpliedDo;
 if (ATmatch(term, "AcValue(<term>)", &AcImpliedDo.term)) {

#ifdef NOT_YET
      if (ofp_traverse_AcImpliedDo(AcImpliedDo.term, &AcImpliedDo)) {
         // MATCHED AcImpliedDo
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse Expr;
 if (ATmatch(term, "AcValue(<term>)", &Expr.term)) {

      if (ofp_traverse_Expr(Expr.term, &Expr)) {
         // MATCHED Expr
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
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

 ATbool matched = ATfalse;
 OFP_Traverse Label, DeclarationTypeSpec, AttrSpecList, EntityDeclList, EOS;
 if (ATmatch(term, "TypeDeclarationStmt(<term>,<term>,<term>,<term>,<term>)", &Label.term, &DeclarationTypeSpec.term, &AttrSpecList.term, &EntityDeclList.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
         matched = ATtrue;
      } else return ATfalse;
   }

      if (ofp_traverse_DeclarationTypeSpec(DeclarationTypeSpec.term, &DeclarationTypeSpec)) {
         // MATCHED DeclarationTypeSpec
         matched = ATtrue;
      } else return ATfalse;

   if (ATmatch(AttrSpecList.term, "Some(<term>)", &AttrSpecList.term)) {
   if (ATmatch(AttrSpecList.term, "(Some(<term>))", &AttrSpecList.term)) {
   if (ATmatch(AttrSpecList.term, "(<term>)", &AttrSpecList.term)) {
      if (ofp_traverse_AttrSpecList(AttrSpecList.term, &AttrSpecList)) {
         // MATCHED AttrSpecList
         matched = ATtrue;
      } else return ATfalse;
   }
   }
   }

      if (ofp_traverse_EntityDeclList(EntityDeclList.term, &EntityDeclList)) {
         // MATCHED EntityDeclList
         matched = ATtrue;
      } else return ATfalse;

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
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

 ATbool matched = ATfalse;

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
         matched = ATtrue;
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
         matched = ATtrue;
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
         matched = ATtrue;
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
         matched = ATtrue;
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
         matched = ATtrue;
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

 ATbool matched = ATfalse;

 OFP_Traverse ObjectName, ArraySpec, CoarraySpec, CharLength, Initialization;
 if (ATmatch(term, "EntityDecl(<term>,<term>,<term>,<term>,<term>)", &ObjectName.term, &ArraySpec.term, &CoarraySpec.term, &CharLength.term, &Initialization.term)) {

      if (ofp_traverse_ObjectName(ObjectName.term, &ObjectName)) {
         // MATCHED ObjectName
         matched = ATtrue;
      } else return ATfalse;

   if (ATmatch(ArraySpec.term, "Some(<term>)", &ArraySpec.term)) {
   if (ATmatch(ArraySpec.term, "(<term>)", &ArraySpec.term)) {
#ifdef NOT_YET
      if (ofp_traverse_ArraySpec(ArraySpec.term, &ArraySpec)) {
         // MATCHED ArraySpec
         matched = ATtrue;
      } else return ATfalse;
#endif
   }
   }

   if (ATmatch(CoarraySpec.term, "Some(<term>)", &CoarraySpec.term)) {
   if (ATmatch(CoarraySpec.term, "(<term>)", &CoarraySpec.term)) {
#ifdef NOT_YET
      if (ofp_traverse_CoarraySpec(CoarraySpec.term, &CoarraySpec)) {
         // MATCHED CoarraySpec
         matched = ATtrue;
      } else return ATfalse;
#endif
   }
   }

   if (ATmatch(CharLength.term, "Some(<term>)", &CharLength.term)) {
   if (ATmatch(CharLength.term, "(<term>)", &CharLength.term)) {
#ifdef NOT_YET
      if (ofp_traverse_CharLength(CharLength.term, &CharLength)) {
         // MATCHED CharLength
         matched = ATtrue;
      } else return ATfalse;
#endif
   }
   }

   if (ATmatch(Initialization.term, "Some(<term>)", &Initialization.term)) {
#ifdef NOT_YET
      if (ofp_traverse_Initialization(Initialization.term, &Initialization)) {
         // MATCHED Initialization
         matched = ATtrue;
      } else return ATfalse;
#endif
   }

   if (matched) return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1101 main-program
//----------------------------------------------------------------------------------------
#ifdef USE_FINISHED
ATbool ofp_traverse_MainProgram(ATerm term, pOFP_Traverse MainProgram)
{
#ifdef DEBUG_PRINT
   printf("\nMainProgram: %s\n", ATwriteToString(term));
#endif

 ATbool matched = ATfalse;
 OFP_Traverse ProgramStmt, SpecificationPart, ExecutionPart, InternalSubprogramPart, EndProgramStmt;
 if (ATmatch(term, "MainProgram(<term>,<term>,<term>,<term>,<term>)", &ProgramStmt.term, &SpecificationPart.term, &ExecutionPart.term, &InternalSubprogramPart.term, &EndProgramStmt.term)) {

   if (ATmatch(ProgramStmt.term, "Some(<term>)", &ProgramStmt.term)) {
      if (ofp_traverse_ProgramStmt(ProgramStmt.term, &ProgramStmt)) {
         // MATCHED ProgramStmt
         matched = ATtrue;
      } else return ATfalse;
   }

      if (ofp_traverse_SpecificationPart(SpecificationPart.term, &SpecificationPart)) {
         // MATCHED SpecificationPart
         matched = ATtrue;
      } else return ATfalse;

      if (ofp_traverse_ExecutionPart(ExecutionPart.term, &ExecutionPart)) {
         // MATCHED ExecutionPart
         matched = ATtrue;
      } else return ATfalse;

   if (ATmatch(InternalSubprogramPart.term, "Some(<term>)", &InternalSubprogramPart.term)) {
      if (ofp_traverse_InternalSubprogramPart(InternalSubprogramPart.term, &InternalSubprogramPart)) {
         // MATCHED InternalSubprogramPart
         matched = ATtrue;
      } else return ATfalse;
   }

      if (ofp_traverse_EndProgramStmt(EndProgramStmt.term, &EndProgramStmt)) {
         // MATCHED EndProgramStmt
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
 }

 return ATfalse;
}
#endif

//========================================================================================
// R1102 program-stmt
//----------------------------------------------------------------------------------------
#ifdef USE_FINISHED
ATbool ofp_traverse_ProgramStmt(ATerm term, pOFP_Traverse ProgramStmt)
{
#ifdef DEBUG_PRINT
   printf("\nProgramStmt: %s\n", ATwriteToString(term));
#endif

 ATbool matched = ATfalse;
 OFP_Traverse Label, ProgramName, EOS;
 if (ATmatch(term, "ProgramStmt(<term>,<term>,<term>)", &Label.term, &ProgramName.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
         matched = ATtrue;
      } else return ATfalse;
   }

      if (ofp_traverse_ProgramName(ProgramName.term, &ProgramName)) {
         // MATCHED ProgramName
         matched = ATtrue;
      } else return ATfalse;

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
 }

 return ATfalse;
}
#endif

//========================================================================================
// R1103 end-program-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_EndProgramStmt(ATerm term, pOFP_Traverse EndProgramStmt)
{
#ifdef DEBUG_PRINT
   printf("\nEndProgramStmt: %s\n", ATwriteToString(term));
#endif

 ATbool matched = ATfalse;
 OFP_Traverse Label, ProgramName, EOS;
 if (ATmatch(term, "EndProgramStmt(<term>,<term>,<term>)", &Label.term, &ProgramName.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
         matched = ATtrue;
      } else return ATfalse;
   }

   if (ATmatch(ProgramName.term, "Some(<term>)", &ProgramName.term)) {
   if (ATmatch(ProgramName.term, "(Some(<term>))", &ProgramName.term)) {
      if (ofp_traverse_ProgramName(ProgramName.term, &ProgramName)) {
         // MATCHED ProgramName
         matched = ATtrue;
      } else return ATfalse;
   }
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1104 module
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_Module(ATerm term, pOFP_Traverse Module)
{
#ifdef DEBUG_PRINT
   printf("Module: %s\n", ATwriteToString(term));
#endif

 ATbool matched = ATfalse;

 OFP_Traverse ModuleStmt, SpecificationPart, ModuleSubprogramPart, EndModuleStmt;
 if (ATmatch(term, "Module(<term>,<term>,<term>,<term>)", &ModuleStmt.term, &SpecificationPart.term, &ModuleSubprogramPart.term, &EndModuleStmt.term)) {

      if (ofp_traverse_ModuleStmt(ModuleStmt.term, &ModuleStmt)) {
         // MATCHED ModuleStmt
         matched = ATtrue;
      } else return ATfalse;

      if (ofp_traverse_SpecificationPart(SpecificationPart.term, &SpecificationPart)) {
         // MATCHED SpecificationPart
         matched = ATtrue;
      } else return ATfalse;

   if (ATmatch(ModuleSubprogramPart.term, "Some(<term>)", &ModuleSubprogramPart.term)) {
      if (ofp_traverse_ModuleSubprogramPart(ModuleSubprogramPart.term, &ModuleSubprogramPart)) {
         // MATCHED ModuleSubprogramPart
         matched = ATtrue;
      } else return ATfalse;
   }

      if (ofp_traverse_EndModuleStmt(EndModuleStmt.term, &EndModuleStmt)) {
         // MATCHED EndModuleStmt
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
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

 ATbool matched = ATfalse;

 OFP_Traverse Label, ModuleName, EOS;
 if (ATmatch(term, "ModuleStmt(<term>,<term>,<term>)", &Label.term, &ModuleName.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
         matched = ATtrue;
      } else return ATfalse;
   }

      if (ofp_traverse_ModuleName(ModuleName.term, &ModuleName)) {
         // MATCHED ModuleName
         matched = ATtrue;
      } else return ATfalse;

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
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

 ATbool matched = ATfalse;

 OFP_Traverse Label, ModuleName, EOS;
 if (ATmatch(term, "EndModuleStmt(<term>,<term>,<term>)", &Label.term, &ModuleName.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
         matched = ATtrue;
      } else return ATfalse;
   }

   if (ATmatch(ModuleName.term, "Some(<term>)", &ModuleName.term)) {
   if (ATmatch(ModuleName.term, "(Some(<term>))", &ModuleName.term)) {
      if (ofp_traverse_ModuleName(ModuleName.term, &ModuleName)) {
         // MATCHED ModuleName
         matched = ATtrue;
      } else return ATfalse;
   }
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
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

 ATbool matched = ATfalse;

 OFP_Traverse ContainsStmt, ModuleSubprogram;
 if (ATmatch(term, "ModuleSubprogramPart(<term>,<term>)", &ContainsStmt.term, &ModuleSubprogram.term)) {

#ifdef NOT_YET
      if (ofp_traverse_ContainsStmt(ContainsStmt.term, &ContainsStmt)) {
         // MATCHED ContainsStmt
         matched = ATtrue;
      } else return ATfalse;
#endif

   ATermList ModuleSubprogram_tail = (ATermList) ATmake("<term>", ModuleSubprogram.term);
   if (ATisEmpty(ModuleSubprogram_tail)) matched = ATtrue;
   while (! ATisEmpty(ModuleSubprogram_tail)) {
      ModuleSubprogram.term = ATgetFirst(ModuleSubprogram_tail);
      ModuleSubprogram_tail = ATgetNext (ModuleSubprogram_tail);
      if (ofp_traverse_ModuleSubprogram(ModuleSubprogram.term, &ModuleSubprogram)) {
         // MATCHED ModuleSubprogram
         matched = ATtrue;
      } else return ATfalse;
   }

   if (matched) return ATtrue;
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

 ATbool matched = ATfalse;

 OFP_Traverse SeparateModuleSubprogram;
 if (ATmatch(term, "ModuleSubprogram(<term>)", &SeparateModuleSubprogram.term)) {

#ifdef NOT_YET
      if (ofp_traverse_SeparateModuleSubprogram(SeparateModuleSubprogram.term, &SeparateModuleSubprogram)) {
         // MATCHED SeparateModuleSubprogram
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse SubroutineSubprogram;
 if (ATmatch(term, "ModuleSubprogram(<term>)", &SubroutineSubprogram.term)) {

#ifdef NOT_YET
      if (ofp_traverse_SubroutineSubprogram(SubroutineSubprogram.term, &SubroutineSubprogram)) {
         // MATCHED SubroutineSubprogram
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse FunctionSubprogram;
 if (ATmatch(term, "ModuleSubprogram(<term>)", &FunctionSubprogram.term)) {

#ifdef NOT_YET
      if (ofp_traverse_FunctionSubprogram(FunctionSubprogram.term, &FunctionSubprogram)) {
         // MATCHED FunctionSubprogram
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
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

 ATbool matched = ATfalse;

 OFP_Traverse Label, ModuleNature, ModuleName, OnlyList, EOS;
 if (ATmatch(term, "UseStmt_Only(<term>,<term>,<term>,<term>,<term>)", &Label.term, &ModuleNature.term, &ModuleName.term, &OnlyList.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
         matched = ATtrue;
      } else return ATfalse;
   }

   if (ATmatch(ModuleNature.term, "Some(<term>)", &ModuleNature.term)) {
   if (ATmatch(ModuleNature.term, "(Some(<term>))", &ModuleNature.term)) {
   if (ATmatch(ModuleNature.term, "(<term>)", &ModuleNature.term)) {
      if (ofp_traverse_ModuleNature(ModuleNature.term, &ModuleNature)) {
         // MATCHED ModuleNature
         matched = ATtrue;
      } else return ATfalse;
   }
   }
   }

      if (ofp_traverse_ModuleName(ModuleName.term, &ModuleName)) {
         // MATCHED ModuleName
         matched = ATtrue;
      } else return ATfalse;

   if (ATmatch(OnlyList.term, "Some(<term>)", &OnlyList.term)) {
      if (ofp_traverse_OnlyList(OnlyList.term, &OnlyList)) {
         // MATCHED OnlyList
         matched = ATtrue;
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
         matched = ATtrue;
      } else return ATfalse;

   // MATCHED UseStmt_Only

   return ATtrue;
 }

 OFP_Traverse Label1, ModuleNature1, ModuleName1, RenameList, EOS1;
 if (ATmatch(term, "UseStmt_Rename(<term>,<term>,<term>,<term>,<term>)", &Label1.term, &ModuleNature1.term, &ModuleName1.term, &RenameList.term, &EOS1.term)) {

   if (ATmatch(Label1.term, "Some(<term>)", &Label1.term)) {
      if (ofp_traverse_Label(Label1.term, &Label1)) {
         // MATCHED Label
         matched = ATtrue;
      } else return ATfalse;
   }

   if (ATmatch(ModuleNature1.term, "Some(<term>)", &ModuleNature1.term)) {
   if (ATmatch(ModuleNature1.term, "(Some(<term>))", &ModuleNature1.term)) {
   if (ATmatch(ModuleNature1.term, "(<term>)", &ModuleNature1.term)) {
      if (ofp_traverse_ModuleNature(ModuleNature1.term, &ModuleNature1)) {
         // MATCHED ModuleNature
         matched = ATtrue;
      } else return ATfalse;
   }
   }
   }

      if (ofp_traverse_ModuleName(ModuleName1.term, &ModuleName1)) {
         // MATCHED ModuleName
         matched = ATtrue;
      } else return ATfalse;

   if (ATmatch(RenameList.term, "Some(<term>)", &RenameList.term)) {
   if (ATmatch(RenameList.term, "(<term>)", &RenameList.term)) {
      if (ofp_traverse_RenameList(RenameList.term, &RenameList)) {
         // MATCHED RenameList
         matched = ATtrue;
      } else return ATfalse;
   }
   }

      if (ofp_traverse_EOS(EOS1.term, &EOS1)) {
         // MATCHED EOS
         matched = ATtrue;
      } else return ATfalse;

   // MATCHED UseStmt_Rename

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

 ATbool matched = ATfalse;

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

 ATbool matched = ATfalse;

 OFP_Traverse LocalDefinedOperator, UseDefinedOperator;
 if (ATmatch(term, "Rename(<term>,<term>)", &LocalDefinedOperator.term, &UseDefinedOperator.term)) {

#ifdef NOT_YET
      if (ofp_traverse_LocalDefinedOperator(LocalDefinedOperator.term, &LocalDefinedOperator)) {
         // MATCHED LocalDefinedOperator
         matched = ATtrue;
      } else return ATfalse;
#endif

      if (ofp_traverse_UseDefinedOperator(UseDefinedOperator.term, &UseDefinedOperator)) {
         // MATCHED UseDefinedOperator
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
 }

 OFP_Traverse LocalName, UseName;
 if (ATmatch(term, "Rename(<term>,<term>)", &LocalName.term, &UseName.term)) {

      if (ofp_traverse_LocalName(LocalName.term, &LocalName)) {
         // MATCHED LocalName
         matched = ATtrue;
      } else return ATfalse;

      if (ofp_traverse_UseName(UseName.term, &UseName)) {
         // MATCHED UseName
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_RenameList(ATerm term, pOFP_Traverse RenameList)
{
#ifdef DEBUG_PRINT
   printf("RenameList: %s\n", ATwriteToString(term));
#endif

 ATbool matched = ATfalse;

 OFP_Traverse Rename;
 if (ATmatch(term, "RenameList(<term>)", &Rename.term)) {

   ATermList Rename_tail = (ATermList) ATmake("<term>", Rename.term);
   if (ATisEmpty(Rename_tail)) matched = ATtrue;
   while (! ATisEmpty(Rename_tail)) {
      Rename.term = ATgetFirst(Rename_tail);
      Rename_tail = ATgetNext (Rename_tail);
      if (ofp_traverse_Rename(Rename.term, &Rename)) {
         // MATCHED Rename
         matched = ATtrue;
      } else return ATfalse;
   }

   if (matched) return ATtrue;
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

 ATbool matched = ATfalse;

 OFP_Traverse Rename;
 if (ATmatch(term, "Only(<term>)", &Rename.term)) {

      if (ofp_traverse_Rename(Rename.term, &Rename)) {
         // MATCHED Rename
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
 }

 OFP_Traverse OnlyUseName;
 if (ATmatch(term, "Only(<term>)", &OnlyUseName.term)) {

      if (ofp_traverse_OnlyUseName(OnlyUseName.term, &OnlyUseName)) {
         // MATCHED OnlyUseName
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_OnlyList(ATerm term, pOFP_Traverse OnlyList)
{
#ifdef DEBUG_PRINT
   printf("OnlyList: %s\n", ATwriteToString(term));
#endif

 ATbool matched = ATfalse;

 OFP_Traverse Only;
 if (ATmatch(term, "OnlyList(<term>)", &Only.term)) {

   ATermList Only_tail = (ATermList) ATmake("<term>", Only.term);
   if (ATisEmpty(Only_tail)) matched = ATtrue;
   while (! ATisEmpty(Only_tail)) {
      Only.term = ATgetFirst(Only_tail);
      Only_tail = ATgetNext (Only_tail);
      if (ofp_traverse_Only(Only.term, &Only)) {
         // MATCHED Only
         matched = ATtrue;
      } else return ATfalse;
   }

   if (matched) return ATtrue;
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

 ATbool matched = ATfalse;

 OFP_Traverse Ident;
 if (ATmatch(term, "OnlyUseName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
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

 ATbool matched = ATfalse;

 OFP_Traverse DefinedBinaryOp;
 if (ATmatch(term, "LocalDefinedOperator(<term>)", &DefinedBinaryOp.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefinedBinaryOp(DefinedBinaryOp.term, &DefinedBinaryOp)) {
         // MATCHED DefinedBinaryOp
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse DefinedUnaryOp;
 if (ATmatch(term, "LocalDefinedOperator(<term>)", &DefinedUnaryOp.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefinedUnaryOp(DefinedUnaryOp.term, &DefinedUnaryOp)) {
         // MATCHED DefinedUnaryOp
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
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

 ATbool matched = ATfalse;

 OFP_Traverse DefinedBinaryOp;
 if (ATmatch(term, "UseDefinedOperator(<term>)", &DefinedBinaryOp.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefinedBinaryOp(DefinedBinaryOp.term, &DefinedBinaryOp)) {
         // MATCHED DefinedBinaryOp
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 OFP_Traverse DefinedUnaryOp;
 if (ATmatch(term, "UseDefinedOperator(<term>)", &DefinedUnaryOp.term)) {

#ifdef NOT_YET
      if (ofp_traverse_DefinedUnaryOp(DefinedUnaryOp.term, &DefinedUnaryOp)) {
         // MATCHED DefinedUnaryOp
         matched = ATtrue;
      } else return ATfalse;
#endif

   if (matched) return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1116 submodule
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_Submodule(ATerm term, pOFP_Traverse Submodule)
{
#ifdef DEBUG_PRINT
   printf("Submodule: %s\n", ATwriteToString(term));
#endif

 ATbool matched = ATfalse;

 OFP_Traverse SubmoduleStmt, SpecificationPart, ModuleSubprogramPart, EndSubmoduleStmt;
 if (ATmatch(term, "Submodule(<term>,<term>,<term>,<term>)", &SubmoduleStmt.term, &SpecificationPart.term, &ModuleSubprogramPart.term, &EndSubmoduleStmt.term)) {

      if (ofp_traverse_SubmoduleStmt(SubmoduleStmt.term, &SubmoduleStmt)) {
         // MATCHED SubmoduleStmt
         matched = ATtrue;
      } else return ATfalse;

      if (ofp_traverse_SpecificationPart(SpecificationPart.term, &SpecificationPart)) {
         // MATCHED SpecificationPart
         matched = ATtrue;
      } else return ATfalse;

   if (ATmatch(ModuleSubprogramPart.term, "Some(<term>)", &ModuleSubprogramPart.term)) {
      if (ofp_traverse_ModuleSubprogramPart(ModuleSubprogramPart.term, &ModuleSubprogramPart)) {
         // MATCHED ModuleSubprogramPart
         matched = ATtrue;
      } else return ATfalse;
   }

      if (ofp_traverse_EndSubmoduleStmt(EndSubmoduleStmt.term, &EndSubmoduleStmt)) {
         // MATCHED EndSubmoduleStmt
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
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

 ATbool matched = ATfalse;

 OFP_Traverse Label, ParentIdentifier, SubmoduleName, EOS;
 if (ATmatch(term, "SubmoduleStmt(<term>,<term>,<term>,<term>)", &Label.term, &ParentIdentifier.term, &SubmoduleName.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
         matched = ATtrue;
      } else return ATfalse;
   }

      if (ofp_traverse_ParentIdentifier(ParentIdentifier.term, &ParentIdentifier)) {
         // MATCHED ParentIdentifier
         matched = ATtrue;
      } else return ATfalse;

      if (ofp_traverse_SubmoduleName(SubmoduleName.term, &SubmoduleName)) {
         // MATCHED SubmoduleName
         matched = ATtrue;
      } else return ATfalse;

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
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

 ATbool matched = ATfalse;

 OFP_Traverse AncestorModuleName, ParentSubmoduleName;
 if (ATmatch(term, "ParentIdentifier(<term>,<term>)", &AncestorModuleName.term, &ParentSubmoduleName.term)) {

      if (ofp_traverse_AncestorModuleName(AncestorModuleName.term, &AncestorModuleName)) {
         // MATCHED AncestorModuleName
         matched = ATtrue;
      } else return ATfalse;

   if (ATmatch(ParentSubmoduleName.term, "Some(<term>)", &ParentSubmoduleName.term)) {
   if (ATmatch(ParentSubmoduleName.term, "(<term>)", &ParentSubmoduleName.term)) {
      if (ofp_traverse_ParentSubmoduleName(ParentSubmoduleName.term, &ParentSubmoduleName)) {
         // MATCHED ParentSubmoduleName
         matched = ATtrue;
      } else return ATfalse;
   }
   }

   if (matched) return ATtrue;
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

 ATbool matched = ATfalse;

 OFP_Traverse Label, SubmoduleName, EOS;
 if (ATmatch(term, "EndSubmoduleStmt(<term>,<term>,<term>)", &Label.term, &SubmoduleName.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
         matched = ATtrue;
      } else return ATfalse;
   }

   if (ATmatch(SubmoduleName.term, "Some(<term>)", &SubmoduleName.term)) {
   if (ATmatch(SubmoduleName.term, "(Some(<term>))", &SubmoduleName.term)) {
      if (ofp_traverse_SubmoduleName(SubmoduleName.term, &SubmoduleName)) {
         // MATCHED SubmoduleName
         matched = ATtrue;
      } else return ATfalse;
   }
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
 }

 return ATfalse;
}

//========================================================================================
// R1120 block-data
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_BlockData(ATerm term, pOFP_Traverse BlockData)
{
#ifdef DEBUG_PRINT
   printf("BlockData: %s\n", ATwriteToString(term));
#endif

 ATbool matched = ATfalse;

 OFP_Traverse BlockDataStmt, SpecificationPart, EndBlockDataStmt;
 if (ATmatch(term, "BlockData(<term>,<term>,<term>)", &BlockDataStmt.term, &SpecificationPart.term, &EndBlockDataStmt.term)) {

      if (ofp_traverse_BlockDataStmt(BlockDataStmt.term, &BlockDataStmt)) {
         // MATCHED BlockDataStmt
         matched = ATtrue;
      } else return ATfalse;

      if (ofp_traverse_SpecificationPart(SpecificationPart.term, &SpecificationPart)) {
         // MATCHED SpecificationPart
         matched = ATtrue;
      } else return ATfalse;

      if (ofp_traverse_EndBlockDataStmt(EndBlockDataStmt.term, &EndBlockDataStmt)) {
         // MATCHED EndBlockDataStmt
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
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

 ATbool matched = ATfalse;

 OFP_Traverse Label, BlockDataName, EOS;
 if (ATmatch(term, "BlockDataStmt(<term>,<term>,<term>)", &Label.term, &BlockDataName.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
         matched = ATtrue;
      } else return ATfalse;
   }

   if (ATmatch(BlockDataName.term, "Some(<term>)", &BlockDataName.term)) {
      if (ofp_traverse_BlockDataName(BlockDataName.term, &BlockDataName)) {
         // MATCHED BlockDataName
         matched = ATtrue;
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
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

 ATbool matched = ATfalse;

 OFP_Traverse Label, EOS;
 if (ATmatch(term, "EndBlockDataStmt(<term>,<term>)", &Label.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
         matched = ATtrue;
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
 }

 OFP_Traverse Label1, BlockDataName, EOS1;
 if (ATmatch(term, "EndBlockDataStmt(<term>,<term>,<term>)", &Label1.term, &BlockDataName.term, &EOS1.term)) {

   if (ATmatch(Label1.term, "Some(<term>)", &Label1.term)) {
      if (ofp_traverse_Label(Label1.term, &Label1)) {
         // MATCHED Label
         matched = ATtrue;
      } else return ATfalse;
   }

   if (ATmatch(BlockDataName.term, "Some(<term>)", &BlockDataName.term)) {
      if (ofp_traverse_BlockDataName(BlockDataName.term, &BlockDataName)) {
         // MATCHED BlockDataName
         matched = ATtrue;
      } else return ATfalse;
   }

      if (ofp_traverse_EOS(EOS1.term, &EOS1)) {
         // MATCHED EOS
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
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

 ATbool matched = ATfalse;

 OFP_Traverse Ident;
 if (ATmatch(term, "AncestorModuleName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ArgName(ATerm term, pOFP_Traverse ArgName)
{
#ifdef DEBUG_PRINT
   printf("ArgName: %s\n", ATwriteToString(term));
#endif

 ATbool matched = ATfalse;

 OFP_Traverse Ident;
 if (ATmatch(term, "ArgName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_BindingName(ATerm term, pOFP_Traverse BindingName)
{
#ifdef DEBUG_PRINT
   printf("BindingName: %s\n", ATwriteToString(term));
#endif

 ATbool matched = ATfalse;

 OFP_Traverse Ident;
 if (ATmatch(term, "BindingName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_BlockDataName(ATerm term, pOFP_Traverse BlockDataName)
{
#ifdef DEBUG_PRINT
   printf("BlockDataName: %s\n", ATwriteToString(term));
#endif

 ATbool matched = ATfalse;

 OFP_Traverse Ident;
 if (ATmatch(term, "BlockDataName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ComponentName(ATerm term, pOFP_Traverse ComponentName)
{
#ifdef DEBUG_PRINT
   printf("ComponentName: %s\n", ATwriteToString(term));
#endif

 ATbool matched = ATfalse;

 OFP_Traverse Ident;
 if (ATmatch(term, "ComponentName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_FinalSubroutineName(ATerm term, pOFP_Traverse FinalSubroutineName)
{
#ifdef DEBUG_PRINT
   printf("FinalSubroutineName: %s\n", ATwriteToString(term));
#endif

 ATbool matched = ATfalse;

 OFP_Traverse Ident;
 if (ATmatch(term, "FinalSubroutineName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_InterfaceName(ATerm term, pOFP_Traverse InterfaceName)
{
#ifdef DEBUG_PRINT
   printf("InterfaceName: %s\n", ATwriteToString(term));
#endif

 ATbool matched = ATfalse;

 OFP_Traverse Ident;
 if (ATmatch(term, "InterfaceName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_LocalName(ATerm term, pOFP_Traverse LocalName)
{
#ifdef DEBUG_PRINT
   printf("LocalName: %s\n", ATwriteToString(term));
#endif

 ATbool matched = ATfalse;

 OFP_Traverse Ident;
 if (ATmatch(term, "LocalName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ModuleName(ATerm term, pOFP_Traverse ModuleName)
{
#ifdef DEBUG_PRINT
   printf("ModuleName: %s\n", ATwriteToString(term));
#endif

 ATbool matched = ATfalse;

 OFP_Traverse Ident;
 if (ATmatch(term, "ModuleName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_Name(ATerm term, pOFP_Traverse Name)
{
#ifdef DEBUG_PRINT
   printf("Name: %s\n", ATwriteToString(term));
#endif

 ATbool matched = ATfalse;

 OFP_Traverse Ident;
 if (ATmatch(term, "Name(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ObjectName(ATerm term, pOFP_Traverse ObjectName)
{
#ifdef DEBUG_PRINT
   printf("ObjectName: %s\n", ATwriteToString(term));
#endif

 ATbool matched = ATfalse;
 OFP_Traverse Ident;
 if (ATmatch(term, "ObjectName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ParentSubmoduleName(ATerm term, pOFP_Traverse ParentSubmoduleName)
{
#ifdef DEBUG_PRINT
   printf("ParentSubmoduleName: %s\n", ATwriteToString(term));
#endif

 ATbool matched = ATfalse;

 OFP_Traverse Ident;
 if (ATmatch(term, "ParentSubmoduleName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ParentTypeName(ATerm term, pOFP_Traverse ParentTypeName)
{
#ifdef DEBUG_PRINT
   printf("ParentTypeName: %s\n", ATwriteToString(term));
#endif

 ATbool matched = ATfalse;

 OFP_Traverse Ident;
 if (ATmatch(term, "ParentTypeName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ProcedureName(ATerm term, pOFP_Traverse ProcedureName)
{
#ifdef DEBUG_PRINT
   printf("ProcedureName: %s\n", ATwriteToString(term));
#endif

 ATbool matched = ATfalse;

 OFP_Traverse Ident;
 if (ATmatch(term, "ProcedureName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ProgramName(ATerm term, pOFP_Traverse ProgramName)
{
#ifdef DEBUG_PRINT
   printf("ProgramName: %s\n", ATwriteToString(term));
#endif

 ATbool matched = ATfalse;
 OFP_Traverse Ident;
 if (ATmatch(term, "ProgramName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_ScalarIntConstantName(ATerm term, pOFP_Traverse ScalarIntConstantName)
{
#ifdef DEBUG_PRINT
   printf("ScalarIntConstantName: %s\n", ATwriteToString(term));
#endif

 ATbool matched = ATfalse;

 OFP_Traverse Ident;
 if (ATmatch(term, "ScalarIntConstantName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_SubmoduleName(ATerm term, pOFP_Traverse SubmoduleName)
{
#ifdef DEBUG_PRINT
   printf("SubmoduleName: %s\n", ATwriteToString(term));
#endif

 ATbool matched = ATfalse;

 OFP_Traverse Ident;
 if (ATmatch(term, "SubmoduleName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_TypeName(ATerm term, pOFP_Traverse TypeName)
{
#ifdef DEBUG_PRINT
   printf("TypeName: %s\n", ATwriteToString(term));
#endif

 ATbool matched = ATfalse;

 OFP_Traverse Ident;
 if (ATmatch(term, "TypeName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_TypeParamName(ATerm term, pOFP_Traverse TypeParamName)
{
#ifdef DEBUG_PRINT
   printf("TypeParamName: %s\n", ATwriteToString(term));
#endif

 ATbool matched = ATfalse;

 OFP_Traverse Ident;
 if (ATmatch(term, "TypeParamName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
 }

 return ATfalse;
}

ATbool ofp_traverse_UseName(ATerm term, pOFP_Traverse UseName)
{
#ifdef DEBUG_PRINT
   printf("UseName: %s\n", ATwriteToString(term));
#endif

 ATbool matched = ATfalse;

 OFP_Traverse Ident;
 if (ATmatch(term, "UseName(<term>)", &Ident.term)) {

      if (ofp_traverse_Ident(Ident.term, &Ident)) {
         // MATCHED Ident
         matched = ATtrue;
      } else return ATfalse;

   if (matched) return ATtrue;
 }

 return ATfalse;
}

