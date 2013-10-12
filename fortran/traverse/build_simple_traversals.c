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
   fpc = fopen("ofp_traverse_simple.c", "w");    assert(fpc != NULL);
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

/**
 * Traverse a production: Prod("constructor name", [sub-productions])
 *   - the symbol name must match the constructor name
 */
ATbool ofp_traverse_Prod_name_common(ATerm term, pOFP_Traverse Prod, ATerm symbol)
{
#ifdef DEBUG_PRINT
   printf("Prod(name match): %s\n", ATwriteToString(term));
#endif

   ATerm constructor;
   ATermList symbols;
   if (ATmatch(term, "Prod(<term>,<term>)", &constructor, &symbols)) {

      if (! ATisEqual(constructor, symbol)) {
         return ATfalse;
      }
      if (ATisEmpty(symbols)) {
         printf("WARNING: Prod (name match): has empty sub-production list%s\n", ATwriteToString(term));
         return ATfalse;
      }

      printf("         Prod(name match): %s", ATwriteToString(constructor));
      printf("\t\t%s\n", ATwriteToString((ATerm)symbols));

      ofp_build_traversal_nonterminals_common(symbol, constructor, symbols);
   }

   return ATfalse;
}

/**
 * Traverse a production: Prod("constructor name", [sub-productions])
 *   - the symbol name must not match the constructor name
 */
ATbool ofp_traverse_Prod_name(ATerm term, pOFP_Traverse Prod, ATerm symbol)
{
#ifdef DEBUG_PRINT
   printf("Prod(no name match): %s\n", ATwriteToString(term));
#endif

   ATerm constructor;
   ATermList symbols;
   if (ATmatch(term, "Prod(<term>,<term>)", &constructor, &symbols)) {

      if (ATisEqual(constructor, symbol)) {
         return ATfalse;
      }
      if (ATisEmpty(symbols)) {
         // a terminal production
         return ATfalse;
      }

      printf("         Prod(no name match): %s", ATwriteToString(constructor));
      printf("\t\t%s\n", ATwriteToString((ATerm)symbols));

      ofp_build_traversal_nonterminals(constructor, symbols);
   }

   return ATfalse;
}

/**
 * Traverse a production: Prod("constructor name", [sub-productions])
 *   - the production must be a terminal (empty sub-production list)
 */
ATbool ofp_traverse_Prod_terminal(ATerm term, pOFP_Traverse Prod, ATerm symbol)
{
#ifdef DEBUG_PRINT
   printf("Prod(terminal): %s\n", ATwriteToString(term));
#endif

   ATerm constructor;
   ATermList symbols;
   if (ATmatch(term, "Prod(<term>,<term>)", &constructor, &symbols)) {

      if (! ATisEmpty(symbols)) {
         return ATfalse;
      }
      if (ATisEqual(constructor, symbol)) {
         printf("WARNING: Prod(terminal): symbol constructor name match%s\n", ATwriteToString(term));
         return ATfalse;
      }

      printf("         Prod(terminal): %s", ATwriteToString(constructor));
      printf("\t\t%s\n", ATwriteToString((ATerm)symbols));

      // terminal symbol
      if (ofp_build_match_terminal(constructor)) {
         // MATCHED terminal
         return ATtrue;
      }
   }

   return ATfalse;
}

/**
 * Traverse the productions for a symbol.
 *   Symbol("symbol_name", [Prod("cons_name", [productions]), ...])
 *
 *  One (and only one) of the productions (Prod) for the Symbol must match,
 *  otherwise it is an error (OR relationship).
 *
 *  Productions for each separate constructor (given by cons_name) must each
 *  match, otherwise it is an error (AND relationship).
 */
ATbool ofp_traverse_Symbol(ATerm term, pOFP_Traverse Symbol)
{
#ifdef DEBUG_PRINT
   printf("\nSymbol: %s\n", ATwriteToString(term));
#endif

   printf("\n...Symbol: %s\n", ATwriteToString(term));

   ATermList productions;
   if (ATmatch(term, "Symbol(<term>,<term>)", &Symbol->term, &productions)) {
      printf("     symbol: %s\n", ATwriteToString(Symbol->term));
      printf("     prods : %s\n", ATwriteToString((ATerm)productions));

      ofp_build_traversal_func_begin(Symbol->term);

      /** There are three separate traversals of the productions:
       *    - traverse productions whose constructor name matches the symbol name
       *    - traverse productions whose constructor name differs from the symbol name
       *    - traverse terminal productions (constructors (Prod) with empty production list)
       */


      // These traversals share common constructor name (the original symbol
      ofp_build_match_begin(Symbol->term);

      OFP_Traverse Prod;
      ATermList Prod_tail = (ATermList) ATmake("<term>", productions);
      while (! ATisEmpty(Prod_tail)) {
         Prod.term = ATgetFirst(Prod_tail);
         Prod_tail = ATgetNext (Prod_tail);
         if (ofp_traverse_Prod_name_common(Prod.term, &Prod, Symbol->term)) {
            // MATCHED Prod with constructor name sharing common symbol name
         }
      }
      ofp_build_match_end(Symbol->term);

      Prod_tail = (ATermList) ATmake("<term>", productions);
      while (! ATisEmpty(Prod_tail)) {
         Prod.term = ATgetFirst(Prod_tail);
         Prod_tail = ATgetNext (Prod_tail);
         if (ofp_traverse_Prod_name(Prod.term, &Prod, Symbol->term)) {
            // MATCHED Prod with constructor name not sharing common symbol name
         }
      }

      Prod_tail = (ATermList) ATmake("<term>", productions);
      while (! ATisEmpty(Prod_tail)) {
         Prod.term = ATgetFirst(Prod_tail);
         Prod_tail = ATgetNext (Prod_tail);
         if (ofp_traverse_Prod_terminal(Prod.term, &Prod, Symbol->term)) {
            // MATCHED Prod terminal
         }
      }

      // one of the productions must match, otherwise return ATfalse
      ofp_build_traversal_func_end(Symbol->term, ATfalse);
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

      /* First build the production table. It is needed when matching productions.
       */
      gProdTable = ofp_build_production_table(OpDecl_list.term);

      //printf("%s\n", ATwriteToString((ATerm)gProdTable));

      if (ATisEmpty(gProdTable)) {
         return ATfalse;
      }

      OFP_Traverse Symbol;
      ATermList    Symbols_tail;
      Symbol.term  = ATgetFirst(gProdTable);
      Symbols_tail = ATgetNext (gProdTable);
      do {
         if (ofp_traverse_Symbol(Symbol.term, &Symbol)) {
            // MATCHED Symbol
         }

         Symbol.term  = ATgetFirst(Symbols_tail);
         Symbols_tail = ATgetNext (Symbols_tail);

      } while (! ATisEmpty(Symbols_tail));

      return ATtrue;
   }

   return ATfalse;
}
