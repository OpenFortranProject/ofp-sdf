#include "traversal.h"

#ifdef DELETE_ME
ATbool ofp_traverse_ProgramName(ATerm term, pOFP_Traverse ProgramName);
#endif

// This is an alias
ATbool ofp_traverse_OptProgramName1(ATerm term, pOFP_Traverse OptProgramName1)
{
#ifdef DEBUG_PRINT
   printf("OptProgramName1: %s\n", ATwriteToString(term));
#endif

   if (ATmatch(term, "(Some(<term>))", &OptProgramName1->term)) {
      OFP_Traverse ProgramName;
      if (ofp_traverse_ProgramName(OptProgramName1->term, &ProgramName)) {
         // MATCHED ProgramName
      } else return ATfalse;
   }
   return ATtrue;
}

//========================================================================================
// R201 Program
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_Program(ATerm term, pOFP_Traverse Program)
{
#ifdef DEBUG_PRINT
   printf("Program: %s\n\n", ATwriteToString(term));
#endif

   OFP_Traverse StartCommentBlock_term, ProgramUnit_list;
   if (ATmatch(term, "Program(<term>,<term>)", &StartCommentBlock_term.term, &ProgramUnit_list.term)) {

      OFP_Traverse StartCommentBlock;
      if (ATmatch(StartCommentBlock_term.term, "Some(<term>)", &StartCommentBlock.term)) {
         if (ofp_traverse_StartCommentBlock(StartCommentBlock.term, &StartCommentBlock)) {
            // MATCHED StartCommentBlock
         } else return ATfalse;
      }

#ifdef OLD
      char * StartCommentBlock_val;
      if (ATmatch(StartCommentBlock_term.term, "Some(<str>)", &StartCommentBlock_val)) {
         // MATCHED StartCommentBlock
      }
#endif

      OFP_Traverse ProgramUnit;
      ATermList ProgramUnit_tail = (ATermList) ATmake("<term>", ProgramUnit_list.term);
      while (! ATisEmpty(ProgramUnit_tail)) {
         ProgramUnit.term = ATgetFirst(ProgramUnit_tail);
         ProgramUnit_tail = ATgetNext(ProgramUnit_tail);
         if (ofp_traverse_ProgramUnit(ProgramUnit.term, &ProgramUnit)) {
            // MATCHED ProgramUnit
         } else return ATfalse;
      }

      return ATtrue;
   }

   return ATfalse;
}

//========================================================================================
// R202 ProgramUnit
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_ProgramUnit_orig(ATerm term, pOFP_Traverse ProgramUnit)
{
#ifdef DEBUG_PRINT
   printf("ProgramUnit: %s\n\n", ATwriteToString(term));
#endif

   OFP_Traverse MainProgram_ExternalSubprogram_Module_Submodule_BlockData0_term;
   if (ATmatch(term, "ProgramUnit(<term>)", &MainProgram_ExternalSubprogram_Module_Submodule_BlockData0_term.term)) {

#ifdef NOT_YET
      OFP_Traverse BlockData;
      if (ATmatch(MainProgram_ExternalSubprogram_Module_Submodule_BlockData0_term.term, "<term>", &BlockData.term)) {
         if (ofp_traverse_BlockData(BlockData.term, &BlockData)) {
            // MATCHED BlockData
            return ATtrue;
         } else return ATfalse;
      }

      OFP_Traverse Submodule;
      if (ATmatch(MainProgram_ExternalSubprogram_Module_Submodule_BlockData0_term.term, "<term>", &Submodule.term)) {
         if (ofp_traverse_Submodule(Submodule.term, &Submodule)) {
            // MATCHED Submodule
            return ATtrue;
         } else return ATfalse;
      }

      OFP_Traverse Module;
      if (ATmatch(MainProgram_ExternalSubprogram_Module_Submodule_BlockData0_term.term, "<term>", &Module.term)) {
         if (ofp_traverse_Module(Module.term, &Module)) {
            // MATCHED Module
            return ATtrue;
         } else return ATfalse;
      }

      OFP_Traverse ExternalSubprogram;
      if (ATmatch(MainProgram_ExternalSubprogram_Module_Submodule_BlockData0_term.term, "<term>", &ExternalSubprogram.term)) {
         if (ofp_traverse_ExternalSubprogram(ExternalSubprogram.term, &ExternalSubprogram)) {
            // MATCHED ExternalSubprogram
            return ATtrue;
         } else return ATfalse;
      }
#endif

      OFP_Traverse MainProgram;
      if (ATmatch(MainProgram_ExternalSubprogram_Module_Submodule_BlockData0_term.term, "<term>", &MainProgram.term)) {
         if (ofp_traverse_MainProgram(MainProgram.term, &MainProgram)) {
            // MATCHED MainProgram
            return ATtrue;
         } else return ATfalse;
      }

      return ATfalse; /* for set of OR productions */

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

   OFP_Traverse UseStmt_list, ImportStmt_list, ImplicitPart_term, DeclarationConstruct_list;
   if (ATmatch(term, "SpecificationPart(<term>,<term>,<term>,<term>)", &UseStmt_list.term, &ImportStmt_list.term, &ImplicitPart_term.term, &DeclarationConstruct_list.term)) {

#ifdef NOT_YET
      OFP_Traverse UseStmt;
      ATermList UseStmt_tail = (ATermList) ATmake("<term>", UseStmt_list.term);
      while (! ATisEmpty(UseStmt_tail)) {
         UseStmt.term = ATgetFirst(UseStmt_tail);
         UseStmt_tail = ATgetNext(UseStmt_tail);
         if (ofp_traverse_UseStmt(UseStmt.term, &UseStmt)) {
            // MATCHED UseStmt
         } else return ATfalse;
      }

      OFP_Traverse ImportStmt;
      ATermList ImportStmt_tail = (ATermList) ATmake("<term>", ImportStmt_list.term);
      while (! ATisEmpty(ImportStmt_tail)) {
         ImportStmt.term = ATgetFirst(ImportStmt_tail);
         ImportStmt_tail = ATgetNext(ImportStmt_tail);
         if (ofp_traverse_ImportStmt(ImportStmt.term, &ImportStmt)) {
            // MATCHED ImportStmt
         } else return ATfalse;
      }

      OFP_Traverse ImplicitPart;
      if (ATmatch(ImplicitPart_term.term, "Some(<term>)", &ImplicitPart.term)) {
         if (ofp_traverse_ImplicitPart(ImplicitPart.term, &ImplicitPart)) {
            // MATCHED ImplicitPart
         } else return ATfalse;
      }
#endif

      OFP_Traverse DeclarationConstruct;
      ATermList DeclarationConstruct_tail = (ATermList) ATmake("<term>", DeclarationConstruct_list.term);
      while (! ATisEmpty(DeclarationConstruct_tail)) {
         DeclarationConstruct.term = ATgetFirst(DeclarationConstruct_tail);
         DeclarationConstruct_tail = ATgetNext(DeclarationConstruct_tail);
         if (ofp_traverse_DeclarationConstruct(DeclarationConstruct.term, &DeclarationConstruct)) {
            // MATCHED DeclarationConstruct
         } else return ATfalse;
      }

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

   OFP_Traverse DerivedTypeDef_EntryStmt_EnumDef_FormatStmt_InterfaceBlock_ParameterStmt_ProcedureDeclarationStmt_OtherSpecificationStmt_TypeDeclarationStmt_StmtFunctionStmt0_term;
   if (ATmatch(term, "DeclarationConstruct(<term>)", &DerivedTypeDef_EntryStmt_EnumDef_FormatStmt_InterfaceBlock_ParameterStmt_ProcedureDeclarationStmt_OtherSpecificationStmt_TypeDeclarationStmt_StmtFunctionStmt0_term.term)) {

      OFP_Traverse TypeDeclarationStmt;
      if (ATmatch(DerivedTypeDef_EntryStmt_EnumDef_FormatStmt_InterfaceBlock_ParameterStmt_ProcedureDeclarationStmt_OtherSpecificationStmt_TypeDeclarationStmt_StmtFunctionStmt0_term.term, "<term>", &TypeDeclarationStmt.term)) {
         if (ofp_traverse_TypeDeclarationStmt(TypeDeclarationStmt.term, &TypeDeclarationStmt)) {
            // MATCHED TypeDeclarationStmt
            return ATtrue;
         } else return ATfalse;
      }

#ifdef NOTYET
      OFP_Traverse OtherSpecificationStmt;
      if (ATmatch(DerivedTypeDef_EntryStmt_EnumDef_FormatStmt_InterfaceBlock_ParameterStmt_ProcedureDeclarationStmt_OtherSpecificationStmt_TypeDeclarationStmt_StmtFunctionStmt0_term.term, "<term>", &OtherSpecificationStmt.term)) {
         if (ofp_traverse_OtherSpecificationStmt(OtherSpecificationStmt.term, &OtherSpecificationStmt)) {
            // MATCHED OtherSpecificationStmt
            return ATtrue;
         } else return ATfalse;
      }

      OFP_Traverse ProcedureDeclarationStmt;
      if (ATmatch(DerivedTypeDef_EntryStmt_EnumDef_FormatStmt_InterfaceBlock_ParameterStmt_ProcedureDeclarationStmt_OtherSpecificationStmt_TypeDeclarationStmt_StmtFunctionStmt0_term.term, "<term>", &ProcedureDeclarationStmt.term)) {
         if (ofp_traverse_ProcedureDeclarationStmt(ProcedureDeclarationStmt.term, &ProcedureDeclarationStmt)) {
            // MATCHED ProcedureDeclarationStmt
            return ATtrue;
         } else return ATfalse;
      }

      OFP_Traverse InterfaceBlock;
      if (ATmatch(DerivedTypeDef_EntryStmt_EnumDef_FormatStmt_InterfaceBlock_ParameterStmt_ProcedureDeclarationStmt_OtherSpecificationStmt_TypeDeclarationStmt_StmtFunctionStmt0_term.term, "<term>", &InterfaceBlock.term)) {
         if (ofp_traverse_InterfaceBlock(InterfaceBlock.term, &InterfaceBlock)) {
            // MATCHED InterfaceBlock
            return ATtrue;
         } else return ATfalse;
      }

      OFP_Traverse FormatStmt;
      if (ATmatch(DerivedTypeDef_EntryStmt_EnumDef_FormatStmt_InterfaceBlock_ParameterStmt_ProcedureDeclarationStmt_OtherSpecificationStmt_TypeDeclarationStmt_StmtFunctionStmt0_term.term, "<term>", &FormatStmt.term)) {
         if (ofp_traverse_FormatStmt(FormatStmt.term, &FormatStmt)) {
            // MATCHED FormatStmt
            return ATtrue;
         } else return ATfalse;
      }

      OFP_Traverse EnumDef;
      if (ATmatch(DerivedTypeDef_EntryStmt_EnumDef_FormatStmt_InterfaceBlock_ParameterStmt_ProcedureDeclarationStmt_OtherSpecificationStmt_TypeDeclarationStmt_StmtFunctionStmt0_term.term, "<term>", &EnumDef.term)) {
         if (ofp_traverse_EnumDef(EnumDef.term, &EnumDef)) {
            // MATCHED EnumDef
            return ATtrue;
         } else return ATfalse;
      }

      OFP_Traverse EntryStmt;
      if (ATmatch(DerivedTypeDef_EntryStmt_EnumDef_FormatStmt_InterfaceBlock_ParameterStmt_ProcedureDeclarationStmt_OtherSpecificationStmt_TypeDeclarationStmt_StmtFunctionStmt0_term.term, "<term>", &EntryStmt.term)) {
         if (ofp_traverse_EntryStmt(EntryStmt.term, &EntryStmt)) {
            // MATCHED EntryStmt
            return ATtrue;
         } else return ATfalse;
      }

      OFP_Traverse DerivedTypeDef;
      if (ATmatch(DerivedTypeDef_EntryStmt_EnumDef_FormatStmt_InterfaceBlock_ParameterStmt_ProcedureDeclarationStmt_OtherSpecificationStmt_TypeDeclarationStmt_StmtFunctionStmt0_term.term, "<term>", &DerivedTypeDef.term)) {
         if (ofp_traverse_DerivedTypeDef(DerivedTypeDef.term, &DerivedTypeDef)) {
            // MATCHED DerivedTypeDef
            return ATtrue;
         } else return ATfalse;
      }
#endif

      return ATfalse; /* for set of OR productions */

      return ATtrue;
   }

   return ATfalse;
}

//========================================================================================
// R501 TypeDeclarationStmt
//----------------------------------------------------------------------------------------
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

//========================================================================================
// R1101 MainProgram
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_MainProgram(ATerm term, pOFP_Traverse MainProgram)
{
#ifdef DEBUG_PRINT
   printf("MainProgram: %s\n", ATwriteToString(term));
#endif

   OFP_Traverse ProgramStmt_term, SpecificationPart_term, ExecutionPart_term, InternalSubprogramPart_term, EndProgramStmt_term;
   if (ATmatch(term, "MainProgram(<term>,<term>,<term>,<term>,<term>)", &ProgramStmt_term.term, &SpecificationPart_term.term, &ExecutionPart_term.term, &InternalSubprogramPart_term.term, &EndProgramStmt_term.term)) {

      OFP_Traverse ProgramStmt;
      if (ATmatch(ProgramStmt_term.term, "Some(<term>)", &ProgramStmt.term)) {
         if (ofp_traverse_ProgramStmt(ProgramStmt.term, &ProgramStmt)) {
            // MATCHED ProgramStmt
         } else return ATfalse;
      }

      OFP_Traverse SpecificationPart;
      if (ATmatch(SpecificationPart_term.term, "<term>", &SpecificationPart.term)) {
         if (ofp_traverse_SpecificationPart(SpecificationPart.term, &SpecificationPart)) {
            // MATCHED SpecificationPart
         } else return ATfalse;
      } else return ATfalse;

      OFP_Traverse ExecutionPart;
      if (ATmatch(ExecutionPart_term.term, "<term>", &ExecutionPart.term)) {
         if (ofp_traverse_ExecutionPart(ExecutionPart.term, &ExecutionPart)) {
            // MATCHED ExecutionPart
         } else return ATfalse;
      } else return ATfalse;

      OFP_Traverse InternalSubprogramPart;
      if (ATmatch(InternalSubprogramPart_term.term, "Some(<term>)", &InternalSubprogramPart.term)) {
         if (ofp_traverse_InternalSubprogramPart(InternalSubprogramPart.term, &InternalSubprogramPart)) {
            // MATCHED InternalSubprogramPart
         } else return ATfalse;
      }

      OFP_Traverse EndProgramStmt;
      if (ATmatch(EndProgramStmt_term.term, "<term>", &EndProgramStmt.term)) {
         if (ofp_traverse_EndProgramStmt(EndProgramStmt.term, &EndProgramStmt)) {
            // MATCHED EndProgramStmt
         } else return ATfalse;
      } else return ATfalse;

      return ATtrue;
   }

   return ATfalse;
}

//========================================================================================
// ProgramName
//----------------------------------------------------------------------------------------
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

//========================================================================================
// EndProgramStmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_EndProgramStmt(ATerm term, pOFP_Traverse EndProgramStmt)
{
#ifdef DEBUG_PRINT
   printf("EndProgramStmt: %s\n", ATwriteToString(term));
#endif

   OFP_Traverse Label_opt, OptProgramName1_opt, EOS_term;
   if (ATmatch(term, "EndProgramStmt(<term>,<term>,<term>)", &Label_opt.term, &OptProgramName1_opt.term, &EOS_term.term)) {

      OFP_Traverse Label;
      if (ATmatch(Label_opt.term, "Some(<term>)", &Label.term)) {
         if (ofp_traverse_Label(Label.term, &Label)) {
            // MATCHED Label
         } else return ATfalse;
      }

      OFP_Traverse OptProgramName1;
      if (ATmatch(OptProgramName1_opt.term, "Some(<term>)", &OptProgramName1.term)) {
         if (ofp_traverse_OptProgramName1(OptProgramName1.term, &OptProgramName1)) {
            // MATCHED OptProgramName1
         } else return ATfalse;
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

//========================================================================================
// ProgramStmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_ProgramStmt(ATerm term, pOFP_Traverse ProgramStmt)
{
#ifdef DEBUG_PRINT
   printf("ProgramStmt: %s\n", ATwriteToString(term));
#endif

   OFP_Traverse Label_term, ProgramName_term, EOS_term;
   if (ATmatch(term, "ProgramStmt(<term>,<term>,<term>)", &Label_term.term, &ProgramName_term.term, &EOS_term.term)) {

      OFP_Traverse Label;
      if (ATmatch(Label_term.term, "Some(<term>)", &Label.term)) {
         if (ofp_traverse_Label(Label.term, &Label)) {
            // MATCHED Label
         } else return ATfalse;
      }

      OFP_Traverse ProgramName;
      if (ATmatch(ProgramName_term.term, "<term>", &ProgramName.term)) {
         if (ofp_traverse_ProgramName(ProgramName.term, &ProgramName)) {
            // MATCHED ProgramName
         } else return ATfalse;
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
