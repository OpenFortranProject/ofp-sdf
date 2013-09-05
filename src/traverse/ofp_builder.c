#include "traversal.h"
#include <assert.h>
#include <stdlib.h>

#undef DEBUG_PRINT

ATbool ofp_isStringType(ATerm term)
{
   if (ATmatch(term, "\"String\"")) {
      return ATtrue;
   }
   return ATfalse;
}

ATbool ofp_isIdentType(ATerm term)
{
   if (ATmatch(term, "\"Ident\"")) {
      return ATtrue;
   }
   return ATfalse;
}

enum DataType ofp_getDataType(ATerm term)
{
   if (ofp_isStringType(term)) return STRING;
   if (ofp_isIdentType (term)) return IDENT;

   return UNKNOWN;
}

ATbool ofp_isPrimitiveType(ATerm term)
{
   switch (ofp_getDataType(term)) {
      case STRING:
      case IDENT:
         return ATtrue;
   }
   return ATfalse;
}

ATbool ofp_traverse_Signature(ATerm term, pOFP_Traverse Signature)
{
#ifdef DEBUG_PRINT
   printf("\nSignature: %s\n", ATwriteToString(term));
#endif

   OFP_Traverse Constructors_list;
   if (ATmatch(term, "Signature(<term>)", &Constructors_list.term) ) {

      ATermList Constructors_tail = (ATermList) ATmake("<term>", Constructors_list.term);
      while (! ATisEmpty(Constructors_tail)) {
         OFP_Traverse Constructors;
         Constructors.term = ATgetFirst(Constructors_tail);
         Constructors_tail = ATgetNext(Constructors_tail);

         if (ofp_traverse_Constructors(Constructors.term, &Constructors)) {
            // MATCHED Constructors
         } else return ATfalse;
      }
      return ATtrue;
   }

   return ATfalse;
}

ATbool ofp_traverse_Module(ATerm term, pOFP_Traverse Module)
{
#ifdef DEBUG_PRINT
   printf("Module: %s\n", ATwriteToString(term));
#endif

   OFP_Traverse Name, Signature_list;
   if (ATmatch(term, "Module(<term>,<term>)", &Name.term, &Signature_list.term) ) {

      char * String;
      if (ATmatch(Name.term, "<str>", &String)) {
         // MATCHED module name
      }

      // Only traverse one signature, the others cause problems
      //
      ATermList Signature_tail = (ATermList) ATmake("<term>", Signature_list.term);
      if (! ATisEmpty(Signature_tail)) {
         OFP_Traverse Signature;
         Signature.term = ATgetFirst(Signature_tail);
         Signature_tail = ATgetNext(Signature_tail);

         if (ofp_traverse_Signature(Signature.term, &Signature)) {
            // MATCHED Signature
         } else return ATfalse;
      }
      return ATtrue;
   }

   return ATfalse;
}

ATermList ofp_coalesceAliasTable(ATermList oldTable)
{
   // Assumes:
   //  1. Contains list of terms Type(<str>,<list>) or OptType(<str>,<list>)
   //      a. <str> is type name
   //      b. <list> is [type] of length 1
   //  2. Portions of table to be coalesced are in order
   //  3. If OptType must match "(Some(<term>))"
   //
   ATerm head;

   ATermList table = (ATermList) ATmake("[]");
   ATermList tail  = (ATermList) ATmake("<term>", oldTable);

   head = ATgetFirst(tail);
   tail = ATgetNext(tail);

   while (1) {
      ATerm headType, headAlias, next, nextType, nextAlias;

      if (ATisEmpty(tail)) next = ATmake("Alias(None,None)");
      else                 next = ATgetFirst(tail);

      assert( ATmatch(head, "Alias(<term>,<term>)", &headType, &headAlias) );
      assert( ATmatch(next, "Alias(<term>,<term>)", &nextType, &nextAlias) );

      // throw away multiple productions of same alias
      if (ATisEqual(headAlias, nextAlias)) {
         while (ATisEqual(headAlias, nextAlias)) {
            // skip these two
            if (ATisEmpty(tail)) return table;

            tail = ATgetNext(tail);
            head = ATgetFirst(tail);
            tail = ATgetNext(tail);

            if (ATisEmpty(tail)) next = ATmake("Alias(None,None)");
            else                 next = ATgetFirst(tail);

            assert( ATmatch(head, "Alias(<term>,<term>)", &headType, &headAlias) );
            assert( ATmatch(next, "Alias(<term>,<term>)", &nextType, &nextAlias) );
         }
      }
      else if (!ofp_isPrimitiveType(headType)) {
         // skip primitive types
         table = ATappend(table, head);
      }

      if (ATisEmpty(tail)) break;

      head = ATgetFirst(tail);
      tail = ATgetNext(tail);
   }

   return table;
}
