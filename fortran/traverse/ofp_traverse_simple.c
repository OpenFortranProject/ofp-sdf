#include "traversal.h"

ATbool ofp_traverse_ProgramUnit(ATerm term, pOFP_Traverse ProgramUnit)
{
#ifdef DEBUG_PRINT
   printf("ProgramUnit: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ProgramUnit(<term>)", &ProgramUnit->term)) {
   OFP_Traverse BlockData;
   OFP_Traverse MainProgram;
   if (ofp_traverse_MainProgram(ProgramUnit->term, &MainProgram)) {
      // MATCHED MainProgram
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_AttrSpec(ATerm term, pOFP_Traverse AttrSpec)
{
#ifdef DEBUG_PRINT
   printf("AttrSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AttrSpec(<term>)", &AttrSpec->term)) {
 }

   OFP_Traverse ArraySpec;
   if (ATmatch(term, "AttrSpec_DIMENSION(<term>)", &ArraySpec.term)) {
      //  if (ofp_traverse_ArraySpec(ArraySpec.term, &ArraySpec)) {
         // MATCHED ArraySpec
      //         return ATtrue;
      //      } else return ATfalse;
   }

   if (ATmatch(term, "AttrSpec_VOLATILE")) {
      // MATCHED AttrSpec_VOLATILE
      return ATtrue;
   }

   if (ATmatch(term, "AttrSpec_VALUE")) {
      // MATCHED AttrSpec_VALUE
      return ATtrue;
   }

   if (ATmatch(term, "AttrSpec_TARGET")) {
      // MATCHED AttrSpec_TARGET
      return ATtrue;
   }

   if (ATmatch(term, "AttrSpec_SAVE")) {
      // MATCHED AttrSpec_SAVE
      return ATtrue;
   }

   if (ATmatch(term, "AttrSpec_PROTECTED")) {
      // MATCHED AttrSpec_PROTECTED
      return ATtrue;
   }

   if (ATmatch(term, "AttrSpec_POINTER")) {
      // MATCHED AttrSpec_POINTER
      return ATtrue;
   }

   if (ATmatch(term, "AttrSpec_PARAMETER")) {
      // MATCHED AttrSpec_PARAMETER
      return ATtrue;
   }

   if (ATmatch(term, "AttrSpec_OPTIONAL")) {
      // MATCHED AttrSpec_OPTIONAL
      return ATtrue;
   }

   if (ATmatch(term, "AttrSpec_INTRINSIC")) {
      // MATCHED AttrSpec_INTRINSIC
      return ATtrue;
   }

   if (ATmatch(term, "AttrSpec_EXTERNAL")) {
      // MATCHED AttrSpec_EXTERNAL
      return ATtrue;
   }

   if (ATmatch(term, "AttrSpec_CONTIGUOUS")) {
      // MATCHED AttrSpec_CONTIGUOUS
      return ATtrue;
   }

   if (ATmatch(term, "AttrSpec_ASYNCHRONOUS")) {
      // MATCHED AttrSpec_ASYNCHRONOUS
      return ATtrue;
   }

   if (ATmatch(term, "AttrSpec_ALLOCATABLE")) {
      // MATCHED AttrSpec_ALLOCATABLE
      return ATtrue;
   }

   return ATfalse;
}

