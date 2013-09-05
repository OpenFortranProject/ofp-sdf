#include "traversal.h"
#include <assert.h>
#include <stdlib.h>

#undef DEBUG_PRINT

ATbool ofp_traverse_OpDecl(ATerm term, pOFP_Traverse OpDecl)
{
#ifdef DEBUG_PRINT
   printf("\nOpDecl: %s\n", ATwriteToString(term));
#endif

   OFP_Traverse Name, FunType;
   if (ATmatch(term, "OpDecl(<term>,<term>)", &Name.term, &FunType.term) ) {

      char * String;
      if (ATmatch(Name.term, "<str>", &String)) {
         // MATCHED OpDecl name
         OpDecl->post = String;
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
            char * name = (char *) OpDecl.post;

            /** Output function signature
             */
            printf("ATbool ofp_traverse_%s(ATerm term, pOFP_Traverse %s);\n\n", name, name);
         }
      }
      return ATtrue;
   }
   return ATfalse;
}
