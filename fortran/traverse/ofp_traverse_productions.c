#include "traversal.h"

//========================================================================================
// R201 Program
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
// R202 ProgramUnit
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_ProgramUnit(ATerm term, pOFP_Traverse ProgramUnit)
{
#ifdef DEBUG_PRINT
   printf("\nProgramUnit: %s\n", ATwriteToString(term));
#endif

 ATbool matched = ATfalse;
 OFP_Traverse BlockData;
 if (ATmatch(term, "ProgramUnit(<term>)", &BlockData.term)) {

#ifdef NOT_YET
      if (ofp_traverse_BlockData(BlockData.term, &BlockData)) {
         // MATCHED BlockData
         matched = ATtrue;
      } else return ATfalse;
#endif

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

//========================================================================================
// R203 external-subprogram
//----------------------------------------------------------------------------------------

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
   while (! ATisEmpty(UseStmt_tail)) {
      UseStmt.term = ATgetFirst(UseStmt_tail);
      UseStmt_tail = ATgetNext (UseStmt_tail);
#ifdef NOT_YET
      if (ofp_traverse_UseStmt(UseStmt.term, &UseStmt)) {
         // MATCHED UseStmt
         matched = ATtrue;
      } else return ATfalse;
#endif
   }

   ATermList ImportStmt_tail = (ATermList) ATmake("<term>", ImportStmt.term);
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
#ifdef NOT_YET
      if (ofp_traverse_ImplicitPart(ImplicitPart.term, &ImplicitPart)) {
         // MATCHED ImplicitPart
         matched = ATtrue;
      } else return ATfalse;
#endif
   }

   ATermList DeclarationConstruct_tail = (ATermList) ATmake("<term>", DeclarationConstruct.term);
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
// R501 TypeDeclarationStmt
//----------------------------------------------------------------------------------------
// TODO-TODO-TODO-TODO-TODO-TODO-TODO
ATbool ofp_traverse_TypeDeclarationStmt(ATerm term, pOFP_Traverse TypeDeclarationStmt)
{
#ifdef DEBUG_PRINT
   printf("TypeDeclarationStmt: %s\n", ATwriteToString(term));
#endif

 ATbool matched = ATfalse;
 OFP_Traverse Label, DeclarationTypeSpec, OptAttrSpecList1, EntityDeclList, EOS;
 if (ATmatch(term, "TypeDeclarationStmt(<term>,<term>,<term>,<term>,<term>)", &Label.term, &DeclarationTypeSpec.term, &OptAttrSpecList1.term, &EntityDeclList.term, &EOS.term)) {

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

   if (ATmatch(OptAttrSpecList1.term, "Some(<term>)", &OptAttrSpecList1.term)) {
   if (ATmatch(OptAttrSpecList1.term, "(Some((<term>)))", &OptAttrSpecList1.term)) {
      if (ofp_traverse_AttrSpecList(OptAttrSpecList1.term, &OptAttrSpecList1)) {
         // MATCHED AttrSpecList
         matched = ATtrue;
      } else return ATfalse;
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
#ifdef OBSOLETE
ATbool ofp_traverse_TypeDeclarationStmt(ATerm term, pOFP_Traverse TypeDeclarationStmt)
{
#ifdef DEBUG_PRINT
   printf("TypeDeclarationStmt: %s\n", ATwriteToString(term));
#endif

   OFP_Traverse Label_term, DeclarationTypeSpec_term, OptListPlusOfAttrSpec1_term, EntityDecl_list, EOS_term;
   if (ATmatch(term, "TypeDeclarationStmt(<term>,<term>,<term>,<term>,<term>)", &Label_term.term, &DeclarationTypeSpec_term.term, &OptListPlusOfAttrSpec1_term.term, &EntityDecl_list.term, &EOS_term.term)) {

      OFP_Traverse Label;
      if (ATmatch(Label_term.term, "Some(<term>)", &Label.term)) {
         if (ofp_traverse_Label(Label.term, &Label)) {
            // MATCHED Label
         } else return ATfalse;
      }

      OFP_Traverse DeclarationTypeSpec;
      if (ATmatch(DeclarationTypeSpec_term.term, "<term>", &DeclarationTypeSpec.term)) {
         if (ofp_traverse_DeclarationTypeSpec(DeclarationTypeSpec.term, &DeclarationTypeSpec)) {
            // MATCHED DeclarationTypeSpec
         } else return ATfalse;
      } else return ATfalse;

      OFP_Traverse OptListPlusOfAttrSpec1;
      if (ATmatch(OptListPlusOfAttrSpec1_term.term, "Some((<term>))", &OptListPlusOfAttrSpec1.term)) {

         OFP_Traverse ListPlusOfAttrSpec1;
         if (ATmatch(OptListPlusOfAttrSpec1.term, "Some((<term>))", &ListPlusOfAttrSpec1.term)) {
            OFP_Traverse AttrSpecList;
            if (ofp_traverse_AttrSpecList(ListPlusOfAttrSpec1.term, &AttrSpecList)) {
               // MATCHED AttrSpeclList
            } else return ATfalse;
         }
      }

      OFP_Traverse EntityDeclList;
      if (ofp_traverse_EntityDeclList(EntityDecl_list.term, &EntityDeclList)) {
         // MATCHED EntityDeclList
      } else return ATfalse;

      OFP_Traverse EOS;
      if (ATmatch(EOS_term.term, "<term>", &EOS.term)) {
         if (ofp_traverse_EOS(EOS.term, &EOS)) {
            // MATCHED EOS
         } else return ATfalse;
      } else return ATfalse;

      return ATtrue;
   }

   return ATfalse;
}
#endif

//========================================================================================
// R1101 MainProgram
//----------------------------------------------------------------------------------------
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

//========================================================================================
// ProgramName
//----------------------------------------------------------------------------------------
#ifdef FINISHED
ATbool ofp_traverse_ProgramName(ATerm term, pOFP_Traverse ProgramName)
{
#ifdef DEBUG_PRINT
   printf("ProgramName: %s\n", ATwriteToString(term));
#endif

   OFP_Traverse Ident_term;
   if (ATmatch(term, "ProgramName(<term>)", &Ident_term.term)) {
      char * Ident_val;
      if (ATmatch(Ident_term.term, "<str>", &Ident_val)) {
         // MATCHED Ident
      } else return ATfalse;


      return ATtrue;
   }

   return ATfalse;
}
#endif

//========================================================================================
// EndProgramStmt
//----------------------------------------------------------------------------------------
// TODO-TODO-TODO-TODO-TODO-TODO-TODO
ATbool ofp_traverse_EndProgramStmt(ATerm term, pOFP_Traverse EndProgramStmt)
{
#ifdef DEBUG_PRINT
   printf("\nEndProgramStmt: %s\n", ATwriteToString(term));
#endif

 ATbool matched = ATfalse;
 OFP_Traverse Label, OptProgramName1, EOS;
 if (ATmatch(term, "EndProgramStmt(<term>,<term>,<term>)", &Label.term, &OptProgramName1.term, &EOS.term)) {

   if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
         matched = ATtrue;
      } else return ATfalse;
   }

   if (ATmatch(OptProgramName1.term, "Some(<term>)", &OptProgramName1.term)) {
   if (ATmatch(OptProgramName1.term, "(Some(<term>))", &OptProgramName1.term)) {
      if (ofp_traverse_ProgramName(OptProgramName1.term, &OptProgramName1)) {
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
// ProgramStmt
//----------------------------------------------------------------------------------------
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
