#include "ofp_builder.h"
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

ATermList ofp_coalesceProdTable(ATermList oldTable)
{
   // Assumes:
   //  1. Contains list of terms Symbol(<str>,Prod(<str>,<list>)))
   //      a. first <str> is the symbol name
   //      b. second <str> is a production name
   //      b. <list> is [production symbols] of length 1
   //  2. Portions of table to be coalesced are in order
   //
   ATerm head;

   ATermList table = (ATermList) ATmake("[]");
   ATermList tail  = (ATermList) ATmake("<term>", oldTable);

   head = ATgetFirst(tail);
   tail = ATgetNext(tail);

   while (1) {
      ATerm headName, headProd, next, nextName, nextProd, symbol;
      ATermList plist = (ATermList) ATmake("[]");

      if (ATisEmpty(tail)) next = ATmake("Symbol(None,None)");
      else                 next = ATgetFirst(tail);

      assert( ATmatch(head, "Symbol(<term>,<term>)", &headName, &headProd) );
      assert( ATmatch(next, "Symbol(<term>,<term>)", &nextName, &nextProd) );

      plist = ATappend(plist, headProd);
      printf("-------- %s\n", ATwriteToString((ATerm)plist));

      // coalesce multiple productions of same name
      while (ATisEqual(headName, nextName)) {
         head = ATgetFirst(tail);
         tail = ATgetNext(tail);

         if (ATisEmpty(tail)) next = ATmake("Symbol(None,None)");
         else                 next = ATgetFirst(tail);

         assert( ATmatch(head, "Symbol(<term>,<term>)", &headName, &headProd) );
         assert( ATmatch(next, "Symbol(<term>,<term>)", &nextName, &nextProd) );

         plist = ATappend(plist, headProd);
         printf("++++++++ %s\n", ATwriteToString((ATerm)plist));
      }

      symbol = ATmake("Symbol(<term>,<term>)", headName, plist);
      table = ATappend(table, symbol);

      if (ATisEmpty(tail)) break;

      head = ATgetFirst(tail);
      tail = ATgetNext(tail);
   }

   return table;
}

/**
 * Build table of productions.  Multiple productions may be bound to a
 * production name.  Thus the table should be coalesced after building it.
 * An entry in the table is Symbol(symName, [Prod(consName, [symType])])
 */
ATermList ofp_build_production_table(ATerm term)
{
   ATerm OpDecl, symName, consName, symType, symbol, prod;
   ATermList ptable, empty, plist;

   ptable = (ATermList) ATmake("[]");
   empty  = (ATermList) ATmake("[]");

   ATermList tail = (ATermList) ATmake("<term>", term);
   while (! ATisEmpty(tail)) {
      OpDecl = ATgetFirst(tail);
      tail = ATgetNext(tail);

      if (! ATmatch(OpDecl, "OpDecl(<term>,<term>)", &consName, &symType) ) {
         continue;
      }

      if (ATmatch(symType, "ConstType(SortNoArgs(<term>))", &symName) ) {
         prod   = ATmake("Prod(<term>, <term>)", consName, empty);
         symbol = ATmake("Symbol(<term>,<term>)", symName, prod);
         printf("........ %s\n", ATwriteToString(symbol));
      }
      else if (ATmatch(symType, "FunType(<term>, ConstType(SortNoArgs(<term>)))", &plist, &symName) ) {
         prod   = ATmake("Prod(<term>, <term>)", consName, plist);
         symbol = ATmake("Symbol(<term>,<term>)", symName, prod);
         printf("******** %s\n", ATwriteToString(symbol));
      }
      else {
         printf("???????????????????? %s\n", ATwriteToString(symName));
         continue;
      }

      ptable = ATappend(ptable, symbol);
   }

   /* Coalesce the table of productions so there is one production per symbol
    */
   ptable = ofp_coalesceProdTable(ptable);

   return ptable;
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

ATbool ofp_build_traversal_func_begin(ATerm name)
{
   char * percs = "%s";
   char * nameStr;

   if (! ATmatch(name, "<str>", &nameStr)) {
      return ATfalse;
   }

   /** write to implementation file
    */
   fprintf(fpc, "ATbool ofp_traverse_%s(ATerm term, pOFP_Traverse %s)\n", nameStr, nameStr);
   fprintf(fpc, "{\n");

   /** Debugging output
    */
   fprintf(fpc, "#ifdef DEBUG_PRINT\n");
   fprintf(fpc, "   printf(\"%s: %s\\n\", ATwriteToString(term));\n", nameStr, percs);
   fprintf(fpc, "#endif\n\n");

   return ATtrue;
}

ATbool ofp_build_traversal_func_end(ATerm name, ATbool returnTrue)
{
   if (returnTrue) fprintf(fpc, "   return ATtrue;\n");
   else            fprintf(fpc, "   return ATfalse;\n");
   fprintf(fpc, "}\n\n");
   return ATtrue;
}

ATbool ofp_build_traversal_string_match(ATerm name)
{
   char * nameStr;

   if (! ATmatch(name, "<str>", &nameStr)) {
      return ATfalse;
   }

   /** Match the name term, otherwise return false
    */
   fprintf(fpc, "   char * %s_val;\n", nameStr);
   fprintf(fpc, "   if (ATmatch(term, \"<str>\", &%s_val)) {\n", nameStr);
   fprintf(fpc, "      // MATCHED %s\n", nameStr);
   fprintf(fpc, "      return ATtrue;\n");
   fprintf(fpc, "   } else return ATfalse;\n\n");

   return ATtrue;
}

ATbool ofp_build_match_terminal(ATerm terminal)
{
   char * name;
   if (! ATmatch(terminal, "<str>", &name)) {
      return ATfalse;
   }

   /** Match the terminal name
    */
   fprintf(fpc, "   if (ATmatch(term, \"%s\")) {\n", name);
   fprintf(fpc, "      // MATCHED %s\n", name);
   fprintf(fpc, "      return ATtrue;\n");
   fprintf(fpc, "   }\n\n");

   return ATtrue;
}

ATbool ofp_build_match_begin(ATerm symbol)
{
   char * sym_name;
   if (! ATmatch(symbol,      "<str>", &sym_name )) return ATfalse;

   /** Match into the symbol name traversal struct
    */
   fprintf(fpc, " // This match may not be required for some productions.\n");
   fprintf(fpc, " if (ATmatch(term, \"%s(<term>)\", &%s->term)) {\n", sym_name, sym_name);

   return ATtrue;
}

ATbool ofp_build_match_end(ATerm symbol)
{
   fprintf(fpc, " }\n\n");
   return ATtrue;
}

ATbool ofp_build_match_nonterminal_begin(ATerm constructor, ATerm symbol)
{
   char * cons_name, * sym_name;
   if (! ATmatch(constructor, "<str>", &cons_name)) return ATfalse;
   if (! ATmatch(symbol,      "<str>", &sym_name )) return ATfalse;

   /** Match into the constructor name traversal struct
    */
   fprintf(fpc, "   OFP_Traverse %s;\n", sym_name);
   fprintf(fpc, "   if (ATmatch(term, \"%s(<term>)\", &%s.term)) {\n", cons_name, sym_name);

   return ATtrue;
}

ATbool ofp_build_match_nonterminal_end(ATerm constructor, ATerm symbol)
{
   fprintf(fpc, "   }\n\n");
   return ATtrue;
}

ATbool ofp_build_traversal_nonterminal_common(ATerm symbol, ATerm prod_symbol)
{
   char * sym_name, * prod_name;
   if (! ATmatch(symbol,      "<str>", &sym_name )) return ATfalse;
   if (! ATmatch(prod_symbol, "<str>", &prod_name)) return ATfalse;

   fprintf(fpc, "   OFP_Traverse %s;\n", prod_name);
   fprintf(fpc, "   if (ofp_traverse_%s(%s->term, &%s)) {\n", prod_name, sym_name, prod_name);
   fprintf(fpc, "      // MATCHED %s\n", prod_name);
   fprintf(fpc, "      return ATtrue;\n");
   fprintf(fpc, "   } \n");

   return ATtrue;
}

ATbool ofp_build_traversal_nonterminal(ATerm symbol)
{
   char * name;
   if (! ATmatch(symbol, "<str>", &name)) {
      return ATfalse;
   }

   fprintf(fpc, "      if (ofp_traverse_%s(%s.term, &%s)) {\n", name, name, name);
   fprintf(fpc, "         // MATCHED %s\n", name);
   fprintf(fpc, "         return ATtrue;\n");
   fprintf(fpc, "      } else return ATfalse;\n");

   return ATtrue;
}

ATbool ofp_build_traversal_nonterminals_common(ATerm symbol, ATerm constructor, ATermList prod_symbols)
{
   ATermList tail = (ATermList) ATmake("<term>", prod_symbols);
   while (! ATisEmpty(tail)) {
      ATerm head, prod_symbol;
      head = ATgetFirst(tail);
      tail = ATgetNext(tail);

      if (! ATmatch(head, "ConstType(SortNoArgs(<term>))", &prod_symbol)) {
         return ATfalse;
      }
      ofp_build_traversal_nonterminal_common(symbol, prod_symbol);
   }
   return ATtrue;
}

ATbool ofp_build_traversal_nonterminals(ATerm constructor, ATermList prod_symbols)
{
   char * name;
   if (! ATmatch(constructor, "<str>", &name)) {
      return ATfalse;
   }

   ATermList tail = (ATermList) ATmake("<term>", prod_symbols);
   while (! ATisEmpty(tail)) {
      ATerm head, prod_symbol;
      head = ATgetFirst(tail);
      tail = ATgetNext(tail);

      if (ATmatch(head, "ConstType(SortNoArgs(<term>))", &prod_symbol)) {
         printf("....... symbol: %s\n", ATwriteToString(prod_symbol));
      }

      ofp_build_match_nonterminal_begin(constructor, prod_symbol);
      ofp_build_traversal_nonterminal(prod_symbol);
      ofp_build_match_nonterminal_end(constructor, prod_symbol);
   }

   return ATtrue;
}

ATbool ofp_build_string_traversal(ATerm type, ATerm name)
{
   char * nameStr;

   if (! ATisEqual(type, ATmake("<str>", "String"))) {
      return ATfalse;
   }

   if (! ATmatch(name, "<str>", &nameStr)) {
      return ATfalse;
   }

   ofp_build_traversal_func_begin(name);
   ofp_build_traversal_string_match(name);
   ofp_build_traversal_func_end(name, ATfalse);

   return ATfalse;
}

ATbool ofp_build_list_traversal(ATerm name)
{
   char * nameStr;
   char * percs = "%s";

   if (! ATmatch(name, "<str>", &nameStr)) {
      return ATfalse;
   }

   /** write to header file
    */
   //fprintf(fph, "ATbool ofp_traverse_%s(ATerm term, pOFP_Traverse %s);\n", listStr, listStr);

   /** Match the list term, otherwise return false
    */
   fprintf(fpc, "   if (! ATmatch(term, \"%sList(<term>)\", &%sList->term)) {\n", nameStr, nameStr);
   fprintf(fpc, "      return ATfalse;\n");
   fprintf(fpc, "   }\n\n");

   /** Traverse the list
    */
   fprintf(fpc, "   OFP_Traverse %s;\n", nameStr);
   fprintf(fpc, "   ATermList %s_tail = (ATermList) ATmake(\"<term>\", %sList->term);\n", nameStr, nameStr);
   fprintf(fpc, "   while (! ATisEmpty(%s_tail)) {\n", nameStr);
   fprintf(fpc, "      %s.term = ATgetFirst(%s_tail);\n", nameStr, nameStr);
   fprintf(fpc, "      %s_tail = ATgetNext (%s_tail);\n", nameStr, nameStr);
   fprintf(fpc, "      if (ofp_traverse_%s(%s.term, &%s)) {\n", nameStr, nameStr, nameStr);
   fprintf(fpc, "         // MATCHED %s\n", nameStr);
   fprintf(fpc, "      } else return ATfalse;\n");
   fprintf(fpc, "   }\n");

   return ATtrue;
}
