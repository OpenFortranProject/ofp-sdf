#include "ofp_builder.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#undef DEBUG_PRINT

/**
 * Returns the ultimate symbol found after traversing the alias table
 */
ATerm ofp_getUltimateSymbol(ATermTable table, ATerm symbol)
{
   ATerm alias = ATtableGet(table, symbol);
   if (alias != NULL) {
      ATerm aname = ofp_getAliasSymbol(alias);
      return ofp_getUltimateSymbol(table, aname);
   }
   return symbol;
}

/**
 * Returns the symbol, or a modified form of the symbol if it
 * is already present.
 */
ATerm ofp_getUniqueSymbol(ATermTable table, ATerm symbol)
{
   int id = 0;
   ATerm sym = symbol;
   ATerm value = ATtableGet(table, symbol);

   if (value) {
      fprintf(fpc, "//.......       from table: %s\n", ATwriteToString(value));
      assert(ATmatch(value, "<int>", &id));
      id += 1;
      fprintf(fpc, "//.......               id: %d\n", id);

      int len;
      char * symString, * uniqueString;

      assert(ATmatch(symbol, "<str>", &symString));
      assert(id < 1000);    // ensures that new name fits

      len = strlen(symString) + 3;
      uniqueString = (char*) malloc(len);
      sprintf(uniqueString, "%s%d", symString, id);

      sym = ATmake("<str>", uniqueString);

      fprintf(fpc, "//.......       unique sym: %s\n", ATwriteToString(sym));
      free(uniqueString);
   }

   ATtablePut(table, symbol, ATmake("<int>", id));

   return sym;   
}

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

ATbool ofp_isOptionType(ATerm term)
{
   if (ATmatch(term, "\"Option\"")) {
      return ATtrue;
   }
   return ATfalse;
}

ATbool ofp_isConstType(ATerm term)
{
   if (ATmatch(term, "\"Const\"")) {
      return ATtrue;
   }
   return ATfalse;
}

enum DataType ofp_getDataType(ATerm term)
{
   if (ofp_isStringType(term)) return STRING;
   if (ofp_isIdentType (term)) return IDENT;
   if (ofp_isOptionType(term)) return OPTION;
   if (ofp_isConstType (term)) return CONST;

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

char * ofp_getChars(ATerm term)
{
   char * cptr;
   assert(ATmatch(term, "<str>", &cptr));
   return cptr;
}

ATerm ofp_getArgName(ATerm term)
{
   ATerm name, type;

   assert(ATmatch(term, "Arg(<term>,<term>)", &name, &type));
   return name;
}

ATerm ofp_getArgType(ATerm term)
{
   ATerm name, type;

   assert(ATmatch(term, "Arg(<term>,<term>)", &name, &type));
   return type;
}

ATerm ofp_getAliasSymbol(ATerm term)
{
   ATerm symbol, alias, type;

   assert(ATmatch(term, "Alias(<term>,<term>,<term>)", &symbol, &alias, &type));
   return symbol;
}

ATerm ofp_getAliasName(ATerm term)
{
   ATerm symbol, alias, type;

   assert(ATmatch(term, "Alias(<term>,<term>,<term>)", &symbol, &alias, &type));
   return alias;
}

ATerm ofp_getAliasType(ATerm term)
{
   ATerm symbol, alias, type;

   assert(ATmatch(term, "Alias(<term>,<term>,<term>)", &symbol, &alias, &type));
   return type;
}

ATerm ofp_getProdArgName(ATerm term)
{
   ATerm name;
   if (ATmatch(term, "ConstType(SortNoArgs(<term>))", &name)) {
      return name;
   }
   else if (ATmatch(term, "ConstType(Sort(\"Option\",[SortNoArgs(<term>)]))", &name)) {
      return name;
   }
   else if (ATmatch(term, "ConstType(Sort(\"List\",[SortNoArgs(<term>)]))", &name)) {
      return name;
   }

   return ATmake("<str>", "UNKNOWN");
}

ATerm ofp_getProdArgType(ATerm term)
{
   ATerm name, type;
   if (ATmatch(term, "ConstType(SortNoArgs(<term>))", &name)) {
      return ATmake("<str>", "Const");
   }
   else if (ATmatch(term, "ConstType(Sort(\"Option\",[SortNoArgs(<term>)]))", &name)) {
      return ATmake("<str>", "Option");
   }
   else if (ATmatch(term, "ConstType(Sort(\"List\",[SortNoArgs(<term>)]))", &name)) {
      return ATmake("<str>", "List");
   }

   return ATmake("<str>", "UNKNOWN");
}

ATermList ofp_getArgList(ATermList alist)
{
   ATerm name, type;

   ATermList args = (ATermList) ATmake("[]");

   ATermList tail = (ATermList) ATmake("<term>", alist);
   while (! ATisEmpty(tail)) {
      ATerm head = ATgetFirst(tail);
      ATerm name = ofp_getUltimateSymbol(gAliasTable, ofp_getProdArgName(head));
      ATerm type = ofp_getProdArgType(head);

      tail = ATgetNext(tail);
      args = ATappend(args, ATmake("Arg(<term>,<term>)", name, type));
   }

   return args;
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

      // coalesce multiple productions of same name
      while (ATisEqual(headName, nextName)) {
         head = ATgetFirst(tail);
         tail = ATgetNext(tail);

         if (ATisEmpty(tail)) next = ATmake("Symbol(None,None)");
         else                 next = ATgetFirst(tail);

         assert( ATmatch(head, "Symbol(<term>,<term>)", &headName, &headProd) );
         assert( ATmatch(next, "Symbol(<term>,<term>)", &nextName, &nextProd) );

         plist = ATappend(plist, headProd);
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
         printf("******** Prod(%d) ", ATgetLength(plist));
         printf("%s\n", ATwriteToString(symbol));
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
      ATerm headSymbol, headAlias, headType, next, nextSymbol, nextAlias, nextType;

      if (ATisEmpty(tail)) next = ATmake("Alias(None,None,None)");
      else                 next = ATgetFirst(tail);

      assert( ATmatch(head, "Alias(<term>,<term>,<term>)", &headSymbol, &headAlias, &headType) );
      assert( ATmatch(next, "Alias(<term>,<term>,<term>)", &nextSymbol, &nextAlias, &nextType) );

      // throw away multiple productions of same alias
      if (ATisEqual(headAlias, nextAlias)) {
         while (ATisEqual(headAlias, nextAlias)) {
            // skip these two
            if (ATisEmpty(tail)) return table;

            tail = ATgetNext(tail);
            head = ATgetFirst(tail);
            tail = ATgetNext(tail);

            if (ATisEmpty(tail)) next = ATmake("Alias(None,None,None)");
            else                 next = ATgetFirst(tail);

            assert( ATmatch(head, "Alias(<term>,<term>,<term>)", &headSymbol, &headAlias, &headType) );
            assert( ATmatch(next, "Alias(<term>,<term>,<term>)", &nextSymbol, &nextAlias, &nextType) );
         }
      }
      else if (!ofp_isPrimitiveType(headSymbol)) {
         // skip primitive types
         table = ATappend(table, head);
      }

      if (ATisEmpty(tail)) break;

      head = ATgetFirst(tail);
      tail = ATgetNext(tail);
   }

   return table;
}

ATbool ofp_build_traversal_func_header(ATerm name)
{
   char * percs = "%s";
   char * nameStr;

   if (! ATmatch(name, "<str>", &nameStr)) {
      return ATfalse;
   }

   /** write to header file
    */
   fprintf(fph, "ATbool ofp_traverse_%s(ATerm term, pOFP_Traverse %s);\n", nameStr, nameStr);

   return ATtrue;
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

   /** Return condition
    */
   fprintf(fpc, " ATbool matched = ATfalse;\n");

   return ATtrue;
}

ATbool ofp_build_traversal_func_end(ATerm name, ATbool returnTrue)
{
   if (returnTrue) fprintf(fpc, " return ATtrue;\n");
   else            fprintf(fpc, " return ATfalse;\n");
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

ATbool ofp_build_match_args_decl(ATermList args)
{
   char * comma = "";
   ATermList tail = (ATermList) ATmake("<term>", args);

   fprintf(fpc, " OFP_Traverse");
   while (! ATisEmpty(tail)) {
      ATerm head = ATgetFirst(tail);
      ATerm name = ofp_getArgName(head);
      tail = ATgetNext(tail);
      fprintf(fpc, "%s %s", comma, ofp_getChars(name));
      comma = ",";
   }
   fprintf(fpc, ";\n");

   return ATtrue;
}

ATbool ofp_build_match_begin(ATerm symbol, ATerm constructor, ATermList args)
{
   int i, len;
   ATerm cons, prod, arglist;
   char * comma = "";

   ofp_build_match_args_decl(args);
   len = ATgetLength(args);

   fprintf(fpc, " if (ATmatch(term, \"%s(", ofp_getChars(constructor));
   for (i = 0; i < len; i++) {
      fprintf(fpc, "%s<term>", comma);
      comma = ",";
   }
   fprintf(fpc, ")\"");
   for (i = 0; i < len; i++) {
      ATerm name = ofp_getArgName(ATelementAt(args, i));
      fprintf(fpc, ", &%s.term", ofp_getChars(name));
   }
   fprintf(fpc, ")) {\n");

   return ATtrue;
}

ATbool ofp_build_match_end(ATerm symbol, ATerm constructor)
{
   if (ATisEqual(symbol, constructor)) {
      fprintf(fpc, "\n   if (matched) return ATtrue;\n");
   }
   else {
      fprintf(fpc, "\n   // MATCHED %s\n", ATwriteToString(constructor));
      fprintf(fpc, "\n   return ATtrue;\n");
   }
   fprintf(fpc, " }\n\n");

   return ATtrue;
}

ATbool ofp_build_match_all_begin(ATerm symbol, ATerm unique, ATerm type, ATbool aliased)
{
   char * name;

   switch (ofp_getDataType(type)) {
      case OPTION:
         ofp_build_match_sort_option_begin(unique, aliased);
         break;
      case CONST:
         name = ofp_getChars(unique);
         fprintf(fpc, "   if (ATmatch(%s.term, \"(<term>)\", &%s.term)) {\n", name, name);
         break;
      default:
         printf("ERROR: ofp_build_match_all_begin: symbol type not handled: %s\n", ATwriteToString(type));
         break;
   }

   /* Recurs if an alias exists */
   ATerm alias = ATtableGet(gAliasTable, symbol);
   if (alias != NULL) {
      ATerm aname   = ofp_getAliasName(alias);
      ATerm asymbol = ofp_getAliasSymbol(alias);
      type = ofp_getAliasType(alias);
      printf("------ recursion: %s\n", ATwriteToString(alias));
      printf("------     alias: %s\n", ATwriteToString(asymbol));
      printf("------    unique: %s\n", ATwriteToString(unique));
      printf("------      type: %s\n", ATwriteToString(type));

      ofp_build_match_all_begin(asymbol, unique, type, ATtrue);
   }

   return ATtrue;
}

ATbool ofp_build_match_all_end(ATerm symbol, ATerm unique, ATerm type)
{
   fprintf(fpc, "   }\n");

   /* Recurs if an alias exists */
   ATerm alias = ATtableGet(gAliasTable, symbol);
   if (alias != NULL) {
      ATerm asymbol = ofp_getAliasSymbol(alias);
      printf("++++++     alias: %s\n", ATwriteToString(asymbol));
      ofp_build_match_all_end(asymbol, unique, type);
   }

   return ATtrue;

}

ATbool ofp_build_match_sort_option_begin(ATerm symbol, ATbool aliased)
{
   char * name = ofp_getChars(symbol);
   if (aliased) {
      fprintf(fpc, "   if (ATmatch(%s.term, \"(Some(<term>))\", &%s.term)) {\n", name, name);
   }
   else {
      fprintf(fpc, "   if (ATmatch(%s.term, \"Some(<term>)\", &%s.term)) {\n", name, name);
   }
   return ATtrue;
}

ATbool ofp_build_match_sort_option_end(ATerm symbol)
{
   fprintf(fpc, "   }\n");
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

ATbool ofp_build_traversal_nonterminal_common(ATerm symbol, ATerm prod_symbol, ATerm unique_sym)
{
   char * sym_name, * prod_name, * unique;
   if (! ATmatch(symbol,      "<str>", &sym_name )) return ATfalse;
   if (! ATmatch(prod_symbol, "<str>", &prod_name)) return ATfalse;
   if (! ATmatch(unique_sym,  "<str>", &unique   )) return ATfalse;

   //TODO - figure this out
   //fprintf(fpc, "   OFP_Traverse %s;\n", unique);
   //fprintf(fpc, "   if (ofp_traverse_%s(%s->term, &%s)) {\n", prod_name, sym_name, unique);
   fprintf(fpc, "    if (ofp_traverse_%s(%s.term, &%s)) {\n", prod_name, prod_name, unique);
   fprintf(fpc, "       // MATCHED %s\n", prod_name);
   //fprintf(fpc, "       return ATtrue;\n");
   //fprintf(fpc, "    } \n");
   fprintf(fpc, "    } else return ATfalse;\n");

   return ATtrue;
}

ATbool ofp_build_traversal_nonterminal(ATerm symbol, ATerm prod_symbol, ATerm unique_sym)
{
   char * sym_name, * prod_name, * unique;
   assert(ATmatch(symbol,      "<str>", &sym_name ));
   assert(ATmatch(prod_symbol, "<str>", &prod_name));
   assert(ATmatch(unique_sym,  "<str>", &unique   ));

   fprintf(fpc, "      if (ofp_traverse_%s(%s.term, &%s)) {\n", prod_name, unique, unique);
   fprintf(fpc, "         // MATCHED %s\n", prod_name);
   fprintf(fpc, "         matched = ATtrue;\n");
   fprintf(fpc, "      } else return ATfalse;\n");

   return ATtrue;
}

ATbool ofp_build_traversal_production(ATerm symbol, ATerm constructor, ATermList prod_symbols)
{
   ATermList tail = (ATermList) ATmake("<term>", prod_symbols);
   while (! ATisEmpty(tail)) {
      ATerm head, prod_symbol;
      head = ATgetFirst(tail);
      tail = ATgetNext(tail);

      if (! ATmatch(head, "ConstType(<term>)", &head)) {
         return ATfalse;
      }

      if (ATmatch(head, "Sort(\"Option\", [SortNoArgs(<term>)])", &prod_symbol)) {
         ATerm ultimate = ofp_getUltimateSymbol (gAliasTable, prod_symbol);
         ATerm unique   = ofp_getUniqueSymbol   (gSymTable,   ultimate);
         ATerm alias    = ATtableGet            (gAliasTable, prod_symbol);

                      printf(".....     cons  : %s\n", ATwriteToString(constructor));
                      printf(".....     symbol: %s\n", ATwriteToString(symbol));
                      printf(".....sort symbol: %s\n", ATwriteToString(prod_symbol));
                      printf(".....ulti symbol: %s\n", ATwriteToString(ultimate));
                      printf(".....uniq symbol: %s\n", ATwriteToString(unique));
   if (alias != NULL) printf(".....     alias : %s\n", ATwriteToString(alias));

         //ofp_build_match_sort_option_begin(unique);
         fprintf(fpc, "\n");  // pretty printing
         ofp_build_match_all_begin(prod_symbol, unique, ATmake("<str>", "Option"), ATfalse);
         ofp_build_traversal_nonterminal(symbol, ultimate, unique);
         //ofp_build_match_sort_option_end(unique);
         ofp_build_match_all_end(prod_symbol, unique, ATmake("<str>", "Option"));
      }
      else if (ATmatch(head, "Sort(\"List\", [SortNoArgs(<term>)])", &prod_symbol)) {
         fprintf(fpc, "\n");
         ofp_build_list_traversal(prod_symbol);
      }
      else if (ATmatch(head, "SortNoArgs(<term>)", &prod_symbol)) {
   printf(".....arg  symbol: %s\n", ATwriteToString(prod_symbol));
         ATerm unique = ofp_getUniqueSymbol(gSymTable, prod_symbol);
         fprintf(fpc, "\n");  // make spacing same as Sort match
         ofp_build_traversal_nonterminal(symbol, prod_symbol, unique);
      }
      else {
         printf("ofp_build_traversal_nonterminals_common: need to match something else: %s\n",
                 ATwriteToString(head));
         return ATfalse;
      }
   }

   return ATtrue;
}

ATbool ofp_build_traversal_nonterminals_common(ATerm symbol, ATerm constructor, ATermList prod_symbols)
{
   ATermList tail = (ATermList) ATmake("<term>", prod_symbols);
   while (! ATisEmpty(tail)) {
      ATerm head, prod_symbol;
      head = ATgetFirst(tail);
      tail = ATgetNext(tail);

      if (! ATmatch(head, "ConstType(<term>)", &head)) {
         return ATfalse;
      }

      if (ATmatch(head, "Sort(\"Option\", [SortNoArgs(<term>)])", &prod_symbol)) {
         ATerm unique = ofp_getUniqueSymbol(gSymTable, prod_symbol);
         ofp_build_match_sort_option_begin(unique, ATfalse);
         ofp_build_traversal_nonterminal_common(symbol, prod_symbol, unique);
         ofp_build_match_sort_option_end(unique);
      }
      else if (ATmatch(head, "Sort(\"List\", [SortNoArgs(<term>)])", &prod_symbol)) {
         fprintf(fpc, "    //########### ==need to match LIST: %s\n", ATwriteToString(prod_symbol));
         return ofp_build_list_traversal(prod_symbol);
      }
      else if (ATmatch(head, "SortNoArgs(<term>)", &prod_symbol)) {
         ATerm unique = ofp_getUniqueSymbol(gSymTable, prod_symbol);
         ofp_build_traversal_nonterminal_common(symbol, prod_symbol, unique);
         return ATtrue;
      }
      else {
         printf("ofp_build_traversal_nonterminals_common: need to match something else: %s\n",
                 ATwriteToString(head));
         return ATfalse;
      }
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
         ATerm unique = ofp_getUniqueSymbol(gSymTable, prod_symbol);
         ofp_build_match_nonterminal_begin(constructor, unique);
         //ofp_build_traversal_nonterminal(prod_symbol, unique);
         ofp_build_match_nonterminal_end(constructor, unique);
      }
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

   /** Traverse the list
    */
   fprintf(fpc, "   ATermList %s_tail = (ATermList) ATmake(\"<term>\", %s.term);\n", nameStr, nameStr);
   fprintf(fpc, "   while (! ATisEmpty(%s_tail)) {\n", nameStr);
   fprintf(fpc, "      %s.term = ATgetFirst(%s_tail);\n", nameStr, nameStr);
   fprintf(fpc, "      %s_tail = ATgetNext (%s_tail);\n", nameStr, nameStr);
   fprintf(fpc, "      if (ofp_traverse_%s(%s.term, &%s)) {\n", nameStr, nameStr, nameStr);
   fprintf(fpc, "         // MATCHED %s\n", nameStr);
   fprintf(fpc, "         matched = ATtrue;\n", nameStr);
   fprintf(fpc, "      } else return ATfalse;\n");
   fprintf(fpc, "   }\n");

   return ATtrue;
}

#ifdef OBSOLETE
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
#endif
