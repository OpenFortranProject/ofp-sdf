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
   fpc = fopen("ofp_traverse_lists.c", "w");    assert(fpc != NULL);
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
#ifdef DEBUG_PRINT
   printf("\nOpDecl: %s\n", ATwriteToString(term));
#endif

   OFP_Traverse name, funType;
   if (ATmatch(term, "OpDecl(<term>,<term>)", &name.term, &funType.term) ) {
      char * listStr, * nameStr;
      ATerm sortType, sortName, listName, prod;

      if (! ATmatch(funType.term,
                    "FunType([ConstType(Sort(<term>, [SortNoArgs(<term>)]))],<term>)",
                    &sortType, &sortName, &prod))
      {
         return ATfalse;
      }

      if (! ATisEqual(sortType, ATmake("<str>", "List")))
      {
         return ATfalse;
      }

      if (! ATmatch(prod, "ConstType(SortNoArgs(<term>))", &listName)) {
         return ATfalse;
      }

      if (! ATmatch(listName, "<str>", &listStr) || !ATmatch(sortName, "<str>", &nameStr)) {
         return ATfalse;
      }
      // sanity check of list name
      if (strncmp(listStr, nameStr, strlen(nameStr)) != 0) {
         return ATfalse;
      }

      ofp_build_traversal_func_begin(listName);
      ofp_build_list_traversal(sortName);
      ofp_build_traversal_func_end(listName, ATtrue);

      return ATtrue;
   }
   return ATfalse;
}

ATbool ofp_traverse_OpDeclInj(ATerm term, pOFP_Traverse OpDeclInj)
{
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
