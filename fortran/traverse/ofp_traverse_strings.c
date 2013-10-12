#include "traversal.h"

ATbool ofp_traverse_Dop(ATerm term, pOFP_Traverse Dop)
{
#ifdef DEBUG_PRINT
   printf("Dop: %s\n", ATwriteToString(term));
#endif

   char * Dop_val;
   if (ATmatch(term, "<str>", &Dop_val)) {
      // MATCHED Dop
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
      return ATtrue;
   } else return ATfalse;

   return ATtrue;
}

