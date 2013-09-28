#include "traversal.h"
#include <assert.h>
#include <stdlib.h>

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

ATermList gTypeAliases;

/**
 * Perform any necessary initialization for this traversal
 */
ATbool ofp_traverse_init()
{
   return ATtrue;
}

/**
 * Perform finalization tasks for this traversal
 */
ATbool ofp_traverse_finalize()
{
   return ATtrue;
}

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
         FunType.pre  = String;
         OpDecl->post = String;
      }
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
