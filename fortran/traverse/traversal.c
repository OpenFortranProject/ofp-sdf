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
