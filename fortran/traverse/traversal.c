#include "traversal.h"
#include <string.h>

#define DEBUG_PRINT

/**
 * Perform any necessary initialization for this traversal
 */
ATbool ofp_traverse_init()
{
   return ATtrue;
}

static char * ofp_strdup(char * str)
{
   return strdup(str);
}

ATbool ofp_traverse_Dop(ATerm term, pOFP_Traverse Dop)
{
#ifdef DEBUG_PRINT
   printf("Dop: %s\n", ATwriteToString(term));
#endif

   char * Dop_val;
   if (ATmatch(term, "<str>", &Dop_val)) {
      // MATCHED Dop
      Dop->post = ofp_strdup(Dop_val);
      return ATtrue;
   } else return ATfalse;

   return ATtrue;
}

ATbool ofp_traverse_HexConstant(ATerm term, pOFP_Traverse HexConstant)
{
#ifdef DEBUG_PRINT
   printf("HexConstant: %s\n", ATwriteToString(term));
#endif

   char * HexConstant_val;
   if (ATmatch(term, "<str>", &HexConstant_val)) {
      // MATCHED HexConstant
      HexConstant->post = ofp_strdup(HexConstant_val);
      return ATtrue;
   } else return ATfalse;

   return ATtrue;
}

ATbool ofp_traverse_OctalConstant(ATerm term, pOFP_Traverse OctalConstant)
{
#ifdef DEBUG_PRINT
   printf("OctalConstant: %s\n", ATwriteToString(term));
#endif

   char * OctalConstant_val;
   if (ATmatch(term, "<str>", &OctalConstant_val)) {
      // MATCHED OctalConstant
      OctalConstant->post = ofp_strdup(OctalConstant_val);
      return ATtrue;
   } else return ATfalse;

   return ATtrue;
}

ATbool ofp_traverse_BinaryConstant(ATerm term, pOFP_Traverse BinaryConstant)
{
#ifdef DEBUG_PRINT
   printf("BinaryConstant: %s\n", ATwriteToString(term));
#endif

   char * BinaryConstant_val;
   if (ATmatch(term, "<str>", &BinaryConstant_val)) {
      // MATCHED BinaryConstant
      BinaryConstant->post = ofp_strdup(BinaryConstant_val);
      return ATtrue;
   } else return ATfalse;

   return ATtrue;
}

ATbool ofp_traverse_Rcon(ATerm term, pOFP_Traverse Rcon)
{
#ifdef DEBUG_PRINT
   printf("Rcon: %s\n", ATwriteToString(term));
#endif

   char * Rcon_val;
   if (ATmatch(term, "<str>", &Rcon_val)) {
      // MATCHED Rcon
      Rcon->post = ofp_strdup(Rcon_val);
      return ATtrue;
   } else return ATfalse;

   return ATtrue;
}

ATbool ofp_traverse_Scon(ATerm term, pOFP_Traverse Scon)
{
#ifdef DEBUG_PRINT
   printf("Scon: %s\n", ATwriteToString(term));
#endif

   char * Scon_val;
   if (ATmatch(term, "<str>", &Scon_val)) {
      // MATCHED Scon
      Scon->post = ofp_strdup(Scon_val);
      return ATtrue;
   } else return ATfalse;

   return ATtrue;
}

ATbool ofp_traverse_Icon(ATerm term, pOFP_Traverse Icon)
{
#ifdef DEBUG_PRINT
   printf("Icon: %s\n", ATwriteToString(term));
#endif

   char * Icon_val;
   if (ATmatch(term, "<str>", &Icon_val)) {
      // MATCHED Icon
      Icon->post = ofp_strdup(Icon_val);
      return ATtrue;
   } else return ATfalse;

   return ATtrue;
}

ATbool ofp_traverse_Ident(ATerm term, pOFP_Traverse Ident)
{
#ifdef DEBUG_PRINT
   printf("Ident: %s\n", ATwriteToString(term));
#endif

   char * Ident_val;
   if (ATmatch(term, "<str>", &Ident_val)) {
      // MATCHED Ident
      Ident->post = ofp_strdup(Ident_val);
      return ATtrue;
   } else return ATfalse;

   return ATtrue;
}

ATbool ofp_traverse_Letter(ATerm term, pOFP_Traverse Letter)
{
#ifdef DEBUG_PRINT
   printf("Letter: %s\n", ATwriteToString(term));
#endif

   char * Letter_val;
   if (ATmatch(term, "<str>", &Letter_val)) {
      // MATCHED Letter
      Letter->post = ofp_strdup(Letter_val);
      return ATtrue;
   } else return ATfalse;

   return ATtrue;
}

ATbool ofp_traverse_Label(ATerm term, pOFP_Traverse Label)
{
#ifdef DEBUG_PRINT
   printf("Label: %s\n", ATwriteToString(term));
#endif

   char * Label_val;
   if (ATmatch(term, "<str>", &Label_val)) {
      // MATCHED Label
      Label->post = ofp_strdup(Label_val);
      return ATtrue;
   } else return ATfalse;

   return ATtrue;
}

ATbool ofp_traverse_LblRef(ATerm term, pOFP_Traverse LblRef)
{
#ifdef DEBUG_PRINT
   printf("LblRef: %s\n", ATwriteToString(term));
#endif

   char * LblRef_val;
   if (ATmatch(term, "<str>", &LblRef_val)) {
      // MATCHED LblRef
      LblRef->post = ofp_strdup(LblRef_val);
      return ATtrue;
   } else return ATfalse;

   return ATtrue;
}

ATbool ofp_traverse_StartCommentBlock(ATerm term, pOFP_Traverse StartCommentBlock)
{
#ifdef DEBUG_PRINT
   printf("StartCommentBlock: %s\n", ATwriteToString(term));
#endif

   char * StartCommentBlock_val;
   if (ATmatch(term, "<str>", &StartCommentBlock_val)) {
      // MATCHED StartCommentBlock
      StartCommentBlock->post = ofp_strdup(StartCommentBlock_val);
      return ATtrue;
   } else return ATfalse;

   return ATtrue;
}

ATbool ofp_traverse_EOS(ATerm term, pOFP_Traverse EOS)
{
#ifdef DEBUG_PRINT
   printf("EOS: %s\n", ATwriteToString(term));
#endif

   char * EOS_val;
   if (ATmatch(term, "<str>", &EOS_val)) {
      // MATCHED EOS
      EOS->post = ofp_strdup(EOS_val);
      return ATtrue;
   } else return ATfalse;

   return ATtrue;
}

