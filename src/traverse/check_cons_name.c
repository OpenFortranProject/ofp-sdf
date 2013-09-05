#include "traversal.h"
#include <assert.h>
#include <stdlib.h>

#undef DEBUG_PRINT

ATbool ofp_traverse_OpDecl(ATerm term, pOFP_Traverse OpDecl)
{
#ifdef DEBUG_PRINT
   printf("\nOpDecl: %s\n", ATwriteToString(term));
#endif

   ATerm name, funType;
   if (ATmatch(term, "OpDecl(<term>,<term>)", &name, &funType)) {
      ATerm list, consName;
      if (ATmatch(funType, "FunType(<term>,ConstType(SortNoArgs(<term>)))", &list, &consName)) {
         if (!ATisEqual(name, consName)) {
            printf("Name error: %s ", ATwriteToString(name));
            printf("%s\n", ATwriteToString(consName));
         }
      }
      return ATtrue;
   }
   return ATfalse;
}

ATbool ofp_traverse_Constructors(ATerm term, pOFP_Traverse Constructors)
{
#ifdef DEBUG_PRINT
   printf("\nConstructors: %s\n", ATwriteToString(term));
#endif

   OFP_Traverse OpDecl_list;
   if (ATmatch(term, "Constructors(<term>)", &OpDecl_list.term) ) {
      ATermList OpDecl_tail = (ATermList) ATmake("<term>", OpDecl_list.term);
      while (! ATisEmpty(OpDecl_tail)) {
         OFP_Traverse OpDecl;
         OpDecl.term = ATgetFirst(OpDecl_tail);
         OpDecl_tail = ATgetNext(OpDecl_tail);

         if (ofp_traverse_OpDecl(OpDecl.term, &OpDecl)) {
            // MATCHED OpDecl
         }
      }
      return ATtrue;
   }
   return ATfalse;
}
