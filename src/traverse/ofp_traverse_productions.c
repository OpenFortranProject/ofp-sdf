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

      char * StartCommentBlock_val;
      if (ATmatch(StartCommentBlock_term.term, "Some(<str>)", &StartCommentBlock_val)) {
         // MATCHED StartCommentBlock
      }

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
ATbool ofp_traverse_ProgramUnit(ATerm term, pOFP_Traverse ProgramUnit)
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
   if (ATmatch(term, "Name(<term>)", &Ident_term.term)) {
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

   OFP_Traverse Label_term, OptProgramName1_term, EOS_term;
   if (ATmatch(term, "EndProgramStmt(<term>,<term>,<term>)", &Label_term.term, &OptProgramName1_term.term, &EOS_term.term)) {

      OFP_Traverse Label;
      if (ATmatch(Label_term.term, "Some(<term>)", &Label.term)) {
         if (ofp_traverse_Label(Label.term, &Label)) {
            // MATCHED Label
         } else return ATfalse;
      }

      OFP_Traverse ProgramName;
      if (ATmatch(OptProgramName1_term.term, "Some((Some(<term>)))", &ProgramName.term)) {
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
