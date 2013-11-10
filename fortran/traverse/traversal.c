#include "traversal.h"
#include <assert.h>

#define DEBUG_PRINT

/**
 * Perform any necessary initialization for this traversal
 */
ATbool ofp_traverse_init()
{
   return ATtrue;
}

ATbool ofp_traverse_Name(ATerm term, pOFP_Traverse Name)
{
#ifdef DEBUG_PRINT
   printf("Name: %s\n", ATwriteToString(term));
#endif

   if (ATmatch(term, "Name(<term>)", &Name->term)) {
      char * Name_val;
      if (ATmatch(term, "Name(<str>)", &Name_val)) {
         // MATCHED Name
         return ATtrue;
      }
      return ATfalse;
   }
   return ATfalse;
}

//========================================================================================
// R204 specification-part
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_SpecificationPart_orig(ATerm term, pOFP_Traverse SpecificationPart)
{
#ifdef DEBUG_PRINT
   printf("\nSpecificationPart: %s\n", ATwriteToString(term));
#endif

   OFP_Traverse UseStmt_list, ImportStmt_list, ImplicitPart, DeclarationConstruct_list;
   if (ATmatch(term, "SpecificationPart(<term>,<term>,<term>,<term>)", &UseStmt_list.term, &ImportStmt_list.term, &ImplicitPart.term, &DeclarationConstruct_list.term)) {

      // TODO UseStmt*
      // TODO ImportStmt*
      // TODO ImplicitPart?
      // TODO DeclarationConstruct*

      ATermList DeclarationConstruct_tail = (ATermList) ATmake("<term>", DeclarationConstruct_list.term);
      while (! ATisEmpty(DeclarationConstruct_tail)) {
         OFP_Traverse DeclarationConstruct;
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
ATbool ofp_traverse_DeclarationConstruct_orig(ATerm term, pOFP_Traverse DeclarationConstruct)
{
#ifdef DEBUG_PRINT
   printf("\nDeclarationConstruct: %s\n", ATwriteToString(term));
#endif

   OFP_Traverse TypeDeclarationStmt;
   if (ATmatch(term, "DeclarationConstruct(<term>)", &TypeDeclarationStmt.term)) {
      if (ofp_traverse_TypeDeclarationStmt(TypeDeclarationStmt.term, &TypeDeclarationStmt)) {
         // MATCHED TypeDeclarationStmt
      } else return ATfalse;

      return ATtrue;
   }

#ifdef TODO
    DerivedTypeDef
  | EntryStmt
  | EnumDef
  | FormatStmt
  | InterfaceBlock
  | ParameterStmt
  | ProcedureDeclarationStmt
  | OtherSpecificationStmt
  | TypeDeclarationStmt
  | StmtFunctionStmt
#endif

   return ATfalse;
}

#ifdef FINISHED
//========================================================================================
// R208 execution-part
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_ExecutionPart(ATerm term, pOFP_Traverse ExecutionPart)
{
#ifdef DEBUG_PRINT
   printf("\nExecutionPart: %s\n", ATwriteToString(term));
#endif

   OFP_Traverse ExecutionPartConstruct_list;
   if (ATmatch(term, "ExecutionPart(<term>)", &ExecutionPartConstruct_list.term)) {
      ATermList ExecutionPartConstruct_tail = (ATermList) ATmake("<term>", ExecutionPartConstruct_list.term);

      while (! ATisEmpty(ExecutionPartConstruct_tail)) {
         OFP_Traverse ExecutionPartConstruct;
         ExecutionPartConstruct.term = ATgetFirst(ExecutionPartConstruct_tail);
         ExecutionPartConstruct_tail = ATgetNext(ExecutionPartConstruct_tail);
         if (ofp_traverse_ExecutionPartConstruct(ExecutionPartConstruct.term, &ExecutionPartConstruct)) {
            // MATCHED ExecutionPartConstruct
         } else return ATfalse;
      }
      return ATtrue;
   }

   return ATfalse;
}
#endif

#ifdef FINISHED
//========================================================================================
// R209 execution-part-construct
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_ExecutionPartConstruct(ATerm term, pOFP_Traverse ExecutionPartConstruct)
{
#ifdef DEBUG_PRINT
   printf("\nExecutionPartConstruct: %s\n", ATwriteToString(term));
#endif

   OFP_Traverse ExecutableConstruct;
   if (ATmatch(term, "ExecutionPartConstruct(<term>)", &ExecutableConstruct.term)) {

      if (ofp_traverse_ExecutableConstruct(ExecutableConstruct.term, &ExecutableConstruct)) {
         // MATCHED ExecutableConstruct
         return ATtrue;
      }
      // TODO   | FormatStmt
      // TODO   | EntryStmt
      // TODO   | DataStmt
   }

   return ATfalse;
}
#endif

#ifdef FINISHED
//========================================================================================
// R210 internal-subprogram-part
//----------------------------------------------------------------------------------------
vATbool ofp_traverse_InternalSubprogramPart(ATerm term, pOFP_Traverse InternalSubprogramPart)
{
#ifdef DEBUG_PRINT
   printf("\nInternalSubprogramPart: %s\n", ATwriteToString(term));
#endif

   OFP_Traverse ContainsStmt, InternalSubprogram_list;
   if (ATmatch(term, "InternalSubprogramPart(<term>,<term>)", &ContainsStmt.term, &InternalSubprogram_list.term)) {
      // MATCHED InternalSubprogramPart
      return ATtrue;
   }

   return ATfalse;
}
#endif

//========================================================================================
// R213 executable-construct
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_ExecutableConstruct(ATerm term, pOFP_Traverse ExecutableConstruct)
{
#ifdef DEBUG_PRINT
   printf("\ExecutableConstruct: %s\n", ATwriteToString(term));
#endif

   OFP_Traverse ActionStmt;
   if (ATmatch(term, "ExecutableConstruct(<term>)", &ActionStmt.term)) {

      if (ofp_traverse_ActionStmt(ActionStmt.term, &ActionStmt)) {
         // MATCHED ActionStmt
      } else return ATfalse;

         // | AssociateConstruct
         // | BlockConstruct
         // | CaseConstruct
         // | CriticalConstruct
         // %%| DoConstruct          %% Ambiguous - placed related statements in action-stmt
         // | ForallConstruct
         // | IfConstruct
         // | SelectTypeConstruct
         // | WhereConstruct

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
   printf("\ExecutableConstruct: %s\n", ATwriteToString(term));
#endif

   OFP_Traverse AssignmentStmt;
   if (ATmatch(term, "ActionStmt(<term>)", &AssignmentStmt.term)) {
      if (ofp_traverse_AssignmentStmt(AssignmentStmt.term, &AssignmentStmt)) {
         // MATCHED AssignmentStmt
         return ATtrue;
      }
      // TODO other options
   }

   return ATfalse;
}

/**
 * Section/Clause 4: Types
 */

//========================================================================================
// R405 kind-selector
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_KindSelector(ATerm term, pOFP_Traverse KindSelector)
{
#ifdef DEBUG_PRINT
   printf("KindSelector: %s\n", ATwriteToString(term));
#endif

   if (ATmatch(term, "KindSelector_KIND")) {
      // TODO KindSelector_KIND
      return ATtrue;
   }
   else if (ATmatch(term, "KindSelector_STAR")) {
      // TODO KindSelector_STAR
      return ATtrue;
   }

   return ATfalse;
}

//========================================================================================
// R407 int-literal-constant
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_IntLiteralConstant(ATerm term, pOFP_Traverse IntLiteralConstant)
{
#ifdef DEBUG_PRINT
   printf("IntLiteralConstant: %s\n", ATwriteToString(term));
#endif

   OFP_Traverse DigitString, KindParam;
   if (ATmatch(term, "IntLiteralConstant(<term>,<term>)", &DigitString.term, &KindParam.term)) {
      int i;
      if (ATmatch(term, "<int>", &i)) {
         // MATCHED integer constant
      } else return ATfalse;
      
      // TODO KindParam

      return ATtrue;
   }

   return ATtrue;
}


/**
 * Section/Clause 5: Attribute declarations and specifications
 */

//========================================================================================
// R501 TypeDeclarationStmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_TypeDeclarationStmt_orig(ATerm term, pOFP_Traverse TypeDeclarationStmt)
{
#ifdef DEBUG_PRINT
   printf("\nTypeDeclarationStmt: %s\n", ATwriteToString(term));
#endif

   OFP_Traverse Label, DeclarationTypeSpec, AttrSpec_list, EntityDecl_list, EOS;
   if (ATmatch(term, "TypeDeclarationStmt(<term>,<term>,<term>,<term>,<term>)", &Label.term, &DeclarationTypeSpec.term, &AttrSpec_list.term, &EntityDecl_list.term, &EOS.term)) {

      if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
         if (ofp_traverse_Label(Label.term, &Label)) {
            // MATCHED Label
         } else return ATfalse;
      }

      if (ofp_traverse_DeclarationTypeSpec(DeclarationTypeSpec.term, &DeclarationTypeSpec)) {
         // MATCHED DeclarationTypeSpec
      } else return ATfalse;

      if (ATmatch(AttrSpec_list.term, "Some((Some((<term>))))", &AttrSpec_list.term)) {
         ATermList AttrSpec_tail = (ATermList) ATmake("<term>", AttrSpec_list.term);

         while (! ATisEmpty(AttrSpec_tail)) {
            OFP_Traverse AttrSpec;
            AttrSpec.term = ATgetFirst(AttrSpec_tail);
            AttrSpec_tail = ATgetNext(AttrSpec_tail);

            // TODO AttrSpec
            printf("AttrSpec: %s\n", ATwriteToString(AttrSpec.term));
         }
      } else return ATfalse;

      ATermList EntityDecl_tail = (ATermList) ATmake("<term>", EntityDecl_list.term);
      while (! ATisEmpty(EntityDecl_tail)) {
         OFP_Traverse EntityDecl;
         EntityDecl.term = ATgetFirst(EntityDecl_tail);
         EntityDecl_tail = ATgetNext(EntityDecl_tail);
         if (ofp_traverse_EntityDecl(EntityDecl.term, &EntityDecl)) {
            // MATCHED EntityDecl
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
// R601 designator
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_Designator(ATerm term, pOFP_Traverse Designator)
{
#ifdef DEBUG_PRINT
   printf("Designator: %s\n", ATwriteToString(term));
#endif

   OFP_Traverse DataRef;
   if (ATmatch(term, "Designator(<term>)", &DataRef.term)) {
      if (ofp_traverse_DataRef(DataRef.term, &DataRef)) {
         // MATCHED DataRef
      } else return ATfalse;

      // TODO | Substring

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
      } else ATfalse;

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

   OFP_Traverse PartRef, PartRef_list;
   if (ATmatch(term, "DataRef(<term>,<term>)", &PartRef.term, &PartRef_list.term)) {
      if (ofp_traverse_PartRef(PartRef.term, &PartRef)) {
         // MATCHED PartRef
      } else ATfalse;

      // TODO PartRef_list

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

   OFP_Traverse PartName, SectionSubscript_list1, SectionSubscript_list2;
   if (ATmatch(term, "PartRef(<term>,<term>,<term>)", &PartName.term, &SectionSubscript_list1.term, &SectionSubscript_list2.term)) {

      if (ofp_traverse_Name(PartName.term, &PartName)) {
         // MATCHED PartName
      } else return ATfalse;

      // TODO array SectionSubscript list
      // TODO caarray SectionSubscript list

      return ATtrue;
   }

   return ATfalse;
}

//========================================================================================
// R722 expr
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_Expr(ATerm term, pOFP_Traverse Expr)
{
#ifdef DEBUG_PRINT
   printf("\nExpr: %s\n", ATwriteToString(term));
#endif

   OFP_Traverse IntLiteralConstant;
   if (ATmatch(term, "Expr(<term>)", &IntLiteralConstant.term)) {
      if (ofp_traverse_IntLiteralConstant(IntLiteralConstant.term, &IntLiteralConstant)) {
         // MATCHED IntLiteralConstant
      } else return ATfalse;

      return ATtrue;
   }

   return ATfalse;
}

//========================================================================================
// R732 assignment-stmt
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_AssignmentStmt(ATerm term, pOFP_Traverse AssignmentStmt)
{
#ifdef DEBUG_PRINT
   printf("\nAssignmentStmt: %s\n", ATwriteToString(term));
#endif

   OFP_Traverse Label, Variable, Expr, EOS;
   if (ATmatch(term, "AssignmentStmt(<term>,<term>,<term>,<term>)", &Label.term, &Variable.term, &Expr.term, &EOS.term)) {
      if (ATmatch(Label.term, "Some(<term>)", &Label.term)) {
         if (ofp_traverse_Label(Label.term, &Label)) {
            // MATCHED Label
         } else return ATfalse;
      }

      if (ofp_traverse_Variable(Variable.term, &Variable)) {
         // MATCHED Variable
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
