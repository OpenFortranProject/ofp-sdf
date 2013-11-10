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

#ifdef FINISHED
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
#endif

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
