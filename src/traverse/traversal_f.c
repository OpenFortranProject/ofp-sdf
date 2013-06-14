#include "traversal.h"
#include <assert.h>
#include <stdlib.h>

#undef DEBUG_PRINT

ATermList gTypeTable;

char * ofp_getArgName(ATerm list, char ** name)
{
   ATerm aType;
   if (ATmatch(list, "[<term>,<str>]", &aType, name)) {
      // MATCHED name
   }
   else {
      printf("\nofp_getArgName: Error reading name from %s\n", ATwriteToString(list));
      exit(1);
   }
   return *name;
}

ATbool ofp_isArgListType(ATerm list)
{
   char * type;
   ATerm aType, aName;
   if (ATmatch(list, "[<str>,<term>]", &type, &aName)) {
      // MATCHED name
   }
   else {
      printf("\nofp_isArgListType: Error reading type from %s\n", ATwriteToString(list));
      exit(1);
   }

   if (strncmp("List", type, 4) == 0) {
      return ATtrue;
   }
   return ATfalse;
}

ATbool ofp_isArgOptionType(ATerm list)
{
   char * kind;
   ATerm aName;
   if (ATmatch(list, "[<str>,<term>]", &kind, &aName)) {
      // MATCHED name
   }
   else {
      printf("\nofp_isArgOptionType: Error reading kind from %s\n", ATwriteToString(list));
      exit(1);
   }

   if (strncmp("Option", kind, 6) == 0) {
      return ATtrue;
   }
   return ATfalse;
}

ATbool ofp_isStringType(ATerm term)
{
   if (ATmatch(term, "[\"String\"]")) {
      return ATtrue;
   }
   return ATfalse;
}

ATerm ofp_getArgType(ATerm term)
{
   int i;
   ATerm kind, name;

   if (ATmatch(term, "[<term>,<term>]", &kind, &name)) {
      // MATCHED name
   } else return ATmake("None");


   for (i = 0; i <  ATgetLength(gTypeTable); i++) {
      ATerm typeName, typeList;
      ATerm name_type = ATelementAt(gTypeTable, i);
      if (ATmatch(name_type, "Type(<term>,<term>)", &typeName, &typeList)) {
         if (ATisEqual(name, typeName)) {
            return typeList;
         }
      }
   }

   return ATmake("None");
}

/** Make traversal call for a production
 */
ATbool ofp_build_node_traversal(ATerm term)
{
   ATerm typeList;
   ATbool option_type;
   char * arg_name = "None";

   option_type = ofp_isArgOptionType(term);
   arg_name = ofp_getArgName(term, &arg_name);
   typeList = ofp_getArgType(term);

   if (ofp_isArgListType(term)) {
      printf("      ATermList %s_tail = (ATermList) ATmake(\"<term>\", %s_list.term);\n", arg_name, arg_name);
      printf("      while (! ATisEmpty(%s_tail)) {\n", arg_name);
      printf("         OFP_Traverse %s;\n", arg_name);
      printf("         %s.term = ATgetFirst(%s_tail);\n", arg_name, arg_name);
      printf("         %s_tail = ATgetNext(%s_tail);\n", arg_name, arg_name);
      printf("         if (ofp_traverse_%s(%s.term, &%s)) {\n", arg_name, arg_name, arg_name);
      printf("            // MATCHED %s\n", arg_name);
      printf("         } else return ATfalse;\n");
      printf("      }\n");
   }
   else if (ofp_isStringType(typeList)) {
      printf("      char * str;\n");
      printf("      if (ATmatch(%s.term, ", arg_name);
      if (option_type) {
         printf("\"Some(<str>)\"");
      }
      else {
         printf("\"<str>\"");
      }
      printf(", &str)) {\n");
      printf("         // MATCHED %s\n", arg_name);
      printf("      } else return ATfalse;\n\n");
   }
   else {
      printf("      if (ofp_traverse_%s(%s.term, &%s)) {\n", arg_name, arg_name, arg_name);
      printf("         // MATCHED %s\n", arg_name);
      printf("      } else return ATfalse;\n\n");
   }

      //      if (option_type) {
      //         printf("Some(<term>)\"");
      //      }
      //      else {
      //         printf("<term>\"");
      //      }

   return ATtrue;
}

ATbool ofp_traverse_FunType_arg(ATerm term, pOFP_Traverse FunType_arg)
{
#ifdef DEBUG_PRINT
   printf("\nFunType_arg: %s\n", ATwriteToString(term));
#endif

   if (ATmatch(term, "ConstType(Sort(<str>,<term>))", &FunType_arg->pre, &FunType_arg->term)) {
      if (ATmatch(FunType_arg->term, "[SortNoArgs(<str>)]", &FunType_arg->post)) {
         // MATCHED FunType_arg_type
      } else return ATfalse;
   }
   else if (ATmatch(term, "ConstType(SortNoArgs(<str>))", &FunType_arg->post)) {
      // MATCHED FunType_arg_type
      FunType_arg->pre = "None";
   }
   else {
      return ATfalse;
   }
   FunType_arg->term = ATmake("[<str>,<str>]", (char*)FunType_arg->pre, (char*)FunType_arg->post);

   return ATtrue;
}

ATbool ofp_traverse_FunType_result(ATerm term, pOFP_Traverse FunType_result)
{
#ifdef DEBUG_PRINT
   printf("\nFunType_result: %s\n", ATwriteToString(term));
#endif

   if (ATmatch(term, "ConstType(SortNoArgs(<str>))", &FunType_result->post)) {
      // MATCHED FunType_result
      return ATtrue;
   }

   return ATfalse;
}

ATbool ofp_traverse_FunType(ATerm term, pOFP_Traverse FunType)
{
   int i;
   char * percent_s = "%s";
   char * comma = "";
   char * name = "None";
   ATermList args = (ATermList) ATmake("[]");

#ifdef DEBUG_PRINT
   printf("\nFunType: %s\n", ATwriteToString(term));
#endif

   OFP_Traverse FunType_args, FunType_result;
   if (ATmatch(term, "FunType(<term>,<term>)", &FunType_args.term, &FunType_result.term) ) {

      if (ofp_traverse_FunType_result(FunType_result.term, &FunType_result)) {
         // MATCHED FunType_result
         name = (char*) FunType_result.post;
      } else return ATfalse;

      ATermList FunType_args_tail = (ATermList) ATmake("<term>", FunType_args.term);
      while (! ATisEmpty(FunType_args_tail)) {
         OFP_Traverse FunType_arg;
         FunType_arg.term = ATgetFirst(FunType_args_tail);
         FunType_args_tail = ATgetNext(FunType_args_tail);

         if (ofp_traverse_FunType_arg(FunType_arg.term, &FunType_arg)) {
            // MATCHED FunType_arg
            args = ATappend(args, FunType_arg.term);
         } else return ATfalse;
      }

   }

   /** Output traversal function header information
    */
   printf("\n");
   printf("//========================================================================================\n");
   printf("// %s\n", name);
   printf("//----------------------------------------------------------------------------------------\n");
   printf("ATbool ofp_traverse_%s(ATerm term, pOFP_Traverse %s)\n", name, name);
   printf("{\n");
   printf("#ifdef DEBUG_PRINT\n");
   printf("   printf(\"%s: %s\\n\", ATwriteToString(term));\n", name, percent_s);
   printf("#endif\n\n");

   /** Declare input (args) to production 
    */
   comma = "";
   printf("   OFP_Traverse");
   for (i = 0; i <  ATgetLength(args); i++) {
      char * arg_name = "None";
      ATerm arg = ATelementAt(args, i);
      ATbool list_type = ofp_isArgListType(arg);
      printf("%s %s", comma, ofp_getArgName(arg, &arg_name));
      if (list_type) printf("_list");
      comma = ",";
   }
   printf(";\n");

   /** Traverse input (args) to production 
    */
   comma = "";
   printf("   if (ATmatch(term, \"%s(", name);
   for (i = 0; i <  ATgetLength(args); i++) {
      printf("%s<term>", comma);
      comma = ",";
   }
   printf(")\"");

   for (i = 0; i <  ATgetLength(args); i++) {
      char * arg_name = "None";
      ATerm arg = ATelementAt(args, i);
      ATbool list_type = ofp_isArgListType(arg);

      printf(", &%s", ofp_getArgName(arg, &arg_name));
      if (list_type) printf("_list");
      printf(".term");
   }
   printf(")) {\n\n");

   /** Call traversal for input (arg) to production 
    */
   for (i = 0; i <  ATgetLength(args); i++) {
      ofp_build_node_traversal(ATelementAt(args, i));
   }

   printf("\n      return ATtrue;\n");
   printf("   }\n");
   printf("\n   return ATfalse;\n");
   printf("}\n");

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
      }
      if (ofp_traverse_FunType(FunType.term, &FunType)) {
         // MATCHED FunType
      } else return ATfalse;

      return ATtrue;
   }
   else if (ATmatch(term, "OpDeclInj(<term>)", &FunType.term) ) {
      // MATCHED OpDeclInj: already processed these terms
      return ATtrue;
   }

   return ATfalse;
}

ATbool ofp_traverse_OpDeclInj(ATerm term, pOFP_Traverse OpDeclInj)
{
   ATerm name, type;
   if (ATmatch(term, "OpDeclInj(<term>)", &OpDeclInj->term)) {
#ifdef DEBUG_PRINT
      printf("\nofp_traverse_OpDeclInj: %s\n", ATwriteToString(OpDeclInj->term));
#endif
      if (ATmatch(OpDeclInj->term, "FunType(<term>,<term>)", &type, &name)) {
         if (ATmatch(type, "[ConstType(SortNoArgs(<term>))]", &type)) {
            // MATCHED object type
         } else return ATfalse;
         if (ATmatch(name, "ConstType(SortNoArgs(<term>))", &name)) {
            // MATCHED object name
         } else return ATfalse;
      } else return ATfalse;

      OpDeclInj->term = ATmake("Type(<term>,[<term>])", name, type);

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
      gTypeTable = (ATermList) ATmake("[]");

      /* First build the type table.  It is needed when matching productions.
       */
      ATermList OpDeclInj_tail = (ATermList) ATmake("<term>", OpDecl_list.term);
      while (! ATisEmpty(OpDeclInj_tail)) {
         OFP_Traverse OpDeclInj;
         OpDeclInj.term = ATgetFirst(OpDeclInj_tail);
         OpDeclInj_tail = ATgetNext(OpDeclInj_tail);

         if (ofp_traverse_OpDeclInj(OpDeclInj.term, &OpDeclInj)) {
            // MATCHED OpDecl
            gTypeTable = ATappend(gTypeTable, OpDeclInj.term);
         }
      }

      ATermList OpDecl_tail = (ATermList) ATmake("<term>", OpDecl_list.term);
      while (! ATisEmpty(OpDecl_tail)) {
         OFP_Traverse OpDecl;
         OpDecl.term = ATgetFirst(OpDecl_tail);
         OpDecl_tail = ATgetNext(OpDecl_tail);

         if (ofp_traverse_OpDecl(OpDecl.term, &OpDecl)) {
            // MATCHED OpDecl
         } else return ATfalse;
      }

      printf("\nTYPES: %s\n", ATwriteToString((ATerm) gTypeTable));

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
         printf("\nModule name: %s\n", String);
      }

      ATermList Signature_tail = (ATermList) ATmake("<term>", Signature_list.term);
      while (! ATisEmpty(Signature_tail)) {
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
