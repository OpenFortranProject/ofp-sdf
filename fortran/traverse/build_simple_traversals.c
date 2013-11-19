#include "ofp_builder.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#undef DEBUG_PRINT

/**
 * Build table of aliases.
 * An entry in the table is Alias(symbol, alias, type)
 */
ATbool ofp_build_alias_table(ATermTable aTable, ATerm term)
{
   ATermList tail = (ATermList) ATmake("<term>", term);
   while (! ATisEmpty(tail)) {
      ATerm head, funtype, alias, symbol, type;

      head = ATgetFirst(tail);
      tail = ATgetNext(tail);

      if (! ATmatch(head, "OpDeclInj(<term>)", &funtype)) {
         continue;
      }

      assert (ATmatch(funtype, "FunType([<term>],ConstType(SortNoArgs(<term>)))", &symbol, &alias));

      if (ATmatch(symbol, "ConstType(SortNoArgs(<term>))", &symbol)) {
         // MATCHED symbol
         type = ATmake("<str>", "Const");
      }
      else if (ATmatch(symbol, "ConstType(Sort(\"Option\",[SortNoArgs(<term>)]))", &symbol)) {
            printf("...... option type : %s\n", ATwriteToString(symbol));
            printf("......       alias : %s\n", ATwriteToString(alias));
            type = ATmake("<str>", "Option");
      }
      else {
         printf("......  ????? type : %s\n", ATwriteToString(symbol));
         continue;
      }

      ATtablePut(aTable, alias, ATmake("Alias(<term>,<term>,<term>)", symbol, alias, type));
   }

   return ATtrue;
}

/**
 * Perform any necessary initialization for this traversal
 */
ATbool ofp_traverse_init()
{
   // symbol and alias tables
   gSymTable   = ATtableCreate(200, 50);
   gAliasTable = ATtableCreate(200, 50);

   fpc = fopen("ofp_traverse_simple.c", "w");    assert(fpc != NULL);
   fph = fopen("ofp_traverse_simple.h", "w");    assert(fph != NULL);
   fprintf(fpc, "#include \"traversal.h\"\n");
   fprintf(fpc, "#include \"ofp_traverse_simple.h\"\n\n");

   return ATtrue;
}

/**
 * Perform finalization tasks for this traversal
 */
ATbool ofp_traverse_finalize()
{
   fclose(fpc);
   ATtableDestroy(gSymTable);
   ATtableDestroy(gAliasTable);
   return ATtrue;
}

/**
 * Traverse a production: Prod("constructor name", [args])
 */
ATbool ofp_traverse_Prod(ATerm term, pOFP_Traverse Prod, ATerm symbol)
{
#ifdef DEBUG_PRINT
   printf("ofp_traverse_Prod: %s\n", ATwriteToString(term));
#endif

   ATerm constructor;
   ATermList symbols;
   if (ATmatch(term, "Prod(<term>,<term>)", &constructor, &symbols)) {
      ATermList args = ofp_getArgList((ATermList)symbols);

      if (ATisEmpty(symbols)) {
         ofp_build_match_begin(symbol, constructor, args);
         ofp_build_match_end(symbol, constructor);
         return ATfalse;
      }

      ofp_build_match_begin(symbol, constructor, args);
      ofp_build_traversal_production(symbol, constructor, symbols, args);
      ofp_build_match_end(symbol, constructor);

      return ATtrue;
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

      ofp_build_traversal_func_header(Symbol->term);
      ofp_build_traversal_func_begin (Symbol->term);

      /** There are three separate traversals of the productions:
       *    - traverse productions whose constructor name matches the symbol name
       *    - traverse productions whose constructor name differs from the symbol name
       *    - traverse terminal productions (constructors (Prod) with empty production list)
       */

      // Reset symbol table for new scope
      ATtableReset(gSymTable);
      ATtablePut(gSymTable, Symbol->term, ATmake("<int>", 0));

      OFP_Traverse Prod;
      ATermList Prod_tail = (ATermList) ATmake("<term>", productions);
      while (! ATisEmpty(Prod_tail)) {
         Prod.term = ATgetFirst(Prod_tail);
         Prod_tail = ATgetNext (Prod_tail);

         if (ofp_traverse_Prod(Prod.term, &Prod, Symbol->term)) {
            // MATCHED Prod
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
      ATprotectTerm(gProdTable);

      if (ATisEmpty(gProdTable)) {
         return ATfalse;
      }

      ofp_build_alias_table(gAliasTable, OpDecl_list.term);

      OFP_Traverse Symbol;
      ATermList    Symbols_tail;
      Symbols_tail = ATgetNext (gProdTable);
      Symbols_tail = (ATermList) ATmake("<term>", gProdTable);
      while (! ATisEmpty(Symbols_tail)) {
         Symbol.term  = ATgetFirst(Symbols_tail);
         Symbols_tail = ATgetNext (Symbols_tail);
         if (ofp_traverse_Symbol(Symbol.term, &Symbol)) {
            // MATCHED Symbol
         }
      }

      ATermList alist = ATtableValues(gAliasTable);
      printf("\n...... aTable: %s\n\n\n", ATwriteToString((ATerm)alist));

      return ATtrue;
   }

   return ATfalse;
}
