#include "traversal.h"
#include <assert.h>

#define DEBUG_PRINT

ATbool ofp_traverse_EOS(ATerm term, pOFP_Traverse EOS)
{
   char * EOS_val;

#ifdef DEBUG_PRINT
   printf("EOS: %s\n", ATwriteToString(term));
#endif

   if (ATmatch(term, "<str>", &EOS_val)) {
      return ATtrue;
   }
   return ATfalse;
}

ATbool ofp_traverse_Label(ATerm term, pOFP_Traverse Label)
{
#ifdef DEBUG_PRINT
   printf("Label: %s\n", ATwriteToString(term));
#endif

   if (ATmatch(term, "Label(<term>)", &Label->term)) {
      int Label_val;
      if (ATmatch(term, "Label(<int>)", &Label_val)) {
         return ATtrue;
      }
      return ATfalse;
   }
   return ATfalse;
}

ATbool ofp_traverse_Name(ATerm term, pOFP_Traverse Name)
{
#ifdef DEBUG_PRINT
   printf("Name: %s\n", ATwriteToString(term));
#endif

   if (ATmatch(term, "Name(<term>)", &Name->term)) {
      char * Name_val;
      if (ATmatch(term, "Name(<str>)", &Name_val)) {
         return ATtrue;
      }
      return ATfalse;
   }
   return ATfalse;
}

//========================================================================================
// R201 program
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_Program(ATerm term, pOFP_Traverse StartCommentBlock_opt, pOFP_Traverse ProgramUnit_list)
{
#ifdef DEBUG_PRINT
   printf("Program: %s\n", ATwriteToString(term));
#endif

   if (ATmatch(term, "Program(<term>,<term>)", &StartCommentBlock_opt->term, &ProgramUnit_list->term) ) {
      ATermList ProgramUnit_tail = (ATermList) ATmake("<term>", ProgramUnit_list->term);

      while (! ATisEmpty(ProgramUnit_tail)) {
         OFP_Traverse ProgramUnit;
         ProgramUnit.term = ATgetFirst(ProgramUnit_tail);
         ProgramUnit_tail = ATgetNext(ProgramUnit_tail);
         if (! ofp_traverse_ProgramUnit(ProgramUnit.term, &ProgramUnit)) {
            return ATfalse;
         }
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

   if (ATmatch(term, "ProgramUnit(<term>)", &ProgramUnit->term)) {
      OFP_Traverse ProgramStmt_opt, SpecificationPart, ExecutionPart, InternalSubprogramPart_opt, EndProgramStmt;
      if (ofp_traverse_MainProgram(ProgramUnit->term, &ProgramStmt_opt, &SpecificationPart, &ExecutionPart, &InternalSubprogramPart_opt, &EndProgramStmt)) {
         return ATtrue;
      }
      return ATfalse;
   }

   //TODO | ExternalSubprogram
   //TODO | Module
   //TODO | Submodule
   //TODO | BlockData

   return ATfalse;
}

//========================================================================================
// R204 specification-part
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_SpecificationPart(ATerm term, pOFP_Traverse UseStmt_list, pOFP_Traverse ImportStmt_list, pOFP_Traverse ImplicitPart_opt, pOFP_Traverse DeclarationConstruct_list)
{
#ifdef DEBUG_PRINT
   printf("\nSpecificationPart: %s\n", ATwriteToString(term));
#endif

   if (ATmatch(term, "SpecificationPart(<term>,<term>,<term>,<term>)", &UseStmt_list->term, &ImportStmt_list->term, &ImplicitPart_opt->term, &DeclarationConstruct_list)) {
      // TODO
      return ATtrue;
   }

   return ATfalse;
}

//========================================================================================
// R207 declaration-construct
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_declaration_construct(ATerm term)
{
   ATbool  matched;
   ATerm   decl_construct;
   ATerm   t1, t2, t3;

   matched = ATmatch(term, "declaration-construct(<term>)", &decl_construct);
   if (!matched) return ATfalse;

   if (matched = ATmatch(decl_construct,"type-declaration-stmt(<term>,<term>,<term>)",&t1,&t2,&t3)) {
      matched = ofp_traverse_type_declaration_stmt(decl_construct);
   }

   return matched;
}

ATbool ofp_traverse_declaration_construct_list(ATerm term)
{
   ATerm     head;
   ATermList tail;

   if (! ATmatch(term, "declaration-construct-list(<list>)", &tail)) return ATfalse;

   while (! ATisEmpty(tail)) {
      head = ATgetFirst (tail);
      tail = ATgetNext  (tail);
      if ( ofp_traverse_declaration_construct(head) != ATtrue) return ATfalse;
   }

   return ATtrue;
}

//========================================================================================
// R208 execution-part
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_ExecutionPart(ATerm term, pOFP_Traverse ExecutionPartConstruct_list)
{
#ifdef DEBUG_PRINT
   printf("\nExecutionPart: %s\n", ATwriteToString(term));
#endif

   if (ATmatch(term, "ExecutionPart(<term>)", &ExecutionPartConstruct_list->term)) {
      return ATtrue;
   }

   return ATfalse;
}

//========================================================================================
// R209-F08 execution-part-construct
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_execution_part_construct(ATerm term)
{
   //TODO PUTBACK   if ( ofp_traverse_format_stmt          (term) ) return ATtrue;
   //TODO PUTBACK   if ( ofp_traverse_entry_stmt           (term) ) return ATtrue;
   //TODO PUTBACK   if ( ofp_traverse_data_stmt            (term) ) return ATtrue;

   if ( ofp_traverse_executable_construct (term) ) return ATtrue;

   return ATfalse;
}

ATbool ofp_traverse_executable_part_construct_list(ATerm term)
{
   ATerm     head;
   ATermList tail;

   if (! ATmatch(term, "executable-part-construct-list(<list>)", &tail)) return ATfalse;

   while (! ATisEmpty(tail)) {
      head = ATgetFirst (tail);
      tail = ATgetNext  (tail);
      if ( ofp_traverse_executable_construct(head) != ATtrue) return ATfalse;
   }

   return ATtrue;
}

//========================================================================================
// R210 internal-subprogram-part
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_InternalSubprogramPart(ATerm term, pOFP_Traverse ContainsStmt, pOFP_Traverse InternalSubprogram_list)
{
#ifdef DEBUG_PRINT
   printf("\nInternalSubprogramPart: %s\n", ATwriteToString(term));
#endif

   if (ATmatch(term, "InternalSubprogramPart(<term>,<term>)", &ContainsStmt->term, &InternalSubprogram_list->term)) {
      return ATtrue;
   }

   return ATfalse;
}

//========================================================================================
// R213-F08 executable-construct
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_executable_construct(ATerm term)
{
   if ( ofp_traverse_action_stmt (term) ) return ATtrue;
   //TODO PUTBACK other branches

   return ATfalse;
}

//========================================================================================
// R214-F08 action-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_action_stmt(ATerm term)
{
   if ( ofp_traverse_assignment_stmt (term) ) return ATtrue;
   //TODO PUTBACK other branches

   return ATfalse;
}

/**
 * Section/Clause 4: Types
 */

//========================================================================================
// R403-F08 declaration-type-spec
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_declaration_type_spec(ATerm term)
{
   ATbool  matched;
   ATerm   intrinsic_type_spec;

   matched = ATmatch(term, "declaration-type-spec(<term>)", &intrinsic_type_spec);
   if (!matched) return ATfalse;

   if (ofp_traverse_intrinsic_type_spec (intrinsic_type_spec) == ATfalse) return ATfalse;

   return matched;
}

//========================================================================================
// R404-F08 intrinsic-type-spec
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_intrinsic_type_spec(ATerm term)
{
   ATbool  matched;
   ATerm   type, kind;

   matched = ATmatch(term, "intrinsic-type-spec(<term>,<term>)", &type, &kind);
   if (!matched) return ATfalse;

   if (ATmatch(type, "REAL")) {printf("REAL"); return ATtrue;}

   ATprintf("%t", kind);

   return matched;
}

//========================================================================================
// R407-F08  int-literal-constant
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_int_literal_constant(ATerm term)
{
   int i;

   if (! ATmatch(term, "int-literal-constant(<int>)", &i)) return ATfalse;
   printf("%d", i);

   return ATtrue;
}

/**
 * Section/Clause 5: Attribute declarations and specifications
 */

//========================================================================================
// R501-F08 type-declaration-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_type_declaration_stmt(ATerm term)
{
   ATbool     matched;
   ATerm      decl_construct;
   ATerm      label, decl_type_spec;
   ATerm      entity_decl_list;

   matched = ATmatch(term, "type-declaration-stmt(<term>, <term>, <term>)",
                     &label,
                     &decl_type_spec,
                     &entity_decl_list);
   if (!matched) return ATfalse;

   //   ofp_traverse_label(label);   /* optional */

   if ( ofp_traverse_declaration_type_spec (decl_type_spec) != ATtrue ) return ATfalse;
   printf(" :: ");

   if ( ofp_traverse_entity_decl_list (entity_decl_list)    != ATtrue ) return ATfalse;
   printf("\n");

   return ATtrue;
}

//========================================================================================
// R503-F08 entity-decl
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_entity_decl(ATerm term)
{
   char *  object;

   if ( ATmatch(term, "object-name(name(<str>))", &object) != ATtrue ) return ATfalse;
   printf("%s", object);

   return ATtrue;
}

ATbool ofp_traverse_entity_decl_list(ATerm term)
{
   ATerm     head;
   ATermList tail;
   char *    comma   = "";

   if ( ATmatch(term, "entity-decl-list(<term>)", &tail) != ATtrue ) return ATfalse;

   while (!ATisEmpty(tail)) {
      head = ATgetFirst (tail);
      tail = ATgetNext  (tail);
      printf("%s", comma);      comma = ",";
      if ( ofp_traverse_entity_decl (head) != ATtrue ) return ATfalse;
   }

   return ATtrue;
}

//========================================================================================
// R601-F08 designator
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_designator(ATerm term)
{
   ATerm data_ref;

   if (! ATmatch(term, "designator(<term>)", &data_ref)) return ATfalse;
   if (! ofp_traverse_data_ref(data_ref))                return ATfalse;

   return ATtrue;
}

//========================================================================================
// R602-F08 variable
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_variable(ATerm term)
{
   ATerm designator;

   if (! ATmatch(term, "variable(<term>)", &designator)) return ATfalse;
   if (! ofp_traverse_designator(designator))            return ATfalse;

   return ATtrue;
}

//========================================================================================
// R611-F08 data-ref
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_data_ref(ATerm term)
{
   ATerm list;

   if (! ATmatch(term, "data-ref(<term>)", &list)) return ATfalse;
   if (! ofp_traverse_part_ref(list))              return ATfalse;

   return ATtrue;
}

//========================================================================================
// R612-F08 part-ref
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_part_ref(ATerm term)
{
   ATermList tail;
   ATerm  head;
   char * id, * percent = "";

   if (! ATmatch(term, "<term>)", &tail)) return ATfalse;

   while (! ATisEmpty(tail)) {
      head = ATgetFirst (tail);
      tail = ATgetNext  (tail);
      if (! ATmatch(head, "part-ref(<str>)", &id)) return ATfalse;
      printf("%s%s", id, percent);      percent = "%";
   }

   return ATtrue;
}


//========================================================================================
// R722-F08  expr
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_expr(ATerm term)
{
   ATerm int_literal_constant;

   if (! ATmatch(term, "expr(<term>)", &int_literal_constant))    return ATfalse;
   if (! ofp_traverse_int_literal_constant(int_literal_constant)) return ATfalse;

   return ATtrue;
}

//========================================================================================
// R732-F08 assignment-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_assignment_stmt(ATerm term)
{
   ATerm label, var, expr;

   if (! ATmatch(term,"assignment-stmt(<term>,<term>,<term>)",&label,&var,&expr)) return ATfalse;

   //   ofp_traverse_label(label);         /* optional */

   if (! ofp_traverse_variable(var)) return ATfalse;
   printf(" = ");
   if (! ofp_traverse_expr(expr)   ) return ATfalse;
   printf("\n");

   return ATtrue;
}

//========================================================================================
// R1101 main-program
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_MainProgram(ATerm term, pOFP_Traverse ProgramStmt_opt, pOFP_Traverse SpecificationPart, pOFP_Traverse ExecutionPart, pOFP_Traverse InternalSubprogramPart_opt, pOFP_Traverse EndProgramStmt)
{
#ifdef DEBUG_PRINT
   printf("\nMainProgram: %s\n", ATwriteToString(term));
#endif

   if (ATmatch(term, "MainProgram(<term>,<term>,<term>,<term>,<term>)", &ProgramStmt_opt->term, &SpecificationPart->term, &ExecutionPart->term, &InternalSubprogramPart_opt->term, &EndProgramStmt->term)) {
      if (ATmatch(ProgramStmt_opt->term, "Some(<term>)", &ProgramStmt_opt->term)) {
         OFP_Traverse Label_opt, ProgramName, EOS;
         if (! ofp_traverse_ProgramStmt(ProgramStmt_opt->term, &Label_opt, &ProgramName, &EOS)) {
            return ATfalse;
         }
      }

      {
         OFP_Traverse UseStmt_list, ImportStmt_list, ImplicitPart_opt, DeclarationConstruct_list;
         if (! ofp_traverse_SpecificationPart(SpecificationPart->term, &UseStmt_list, &ImportStmt_list, &ImplicitPart_opt, &DeclarationConstruct_list)) {
            return ATfalse;
         }
      }

      {
         OFP_Traverse ExecutionPartConstruct_list;
         if (! ofp_traverse_ExecutionPart(ExecutionPart->term, &ExecutionPartConstruct_list)) {
            return ATfalse;
         }
      }

      if (ATmatch(InternalSubprogramPart_opt->term, "Some(<term>)", &InternalSubprogramPart_opt->term)) {
         OFP_Traverse ContainsStmt, InternalSubprogram_list;
         if (! ofp_traverse_InternalSubprogramPart(InternalSubprogramPart_opt->term, &ContainsStmt, &InternalSubprogram_list)) {
            return ATfalse;
         }
      }

      {
         OFP_Traverse Label_opt, ProgramName_opt, EOS;
         if (! ofp_traverse_EndProgramStmt(EndProgramStmt->term, &Label_opt, &ProgramName_opt, &EOS)) {
            return ATfalse;
         }
      }

      return ATtrue;
   }

   return ATfalse;
}

//========================================================================================
// R1102 program-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_ProgramStmt(ATerm term, pOFP_Traverse Label_opt, pOFP_Traverse ProgramName, pOFP_Traverse EOS)
{
#ifdef DEBUG_PRINT
   printf("\nProgramStmt: %s\n", ATwriteToString(term));
#endif

   if (ATmatch(term, "ProgramStmt(<term>,<term>,<term>)", &Label_opt->term, &ProgramName->term, &EOS->term)) {
      if (ATmatch(Label_opt->term, "Some(<term>)", &Label_opt->term)) {
         if (! ofp_traverse_Label(Label_opt->term, Label_opt)) {
            return ATfalse;
         }
      }
      if (! ofp_traverse_Name(ProgramName->term, ProgramName)) {
            return ATfalse;
      }
      if (! ofp_traverse_EOS(EOS->term, EOS)) {
         return ATfalse;
      }
      return ATtrue;
   }
   return ATfalse;
}

//========================================================================================
// R1103 end-program-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_EndProgramStmt(ATerm term, pOFP_Traverse Label_opt, pOFP_Traverse ProgramName_opt, pOFP_Traverse EOS)
{
#ifdef DEBUG_PRINT
   printf("\nEndProgramStmt: %s\n", ATwriteToString(term));
#endif

   if (ATmatch(term, "EndProgramStmt(<term>,<term>,<term>)", &Label_opt->term, &ProgramName_opt->term, &EOS->term)) {
      if (ATmatch(Label_opt->term, "Some(<term>)", &Label_opt->term)) {
         if (! ofp_traverse_Label(Label_opt->term, Label_opt)) {
            return ATfalse;
         }
      }
      if (ATmatch(ProgramName_opt->term, "Some((Some(<term>)))", &ProgramName_opt->term)) {
         if (! ofp_traverse_Name(ProgramName_opt->term, ProgramName_opt)) {
            return ATfalse;
         }
      }
      if (! ofp_traverse_EOS(EOS->term, EOS)) {
         return ATfalse;
      }
      return ATtrue;
   }
   return ATfalse;
}

ATbool ofp_traverse_end_program_stmt(ATerm term)
{
   ATerm  label, name;

   if (! ATmatch(term, "end-program-stmt(<term>,<term>)", &label, &name)) return ATfalse;

   //   ofp_traverse_label(label);         /* optional */
   printf("END PROGRAM");

   //   ofp_traverse_program_name(name);   /* optional */
   printf("\n");

   return ATtrue;
}
