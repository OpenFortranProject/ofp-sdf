#include "traversal.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#undef DEBUG_PRINT

//---------------------------------------------------------------
// Steps to traverse a production
//    1. Get production name
//    2. Get list of source terms
//    3.  a. build source variable list
//        b. match prodution term populating source variables
//    4. For all source terms
//        a. if source is a terminal, match source         -- FINISHED
//        b. if source is not a terminal, traverse source  -- RECUR
//        c. if source is optional, match, traverse source -- RECUR
//        d. if source is a list, traverse all sources     -- RECUR
//        e. if source is an alias?????
//---------------------------------------------------------------

// global variables
//
FILE * fph = NULL;
FILE * fpc = NULL;

ATermList gTypeAliases;  // TODO - delete me

/**
 * Perform any necessary initialization for this traversal
 */
ATbool ofp_traverse_init()
{
   fpc = fopen("ofp_list_builder.c", "w");    assert(fpc != NULL);
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

ATbool ofp_build_list_traversal(ATerm term, ATerm name)
{
   ATerm listName;
   char * percs = "%s";

   if (ATmatch(term, "ConstType(SortNoArgs(<term>))", &listName)) {
      char * listStr, * nameStr;
      if (!ATmatch(listName, "<str>", &listStr) || !ATmatch(name, "<str>", &nameStr)) {
         return ATfalse;
      }
      // sanity check of list name
      if (strncmp(listStr, nameStr, strlen(nameStr)) != 0) {
         return ATfalse;
      }

      /** write to header file
       */
      //fprintf(fph, "ATbool ofp_traverse_%s(ATerm term, pOFP_Traverse %s);\n", listStr, listStr);

      /** write to implementation file
       */
      fprintf(fpc, "ATbool ofp_traverse_%s(ATerm term, pOFP_Traverse %s)\n", listStr, listStr);
      fprintf(fpc, "{\n");

      /** Debugging output
       */
      fprintf(fpc, "#ifdef DEBUG_PRINT\n");
      fprintf(fpc, "   printf(\"ofp_traverse_%s: %s\\n\", ATwriteToString(term));\n", listStr, percs);
      fprintf(fpc, "#endif\n\n");

      /** Match the list term, otherwise return false
       */
      fprintf(fpc, "   if (! ATmatch(term, \"%s(<term>)\", &%s->term)) {\n", listStr, listStr);
      fprintf(fpc, "      return ATfalse;\n");
      fprintf(fpc, "   }\n\n");

      /** Traverse the list
       */
      fprintf(fpc, "   OFP_Traverse %s;\n", nameStr);
      fprintf(fpc, "   ATermList %s_tail = (ATermList) ATmake(\"<term>\", %s->term);\n", nameStr, listStr);
      fprintf(fpc, "   while (! ATisEmpty(%s_tail)) {\n", nameStr);
      fprintf(fpc, "      %s.term = ATgetFirst(%s_tail);\n", nameStr, nameStr);
      fprintf(fpc, "      %s_tail = ATgetNext (%s_tail);\n", nameStr, nameStr);
      fprintf(fpc, "      if (ofp_traverse_%s(%s.term, &%s)) {\n", nameStr, nameStr, nameStr);
      fprintf(fpc, "         // MATCHED %s\n", nameStr);
      fprintf(fpc, "      } else return ATfalse;\n");
      fprintf(fpc, "   }\n");
      fprintf(fpc, "   return ATtrue;\n");
      fprintf(fpc, "}\n\n");

      return ATtrue;
   }

   return ATfalse;

#ifdef NOT_ME
      OFP_Traverse EntityDecl;
      ATermList EntityDecl_tail = (ATermList) ATmake("<term>", EntityDecl_list.term);
      while (! ATisEmpty(EntityDecl_tail)) {
         EntityDecl.term = ATgetFirst(EntityDecl_tail);
         EntityDecl_tail = ATgetNext(EntityDecl_tail);
         if (ofp_traverse_EntityDecl(EntityDecl.term, &EntityDecl)) {
            // MATCHED EntityDecl
         } else return ATfalse;
      }
#endif
}

ATbool ofp_traverse_OpDecl(ATerm term, pOFP_Traverse OpDecl)
{
#ifdef DEBUG_PRINT
   printf("\nOpDecl: %s\n", ATwriteToString(term));
#endif

   OFP_Traverse name, funType;
   if (ATmatch(term, "OpDecl(<term>,<term>)", &name.term, &funType.term) ) {
      ATerm sortType, sortName, prod;

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

      ofp_build_list_traversal(prod, sortName);

      return ATtrue;
   }
   return ATfalse;
}

ATbool ofp_traverse_OpDeclInj(ATerm term, pOFP_Traverse OpDeclInj)
{
   ATerm alias, type, opt;
   int isOptType = 0;

   if (ATmatch(term, "OpDeclInj(<term>)", &OpDeclInj->term)) {
#ifdef DEBUG_PRINT
      printf("\nofp_traverse_OpDeclInj: %s\n", ATwriteToString(OpDeclInj->term));
#endif
      if (ATmatch(OpDeclInj->term, "FunType(<term>,<term>)", &type, &alias)) {
         ATermList list;
         if (ATmatch(type, "<term>", &list)) {
            // not a simple alias
            if (ATgetLength(list) > 1) return ATfalse;
         } else return ATfalse;
         if (ATmatch(type, "[ConstType(SortNoArgs(<term>))]", &type)) {
            // MATCHED object type
         } else return ATfalse;
         if (ATmatch(alias, "ConstType(SortNoArgs(<term>))", &alias)) {
            // MATCHED object alias
         } else return ATfalse;
      } else return ATfalse;

      OpDeclInj->term = ATmake("Alias(<term>,<term>)", type, alias);

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
      gTypeAliases = (ATermList) ATmake("[]");

      /* First build the type aliase table.  It is needed when matching productions.
       */
      ATermList OpDeclInj_tail = (ATermList) ATmake("<term>", OpDecl_list.term);
      while (! ATisEmpty(OpDeclInj_tail)) {
         OFP_Traverse OpDeclInj;
         OpDeclInj.term = ATgetFirst(OpDeclInj_tail);
         OpDeclInj_tail = ATgetNext(OpDeclInj_tail);

         if (ofp_traverse_OpDeclInj(OpDeclInj.term, &OpDeclInj)) {
            // MATCHED OpDeclInj
            gTypeAliases = ATappend(gTypeAliases, OpDeclInj.term);
         }
      }

      /* Coalesce the type table so there is one name per list of types
       */
      gTypeAliases = ofp_coalesceAliasTable(gTypeAliases);

      ATermList OpDecl_tail = (ATermList) ATmake("<term>", OpDecl_list.term);
      while (! ATisEmpty(OpDecl_tail)) {
         OFP_Traverse OpDecl;
         OpDecl.term = ATgetFirst(OpDecl_tail);
         OpDecl_tail = ATgetNext(OpDecl_tail);

         if (ofp_traverse_OpDecl(OpDecl.term, &OpDecl)) {
            // MATCHED OpDecl
         }
      }

      printf("\nALIASES: %s\n", ATwriteToString((ATerm) gTypeAliases));

      return ATtrue;
   }

   return ATfalse;
}
