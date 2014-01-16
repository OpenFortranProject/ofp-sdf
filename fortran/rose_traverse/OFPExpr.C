#include "OFPExpr.h"

OFP::Expr::~Expr()
{
   if (pExpr1)            delete pExpr1;
   if (pExpr2)            delete pExpr2;
   if (pPrimary)          delete pPrimary;
   if (pDefinedBinaryOp)  delete pDefinedBinaryOp;
   if (pDefinedUnaryOp)   delete pDefinedUnaryOp;
}

//========================================================================================
// R722 expr
//----------------------------------------------------------------------------------------
ATbool ofp_traverse_Expr(ATerm term, OFP::Expr* Expr)
{
#ifdef DEBUG_PRINT
   printf("Expr: %s\n", ATwriteToString(term));
#endif

 OFP::Expr Expr1, Expr2;
 OFP::DefinedBinaryOp DefinedBinaryOp;
 if (ATmatch(term, "DefBinExpr(<term>,<term>,<term>)", &Expr1.term, &DefinedBinaryOp.term, &Expr2.term)) {

      if (ofp_traverse_Expr(Expr1.term, &Expr1)) {
         // MATCHED Expr
         Expr->setExpr1(Expr1.newExpr());
      } else return ATfalse;

      if (ofp_traverse_DefinedBinaryOp(DefinedBinaryOp.term, &DefinedBinaryOp)) {
         // MATCHED DefinedBinaryOp
         Expr->setDefinedBinaryOp(DefinedBinaryOp.newDefinedBinaryOp());
      } else return ATfalse;

      if (ofp_traverse_Expr(Expr2.term, &Expr2)) {
         // MATCHED Expr
         Expr->setExpr2(Expr2.newExpr());
      } else return ATfalse;

   // MATCHED DefBinExpr
   Expr->setOptionType(OFP::Expr::DefBinExpr);

   return ATtrue;
 }

 if (ATmatch(term, "NotEqvExpr(<term>,<term>)", &Expr1.term, &Expr2.term)) {

      if (ofp_traverse_Expr(Expr1.term, &Expr1)) {
         // MATCHED Expr
         Expr->setExpr1(Expr1.newExpr());
      } else return ATfalse;

      if (ofp_traverse_Expr(Expr2.term, &Expr2)) {
         // MATCHED Expr
         Expr->setExpr2(Expr2.newExpr());
      } else return ATfalse;

   // MATCHED NotEqvExpr
   Expr->setOptionType(OFP::Expr::NotEqvExpr);

   return ATtrue;
 }

 if (ATmatch(term, "EqvExpr(<term>,<term>)", &Expr1.term, &Expr2.term)) {

      if (ofp_traverse_Expr(Expr1.term, &Expr1)) {
         // MATCHED Expr
         Expr->setExpr1(Expr1.newExpr());
      } else return ATfalse;

      if (ofp_traverse_Expr(Expr2.term, &Expr2)) {
         // MATCHED Expr
         Expr->setExpr2(Expr2.newExpr());
      } else return ATfalse;

   // MATCHED EqvExpr
   Expr->setOptionType(OFP::Expr::EqvExpr);

   return ATtrue;
 }

 if (ATmatch(term, "OrExpr(<term>,<term>)", &Expr1.term, &Expr2.term)) {

      if (ofp_traverse_Expr(Expr1.term, &Expr1)) {
         // MATCHED Expr
         Expr->setExpr1(Expr1.newExpr());
      } else return ATfalse;

      if (ofp_traverse_Expr(Expr2.term, &Expr2)) {
         // MATCHED Expr
         Expr->setExpr2(Expr2.newExpr());
      } else return ATfalse;

   // MATCHED OrExpr
   Expr->setOptionType(OFP::Expr::OrExpr);

   return ATtrue;
 }

 if (ATmatch(term, "AndExpr(<term>,<term>)", &Expr1.term, &Expr2.term)) {

      if (ofp_traverse_Expr(Expr1.term, &Expr1)) {
         // MATCHED Expr
         Expr->setExpr1(Expr1.newExpr());
      } else return ATfalse;

      if (ofp_traverse_Expr(Expr2.term, &Expr2)) {
         // MATCHED Expr
         Expr->setExpr2(Expr2.newExpr());
      } else return ATfalse;

   // MATCHED AndExpr
   Expr->setOptionType(OFP::Expr::AndExpr);

   return ATtrue;
 }

 if (ATmatch(term, "NotExpr(<term>)", &Expr1.term)) {

      if (ofp_traverse_Expr(Expr1.term, &Expr1)) {
         // MATCHED Expr
         Expr->setExpr1(Expr1.newExpr());
      } else return ATfalse;

   // MATCHED NotExpr
   Expr->setOptionType(OFP::Expr::NotExpr);

   return ATtrue;
 }

 if (ATmatch(term, "GE_Expr(<term>,<term>)", &Expr1.term, &Expr2.term)) {

      if (ofp_traverse_Expr(Expr1.term, &Expr1)) {
         // MATCHED Expr
         Expr->setExpr1(Expr1.newExpr());
      } else return ATfalse;

      if (ofp_traverse_Expr(Expr2.term, &Expr2)) {
         // MATCHED Expr
         Expr->setExpr2(Expr2.newExpr());
      } else return ATfalse;

   // MATCHED GE_Expr
   Expr->setOptionType(OFP::Expr::GE_Expr);

   return ATtrue;
 }

 if (ATmatch(term, "GT_Expr(<term>,<term>)", &Expr1.term, &Expr2.term)) {

      if (ofp_traverse_Expr(Expr1.term, &Expr1)) {
         // MATCHED Expr
         Expr->setExpr1(Expr1.newExpr());
      } else return ATfalse;

      if (ofp_traverse_Expr(Expr2.term, &Expr2)) {
         // MATCHED Expr
         Expr->setExpr2(Expr2.newExpr());
      } else return ATfalse;

   // MATCHED GT_Expr
   Expr->setOptionType(OFP::Expr::GT_Expr);

   return ATtrue;
 }

 if (ATmatch(term, "LE_Expr(<term>,<term>)", &Expr1.term, &Expr2.term)) {

      if (ofp_traverse_Expr(Expr1.term, &Expr1)) {
         // MATCHED Expr
         Expr->setExpr1(Expr1.newExpr());
      } else return ATfalse;

      if (ofp_traverse_Expr(Expr2.term, &Expr2)) {
         // MATCHED Expr
         Expr->setExpr2(Expr2.newExpr());
      } else return ATfalse;

   // MATCHED LE_Expr
   Expr->setOptionType(OFP::Expr::LE_Expr);

   return ATtrue;
 }

 if (ATmatch(term, "LT_Expr(<term>,<term>)", &Expr1.term, &Expr2.term)) {

      if (ofp_traverse_Expr(Expr1.term, &Expr1)) {
         // MATCHED Expr
         Expr->setExpr1(Expr1.newExpr());
      } else return ATfalse;

      if (ofp_traverse_Expr(Expr2.term, &Expr2)) {
         // MATCHED Expr
         Expr->setExpr2(Expr2.newExpr());
      } else return ATfalse;

   // MATCHED LT_Expr
   Expr->setOptionType(OFP::Expr::LT_Expr);

   return ATtrue;
 }

 if (ATmatch(term, "NE_Expr(<term>,<term>)", &Expr1.term, &Expr2.term)) {

      if (ofp_traverse_Expr(Expr1.term, &Expr1)) {
         // MATCHED Expr
         Expr->setExpr1(Expr1.newExpr());
      } else return ATfalse;

      if (ofp_traverse_Expr(Expr2.term, &Expr2)) {
         // MATCHED Expr
         Expr->setExpr2(Expr2.newExpr());
      } else return ATfalse;

   // MATCHED NE_Expr
   Expr->setOptionType(OFP::Expr::NE_Expr);

   return ATtrue;
 }

 if (ATmatch(term, "EQ_Expr(<term>,<term>)", &Expr1.term, &Expr2.term)) {

      if (ofp_traverse_Expr(Expr1.term, &Expr1)) {
         // MATCHED Expr
         Expr->setExpr1(Expr1.newExpr());
      } else return ATfalse;

      if (ofp_traverse_Expr(Expr2.term, &Expr2)) {
         // MATCHED Expr
         Expr->setExpr2(Expr2.newExpr());
      } else return ATfalse;

   // MATCHED EQ_Expr
   Expr->setOptionType(OFP::Expr::EQ_Expr);

   return ATtrue;
 }

 if (ATmatch(term, "ConcatExpr(<term>,<term>)", &Expr1.term, &Expr2.term)) {

      if (ofp_traverse_Expr(Expr1.term, &Expr1)) {
         // MATCHED Expr
         Expr->setExpr1(Expr1.newExpr());
      } else return ATfalse;

      if (ofp_traverse_Expr(Expr2.term, &Expr2)) {
         // MATCHED Expr
         Expr->setExpr2(Expr2.newExpr());
      } else return ATfalse;

   // MATCHED ConcatExpr
   Expr->setOptionType(OFP::Expr::ConcatExpr);

   return ATtrue;
 }

 if (ATmatch(term, "MinusExpr(<term>,<term>)", &Expr1.term, &Expr2.term)) {

      if (ofp_traverse_Expr(Expr1.term, &Expr1)) {
         // MATCHED Expr
         Expr->setExpr1(Expr1.newExpr());
      } else return ATfalse;

      if (ofp_traverse_Expr(Expr2.term, &Expr2)) {
         // MATCHED Expr
         Expr->setExpr2(Expr2.newExpr());
      } else return ATfalse;

   // MATCHED MinusExpr
   Expr->setOptionType(OFP::Expr::MinusExpr);

   return ATtrue;
 }

 if (ATmatch(term, "PlusExpr(<term>,<term>)", &Expr1.term, &Expr2.term)) {

      if (ofp_traverse_Expr(Expr1.term, &Expr1)) {
         // MATCHED Expr
         Expr->setExpr1(Expr1.newExpr());
      } else return ATfalse;

      if (ofp_traverse_Expr(Expr2.term, &Expr2)) {
         // MATCHED Expr
         Expr->setExpr2(Expr2.newExpr());
      } else return ATfalse;

   // MATCHED PlusExpr
   Expr->setOptionType(OFP::Expr::PlusExpr);

   return ATtrue;
 }

 if (ATmatch(term, "UnaryMinusExpr(<term>)", &Expr1.term)) {

      if (ofp_traverse_Expr(Expr1.term, &Expr1)) {
         // MATCHED Expr
         Expr->setExpr1(Expr1.newExpr());
      } else return ATfalse;

   // MATCHED UnaryMinusExpr
   Expr->setOptionType(OFP::Expr::UnaryMinusExpr);

   return ATtrue;
 }

 if (ATmatch(term, "UnaryPlusExpr(<term>)", &Expr1.term)) {

      if (ofp_traverse_Expr(Expr1.term, &Expr1)) {
         // MATCHED Expr
         Expr->setExpr1(Expr1.newExpr());
      } else return ATfalse;

   // MATCHED UnaryPlusExpr
   Expr->setOptionType(OFP::Expr::UnaryPlusExpr);

   return ATtrue;
 }

 if (ATmatch(term, "DivExpr(<term>,<term>)", &Expr1.term, &Expr2.term)) {

      if (ofp_traverse_Expr(Expr1.term, &Expr1)) {
         // MATCHED Expr
         Expr->setExpr1(Expr1.newExpr());
      } else return ATfalse;

      if (ofp_traverse_Expr(Expr2.term, &Expr2)) {
         // MATCHED Expr
         Expr->setExpr2(Expr2.newExpr());
      } else return ATfalse;

   // MATCHED DivExpr
   Expr->setOptionType(OFP::Expr::DivExpr);

   return ATtrue;
 }

 if (ATmatch(term, "MultExpr(<term>,<term>)", &Expr1.term, &Expr2.term)) {

      if (ofp_traverse_Expr(Expr1.term, &Expr1)) {
         // MATCHED Expr
         Expr->setExpr1(Expr1.newExpr());
      } else return ATfalse;

      if (ofp_traverse_Expr(Expr2.term, &Expr2)) {
         // MATCHED Expr
         Expr->setExpr2(Expr2.newExpr());
      } else return ATfalse;

   // MATCHED MultExpr
   Expr->setOptionType(OFP::Expr::MultExpr);

   return ATtrue;
 }

 if (ATmatch(term, "PowerExpr(<term>,<term>)", &Expr1.term, &Expr2.term)) {

      if (ofp_traverse_Expr(Expr1.term, &Expr1)) {
         // MATCHED Expr
         Expr->setExpr1(Expr1.newExpr());
      } else return ATfalse;

      if (ofp_traverse_Expr(Expr2.term, &Expr2)) {
         // MATCHED Expr
         Expr->setExpr2(Expr2.newExpr());
      } else return ATfalse;

   // MATCHED PowerExpr
   Expr->setOptionType(OFP::Expr::PowerExpr);

   return ATtrue;
 }

 OFP::DefinedUnaryOp DefinedUnaryOp;
 if (ATmatch(term, "DefUnaryExpr(<term>,<term>)", &DefinedUnaryOp.term, &Expr1.term)) {

      if (ofp_traverse_DefinedUnaryOp(DefinedUnaryOp.term, &DefinedUnaryOp)) {
         // MATCHED DefinedUnaryOp
         Expr->setDefinedUnaryOp(DefinedUnaryOp.newDefinedUnaryOp());
      } else return ATfalse;

      if (ofp_traverse_Expr(Expr1.term, &Expr1)) {
         // MATCHED Expr
         Expr->setExpr1(Expr1.newExpr());
      } else return ATfalse;

   // MATCHED DefUnaryExpr
   Expr->setOptionType(OFP::Expr::DefUnaryExpr);

   return ATtrue;
 }

 OFP::Primary Primary;
 if (ATmatch(term, "Expr_P(<term>)", &Primary.term)) {

      if (ofp_traverse_Primary(Primary.term, &Primary)) {
         // MATCHED Primary
         Expr->setPrimary(Primary.newPrimary());
      } else return ATfalse;

   // MATCHED Expr_P
   Expr->setOptionType(OFP::Expr::Expr_P);

   return ATtrue;
 }

 return ATfalse;
}
