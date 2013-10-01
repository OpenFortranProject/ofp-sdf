#include "traversal.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#undef DEBUG_PRINT

// global variables
//
FILE * fpc = NULL;

ATermList gTypeAliases;  // TODO - delete me

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

ATbool ofp_build_traversal_func_end(ATerm name)
{
   fprintf(fpc, "   return ATtrue;\n");
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
   ofp_build_traversal_func_end(name);

   return ATfalse;
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
