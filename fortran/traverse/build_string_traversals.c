#include "ofp_builder.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#undef DEBUG_PRINT

/**
 * Perform any necessary initialization for this traversal
 */
ATbool ofp_traverse_init()
{
   fpc = fopen("ofp_traverse_strings.c", "w");    assert(fpc != NULL);
   fprintf(fpc, "#include \"traversal.h\"\n\n");
   return ATtrue;
}

/**
 * Perform finalization tasks for this traversal
 */
ATbool ofp_traverse_finalize()
{
   fclose(fpc);
   return ATtrue;
}

ATbool ofp_traverse_OpDecl(ATerm term, pOFP_Traverse OpDecl)
{
   return ATfalse;
}

ATbool ofp_traverse_OpDeclInj(ATerm term, pOFP_Traverse OpDeclInj)
{
#ifdef DEBUG_PRINT
   printf("\nOpDeclInj: %s\n", ATwriteToString(term));
#endif

   ATerm funType, type, name;
   if (! ATmatch(term, "OpDeclInj(<term>)", &funType) )
   {
      return ATfalse;
   }

   if (ATmatch(funType, "FunType([ConstType(SortNoArgs(<term>))],ConstType(SortNoArgs(<term>)))", &type, &name)) {
      if (ofp_build_string_traversal(type, name)) {
         return ATtrue;
      } else return ATfalse;
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
      ATermList OpDeclInj_tail = (ATermList) ATmake("<term>", OpDecl_list.term);

      while (! ATisEmpty(OpDeclInj_tail)) {
         OFP_Traverse OpDeclInj;
         OpDeclInj.term = ATgetFirst(OpDeclInj_tail);
         OpDeclInj_tail = ATgetNext(OpDeclInj_tail);

         if (ofp_traverse_OpDeclInj(OpDeclInj.term, &OpDeclInj)) {
            // MATCHED OpDeclInj
         }
      }
      return ATtrue;
   }
   return ATfalse;
}
