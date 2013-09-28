#include "traversal.h"
#include <assert.h>
#include <stdlib.h>

#undef DEBUG_PRINT

ATermList gTypeProductions;

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
   ATerm name, type, opt;
   int isOptType = 0;

   if (ATmatch(term, "OpDeclInj(<term>)", &OpDeclInj->term)) {
#ifdef DEBUG_PRINT
      printf("\nofp_traverse_OpDeclInj: %s\n", ATwriteToString(OpDeclInj->term));
#endif
      if (ATmatch(OpDeclInj->term, "FunType(<term>,<term>)", &type, &name)) {
         if (ATmatch(type, "[ConstType(Sort(<term>,<term>))]", &opt, &type)) {
            // MATCHED option object type
            if (ATmatch(type, "[SortNoArgs(<term>)]", &type) && ATisEqual(opt, ATmake("\"Option\""))) {
               isOptType = 1;
            } else return ATfalse;
         }
         else if (ATmatch(type, "[ConstType(SortNoArgs(<term>))]", &type)) {
            // MATCHED object type
         }
         if (ATmatch(name, "ConstType(SortNoArgs(<term>))", &name)) {
            // MATCHED object name
         } else return ATfalse;
      } else return ATfalse;

      if (isOptType) {
         OpDeclInj->term = ATmake("OptType(<term>,[<term>])", name, type);
      }
      else {
         OpDeclInj->term = ATmake("Type(<term>,[<term>])", name, type);
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
      gTypeProductions = (ATermList) ATmake("[]");

      /* First build the type aliase table.  It is needed when matching productions.
       */
      ATermList OpDeclInj_tail = (ATermList) ATmake("<term>", OpDecl_list.term);
      while (! ATisEmpty(OpDeclInj_tail)) {
         OFP_Traverse OpDeclInj;
         OpDeclInj.term = ATgetFirst(OpDeclInj_tail);
         OpDeclInj_tail = ATgetNext(OpDeclInj_tail);

         if (ofp_traverse_OpDeclInj(OpDeclInj.term, &OpDeclInj)) {
            // MATCHED OpDeclInj
            gTypeProductions = ATappend(gTypeProductions, OpDeclInj.term);
         }
      }

      /* Coalesce the type table so there is one name per list of types
       */
      gTypeProductions = ofp_coalesceAliasTable(gTypeProductions);

      ATermList OpDecl_tail = (ATermList) ATmake("<term>", OpDecl_list.term);
      while (! ATisEmpty(OpDecl_tail)) {
         OFP_Traverse OpDecl;
         OpDecl.term = ATgetFirst(OpDecl_tail);
         OpDecl_tail = ATgetNext(OpDecl_tail);

         if (ofp_traverse_OpDecl(OpDecl.term, &OpDecl)) {
            // MATCHED OpDecl
         }
      }

      printf("\nPRODUCTIONS: %s\n", ATwriteToString((ATerm) gTypeProductions));

      return ATtrue;
   }

   return ATfalse;
}
