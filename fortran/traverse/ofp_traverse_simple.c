#include "traversal.h"
#include "ofp_traverse_simple.h"

#ifdef NOT_YET
ATbool ofp_traverse_AcDoVariable(ATerm term, pOFP_Traverse AcDoVariable)
{
#ifdef DEBUG_PRINT
   printf("AcDoVariable: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AcDoVariable(<term>)", &AcDoVariable->term)) {
//....... ofp_uniqueSymbol: "DoVariable"
   OFP_Traverse DoVariable;
   if (ofp_traverse_DoVariable(AcDoVariable->term, &DoVariable)) {
      // MATCHED DoVariable
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_AcImpliedDoControl(ATerm term, pOFP_Traverse AcImpliedDoControl)
{
#ifdef DEBUG_PRINT
   printf("AcImpliedDoControl: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AcImpliedDoControl(<term>)", &AcImpliedDoControl->term)) {
//....... ofp_uniqueSymbol: "AcDoVariable"
   OFP_Traverse AcDoVariable;
   if (ofp_traverse_AcDoVariable(AcImpliedDoControl->term, &AcDoVariable)) {
      // MATCHED AcDoVariable
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_AcImpliedDo(ATerm term, pOFP_Traverse AcImpliedDo)
{
#ifdef DEBUG_PRINT
   printf("AcImpliedDo: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AcImpliedDo(<term>)", &AcImpliedDo->term)) {
//....... ofp_uniqueSymbol: "AcValueList"
   OFP_Traverse AcValueList;
   if (ofp_traverse_AcValueList(AcImpliedDo->term, &AcValueList)) {
      // MATCHED AcValueList
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_AcValue(ATerm term, pOFP_Traverse AcValue)
{
#ifdef DEBUG_PRINT
   printf("AcValue: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AcValue(<term>)", &AcValue->term)) {
//....... ofp_uniqueSymbol: "AcImpliedDo"
   OFP_Traverse AcImpliedDo;
   if (ofp_traverse_AcImpliedDo(AcValue->term, &AcImpliedDo)) {
      // MATCHED AcImpliedDo
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "Expr"
   OFP_Traverse Expr;
   if (ofp_traverse_Expr(AcValue->term, &Expr)) {
      // MATCHED Expr
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_AcValueList(ATerm term, pOFP_Traverse AcValueList)
{
#ifdef DEBUG_PRINT
   printf("AcValueList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AcValueList(<term>)", &AcValueList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_AcSpec(ATerm term, pOFP_Traverse AcSpec)
{
#ifdef DEBUG_PRINT
   printf("AcSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AcSpec(<term>)", &AcSpec->term)) {
//....... ofp_uniqueSymbol: "TypeSpec0"
   OFP_Traverse TypeSpec0;
   if (ofp_traverse_TypeSpec0(AcSpec->term, &TypeSpec0)) {
      // MATCHED TypeSpec0
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "TypeSpec"
   OFP_Traverse TypeSpec;
   if (ofp_traverse_TypeSpec(AcSpec->term, &TypeSpec)) {
      // MATCHED TypeSpec
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ArrayConstructor(ATerm term, pOFP_Traverse ArrayConstructor)
{
#ifdef DEBUG_PRINT
   printf("ArrayConstructor: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ArrayConstructor(<term>)", &ArrayConstructor->term)) {
//....... ofp_uniqueSymbol: "AcSpec"
   OFP_Traverse AcSpec;
   if (ofp_traverse_AcSpec(ArrayConstructor->term, &AcSpec)) {
      // MATCHED AcSpec
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_BozLiteralConstant(ATerm term, pOFP_Traverse BozLiteralConstant)
{
#ifdef DEBUG_PRINT
   printf("BozLiteralConstant: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "BozLiteralConstant(<term>)", &BozLiteralConstant->term)) {
//....... ofp_uniqueSymbol: "HexConstant"
   OFP_Traverse HexConstant;
   if (ofp_traverse_HexConstant(BozLiteralConstant->term, &HexConstant)) {
      // MATCHED HexConstant
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "OctalConstant"
   OFP_Traverse OctalConstant;
   if (ofp_traverse_OctalConstant(BozLiteralConstant->term, &OctalConstant)) {
      // MATCHED OctalConstant
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "BinaryConstant"
   OFP_Traverse BinaryConstant;
   if (ofp_traverse_BinaryConstant(BozLiteralConstant->term, &BinaryConstant)) {
      // MATCHED BinaryConstant
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_EndEnumStmt(ATerm term, pOFP_Traverse EndEnumStmt)
{
#ifdef DEBUG_PRINT
   printf("EndEnumStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EndEnumStmt(<term>)", &EndEnumStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(EndEnumStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_EnumeratorList(ATerm term, pOFP_Traverse EnumeratorList)
{
#ifdef DEBUG_PRINT
   printf("EnumeratorList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EnumeratorList(<term>)", &EnumeratorList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_Enumerator(ATerm term, pOFP_Traverse Enumerator)
{
#ifdef DEBUG_PRINT
   printf("Enumerator: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "Enumerator(<term>)", &Enumerator->term)) {
//....... ofp_uniqueSymbol: "NamedConstant"
   OFP_Traverse NamedConstant;
   if (ofp_traverse_NamedConstant(Enumerator->term, &NamedConstant)) {
      // MATCHED NamedConstant
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_EnumeratorDefStmt(ATerm term, pOFP_Traverse EnumeratorDefStmt)
{
#ifdef DEBUG_PRINT
   printf("EnumeratorDefStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EnumeratorDefStmt(<term>)", &EnumeratorDefStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(EnumeratorDefStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_EnumDefStmt(ATerm term, pOFP_Traverse EnumDefStmt)
{
#ifdef DEBUG_PRINT
   printf("EnumDefStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EnumDefStmt(<term>)", &EnumDefStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(EnumDefStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_EnumDef(ATerm term, pOFP_Traverse EnumDef)
{
#ifdef DEBUG_PRINT
   printf("EnumDef: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EnumDef(<term>)", &EnumDef->term)) {
//....... ofp_uniqueSymbol: "EnumDefStmt"
   OFP_Traverse EnumDefStmt;
   if (ofp_traverse_EnumDefStmt(EnumDef->term, &EnumDefStmt)) {
      // MATCHED EnumDefStmt
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ComponentDataSource(ATerm term, pOFP_Traverse ComponentDataSource)
{
#ifdef DEBUG_PRINT
   printf("ComponentDataSource: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ComponentDataSource(<term>)", &ComponentDataSource->term)) {
//....... ofp_uniqueSymbol: "ProcTarget"
   OFP_Traverse ProcTarget;
   if (ofp_traverse_ProcTarget(ComponentDataSource->term, &ProcTarget)) {
      // MATCHED ProcTarget
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "DataTarget"
   OFP_Traverse DataTarget;
   if (ofp_traverse_DataTarget(ComponentDataSource->term, &DataTarget)) {
      // MATCHED DataTarget
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "Expr"
   OFP_Traverse Expr;
   if (ofp_traverse_Expr(ComponentDataSource->term, &Expr)) {
      // MATCHED Expr
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ComponentSpec(ATerm term, pOFP_Traverse ComponentSpec)
{
#ifdef DEBUG_PRINT
   printf("ComponentSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ComponentSpec(<term>)", &ComponentSpec->term)) {
//....... ofp_uniqueSymbol: "Keyword0"
   OFP_Traverse Keyword0;
   if (ofp_traverse_Keyword0(ComponentSpec->term, &Keyword0)) {
      // MATCHED Keyword0
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_StructureConstructor(ATerm term, pOFP_Traverse StructureConstructor)
{
#ifdef DEBUG_PRINT
   printf("StructureConstructor: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "StructureConstructor(<term>)", &StructureConstructor->term)) {
//....... ofp_uniqueSymbol: "DerivedTypeSpec"
   OFP_Traverse DerivedTypeSpec;
   if (ofp_traverse_DerivedTypeSpec(StructureConstructor->term, &DerivedTypeSpec)) {
      // MATCHED DerivedTypeSpec
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_TypeParamSpecList(ATerm term, pOFP_Traverse TypeParamSpecList)
{
#ifdef DEBUG_PRINT
   printf("TypeParamSpecList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "TypeParamSpecList(<term>)", &TypeParamSpecList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_TypeParamSpec(ATerm term, pOFP_Traverse TypeParamSpec)
{
#ifdef DEBUG_PRINT
   printf("TypeParamSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "TypeParamSpec(<term>)", &TypeParamSpec->term)) {
//....... ofp_uniqueSymbol: "Keyword0"
   OFP_Traverse Keyword0;
   if (ofp_traverse_Keyword0(TypeParamSpec->term, &Keyword0)) {
      // MATCHED Keyword0
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_DerivedTypeSpec(ATerm term, pOFP_Traverse DerivedTypeSpec)
{
#ifdef DEBUG_PRINT
   printf("DerivedTypeSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DerivedTypeSpec(<term>)", &DerivedTypeSpec->term)) {
//....... ofp_uniqueSymbol: "TypeName"
   OFP_Traverse TypeName;
   if (ofp_traverse_TypeName(DerivedTypeSpec->term, &TypeName)) {
      // MATCHED TypeName
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_FinalSubroutineNameList(ATerm term, pOFP_Traverse FinalSubroutineNameList)
{
#ifdef DEBUG_PRINT
   printf("FinalSubroutineNameList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "FinalSubroutineNameList(<term>)", &FinalSubroutineNameList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_FinalProcedureStmt(ATerm term, pOFP_Traverse FinalProcedureStmt)
{
#ifdef DEBUG_PRINT
   printf("FinalProcedureStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "FinalProcedureStmt(<term>)", &FinalProcedureStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(FinalProcedureStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_BindingAttr(ATerm term, pOFP_Traverse BindingAttr)
{
#ifdef DEBUG_PRINT
   printf("BindingAttr: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "BindingAttr(<term>)", &BindingAttr->term)) {
 }

//....... ofp_uniqueSymbol: "AccessSpec"
   OFP_Traverse AccessSpec;
   if (ATmatch(term, "BindingAttr_AS(<term>)", &AccessSpec.term)) {
      if (ofp_traverse_AccessSpec(AccessSpec.term, &AccessSpec)) {
         // MATCHED AccessSpec
         return ATtrue;
      } else return ATfalse;
   }

   if (ATmatch(term, "BindingAttr_DEFERRED")) {
      // MATCHED BindingAttr_DEFERRED
      return ATtrue;
   }

   if (ATmatch(term, "BindingAttr_NON_OVERRIDABLE")) {
      // MATCHED BindingAttr_NON_OVERRIDABLE
      return ATtrue;
   }

   if (ATmatch(term, "BindingAttr_NOPASS")) {
      // MATCHED BindingAttr_NOPASS
      return ATtrue;
   }

   return ATfalse;
}

ATbool ofp_traverse_TypeBoundGenericStmt(ATerm term, pOFP_Traverse TypeBoundGenericStmt)
{
#ifdef DEBUG_PRINT
   printf("TypeBoundGenericStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "TypeBoundGenericStmt(<term>)", &TypeBoundGenericStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(TypeBoundGenericStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_TypeBoundProcDeclList(ATerm term, pOFP_Traverse TypeBoundProcDeclList)
{
#ifdef DEBUG_PRINT
   printf("TypeBoundProcDeclList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "TypeBoundProcDeclList(<term>)", &TypeBoundProcDeclList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_TypeBoundProcDecl(ATerm term, pOFP_Traverse TypeBoundProcDecl)
{
#ifdef DEBUG_PRINT
   printf("TypeBoundProcDecl: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "TypeBoundProcDecl(<term>)", &TypeBoundProcDecl->term)) {
//....... ofp_uniqueSymbol: "BindingName"
   OFP_Traverse BindingName;
   if (ofp_traverse_BindingName(TypeBoundProcDecl->term, &BindingName)) {
      // MATCHED BindingName
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_BindingNameList(ATerm term, pOFP_Traverse BindingNameList)
{
#ifdef DEBUG_PRINT
   printf("BindingNameList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "BindingNameList(<term>)", &BindingNameList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_BindingAttrList(ATerm term, pOFP_Traverse BindingAttrList)
{
#ifdef DEBUG_PRINT
   printf("BindingAttrList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "BindingAttrList(<term>)", &BindingAttrList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_TypeBoundProcedureStmt(ATerm term, pOFP_Traverse TypeBoundProcedureStmt)
{
#ifdef DEBUG_PRINT
   printf("TypeBoundProcedureStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "TypeBoundProcedureStmt(<term>)", &TypeBoundProcedureStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(TypeBoundProcedureStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "Label"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "Label1"
   OFP_Traverse Label1;
   if (ofp_traverse_Label(TypeBoundProcedureStmt->term, &Label1)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_TypeBoundProcBinding(ATerm term, pOFP_Traverse TypeBoundProcBinding)
{
#ifdef DEBUG_PRINT
   printf("TypeBoundProcBinding: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "TypeBoundProcBinding(<term>)", &TypeBoundProcBinding->term)) {
//....... ofp_uniqueSymbol: "FinalProcedureStmt"
   OFP_Traverse FinalProcedureStmt;
   if (ofp_traverse_FinalProcedureStmt(TypeBoundProcBinding->term, &FinalProcedureStmt)) {
      // MATCHED FinalProcedureStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "TypeBoundGenericStmt"
   OFP_Traverse TypeBoundGenericStmt;
   if (ofp_traverse_TypeBoundGenericStmt(TypeBoundProcBinding->term, &TypeBoundGenericStmt)) {
      // MATCHED TypeBoundGenericStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "TypeBoundProcedureStmt"
   OFP_Traverse TypeBoundProcedureStmt;
   if (ofp_traverse_TypeBoundProcedureStmt(TypeBoundProcBinding->term, &TypeBoundProcedureStmt)) {
      // MATCHED TypeBoundProcedureStmt
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_BindingPrivateStmt(ATerm term, pOFP_Traverse BindingPrivateStmt)
{
#ifdef DEBUG_PRINT
   printf("BindingPrivateStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "BindingPrivateStmt(<term>)", &BindingPrivateStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(BindingPrivateStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_TypeBoundProcedurePart(ATerm term, pOFP_Traverse TypeBoundProcedurePart)
{
#ifdef DEBUG_PRINT
   printf("TypeBoundProcedurePart: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "TypeBoundProcedurePart(<term>)", &TypeBoundProcedurePart->term)) {
//....... ofp_uniqueSymbol: "ContainsStmt"
   OFP_Traverse ContainsStmt;
   if (ofp_traverse_ContainsStmt(TypeBoundProcedurePart->term, &ContainsStmt)) {
      // MATCHED ContainsStmt
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_PrivateComponentsStmt(ATerm term, pOFP_Traverse PrivateComponentsStmt)
{
#ifdef DEBUG_PRINT
   printf("PrivateComponentsStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "PrivateComponentsStmt(<term>)", &PrivateComponentsStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(PrivateComponentsStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_InitialDataTarget(ATerm term, pOFP_Traverse InitialDataTarget)
{
#ifdef DEBUG_PRINT
   printf("InitialDataTarget: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "InitialDataTarget(<term>)", &InitialDataTarget->term)) {
//....... ofp_uniqueSymbol: "Designator"
   OFP_Traverse Designator;
   if (ofp_traverse_Designator(InitialDataTarget->term, &Designator)) {
      // MATCHED Designator
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ComponentInitialization(ATerm term, pOFP_Traverse ComponentInitialization)
{
#ifdef DEBUG_PRINT
   printf("ComponentInitialization: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ComponentInitialization(<term>)", &ComponentInitialization->term)) {
//....... ofp_uniqueSymbol: "InitialDataTarget"
   OFP_Traverse InitialDataTarget;
   if (ofp_traverse_InitialDataTarget(ComponentInitialization->term, &InitialDataTarget)) {
      // MATCHED InitialDataTarget
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "NullInit"
   OFP_Traverse NullInit;
   if (ofp_traverse_NullInit(ComponentInitialization->term, &NullInit)) {
      // MATCHED NullInit
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "Expr"
   OFP_Traverse Expr;
   if (ofp_traverse_Expr(ComponentInitialization->term, &Expr)) {
      // MATCHED Expr
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ProcComponentAttrSpecList(ATerm term, pOFP_Traverse ProcComponentAttrSpecList)
{
#ifdef DEBUG_PRINT
   printf("ProcComponentAttrSpecList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ProcComponentAttrSpecList(<term>)", &ProcComponentAttrSpecList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_ProcComponentAttrSpec(ATerm term, pOFP_Traverse ProcComponentAttrSpec)
{
#ifdef DEBUG_PRINT
   printf("ProcComponentAttrSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ProcComponentAttrSpec(<term>)", &ProcComponentAttrSpec->term)) {
 }

//....... ofp_uniqueSymbol: "AccessSpec"
   OFP_Traverse AccessSpec;
   if (ATmatch(term, "ProcComponentAttrSpec_AS(<term>)", &AccessSpec.term)) {
      if (ofp_traverse_AccessSpec(AccessSpec.term, &AccessSpec)) {
         // MATCHED AccessSpec
         return ATtrue;
      } else return ATfalse;
   }

   if (ATmatch(term, "ProcComponentAttrSpec_NOPASS")) {
      // MATCHED ProcComponentAttrSpec_NOPASS
      return ATtrue;
   }

   if (ATmatch(term, "ProcComponentAttrSpec_PASS")) {
      // MATCHED ProcComponentAttrSpec_PASS
      return ATtrue;
   }

   if (ATmatch(term, "ProcComponentAttrSpec_POINTER")) {
      // MATCHED ProcComponentAttrSpec_POINTER
      return ATtrue;
   }

   return ATfalse;
}

ATbool ofp_traverse_ProcComponentDefStmt(ATerm term, pOFP_Traverse ProcComponentDefStmt)
{
#ifdef DEBUG_PRINT
   printf("ProcComponentDefStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ProcComponentDefStmt(<term>)", &ProcComponentDefStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(ProcComponentDefStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ComponentArraySpec(ATerm term, pOFP_Traverse ComponentArraySpec)
{
#ifdef DEBUG_PRINT
   printf("ComponentArraySpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ComponentArraySpec(<term>)", &ComponentArraySpec->term)) {
//....... ofp_uniqueSymbol: "DeferredShapeSpecList"
   OFP_Traverse DeferredShapeSpecList;
   if (ofp_traverse_DeferredShapeSpecList(ComponentArraySpec->term, &DeferredShapeSpecList)) {
      // MATCHED DeferredShapeSpecList
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "ExplicitShapeSpecList"
   OFP_Traverse ExplicitShapeSpecList;
   if (ofp_traverse_ExplicitShapeSpecList(ComponentArraySpec->term, &ExplicitShapeSpecList)) {
      // MATCHED ExplicitShapeSpecList
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ComponentDeclList(ATerm term, pOFP_Traverse ComponentDeclList)
{
#ifdef DEBUG_PRINT
   printf("ComponentDeclList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ComponentDeclList(<term>)", &ComponentDeclList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_ComponentDecl(ATerm term, pOFP_Traverse ComponentDecl)
{
#ifdef DEBUG_PRINT
   printf("ComponentDecl: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ComponentDecl(<term>)", &ComponentDecl->term)) {
//....... ofp_uniqueSymbol: "ComponentName"
   OFP_Traverse ComponentName;
   if (ofp_traverse_ComponentName(ComponentDecl->term, &ComponentName)) {
      // MATCHED ComponentName
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ComponentAttrSpecList(ATerm term, pOFP_Traverse ComponentAttrSpecList)
{
#ifdef DEBUG_PRINT
   printf("ComponentAttrSpecList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ComponentAttrSpecList(<term>)", &ComponentAttrSpecList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_ComponentAttrSpec(ATerm term, pOFP_Traverse ComponentAttrSpec)
{
#ifdef DEBUG_PRINT
   printf("ComponentAttrSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ComponentAttrSpec(<term>)", &ComponentAttrSpec->term)) {
 }

//....... ofp_uniqueSymbol: "ComponentArraySpec"
   OFP_Traverse ComponentArraySpec;
   if (ATmatch(term, "ComponentAttrSpec_DIMENSION(<term>)", &ComponentArraySpec.term)) {
      if (ofp_traverse_ComponentArraySpec(ComponentArraySpec.term, &ComponentArraySpec)) {
         // MATCHED ComponentArraySpec
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "CoarraySpec"
   OFP_Traverse CoarraySpec;
   if (ATmatch(term, "ComponentAttrSpec_CODIMENSION(<term>)", &CoarraySpec.term)) {
      if (ofp_traverse_CoarraySpec(CoarraySpec.term, &CoarraySpec)) {
         // MATCHED CoarraySpec
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "AccessSpec"
   OFP_Traverse AccessSpec;
   if (ATmatch(term, "ComponentAttrSpec_AS(<term>)", &AccessSpec.term)) {
      if (ofp_traverse_AccessSpec(AccessSpec.term, &AccessSpec)) {
         // MATCHED AccessSpec
         return ATtrue;
      } else return ATfalse;
   }

   if (ATmatch(term, "ComponentAttrSpec_POINTER")) {
      // MATCHED ComponentAttrSpec_POINTER
      return ATtrue;
   }

   if (ATmatch(term, "ComponentAttrSpec_CONTIGUOUS")) {
      // MATCHED ComponentAttrSpec_CONTIGUOUS
      return ATtrue;
   }

   if (ATmatch(term, "ComponentAttrSpec_ALLOCATABLE")) {
      // MATCHED ComponentAttrSpec_ALLOCATABLE
      return ATtrue;
   }

   return ATfalse;
}

ATbool ofp_traverse_DataComponentDefStmt(ATerm term, pOFP_Traverse DataComponentDefStmt)
{
#ifdef DEBUG_PRINT
   printf("DataComponentDefStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DataComponentDefStmt(<term>)", &DataComponentDefStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(DataComponentDefStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ComponentDefStmt(ATerm term, pOFP_Traverse ComponentDefStmt)
{
#ifdef DEBUG_PRINT
   printf("ComponentDefStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ComponentDefStmt(<term>)", &ComponentDefStmt->term)) {
//....... ofp_uniqueSymbol: "ProcComponentDefStmt"
   OFP_Traverse ProcComponentDefStmt;
   if (ofp_traverse_ProcComponentDefStmt(ComponentDefStmt->term, &ProcComponentDefStmt)) {
      // MATCHED ProcComponentDefStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "DataComponentDefStmt"
   OFP_Traverse DataComponentDefStmt;
   if (ofp_traverse_DataComponentDefStmt(ComponentDefStmt->term, &DataComponentDefStmt)) {
      // MATCHED DataComponentDefStmt
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ComponentPart(ATerm term, pOFP_Traverse ComponentPart)
{
#ifdef DEBUG_PRINT
   printf("ComponentPart: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ComponentPart(<term>)", &ComponentPart->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_TypeParamAttrSpec(ATerm term, pOFP_Traverse TypeParamAttrSpec)
{
#ifdef DEBUG_PRINT
   printf("TypeParamAttrSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "TypeParamAttrSpec(<term>)", &TypeParamAttrSpec->term)) {
 }

   if (ATmatch(term, "TypeParamAttrSpec_LEN")) {
      // MATCHED TypeParamAttrSpec_LEN
      return ATtrue;
   }

   if (ATmatch(term, "TypeParamAttrSpec_KIND")) {
      // MATCHED TypeParamAttrSpec_KIND
      return ATtrue;
   }

   return ATfalse;
}

ATbool ofp_traverse_TypeParamDeclList(ATerm term, pOFP_Traverse TypeParamDeclList)
{
#ifdef DEBUG_PRINT
   printf("TypeParamDeclList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "TypeParamDeclList(<term>)", &TypeParamDeclList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_TypeParamDecl(ATerm term, pOFP_Traverse TypeParamDecl)
{
#ifdef DEBUG_PRINT
   printf("TypeParamDecl: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "TypeParamDecl(<term>)", &TypeParamDecl->term)) {
//....... ofp_uniqueSymbol: "TypeParamName"
   OFP_Traverse TypeParamName;
   if (ofp_traverse_TypeParamName(TypeParamDecl->term, &TypeParamName)) {
      // MATCHED TypeParamName
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_TypeParamDefStmt(ATerm term, pOFP_Traverse TypeParamDefStmt)
{
#ifdef DEBUG_PRINT
   printf("TypeParamDefStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "TypeParamDefStmt(<term>)", &TypeParamDefStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(TypeParamDefStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_SequenceStmt(ATerm term, pOFP_Traverse SequenceStmt)
{
#ifdef DEBUG_PRINT
   printf("SequenceStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "SequenceStmt(<term>)", &SequenceStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(SequenceStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_EndTypeStmt(ATerm term, pOFP_Traverse EndTypeStmt)
{
#ifdef DEBUG_PRINT
   printf("EndTypeStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EndTypeStmt(<term>)", &EndTypeStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(EndTypeStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_PrivateOrSequence(ATerm term, pOFP_Traverse PrivateOrSequence)
{
#ifdef DEBUG_PRINT
   printf("PrivateOrSequence: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "PrivateOrSequence(<term>)", &PrivateOrSequence->term)) {
//....... ofp_uniqueSymbol: "SequenceStmt"
   OFP_Traverse SequenceStmt;
   if (ofp_traverse_SequenceStmt(PrivateOrSequence->term, &SequenceStmt)) {
      // MATCHED SequenceStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "PrivateComponentsStmt"
   OFP_Traverse PrivateComponentsStmt;
   if (ofp_traverse_PrivateComponentsStmt(PrivateOrSequence->term, &PrivateComponentsStmt)) {
      // MATCHED PrivateComponentsStmt
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_TypeAttrSpecList(ATerm term, pOFP_Traverse TypeAttrSpecList)
{
#ifdef DEBUG_PRINT
   printf("TypeAttrSpecList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "TypeAttrSpecList(<term>)", &TypeAttrSpecList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_TypeAttrSpec(ATerm term, pOFP_Traverse TypeAttrSpec)
{
#ifdef DEBUG_PRINT
   printf("TypeAttrSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "TypeAttrSpec(<term>)", &TypeAttrSpec->term)) {
 }

//....... ofp_uniqueSymbol: "ParentTypeName"
   OFP_Traverse ParentTypeName;
   if (ATmatch(term, "TypeAttrSpec_EXTENDS(<term>)", &ParentTypeName.term)) {
      if (ofp_traverse_ParentTypeName(ParentTypeName.term, &ParentTypeName)) {
         // MATCHED ParentTypeName
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "AccessSpec"
   OFP_Traverse AccessSpec;
   if (ATmatch(term, "TypeAttrSpec_AS(<term>)", &AccessSpec.term)) {
      if (ofp_traverse_AccessSpec(AccessSpec.term, &AccessSpec)) {
         // MATCHED AccessSpec
         return ATtrue;
      } else return ATfalse;
   }

   if (ATmatch(term, "TypeAttrSpec_BIND")) {
      // MATCHED TypeAttrSpec_BIND
      return ATtrue;
   }

   if (ATmatch(term, "TypeAttrSpec_ABSTRACT")) {
      // MATCHED TypeAttrSpec_ABSTRACT
      return ATtrue;
   }

   return ATfalse;
}

ATbool ofp_traverse_TypeParamNameList(ATerm term, pOFP_Traverse TypeParamNameList)
{
#ifdef DEBUG_PRINT
   printf("TypeParamNameList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "TypeParamNameList(<term>)", &TypeParamNameList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_DerivedTypeStmt(ATerm term, pOFP_Traverse DerivedTypeStmt)
{
#ifdef DEBUG_PRINT
   printf("DerivedTypeStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DerivedTypeStmt(<term>)", &DerivedTypeStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(DerivedTypeStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_DerivedTypeDef(ATerm term, pOFP_Traverse DerivedTypeDef)
{
#ifdef DEBUG_PRINT
   printf("DerivedTypeDef: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DerivedTypeDef(<term>)", &DerivedTypeDef->term)) {
//....... ofp_uniqueSymbol: "DerivedTypeStmt"
   OFP_Traverse DerivedTypeStmt;
   if (ofp_traverse_DerivedTypeStmt(DerivedTypeDef->term, &DerivedTypeStmt)) {
      // MATCHED DerivedTypeStmt
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_LogicalLiteralConstant(ATerm term, pOFP_Traverse LogicalLiteralConstant)
{
#ifdef DEBUG_PRINT
   printf("LogicalLiteralConstant: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "LogicalLiteralConstant(<term>)", &LogicalLiteralConstant->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_CharLiteralConstant(ATerm term, pOFP_Traverse CharLiteralConstant)
{
#ifdef DEBUG_PRINT
   printf("CharLiteralConstant: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "CharLiteralConstant(<term>)", &CharLiteralConstant->term)) {
//....... ofp_uniqueSymbol: "KindParam1"
   OFP_Traverse KindParam1;
   if (ofp_traverse_KindParam1(CharLiteralConstant->term, &KindParam1)) {
      // MATCHED KindParam1
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_CharLength(ATerm term, pOFP_Traverse CharLength)
{
#ifdef DEBUG_PRINT
   printf("CharLength: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "CharLength(<term>)", &CharLength->term)) {
//....... ofp_uniqueSymbol: "Icon"
   OFP_Traverse Icon;
   if (ofp_traverse_Icon(CharLength->term, &Icon)) {
      // MATCHED Icon
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "TypeParamValue"
   OFP_Traverse TypeParamValue;
   if (ofp_traverse_TypeParamValue(CharLength->term, &TypeParamValue)) {
      // MATCHED TypeParamValue
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_LengthSelector(ATerm term, pOFP_Traverse LengthSelector)
{
#ifdef DEBUG_PRINT
   printf("LengthSelector: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "LengthSelector(<term>)", &LengthSelector->term)) {
 }

//....... ofp_uniqueSymbol: "CharLength"
   OFP_Traverse CharLength;
   if (ATmatch(term, "LengthSelector_STAR(<term>)", &CharLength.term)) {
      if (ofp_traverse_CharLength(CharLength.term, &CharLength)) {
         // MATCHED CharLength
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "TypeParamValue"
   OFP_Traverse TypeParamValue;
   if (ATmatch(term, "LengthSelector_LEN(<term>)", &TypeParamValue.term)) {
      if (ofp_traverse_TypeParamValue(TypeParamValue.term, &TypeParamValue)) {
         // MATCHED TypeParamValue
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_CharSelector(ATerm term, pOFP_Traverse CharSelector)
{
#ifdef DEBUG_PRINT
   printf("CharSelector: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "CharSelector(<term>)", &CharSelector->term)) {
 }

//....... ofp_uniqueSymbol: "Expr"
   OFP_Traverse Expr;
   if (ATmatch(term, "CharSelector_KIND(<term>)", &Expr.term)) {
      if (ofp_traverse_Expr(Expr.term, &Expr)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "Expr1"
   OFP_Traverse Expr1;
   if (ATmatch(term, "CharSelector_KIND_LEN(<term>)", &Expr1.term)) {
      if (ofp_traverse_Expr(Expr1.term, &Expr1)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "TypeParamValue"
   OFP_Traverse TypeParamValue;
   if (ATmatch(term, "CharSelector_KIND_LEN(<term>)", &TypeParamValue.term)) {
      if (ofp_traverse_TypeParamValue(TypeParamValue.term, &TypeParamValue)) {
         // MATCHED TypeParamValue
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "TypeParamValue"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "TypeParamValue1"
   OFP_Traverse TypeParamValue1;
   if (ATmatch(term, "CharSelector_LEN_KIND(<term>)", &TypeParamValue1.term)) {
      if (ofp_traverse_TypeParamValue(TypeParamValue1.term, &TypeParamValue1)) {
         // MATCHED TypeParamValue
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 1
//.......               id: 2
//.......       unique sym: "Expr2"
   OFP_Traverse Expr2;
   if (ATmatch(term, "CharSelector_LEN_KIND(<term>)", &Expr2.term)) {
      if (ofp_traverse_Expr(Expr2.term, &Expr2)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "LengthSelector"
   OFP_Traverse LengthSelector;
   if (ATmatch(term, "CharSelector_LS(<term>)", &LengthSelector.term)) {
      if (ofp_traverse_LengthSelector(LengthSelector.term, &LengthSelector)) {
         // MATCHED LengthSelector
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_ImagPart(ATerm term, pOFP_Traverse ImagPart)
{
#ifdef DEBUG_PRINT
   printf("ImagPart: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ImagPart(<term>)", &ImagPart->term)) {
//....... ofp_uniqueSymbol: "NamedConstant"
   OFP_Traverse NamedConstant;
   if (ofp_traverse_NamedConstant(ImagPart->term, &NamedConstant)) {
      // MATCHED NamedConstant
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "SignedRealLiteralConstant"
   OFP_Traverse SignedRealLiteralConstant;
   if (ofp_traverse_SignedRealLiteralConstant(ImagPart->term, &SignedRealLiteralConstant)) {
      // MATCHED SignedRealLiteralConstant
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "SignedIntLiteralConstant"
   OFP_Traverse SignedIntLiteralConstant;
   if (ofp_traverse_SignedIntLiteralConstant(ImagPart->term, &SignedIntLiteralConstant)) {
      // MATCHED SignedIntLiteralConstant
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_RealPart(ATerm term, pOFP_Traverse RealPart)
{
#ifdef DEBUG_PRINT
   printf("RealPart: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "RealPart(<term>)", &RealPart->term)) {
//....... ofp_uniqueSymbol: "NamedConstant"
   OFP_Traverse NamedConstant;
   if (ofp_traverse_NamedConstant(RealPart->term, &NamedConstant)) {
      // MATCHED NamedConstant
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "SignedRealLiteralConstant"
   OFP_Traverse SignedRealLiteralConstant;
   if (ofp_traverse_SignedRealLiteralConstant(RealPart->term, &SignedRealLiteralConstant)) {
      // MATCHED SignedRealLiteralConstant
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "SignedIntLiteralConstant"
   OFP_Traverse SignedIntLiteralConstant;
   if (ofp_traverse_SignedIntLiteralConstant(RealPart->term, &SignedIntLiteralConstant)) {
      // MATCHED SignedIntLiteralConstant
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ComplexLiteralConstant(ATerm term, pOFP_Traverse ComplexLiteralConstant)
{
#ifdef DEBUG_PRINT
   printf("ComplexLiteralConstant: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ComplexLiteralConstant(<term>)", &ComplexLiteralConstant->term)) {
//....... ofp_uniqueSymbol: "RealPart"
   OFP_Traverse RealPart;
   if (ofp_traverse_RealPart(ComplexLiteralConstant->term, &RealPart)) {
      // MATCHED RealPart
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_RealLiteralConstant(ATerm term, pOFP_Traverse RealLiteralConstant)
{
#ifdef DEBUG_PRINT
   printf("RealLiteralConstant: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "RealLiteralConstant(<term>)", &RealLiteralConstant->term)) {
//....... ofp_uniqueSymbol: "Rcon"
   OFP_Traverse Rcon;
   if (ofp_traverse_Rcon(RealLiteralConstant->term, &Rcon)) {
      // MATCHED Rcon
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_SignedRealLiteralConstant(ATerm term, pOFP_Traverse SignedRealLiteralConstant)
{
#ifdef DEBUG_PRINT
   printf("SignedRealLiteralConstant: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "SignedRealLiteralConstant(<term>)", &SignedRealLiteralConstant->term)) {
//....... ofp_uniqueSymbol: "Sign"
   OFP_Traverse Sign;
   if (ofp_traverse_Sign(SignedRealLiteralConstant->term, &Sign)) {
      // MATCHED Sign
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_Sign(ATerm term, pOFP_Traverse Sign)
{
#ifdef DEBUG_PRINT
   printf("Sign: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "Sign(<term>)", &Sign->term)) {
 }

   if (ATmatch(term, "Sign_MINUS")) {
      // MATCHED Sign_MINUS
      return ATtrue;
   }

   if (ATmatch(term, "Sign_PLUS")) {
      // MATCHED Sign_PLUS
      return ATtrue;
   }

   return ATfalse;
}

ATbool ofp_traverse_DigitString(ATerm term, pOFP_Traverse DigitString)
{
#ifdef DEBUG_PRINT
   printf("DigitString: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DigitString(<term>)", &DigitString->term)) {
//....... ofp_uniqueSymbol: "Icon"
   OFP_Traverse Icon;
   if (ofp_traverse_Icon(DigitString->term, &Icon)) {
      // MATCHED Icon
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_KindParam(ATerm term, pOFP_Traverse KindParam)
{
#ifdef DEBUG_PRINT
   printf("KindParam: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "KindParam(<term>)", &KindParam->term)) {
//....... ofp_uniqueSymbol: "ScalarIntConstantName"
   OFP_Traverse ScalarIntConstantName;
   if (ofp_traverse_ScalarIntConstantName(KindParam->term, &ScalarIntConstantName)) {
      // MATCHED ScalarIntConstantName
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "DigitString"
   OFP_Traverse DigitString;
   if (ofp_traverse_DigitString(KindParam->term, &DigitString)) {
      // MATCHED DigitString
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_IntLiteralConstant(ATerm term, pOFP_Traverse IntLiteralConstant)
{
#ifdef DEBUG_PRINT
   printf("IntLiteralConstant: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "IntLiteralConstant(<term>)", &IntLiteralConstant->term)) {
//....... ofp_uniqueSymbol: "DigitString"
   OFP_Traverse DigitString;
   if (ofp_traverse_DigitString(IntLiteralConstant->term, &DigitString)) {
      // MATCHED DigitString
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_SignedIntLiteralConstant(ATerm term, pOFP_Traverse SignedIntLiteralConstant)
{
#ifdef DEBUG_PRINT
   printf("SignedIntLiteralConstant: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "SignedIntLiteralConstant(<term>)", &SignedIntLiteralConstant->term)) {
//....... ofp_uniqueSymbol: "Sign"
   OFP_Traverse Sign;
   if (ofp_traverse_Sign(SignedIntLiteralConstant->term, &Sign)) {
      // MATCHED Sign
      return ATtrue;
   } 
 }

   return ATfalse;
}
#endif

ATbool ofp_traverse_KindSelector(ATerm term, pOFP_Traverse KindSelector)
{
#ifdef DEBUG_PRINT
   printf("KindSelector: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "KindSelector(<term>)", &KindSelector->term)) {
 }

//....... ofp_uniqueSymbol: "Icon"
   OFP_Traverse Icon;
   if (ATmatch(term, "KindSelector_STAR(<term>)", &Icon.term)) {
      if (ofp_traverse_Icon(Icon.term, &Icon)) {
         // MATCHED Icon
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
   OFP_Traverse Expr;
   if (ATmatch(term, "KindSelector_KIND(<term>)", &Expr.term)) {
      if (ofp_traverse_Expr(Expr.term, &Expr)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

#ifdef NOT_YET
ATbool ofp_traverse_IntrinsicTypeSpec(ATerm term, pOFP_Traverse IntrinsicTypeSpec)
{
#ifdef DEBUG_PRINT
   printf("IntrinsicTypeSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "IntrinsicTypeSpec(<term>)", &IntrinsicTypeSpec->term)) {
 }

   if (ATmatch(term, "IntrinsicTypeSpec_DOUBLE_COMPLEX")) {
      // MATCHED IntrinsicTypeSpec_DOUBLE_COMPLEX
      return ATtrue;
   }

   if (ATmatch(term, "IntrinsicTypeSpec_DOUBLE_PRECISION")) {
      // MATCHED IntrinsicTypeSpec_DOUBLE_PRECISION
      return ATtrue;
   }

   return ATfalse;
}

ATbool ofp_traverse_DeclarationTypeSpec(ATerm term, pOFP_Traverse DeclarationTypeSpec)
{
#ifdef DEBUG_PRINT
   printf("DeclarationTypeSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DeclarationTypeSpec(<term>)", &DeclarationTypeSpec->term)) {
//....... ofp_uniqueSymbol: "IntrinsicTypeSpec"
   OFP_Traverse IntrinsicTypeSpec;
   if (ofp_traverse_IntrinsicTypeSpec(DeclarationTypeSpec->term, &IntrinsicTypeSpec)) {
      // MATCHED IntrinsicTypeSpec
      return ATtrue;
   } 
 }

//....... ofp_uniqueSymbol: "DerivedTypeSpec"
   OFP_Traverse DerivedTypeSpec;
   if (ATmatch(term, "DeclarationTypeSpec_CLASS(<term>)", &DerivedTypeSpec.term)) {
      if (ofp_traverse_DerivedTypeSpec(DerivedTypeSpec.term, &DerivedTypeSpec)) {
         // MATCHED DerivedTypeSpec
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DerivedTypeSpec"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "DerivedTypeSpec1"
   OFP_Traverse DerivedTypeSpec1;
   if (ATmatch(term, "DeclarationTypeSpec_TYPE(<term>)", &DerivedTypeSpec1.term)) {
      if (ofp_traverse_DerivedTypeSpec(DerivedTypeSpec1.term, &DerivedTypeSpec1)) {
         // MATCHED DerivedTypeSpec
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "IntrinsicTypeSpec"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "IntrinsicTypeSpec1"
   OFP_Traverse IntrinsicTypeSpec1;
   if (ATmatch(term, "DeclarationTypeSpec_TYPE(<term>)", &IntrinsicTypeSpec1.term)) {
      if (ofp_traverse_IntrinsicTypeSpec(IntrinsicTypeSpec1.term, &IntrinsicTypeSpec1)) {
         // MATCHED IntrinsicTypeSpec
         return ATtrue;
      } else return ATfalse;
   }

   if (ATmatch(term, "DeclarationTypeSpec_TYPE")) {
      // MATCHED DeclarationTypeSpec_TYPE
      return ATtrue;
   }

   if (ATmatch(term, "DeclarationTypeSpec_CLASS")) {
      // MATCHED DeclarationTypeSpec_CLASS
      return ATtrue;
   }

   return ATfalse;
}

ATbool ofp_traverse_TypeSpec(ATerm term, pOFP_Traverse TypeSpec)
{
#ifdef DEBUG_PRINT
   printf("TypeSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "TypeSpec(<term>)", &TypeSpec->term)) {
//....... ofp_uniqueSymbol: "DerivedTypeSpec"
   OFP_Traverse DerivedTypeSpec;
   if (ofp_traverse_DerivedTypeSpec(TypeSpec->term, &DerivedTypeSpec)) {
      // MATCHED DerivedTypeSpec
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "IntrinsicTypeSpec"
   OFP_Traverse IntrinsicTypeSpec;
   if (ofp_traverse_IntrinsicTypeSpec(TypeSpec->term, &IntrinsicTypeSpec)) {
      // MATCHED IntrinsicTypeSpec
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_TypeParamValue(ATerm term, pOFP_Traverse TypeParamValue)
{
#ifdef DEBUG_PRINT
   printf("TypeParamValue: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "TypeParamValue(<term>)", &TypeParamValue->term)) {
 }

//....... ofp_uniqueSymbol: "Expr"
   OFP_Traverse Expr;
   if (ATmatch(term, "TypeParamValue_Expr(<term>)", &Expr.term)) {
      if (ofp_traverse_Expr(Expr.term, &Expr)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

   if (ATmatch(term, "TypeParamValue_COLON")) {
      // MATCHED TypeParamValue_COLON
      return ATtrue;
   }

   if (ATmatch(term, "TypeParamValue_STAR")) {
      // MATCHED TypeParamValue_STAR
      return ATtrue;
   }

   return ATfalse;
}

ATbool ofp_traverse_NamedConstant(ATerm term, pOFP_Traverse NamedConstant)
{
#ifdef DEBUG_PRINT
   printf("NamedConstant: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "NamedConstant(<term>)", &NamedConstant->term)) {
//....... ofp_uniqueSymbol: "Name"
   OFP_Traverse Name;
   if (ofp_traverse_Name(NamedConstant->term, &Name)) {
      // MATCHED Name
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_LiteralConstant(ATerm term, pOFP_Traverse LiteralConstant)
{
#ifdef DEBUG_PRINT
   printf("LiteralConstant: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "LiteralConstant(<term>)", &LiteralConstant->term)) {
//....... ofp_uniqueSymbol: "BozLiteralConstant"
   OFP_Traverse BozLiteralConstant;
   if (ofp_traverse_BozLiteralConstant(LiteralConstant->term, &BozLiteralConstant)) {
      // MATCHED BozLiteralConstant
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "CharLiteralConstant"
   OFP_Traverse CharLiteralConstant;
   if (ofp_traverse_CharLiteralConstant(LiteralConstant->term, &CharLiteralConstant)) {
      // MATCHED CharLiteralConstant
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "LogicalLiteralConstant"
   OFP_Traverse LogicalLiteralConstant;
   if (ofp_traverse_LogicalLiteralConstant(LiteralConstant->term, &LogicalLiteralConstant)) {
      // MATCHED LogicalLiteralConstant
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "ComplexLiteralConstant"
   OFP_Traverse ComplexLiteralConstant;
   if (ofp_traverse_ComplexLiteralConstant(LiteralConstant->term, &ComplexLiteralConstant)) {
      // MATCHED ComplexLiteralConstant
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "RealLiteralConstant"
   OFP_Traverse RealLiteralConstant;
   if (ofp_traverse_RealLiteralConstant(LiteralConstant->term, &RealLiteralConstant)) {
      // MATCHED RealLiteralConstant
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "IntLiteralConstant"
   OFP_Traverse IntLiteralConstant;
   if (ofp_traverse_IntLiteralConstant(LiteralConstant->term, &IntLiteralConstant)) {
      // MATCHED IntLiteralConstant
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_Constant(ATerm term, pOFP_Traverse Constant)
{
#ifdef DEBUG_PRINT
   printf("Constant: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "Constant(<term>)", &Constant->term)) {
 }

//....... ofp_uniqueSymbol: "LiteralConstant"
   OFP_Traverse LiteralConstant;
   if (ATmatch(term, "Constant_AMB(<term>)", &LiteralConstant.term)) {
      if (ofp_traverse_LiteralConstant(LiteralConstant.term, &LiteralConstant)) {
         // MATCHED LiteralConstant
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_TypeParamName(ATerm term, pOFP_Traverse TypeParamName)
{
#ifdef DEBUG_PRINT
   printf("TypeParamName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "TypeParamName(<term>)", &TypeParamName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(TypeParamName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_TypeName(ATerm term, pOFP_Traverse TypeName)
{
#ifdef DEBUG_PRINT
   printf("TypeName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "TypeName(<term>)", &TypeName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(TypeName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ScalarIntConstantName(ATerm term, pOFP_Traverse ScalarIntConstantName)
{
#ifdef DEBUG_PRINT
   printf("ScalarIntConstantName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ScalarIntConstantName(<term>)", &ScalarIntConstantName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(ScalarIntConstantName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ProcedureName(ATerm term, pOFP_Traverse ProcedureName)
{
#ifdef DEBUG_PRINT
   printf("ProcedureName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ProcedureName(<term>)", &ProcedureName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(ProcedureName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ParentTypeName(ATerm term, pOFP_Traverse ParentTypeName)
{
#ifdef DEBUG_PRINT
   printf("ParentTypeName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ParentTypeName(<term>)", &ParentTypeName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(ParentTypeName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}
#endif

ATbool ofp_traverse_Name(ATerm term, pOFP_Traverse Name)
{
#ifdef DEBUG_PRINT
   printf("Name: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "Name(<term>)", &Name->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(Name->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

#ifdef NOT_YET
ATbool ofp_traverse_InterfaceName(ATerm term, pOFP_Traverse InterfaceName)
{
#ifdef DEBUG_PRINT
   printf("InterfaceName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "InterfaceName(<term>)", &InterfaceName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(InterfaceName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_FinalSubroutineName(ATerm term, pOFP_Traverse FinalSubroutineName)
{
#ifdef DEBUG_PRINT
   printf("FinalSubroutineName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "FinalSubroutineName(<term>)", &FinalSubroutineName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(FinalSubroutineName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ComponentName(ATerm term, pOFP_Traverse ComponentName)
{
#ifdef DEBUG_PRINT
   printf("ComponentName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ComponentName(<term>)", &ComponentName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(ComponentName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_BindingName(ATerm term, pOFP_Traverse BindingName)
{
#ifdef DEBUG_PRINT
   printf("BindingName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "BindingName(<term>)", &BindingName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(BindingName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ArgName(ATerm term, pOFP_Traverse ArgName)
{
#ifdef DEBUG_PRINT
   printf("ArgName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ArgName(<term>)", &ArgName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(ArgName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_CommonBlockObjectList(ATerm term, pOFP_Traverse CommonBlockObjectList)
{
#ifdef DEBUG_PRINT
   printf("CommonBlockObjectList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "CommonBlockObjectList(<term>)", &CommonBlockObjectList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_CommonBlockObject(ATerm term, pOFP_Traverse CommonBlockObject)
{
#ifdef DEBUG_PRINT
   printf("CommonBlockObject: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "CommonBlockObject(<term>)", &CommonBlockObject->term)) {
//....... ofp_uniqueSymbol: "VariableName"
   OFP_Traverse VariableName;
   if (ofp_traverse_VariableName(CommonBlockObject->term, &VariableName)) {
      // MATCHED VariableName
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_CommonStmt(ATerm term, pOFP_Traverse CommonStmt)
{
#ifdef DEBUG_PRINT
   printf("CommonStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "CommonStmt(<term>)", &CommonStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(CommonStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_EquivalenceObjectList(ATerm term, pOFP_Traverse EquivalenceObjectList)
{
#ifdef DEBUG_PRINT
   printf("EquivalenceObjectList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EquivalenceObjectList(<term>)", &EquivalenceObjectList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_EquivalenceObject(ATerm term, pOFP_Traverse EquivalenceObject)
{
#ifdef DEBUG_PRINT
   printf("EquivalenceObject: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EquivalenceObject(<term>)", &EquivalenceObject->term)) {
//....... ofp_uniqueSymbol: "Variable"
   OFP_Traverse Variable;
   if (ofp_traverse_Variable(EquivalenceObject->term, &Variable)) {
      // MATCHED Variable
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_EquivalenceSetList(ATerm term, pOFP_Traverse EquivalenceSetList)
{
#ifdef DEBUG_PRINT
   printf("EquivalenceSetList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EquivalenceSetList(<term>)", &EquivalenceSetList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_EquivalenceSet(ATerm term, pOFP_Traverse EquivalenceSet)
{
#ifdef DEBUG_PRINT
   printf("EquivalenceSet: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EquivalenceSet(<term>)", &EquivalenceSet->term)) {
//....... ofp_uniqueSymbol: "EquivalenceObject"
   OFP_Traverse EquivalenceObject;
   if (ofp_traverse_EquivalenceObject(EquivalenceSet->term, &EquivalenceObject)) {
      // MATCHED EquivalenceObject
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_EquivalenceStmt(ATerm term, pOFP_Traverse EquivalenceStmt)
{
#ifdef DEBUG_PRINT
   printf("EquivalenceStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EquivalenceStmt(<term>)", &EquivalenceStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(EquivalenceStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_NamelistGroupObjectList(ATerm term, pOFP_Traverse NamelistGroupObjectList)
{
#ifdef DEBUG_PRINT
   printf("NamelistGroupObjectList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "NamelistGroupObjectList(<term>)", &NamelistGroupObjectList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_NamelistGroupObject(ATerm term, pOFP_Traverse NamelistGroupObject)
{
#ifdef DEBUG_PRINT
   printf("NamelistGroupObject: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "NamelistGroupObject(<term>)", &NamelistGroupObject->term)) {
//....... ofp_uniqueSymbol: "VariableName"
   OFP_Traverse VariableName;
   if (ofp_traverse_VariableName(NamelistGroupObject->term, &VariableName)) {
      // MATCHED VariableName
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_NamelistStmt(ATerm term, pOFP_Traverse NamelistStmt)
{
#ifdef DEBUG_PRINT
   printf("NamelistStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "NamelistStmt(<term>)", &NamelistStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(NamelistStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_LetterSpecList(ATerm term, pOFP_Traverse LetterSpecList)
{
#ifdef DEBUG_PRINT
   printf("LetterSpecList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "LetterSpecList(<term>)", &LetterSpecList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_LetterSpec(ATerm term, pOFP_Traverse LetterSpec)
{
#ifdef DEBUG_PRINT
   printf("LetterSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "LetterSpec(<term>)", &LetterSpec->term)) {
//....... ofp_uniqueSymbol: "Letter"
   OFP_Traverse Letter;
   if (ofp_traverse_Letter(LetterSpec->term, &Letter)) {
      // MATCHED Letter
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ImplicitSpecList(ATerm term, pOFP_Traverse ImplicitSpecList)
{
#ifdef DEBUG_PRINT
   printf("ImplicitSpecList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ImplicitSpecList(<term>)", &ImplicitSpecList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_ImplicitSpec(ATerm term, pOFP_Traverse ImplicitSpec)
{
#ifdef DEBUG_PRINT
   printf("ImplicitSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ImplicitSpec(<term>)", &ImplicitSpec->term)) {
//....... ofp_uniqueSymbol: "DeclarationTypeSpec"
   OFP_Traverse DeclarationTypeSpec;
   if (ofp_traverse_DeclarationTypeSpec(ImplicitSpec->term, &DeclarationTypeSpec)) {
      // MATCHED DeclarationTypeSpec
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ImplicitStmt(ATerm term, pOFP_Traverse ImplicitStmt)
{
#ifdef DEBUG_PRINT
   printf("ImplicitStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ImplicitStmt(<term>)", &ImplicitStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(ImplicitStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "Label"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "Label1"
   OFP_Traverse Label1;
   if (ofp_traverse_Label(ImplicitStmt->term, &Label1)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_VolatileStmt(ATerm term, pOFP_Traverse VolatileStmt)
{
#ifdef DEBUG_PRINT
   printf("VolatileStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "VolatileStmt(<term>)", &VolatileStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(VolatileStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ValueStmt(ATerm term, pOFP_Traverse ValueStmt)
{
#ifdef DEBUG_PRINT
   printf("ValueStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ValueStmt(<term>)", &ValueStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(ValueStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_TargetDeclList(ATerm term, pOFP_Traverse TargetDeclList)
{
#ifdef DEBUG_PRINT
   printf("TargetDeclList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "TargetDeclList(<term>)", &TargetDeclList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_TargetDecl(ATerm term, pOFP_Traverse TargetDecl)
{
#ifdef DEBUG_PRINT
   printf("TargetDecl: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "TargetDecl(<term>)", &TargetDecl->term)) {
//....... ofp_uniqueSymbol: "ObjectName"
   OFP_Traverse ObjectName;
   if (ofp_traverse_ObjectName(TargetDecl->term, &ObjectName)) {
      // MATCHED ObjectName
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_TargetStmt(ATerm term, pOFP_Traverse TargetStmt)
{
#ifdef DEBUG_PRINT
   printf("TargetStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "TargetStmt(<term>)", &TargetStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(TargetStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ProcPointerName(ATerm term, pOFP_Traverse ProcPointerName)
{
#ifdef DEBUG_PRINT
   printf("ProcPointerName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ProcPointerName(<term>)", &ProcPointerName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(ProcPointerName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_SavedEntityList(ATerm term, pOFP_Traverse SavedEntityList)
{
#ifdef DEBUG_PRINT
   printf("SavedEntityList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "SavedEntityList(<term>)", &SavedEntityList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_SavedEntity(ATerm term, pOFP_Traverse SavedEntity)
{
#ifdef DEBUG_PRINT
   printf("SavedEntity: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "SavedEntity(<term>)", &SavedEntity->term)) {
//....... ofp_uniqueSymbol: "CommonBlockName"
   OFP_Traverse CommonBlockName;
   if (ofp_traverse_CommonBlockName(SavedEntity->term, &CommonBlockName)) {
      // MATCHED CommonBlockName
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "ObjectName"
   OFP_Traverse ObjectName;
   if (ofp_traverse_ObjectName(SavedEntity->term, &ObjectName)) {
      // MATCHED ObjectName
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_SaveStmt(ATerm term, pOFP_Traverse SaveStmt)
{
#ifdef DEBUG_PRINT
   printf("SaveStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "SaveStmt(<term>)", &SaveStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(SaveStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "Label"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "Label1"
   OFP_Traverse Label1;
   if (ofp_traverse_Label(SaveStmt->term, &Label1)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_EntityNameList(ATerm term, pOFP_Traverse EntityNameList)
{
#ifdef DEBUG_PRINT
   printf("EntityNameList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EntityNameList(<term>)", &EntityNameList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_ProtectedStmt(ATerm term, pOFP_Traverse ProtectedStmt)
{
#ifdef DEBUG_PRINT
   printf("ProtectedStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ProtectedStmt(<term>)", &ProtectedStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(ProtectedStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_PointerDeclList(ATerm term, pOFP_Traverse PointerDeclList)
{
#ifdef DEBUG_PRINT
   printf("PointerDeclList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "PointerDeclList(<term>)", &PointerDeclList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_PointerDecl(ATerm term, pOFP_Traverse PointerDecl)
{
#ifdef DEBUG_PRINT
   printf("PointerDecl: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "PointerDecl(<term>)", &PointerDecl->term)) {
//....... ofp_uniqueSymbol: "ProcEntityName"
   OFP_Traverse ProcEntityName;
   if (ofp_traverse_ProcEntityName(PointerDecl->term, &ProcEntityName)) {
      // MATCHED ProcEntityName
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "ObjectName"
   OFP_Traverse ObjectName;
   if (ofp_traverse_ObjectName(PointerDecl->term, &ObjectName)) {
      // MATCHED ObjectName
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_PointerStmt(ATerm term, pOFP_Traverse PointerStmt)
{
#ifdef DEBUG_PRINT
   printf("PointerStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "PointerStmt(<term>)", &PointerStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(PointerStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_NamedConstantDefList(ATerm term, pOFP_Traverse NamedConstantDefList)
{
#ifdef DEBUG_PRINT
   printf("NamedConstantDefList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "NamedConstantDefList(<term>)", &NamedConstantDefList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_NamedConstantDef(ATerm term, pOFP_Traverse NamedConstantDef)
{
#ifdef DEBUG_PRINT
   printf("NamedConstantDef: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "NamedConstantDef(<term>)", &NamedConstantDef->term)) {
//....... ofp_uniqueSymbol: "NamedConstant"
   OFP_Traverse NamedConstant;
   if (ofp_traverse_NamedConstant(NamedConstantDef->term, &NamedConstant)) {
      // MATCHED NamedConstant
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ParameterStmt(ATerm term, pOFP_Traverse ParameterStmt)
{
#ifdef DEBUG_PRINT
   printf("ParameterStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ParameterStmt(<term>)", &ParameterStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(ParameterStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_OptionalStmt(ATerm term, pOFP_Traverse OptionalStmt)
{
#ifdef DEBUG_PRINT
   printf("OptionalStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "OptionalStmt(<term>)", &OptionalStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(OptionalStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_IntentStmt(ATerm term, pOFP_Traverse IntentStmt)
{
#ifdef DEBUG_PRINT
   printf("IntentStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "IntentStmt(<term>)", &IntentStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(IntentStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_DimensionStmt(ATerm term, pOFP_Traverse DimensionStmt)
{
#ifdef DEBUG_PRINT
   printf("DimensionStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DimensionStmt(<term>)", &DimensionStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(DimensionStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ConstantSubobject(ATerm term, pOFP_Traverse ConstantSubobject)
{
#ifdef DEBUG_PRINT
   printf("ConstantSubobject: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ConstantSubobject(<term>)", &ConstantSubobject->term)) {
//....... ofp_uniqueSymbol: "Designator"
   OFP_Traverse Designator;
   if (ofp_traverse_Designator(ConstantSubobject->term, &Designator)) {
      // MATCHED Designator
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_IntConstantSubobject(ATerm term, pOFP_Traverse IntConstantSubobject)
{
#ifdef DEBUG_PRINT
   printf("IntConstantSubobject: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "IntConstantSubobject(<term>)", &IntConstantSubobject->term)) {
//....... ofp_uniqueSymbol: "ConstantSubobject"
   OFP_Traverse ConstantSubobject;
   if (ofp_traverse_ConstantSubobject(IntConstantSubobject->term, &ConstantSubobject)) {
      // MATCHED ConstantSubobject
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_DataStmtConstant(ATerm term, pOFP_Traverse DataStmtConstant)
{
#ifdef DEBUG_PRINT
   printf("DataStmtConstant: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DataStmtConstant(<term>)", &DataStmtConstant->term)) {
//....... ofp_uniqueSymbol: "StructureConstructor"
   OFP_Traverse StructureConstructor;
   if (ofp_traverse_StructureConstructor(DataStmtConstant->term, &StructureConstructor)) {
      // MATCHED StructureConstructor
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "InitialDataTarget"
   OFP_Traverse InitialDataTarget;
   if (ofp_traverse_InitialDataTarget(DataStmtConstant->term, &InitialDataTarget)) {
      // MATCHED InitialDataTarget
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "NullInit"
   OFP_Traverse NullInit;
   if (ofp_traverse_NullInit(DataStmtConstant->term, &NullInit)) {
      // MATCHED NullInit
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "SignedRealLiteralConstant"
   OFP_Traverse SignedRealLiteralConstant;
   if (ofp_traverse_SignedRealLiteralConstant(DataStmtConstant->term, &SignedRealLiteralConstant)) {
      // MATCHED SignedRealLiteralConstant
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "SignedIntLiteralConstant"
   OFP_Traverse SignedIntLiteralConstant;
   if (ofp_traverse_SignedIntLiteralConstant(DataStmtConstant->term, &SignedIntLiteralConstant)) {
      // MATCHED SignedIntLiteralConstant
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "ConstantSubobject"
   OFP_Traverse ConstantSubobject;
   if (ofp_traverse_ConstantSubobject(DataStmtConstant->term, &ConstantSubobject)) {
      // MATCHED ConstantSubobject
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "Constant"
   OFP_Traverse Constant;
   if (ofp_traverse_Constant(DataStmtConstant->term, &Constant)) {
      // MATCHED Constant
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_DataStmtRepeat(ATerm term, pOFP_Traverse DataStmtRepeat)
{
#ifdef DEBUG_PRINT
   printf("DataStmtRepeat: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DataStmtRepeat(<term>)", &DataStmtRepeat->term)) {
//....... ofp_uniqueSymbol: "IntConstantSubobject"
   OFP_Traverse IntConstantSubobject;
   if (ofp_traverse_IntConstantSubobject(DataStmtRepeat->term, &IntConstantSubobject)) {
      // MATCHED IntConstantSubobject
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "Icon"
   OFP_Traverse Icon;
   if (ofp_traverse_Icon(DataStmtRepeat->term, &Icon)) {
      // MATCHED Icon
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_DataStmtValueList(ATerm term, pOFP_Traverse DataStmtValueList)
{
#ifdef DEBUG_PRINT
   printf("DataStmtValueList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DataStmtValueList(<term>)", &DataStmtValueList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_DataStmtValue(ATerm term, pOFP_Traverse DataStmtValue)
{
#ifdef DEBUG_PRINT
   printf("DataStmtValue: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DataStmtValue(<term>)", &DataStmtValue->term)) {
//....... ofp_uniqueSymbol: "DataStmtRepeat0"
   OFP_Traverse DataStmtRepeat0;
   if (ofp_traverse_DataStmtRepeat0(DataStmtValue->term, &DataStmtRepeat0)) {
      // MATCHED DataStmtRepeat0
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_DataIDoVariable(ATerm term, pOFP_Traverse DataIDoVariable)
{
#ifdef DEBUG_PRINT
   printf("DataIDoVariable: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DataIDoVariable(<term>)", &DataIDoVariable->term)) {
//....... ofp_uniqueSymbol: "DoVariable"
   OFP_Traverse DoVariable;
   if (ofp_traverse_DoVariable(DataIDoVariable->term, &DoVariable)) {
      // MATCHED DoVariable
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_DataIDoObjectList(ATerm term, pOFP_Traverse DataIDoObjectList)
{
#ifdef DEBUG_PRINT
   printf("DataIDoObjectList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DataIDoObjectList(<term>)", &DataIDoObjectList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_DataIDoObject(ATerm term, pOFP_Traverse DataIDoObject)
{
#ifdef DEBUG_PRINT
   printf("DataIDoObject: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DataIDoObject(<term>)", &DataIDoObject->term)) {
//....... ofp_uniqueSymbol: "DataImpliedDo"
   OFP_Traverse DataImpliedDo;
   if (ofp_traverse_DataImpliedDo(DataIDoObject->term, &DataImpliedDo)) {
      // MATCHED DataImpliedDo
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "StructureComponent"
   OFP_Traverse StructureComponent;
   if (ofp_traverse_StructureComponent(DataIDoObject->term, &StructureComponent)) {
      // MATCHED StructureComponent
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "ArrayElement"
   OFP_Traverse ArrayElement;
   if (ofp_traverse_ArrayElement(DataIDoObject->term, &ArrayElement)) {
      // MATCHED ArrayElement
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_DataImpliedDo(ATerm term, pOFP_Traverse DataImpliedDo)
{
#ifdef DEBUG_PRINT
   printf("DataImpliedDo: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DataImpliedDo(<term>)", &DataImpliedDo->term)) {
//....... ofp_uniqueSymbol: "DataIDoObjectList"
   OFP_Traverse DataIDoObjectList;
   if (ofp_traverse_DataIDoObjectList(DataImpliedDo->term, &DataIDoObjectList)) {
      // MATCHED DataIDoObjectList
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_DataStmtObjectList(ATerm term, pOFP_Traverse DataStmtObjectList)
{
#ifdef DEBUG_PRINT
   printf("DataStmtObjectList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DataStmtObjectList(<term>)", &DataStmtObjectList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_DataStmtObject(ATerm term, pOFP_Traverse DataStmtObject)
{
#ifdef DEBUG_PRINT
   printf("DataStmtObject: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DataStmtObject(<term>)", &DataStmtObject->term)) {
//....... ofp_uniqueSymbol: "DataImpliedDo"
   OFP_Traverse DataImpliedDo;
   if (ofp_traverse_DataImpliedDo(DataStmtObject->term, &DataImpliedDo)) {
      // MATCHED DataImpliedDo
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "Variable"
   OFP_Traverse Variable;
   if (ofp_traverse_Variable(DataStmtObject->term, &Variable)) {
      // MATCHED Variable
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_DataStmtSetList(ATerm term, pOFP_Traverse DataStmtSetList)
{
#ifdef DEBUG_PRINT
   printf("DataStmtSetList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DataStmtSetList(<term>)", &DataStmtSetList->term)) {
//....... ofp_uniqueSymbol: "DataStmtSetList"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "DataStmtSetList1"
   OFP_Traverse DataStmtSetList1;
   if (ofp_traverse_DataStmtSetList(DataStmtSetList->term, &DataStmtSetList1)) {
      // MATCHED DataStmtSetList
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "DataStmtSet"
   OFP_Traverse DataStmtSet;
   if (ofp_traverse_DataStmtSet(DataStmtSetList->term, &DataStmtSet)) {
      // MATCHED DataStmtSet
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_DataStmtSet(ATerm term, pOFP_Traverse DataStmtSet)
{
#ifdef DEBUG_PRINT
   printf("DataStmtSet: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DataStmtSet(<term>)", &DataStmtSet->term)) {
//....... ofp_uniqueSymbol: "DataStmtObjectList"
   OFP_Traverse DataStmtObjectList;
   if (ofp_traverse_DataStmtObjectList(DataStmtSet->term, &DataStmtObjectList)) {
      // MATCHED DataStmtObjectList
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_DataStmt(ATerm term, pOFP_Traverse DataStmt)
{
#ifdef DEBUG_PRINT
   printf("DataStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DataStmt(<term>)", &DataStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(DataStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ObjectNameList(ATerm term, pOFP_Traverse ObjectNameList)
{
#ifdef DEBUG_PRINT
   printf("ObjectNameList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ObjectNameList(<term>)", &ObjectNameList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_ContiguousStmt(ATerm term, pOFP_Traverse ContiguousStmt)
{
#ifdef DEBUG_PRINT
   printf("ContiguousStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ContiguousStmt(<term>)", &ContiguousStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(ContiguousStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_CodimensionDeclList(ATerm term, pOFP_Traverse CodimensionDeclList)
{
#ifdef DEBUG_PRINT
   printf("CodimensionDeclList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "CodimensionDeclList(<term>)", &CodimensionDeclList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_CodimensionDecl(ATerm term, pOFP_Traverse CodimensionDecl)
{
#ifdef DEBUG_PRINT
   printf("CodimensionDecl: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "CodimensionDecl(<term>)", &CodimensionDecl->term)) {
//....... ofp_uniqueSymbol: "CoarrayName"
   OFP_Traverse CoarrayName;
   if (ofp_traverse_CoarrayName(CodimensionDecl->term, &CoarrayName)) {
      // MATCHED CoarrayName
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_CodimensionStmt(ATerm term, pOFP_Traverse CodimensionStmt)
{
#ifdef DEBUG_PRINT
   printf("CodimensionStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "CodimensionStmt(<term>)", &CodimensionStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(CodimensionStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_BindEntityList(ATerm term, pOFP_Traverse BindEntityList)
{
#ifdef DEBUG_PRINT
   printf("BindEntityList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "BindEntityList(<term>)", &BindEntityList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_BindEntity(ATerm term, pOFP_Traverse BindEntity)
{
#ifdef DEBUG_PRINT
   printf("BindEntity: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "BindEntity(<term>)", &BindEntity->term)) {
 }

//....... ofp_uniqueSymbol: "CommonBlockName"
   OFP_Traverse CommonBlockName;
   if (ATmatch(term, "BindEntity_CBN(<term>)", &CommonBlockName.term)) {
      if (ofp_traverse_CommonBlockName(CommonBlockName.term, &CommonBlockName)) {
         // MATCHED CommonBlockName
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "EntityName"
   OFP_Traverse EntityName;
   if (ATmatch(term, "BindEntity_EN(<term>)", &EntityName.term)) {
      if (ofp_traverse_EntityName(EntityName.term, &EntityName)) {
         // MATCHED EntityName
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_BindStmt(ATerm term, pOFP_Traverse BindStmt)
{
#ifdef DEBUG_PRINT
   printf("BindStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "BindStmt(<term>)", &BindStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(BindStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_AsynchronousStmt(ATerm term, pOFP_Traverse AsynchronousStmt)
{
#ifdef DEBUG_PRINT
   printf("AsynchronousStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AsynchronousStmt(<term>)", &AsynchronousStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(AsynchronousStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_AllocatableDeclList(ATerm term, pOFP_Traverse AllocatableDeclList)
{
#ifdef DEBUG_PRINT
   printf("AllocatableDeclList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AllocatableDeclList(<term>)", &AllocatableDeclList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_AllocatableDecl(ATerm term, pOFP_Traverse AllocatableDecl)
{
#ifdef DEBUG_PRINT
   printf("AllocatableDecl: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AllocatableDecl(<term>)", &AllocatableDecl->term)) {
//....... ofp_uniqueSymbol: "ObjectName"
   OFP_Traverse ObjectName;
   if (ofp_traverse_ObjectName(AllocatableDecl->term, &ObjectName)) {
      // MATCHED ObjectName
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_AllocatableStmt(ATerm term, pOFP_Traverse AllocatableStmt)
{
#ifdef DEBUG_PRINT
   printf("AllocatableStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AllocatableStmt(<term>)", &AllocatableStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(AllocatableStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_AccessIdList(ATerm term, pOFP_Traverse AccessIdList)
{
#ifdef DEBUG_PRINT
   printf("AccessIdList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AccessIdList(<term>)", &AccessIdList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_AccessId(ATerm term, pOFP_Traverse AccessId)
{
#ifdef DEBUG_PRINT
   printf("AccessId: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AccessId(<term>)", &AccessId->term)) {
//....... ofp_uniqueSymbol: "GenericSpec"
   OFP_Traverse GenericSpec;
   if (ofp_traverse_GenericSpec(AccessId->term, &GenericSpec)) {
      // MATCHED GenericSpec
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_AccessStmt(ATerm term, pOFP_Traverse AccessStmt)
{
#ifdef DEBUG_PRINT
   printf("AccessStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AccessStmt(<term>)", &AccessStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(AccessStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "Label"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "Label1"
   OFP_Traverse Label1;
   if (ofp_traverse_Label(AccessStmt->term, &Label1)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_IntentSpec(ATerm term, pOFP_Traverse IntentSpec)
{
#ifdef DEBUG_PRINT
   printf("IntentSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "IntentSpec(<term>)", &IntentSpec->term)) {
 }

   if (ATmatch(term, "IntentSpec_INOUT")) {
      // MATCHED IntentSpec_INOUT
      return ATtrue;
   }

   if (ATmatch(term, "IntentSpec_OUT")) {
      // MATCHED IntentSpec_OUT
      return ATtrue;
   }

   if (ATmatch(term, "IntentSpec_IN")) {
      // MATCHED IntentSpec_IN
      return ATtrue;
   }

   return ATfalse;
}

ATbool ofp_traverse_ImpliedShapeSpecList(ATerm term, pOFP_Traverse ImpliedShapeSpecList)
{
#ifdef DEBUG_PRINT
   printf("ImpliedShapeSpecList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ImpliedShapeSpecList(<term>)", &ImpliedShapeSpecList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_ImpliedShapeSpec(ATerm term, pOFP_Traverse ImpliedShapeSpec)
{
#ifdef DEBUG_PRINT
   printf("ImpliedShapeSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ImpliedShapeSpec(<term>)", &ImpliedShapeSpec->term)) {
//....... ofp_uniqueSymbol: "LowerBound0"
   OFP_Traverse LowerBound0;
   if (ofp_traverse_LowerBound0(ImpliedShapeSpec->term, &LowerBound0)) {
      // MATCHED LowerBound0
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_AssumedRankSpec(ATerm term, pOFP_Traverse AssumedRankSpec)
{
#ifdef DEBUG_PRINT
   printf("AssumedRankSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AssumedRankSpec(<term>)", &AssumedRankSpec->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_AssumedSizeSpec(ATerm term, pOFP_Traverse AssumedSizeSpec)
{
#ifdef DEBUG_PRINT
   printf("AssumedSizeSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AssumedSizeSpec(<term>)", &AssumedSizeSpec->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_DeferredShapeSpecList(ATerm term, pOFP_Traverse DeferredShapeSpecList)
{
#ifdef DEBUG_PRINT
   printf("DeferredShapeSpecList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DeferredShapeSpecList(<term>)", &DeferredShapeSpecList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_DeferredShapeSpec(ATerm term, pOFP_Traverse DeferredShapeSpec)
{
#ifdef DEBUG_PRINT
   printf("DeferredShapeSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DeferredShapeSpec(<term>)", &DeferredShapeSpec->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_AssumedShapeSpecList(ATerm term, pOFP_Traverse AssumedShapeSpecList)
{
#ifdef DEBUG_PRINT
   printf("AssumedShapeSpecList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AssumedShapeSpecList(<term>)", &AssumedShapeSpecList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_AssumedShapeSpec(ATerm term, pOFP_Traverse AssumedShapeSpec)
{
#ifdef DEBUG_PRINT
   printf("AssumedShapeSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AssumedShapeSpec(<term>)", &AssumedShapeSpec->term)) {
//....... ofp_uniqueSymbol: "LowerBound"
   OFP_Traverse LowerBound;
   if (ofp_traverse_LowerBound(AssumedShapeSpec->term, &LowerBound)) {
      // MATCHED LowerBound
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_UpperBound(ATerm term, pOFP_Traverse UpperBound)
{
#ifdef DEBUG_PRINT
   printf("UpperBound: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "UpperBound(<term>)", &UpperBound->term)) {
//....... ofp_uniqueSymbol: "SpecificationExpr"
   OFP_Traverse SpecificationExpr;
   if (ofp_traverse_SpecificationExpr(UpperBound->term, &SpecificationExpr)) {
      // MATCHED SpecificationExpr
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_LowerBound(ATerm term, pOFP_Traverse LowerBound)
{
#ifdef DEBUG_PRINT
   printf("LowerBound: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "LowerBound(<term>)", &LowerBound->term)) {
//....... ofp_uniqueSymbol: "SpecificationExpr"
   OFP_Traverse SpecificationExpr;
   if (ofp_traverse_SpecificationExpr(LowerBound->term, &SpecificationExpr)) {
      // MATCHED SpecificationExpr
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ExplicitShapeSpecList(ATerm term, pOFP_Traverse ExplicitShapeSpecList)
{
#ifdef DEBUG_PRINT
   printf("ExplicitShapeSpecList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ExplicitShapeSpecList(<term>)", &ExplicitShapeSpecList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_ExplicitShapeSpec(ATerm term, pOFP_Traverse ExplicitShapeSpec)
{
#ifdef DEBUG_PRINT
   printf("ExplicitShapeSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ExplicitShapeSpec(<term>)", &ExplicitShapeSpec->term)) {
//....... ofp_uniqueSymbol: "LowerBound0"
   OFP_Traverse LowerBound0;
   if (ofp_traverse_LowerBound0(ExplicitShapeSpec->term, &LowerBound0)) {
      // MATCHED LowerBound0
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ArraySpec(ATerm term, pOFP_Traverse ArraySpec)
{
#ifdef DEBUG_PRINT
   printf("ArraySpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ArraySpec(<term>)", &ArraySpec->term)) {
//....... ofp_uniqueSymbol: "AssumedRankSpec"
   OFP_Traverse AssumedRankSpec;
   if (ofp_traverse_AssumedRankSpec(ArraySpec->term, &AssumedRankSpec)) {
      // MATCHED AssumedRankSpec
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "ImpliedShapeSpecList"
   OFP_Traverse ImpliedShapeSpecList;
   if (ofp_traverse_ImpliedShapeSpecList(ArraySpec->term, &ImpliedShapeSpecList)) {
      // MATCHED ImpliedShapeSpecList
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "AssumedSizeSpec"
   OFP_Traverse AssumedSizeSpec;
   if (ofp_traverse_AssumedSizeSpec(ArraySpec->term, &AssumedSizeSpec)) {
      // MATCHED AssumedSizeSpec
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "DeferredShapeSpecList"
   OFP_Traverse DeferredShapeSpecList;
   if (ofp_traverse_DeferredShapeSpecList(ArraySpec->term, &DeferredShapeSpecList)) {
      // MATCHED DeferredShapeSpecList
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "AssumedShapeSpecList"
   OFP_Traverse AssumedShapeSpecList;
   if (ofp_traverse_AssumedShapeSpecList(ArraySpec->term, &AssumedShapeSpecList)) {
      // MATCHED AssumedShapeSpecList
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "ExplicitShapeSpecList"
   OFP_Traverse ExplicitShapeSpecList;
   if (ofp_traverse_ExplicitShapeSpecList(ArraySpec->term, &ExplicitShapeSpecList)) {
      // MATCHED ExplicitShapeSpecList
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_UpperCobound(ATerm term, pOFP_Traverse UpperCobound)
{
#ifdef DEBUG_PRINT
   printf("UpperCobound: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "UpperCobound(<term>)", &UpperCobound->term)) {
//....... ofp_uniqueSymbol: "SpecificationExpr"
   OFP_Traverse SpecificationExpr;
   if (ofp_traverse_SpecificationExpr(UpperCobound->term, &SpecificationExpr)) {
      // MATCHED SpecificationExpr
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_LowerCobound(ATerm term, pOFP_Traverse LowerCobound)
{
#ifdef DEBUG_PRINT
   printf("LowerCobound: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "LowerCobound(<term>)", &LowerCobound->term)) {
//....... ofp_uniqueSymbol: "SpecificationExpr"
   OFP_Traverse SpecificationExpr;
   if (ofp_traverse_SpecificationExpr(LowerCobound->term, &SpecificationExpr)) {
      // MATCHED SpecificationExpr
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ExplicitCoshapeSpec(ATerm term, pOFP_Traverse ExplicitCoshapeSpec)
{
#ifdef DEBUG_PRINT
   printf("ExplicitCoshapeSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ExplicitCoshapeSpec(<term>)", &ExplicitCoshapeSpec->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_DeferredCoshapeSpecList(ATerm term, pOFP_Traverse DeferredCoshapeSpecList)
{
#ifdef DEBUG_PRINT
   printf("DeferredCoshapeSpecList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DeferredCoshapeSpecList(<term>)", &DeferredCoshapeSpecList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_DeferredCoshapeSpec(ATerm term, pOFP_Traverse DeferredCoshapeSpec)
{
#ifdef DEBUG_PRINT
   printf("DeferredCoshapeSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DeferredCoshapeSpec(<term>)", &DeferredCoshapeSpec->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_CoarraySpec(ATerm term, pOFP_Traverse CoarraySpec)
{
#ifdef DEBUG_PRINT
   printf("CoarraySpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "CoarraySpec(<term>)", &CoarraySpec->term)) {
//....... ofp_uniqueSymbol: "ExplicitCoshapeSpec"
   OFP_Traverse ExplicitCoshapeSpec;
   if (ofp_traverse_ExplicitCoshapeSpec(CoarraySpec->term, &ExplicitCoshapeSpec)) {
      // MATCHED ExplicitCoshapeSpec
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "DeferredCoshapeSpecList"
   OFP_Traverse DeferredCoshapeSpecList;
   if (ofp_traverse_DeferredCoshapeSpecList(CoarraySpec->term, &DeferredCoshapeSpecList)) {
      // MATCHED DeferredCoshapeSpecList
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_LanguageBindingSpec(ATerm term, pOFP_Traverse LanguageBindingSpec)
{
#ifdef DEBUG_PRINT
   printf("LanguageBindingSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "LanguageBindingSpec(<term>)", &LanguageBindingSpec->term)) {
//....... ofp_uniqueSymbol: "Scon0"
   OFP_Traverse Scon0;
   if (ofp_traverse_Scon0(LanguageBindingSpec->term, &Scon0)) {
      // MATCHED Scon0
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_AccessSpec(ATerm term, pOFP_Traverse AccessSpec)
{
#ifdef DEBUG_PRINT
   printf("AccessSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AccessSpec(<term>)", &AccessSpec->term)) {
 }

   if (ATmatch(term, "AccessSpec_PRIVATE")) {
      // MATCHED AccessSpec_PRIVATE
      return ATtrue;
   }

   if (ATmatch(term, "AccessSpec_PUBLIC")) {
      // MATCHED AccessSpec_PUBLIC
      return ATtrue;
   }

   return ATfalse;
}

ATbool ofp_traverse_NullInit(ATerm term, pOFP_Traverse NullInit)
{
#ifdef DEBUG_PRINT
   printf("NullInit: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "NullInit(<term>)", &NullInit->term)) {
//....... ofp_uniqueSymbol: "FunctionReference"
   OFP_Traverse FunctionReference;
   if (ofp_traverse_FunctionReference(NullInit->term, &FunctionReference)) {
      // MATCHED FunctionReference
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_Initialization(ATerm term, pOFP_Traverse Initialization)
{
#ifdef DEBUG_PRINT
   printf("Initialization: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "Initialization(<term>)", &Initialization->term)) {
//....... ofp_uniqueSymbol: "InitialDataTarget"
   OFP_Traverse InitialDataTarget;
   if (ofp_traverse_InitialDataTarget(Initialization->term, &InitialDataTarget)) {
      // MATCHED InitialDataTarget
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "NullInit"
   OFP_Traverse NullInit;
   if (ofp_traverse_NullInit(Initialization->term, &NullInit)) {
      // MATCHED NullInit
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "ConstantExpr"
   OFP_Traverse ConstantExpr;
   if (ofp_traverse_ConstantExpr(Initialization->term, &ConstantExpr)) {
      // MATCHED ConstantExpr
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_EntityDeclList(ATerm term, pOFP_Traverse EntityDeclList)
{
#ifdef DEBUG_PRINT
   printf("EntityDeclList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EntityDeclList(<term>)", &EntityDeclList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_EntityDecl(ATerm term, pOFP_Traverse EntityDecl)
{
#ifdef DEBUG_PRINT
   printf("EntityDecl: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EntityDecl(<term>)", &EntityDecl->term)) {
//....... ofp_uniqueSymbol: "ObjectName"
   OFP_Traverse ObjectName;
   if (ofp_traverse_ObjectName(EntityDecl->term, &ObjectName)) {
      // MATCHED ObjectName
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_AttrSpecList(ATerm term, pOFP_Traverse AttrSpecList)
{
#ifdef DEBUG_PRINT
   printf("AttrSpecList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AttrSpecList(<term>)", &AttrSpecList->term)) {
 }

   return ATfalse;
}
#endif

ATbool ofp_traverse_AttrSpec(ATerm term, pOFP_Traverse AttrSpec)
{
#ifdef DEBUG_PRINT
   printf("AttrSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AttrSpec(<term>)", &AttrSpec->term)) {
 }

#ifdef NOT_YET
//....... ofp_uniqueSymbol: "LanguageBindingSpec"
   OFP_Traverse LanguageBindingSpec;
   if (ATmatch(term, "AttrSpec_LBS(<term>)", &LanguageBindingSpec.term)) {
      if (ofp_traverse_LanguageBindingSpec(LanguageBindingSpec.term, &LanguageBindingSpec)) {
         // MATCHED LanguageBindingSpec
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "IntentSpec"
   OFP_Traverse IntentSpec;
   if (ATmatch(term, "AttrSpec_INTENT(<term>)", &IntentSpec.term)) {
      if (ofp_traverse_IntentSpec(IntentSpec.term, &IntentSpec)) {
         // MATCHED IntentSpec
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "ArraySpec"
   OFP_Traverse ArraySpec;
   if (ATmatch(term, "AttrSpec_DIMENSION(<term>)", &ArraySpec.term)) {
      if (ofp_traverse_ArraySpec(ArraySpec.term, &ArraySpec)) {
         // MATCHED ArraySpec
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "CoarraySpec"
   OFP_Traverse CoarraySpec;
   if (ATmatch(term, "AttrSpec_CODIMENSION(<term>)", &CoarraySpec.term)) {
      if (ofp_traverse_CoarraySpec(CoarraySpec.term, &CoarraySpec)) {
         // MATCHED CoarraySpec
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "AccessSpec"
   OFP_Traverse AccessSpec;
   if (ATmatch(term, "AttrSpec_AS(<term>)", &AccessSpec.term)) {
      if (ofp_traverse_AccessSpec(AccessSpec.term, &AccessSpec)) {
         // MATCHED AccessSpec
         return ATtrue;
      } else return ATfalse;
   }
#endif

   if (ATmatch(term, "AttrSpec_VOLATILE")) {
      // MATCHED AttrSpec_VOLATILE
      return ATtrue;
   }

   if (ATmatch(term, "AttrSpec_VALUE")) {
      // MATCHED AttrSpec_VALUE
      return ATtrue;
   }

   if (ATmatch(term, "AttrSpec_TARGET")) {
      // MATCHED AttrSpec_TARGET
      return ATtrue;
   }

   if (ATmatch(term, "AttrSpec_SAVE")) {
      // MATCHED AttrSpec_SAVE
      return ATtrue;
   }

   if (ATmatch(term, "AttrSpec_PROTECTED")) {
      // MATCHED AttrSpec_PROTECTED
      return ATtrue;
   }

   if (ATmatch(term, "AttrSpec_POINTER")) {
      // MATCHED AttrSpec_POINTER
      return ATtrue;
   }

   if (ATmatch(term, "AttrSpec_PARAMETER")) {
      // MATCHED AttrSpec_PARAMETER
      return ATtrue;
   }

   if (ATmatch(term, "AttrSpec_OPTIONAL")) {
      // MATCHED AttrSpec_OPTIONAL
      return ATtrue;
   }

   if (ATmatch(term, "AttrSpec_INTRINSIC")) {
      // MATCHED AttrSpec_INTRINSIC
      return ATtrue;
   }

   if (ATmatch(term, "AttrSpec_EXTERNAL")) {
      // MATCHED AttrSpec_EXTERNAL
      return ATtrue;
   }

   if (ATmatch(term, "AttrSpec_CONTIGUOUS")) {
      // MATCHED AttrSpec_CONTIGUOUS
      return ATtrue;
   }

   if (ATmatch(term, "AttrSpec_ASYNCHRONOUS")) {
      // MATCHED AttrSpec_ASYNCHRONOUS
      return ATtrue;
   }

   if (ATmatch(term, "AttrSpec_ALLOCATABLE")) {
      // MATCHED AttrSpec_ALLOCATABLE
      return ATtrue;
   }

   return ATfalse;
}

#ifdef NOT_YET
ATbool ofp_traverse_TypeDeclarationStmt(ATerm term, pOFP_Traverse TypeDeclarationStmt)
{
#ifdef DEBUG_PRINT
   printf("TypeDeclarationStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "TypeDeclarationStmt(<term>)", &TypeDeclarationStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(TypeDeclarationStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ProcEntityName(ATerm term, pOFP_Traverse ProcEntityName)
{
#ifdef DEBUG_PRINT
   printf("ProcEntityName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ProcEntityName(<term>)", &ProcEntityName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(ProcEntityName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}
#endif

ATbool ofp_traverse_ObjectName(ATerm term, pOFP_Traverse ObjectName)
{
#ifdef DEBUG_PRINT
   printf("ObjectName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ObjectName(<term>)", &ObjectName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(ObjectName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

#ifdef NOT_YET
ATbool ofp_traverse_NamelistGroupName(ATerm term, pOFP_Traverse NamelistGroupName)
{
#ifdef DEBUG_PRINT
   printf("NamelistGroupName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "NamelistGroupName(<term>)", &NamelistGroupName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(NamelistGroupName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_EntityName(ATerm term, pOFP_Traverse EntityName)
{
#ifdef DEBUG_PRINT
   printf("EntityName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EntityName(<term>)", &EntityName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(EntityName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_CoarrayName(ATerm term, pOFP_Traverse CoarrayName)
{
#ifdef DEBUG_PRINT
   printf("CoarrayName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "CoarrayName(<term>)", &CoarrayName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(CoarrayName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_CommonBlockName(ATerm term, pOFP_Traverse CommonBlockName)
{
#ifdef DEBUG_PRINT
   printf("CommonBlockName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "CommonBlockName(<term>)", &CommonBlockName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(CommonBlockName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ArrayName(ATerm term, pOFP_Traverse ArrayName)
{
#ifdef DEBUG_PRINT
   printf("ArrayName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ArrayName(<term>)", &ArrayName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(ArrayName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ForallStmt(ATerm term, pOFP_Traverse ForallStmt)
{
#ifdef DEBUG_PRINT
   printf("ForallStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ForallStmt(<term>)", &ForallStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(ForallStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_EndForallStmt(ATerm term, pOFP_Traverse EndForallStmt)
{
#ifdef DEBUG_PRINT
   printf("EndForallStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EndForallStmt(<term>)", &EndForallStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(EndForallStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ForallAssignmentStmt(ATerm term, pOFP_Traverse ForallAssignmentStmt)
{
#ifdef DEBUG_PRINT
   printf("ForallAssignmentStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ForallAssignmentStmt(<term>)", &ForallAssignmentStmt->term)) {
//....... ofp_uniqueSymbol: "PointerAssignmentStmt"
   OFP_Traverse PointerAssignmentStmt;
   if (ofp_traverse_PointerAssignmentStmt(ForallAssignmentStmt->term, &PointerAssignmentStmt)) {
      // MATCHED PointerAssignmentStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "AssignmentStmt"
   OFP_Traverse AssignmentStmt;
   if (ofp_traverse_AssignmentStmt(ForallAssignmentStmt->term, &AssignmentStmt)) {
      // MATCHED AssignmentStmt
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ForallBodyConstruct(ATerm term, pOFP_Traverse ForallBodyConstruct)
{
#ifdef DEBUG_PRINT
   printf("ForallBodyConstruct: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ForallBodyConstruct(<term>)", &ForallBodyConstruct->term)) {
//....... ofp_uniqueSymbol: "ForallStmt"
   OFP_Traverse ForallStmt;
   if (ofp_traverse_ForallStmt(ForallBodyConstruct->term, &ForallStmt)) {
      // MATCHED ForallStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "ForallConstruct"
   OFP_Traverse ForallConstruct;
   if (ofp_traverse_ForallConstruct(ForallBodyConstruct->term, &ForallConstruct)) {
      // MATCHED ForallConstruct
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "WhereConstruct"
   OFP_Traverse WhereConstruct;
   if (ofp_traverse_WhereConstruct(ForallBodyConstruct->term, &WhereConstruct)) {
      // MATCHED WhereConstruct
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "WhereStmt"
   OFP_Traverse WhereStmt;
   if (ofp_traverse_WhereStmt(ForallBodyConstruct->term, &WhereStmt)) {
      // MATCHED WhereStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "ForallAssignmentStmt"
   OFP_Traverse ForallAssignmentStmt;
   if (ofp_traverse_ForallAssignmentStmt(ForallBodyConstruct->term, &ForallAssignmentStmt)) {
      // MATCHED ForallAssignmentStmt
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ForallStep(ATerm term, pOFP_Traverse ForallStep)
{
#ifdef DEBUG_PRINT
   printf("ForallStep: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ForallStep(<term>)", &ForallStep->term)) {
//....... ofp_uniqueSymbol: "IntExpr"
   OFP_Traverse IntExpr;
   if (ofp_traverse_IntExpr(ForallStep->term, &IntExpr)) {
      // MATCHED IntExpr
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ForallLimit(ATerm term, pOFP_Traverse ForallLimit)
{
#ifdef DEBUG_PRINT
   printf("ForallLimit: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ForallLimit(<term>)", &ForallLimit->term)) {
//....... ofp_uniqueSymbol: "IntExpr"
   OFP_Traverse IntExpr;
   if (ofp_traverse_IntExpr(ForallLimit->term, &IntExpr)) {
      // MATCHED IntExpr
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ForallTripletSpecList(ATerm term, pOFP_Traverse ForallTripletSpecList)
{
#ifdef DEBUG_PRINT
   printf("ForallTripletSpecList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ForallTripletSpecList(<term>)", &ForallTripletSpecList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_ForallTripletSpec(ATerm term, pOFP_Traverse ForallTripletSpec)
{
#ifdef DEBUG_PRINT
   printf("ForallTripletSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ForallTripletSpec(<term>)", &ForallTripletSpec->term)) {
//....... ofp_uniqueSymbol: "IndexName"
   OFP_Traverse IndexName;
   if (ofp_traverse_IndexName(ForallTripletSpec->term, &IndexName)) {
      // MATCHED IndexName
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ForallHeader(ATerm term, pOFP_Traverse ForallHeader)
{
#ifdef DEBUG_PRINT
   printf("ForallHeader: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ForallHeader(<term>)", &ForallHeader->term)) {
//....... ofp_uniqueSymbol: "TypeSpec0"
   OFP_Traverse TypeSpec0;
   if (ofp_traverse_TypeSpec0(ForallHeader->term, &TypeSpec0)) {
      // MATCHED TypeSpec0
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ForallConstructStmt(ATerm term, pOFP_Traverse ForallConstructStmt)
{
#ifdef DEBUG_PRINT
   printf("ForallConstructStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ForallConstructStmt(<term>)", &ForallConstructStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(ForallConstructStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ForallConstruct(ATerm term, pOFP_Traverse ForallConstruct)
{
#ifdef DEBUG_PRINT
   printf("ForallConstruct: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ForallConstruct(<term>)", &ForallConstruct->term)) {
//....... ofp_uniqueSymbol: "ForallConstructStmt"
   OFP_Traverse ForallConstructStmt;
   if (ofp_traverse_ForallConstructStmt(ForallConstruct->term, &ForallConstructStmt)) {
      // MATCHED ForallConstructStmt
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_EndWhereStmt(ATerm term, pOFP_Traverse EndWhereStmt)
{
#ifdef DEBUG_PRINT
   printf("EndWhereStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EndWhereStmt(<term>)", &EndWhereStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(EndWhereStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ElsewhereStmt(ATerm term, pOFP_Traverse ElsewhereStmt)
{
#ifdef DEBUG_PRINT
   printf("ElsewhereStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ElsewhereStmt(<term>)", &ElsewhereStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(ElsewhereStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_MaskedElsewhereStmt(ATerm term, pOFP_Traverse MaskedElsewhereStmt)
{
#ifdef DEBUG_PRINT
   printf("MaskedElsewhereStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "MaskedElsewhereStmt(<term>)", &MaskedElsewhereStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(MaskedElsewhereStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_MaskExpr(ATerm term, pOFP_Traverse MaskExpr)
{
#ifdef DEBUG_PRINT
   printf("MaskExpr: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "MaskExpr(<term>)", &MaskExpr->term)) {
//....... ofp_uniqueSymbol: "LogicalExpr"
   OFP_Traverse LogicalExpr;
   if (ofp_traverse_LogicalExpr(MaskExpr->term, &LogicalExpr)) {
      // MATCHED LogicalExpr
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_WhereAssignmentStmt(ATerm term, pOFP_Traverse WhereAssignmentStmt)
{
#ifdef DEBUG_PRINT
   printf("WhereAssignmentStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "WhereAssignmentStmt(<term>)", &WhereAssignmentStmt->term)) {
//....... ofp_uniqueSymbol: "AssignmentStmt"
   OFP_Traverse AssignmentStmt;
   if (ofp_traverse_AssignmentStmt(WhereAssignmentStmt->term, &AssignmentStmt)) {
      // MATCHED AssignmentStmt
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_WhereBodyConstruct(ATerm term, pOFP_Traverse WhereBodyConstruct)
{
#ifdef DEBUG_PRINT
   printf("WhereBodyConstruct: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "WhereBodyConstruct(<term>)", &WhereBodyConstruct->term)) {
//....... ofp_uniqueSymbol: "WhereConstruct"
   OFP_Traverse WhereConstruct;
   if (ofp_traverse_WhereConstruct(WhereBodyConstruct->term, &WhereConstruct)) {
      // MATCHED WhereConstruct
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "WhereStmt"
   OFP_Traverse WhereStmt;
   if (ofp_traverse_WhereStmt(WhereBodyConstruct->term, &WhereStmt)) {
      // MATCHED WhereStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "WhereAssignmentStmt"
   OFP_Traverse WhereAssignmentStmt;
   if (ofp_traverse_WhereAssignmentStmt(WhereBodyConstruct->term, &WhereAssignmentStmt)) {
      // MATCHED WhereAssignmentStmt
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_WhereConstructStmt(ATerm term, pOFP_Traverse WhereConstructStmt)
{
#ifdef DEBUG_PRINT
   printf("WhereConstructStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "WhereConstructStmt(<term>)", &WhereConstructStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(WhereConstructStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_WhereConstruct(ATerm term, pOFP_Traverse WhereConstruct)
{
#ifdef DEBUG_PRINT
   printf("WhereConstruct: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "WhereConstruct(<term>)", &WhereConstruct->term)) {
//....... ofp_uniqueSymbol: "WhereConstructStmt"
   OFP_Traverse WhereConstructStmt;
   if (ofp_traverse_WhereConstructStmt(WhereConstruct->term, &WhereConstructStmt)) {
      // MATCHED WhereConstructStmt
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_WhereStmt(ATerm term, pOFP_Traverse WhereStmt)
{
#ifdef DEBUG_PRINT
   printf("WhereStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "WhereStmt(<term>)", &WhereStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(WhereStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ProcTarget(ATerm term, pOFP_Traverse ProcTarget)
{
#ifdef DEBUG_PRINT
   printf("ProcTarget: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ProcTarget(<term>)", &ProcTarget->term)) {
//....... ofp_uniqueSymbol: "ProcComponentRef"
   OFP_Traverse ProcComponentRef;
   if (ofp_traverse_ProcComponentRef(ProcTarget->term, &ProcComponentRef)) {
      // MATCHED ProcComponentRef
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "ProcedureName"
   OFP_Traverse ProcedureName;
   if (ofp_traverse_ProcedureName(ProcTarget->term, &ProcedureName)) {
      // MATCHED ProcedureName
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "Expr"
   OFP_Traverse Expr;
   if (ofp_traverse_Expr(ProcTarget->term, &Expr)) {
      // MATCHED Expr
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ProcComponentRef(ATerm term, pOFP_Traverse ProcComponentRef)
{
#ifdef DEBUG_PRINT
   printf("ProcComponentRef: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ProcComponentRef(<term>)", &ProcComponentRef->term)) {
//....... ofp_uniqueSymbol: "Variable"
   OFP_Traverse Variable;
   if (ofp_traverse_Variable(ProcComponentRef->term, &Variable)) {
      // MATCHED Variable
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ProcPointerObject(ATerm term, pOFP_Traverse ProcPointerObject)
{
#ifdef DEBUG_PRINT
   printf("ProcPointerObject: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ProcPointerObject(<term>)", &ProcPointerObject->term)) {
//....... ofp_uniqueSymbol: "ProcComponentRef"
   OFP_Traverse ProcComponentRef;
   if (ofp_traverse_ProcComponentRef(ProcPointerObject->term, &ProcComponentRef)) {
      // MATCHED ProcComponentRef
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "ProcPointerName"
   OFP_Traverse ProcPointerName;
   if (ofp_traverse_ProcPointerName(ProcPointerObject->term, &ProcPointerName)) {
      // MATCHED ProcPointerName
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_BoundsRemappingList(ATerm term, pOFP_Traverse BoundsRemappingList)
{
#ifdef DEBUG_PRINT
   printf("BoundsRemappingList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "BoundsRemappingList(<term>)", &BoundsRemappingList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_BoundsRemapping(ATerm term, pOFP_Traverse BoundsRemapping)
{
#ifdef DEBUG_PRINT
   printf("BoundsRemapping: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "BoundsRemapping(<term>)", &BoundsRemapping->term)) {
//....... ofp_uniqueSymbol: "LowerBoundExpr"
   OFP_Traverse LowerBoundExpr;
   if (ofp_traverse_LowerBoundExpr(BoundsRemapping->term, &LowerBoundExpr)) {
      // MATCHED LowerBoundExpr
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_BoundsSpecList(ATerm term, pOFP_Traverse BoundsSpecList)
{
#ifdef DEBUG_PRINT
   printf("BoundsSpecList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "BoundsSpecList(<term>)", &BoundsSpecList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_BoundsSpec(ATerm term, pOFP_Traverse BoundsSpec)
{
#ifdef DEBUG_PRINT
   printf("BoundsSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "BoundsSpec(<term>)", &BoundsSpec->term)) {
//....... ofp_uniqueSymbol: "LowerBoundExpr"
   OFP_Traverse LowerBoundExpr;
   if (ofp_traverse_LowerBoundExpr(BoundsSpec->term, &LowerBoundExpr)) {
      // MATCHED LowerBoundExpr
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_DataPointerObject(ATerm term, pOFP_Traverse DataPointerObject)
{
#ifdef DEBUG_PRINT
   printf("DataPointerObject: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DataPointerObject(<term>)", &DataPointerObject->term)) {
//....... ofp_uniqueSymbol: "Variable"
   OFP_Traverse Variable;
   if (ofp_traverse_Variable(DataPointerObject->term, &Variable)) {
      // MATCHED Variable
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "VariableName"
   OFP_Traverse VariableName;
   if (ofp_traverse_VariableName(DataPointerObject->term, &VariableName)) {
      // MATCHED VariableName
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_PointerAssignmentStmt(ATerm term, pOFP_Traverse PointerAssignmentStmt)
{
#ifdef DEBUG_PRINT
   printf("PointerAssignmentStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "PointerAssignmentStmt(<term>)", &PointerAssignmentStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(PointerAssignmentStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "Label"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "Label1"
   OFP_Traverse Label1;
   if (ofp_traverse_Label(PointerAssignmentStmt->term, &Label1)) {
      // MATCHED Label
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "Label"
//.......       from table: 1
//.......               id: 2
//.......       unique sym: "Label2"
   OFP_Traverse Label2;
   if (ofp_traverse_Label(PointerAssignmentStmt->term, &Label2)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_AssignmentStmt(ATerm term, pOFP_Traverse AssignmentStmt)
{
#ifdef DEBUG_PRINT
   printf("AssignmentStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AssignmentStmt(<term>)", &AssignmentStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(AssignmentStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_IntConstantExpr(ATerm term, pOFP_Traverse IntConstantExpr)
{
#ifdef DEBUG_PRINT
   printf("IntConstantExpr: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "IntConstantExpr(<term>)", &IntConstantExpr->term)) {
//....... ofp_uniqueSymbol: "IntExpr"
   OFP_Traverse IntExpr;
   if (ofp_traverse_IntExpr(IntConstantExpr->term, &IntExpr)) {
      // MATCHED IntExpr
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ConstantExpr(ATerm term, pOFP_Traverse ConstantExpr)
{
#ifdef DEBUG_PRINT
   printf("ConstantExpr: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ConstantExpr(<term>)", &ConstantExpr->term)) {
//....... ofp_uniqueSymbol: "Expr"
   OFP_Traverse Expr;
   if (ofp_traverse_Expr(ConstantExpr->term, &Expr)) {
      // MATCHED Expr
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_SpecificationExpr(ATerm term, pOFP_Traverse SpecificationExpr)
{
#ifdef DEBUG_PRINT
   printf("SpecificationExpr: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "SpecificationExpr(<term>)", &SpecificationExpr->term)) {
//....... ofp_uniqueSymbol: "IntExpr"
   OFP_Traverse IntExpr;
   if (ofp_traverse_IntExpr(SpecificationExpr->term, &IntExpr)) {
      // MATCHED IntExpr
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_IntExpr(ATerm term, pOFP_Traverse IntExpr)
{
#ifdef DEBUG_PRINT
   printf("IntExpr: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "IntExpr(<term>)", &IntExpr->term)) {
//....... ofp_uniqueSymbol: "Expr"
   OFP_Traverse Expr;
   if (ofp_traverse_Expr(IntExpr->term, &Expr)) {
      // MATCHED Expr
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_DefaultCharExpr(ATerm term, pOFP_Traverse DefaultCharExpr)
{
#ifdef DEBUG_PRINT
   printf("DefaultCharExpr: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DefaultCharExpr(<term>)", &DefaultCharExpr->term)) {
//....... ofp_uniqueSymbol: "Expr"
   OFP_Traverse Expr;
   if (ofp_traverse_Expr(DefaultCharExpr->term, &Expr)) {
      // MATCHED Expr
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_LogicalExpr(ATerm term, pOFP_Traverse LogicalExpr)
{
#ifdef DEBUG_PRINT
   printf("LogicalExpr: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "LogicalExpr(<term>)", &LogicalExpr->term)) {
//....... ofp_uniqueSymbol: "Expr"
   OFP_Traverse Expr;
   if (ofp_traverse_Expr(LogicalExpr->term, &Expr)) {
      // MATCHED Expr
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_DefinedBinaryOp(ATerm term, pOFP_Traverse DefinedBinaryOp)
{
#ifdef DEBUG_PRINT
   printf("DefinedBinaryOp: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DefinedBinaryOp(<term>)", &DefinedBinaryOp->term)) {
//....... ofp_uniqueSymbol: "Dop"
   OFP_Traverse Dop;
   if (ofp_traverse_Dop(DefinedBinaryOp->term, &Dop)) {
      // MATCHED Dop
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_Expr(ATerm term, pOFP_Traverse Expr)
{
#ifdef DEBUG_PRINT
   printf("Expr: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "Expr(<term>)", &Expr->term)) {
//....... ofp_uniqueSymbol: "Primary"
   OFP_Traverse Primary;
   if (ofp_traverse_Primary(Expr->term, &Primary)) {
      // MATCHED Primary
      return ATtrue;
   } 
 }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "Expr1"
   OFP_Traverse Expr1;
   if (ATmatch(term, "DefBinExpr(<term>)", &Expr1.term)) {
      if (ofp_traverse_Expr(Expr1.term, &Expr1)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefinedBinaryOp"
   OFP_Traverse DefinedBinaryOp;
   if (ATmatch(term, "DefBinExpr(<term>)", &DefinedBinaryOp.term)) {
      if (ofp_traverse_DefinedBinaryOp(DefinedBinaryOp.term, &DefinedBinaryOp)) {
         // MATCHED DefinedBinaryOp
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 1
//.......               id: 2
//.......       unique sym: "Expr2"
   OFP_Traverse Expr2;
   if (ATmatch(term, "DefBinExpr(<term>)", &Expr2.term)) {
      if (ofp_traverse_Expr(Expr2.term, &Expr2)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 2
//.......               id: 3
//.......       unique sym: "Expr3"
   OFP_Traverse Expr3;
   if (ATmatch(term, "NotEqvExpr(<term>)", &Expr3.term)) {
      if (ofp_traverse_Expr(Expr3.term, &Expr3)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 3
//.......               id: 4
//.......       unique sym: "Expr4"
   OFP_Traverse Expr4;
   if (ATmatch(term, "NotEqvExpr(<term>)", &Expr4.term)) {
      if (ofp_traverse_Expr(Expr4.term, &Expr4)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 4
//.......               id: 5
//.......       unique sym: "Expr5"
   OFP_Traverse Expr5;
   if (ATmatch(term, "EqvExpr(<term>)", &Expr5.term)) {
      if (ofp_traverse_Expr(Expr5.term, &Expr5)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 5
//.......               id: 6
//.......       unique sym: "Expr6"
   OFP_Traverse Expr6;
   if (ATmatch(term, "EqvExpr(<term>)", &Expr6.term)) {
      if (ofp_traverse_Expr(Expr6.term, &Expr6)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 6
//.......               id: 7
//.......       unique sym: "Expr7"
   OFP_Traverse Expr7;
   if (ATmatch(term, "OrExpr(<term>)", &Expr7.term)) {
      if (ofp_traverse_Expr(Expr7.term, &Expr7)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 7
//.......               id: 8
//.......       unique sym: "Expr8"
   OFP_Traverse Expr8;
   if (ATmatch(term, "OrExpr(<term>)", &Expr8.term)) {
      if (ofp_traverse_Expr(Expr8.term, &Expr8)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 8
//.......               id: 9
//.......       unique sym: "Expr9"
   OFP_Traverse Expr9;
   if (ATmatch(term, "AndExpr(<term>)", &Expr9.term)) {
      if (ofp_traverse_Expr(Expr9.term, &Expr9)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 9
//.......               id: 10
//.......       unique sym: "Expr10"
   OFP_Traverse Expr10;
   if (ATmatch(term, "AndExpr(<term>)", &Expr10.term)) {
      if (ofp_traverse_Expr(Expr10.term, &Expr10)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 10
//.......               id: 11
//.......       unique sym: "Expr11"
   OFP_Traverse Expr11;
   if (ATmatch(term, "NotExpr(<term>)", &Expr11.term)) {
      if (ofp_traverse_Expr(Expr11.term, &Expr11)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 11
//.......               id: 12
//.......       unique sym: "Expr12"
   OFP_Traverse Expr12;
   if (ATmatch(term, "GE_Expr(<term>)", &Expr12.term)) {
      if (ofp_traverse_Expr(Expr12.term, &Expr12)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 12
//.......               id: 13
//.......       unique sym: "Expr13"
   OFP_Traverse Expr13;
   if (ATmatch(term, "GE_Expr(<term>)", &Expr13.term)) {
      if (ofp_traverse_Expr(Expr13.term, &Expr13)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 13
//.......               id: 14
//.......       unique sym: "Expr14"
   OFP_Traverse Expr14;
   if (ATmatch(term, "GT_Expr(<term>)", &Expr14.term)) {
      if (ofp_traverse_Expr(Expr14.term, &Expr14)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 14
//.......               id: 15
//.......       unique sym: "Expr15"
   OFP_Traverse Expr15;
   if (ATmatch(term, "GT_Expr(<term>)", &Expr15.term)) {
      if (ofp_traverse_Expr(Expr15.term, &Expr15)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 15
//.......               id: 16
//.......       unique sym: "Expr16"
   OFP_Traverse Expr16;
   if (ATmatch(term, "LE_Expr(<term>)", &Expr16.term)) {
      if (ofp_traverse_Expr(Expr16.term, &Expr16)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 16
//.......               id: 17
//.......       unique sym: "Expr17"
   OFP_Traverse Expr17;
   if (ATmatch(term, "LE_Expr(<term>)", &Expr17.term)) {
      if (ofp_traverse_Expr(Expr17.term, &Expr17)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 17
//.......               id: 18
//.......       unique sym: "Expr18"
   OFP_Traverse Expr18;
   if (ATmatch(term, "LT_Expr(<term>)", &Expr18.term)) {
      if (ofp_traverse_Expr(Expr18.term, &Expr18)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 18
//.......               id: 19
//.......       unique sym: "Expr19"
   OFP_Traverse Expr19;
   if (ATmatch(term, "LT_Expr(<term>)", &Expr19.term)) {
      if (ofp_traverse_Expr(Expr19.term, &Expr19)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 19
//.......               id: 20
//.......       unique sym: "Expr20"
   OFP_Traverse Expr20;
   if (ATmatch(term, "NE_Expr(<term>)", &Expr20.term)) {
      if (ofp_traverse_Expr(Expr20.term, &Expr20)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 20
//.......               id: 21
//.......       unique sym: "Expr21"
   OFP_Traverse Expr21;
   if (ATmatch(term, "NE_Expr(<term>)", &Expr21.term)) {
      if (ofp_traverse_Expr(Expr21.term, &Expr21)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 21
//.......               id: 22
//.......       unique sym: "Expr22"
   OFP_Traverse Expr22;
   if (ATmatch(term, "EQ_Expr(<term>)", &Expr22.term)) {
      if (ofp_traverse_Expr(Expr22.term, &Expr22)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 22
//.......               id: 23
//.......       unique sym: "Expr23"
   OFP_Traverse Expr23;
   if (ATmatch(term, "EQ_Expr(<term>)", &Expr23.term)) {
      if (ofp_traverse_Expr(Expr23.term, &Expr23)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 23
//.......               id: 24
//.......       unique sym: "Expr24"
   OFP_Traverse Expr24;
   if (ATmatch(term, "ConcatExpr(<term>)", &Expr24.term)) {
      if (ofp_traverse_Expr(Expr24.term, &Expr24)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 24
//.......               id: 25
//.......       unique sym: "Expr25"
   OFP_Traverse Expr25;
   if (ATmatch(term, "ConcatExpr(<term>)", &Expr25.term)) {
      if (ofp_traverse_Expr(Expr25.term, &Expr25)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 25
//.......               id: 26
//.......       unique sym: "Expr26"
   OFP_Traverse Expr26;
   if (ATmatch(term, "MinusExpr(<term>)", &Expr26.term)) {
      if (ofp_traverse_Expr(Expr26.term, &Expr26)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 26
//.......               id: 27
//.......       unique sym: "Expr27"
   OFP_Traverse Expr27;
   if (ATmatch(term, "MinusExpr(<term>)", &Expr27.term)) {
      if (ofp_traverse_Expr(Expr27.term, &Expr27)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 27
//.......               id: 28
//.......       unique sym: "Expr28"
   OFP_Traverse Expr28;
   if (ATmatch(term, "PlusExpr(<term>)", &Expr28.term)) {
      if (ofp_traverse_Expr(Expr28.term, &Expr28)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 28
//.......               id: 29
//.......       unique sym: "Expr29"
   OFP_Traverse Expr29;
   if (ATmatch(term, "PlusExpr(<term>)", &Expr29.term)) {
      if (ofp_traverse_Expr(Expr29.term, &Expr29)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 29
//.......               id: 30
//.......       unique sym: "Expr30"
   OFP_Traverse Expr30;
   if (ATmatch(term, "UnaryMinusExpr(<term>)", &Expr30.term)) {
      if (ofp_traverse_Expr(Expr30.term, &Expr30)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 30
//.......               id: 31
//.......       unique sym: "Expr31"
   OFP_Traverse Expr31;
   if (ATmatch(term, "UnaryPlusExpr(<term>)", &Expr31.term)) {
      if (ofp_traverse_Expr(Expr31.term, &Expr31)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 31
//.......               id: 32
//.......       unique sym: "Expr32"
   OFP_Traverse Expr32;
   if (ATmatch(term, "DivExpr(<term>)", &Expr32.term)) {
      if (ofp_traverse_Expr(Expr32.term, &Expr32)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 32
//.......               id: 33
//.......       unique sym: "Expr33"
   OFP_Traverse Expr33;
   if (ATmatch(term, "DivExpr(<term>)", &Expr33.term)) {
      if (ofp_traverse_Expr(Expr33.term, &Expr33)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 33
//.......               id: 34
//.......       unique sym: "Expr34"
   OFP_Traverse Expr34;
   if (ATmatch(term, "MultExpr(<term>)", &Expr34.term)) {
      if (ofp_traverse_Expr(Expr34.term, &Expr34)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 34
//.......               id: 35
//.......       unique sym: "Expr35"
   OFP_Traverse Expr35;
   if (ATmatch(term, "MultExpr(<term>)", &Expr35.term)) {
      if (ofp_traverse_Expr(Expr35.term, &Expr35)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 35
//.......               id: 36
//.......       unique sym: "Expr36"
   OFP_Traverse Expr36;
   if (ATmatch(term, "PowerExpr(<term>)", &Expr36.term)) {
      if (ofp_traverse_Expr(Expr36.term, &Expr36)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 36
//.......               id: 37
//.......       unique sym: "Expr37"
   OFP_Traverse Expr37;
   if (ATmatch(term, "PowerExpr(<term>)", &Expr37.term)) {
      if (ofp_traverse_Expr(Expr37.term, &Expr37)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefinedUnaryOp"
   OFP_Traverse DefinedUnaryOp;
   if (ATmatch(term, "DefUnaryExpr(<term>)", &DefinedUnaryOp.term)) {
      if (ofp_traverse_DefinedUnaryOp(DefinedUnaryOp.term, &DefinedUnaryOp)) {
         // MATCHED DefinedUnaryOp
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 37
//.......               id: 38
//.......       unique sym: "Expr38"
   OFP_Traverse Expr38;
   if (ATmatch(term, "DefUnaryExpr(<term>)", &Expr38.term)) {
      if (ofp_traverse_Expr(Expr38.term, &Expr38)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_EquivOp(ATerm term, pOFP_Traverse EquivOp)
{
#ifdef DEBUG_PRINT
   printf("EquivOp: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EquivOp(<term>)", &EquivOp->term)) {
 }

   if (ATmatch(term, "EquivOp_NEQV")) {
      // MATCHED EquivOp_NEQV
      return ATtrue;
   }

   if (ATmatch(term, "EquivOp_EQV")) {
      // MATCHED EquivOp_EQV
      return ATtrue;
   }

   return ATfalse;
}

ATbool ofp_traverse_OrOp(ATerm term, pOFP_Traverse OrOp)
{
#ifdef DEBUG_PRINT
   printf("OrOp: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "OrOp(<term>)", &OrOp->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_AndOp(ATerm term, pOFP_Traverse AndOp)
{
#ifdef DEBUG_PRINT
   printf("AndOp: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AndOp(<term>)", &AndOp->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_NotOp(ATerm term, pOFP_Traverse NotOp)
{
#ifdef DEBUG_PRINT
   printf("NotOp: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "NotOp(<term>)", &NotOp->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_RelOp(ATerm term, pOFP_Traverse RelOp)
{
#ifdef DEBUG_PRINT
   printf("RelOp: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "RelOp(<term>)", &RelOp->term)) {
 }

   if (ATmatch(term, "RelOp_GE")) {
      // MATCHED RelOp_GE
      return ATtrue;
   }

   if (ATmatch(term, "RelOp_GT")) {
      // MATCHED RelOp_GT
      return ATtrue;
   }

   if (ATmatch(term, "RelOp_LE")) {
      // MATCHED RelOp_LE
      return ATtrue;
   }

   if (ATmatch(term, "RelOp_LT")) {
      // MATCHED RelOp_LT
      return ATtrue;
   }

   if (ATmatch(term, "RelOp_NE")) {
      // MATCHED RelOp_NE
      return ATtrue;
   }

   if (ATmatch(term, "RelOp_EQ")) {
      // MATCHED RelOp_EQ
      return ATtrue;
   }

   return ATfalse;
}

ATbool ofp_traverse_ConcatOp(ATerm term, pOFP_Traverse ConcatOp)
{
#ifdef DEBUG_PRINT
   printf("ConcatOp: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ConcatOp(<term>)", &ConcatOp->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_AddOp(ATerm term, pOFP_Traverse AddOp)
{
#ifdef DEBUG_PRINT
   printf("AddOp: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AddOp(<term>)", &AddOp->term)) {
 }

   if (ATmatch(term, "AddOp_MINUS")) {
      // MATCHED AddOp_MINUS
      return ATtrue;
   }

   if (ATmatch(term, "AddOp_PLUS")) {
      // MATCHED AddOp_PLUS
      return ATtrue;
   }

   return ATfalse;
}

ATbool ofp_traverse_MultOp(ATerm term, pOFP_Traverse MultOp)
{
#ifdef DEBUG_PRINT
   printf("MultOp: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "MultOp(<term>)", &MultOp->term)) {
 }

   if (ATmatch(term, "MultOp_DIV")) {
      // MATCHED MultOp_DIV
      return ATtrue;
   }

   if (ATmatch(term, "MultOp_TIMES")) {
      // MATCHED MultOp_TIMES
      return ATtrue;
   }

   return ATfalse;
}

ATbool ofp_traverse_PowerOp(ATerm term, pOFP_Traverse PowerOp)
{
#ifdef DEBUG_PRINT
   printf("PowerOp: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "PowerOp(<term>)", &PowerOp->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_DefinedUnaryOp(ATerm term, pOFP_Traverse DefinedUnaryOp)
{
#ifdef DEBUG_PRINT
   printf("DefinedUnaryOp: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DefinedUnaryOp(<term>)", &DefinedUnaryOp->term)) {
//....... ofp_uniqueSymbol: "Dop"
   OFP_Traverse Dop;
   if (ofp_traverse_Dop(DefinedUnaryOp->term, &Dop)) {
      // MATCHED Dop
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_Primary(ATerm term, pOFP_Traverse Primary)
{
#ifdef DEBUG_PRINT
   printf("Primary: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "Primary(<term>)", &Primary->term)) {
 }

//....... ofp_uniqueSymbol: "Expr"
   OFP_Traverse Expr;
   if (ATmatch(term, "Primary_AMB(<term>)", &Expr.term)) {
      if (ofp_traverse_Expr(Expr.term, &Expr)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "TypeParamInquiry"
   OFP_Traverse TypeParamInquiry;
   if (ATmatch(term, "Primary_AMB(<term>)", &TypeParamInquiry.term)) {
      if (ofp_traverse_TypeParamInquiry(TypeParamInquiry.term, &TypeParamInquiry)) {
         // MATCHED TypeParamInquiry
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "FunctionReference"
   OFP_Traverse FunctionReference;
   if (ATmatch(term, "Primary_AMB(<term>)", &FunctionReference.term)) {
      if (ofp_traverse_FunctionReference(FunctionReference.term, &FunctionReference)) {
         // MATCHED FunctionReference
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "StructureConstructor"
   OFP_Traverse StructureConstructor;
   if (ATmatch(term, "Primary_AMB(<term>)", &StructureConstructor.term)) {
      if (ofp_traverse_StructureConstructor(StructureConstructor.term, &StructureConstructor)) {
         // MATCHED StructureConstructor
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "ArrayConstructor"
   OFP_Traverse ArrayConstructor;
   if (ATmatch(term, "Primary_AMB(<term>)", &ArrayConstructor.term)) {
      if (ofp_traverse_ArrayConstructor(ArrayConstructor.term, &ArrayConstructor)) {
         // MATCHED ArrayConstructor
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Designator"
   OFP_Traverse Designator;
   if (ATmatch(term, "Primary_AMB(<term>)", &Designator.term)) {
      if (ofp_traverse_Designator(Designator.term, &Designator)) {
         // MATCHED Designator
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Constant"
   OFP_Traverse Constant;
   if (ATmatch(term, "Primary_AMB(<term>)", &Constant.term)) {
      if (ofp_traverse_Constant(Constant.term, &Constant)) {
         // MATCHED Constant
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_ExtendedIntrinsicOp(ATerm term, pOFP_Traverse ExtendedIntrinsicOp)
{
#ifdef DEBUG_PRINT
   printf("ExtendedIntrinsicOp: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ExtendedIntrinsicOp(<term>)", &ExtendedIntrinsicOp->term)) {
//....... ofp_uniqueSymbol: "IntrinsicOperator"
   OFP_Traverse IntrinsicOperator;
   if (ofp_traverse_IntrinsicOperator(ExtendedIntrinsicOp->term, &IntrinsicOperator)) {
      // MATCHED IntrinsicOperator
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_DefinedOperator(ATerm term, pOFP_Traverse DefinedOperator)
{
#ifdef DEBUG_PRINT
   printf("DefinedOperator: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DefinedOperator(<term>)", &DefinedOperator->term)) {
//....... ofp_uniqueSymbol: "ExtendedIntrinsicOp"
   OFP_Traverse ExtendedIntrinsicOp;
   if (ofp_traverse_ExtendedIntrinsicOp(DefinedOperator->term, &ExtendedIntrinsicOp)) {
      // MATCHED ExtendedIntrinsicOp
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "DefinedBinaryOp"
   OFP_Traverse DefinedBinaryOp;
   if (ofp_traverse_DefinedBinaryOp(DefinedOperator->term, &DefinedBinaryOp)) {
      // MATCHED DefinedBinaryOp
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "DefinedUnaryOp"
   OFP_Traverse DefinedUnaryOp;
   if (ofp_traverse_DefinedUnaryOp(DefinedOperator->term, &DefinedUnaryOp)) {
      // MATCHED DefinedUnaryOp
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_IntrinsicOperator(ATerm term, pOFP_Traverse IntrinsicOperator)
{
#ifdef DEBUG_PRINT
   printf("IntrinsicOperator: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "IntrinsicOperator(<term>)", &IntrinsicOperator->term)) {
//....... ofp_uniqueSymbol: "EquivOp"
   OFP_Traverse EquivOp;
   if (ofp_traverse_EquivOp(IntrinsicOperator->term, &EquivOp)) {
      // MATCHED EquivOp
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "OrOp"
   OFP_Traverse OrOp;
   if (ofp_traverse_OrOp(IntrinsicOperator->term, &OrOp)) {
      // MATCHED OrOp
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "AndOp"
   OFP_Traverse AndOp;
   if (ofp_traverse_AndOp(IntrinsicOperator->term, &AndOp)) {
      // MATCHED AndOp
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "NotOp"
   OFP_Traverse NotOp;
   if (ofp_traverse_NotOp(IntrinsicOperator->term, &NotOp)) {
      // MATCHED NotOp
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "RelOp"
   OFP_Traverse RelOp;
   if (ofp_traverse_RelOp(IntrinsicOperator->term, &RelOp)) {
      // MATCHED RelOp
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "ConcatOp"
   OFP_Traverse ConcatOp;
   if (ofp_traverse_ConcatOp(IntrinsicOperator->term, &ConcatOp)) {
      // MATCHED ConcatOp
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "AddOp"
   OFP_Traverse AddOp;
   if (ofp_traverse_AddOp(IntrinsicOperator->term, &AddOp)) {
      // MATCHED AddOp
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "MultOp"
   OFP_Traverse MultOp;
   if (ofp_traverse_MultOp(IntrinsicOperator->term, &MultOp)) {
      // MATCHED MultOp
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "PowerOp"
   OFP_Traverse PowerOp;
   if (ofp_traverse_PowerOp(IntrinsicOperator->term, &PowerOp)) {
      // MATCHED PowerOp
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ProcedureComponentName(ATerm term, pOFP_Traverse ProcedureComponentName)
{
#ifdef DEBUG_PRINT
   printf("ProcedureComponentName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ProcedureComponentName(<term>)", &ProcedureComponentName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(ProcedureComponentName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_IndexName(ATerm term, pOFP_Traverse IndexName)
{
#ifdef DEBUG_PRINT
   printf("IndexName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "IndexName(<term>)", &IndexName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(IndexName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ForallConstructName(ATerm term, pOFP_Traverse ForallConstructName)
{
#ifdef DEBUG_PRINT
   printf("ForallConstructName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ForallConstructName(<term>)", &ForallConstructName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(ForallConstructName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_DataPointerComponentName(ATerm term, pOFP_Traverse DataPointerComponentName)
{
#ifdef DEBUG_PRINT
   printf("DataPointerComponentName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DataPointerComponentName(<term>)", &DataPointerComponentName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(DataPointerComponentName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_StmtFunctionStmt(ATerm term, pOFP_Traverse StmtFunctionStmt)
{
#ifdef DEBUG_PRINT
   printf("StmtFunctionStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "StmtFunctionStmt(<term>)", &StmtFunctionStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(StmtFunctionStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ContainsStmt(ATerm term, pOFP_Traverse ContainsStmt)
{
#ifdef DEBUG_PRINT
   printf("ContainsStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ContainsStmt(<term>)", &ContainsStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(ContainsStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ReturnStmt(ATerm term, pOFP_Traverse ReturnStmt)
{
#ifdef DEBUG_PRINT
   printf("ReturnStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ReturnStmt(<term>)", &ReturnStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(ReturnStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_EntryStmt(ATerm term, pOFP_Traverse EntryStmt)
{
#ifdef DEBUG_PRINT
   printf("EntryStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EntryStmt(<term>)", &EntryStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(EntryStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_EndMpSubprogramStmt(ATerm term, pOFP_Traverse EndMpSubprogramStmt)
{
#ifdef DEBUG_PRINT
   printf("EndMpSubprogramStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EndMpSubprogramStmt(<term>)", &EndMpSubprogramStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(EndMpSubprogramStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_MpSubprogramStmt(ATerm term, pOFP_Traverse MpSubprogramStmt)
{
#ifdef DEBUG_PRINT
   printf("MpSubprogramStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "MpSubprogramStmt(<term>)", &MpSubprogramStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(MpSubprogramStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_SeparateModuleSubprogram(ATerm term, pOFP_Traverse SeparateModuleSubprogram)
{
#ifdef DEBUG_PRINT
   printf("SeparateModuleSubprogram: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "SeparateModuleSubprogram(<term>)", &SeparateModuleSubprogram->term)) {
//....... ofp_uniqueSymbol: "MpSubprogramStmt"
   OFP_Traverse MpSubprogramStmt;
   if (ofp_traverse_MpSubprogramStmt(SeparateModuleSubprogram->term, &MpSubprogramStmt)) {
      // MATCHED MpSubprogramStmt
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_EndSubroutineStmt(ATerm term, pOFP_Traverse EndSubroutineStmt)
{
#ifdef DEBUG_PRINT
   printf("EndSubroutineStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EndSubroutineStmt(<term>)", &EndSubroutineStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(EndSubroutineStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_DummyArgList(ATerm term, pOFP_Traverse DummyArgList)
{
#ifdef DEBUG_PRINT
   printf("DummyArgList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DummyArgList(<term>)", &DummyArgList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_DummyArg(ATerm term, pOFP_Traverse DummyArg)
{
#ifdef DEBUG_PRINT
   printf("DummyArg: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DummyArg(<term>)", &DummyArg->term)) {
//....... ofp_uniqueSymbol: "DummyArgName"
   OFP_Traverse DummyArgName;
   if (ofp_traverse_DummyArgName(DummyArg->term, &DummyArgName)) {
      // MATCHED DummyArgName
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_SubroutineStmt(ATerm term, pOFP_Traverse SubroutineStmt)
{
#ifdef DEBUG_PRINT
   printf("SubroutineStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "SubroutineStmt(<term>)", &SubroutineStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(SubroutineStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_SubroutineSubprogram(ATerm term, pOFP_Traverse SubroutineSubprogram)
{
#ifdef DEBUG_PRINT
   printf("SubroutineSubprogram: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "SubroutineSubprogram(<term>)", &SubroutineSubprogram->term)) {
//....... ofp_uniqueSymbol: "SubroutineStmt"
   OFP_Traverse SubroutineStmt;
   if (ofp_traverse_SubroutineStmt(SubroutineSubprogram->term, &SubroutineStmt)) {
      // MATCHED SubroutineStmt
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_EndFunctionStmt(ATerm term, pOFP_Traverse EndFunctionStmt)
{
#ifdef DEBUG_PRINT
   printf("EndFunctionStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EndFunctionStmt(<term>)", &EndFunctionStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(EndFunctionStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_Suffix(ATerm term, pOFP_Traverse Suffix)
{
#ifdef DEBUG_PRINT
   printf("Suffix: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "Suffix(<term>)", &Suffix->term)) {
//....... ofp_uniqueSymbol: "ResultName"
   OFP_Traverse ResultName;
   if (ofp_traverse_ResultName(Suffix->term, &ResultName)) {
      // MATCHED ResultName
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "ProcLanguageBindingSpec"
   OFP_Traverse ProcLanguageBindingSpec;
   if (ofp_traverse_ProcLanguageBindingSpec(Suffix->term, &ProcLanguageBindingSpec)) {
      // MATCHED ProcLanguageBindingSpec
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_DummyArgNameList(ATerm term, pOFP_Traverse DummyArgNameList)
{
#ifdef DEBUG_PRINT
   printf("DummyArgNameList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DummyArgNameList(<term>)", &DummyArgNameList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_DummyArgName(ATerm term, pOFP_Traverse DummyArgName)
{
#ifdef DEBUG_PRINT
   printf("DummyArgName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DummyArgName(<term>)", &DummyArgName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(DummyArgName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ProcLanguageBindingSpec(ATerm term, pOFP_Traverse ProcLanguageBindingSpec)
{
#ifdef DEBUG_PRINT
   printf("ProcLanguageBindingSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ProcLanguageBindingSpec(<term>)", &ProcLanguageBindingSpec->term)) {
//....... ofp_uniqueSymbol: "LanguageBindingSpec"
   OFP_Traverse LanguageBindingSpec;
   if (ofp_traverse_LanguageBindingSpec(ProcLanguageBindingSpec->term, &LanguageBindingSpec)) {
      // MATCHED LanguageBindingSpec
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_FunctionStmt(ATerm term, pOFP_Traverse FunctionStmt)
{
#ifdef DEBUG_PRINT
   printf("FunctionStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "FunctionStmt(<term>)", &FunctionStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(FunctionStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_FunctionSubprogram(ATerm term, pOFP_Traverse FunctionSubprogram)
{
#ifdef DEBUG_PRINT
   printf("FunctionSubprogram: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "FunctionSubprogram(<term>)", &FunctionSubprogram->term)) {
//....... ofp_uniqueSymbol: "FunctionStmt"
   OFP_Traverse FunctionStmt;
   if (ofp_traverse_FunctionStmt(FunctionSubprogram->term, &FunctionStmt)) {
      // MATCHED FunctionStmt
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_PrefixSpec(ATerm term, pOFP_Traverse PrefixSpec)
{
#ifdef DEBUG_PRINT
   printf("PrefixSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "PrefixSpec(<term>)", &PrefixSpec->term)) {
//....... ofp_uniqueSymbol: "DeclarationTypeSpec"
   OFP_Traverse DeclarationTypeSpec;
   if (ofp_traverse_DeclarationTypeSpec(PrefixSpec->term, &DeclarationTypeSpec)) {
      // MATCHED DeclarationTypeSpec
      return ATtrue;
   } 
 }

   if (ATmatch(term, "PrefixSpec_RECURSIVE")) {
      // MATCHED PrefixSpec_RECURSIVE
      return ATtrue;
   }

   if (ATmatch(term, "PrefixSpec_PURE")) {
      // MATCHED PrefixSpec_PURE
      return ATtrue;
   }

   if (ATmatch(term, "PrefixSpec_MODULE")) {
      // MATCHED PrefixSpec_MODULE
      return ATtrue;
   }

   if (ATmatch(term, "PrefixSpec_IMPURE")) {
      // MATCHED PrefixSpec_IMPURE
      return ATtrue;
   }

   if (ATmatch(term, "PrefixSpec_ELEMENTAL")) {
      // MATCHED PrefixSpec_ELEMENTAL
      return ATtrue;
   }

   return ATfalse;
}

ATbool ofp_traverse_Prefix(ATerm term, pOFP_Traverse Prefix)
{
#ifdef DEBUG_PRINT
   printf("Prefix: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "Prefix(<term>)", &Prefix->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_AltReturnSpec(ATerm term, pOFP_Traverse AltReturnSpec)
{
#ifdef DEBUG_PRINT
   printf("AltReturnSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AltReturnSpec(<term>)", &AltReturnSpec->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(AltReturnSpec->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ActualArg(ATerm term, pOFP_Traverse ActualArg)
{
#ifdef DEBUG_PRINT
   printf("ActualArg: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ActualArg(<term>)", &ActualArg->term)) {
//....... ofp_uniqueSymbol: "AltReturnSpec"
   OFP_Traverse AltReturnSpec;
   if (ofp_traverse_AltReturnSpec(ActualArg->term, &AltReturnSpec)) {
      // MATCHED AltReturnSpec
      return ATtrue;
   } 
 }

//....... ofp_uniqueSymbol: "Expr"
   OFP_Traverse Expr;
   if (ATmatch(term, "ActualArg_AMB(<term>)", &Expr.term)) {
      if (ofp_traverse_Expr(Expr.term, &Expr)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_ActualArgSpecList(ATerm term, pOFP_Traverse ActualArgSpecList)
{
#ifdef DEBUG_PRINT
   printf("ActualArgSpecList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ActualArgSpecList(<term>)", &ActualArgSpecList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_ActualArgSpec(ATerm term, pOFP_Traverse ActualArgSpec)
{
#ifdef DEBUG_PRINT
   printf("ActualArgSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ActualArgSpec(<term>)", &ActualArgSpec->term)) {
//....... ofp_uniqueSymbol: "Keyword0"
   OFP_Traverse Keyword0;
   if (ofp_traverse_Keyword0(ActualArgSpec->term, &Keyword0)) {
      // MATCHED Keyword0
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ProcedureDesignator(ATerm term, pOFP_Traverse ProcedureDesignator)
{
#ifdef DEBUG_PRINT
   printf("ProcedureDesignator: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ProcedureDesignator(<term>)", &ProcedureDesignator->term)) {
//....... ofp_uniqueSymbol: "ProcedureName"
   OFP_Traverse ProcedureName;
   if (ofp_traverse_ProcedureName(ProcedureDesignator->term, &ProcedureName)) {
      // MATCHED ProcedureName
      return ATtrue;
   } 
 }

//....... ofp_uniqueSymbol: "DataRef"
   OFP_Traverse DataRef;
   if (ATmatch(term, "ProcedureDesignator_AMB(<term>)", &DataRef.term)) {
      if (ofp_traverse_DataRef(DataRef.term, &DataRef)) {
         // MATCHED DataRef
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "BindingName"
   OFP_Traverse BindingName;
   if (ATmatch(term, "ProcedureDesignator_AMB(<term>)", &BindingName.term)) {
      if (ofp_traverse_BindingName(BindingName.term, &BindingName)) {
         // MATCHED BindingName
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_CallStmt(ATerm term, pOFP_Traverse CallStmt)
{
#ifdef DEBUG_PRINT
   printf("CallStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "CallStmt(<term>)", &CallStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(CallStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_FunctionReference(ATerm term, pOFP_Traverse FunctionReference)
{
#ifdef DEBUG_PRINT
   printf("FunctionReference: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "FunctionReference(<term>)", &FunctionReference->term)) {
//....... ofp_uniqueSymbol: "ProcedureDesignator"
   OFP_Traverse ProcedureDesignator;
   if (ofp_traverse_ProcedureDesignator(FunctionReference->term, &ProcedureDesignator)) {
      // MATCHED ProcedureDesignator
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_IntrinsicProcedureNameList(ATerm term, pOFP_Traverse IntrinsicProcedureNameList)
{
#ifdef DEBUG_PRINT
   printf("IntrinsicProcedureNameList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "IntrinsicProcedureNameList(<term>)", &IntrinsicProcedureNameList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_IntrinsicStmt(ATerm term, pOFP_Traverse IntrinsicStmt)
{
#ifdef DEBUG_PRINT
   printf("IntrinsicStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "IntrinsicStmt(<term>)", &IntrinsicStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(IntrinsicStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_InitialProcTarget(ATerm term, pOFP_Traverse InitialProcTarget)
{
#ifdef DEBUG_PRINT
   printf("InitialProcTarget: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "InitialProcTarget(<term>)", &InitialProcTarget->term)) {
//....... ofp_uniqueSymbol: "ProcedureName"
   OFP_Traverse ProcedureName;
   if (ofp_traverse_ProcedureName(InitialProcTarget->term, &ProcedureName)) {
      // MATCHED ProcedureName
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ProcPointerInit(ATerm term, pOFP_Traverse ProcPointerInit)
{
#ifdef DEBUG_PRINT
   printf("ProcPointerInit: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ProcPointerInit(<term>)", &ProcPointerInit->term)) {
//....... ofp_uniqueSymbol: "InitialProcTarget"
   OFP_Traverse InitialProcTarget;
   if (ofp_traverse_InitialProcTarget(ProcPointerInit->term, &InitialProcTarget)) {
      // MATCHED InitialProcTarget
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "NullInit"
   OFP_Traverse NullInit;
   if (ofp_traverse_NullInit(ProcPointerInit->term, &NullInit)) {
      // MATCHED NullInit
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ProcDeclList(ATerm term, pOFP_Traverse ProcDeclList)
{
#ifdef DEBUG_PRINT
   printf("ProcDeclList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ProcDeclList(<term>)", &ProcDeclList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_ProcDecl(ATerm term, pOFP_Traverse ProcDecl)
{
#ifdef DEBUG_PRINT
   printf("ProcDecl: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ProcDecl(<term>)", &ProcDecl->term)) {
//....... ofp_uniqueSymbol: "ProcedureEntityName"
   OFP_Traverse ProcedureEntityName;
   if (ofp_traverse_ProcedureEntityName(ProcDecl->term, &ProcedureEntityName)) {
      // MATCHED ProcedureEntityName
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ProcAttrSpecList(ATerm term, pOFP_Traverse ProcAttrSpecList)
{
#ifdef DEBUG_PRINT
   printf("ProcAttrSpecList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ProcAttrSpecList(<term>)", &ProcAttrSpecList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_ProcAttrSpec(ATerm term, pOFP_Traverse ProcAttrSpec)
{
#ifdef DEBUG_PRINT
   printf("ProcAttrSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ProcAttrSpec(<term>)", &ProcAttrSpec->term)) {
 }

//....... ofp_uniqueSymbol: "IntentSpec"
   OFP_Traverse IntentSpec;
   if (ATmatch(term, "ProcAttrSpec_INTENT(<term>)", &IntentSpec.term)) {
      if (ofp_traverse_IntentSpec(IntentSpec.term, &IntentSpec)) {
         // MATCHED IntentSpec
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "ProcLanguageBindingSpec"
   OFP_Traverse ProcLanguageBindingSpec;
   if (ATmatch(term, "ProcAttrSpec_PBS(<term>)", &ProcLanguageBindingSpec.term)) {
      if (ofp_traverse_ProcLanguageBindingSpec(ProcLanguageBindingSpec.term, &ProcLanguageBindingSpec)) {
         // MATCHED ProcLanguageBindingSpec
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "AccessSpec"
   OFP_Traverse AccessSpec;
   if (ATmatch(term, "ProcAttrSpec_AS(<term>)", &AccessSpec.term)) {
      if (ofp_traverse_AccessSpec(AccessSpec.term, &AccessSpec)) {
         // MATCHED AccessSpec
         return ATtrue;
      } else return ATfalse;
   }

   if (ATmatch(term, "ProcAttrSpec_SAVE")) {
      // MATCHED ProcAttrSpec_SAVE
      return ATtrue;
   }

   if (ATmatch(term, "ProcAttrSpec_POINTER")) {
      // MATCHED ProcAttrSpec_POINTER
      return ATtrue;
   }

   if (ATmatch(term, "ProcAttrSpec_OPTIONAL")) {
      // MATCHED ProcAttrSpec_OPTIONAL
      return ATtrue;
   }

   return ATfalse;
}

ATbool ofp_traverse_ProcInterface(ATerm term, pOFP_Traverse ProcInterface)
{
#ifdef DEBUG_PRINT
   printf("ProcInterface: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ProcInterface(<term>)", &ProcInterface->term)) {
//....... ofp_uniqueSymbol: "DeclarationTypeSpec"
   OFP_Traverse DeclarationTypeSpec;
   if (ofp_traverse_DeclarationTypeSpec(ProcInterface->term, &DeclarationTypeSpec)) {
      // MATCHED DeclarationTypeSpec
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "InterfaceName"
   OFP_Traverse InterfaceName;
   if (ofp_traverse_InterfaceName(ProcInterface->term, &InterfaceName)) {
      // MATCHED InterfaceName
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ProcedureDeclarationStmt(ATerm term, pOFP_Traverse ProcedureDeclarationStmt)
{
#ifdef DEBUG_PRINT
   printf("ProcedureDeclarationStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ProcedureDeclarationStmt(<term>)", &ProcedureDeclarationStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(ProcedureDeclarationStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ExternalNameList(ATerm term, pOFP_Traverse ExternalNameList)
{
#ifdef DEBUG_PRINT
   printf("ExternalNameList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ExternalNameList(<term>)", &ExternalNameList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_ExternalStmt(ATerm term, pOFP_Traverse ExternalStmt)
{
#ifdef DEBUG_PRINT
   printf("ExternalStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ExternalStmt(<term>)", &ExternalStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(ExternalStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ImportNameList(ATerm term, pOFP_Traverse ImportNameList)
{
#ifdef DEBUG_PRINT
   printf("ImportNameList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ImportNameList(<term>)", &ImportNameList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_ImportStmt(ATerm term, pOFP_Traverse ImportStmt)
{
#ifdef DEBUG_PRINT
   printf("ImportStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ImportStmt(<term>)", &ImportStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(ImportStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_DefinedIoGenericSpec(ATerm term, pOFP_Traverse DefinedIoGenericSpec)
{
#ifdef DEBUG_PRINT
   printf("DefinedIoGenericSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DefinedIoGenericSpec(<term>)", &DefinedIoGenericSpec->term)) {
 }

   if (ATmatch(term, "DefinedIoGenericSpec_WU")) {
      // MATCHED DefinedIoGenericSpec_WU
      return ATtrue;
   }

   if (ATmatch(term, "DefinedIoGenericSpec_WF")) {
      // MATCHED DefinedIoGenericSpec_WF
      return ATtrue;
   }

   if (ATmatch(term, "DefinedIoGenericSpec_RU")) {
      // MATCHED DefinedIoGenericSpec_RU
      return ATtrue;
   }

   if (ATmatch(term, "DefinedIoGenericSpec_RF")) {
      // MATCHED DefinedIoGenericSpec_RF
      return ATtrue;
   }

   return ATfalse;
}

ATbool ofp_traverse_GenericSpec(ATerm term, pOFP_Traverse GenericSpec)
{
#ifdef DEBUG_PRINT
   printf("GenericSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "GenericSpec(<term>)", &GenericSpec->term)) {
//....... ofp_uniqueSymbol: "DefinedIoGenericSpec"
   OFP_Traverse DefinedIoGenericSpec;
   if (ofp_traverse_DefinedIoGenericSpec(GenericSpec->term, &DefinedIoGenericSpec)) {
      // MATCHED DefinedIoGenericSpec
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "DefinedOperator"
   OFP_Traverse DefinedOperator;
   if (ofp_traverse_DefinedOperator(GenericSpec->term, &DefinedOperator)) {
      // MATCHED DefinedOperator
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "GenericName"
   OFP_Traverse GenericName;
   if (ofp_traverse_GenericName(GenericSpec->term, &GenericName)) {
      // MATCHED GenericName
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ProcedureNameList(ATerm term, pOFP_Traverse ProcedureNameList)
{
#ifdef DEBUG_PRINT
   printf("ProcedureNameList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ProcedureNameList(<term>)", &ProcedureNameList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_ProcedureStmt(ATerm term, pOFP_Traverse ProcedureStmt)
{
#ifdef DEBUG_PRINT
   printf("ProcedureStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ProcedureStmt(<term>)", &ProcedureStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(ProcedureStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

//....... ofp_uniqueSymbol: "ProcedureNameList"
   OFP_Traverse ProcedureNameList;
   if (ATmatch(term, "ProcedureStmt_MODULE(<term>)", &ProcedureNameList.term)) {
      if (ofp_traverse_ProcedureNameList(ProcedureNameList.term, &ProcedureNameList)) {
         // MATCHED ProcedureNameList
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "EOS"
   OFP_Traverse EOS;
   if (ATmatch(term, "ProcedureStmt_MODULE(<term>)", &EOS.term)) {
      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_InterfaceBody(ATerm term, pOFP_Traverse InterfaceBody)
{
#ifdef DEBUG_PRINT
   printf("InterfaceBody: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "InterfaceBody(<term>)", &InterfaceBody->term)) {
//....... ofp_uniqueSymbol: "SubroutineStmt"
   OFP_Traverse SubroutineStmt;
   if (ofp_traverse_SubroutineStmt(InterfaceBody->term, &SubroutineStmt)) {
      // MATCHED SubroutineStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "FunctionStmt"
   OFP_Traverse FunctionStmt;
   if (ofp_traverse_FunctionStmt(InterfaceBody->term, &FunctionStmt)) {
      // MATCHED FunctionStmt
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_EndInterfaceStmt(ATerm term, pOFP_Traverse EndInterfaceStmt)
{
#ifdef DEBUG_PRINT
   printf("EndInterfaceStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EndInterfaceStmt(<term>)", &EndInterfaceStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(EndInterfaceStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_InterfaceStmt(ATerm term, pOFP_Traverse InterfaceStmt)
{
#ifdef DEBUG_PRINT
   printf("InterfaceStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "InterfaceStmt(<term>)", &InterfaceStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(InterfaceStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "Label"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "Label1"
   OFP_Traverse Label1;
   if (ofp_traverse_Label(InterfaceStmt->term, &Label1)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_InterfaceSpecification(ATerm term, pOFP_Traverse InterfaceSpecification)
{
#ifdef DEBUG_PRINT
   printf("InterfaceSpecification: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "InterfaceSpecification(<term>)", &InterfaceSpecification->term)) {
//....... ofp_uniqueSymbol: "ProcedureStmt"
   OFP_Traverse ProcedureStmt;
   if (ofp_traverse_ProcedureStmt(InterfaceSpecification->term, &ProcedureStmt)) {
      // MATCHED ProcedureStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "InterfaceBody"
   OFP_Traverse InterfaceBody;
   if (ofp_traverse_InterfaceBody(InterfaceSpecification->term, &InterfaceBody)) {
      // MATCHED InterfaceBody
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_InterfaceBlock(ATerm term, pOFP_Traverse InterfaceBlock)
{
#ifdef DEBUG_PRINT
   printf("InterfaceBlock: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "InterfaceBlock(<term>)", &InterfaceBlock->term)) {
//....... ofp_uniqueSymbol: "InterfaceStmt"
   OFP_Traverse InterfaceStmt;
   if (ofp_traverse_InterfaceStmt(InterfaceBlock->term, &InterfaceStmt)) {
      // MATCHED InterfaceStmt
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_SubroutineName(ATerm term, pOFP_Traverse SubroutineName)
{
#ifdef DEBUG_PRINT
   printf("SubroutineName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "SubroutineName(<term>)", &SubroutineName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(SubroutineName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ResultName(ATerm term, pOFP_Traverse ResultName)
{
#ifdef DEBUG_PRINT
   printf("ResultName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ResultName(<term>)", &ResultName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(ResultName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}
#endif

ATbool ofp_traverse_ProgramName(ATerm term, pOFP_Traverse ProgramName)
{
#ifdef DEBUG_PRINT
   printf("ProgramName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ProgramName(<term>)", &ProgramName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(ProgramName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

#ifdef NOT_YET
ATbool ofp_traverse_ProcedureEntityName(ATerm term, pOFP_Traverse ProcedureEntityName)
{
#ifdef DEBUG_PRINT
   printf("ProcedureEntityName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ProcedureEntityName(<term>)", &ProcedureEntityName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(ProcedureEntityName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_IntrinsicProcedureName(ATerm term, pOFP_Traverse IntrinsicProcedureName)
{
#ifdef DEBUG_PRINT
   printf("IntrinsicProcedureName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "IntrinsicProcedureName(<term>)", &IntrinsicProcedureName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(IntrinsicProcedureName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ImportName(ATerm term, pOFP_Traverse ImportName)
{
#ifdef DEBUG_PRINT
   printf("ImportName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ImportName(<term>)", &ImportName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(ImportName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_GenericName(ATerm term, pOFP_Traverse GenericName)
{
#ifdef DEBUG_PRINT
   printf("GenericName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "GenericName(<term>)", &GenericName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(GenericName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_FunctionName(ATerm term, pOFP_Traverse FunctionName)
{
#ifdef DEBUG_PRINT
   printf("FunctionName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "FunctionName(<term>)", &FunctionName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(FunctionName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ExternalName(ATerm term, pOFP_Traverse ExternalName)
{
#ifdef DEBUG_PRINT
   printf("ExternalName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ExternalName(<term>)", &ExternalName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(ExternalName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_EntryName(ATerm term, pOFP_Traverse EntryName)
{
#ifdef DEBUG_PRINT
   printf("EntryName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EntryName(<term>)", &EntryName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(EntryName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_LockVariable(ATerm term, pOFP_Traverse LockVariable)
{
#ifdef DEBUG_PRINT
   printf("LockVariable: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "LockVariable(<term>)", &LockVariable->term)) {
//....... ofp_uniqueSymbol: "Variable"
   OFP_Traverse Variable;
   if (ofp_traverse_Variable(LockVariable->term, &Variable)) {
      // MATCHED Variable
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_UnlockStmt(ATerm term, pOFP_Traverse UnlockStmt)
{
#ifdef DEBUG_PRINT
   printf("UnlockStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "UnlockStmt(<term>)", &UnlockStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(UnlockStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_LockStatList(ATerm term, pOFP_Traverse LockStatList)
{
#ifdef DEBUG_PRINT
   printf("LockStatList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "LockStatList(<term>)", &LockStatList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_LockStat(ATerm term, pOFP_Traverse LockStat)
{
#ifdef DEBUG_PRINT
   printf("LockStat: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "LockStat(<term>)", &LockStat->term)) {
 }

//....... ofp_uniqueSymbol: "SyncStat"
   OFP_Traverse SyncStat;
   if (ATmatch(term, "LockStat_SS(<term>)", &SyncStat.term)) {
      if (ofp_traverse_SyncStat(SyncStat.term, &SyncStat)) {
         // MATCHED SyncStat
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "LogicalVariable"
   OFP_Traverse LogicalVariable;
   if (ATmatch(term, "LockStat_ACQUIRED_LOCK(<term>)", &LogicalVariable.term)) {
      if (ofp_traverse_LogicalVariable(LogicalVariable.term, &LogicalVariable)) {
         // MATCHED LogicalVariable
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_LockStmt(ATerm term, pOFP_Traverse LockStmt)
{
#ifdef DEBUG_PRINT
   printf("LockStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "LockStmt(<term>)", &LockStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(LockStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_SyncMemoryStmt(ATerm term, pOFP_Traverse SyncMemoryStmt)
{
#ifdef DEBUG_PRINT
   printf("SyncMemoryStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "SyncMemoryStmt(<term>)", &SyncMemoryStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(SyncMemoryStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ImageSet(ATerm term, pOFP_Traverse ImageSet)
{
#ifdef DEBUG_PRINT
   printf("ImageSet: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ImageSet(<term>)", &ImageSet->term)) {
 }

//....... ofp_uniqueSymbol: "IntExpr"
   OFP_Traverse IntExpr;
   if (ATmatch(term, "ImageSet_IE(<term>)", &IntExpr.term)) {
      if (ofp_traverse_IntExpr(IntExpr.term, &IntExpr)) {
         // MATCHED IntExpr
         return ATtrue;
      } else return ATfalse;
   }

   if (ATmatch(term, "ImageSet_STAR")) {
      // MATCHED ImageSet_STAR
      return ATtrue;
   }

   return ATfalse;
}

ATbool ofp_traverse_SyncImagesStmt(ATerm term, pOFP_Traverse SyncImagesStmt)
{
#ifdef DEBUG_PRINT
   printf("SyncImagesStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "SyncImagesStmt(<term>)", &SyncImagesStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(SyncImagesStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_SyncStatList(ATerm term, pOFP_Traverse SyncStatList)
{
#ifdef DEBUG_PRINT
   printf("SyncStatList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "SyncStatList(<term>)", &SyncStatList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_SyncStat(ATerm term, pOFP_Traverse SyncStat)
{
#ifdef DEBUG_PRINT
   printf("SyncStat: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "SyncStat(<term>)", &SyncStat->term)) {
 }

//....... ofp_uniqueSymbol: "ErrmsgVariable"
   OFP_Traverse ErrmsgVariable;
   if (ATmatch(term, "SyncStat_ERRMSG(<term>)", &ErrmsgVariable.term)) {
      if (ofp_traverse_ErrmsgVariable(ErrmsgVariable.term, &ErrmsgVariable)) {
         // MATCHED ErrmsgVariable
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "StatVariable"
   OFP_Traverse StatVariable;
   if (ATmatch(term, "SyncStat_STAT(<term>)", &StatVariable.term)) {
      if (ofp_traverse_StatVariable(StatVariable.term, &StatVariable)) {
         // MATCHED StatVariable
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_SyncAllStmt(ATerm term, pOFP_Traverse SyncAllStmt)
{
#ifdef DEBUG_PRINT
   printf("SyncAllStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "SyncAllStmt(<term>)", &SyncAllStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(SyncAllStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_StopCode(ATerm term, pOFP_Traverse StopCode)
{
#ifdef DEBUG_PRINT
   printf("StopCode: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "StopCode(<term>)", &StopCode->term)) {
 }

//....... ofp_uniqueSymbol: "Icon"
   OFP_Traverse Icon;
   if (ATmatch(term, "StopCode_SICE(<term>)", &Icon.term)) {
      if (ofp_traverse_Icon(Icon.term, &Icon)) {
         // MATCHED Icon
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Scon"
   OFP_Traverse Scon;
   if (ATmatch(term, "StopCode_SDCCE(<term>)", &Scon.term)) {
      if (ofp_traverse_Scon(Scon.term, &Scon)) {
         // MATCHED Scon
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_ErrorStopStmt(ATerm term, pOFP_Traverse ErrorStopStmt)
{
#ifdef DEBUG_PRINT
   printf("ErrorStopStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ErrorStopStmt(<term>)", &ErrorStopStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(ErrorStopStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_StopStmt(ATerm term, pOFP_Traverse StopStmt)
{
#ifdef DEBUG_PRINT
   printf("StopStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "StopStmt(<term>)", &StopStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(StopStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

//....... ofp_uniqueSymbol: "EOS"
   OFP_Traverse EOS;
   if (ATmatch(term, "PauseStmt(<term>)", &EOS.term)) {
      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_ContinueStmt(ATerm term, pOFP_Traverse ContinueStmt)
{
#ifdef DEBUG_PRINT
   printf("ContinueStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ContinueStmt(<term>)", &ContinueStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(ContinueStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ArithmeticIfStmt(ATerm term, pOFP_Traverse ArithmeticIfStmt)
{
#ifdef DEBUG_PRINT
   printf("ArithmeticIfStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ArithmeticIfStmt(<term>)", &ArithmeticIfStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(ArithmeticIfStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_LabelList(ATerm term, pOFP_Traverse LabelList)
{
#ifdef DEBUG_PRINT
   printf("LabelList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "LabelList(<term>)", &LabelList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_ComputedGotoStmt(ATerm term, pOFP_Traverse ComputedGotoStmt)
{
#ifdef DEBUG_PRINT
   printf("ComputedGotoStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ComputedGotoStmt(<term>)", &ComputedGotoStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(ComputedGotoStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_GotoStmt(ATerm term, pOFP_Traverse GotoStmt)
{
#ifdef DEBUG_PRINT
   printf("GotoStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "GotoStmt(<term>)", &GotoStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(GotoStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ExitStmt(ATerm term, pOFP_Traverse ExitStmt)
{
#ifdef DEBUG_PRINT
   printf("ExitStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ExitStmt(<term>)", &ExitStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(ExitStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_EndSelectTypeStmt(ATerm term, pOFP_Traverse EndSelectTypeStmt)
{
#ifdef DEBUG_PRINT
   printf("EndSelectTypeStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EndSelectTypeStmt(<term>)", &EndSelectTypeStmt->term)) {
//....... ofp_uniqueSymbol: "SelectConstructName"
   OFP_Traverse SelectConstructName;
   if (ofp_traverse_SelectConstructName(EndSelectTypeStmt->term, &SelectConstructName)) {
      // MATCHED SelectConstructName
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_TypeGuardStmt(ATerm term, pOFP_Traverse TypeGuardStmt)
{
#ifdef DEBUG_PRINT
   printf("TypeGuardStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "TypeGuardStmt(<term>)", &TypeGuardStmt->term)) {
 }

//....... ofp_uniqueSymbol: "EOS"
   OFP_Traverse EOS;
   if (ATmatch(term, "TypeGuardStmt_CLASS_DEFAULT(<term>)", &EOS.term)) {
      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DerivedTypeSpec"
   OFP_Traverse DerivedTypeSpec;
   if (ATmatch(term, "TypeGuardStmt_CLASS(<term>)", &DerivedTypeSpec.term)) {
      if (ofp_traverse_DerivedTypeSpec(DerivedTypeSpec.term, &DerivedTypeSpec)) {
         // MATCHED DerivedTypeSpec
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "EOS"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "EOS1"
   OFP_Traverse EOS1;
   if (ATmatch(term, "TypeGuardStmt_CLASS(<term>)", &EOS1.term)) {
      if (ofp_traverse_EOS(EOS1.term, &EOS1)) {
         // MATCHED EOS
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "TypeSpec"
   OFP_Traverse TypeSpec;
   if (ATmatch(term, "TypeGuardStmt_TYPE(<term>)", &TypeSpec.term)) {
      if (ofp_traverse_TypeSpec(TypeSpec.term, &TypeSpec)) {
         // MATCHED TypeSpec
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "EOS"
//.......       from table: 1
//.......               id: 2
//.......       unique sym: "EOS2"
   OFP_Traverse EOS2;
   if (ATmatch(term, "TypeGuardStmt_TYPE(<term>)", &EOS2.term)) {
      if (ofp_traverse_EOS(EOS2.term, &EOS2)) {
         // MATCHED EOS
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_SelectTypeStmt(ATerm term, pOFP_Traverse SelectTypeStmt)
{
#ifdef DEBUG_PRINT
   printf("SelectTypeStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "SelectTypeStmt(<term>)", &SelectTypeStmt->term)) {
//....... ofp_uniqueSymbol: "SelectConstructName0"
   OFP_Traverse SelectConstructName0;
   if (ofp_traverse_SelectConstructName0(SelectTypeStmt->term, &SelectConstructName0)) {
      // MATCHED SelectConstructName0
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_SelectTypeConstruct(ATerm term, pOFP_Traverse SelectTypeConstruct)
{
#ifdef DEBUG_PRINT
   printf("SelectTypeConstruct: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "SelectTypeConstruct(<term>)", &SelectTypeConstruct->term)) {
//....... ofp_uniqueSymbol: "SelectTypeStmt"
   OFP_Traverse SelectTypeStmt;
   if (ofp_traverse_SelectTypeStmt(SelectTypeConstruct->term, &SelectTypeStmt)) {
      // MATCHED SelectTypeStmt
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_CaseValue(ATerm term, pOFP_Traverse CaseValue)
{
#ifdef DEBUG_PRINT
   printf("CaseValue: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "CaseValue(<term>)", &CaseValue->term)) {
//....... ofp_uniqueSymbol: "ConstantExpr"
   OFP_Traverse ConstantExpr;
   if (ofp_traverse_ConstantExpr(CaseValue->term, &ConstantExpr)) {
      // MATCHED ConstantExpr
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_CaseValueRangeList(ATerm term, pOFP_Traverse CaseValueRangeList)
{
#ifdef DEBUG_PRINT
   printf("CaseValueRangeList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "CaseValueRangeList(<term>)", &CaseValueRangeList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_CaseValueRange(ATerm term, pOFP_Traverse CaseValueRange)
{
#ifdef DEBUG_PRINT
   printf("CaseValueRange: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "CaseValueRange(<term>)", &CaseValueRange->term)) {
//....... ofp_uniqueSymbol: "CaseValue"
   OFP_Traverse CaseValue;
   if (ofp_traverse_CaseValue(CaseValueRange->term, &CaseValue)) {
      // MATCHED CaseValue
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "CaseValue"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "CaseValue1"
   OFP_Traverse CaseValue1;
   if (ofp_traverse_CaseValue(CaseValueRange->term, &CaseValue1)) {
      // MATCHED CaseValue
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_CaseSelector(ATerm term, pOFP_Traverse CaseSelector)
{
#ifdef DEBUG_PRINT
   printf("CaseSelector: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "CaseSelector(<term>)", &CaseSelector->term)) {
 }

//....... ofp_uniqueSymbol: "CaseValueRangeList"
   OFP_Traverse CaseValueRangeList;
   if (ATmatch(term, "CaseSelector_CVRL(<term>)", &CaseValueRangeList.term)) {
      if (ofp_traverse_CaseValueRangeList(CaseValueRangeList.term, &CaseValueRangeList)) {
         // MATCHED CaseValueRangeList
         return ATtrue;
      } else return ATfalse;
   }

   if (ATmatch(term, "CaseSelector_DEFAULT")) {
      // MATCHED CaseSelector_DEFAULT
      return ATtrue;
   }

   return ATfalse;
}

ATbool ofp_traverse_CaseExpr(ATerm term, pOFP_Traverse CaseExpr)
{
#ifdef DEBUG_PRINT
   printf("CaseExpr: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "CaseExpr(<term>)", &CaseExpr->term)) {
//....... ofp_uniqueSymbol: "Expr"
   OFP_Traverse Expr;
   if (ofp_traverse_Expr(CaseExpr->term, &Expr)) {
      // MATCHED Expr
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_EndSelectStmt(ATerm term, pOFP_Traverse EndSelectStmt)
{
#ifdef DEBUG_PRINT
   printf("EndSelectStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EndSelectStmt(<term>)", &EndSelectStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(EndSelectStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_CaseStmt(ATerm term, pOFP_Traverse CaseStmt)
{
#ifdef DEBUG_PRINT
   printf("CaseStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "CaseStmt(<term>)", &CaseStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(CaseStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_SelectCaseStmt(ATerm term, pOFP_Traverse SelectCaseStmt)
{
#ifdef DEBUG_PRINT
   printf("SelectCaseStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "SelectCaseStmt(<term>)", &SelectCaseStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(SelectCaseStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_CaseConstruct(ATerm term, pOFP_Traverse CaseConstruct)
{
#ifdef DEBUG_PRINT
   printf("CaseConstruct: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "CaseConstruct(<term>)", &CaseConstruct->term)) {
//....... ofp_uniqueSymbol: "SelectCaseStmt"
   OFP_Traverse SelectCaseStmt;
   if (ofp_traverse_SelectCaseStmt(CaseConstruct->term, &SelectCaseStmt)) {
      // MATCHED SelectCaseStmt
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_IfStmt(ATerm term, pOFP_Traverse IfStmt)
{
#ifdef DEBUG_PRINT
   printf("IfStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "IfStmt(<term>)", &IfStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(IfStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_EndIfStmt(ATerm term, pOFP_Traverse EndIfStmt)
{
#ifdef DEBUG_PRINT
   printf("EndIfStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EndIfStmt(<term>)", &EndIfStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(EndIfStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ElseStmt(ATerm term, pOFP_Traverse ElseStmt)
{
#ifdef DEBUG_PRINT
   printf("ElseStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ElseStmt(<term>)", &ElseStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(ElseStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ElseIfStmt(ATerm term, pOFP_Traverse ElseIfStmt)
{
#ifdef DEBUG_PRINT
   printf("ElseIfStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ElseIfStmt(<term>)", &ElseIfStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(ElseIfStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_IfThenStmt(ATerm term, pOFP_Traverse IfThenStmt)
{
#ifdef DEBUG_PRINT
   printf("IfThenStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "IfThenStmt(<term>)", &IfThenStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(IfThenStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_IfConstruct(ATerm term, pOFP_Traverse IfConstruct)
{
#ifdef DEBUG_PRINT
   printf("IfConstruct: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "IfConstruct(<term>)", &IfConstruct->term)) {
//....... ofp_uniqueSymbol: "IfThenStmt"
   OFP_Traverse IfThenStmt;
   if (ofp_traverse_IfThenStmt(IfConstruct->term, &IfThenStmt)) {
      // MATCHED IfThenStmt
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_CycleStmt(ATerm term, pOFP_Traverse CycleStmt)
{
#ifdef DEBUG_PRINT
   printf("CycleStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "CycleStmt(<term>)", &CycleStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(CycleStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_EndDoStmt(ATerm term, pOFP_Traverse EndDoStmt)
{
#ifdef DEBUG_PRINT
   printf("EndDoStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EndDoStmt(<term>)", &EndDoStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(EndDoStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_DoVariable(ATerm term, pOFP_Traverse DoVariable)
{
#ifdef DEBUG_PRINT
   printf("DoVariable: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DoVariable(<term>)", &DoVariable->term)) {
//....... ofp_uniqueSymbol: "ScalarIntVariableName"
   OFP_Traverse ScalarIntVariableName;
   if (ofp_traverse_ScalarIntVariableName(DoVariable->term, &ScalarIntVariableName)) {
      // MATCHED ScalarIntVariableName
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_LoopControl(ATerm term, pOFP_Traverse LoopControl)
{
#ifdef DEBUG_PRINT
   printf("LoopControl: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "LoopControl(<term>)", &LoopControl->term)) {
 }

//....... ofp_uniqueSymbol: "ForallHeader"
   OFP_Traverse ForallHeader;
   if (ATmatch(term, "LoopControl_CONCURRENT(<term>)", &ForallHeader.term)) {
      if (ofp_traverse_ForallHeader(ForallHeader.term, &ForallHeader)) {
         // MATCHED ForallHeader
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
   OFP_Traverse Expr;
   if (ATmatch(term, "LoopControl_WHILE(<term>)", &Expr.term)) {
      if (ofp_traverse_Expr(Expr.term, &Expr)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DoVariable"
   OFP_Traverse DoVariable;
   if (ATmatch(term, "LoopControl_DV(<term>)", &DoVariable.term)) {
      if (ofp_traverse_DoVariable(DoVariable.term, &DoVariable)) {
         // MATCHED DoVariable
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "Expr1"
   OFP_Traverse Expr1;
   if (ATmatch(term, "LoopControl_DV(<term>)", &Expr1.term)) {
      if (ofp_traverse_Expr(Expr1.term, &Expr1)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 1
//.......               id: 2
//.......       unique sym: "Expr2"
   OFP_Traverse Expr2;
   if (ATmatch(term, "LoopControl_DV(<term>)", &Expr2.term)) {
      if (ofp_traverse_Expr(Expr2.term, &Expr2)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_NonlabelDoStmt(ATerm term, pOFP_Traverse NonlabelDoStmt)
{
#ifdef DEBUG_PRINT
   printf("NonlabelDoStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "NonlabelDoStmt(<term>)", &NonlabelDoStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(NonlabelDoStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_LabelDoStmt(ATerm term, pOFP_Traverse LabelDoStmt)
{
#ifdef DEBUG_PRINT
   printf("LabelDoStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "LabelDoStmt(<term>)", &LabelDoStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(LabelDoStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_EndCriticalStmt(ATerm term, pOFP_Traverse EndCriticalStmt)
{
#ifdef DEBUG_PRINT
   printf("EndCriticalStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EndCriticalStmt(<term>)", &EndCriticalStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(EndCriticalStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_CriticalStmt(ATerm term, pOFP_Traverse CriticalStmt)
{
#ifdef DEBUG_PRINT
   printf("CriticalStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "CriticalStmt(<term>)", &CriticalStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(CriticalStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_CriticalConstruct(ATerm term, pOFP_Traverse CriticalConstruct)
{
#ifdef DEBUG_PRINT
   printf("CriticalConstruct: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "CriticalConstruct(<term>)", &CriticalConstruct->term)) {
//....... ofp_uniqueSymbol: "CriticalStmt"
   OFP_Traverse CriticalStmt;
   if (ofp_traverse_CriticalStmt(CriticalConstruct->term, &CriticalStmt)) {
      // MATCHED CriticalStmt
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_EndBlockStmt(ATerm term, pOFP_Traverse EndBlockStmt)
{
#ifdef DEBUG_PRINT
   printf("EndBlockStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EndBlockStmt(<term>)", &EndBlockStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(EndBlockStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_BlockStmt(ATerm term, pOFP_Traverse BlockStmt)
{
#ifdef DEBUG_PRINT
   printf("BlockStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "BlockStmt(<term>)", &BlockStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(BlockStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_BlockConstruct(ATerm term, pOFP_Traverse BlockConstruct)
{
#ifdef DEBUG_PRINT
   printf("BlockConstruct: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "BlockConstruct(<term>)", &BlockConstruct->term)) {
//....... ofp_uniqueSymbol: "BlockStmt"
   OFP_Traverse BlockStmt;
   if (ofp_traverse_BlockStmt(BlockConstruct->term, &BlockStmt)) {
      // MATCHED BlockStmt
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_EndAssociateStmt(ATerm term, pOFP_Traverse EndAssociateStmt)
{
#ifdef DEBUG_PRINT
   printf("EndAssociateStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EndAssociateStmt(<term>)", &EndAssociateStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(EndAssociateStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_Selector(ATerm term, pOFP_Traverse Selector)
{
#ifdef DEBUG_PRINT
   printf("Selector: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "Selector(<term>)", &Selector->term)) {
 }

//....... ofp_uniqueSymbol: "Variable"
   OFP_Traverse Variable;
   if (ATmatch(term, "Selector_Var(<term>)", &Variable.term)) {
      if (ofp_traverse_Variable(Variable.term, &Variable)) {
         // MATCHED Variable
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
   OFP_Traverse Expr;
   if (ATmatch(term, "Selector_Expr(<term>)", &Expr.term)) {
      if (ofp_traverse_Expr(Expr.term, &Expr)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_AssociationList(ATerm term, pOFP_Traverse AssociationList)
{
#ifdef DEBUG_PRINT
   printf("AssociationList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AssociationList(<term>)", &AssociationList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_Association(ATerm term, pOFP_Traverse Association)
{
#ifdef DEBUG_PRINT
   printf("Association: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "Association(<term>)", &Association->term)) {
//....... ofp_uniqueSymbol: "AssociateName"
   OFP_Traverse AssociateName;
   if (ofp_traverse_AssociateName(Association->term, &AssociateName)) {
      // MATCHED AssociateName
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_AssociateStmt(ATerm term, pOFP_Traverse AssociateStmt)
{
#ifdef DEBUG_PRINT
   printf("AssociateStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AssociateStmt(<term>)", &AssociateStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(AssociateStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_AssociateConstruct(ATerm term, pOFP_Traverse AssociateConstruct)
{
#ifdef DEBUG_PRINT
   printf("AssociateConstruct: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AssociateConstruct(<term>)", &AssociateConstruct->term)) {
//....... ofp_uniqueSymbol: "AssociateStmt"
   OFP_Traverse AssociateStmt;
   if (ofp_traverse_AssociateStmt(AssociateConstruct->term, &AssociateStmt)) {
      // MATCHED AssociateStmt
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_Block(ATerm term, pOFP_Traverse Block)
{
#ifdef DEBUG_PRINT
   printf("Block: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "Block(<term>)", &Block->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_SelectConstructName(ATerm term, pOFP_Traverse SelectConstructName)
{
#ifdef DEBUG_PRINT
   printf("SelectConstructName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "SelectConstructName(<term>)", &SelectConstructName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(SelectConstructName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ScalarIntVariableName(ATerm term, pOFP_Traverse ScalarIntVariableName)
{
#ifdef DEBUG_PRINT
   printf("ScalarIntVariableName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ScalarIntVariableName(<term>)", &ScalarIntVariableName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(ScalarIntVariableName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_IfConstructName(ATerm term, pOFP_Traverse IfConstructName)
{
#ifdef DEBUG_PRINT
   printf("IfConstructName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "IfConstructName(<term>)", &IfConstructName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(IfConstructName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_DoConstructName(ATerm term, pOFP_Traverse DoConstructName)
{
#ifdef DEBUG_PRINT
   printf("DoConstructName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DoConstructName(<term>)", &DoConstructName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(DoConstructName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_CriticalConstructName(ATerm term, pOFP_Traverse CriticalConstructName)
{
#ifdef DEBUG_PRINT
   printf("CriticalConstructName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "CriticalConstructName(<term>)", &CriticalConstructName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(CriticalConstructName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ConstructName(ATerm term, pOFP_Traverse ConstructName)
{
#ifdef DEBUG_PRINT
   printf("ConstructName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ConstructName(<term>)", &ConstructName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(ConstructName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_CaseConstructName(ATerm term, pOFP_Traverse CaseConstructName)
{
#ifdef DEBUG_PRINT
   printf("CaseConstructName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "CaseConstructName(<term>)", &CaseConstructName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(CaseConstructName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_BlockConstructName(ATerm term, pOFP_Traverse BlockConstructName)
{
#ifdef DEBUG_PRINT
   printf("BlockConstructName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "BlockConstructName(<term>)", &BlockConstructName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(BlockConstructName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_AssociateName(ATerm term, pOFP_Traverse AssociateName)
{
#ifdef DEBUG_PRINT
   printf("AssociateName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AssociateName(<term>)", &AssociateName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(AssociateName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_AssociateConstructName(ATerm term, pOFP_Traverse AssociateConstructName)
{
#ifdef DEBUG_PRINT
   printf("AssociateConstructName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AssociateConstructName(<term>)", &AssociateConstructName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(AssociateConstructName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_EndBlockDataStmt(ATerm term, pOFP_Traverse EndBlockDataStmt)
{
#ifdef DEBUG_PRINT
   printf("EndBlockDataStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EndBlockDataStmt(<term>)", &EndBlockDataStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(EndBlockDataStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "Label"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "Label1"
   OFP_Traverse Label1;
   if (ofp_traverse_Label(EndBlockDataStmt->term, &Label1)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_BlockDataStmt(ATerm term, pOFP_Traverse BlockDataStmt)
{
#ifdef DEBUG_PRINT
   printf("BlockDataStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "BlockDataStmt(<term>)", &BlockDataStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(BlockDataStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_BlockData(ATerm term, pOFP_Traverse BlockData)
{
#ifdef DEBUG_PRINT
   printf("BlockData: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "BlockData(<term>)", &BlockData->term)) {
//....... ofp_uniqueSymbol: "BlockDataStmt"
   OFP_Traverse BlockDataStmt;
   if (ofp_traverse_BlockDataStmt(BlockData->term, &BlockDataStmt)) {
      // MATCHED BlockDataStmt
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_EndSubmoduleStmt(ATerm term, pOFP_Traverse EndSubmoduleStmt)
{
#ifdef DEBUG_PRINT
   printf("EndSubmoduleStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EndSubmoduleStmt(<term>)", &EndSubmoduleStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(EndSubmoduleStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ParentIdentifier(ATerm term, pOFP_Traverse ParentIdentifier)
{
#ifdef DEBUG_PRINT
   printf("ParentIdentifier: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ParentIdentifier(<term>)", &ParentIdentifier->term)) {
//....... ofp_uniqueSymbol: "AncestorModuleName"
   OFP_Traverse AncestorModuleName;
   if (ofp_traverse_AncestorModuleName(ParentIdentifier->term, &AncestorModuleName)) {
      // MATCHED AncestorModuleName
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_SubmoduleStmt(ATerm term, pOFP_Traverse SubmoduleStmt)
{
#ifdef DEBUG_PRINT
   printf("SubmoduleStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "SubmoduleStmt(<term>)", &SubmoduleStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(SubmoduleStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_Submodule(ATerm term, pOFP_Traverse Submodule)
{
#ifdef DEBUG_PRINT
   printf("Submodule: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "Submodule(<term>)", &Submodule->term)) {
//....... ofp_uniqueSymbol: "SubmoduleStmt"
   OFP_Traverse SubmoduleStmt;
   if (ofp_traverse_SubmoduleStmt(Submodule->term, &SubmoduleStmt)) {
      // MATCHED SubmoduleStmt
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_UseDefinedOperator(ATerm term, pOFP_Traverse UseDefinedOperator)
{
#ifdef DEBUG_PRINT
   printf("UseDefinedOperator: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "UseDefinedOperator(<term>)", &UseDefinedOperator->term)) {
//....... ofp_uniqueSymbol: "DefinedBinaryOp"
   OFP_Traverse DefinedBinaryOp;
   if (ofp_traverse_DefinedBinaryOp(UseDefinedOperator->term, &DefinedBinaryOp)) {
      // MATCHED DefinedBinaryOp
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "DefinedUnaryOp"
   OFP_Traverse DefinedUnaryOp;
   if (ofp_traverse_DefinedUnaryOp(UseDefinedOperator->term, &DefinedUnaryOp)) {
      // MATCHED DefinedUnaryOp
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_LocalDefinedOperator(ATerm term, pOFP_Traverse LocalDefinedOperator)
{
#ifdef DEBUG_PRINT
   printf("LocalDefinedOperator: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "LocalDefinedOperator(<term>)", &LocalDefinedOperator->term)) {
//....... ofp_uniqueSymbol: "DefinedBinaryOp"
   OFP_Traverse DefinedBinaryOp;
   if (ofp_traverse_DefinedBinaryOp(LocalDefinedOperator->term, &DefinedBinaryOp)) {
      // MATCHED DefinedBinaryOp
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "DefinedUnaryOp"
   OFP_Traverse DefinedUnaryOp;
   if (ofp_traverse_DefinedUnaryOp(LocalDefinedOperator->term, &DefinedUnaryOp)) {
      // MATCHED DefinedUnaryOp
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_OnlyUseName(ATerm term, pOFP_Traverse OnlyUseName)
{
#ifdef DEBUG_PRINT
   printf("OnlyUseName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "OnlyUseName(<term>)", &OnlyUseName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(OnlyUseName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_OnlyList(ATerm term, pOFP_Traverse OnlyList)
{
#ifdef DEBUG_PRINT
   printf("OnlyList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "OnlyList(<term>)", &OnlyList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_Only(ATerm term, pOFP_Traverse Only)
{
#ifdef DEBUG_PRINT
   printf("Only: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "Only(<term>)", &Only->term)) {
//....... ofp_uniqueSymbol: "Rename"
   OFP_Traverse Rename;
   if (ofp_traverse_Rename(Only->term, &Rename)) {
      // MATCHED Rename
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "OnlyUseName"
   OFP_Traverse OnlyUseName;
   if (ofp_traverse_OnlyUseName(Only->term, &OnlyUseName)) {
      // MATCHED OnlyUseName
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_RenameList(ATerm term, pOFP_Traverse RenameList)
{
#ifdef DEBUG_PRINT
   printf("RenameList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "RenameList(<term>)", &RenameList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_Rename(ATerm term, pOFP_Traverse Rename)
{
#ifdef DEBUG_PRINT
   printf("Rename: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "Rename(<term>)", &Rename->term)) {
//....... ofp_uniqueSymbol: "LocalDefinedOperator"
   OFP_Traverse LocalDefinedOperator;
   if (ofp_traverse_LocalDefinedOperator(Rename->term, &LocalDefinedOperator)) {
      // MATCHED LocalDefinedOperator
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "LocalName"
   OFP_Traverse LocalName;
   if (ofp_traverse_LocalName(Rename->term, &LocalName)) {
      // MATCHED LocalName
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ModuleNature(ATerm term, pOFP_Traverse ModuleNature)
{
#ifdef DEBUG_PRINT
   printf("ModuleNature: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ModuleNature(<term>)", &ModuleNature->term)) {
 }

   if (ATmatch(term, "ModuleNature_NON_INTRINSIC")) {
      // MATCHED ModuleNature_NON_INTRINSIC
      return ATtrue;
   }

   if (ATmatch(term, "ModuleNature_INTRINSIC")) {
      // MATCHED ModuleNature_INTRINSIC
      return ATtrue;
   }

   return ATfalse;
}

ATbool ofp_traverse_UseStmt(ATerm term, pOFP_Traverse UseStmt)
{
#ifdef DEBUG_PRINT
   printf("UseStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "UseStmt(<term>)", &UseStmt->term)) {
 }

//....... ofp_uniqueSymbol: "ModuleName"
   OFP_Traverse ModuleName;
   if (ATmatch(term, "UseStmt_Only(<term>)", &ModuleName.term)) {
      if (ofp_traverse_ModuleName(ModuleName.term, &ModuleName)) {
         // MATCHED ModuleName
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "EOS"
   OFP_Traverse EOS;
   if (ATmatch(term, "UseStmt_Only(<term>)", &EOS.term)) {
      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "ModuleName"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "ModuleName1"
   OFP_Traverse ModuleName1;
   if (ATmatch(term, "UseStmt_Rename(<term>)", &ModuleName1.term)) {
      if (ofp_traverse_ModuleName(ModuleName1.term, &ModuleName1)) {
         // MATCHED ModuleName
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "EOS"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "EOS1"
   OFP_Traverse EOS1;
   if (ATmatch(term, "UseStmt_Rename(<term>)", &EOS1.term)) {
      if (ofp_traverse_EOS(EOS1.term, &EOS1)) {
         // MATCHED EOS
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_ModuleSubprogram(ATerm term, pOFP_Traverse ModuleSubprogram)
{
#ifdef DEBUG_PRINT
   printf("ModuleSubprogram: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ModuleSubprogram(<term>)", &ModuleSubprogram->term)) {
//....... ofp_uniqueSymbol: "SeparateModuleSubprogram"
   OFP_Traverse SeparateModuleSubprogram;
   if (ofp_traverse_SeparateModuleSubprogram(ModuleSubprogram->term, &SeparateModuleSubprogram)) {
      // MATCHED SeparateModuleSubprogram
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "SubroutineSubprogram"
   OFP_Traverse SubroutineSubprogram;
   if (ofp_traverse_SubroutineSubprogram(ModuleSubprogram->term, &SubroutineSubprogram)) {
      // MATCHED SubroutineSubprogram
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "FunctionSubprogram"
   OFP_Traverse FunctionSubprogram;
   if (ofp_traverse_FunctionSubprogram(ModuleSubprogram->term, &FunctionSubprogram)) {
      // MATCHED FunctionSubprogram
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ModuleSubprogramPart(ATerm term, pOFP_Traverse ModuleSubprogramPart)
{
#ifdef DEBUG_PRINT
   printf("ModuleSubprogramPart: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ModuleSubprogramPart(<term>)", &ModuleSubprogramPart->term)) {
//....... ofp_uniqueSymbol: "ContainsStmt"
   OFP_Traverse ContainsStmt;
   if (ofp_traverse_ContainsStmt(ModuleSubprogramPart->term, &ContainsStmt)) {
      // MATCHED ContainsStmt
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_EndModuleStmt(ATerm term, pOFP_Traverse EndModuleStmt)
{
#ifdef DEBUG_PRINT
   printf("EndModuleStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EndModuleStmt(<term>)", &EndModuleStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(EndModuleStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ModuleStmt(ATerm term, pOFP_Traverse ModuleStmt)
{
#ifdef DEBUG_PRINT
   printf("ModuleStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ModuleStmt(<term>)", &ModuleStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(ModuleStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_Module(ATerm term, pOFP_Traverse Module)
{
#ifdef DEBUG_PRINT
   printf("Module: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "Module(<term>)", &Module->term)) {
//....... ofp_uniqueSymbol: "ModuleStmt"
   OFP_Traverse ModuleStmt;
   if (ofp_traverse_ModuleStmt(Module->term, &ModuleStmt)) {
      // MATCHED ModuleStmt
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_EndProgramStmt(ATerm term, pOFP_Traverse EndProgramStmt)
{
#ifdef DEBUG_PRINT
   printf("EndProgramStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EndProgramStmt(<term>)", &EndProgramStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(EndProgramStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ProgramStmt(ATerm term, pOFP_Traverse ProgramStmt)
{
#ifdef DEBUG_PRINT
   printf("ProgramStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ProgramStmt(<term>)", &ProgramStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(ProgramStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_MainProgram(ATerm term, pOFP_Traverse MainProgram)
{
#ifdef DEBUG_PRINT
   printf("MainProgram: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "MainProgram(<term>)", &MainProgram->term)) {
//....... ofp_uniqueSymbol: "ProgramStmt"
   OFP_Traverse ProgramStmt;
   if (ofp_traverse_ProgramStmt(MainProgram->term, &ProgramStmt)) {
      // MATCHED ProgramStmt
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_Keyword(ATerm term, pOFP_Traverse Keyword)
{
#ifdef DEBUG_PRINT
   printf("Keyword: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "Keyword(<term>)", &Keyword->term)) {
//....... ofp_uniqueSymbol: "Name"
   OFP_Traverse Name;
   if (ofp_traverse_Name(Keyword->term, &Name)) {
      // MATCHED Name
      return ATtrue;
   } 
 }

   return ATfalse;
}
#endif

ATbool ofp_traverse_ActionStmt(ATerm term, pOFP_Traverse ActionStmt)
{
#ifdef DEBUG_PRINT
   printf("ActionStmt: %s\n", ATwriteToString(term));
#endif

#ifdef NOT_YET
 // This match may not be required for some productions.
 if (ATmatch(term, "ActionStmt(<term>)", &ActionStmt->term)) {
//....... ofp_uniqueSymbol: "EndDoStmt"
   OFP_Traverse EndDoStmt;
   if (ofp_traverse_EndDoStmt(ActionStmt->term, &EndDoStmt)) {
      // MATCHED EndDoStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "NonlabelDoStmt"
   OFP_Traverse NonlabelDoStmt;
   if (ofp_traverse_NonlabelDoStmt(ActionStmt->term, &NonlabelDoStmt)) {
      // MATCHED NonlabelDoStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "LabelDoStmt"
   OFP_Traverse LabelDoStmt;
   if (ofp_traverse_LabelDoStmt(ActionStmt->term, &LabelDoStmt)) {
      // MATCHED LabelDoStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "ComputedGotoStmt"
   OFP_Traverse ComputedGotoStmt;
   if (ofp_traverse_ComputedGotoStmt(ActionStmt->term, &ComputedGotoStmt)) {
      // MATCHED ComputedGotoStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "ArithmeticIfStmt"
   OFP_Traverse ArithmeticIfStmt;
   if (ofp_traverse_ArithmeticIfStmt(ActionStmt->term, &ArithmeticIfStmt)) {
      // MATCHED ArithmeticIfStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "WriteStmt"
   OFP_Traverse WriteStmt;
   if (ofp_traverse_WriteStmt(ActionStmt->term, &WriteStmt)) {
      // MATCHED WriteStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "WhereStmt"
   OFP_Traverse WhereStmt;
   if (ofp_traverse_WhereStmt(ActionStmt->term, &WhereStmt)) {
      // MATCHED WhereStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "WaitStmt"
   OFP_Traverse WaitStmt;
   if (ofp_traverse_WaitStmt(ActionStmt->term, &WaitStmt)) {
      // MATCHED WaitStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "UnlockStmt"
   OFP_Traverse UnlockStmt;
   if (ofp_traverse_UnlockStmt(ActionStmt->term, &UnlockStmt)) {
      // MATCHED UnlockStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "SyncMemoryStmt"
   OFP_Traverse SyncMemoryStmt;
   if (ofp_traverse_SyncMemoryStmt(ActionStmt->term, &SyncMemoryStmt)) {
      // MATCHED SyncMemoryStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "SyncImagesStmt"
   OFP_Traverse SyncImagesStmt;
   if (ofp_traverse_SyncImagesStmt(ActionStmt->term, &SyncImagesStmt)) {
      // MATCHED SyncImagesStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "SyncAllStmt"
   OFP_Traverse SyncAllStmt;
   if (ofp_traverse_SyncAllStmt(ActionStmt->term, &SyncAllStmt)) {
      // MATCHED SyncAllStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "StopStmt"
   OFP_Traverse StopStmt;
   if (ofp_traverse_StopStmt(ActionStmt->term, &StopStmt)) {
      // MATCHED StopStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "RewindStmt"
   OFP_Traverse RewindStmt;
   if (ofp_traverse_RewindStmt(ActionStmt->term, &RewindStmt)) {
      // MATCHED RewindStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "ReturnStmt"
   OFP_Traverse ReturnStmt;
   if (ofp_traverse_ReturnStmt(ActionStmt->term, &ReturnStmt)) {
      // MATCHED ReturnStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "ReadStmt"
   OFP_Traverse ReadStmt;
   if (ofp_traverse_ReadStmt(ActionStmt->term, &ReadStmt)) {
      // MATCHED ReadStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "PrintStmt"
   OFP_Traverse PrintStmt;
   if (ofp_traverse_PrintStmt(ActionStmt->term, &PrintStmt)) {
      // MATCHED PrintStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "PointerAssignmentStmt"
   OFP_Traverse PointerAssignmentStmt;
   if (ofp_traverse_PointerAssignmentStmt(ActionStmt->term, &PointerAssignmentStmt)) {
      // MATCHED PointerAssignmentStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "OpenStmt"
   OFP_Traverse OpenStmt;
   if (ofp_traverse_OpenStmt(ActionStmt->term, &OpenStmt)) {
      // MATCHED OpenStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "NullifyStmt"
   OFP_Traverse NullifyStmt;
   if (ofp_traverse_NullifyStmt(ActionStmt->term, &NullifyStmt)) {
      // MATCHED NullifyStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "LockStmt"
   OFP_Traverse LockStmt;
   if (ofp_traverse_LockStmt(ActionStmt->term, &LockStmt)) {
      // MATCHED LockStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "InquireStmt"
   OFP_Traverse InquireStmt;
   if (ofp_traverse_InquireStmt(ActionStmt->term, &InquireStmt)) {
      // MATCHED InquireStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "IfStmt"
   OFP_Traverse IfStmt;
   if (ofp_traverse_IfStmt(ActionStmt->term, &IfStmt)) {
      // MATCHED IfStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "GotoStmt"
   OFP_Traverse GotoStmt;
   if (ofp_traverse_GotoStmt(ActionStmt->term, &GotoStmt)) {
      // MATCHED GotoStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "ForallStmt"
   OFP_Traverse ForallStmt;
   if (ofp_traverse_ForallStmt(ActionStmt->term, &ForallStmt)) {
      // MATCHED ForallStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "FlushStmt"
   OFP_Traverse FlushStmt;
   if (ofp_traverse_FlushStmt(ActionStmt->term, &FlushStmt)) {
      // MATCHED FlushStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "ExitStmt"
   OFP_Traverse ExitStmt;
   if (ofp_traverse_ExitStmt(ActionStmt->term, &ExitStmt)) {
      // MATCHED ExitStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "ErrorStopStmt"
   OFP_Traverse ErrorStopStmt;
   if (ofp_traverse_ErrorStopStmt(ActionStmt->term, &ErrorStopStmt)) {
      // MATCHED ErrorStopStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "EndfileStmt"
   OFP_Traverse EndfileStmt;
   if (ofp_traverse_EndfileStmt(ActionStmt->term, &EndfileStmt)) {
      // MATCHED EndfileStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "EndSubroutineStmt"
   OFP_Traverse EndSubroutineStmt;
   if (ofp_traverse_EndSubroutineStmt(ActionStmt->term, &EndSubroutineStmt)) {
      // MATCHED EndSubroutineStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "EndProgramStmt"
   OFP_Traverse EndProgramStmt;
   if (ofp_traverse_EndProgramStmt(ActionStmt->term, &EndProgramStmt)) {
      // MATCHED EndProgramStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "EndMpSubprogramStmt"
   OFP_Traverse EndMpSubprogramStmt;
   if (ofp_traverse_EndMpSubprogramStmt(ActionStmt->term, &EndMpSubprogramStmt)) {
      // MATCHED EndMpSubprogramStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "EndFunctionStmt"
   OFP_Traverse EndFunctionStmt;
   if (ofp_traverse_EndFunctionStmt(ActionStmt->term, &EndFunctionStmt)) {
      // MATCHED EndFunctionStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "DeallocateStmt"
   OFP_Traverse DeallocateStmt;
   if (ofp_traverse_DeallocateStmt(ActionStmt->term, &DeallocateStmt)) {
      // MATCHED DeallocateStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "CycleStmt"
   OFP_Traverse CycleStmt;
   if (ofp_traverse_CycleStmt(ActionStmt->term, &CycleStmt)) {
      // MATCHED CycleStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "ContinueStmt"
   OFP_Traverse ContinueStmt;
   if (ofp_traverse_ContinueStmt(ActionStmt->term, &ContinueStmt)) {
      // MATCHED ContinueStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "CloseStmt"
   OFP_Traverse CloseStmt;
   if (ofp_traverse_CloseStmt(ActionStmt->term, &CloseStmt)) {
      // MATCHED CloseStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "CallStmt"
   OFP_Traverse CallStmt;
   if (ofp_traverse_CallStmt(ActionStmt->term, &CallStmt)) {
      // MATCHED CallStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "BackspaceStmt"
   OFP_Traverse BackspaceStmt;
   if (ofp_traverse_BackspaceStmt(ActionStmt->term, &BackspaceStmt)) {
      // MATCHED BackspaceStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "AssignmentStmt"
   OFP_Traverse AssignmentStmt;
   if (ofp_traverse_AssignmentStmt(ActionStmt->term, &AssignmentStmt)) {
      // MATCHED AssignmentStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "AllocateStmt"
   OFP_Traverse AllocateStmt;
   if (ofp_traverse_AllocateStmt(ActionStmt->term, &AllocateStmt)) {
      // MATCHED AllocateStmt
      return ATtrue;
   } 
 }
#endif
   return ATfalse;
}

#ifdef NOT_YET
ATbool ofp_traverse_ExecutableConstruct(ATerm term, pOFP_Traverse ExecutableConstruct)
{
#ifdef DEBUG_PRINT
   printf("ExecutableConstruct: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ExecutableConstruct(<term>)", &ExecutableConstruct->term)) {
//....... ofp_uniqueSymbol: "WhereConstruct"
   OFP_Traverse WhereConstruct;
   if (ofp_traverse_WhereConstruct(ExecutableConstruct->term, &WhereConstruct)) {
      // MATCHED WhereConstruct
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "SelectTypeConstruct"
   OFP_Traverse SelectTypeConstruct;
   if (ofp_traverse_SelectTypeConstruct(ExecutableConstruct->term, &SelectTypeConstruct)) {
      // MATCHED SelectTypeConstruct
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "IfConstruct"
   OFP_Traverse IfConstruct;
   if (ofp_traverse_IfConstruct(ExecutableConstruct->term, &IfConstruct)) {
      // MATCHED IfConstruct
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "ForallConstruct"
   OFP_Traverse ForallConstruct;
   if (ofp_traverse_ForallConstruct(ExecutableConstruct->term, &ForallConstruct)) {
      // MATCHED ForallConstruct
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "CriticalConstruct"
   OFP_Traverse CriticalConstruct;
   if (ofp_traverse_CriticalConstruct(ExecutableConstruct->term, &CriticalConstruct)) {
      // MATCHED CriticalConstruct
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "CaseConstruct"
   OFP_Traverse CaseConstruct;
   if (ofp_traverse_CaseConstruct(ExecutableConstruct->term, &CaseConstruct)) {
      // MATCHED CaseConstruct
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "BlockConstruct"
   OFP_Traverse BlockConstruct;
   if (ofp_traverse_BlockConstruct(ExecutableConstruct->term, &BlockConstruct)) {
      // MATCHED BlockConstruct
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "AssociateConstruct"
   OFP_Traverse AssociateConstruct;
   if (ofp_traverse_AssociateConstruct(ExecutableConstruct->term, &AssociateConstruct)) {
      // MATCHED AssociateConstruct
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "ActionStmt"
   OFP_Traverse ActionStmt;
   if (ofp_traverse_ActionStmt(ExecutableConstruct->term, &ActionStmt)) {
      // MATCHED ActionStmt
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_OtherSpecificationStmt(ATerm term, pOFP_Traverse OtherSpecificationStmt)
{
#ifdef DEBUG_PRINT
   printf("OtherSpecificationStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "OtherSpecificationStmt(<term>)", &OtherSpecificationStmt->term)) {
//....... ofp_uniqueSymbol: "ValueStmt"
   OFP_Traverse ValueStmt;
   if (ofp_traverse_ValueStmt(OtherSpecificationStmt->term, &ValueStmt)) {
      // MATCHED ValueStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "VolatileStmt"
   OFP_Traverse VolatileStmt;
   if (ofp_traverse_VolatileStmt(OtherSpecificationStmt->term, &VolatileStmt)) {
      // MATCHED VolatileStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "TargetStmt"
   OFP_Traverse TargetStmt;
   if (ofp_traverse_TargetStmt(OtherSpecificationStmt->term, &TargetStmt)) {
      // MATCHED TargetStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "SaveStmt"
   OFP_Traverse SaveStmt;
   if (ofp_traverse_SaveStmt(OtherSpecificationStmt->term, &SaveStmt)) {
      // MATCHED SaveStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "ProtectedStmt"
   OFP_Traverse ProtectedStmt;
   if (ofp_traverse_ProtectedStmt(OtherSpecificationStmt->term, &ProtectedStmt)) {
      // MATCHED ProtectedStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "PointerStmt"
   OFP_Traverse PointerStmt;
   if (ofp_traverse_PointerStmt(OtherSpecificationStmt->term, &PointerStmt)) {
      // MATCHED PointerStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "OptionalStmt"
   OFP_Traverse OptionalStmt;
   if (ofp_traverse_OptionalStmt(OtherSpecificationStmt->term, &OptionalStmt)) {
      // MATCHED OptionalStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "NamelistStmt"
   OFP_Traverse NamelistStmt;
   if (ofp_traverse_NamelistStmt(OtherSpecificationStmt->term, &NamelistStmt)) {
      // MATCHED NamelistStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "IntrinsicStmt"
   OFP_Traverse IntrinsicStmt;
   if (ofp_traverse_IntrinsicStmt(OtherSpecificationStmt->term, &IntrinsicStmt)) {
      // MATCHED IntrinsicStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "IntentStmt"
   OFP_Traverse IntentStmt;
   if (ofp_traverse_IntentStmt(OtherSpecificationStmt->term, &IntentStmt)) {
      // MATCHED IntentStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "ExternalStmt"
   OFP_Traverse ExternalStmt;
   if (ofp_traverse_ExternalStmt(OtherSpecificationStmt->term, &ExternalStmt)) {
      // MATCHED ExternalStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "EquivalenceStmt"
   OFP_Traverse EquivalenceStmt;
   if (ofp_traverse_EquivalenceStmt(OtherSpecificationStmt->term, &EquivalenceStmt)) {
      // MATCHED EquivalenceStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "DimensionStmt"
   OFP_Traverse DimensionStmt;
   if (ofp_traverse_DimensionStmt(OtherSpecificationStmt->term, &DimensionStmt)) {
      // MATCHED DimensionStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "DataStmt"
   OFP_Traverse DataStmt;
   if (ofp_traverse_DataStmt(OtherSpecificationStmt->term, &DataStmt)) {
      // MATCHED DataStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "CommonStmt"
   OFP_Traverse CommonStmt;
   if (ofp_traverse_CommonStmt(OtherSpecificationStmt->term, &CommonStmt)) {
      // MATCHED CommonStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "ContiguousStmt"
   OFP_Traverse ContiguousStmt;
   if (ofp_traverse_ContiguousStmt(OtherSpecificationStmt->term, &ContiguousStmt)) {
      // MATCHED ContiguousStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "CodimensionStmt"
   OFP_Traverse CodimensionStmt;
   if (ofp_traverse_CodimensionStmt(OtherSpecificationStmt->term, &CodimensionStmt)) {
      // MATCHED CodimensionStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "BindStmt"
   OFP_Traverse BindStmt;
   if (ofp_traverse_BindStmt(OtherSpecificationStmt->term, &BindStmt)) {
      // MATCHED BindStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "AsynchronousStmt"
   OFP_Traverse AsynchronousStmt;
   if (ofp_traverse_AsynchronousStmt(OtherSpecificationStmt->term, &AsynchronousStmt)) {
      // MATCHED AsynchronousStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "AllocatableStmt"
   OFP_Traverse AllocatableStmt;
   if (ofp_traverse_AllocatableStmt(OtherSpecificationStmt->term, &AllocatableStmt)) {
      // MATCHED AllocatableStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "AccessStmt"
   OFP_Traverse AccessStmt;
   if (ofp_traverse_AccessStmt(OtherSpecificationStmt->term, &AccessStmt)) {
      // MATCHED AccessStmt
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_InternalSubprogram(ATerm term, pOFP_Traverse InternalSubprogram)
{
#ifdef DEBUG_PRINT
   printf("InternalSubprogram: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "InternalSubprogram(<term>)", &InternalSubprogram->term)) {
//....... ofp_uniqueSymbol: "SubroutineSubprogram"
   OFP_Traverse SubroutineSubprogram;
   if (ofp_traverse_SubroutineSubprogram(InternalSubprogram->term, &SubroutineSubprogram)) {
      // MATCHED SubroutineSubprogram
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "FunctionSubprogram"
   OFP_Traverse FunctionSubprogram;
   if (ofp_traverse_FunctionSubprogram(InternalSubprogram->term, &FunctionSubprogram)) {
      // MATCHED FunctionSubprogram
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_InternalSubprogramPart(ATerm term, pOFP_Traverse InternalSubprogramPart)
{
#ifdef DEBUG_PRINT
   printf("InternalSubprogramPart: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "InternalSubprogramPart(<term>)", &InternalSubprogramPart->term)) {
//....... ofp_uniqueSymbol: "ContainsStmt"
   OFP_Traverse ContainsStmt;
   if (ofp_traverse_ContainsStmt(InternalSubprogramPart->term, &ContainsStmt)) {
      // MATCHED ContainsStmt
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ExecutionPartConstruct(ATerm term, pOFP_Traverse ExecutionPartConstruct)
{
#ifdef DEBUG_PRINT
   printf("ExecutionPartConstruct: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ExecutionPartConstruct(<term>)", &ExecutionPartConstruct->term)) {
//....... ofp_uniqueSymbol: "DataStmt"
   OFP_Traverse DataStmt;
   if (ofp_traverse_DataStmt(ExecutionPartConstruct->term, &DataStmt)) {
      // MATCHED DataStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "EntryStmt"
   OFP_Traverse EntryStmt;
   if (ofp_traverse_EntryStmt(ExecutionPartConstruct->term, &EntryStmt)) {
      // MATCHED EntryStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "FormatStmt"
   OFP_Traverse FormatStmt;
   if (ofp_traverse_FormatStmt(ExecutionPartConstruct->term, &FormatStmt)) {
      // MATCHED FormatStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "ExecutableConstruct"
   OFP_Traverse ExecutableConstruct;
   if (ofp_traverse_ExecutableConstruct(ExecutionPartConstruct->term, &ExecutableConstruct)) {
      // MATCHED ExecutableConstruct
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ExecutionPart(ATerm term, pOFP_Traverse ExecutionPart)
{
#ifdef DEBUG_PRINT
   printf("ExecutionPart: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ExecutionPart(<term>)", &ExecutionPart->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_DeclarationConstruct(ATerm term, pOFP_Traverse DeclarationConstruct)
{
#ifdef DEBUG_PRINT
   printf("DeclarationConstruct: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DeclarationConstruct(<term>)", &DeclarationConstruct->term)) {
//....... ofp_uniqueSymbol: "StmtFunctionStmt"
   OFP_Traverse StmtFunctionStmt;
   if (ofp_traverse_StmtFunctionStmt(DeclarationConstruct->term, &StmtFunctionStmt)) {
      // MATCHED StmtFunctionStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "TypeDeclarationStmt"
   OFP_Traverse TypeDeclarationStmt;
   if (ofp_traverse_TypeDeclarationStmt(DeclarationConstruct->term, &TypeDeclarationStmt)) {
      // MATCHED TypeDeclarationStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "OtherSpecificationStmt"
   OFP_Traverse OtherSpecificationStmt;
   if (ofp_traverse_OtherSpecificationStmt(DeclarationConstruct->term, &OtherSpecificationStmt)) {
      // MATCHED OtherSpecificationStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "ProcedureDeclarationStmt"
   OFP_Traverse ProcedureDeclarationStmt;
   if (ofp_traverse_ProcedureDeclarationStmt(DeclarationConstruct->term, &ProcedureDeclarationStmt)) {
      // MATCHED ProcedureDeclarationStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "ParameterStmt"
   OFP_Traverse ParameterStmt;
   if (ofp_traverse_ParameterStmt(DeclarationConstruct->term, &ParameterStmt)) {
      // MATCHED ParameterStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "InterfaceBlock"
   OFP_Traverse InterfaceBlock;
   if (ofp_traverse_InterfaceBlock(DeclarationConstruct->term, &InterfaceBlock)) {
      // MATCHED InterfaceBlock
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "FormatStmt"
   OFP_Traverse FormatStmt;
   if (ofp_traverse_FormatStmt(DeclarationConstruct->term, &FormatStmt)) {
      // MATCHED FormatStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "EnumDef"
   OFP_Traverse EnumDef;
   if (ofp_traverse_EnumDef(DeclarationConstruct->term, &EnumDef)) {
      // MATCHED EnumDef
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "EntryStmt"
   OFP_Traverse EntryStmt;
   if (ofp_traverse_EntryStmt(DeclarationConstruct->term, &EntryStmt)) {
      // MATCHED EntryStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "DerivedTypeDef"
   OFP_Traverse DerivedTypeDef;
   if (ofp_traverse_DerivedTypeDef(DeclarationConstruct->term, &DerivedTypeDef)) {
      // MATCHED DerivedTypeDef
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ImplicitPartStmt(ATerm term, pOFP_Traverse ImplicitPartStmt)
{
#ifdef DEBUG_PRINT
   printf("ImplicitPartStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ImplicitPartStmt(<term>)", &ImplicitPartStmt->term)) {
//....... ofp_uniqueSymbol: "EntryStmt"
   OFP_Traverse EntryStmt;
   if (ofp_traverse_EntryStmt(ImplicitPartStmt->term, &EntryStmt)) {
      // MATCHED EntryStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "FormatStmt"
   OFP_Traverse FormatStmt;
   if (ofp_traverse_FormatStmt(ImplicitPartStmt->term, &FormatStmt)) {
      // MATCHED FormatStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "ParameterStmt"
   OFP_Traverse ParameterStmt;
   if (ofp_traverse_ParameterStmt(ImplicitPartStmt->term, &ParameterStmt)) {
      // MATCHED ParameterStmt
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "ImplicitStmt"
   OFP_Traverse ImplicitStmt;
   if (ofp_traverse_ImplicitStmt(ImplicitPartStmt->term, &ImplicitStmt)) {
      // MATCHED ImplicitStmt
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ImplicitPart(ATerm term, pOFP_Traverse ImplicitPart)
{
#ifdef DEBUG_PRINT
   printf("ImplicitPart: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ImplicitPart(<term>)", &ImplicitPart->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_SpecificationPart(ATerm term, pOFP_Traverse SpecificationPart)
{
#ifdef DEBUG_PRINT
   printf("SpecificationPart: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "SpecificationPart(<term>)", &SpecificationPart->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_ExternalSubprogram(ATerm term, pOFP_Traverse ExternalSubprogram)
{
#ifdef DEBUG_PRINT
   printf("ExternalSubprogram: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ExternalSubprogram(<term>)", &ExternalSubprogram->term)) {
//....... ofp_uniqueSymbol: "SubroutineSubprogram"
   OFP_Traverse SubroutineSubprogram;
   if (ofp_traverse_SubroutineSubprogram(ExternalSubprogram->term, &SubroutineSubprogram)) {
      // MATCHED SubroutineSubprogram
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "FunctionSubprogram"
   OFP_Traverse FunctionSubprogram;
   if (ofp_traverse_FunctionSubprogram(ExternalSubprogram->term, &FunctionSubprogram)) {
      // MATCHED FunctionSubprogram
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ProgramUnit(ATerm term, pOFP_Traverse ProgramUnit)
{
#ifdef DEBUG_PRINT
   printf("ProgramUnit: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ProgramUnit(<term>)", &ProgramUnit->term)) {
//....... ofp_uniqueSymbol: "BlockData"
#ifdef NOT_YET
   OFP_Traverse BlockData;
   if (ofp_traverse_BlockData(ProgramUnit->term, &BlockData)) {
      // MATCHED BlockData
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "Submodule"
   OFP_Traverse Submodule;
   if (ofp_traverse_Submodule(ProgramUnit->term, &Submodule)) {
      // MATCHED Submodule
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "Module"
   OFP_Traverse Module;
   if (ofp_traverse_Module(ProgramUnit->term, &Module)) {
      // MATCHED Module
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "ExternalSubprogram"
   OFP_Traverse ExternalSubprogram;
   if (ofp_traverse_ExternalSubprogram(ProgramUnit->term, &ExternalSubprogram)) {
      // MATCHED ExternalSubprogram
      return ATtrue;
   } 
#endif
//....... ofp_uniqueSymbol: "MainProgram"
   OFP_Traverse MainProgram;
   if (ofp_traverse_MainProgram(ProgramUnit->term, &MainProgram)) {
      // MATCHED MainProgram
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_Program(ATerm term, pOFP_Traverse Program)
{
#ifdef DEBUG_PRINT
   printf("Program: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "Program(<term>)", &Program->term)) {
//....... ofp_uniqueSymbol: "StartCommentBlock"
   OFP_Traverse StartCommentBlock;
   if (ofp_traverse_StartCommentBlock(Program->term, &StartCommentBlock)) {
      // MATCHED StartCommentBlock
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_UseName(ATerm term, pOFP_Traverse UseName)
{
#ifdef DEBUG_PRINT
   printf("UseName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "UseName(<term>)", &UseName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(UseName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_SubmoduleName(ATerm term, pOFP_Traverse SubmoduleName)
{
#ifdef DEBUG_PRINT
   printf("SubmoduleName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "SubmoduleName(<term>)", &SubmoduleName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(SubmoduleName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ParentSubmoduleName(ATerm term, pOFP_Traverse ParentSubmoduleName)
{
#ifdef DEBUG_PRINT
   printf("ParentSubmoduleName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ParentSubmoduleName(<term>)", &ParentSubmoduleName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(ParentSubmoduleName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ModuleName(ATerm term, pOFP_Traverse ModuleName)
{
#ifdef DEBUG_PRINT
   printf("ModuleName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ModuleName(<term>)", &ModuleName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(ModuleName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_LocalName(ATerm term, pOFP_Traverse LocalName)
{
#ifdef DEBUG_PRINT
   printf("LocalName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "LocalName(<term>)", &LocalName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(LocalName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_BlockDataName(ATerm term, pOFP_Traverse BlockDataName)
{
#ifdef DEBUG_PRINT
   printf("BlockDataName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "BlockDataName(<term>)", &BlockDataName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(BlockDataName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_AncestorModuleName(ATerm term, pOFP_Traverse AncestorModuleName)
{
#ifdef DEBUG_PRINT
   printf("AncestorModuleName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AncestorModuleName(<term>)", &AncestorModuleName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(AncestorModuleName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_CharStringEditDesc(ATerm term, pOFP_Traverse CharStringEditDesc)
{
#ifdef DEBUG_PRINT
   printf("CharStringEditDesc: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "CharStringEditDesc(<term>)", &CharStringEditDesc->term)) {
//....... ofp_uniqueSymbol: "Scon"
   OFP_Traverse Scon;
   if (ofp_traverse_Scon(CharStringEditDesc->term, &Scon)) {
      // MATCHED Scon
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_DecimalEditDesc(ATerm term, pOFP_Traverse DecimalEditDesc)
{
#ifdef DEBUG_PRINT
   printf("DecimalEditDesc: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DecimalEditDesc(<term>)", &DecimalEditDesc->term)) {
 }

   if (ATmatch(term, "DecimalEditDesc_DP")) {
      // MATCHED DecimalEditDesc_DP
      return ATtrue;
   }

   if (ATmatch(term, "DecimalEditDesc_DC")) {
      // MATCHED DecimalEditDesc_DC
      return ATtrue;
   }

   return ATfalse;
}

ATbool ofp_traverse_RoundEditDesc(ATerm term, pOFP_Traverse RoundEditDesc)
{
#ifdef DEBUG_PRINT
   printf("RoundEditDesc: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "RoundEditDesc(<term>)", &RoundEditDesc->term)) {
 }

   if (ATmatch(term, "RoundEditDesc_RP")) {
      // MATCHED RoundEditDesc_RP
      return ATtrue;
   }

   if (ATmatch(term, "RoundEditDesc_RC")) {
      // MATCHED RoundEditDesc_RC
      return ATtrue;
   }

   if (ATmatch(term, "RoundEditDesc_RN")) {
      // MATCHED RoundEditDesc_RN
      return ATtrue;
   }

   if (ATmatch(term, "RoundEditDesc_RZ")) {
      // MATCHED RoundEditDesc_RZ
      return ATtrue;
   }

   if (ATmatch(term, "RoundEditDesc_RD")) {
      // MATCHED RoundEditDesc_RD
      return ATtrue;
   }

   if (ATmatch(term, "RoundEditDesc_RU")) {
      // MATCHED RoundEditDesc_RU
      return ATtrue;
   }

   return ATfalse;
}

ATbool ofp_traverse_BlankInterpEditDesc(ATerm term, pOFP_Traverse BlankInterpEditDesc)
{
#ifdef DEBUG_PRINT
   printf("BlankInterpEditDesc: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "BlankInterpEditDesc(<term>)", &BlankInterpEditDesc->term)) {
 }

   if (ATmatch(term, "BlonkInterpEditDesc_BZ")) {
      // MATCHED BlonkInterpEditDesc_BZ
      return ATtrue;
   }

   if (ATmatch(term, "BlonkInterpEditDesc_BN")) {
      // MATCHED BlonkInterpEditDesc_BN
      return ATtrue;
   }

   return ATfalse;
}

ATbool ofp_traverse_SignEditDesc(ATerm term, pOFP_Traverse SignEditDesc)
{
#ifdef DEBUG_PRINT
   printf("SignEditDesc: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "SignEditDesc(<term>)", &SignEditDesc->term)) {
 }

   if (ATmatch(term, "SignEditDesc_S")) {
      // MATCHED SignEditDesc_S
      return ATtrue;
   }

   if (ATmatch(term, "SignEditDesc_SP")) {
      // MATCHED SignEditDesc_SP
      return ATtrue;
   }

   if (ATmatch(term, "SignEditDesc_SS")) {
      // MATCHED SignEditDesc_SS
      return ATtrue;
   }

   return ATfalse;
}

ATbool ofp_traverse_NEditDesc(ATerm term, pOFP_Traverse NEditDesc)
{
#ifdef DEBUG_PRINT
   printf("NEditDesc: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "NEditDesc(<term>)", &NEditDesc->term)) {
 }

//....... ofp_uniqueSymbol: "Icon"
   OFP_Traverse Icon;
   if (ATmatch(term, "N(<term>)", &Icon.term)) {
      if (ofp_traverse_Icon(Icon.term, &Icon)) {
         // MATCHED Icon
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_PositionEditDesc(ATerm term, pOFP_Traverse PositionEditDesc)
{
#ifdef DEBUG_PRINT
   printf("PositionEditDesc: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "PositionEditDesc(<term>)", &PositionEditDesc->term)) {
 }

//....... ofp_uniqueSymbol: "NEditDesc"
   OFP_Traverse NEditDesc;
   if (ATmatch(term, "PositionEditDesc_X(<term>)", &NEditDesc.term)) {
      if (ofp_traverse_NEditDesc(NEditDesc.term, &NEditDesc)) {
         // MATCHED NEditDesc
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "NEditDesc"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "NEditDesc1"
   OFP_Traverse NEditDesc1;
   if (ATmatch(term, "PositionEditDesc_TR(<term>)", &NEditDesc1.term)) {
      if (ofp_traverse_NEditDesc(NEditDesc1.term, &NEditDesc1)) {
         // MATCHED NEditDesc
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "NEditDesc"
//.......       from table: 1
//.......               id: 2
//.......       unique sym: "NEditDesc2"
   OFP_Traverse NEditDesc2;
   if (ATmatch(term, "PositionEditDesc_TL(<term>)", &NEditDesc2.term)) {
      if (ofp_traverse_NEditDesc(NEditDesc2.term, &NEditDesc2)) {
         // MATCHED NEditDesc
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "NEditDesc"
//.......       from table: 2
//.......               id: 3
//.......       unique sym: "NEditDesc3"
   OFP_Traverse NEditDesc3;
   if (ATmatch(term, "PositionEditDesc_T(<term>)", &NEditDesc3.term)) {
      if (ofp_traverse_NEditDesc(NEditDesc3.term, &NEditDesc3)) {
         // MATCHED NEditDesc
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_KEditDesc(ATerm term, pOFP_Traverse KEditDesc)
{
#ifdef DEBUG_PRINT
   printf("KEditDesc: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "KEditDesc(<term>)", &KEditDesc->term)) {
 }

//....... ofp_uniqueSymbol: "SignedIntLiteralConstant"
   OFP_Traverse SignedIntLiteralConstant;
   if (ATmatch(term, "K(<term>)", &SignedIntLiteralConstant.term)) {
      if (ofp_traverse_SignedIntLiteralConstant(SignedIntLiteralConstant.term, &SignedIntLiteralConstant)) {
         // MATCHED SignedIntLiteralConstant
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_ControlEditDesc(ATerm term, pOFP_Traverse ControlEditDesc)
{
#ifdef DEBUG_PRINT
   printf("ControlEditDesc: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ControlEditDesc(<term>)", &ControlEditDesc->term)) {
 }

//....... ofp_uniqueSymbol: "DecimalEditDesc"
   OFP_Traverse DecimalEditDesc;
   if (ATmatch(term, "ControlEditDesc_alt8(<term>)", &DecimalEditDesc.term)) {
      if (ofp_traverse_DecimalEditDesc(DecimalEditDesc.term, &DecimalEditDesc)) {
         // MATCHED DecimalEditDesc
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "RoundEditDesc"
   OFP_Traverse RoundEditDesc;
   if (ATmatch(term, "ControlEditDesc_alt7(<term>)", &RoundEditDesc.term)) {
      if (ofp_traverse_RoundEditDesc(RoundEditDesc.term, &RoundEditDesc)) {
         // MATCHED RoundEditDesc
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "BlankInterpEditDesc"
   OFP_Traverse BlankInterpEditDesc;
   if (ATmatch(term, "ControlEditDesc_alt6(<term>)", &BlankInterpEditDesc.term)) {
      if (ofp_traverse_BlankInterpEditDesc(BlankInterpEditDesc.term, &BlankInterpEditDesc)) {
         // MATCHED BlankInterpEditDesc
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "KEditDesc"
   OFP_Traverse KEditDesc;
   if (ATmatch(term, "ControlEditDesc_alt5(<term>)", &KEditDesc.term)) {
      if (ofp_traverse_KEditDesc(KEditDesc.term, &KEditDesc)) {
         // MATCHED KEditDesc
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "SignEditDesc"
   OFP_Traverse SignEditDesc;
   if (ATmatch(term, "ControlEditDesc_alt4(<term>)", &SignEditDesc.term)) {
      if (ofp_traverse_SignEditDesc(SignEditDesc.term, &SignEditDesc)) {
         // MATCHED SignEditDesc
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "PositionEditDesc"
   OFP_Traverse PositionEditDesc;
   if (ATmatch(term, "ControlEditDesc_alt1(<term>)", &PositionEditDesc.term)) {
      if (ofp_traverse_PositionEditDesc(PositionEditDesc.term, &PositionEditDesc)) {
         // MATCHED PositionEditDesc
         return ATtrue;
      } else return ATfalse;
   }

   if (ATmatch(term, "ControlEditDesc_alt3")) {
      // MATCHED ControlEditDesc_alt3
      return ATtrue;
   }

   return ATfalse;
}

ATbool ofp_traverse_VEditDescList(ATerm term, pOFP_Traverse VEditDescList)
{
#ifdef DEBUG_PRINT
   printf("VEditDescList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "VEditDescList(<term>)", &VEditDescList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_VEditDesc(ATerm term, pOFP_Traverse VEditDesc)
{
#ifdef DEBUG_PRINT
   printf("VEditDesc: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "VEditDesc(<term>)", &VEditDesc->term)) {
 }

//....... ofp_uniqueSymbol: "Icon"
   OFP_Traverse Icon;
   if (ATmatch(term, "V(<term>)", &Icon.term)) {
      if (ofp_traverse_Icon(Icon.term, &Icon)) {
         // MATCHED Icon
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_EEditDesc(ATerm term, pOFP_Traverse EEditDesc)
{
#ifdef DEBUG_PRINT
   printf("EEditDesc: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EEditDesc(<term>)", &EEditDesc->term)) {
 }

//....... ofp_uniqueSymbol: "Icon"
   OFP_Traverse Icon;
   if (ATmatch(term, "E(<term>)", &Icon.term)) {
      if (ofp_traverse_Icon(Icon.term, &Icon)) {
         // MATCHED Icon
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_DEditDesc(ATerm term, pOFP_Traverse DEditDesc)
{
#ifdef DEBUG_PRINT
   printf("DEditDesc: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DEditDesc(<term>)", &DEditDesc->term)) {
 }

//....... ofp_uniqueSymbol: "Icon"
   OFP_Traverse Icon;
   if (ATmatch(term, "D(<term>)", &Icon.term)) {
      if (ofp_traverse_Icon(Icon.term, &Icon)) {
         // MATCHED Icon
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_MEditDesc(ATerm term, pOFP_Traverse MEditDesc)
{
#ifdef DEBUG_PRINT
   printf("MEditDesc: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "MEditDesc(<term>)", &MEditDesc->term)) {
 }

//....... ofp_uniqueSymbol: "Icon"
   OFP_Traverse Icon;
   if (ATmatch(term, "M(<term>)", &Icon.term)) {
      if (ofp_traverse_Icon(Icon.term, &Icon)) {
         // MATCHED Icon
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_WEditDesc(ATerm term, pOFP_Traverse WEditDesc)
{
#ifdef DEBUG_PRINT
   printf("WEditDesc: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "WEditDesc(<term>)", &WEditDesc->term)) {
 }

//....... ofp_uniqueSymbol: "Icon"
   OFP_Traverse Icon;
   if (ATmatch(term, "W(<term>)", &Icon.term)) {
      if (ofp_traverse_Icon(Icon.term, &Icon)) {
         // MATCHED Icon
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_DataEditDesc(ATerm term, pOFP_Traverse DataEditDesc)
{
#ifdef DEBUG_PRINT
   printf("DataEditDesc: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DataEditDesc(<term>)", &DataEditDesc->term)) {
 }

//....... ofp_uniqueSymbol: "WEditDesc"
   OFP_Traverse WEditDesc;
   if (ATmatch(term, "DataEditDesc_D(<term>)", &WEditDesc.term)) {
      if (ofp_traverse_WEditDesc(WEditDesc.term, &WEditDesc)) {
         // MATCHED WEditDesc
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DEditDesc"
   OFP_Traverse DEditDesc;
   if (ATmatch(term, "DataEditDesc_D(<term>)", &DEditDesc.term)) {
      if (ofp_traverse_DEditDesc(DEditDesc.term, &DEditDesc)) {
         // MATCHED DEditDesc
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "WEditDesc"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "WEditDesc1"
   OFP_Traverse WEditDesc1;
   if (ATmatch(term, "DataEditDesc_L(<term>)", &WEditDesc1.term)) {
      if (ofp_traverse_WEditDesc(WEditDesc1.term, &WEditDesc1)) {
         // MATCHED WEditDesc
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "WEditDesc"
//.......       from table: 1
//.......               id: 2
//.......       unique sym: "WEditDesc2"
   OFP_Traverse WEditDesc2;
   if (ATmatch(term, "DataEditDesc_G(<term>)", &WEditDesc2.term)) {
      if (ofp_traverse_WEditDesc(WEditDesc2.term, &WEditDesc2)) {
         // MATCHED WEditDesc
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "WEditDesc"
//.......       from table: 2
//.......               id: 3
//.......       unique sym: "WEditDesc3"
   OFP_Traverse WEditDesc3;
   if (ATmatch(term, "DataEditDesc_ES(<term>)", &WEditDesc3.term)) {
      if (ofp_traverse_WEditDesc(WEditDesc3.term, &WEditDesc3)) {
         // MATCHED WEditDesc
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DEditDesc"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "DEditDesc1"
   OFP_Traverse DEditDesc1;
   if (ATmatch(term, "DataEditDesc_ES(<term>)", &DEditDesc1.term)) {
      if (ofp_traverse_DEditDesc(DEditDesc1.term, &DEditDesc1)) {
         // MATCHED DEditDesc
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "WEditDesc"
//.......       from table: 3
//.......               id: 4
//.......       unique sym: "WEditDesc4"
   OFP_Traverse WEditDesc4;
   if (ATmatch(term, "DataEditDesc_EN(<term>)", &WEditDesc4.term)) {
      if (ofp_traverse_WEditDesc(WEditDesc4.term, &WEditDesc4)) {
         // MATCHED WEditDesc
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DEditDesc"
//.......       from table: 1
//.......               id: 2
//.......       unique sym: "DEditDesc2"
   OFP_Traverse DEditDesc2;
   if (ATmatch(term, "DataEditDesc_EN(<term>)", &DEditDesc2.term)) {
      if (ofp_traverse_DEditDesc(DEditDesc2.term, &DEditDesc2)) {
         // MATCHED DEditDesc
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "WEditDesc"
//.......       from table: 4
//.......               id: 5
//.......       unique sym: "WEditDesc5"
   OFP_Traverse WEditDesc5;
   if (ATmatch(term, "DataEditDesc_E(<term>)", &WEditDesc5.term)) {
      if (ofp_traverse_WEditDesc(WEditDesc5.term, &WEditDesc5)) {
         // MATCHED WEditDesc
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DEditDesc"
//.......       from table: 2
//.......               id: 3
//.......       unique sym: "DEditDesc3"
   OFP_Traverse DEditDesc3;
   if (ATmatch(term, "DataEditDesc_E(<term>)", &DEditDesc3.term)) {
      if (ofp_traverse_DEditDesc(DEditDesc3.term, &DEditDesc3)) {
         // MATCHED DEditDesc
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "WEditDesc"
//.......       from table: 5
//.......               id: 6
//.......       unique sym: "WEditDesc6"
   OFP_Traverse WEditDesc6;
   if (ATmatch(term, "DataEditDesc_F(<term>)", &WEditDesc6.term)) {
      if (ofp_traverse_WEditDesc(WEditDesc6.term, &WEditDesc6)) {
         // MATCHED WEditDesc
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DEditDesc"
//.......       from table: 3
//.......               id: 4
//.......       unique sym: "DEditDesc4"
   OFP_Traverse DEditDesc4;
   if (ATmatch(term, "DataEditDesc_F(<term>)", &DEditDesc4.term)) {
      if (ofp_traverse_DEditDesc(DEditDesc4.term, &DEditDesc4)) {
         // MATCHED DEditDesc
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "WEditDesc"
//.......       from table: 6
//.......               id: 7
//.......       unique sym: "WEditDesc7"
   OFP_Traverse WEditDesc7;
   if (ATmatch(term, "DataEditDesc_Z(<term>)", &WEditDesc7.term)) {
      if (ofp_traverse_WEditDesc(WEditDesc7.term, &WEditDesc7)) {
         // MATCHED WEditDesc
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "WEditDesc"
//.......       from table: 7
//.......               id: 8
//.......       unique sym: "WEditDesc8"
   OFP_Traverse WEditDesc8;
   if (ATmatch(term, "DataEditDesc_O(<term>)", &WEditDesc8.term)) {
      if (ofp_traverse_WEditDesc(WEditDesc8.term, &WEditDesc8)) {
         // MATCHED WEditDesc
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "WEditDesc"
//.......       from table: 8
//.......               id: 9
//.......       unique sym: "WEditDesc9"
   OFP_Traverse WEditDesc9;
   if (ATmatch(term, "DataEditDesc_B(<term>)", &WEditDesc9.term)) {
      if (ofp_traverse_WEditDesc(WEditDesc9.term, &WEditDesc9)) {
         // MATCHED WEditDesc
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "WEditDesc"
//.......       from table: 9
//.......               id: 10
//.......       unique sym: "WEditDesc10"
   OFP_Traverse WEditDesc10;
   if (ATmatch(term, "DataEditDesc_I(<term>)", &WEditDesc10.term)) {
      if (ofp_traverse_WEditDesc(WEditDesc10.term, &WEditDesc10)) {
         // MATCHED WEditDesc
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_REditDesc(ATerm term, pOFP_Traverse REditDesc)
{
#ifdef DEBUG_PRINT
   printf("REditDesc: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "REditDesc(<term>)", &REditDesc->term)) {
 }

//....... ofp_uniqueSymbol: "Icon"
   OFP_Traverse Icon;
   if (ATmatch(term, "R(<term>)", &Icon.term)) {
      if (ofp_traverse_Icon(Icon.term, &Icon)) {
         // MATCHED Icon
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_UnlimitedFormatItem(ATerm term, pOFP_Traverse UnlimitedFormatItem)
{
#ifdef DEBUG_PRINT
   printf("UnlimitedFormatItem: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "UnlimitedFormatItem(<term>)", &UnlimitedFormatItem->term)) {
//....... ofp_uniqueSymbol: "FormatItems"
   OFP_Traverse FormatItems;
   if (ofp_traverse_FormatItems(UnlimitedFormatItem->term, &FormatItems)) {
      // MATCHED FormatItems
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_FormatItem(ATerm term, pOFP_Traverse FormatItem)
{
#ifdef DEBUG_PRINT
   printf("FormatItem: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "FormatItem(<term>)", &FormatItem->term)) {
 }

//....... ofp_uniqueSymbol: "FormatItems"
   OFP_Traverse FormatItems;
   if (ATmatch(term, "FormatItem_alt4(<term>)", &FormatItems.term)) {
      if (ofp_traverse_FormatItems(FormatItems.term, &FormatItems)) {
         // MATCHED FormatItems
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "CharStringEditDesc"
   OFP_Traverse CharStringEditDesc;
   if (ATmatch(term, "FormatItem_alt3(<term>)", &CharStringEditDesc.term)) {
      if (ofp_traverse_CharStringEditDesc(CharStringEditDesc.term, &CharStringEditDesc)) {
         // MATCHED CharStringEditDesc
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "ControlEditDesc"
   OFP_Traverse ControlEditDesc;
   if (ATmatch(term, "FormatItem_alt2(<term>)", &ControlEditDesc.term)) {
      if (ofp_traverse_ControlEditDesc(ControlEditDesc.term, &ControlEditDesc)) {
         // MATCHED ControlEditDesc
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DataEditDesc"
   OFP_Traverse DataEditDesc;
   if (ATmatch(term, "FormatItem_alt1(<term>)", &DataEditDesc.term)) {
      if (ofp_traverse_DataEditDesc(DataEditDesc.term, &DataEditDesc)) {
         // MATCHED DataEditDesc
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_FormatItems(ATerm term, pOFP_Traverse FormatItems)
{
#ifdef DEBUG_PRINT
   printf("FormatItems: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "FormatItems(<term>)", &FormatItems->term)) {
//....... ofp_uniqueSymbol: "FormatItem"
   OFP_Traverse FormatItem;
   if (ofp_traverse_FormatItem(FormatItems->term, &FormatItem)) {
      // MATCHED FormatItem
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_FormatSpecification(ATerm term, pOFP_Traverse FormatSpecification)
{
#ifdef DEBUG_PRINT
   printf("FormatSpecification: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "FormatSpecification(<term>)", &FormatSpecification->term)) {
 }

//....... ofp_uniqueSymbol: "UnlimitedFormatItem"
   OFP_Traverse UnlimitedFormatItem;
   if (ATmatch(term, "FormatSpecification_alt2(<term>)", &UnlimitedFormatItem.term)) {
      if (ofp_traverse_UnlimitedFormatItem(UnlimitedFormatItem.term, &UnlimitedFormatItem)) {
         // MATCHED UnlimitedFormatItem
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_FormatStmt(ATerm term, pOFP_Traverse FormatStmt)
{
#ifdef DEBUG_PRINT
   printf("FormatStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "FormatStmt(<term>)", &FormatStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(FormatStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_InquireSpecList(ATerm term, pOFP_Traverse InquireSpecList)
{
#ifdef DEBUG_PRINT
   printf("InquireSpecList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "InquireSpecList(<term>)", &InquireSpecList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_InquireSpec(ATerm term, pOFP_Traverse InquireSpec)
{
#ifdef DEBUG_PRINT
   printf("InquireSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "InquireSpec(<term>)", &InquireSpec->term)) {
 }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
   OFP_Traverse DefaultCharExpr;
   if (ATmatch(term, "InquireSpec_WRITE(<term>)", &DefaultCharExpr.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr.term, &DefaultCharExpr)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "DefaultCharExpr1"
   OFP_Traverse DefaultCharExpr1;
   if (ATmatch(term, "InquireSpec_UNFORMATTED(<term>)", &DefaultCharExpr1.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr1.term, &DefaultCharExpr1)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 1
//.......               id: 2
//.......       unique sym: "DefaultCharExpr2"
   OFP_Traverse DefaultCharExpr2;
   if (ATmatch(term, "InquireSpec_STREAM(<term>)", &DefaultCharExpr2.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr2.term, &DefaultCharExpr2)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "IntVariable"
   OFP_Traverse IntVariable;
   if (ATmatch(term, "InquireSpec_SIZE(<term>)", &IntVariable.term)) {
      if (ofp_traverse_IntVariable(IntVariable.term, &IntVariable)) {
         // MATCHED IntVariable
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 2
//.......               id: 3
//.......       unique sym: "DefaultCharExpr3"
   OFP_Traverse DefaultCharExpr3;
   if (ATmatch(term, "InquireSpec_SIGN(<term>)", &DefaultCharExpr3.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr3.term, &DefaultCharExpr3)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 3
//.......               id: 4
//.......       unique sym: "DefaultCharExpr4"
   OFP_Traverse DefaultCharExpr4;
   if (ATmatch(term, "InquireSpec_SEQUENTIAL(<term>)", &DefaultCharExpr4.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr4.term, &DefaultCharExpr4)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 4
//.......               id: 5
//.......       unique sym: "DefaultCharExpr5"
   OFP_Traverse DefaultCharExpr5;
   if (ATmatch(term, "InquireSpec_ROUND(<term>)", &DefaultCharExpr5.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr5.term, &DefaultCharExpr5)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "IntVariable"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "IntVariable1"
   OFP_Traverse IntVariable1;
   if (ATmatch(term, "InquireSpec_RECL(<term>)", &IntVariable1.term)) {
      if (ofp_traverse_IntVariable(IntVariable1.term, &IntVariable1)) {
         // MATCHED IntVariable
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 5
//.......               id: 6
//.......       unique sym: "DefaultCharExpr6"
   OFP_Traverse DefaultCharExpr6;
   if (ATmatch(term, "InquireSpec_READWRITE(<term>)", &DefaultCharExpr6.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr6.term, &DefaultCharExpr6)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 6
//.......               id: 7
//.......       unique sym: "DefaultCharExpr7"
   OFP_Traverse DefaultCharExpr7;
   if (ATmatch(term, "InquireSpec_READ(<term>)", &DefaultCharExpr7.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr7.term, &DefaultCharExpr7)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 7
//.......               id: 8
//.......       unique sym: "DefaultCharExpr8"
   OFP_Traverse DefaultCharExpr8;
   if (ATmatch(term, "InquireSpec_POSITION(<term>)", &DefaultCharExpr8.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr8.term, &DefaultCharExpr8)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "IntVariable"
//.......       from table: 1
//.......               id: 2
//.......       unique sym: "IntVariable2"
   OFP_Traverse IntVariable2;
   if (ATmatch(term, "InquireSpec_POS(<term>)", &IntVariable2.term)) {
      if (ofp_traverse_IntVariable(IntVariable2.term, &IntVariable2)) {
         // MATCHED IntVariable
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "LogicalVariable"
   OFP_Traverse LogicalVariable;
   if (ATmatch(term, "InquireSpec_PENDING(<term>)", &LogicalVariable.term)) {
      if (ofp_traverse_LogicalVariable(LogicalVariable.term, &LogicalVariable)) {
         // MATCHED LogicalVariable
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 8
//.......               id: 9
//.......       unique sym: "DefaultCharExpr9"
   OFP_Traverse DefaultCharExpr9;
   if (ATmatch(term, "InquireSpec_PAD(<term>)", &DefaultCharExpr9.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr9.term, &DefaultCharExpr9)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "LogicalVariable"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "LogicalVariable1"
   OFP_Traverse LogicalVariable1;
   if (ATmatch(term, "InquireSpec_OPENED(<term>)", &LogicalVariable1.term)) {
      if (ofp_traverse_LogicalVariable(LogicalVariable1.term, &LogicalVariable1)) {
         // MATCHED LogicalVariable
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "IntVariable"
//.......       from table: 2
//.......               id: 3
//.......       unique sym: "IntVariable3"
   OFP_Traverse IntVariable3;
   if (ATmatch(term, "InquireSpec_NUMBER(<term>)", &IntVariable3.term)) {
      if (ofp_traverse_IntVariable(IntVariable3.term, &IntVariable3)) {
         // MATCHED IntVariable
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "IntVariable"
//.......       from table: 3
//.......               id: 4
//.......       unique sym: "IntVariable4"
   OFP_Traverse IntVariable4;
   if (ATmatch(term, "InquireSpec_NEXTREC(<term>)", &IntVariable4.term)) {
      if (ofp_traverse_IntVariable(IntVariable4.term, &IntVariable4)) {
         // MATCHED IntVariable
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "LogicalVariable"
//.......       from table: 1
//.......               id: 2
//.......       unique sym: "LogicalVariable2"
   OFP_Traverse LogicalVariable2;
   if (ATmatch(term, "InquireSpec_NAMED(<term>)", &LogicalVariable2.term)) {
      if (ofp_traverse_LogicalVariable(LogicalVariable2.term, &LogicalVariable2)) {
         // MATCHED LogicalVariable
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 9
//.......               id: 10
//.......       unique sym: "DefaultCharExpr10"
   OFP_Traverse DefaultCharExpr10;
   if (ATmatch(term, "InquireSpec_NAME(<term>)", &DefaultCharExpr10.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr10.term, &DefaultCharExpr10)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "IntVariable"
//.......       from table: 4
//.......               id: 5
//.......       unique sym: "IntVariable5"
   OFP_Traverse IntVariable5;
   if (ATmatch(term, "InquireSpec_IOSTAT(<term>)", &IntVariable5.term)) {
      if (ofp_traverse_IntVariable(IntVariable5.term, &IntVariable5)) {
         // MATCHED IntVariable
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "IomsgVariable"
   OFP_Traverse IomsgVariable;
   if (ATmatch(term, "InquireSpec_IOMSG(<term>)", &IomsgVariable.term)) {
      if (ofp_traverse_IomsgVariable(IomsgVariable.term, &IomsgVariable)) {
         // MATCHED IomsgVariable
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "IntExpr"
   OFP_Traverse IntExpr;
   if (ATmatch(term, "InquireSpec_ID(<term>)", &IntExpr.term)) {
      if (ofp_traverse_IntExpr(IntExpr.term, &IntExpr)) {
         // MATCHED IntExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 10
//.......               id: 11
//.......       unique sym: "DefaultCharExpr11"
   OFP_Traverse DefaultCharExpr11;
   if (ATmatch(term, "InquireSpec_FORMATTED(<term>)", &DefaultCharExpr11.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr11.term, &DefaultCharExpr11)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 11
//.......               id: 12
//.......       unique sym: "DefaultCharExpr12"
   OFP_Traverse DefaultCharExpr12;
   if (ATmatch(term, "InquireSpec_FORM(<term>)", &DefaultCharExpr12.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr12.term, &DefaultCharExpr12)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "LogicalVariable"
//.......       from table: 2
//.......               id: 3
//.......       unique sym: "LogicalVariable3"
   OFP_Traverse LogicalVariable3;
   if (ATmatch(term, "InquireSpec_EXIST(<term>)", &LogicalVariable3.term)) {
      if (ofp_traverse_LogicalVariable(LogicalVariable3.term, &LogicalVariable3)) {
         // MATCHED LogicalVariable
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "LblRef"
   OFP_Traverse LblRef;
   if (ATmatch(term, "InquireSpec_ERR(<term>)", &LblRef.term)) {
      if (ofp_traverse_LblRef(LblRef.term, &LblRef)) {
         // MATCHED LblRef
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 12
//.......               id: 13
//.......       unique sym: "DefaultCharExpr13"
   OFP_Traverse DefaultCharExpr13;
   if (ATmatch(term, "InquireSpec_ENCODING(<term>)", &DefaultCharExpr13.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr13.term, &DefaultCharExpr13)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 13
//.......               id: 14
//.......       unique sym: "DefaultCharExpr14"
   OFP_Traverse DefaultCharExpr14;
   if (ATmatch(term, "InquireSpec_DIRECT(<term>)", &DefaultCharExpr14.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr14.term, &DefaultCharExpr14)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 14
//.......               id: 15
//.......       unique sym: "DefaultCharExpr15"
   OFP_Traverse DefaultCharExpr15;
   if (ATmatch(term, "InquireSpec_DELIM(<term>)", &DefaultCharExpr15.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr15.term, &DefaultCharExpr15)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 15
//.......               id: 16
//.......       unique sym: "DefaultCharExpr16"
   OFP_Traverse DefaultCharExpr16;
   if (ATmatch(term, "InquireSpec_DECIMAL(<term>)", &DefaultCharExpr16.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr16.term, &DefaultCharExpr16)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 16
//.......               id: 17
//.......       unique sym: "DefaultCharExpr17"
   OFP_Traverse DefaultCharExpr17;
   if (ATmatch(term, "InquireSpec_BLANK(<term>)", &DefaultCharExpr17.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr17.term, &DefaultCharExpr17)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 17
//.......               id: 18
//.......       unique sym: "DefaultCharExpr18"
   OFP_Traverse DefaultCharExpr18;
   if (ATmatch(term, "InquireSpec_ASYNCHRONOUS(<term>)", &DefaultCharExpr18.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr18.term, &DefaultCharExpr18)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 18
//.......               id: 19
//.......       unique sym: "DefaultCharExpr19"
   OFP_Traverse DefaultCharExpr19;
   if (ATmatch(term, "InquireSpec_ACTION(<term>)", &DefaultCharExpr19.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr19.term, &DefaultCharExpr19)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 19
//.......               id: 20
//.......       unique sym: "DefaultCharExpr20"
   OFP_Traverse DefaultCharExpr20;
   if (ATmatch(term, "InquireSpec_ACCESS(<term>)", &DefaultCharExpr20.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr20.term, &DefaultCharExpr20)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "FileNameExpr"
   OFP_Traverse FileNameExpr;
   if (ATmatch(term, "InquireSpec_FILE(<term>)", &FileNameExpr.term)) {
      if (ofp_traverse_FileNameExpr(FileNameExpr.term, &FileNameExpr)) {
         // MATCHED FileNameExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "FileUnitNumber"
   OFP_Traverse FileUnitNumber;
   if (ATmatch(term, "InquireSpec_UNIT(<term>)", &FileUnitNumber.term)) {
      if (ofp_traverse_FileUnitNumber(FileUnitNumber.term, &FileUnitNumber)) {
         // MATCHED FileUnitNumber
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_InquireStmt(ATerm term, pOFP_Traverse InquireStmt)
{
#ifdef DEBUG_PRINT
   printf("InquireStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "InquireStmt(<term>)", &InquireStmt->term)) {
 }

//....... ofp_uniqueSymbol: "IntVariable"
   OFP_Traverse IntVariable;
   if (ATmatch(term, "InquireStmt_IOLENGTH(<term>)", &IntVariable.term)) {
      if (ofp_traverse_IntVariable(IntVariable.term, &IntVariable)) {
         // MATCHED IntVariable
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "OutputItemList"
   OFP_Traverse OutputItemList;
   if (ATmatch(term, "InquireStmt_IOLENGTH(<term>)", &OutputItemList.term)) {
      if (ofp_traverse_OutputItemList(OutputItemList.term, &OutputItemList)) {
         // MATCHED OutputItemList
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "EOS"
   OFP_Traverse EOS;
   if (ATmatch(term, "InquireStmt_IOLENGTH(<term>)", &EOS.term)) {
      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "InquireSpecList"
   OFP_Traverse InquireSpecList;
   if (ATmatch(term, "InquireStmt_ISL(<term>)", &InquireSpecList.term)) {
      if (ofp_traverse_InquireSpecList(InquireSpecList.term, &InquireSpecList)) {
         // MATCHED InquireSpecList
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "EOS"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "EOS1"
   OFP_Traverse EOS1;
   if (ATmatch(term, "InquireStmt_ISL(<term>)", &EOS1.term)) {
      if (ofp_traverse_EOS(EOS1.term, &EOS1)) {
         // MATCHED EOS
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_FlushSpecList(ATerm term, pOFP_Traverse FlushSpecList)
{
#ifdef DEBUG_PRINT
   printf("FlushSpecList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "FlushSpecList(<term>)", &FlushSpecList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_FlushSpec(ATerm term, pOFP_Traverse FlushSpec)
{
#ifdef DEBUG_PRINT
   printf("FlushSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "FlushSpec(<term>)", &FlushSpec->term)) {
 }

//....... ofp_uniqueSymbol: "LblRef"
   OFP_Traverse LblRef;
   if (ATmatch(term, "FlushSpec_ERR(<term>)", &LblRef.term)) {
      if (ofp_traverse_LblRef(LblRef.term, &LblRef)) {
         // MATCHED LblRef
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "IomsgVariable"
   OFP_Traverse IomsgVariable;
   if (ATmatch(term, "FlushSpec_IOMSG(<term>)", &IomsgVariable.term)) {
      if (ofp_traverse_IomsgVariable(IomsgVariable.term, &IomsgVariable)) {
         // MATCHED IomsgVariable
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "IntVariable"
   OFP_Traverse IntVariable;
   if (ATmatch(term, "FlushSpec_IOSTAT(<term>)", &IntVariable.term)) {
      if (ofp_traverse_IntVariable(IntVariable.term, &IntVariable)) {
         // MATCHED IntVariable
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "FileUnitNumber"
   OFP_Traverse FileUnitNumber;
   if (ATmatch(term, "FlushSpec_UNIT(<term>)", &FileUnitNumber.term)) {
      if (ofp_traverse_FileUnitNumber(FileUnitNumber.term, &FileUnitNumber)) {
         // MATCHED FileUnitNumber
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_FlushStmt(ATerm term, pOFP_Traverse FlushStmt)
{
#ifdef DEBUG_PRINT
   printf("FlushStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "FlushStmt(<term>)", &FlushStmt->term)) {
 }

//....... ofp_uniqueSymbol: "FlushSpecList"
   OFP_Traverse FlushSpecList;
   if (ATmatch(term, "FlushStmt_FSL(<term>)", &FlushSpecList.term)) {
      if (ofp_traverse_FlushSpecList(FlushSpecList.term, &FlushSpecList)) {
         // MATCHED FlushSpecList
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "EOS"
   OFP_Traverse EOS;
   if (ATmatch(term, "FlushStmt_FSL(<term>)", &EOS.term)) {
      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "FileUnitNumber"
   OFP_Traverse FileUnitNumber;
   if (ATmatch(term, "FlushStmt_FUN(<term>)", &FileUnitNumber.term)) {
      if (ofp_traverse_FileUnitNumber(FileUnitNumber.term, &FileUnitNumber)) {
         // MATCHED FileUnitNumber
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "EOS"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "EOS1"
   OFP_Traverse EOS1;
   if (ATmatch(term, "FlushStmt_FUN(<term>)", &EOS1.term)) {
      if (ofp_traverse_EOS(EOS1.term, &EOS1)) {
         // MATCHED EOS
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_PositionSpecList(ATerm term, pOFP_Traverse PositionSpecList)
{
#ifdef DEBUG_PRINT
   printf("PositionSpecList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "PositionSpecList(<term>)", &PositionSpecList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_PositionSpec(ATerm term, pOFP_Traverse PositionSpec)
{
#ifdef DEBUG_PRINT
   printf("PositionSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "PositionSpec(<term>)", &PositionSpec->term)) {
 }

//....... ofp_uniqueSymbol: "LblRef"
   OFP_Traverse LblRef;
   if (ATmatch(term, "PositionSpec_ERR(<term>)", &LblRef.term)) {
      if (ofp_traverse_LblRef(LblRef.term, &LblRef)) {
         // MATCHED LblRef
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "IomsgVariable"
   OFP_Traverse IomsgVariable;
   if (ATmatch(term, "PositionSpec_IOMSG(<term>)", &IomsgVariable.term)) {
      if (ofp_traverse_IomsgVariable(IomsgVariable.term, &IomsgVariable)) {
         // MATCHED IomsgVariable
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "IntVariable"
   OFP_Traverse IntVariable;
   if (ATmatch(term, "PositionSpec_IOSTAT(<term>)", &IntVariable.term)) {
      if (ofp_traverse_IntVariable(IntVariable.term, &IntVariable)) {
         // MATCHED IntVariable
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "FileUnitNumber"
   OFP_Traverse FileUnitNumber;
   if (ATmatch(term, "PositionSpec_UNIT(<term>)", &FileUnitNumber.term)) {
      if (ofp_traverse_FileUnitNumber(FileUnitNumber.term, &FileUnitNumber)) {
         // MATCHED FileUnitNumber
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_RewindStmt(ATerm term, pOFP_Traverse RewindStmt)
{
#ifdef DEBUG_PRINT
   printf("RewindStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "RewindStmt(<term>)", &RewindStmt->term)) {
 }

//....... ofp_uniqueSymbol: "PositionSpecList"
   OFP_Traverse PositionSpecList;
   if (ATmatch(term, "RewindStmt_PSL(<term>)", &PositionSpecList.term)) {
      if (ofp_traverse_PositionSpecList(PositionSpecList.term, &PositionSpecList)) {
         // MATCHED PositionSpecList
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "EOS"
   OFP_Traverse EOS;
   if (ATmatch(term, "RewindStmt_PSL(<term>)", &EOS.term)) {
      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "FileUnitNumber"
   OFP_Traverse FileUnitNumber;
   if (ATmatch(term, "RewindStmt_FUN(<term>)", &FileUnitNumber.term)) {
      if (ofp_traverse_FileUnitNumber(FileUnitNumber.term, &FileUnitNumber)) {
         // MATCHED FileUnitNumber
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "EOS"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "EOS1"
   OFP_Traverse EOS1;
   if (ATmatch(term, "RewindStmt_FUN(<term>)", &EOS1.term)) {
      if (ofp_traverse_EOS(EOS1.term, &EOS1)) {
         // MATCHED EOS
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_EndfileStmt(ATerm term, pOFP_Traverse EndfileStmt)
{
#ifdef DEBUG_PRINT
   printf("EndfileStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "EndfileStmt(<term>)", &EndfileStmt->term)) {
 }

//....... ofp_uniqueSymbol: "PositionSpecList"
   OFP_Traverse PositionSpecList;
   if (ATmatch(term, "EndfileStmt_PSL(<term>)", &PositionSpecList.term)) {
      if (ofp_traverse_PositionSpecList(PositionSpecList.term, &PositionSpecList)) {
         // MATCHED PositionSpecList
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "EOS"
   OFP_Traverse EOS;
   if (ATmatch(term, "EndfileStmt_PSL(<term>)", &EOS.term)) {
      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "FileUnitNumber"
   OFP_Traverse FileUnitNumber;
   if (ATmatch(term, "EndfileStmt_FUN(<term>)", &FileUnitNumber.term)) {
      if (ofp_traverse_FileUnitNumber(FileUnitNumber.term, &FileUnitNumber)) {
         // MATCHED FileUnitNumber
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "EOS"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "EOS1"
   OFP_Traverse EOS1;
   if (ATmatch(term, "EndfileStmt_FUN(<term>)", &EOS1.term)) {
      if (ofp_traverse_EOS(EOS1.term, &EOS1)) {
         // MATCHED EOS
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_BackspaceStmt(ATerm term, pOFP_Traverse BackspaceStmt)
{
#ifdef DEBUG_PRINT
   printf("BackspaceStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "BackspaceStmt(<term>)", &BackspaceStmt->term)) {
 }

//....... ofp_uniqueSymbol: "PositionSpecList"
   OFP_Traverse PositionSpecList;
   if (ATmatch(term, "BackspaceStmt_PSL(<term>)", &PositionSpecList.term)) {
      if (ofp_traverse_PositionSpecList(PositionSpecList.term, &PositionSpecList)) {
         // MATCHED PositionSpecList
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "EOS"
   OFP_Traverse EOS;
   if (ATmatch(term, "BackspaceStmt_PSL(<term>)", &EOS.term)) {
      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "FileUnitNumber"
   OFP_Traverse FileUnitNumber;
   if (ATmatch(term, "BackspaceStmt_FUN(<term>)", &FileUnitNumber.term)) {
      if (ofp_traverse_FileUnitNumber(FileUnitNumber.term, &FileUnitNumber)) {
         // MATCHED FileUnitNumber
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "EOS"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "EOS1"
   OFP_Traverse EOS1;
   if (ATmatch(term, "BackspaceStmt_FUN(<term>)", &EOS1.term)) {
      if (ofp_traverse_EOS(EOS1.term, &EOS1)) {
         // MATCHED EOS
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_WaitSpecList(ATerm term, pOFP_Traverse WaitSpecList)
{
#ifdef DEBUG_PRINT
   printf("WaitSpecList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "WaitSpecList(<term>)", &WaitSpecList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_WaitSpec(ATerm term, pOFP_Traverse WaitSpec)
{
#ifdef DEBUG_PRINT
   printf("WaitSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "WaitSpec(<term>)", &WaitSpec->term)) {
 }

//....... ofp_uniqueSymbol: "IntExpr"
   OFP_Traverse IntExpr;
   if (ATmatch(term, "WaitSpec_IOSTAT(<term>)", &IntExpr.term)) {
      if (ofp_traverse_IntExpr(IntExpr.term, &IntExpr)) {
         // MATCHED IntExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "IomsgVariable"
   OFP_Traverse IomsgVariable;
   if (ATmatch(term, "WaitSpec_IOMSG(<term>)", &IomsgVariable.term)) {
      if (ofp_traverse_IomsgVariable(IomsgVariable.term, &IomsgVariable)) {
         // MATCHED IomsgVariable
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "IntExpr"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "IntExpr1"
   OFP_Traverse IntExpr1;
   if (ATmatch(term, "WaitSpec_ID(<term>)", &IntExpr1.term)) {
      if (ofp_traverse_IntExpr(IntExpr1.term, &IntExpr1)) {
         // MATCHED IntExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "LblRef"
   OFP_Traverse LblRef;
   if (ATmatch(term, "WaitSpec_ERR(<term>)", &LblRef.term)) {
      if (ofp_traverse_LblRef(LblRef.term, &LblRef)) {
         // MATCHED LblRef
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "LblRef"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "LblRef1"
   OFP_Traverse LblRef1;
   if (ATmatch(term, "WaitSpec_EOR(<term>)", &LblRef1.term)) {
      if (ofp_traverse_LblRef(LblRef1.term, &LblRef1)) {
         // MATCHED LblRef
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "LblRef"
//.......       from table: 1
//.......               id: 2
//.......       unique sym: "LblRef2"
   OFP_Traverse LblRef2;
   if (ATmatch(term, "WaitSpec_END(<term>)", &LblRef2.term)) {
      if (ofp_traverse_LblRef(LblRef2.term, &LblRef2)) {
         // MATCHED LblRef
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "FileUnitNumber"
   OFP_Traverse FileUnitNumber;
   if (ATmatch(term, "WaitSpec_UNIT(<term>)", &FileUnitNumber.term)) {
      if (ofp_traverse_FileUnitNumber(FileUnitNumber.term, &FileUnitNumber)) {
         // MATCHED FileUnitNumber
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_WaitStmt(ATerm term, pOFP_Traverse WaitStmt)
{
#ifdef DEBUG_PRINT
   printf("WaitStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "WaitStmt(<term>)", &WaitStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(WaitStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_IoImpliedDoControl(ATerm term, pOFP_Traverse IoImpliedDoControl)
{
#ifdef DEBUG_PRINT
   printf("IoImpliedDoControl: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "IoImpliedDoControl(<term>)", &IoImpliedDoControl->term)) {
//....... ofp_uniqueSymbol: "DoVariable"
   OFP_Traverse DoVariable;
   if (ofp_traverse_DoVariable(IoImpliedDoControl->term, &DoVariable)) {
      // MATCHED DoVariable
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_IoImpliedDoObjectList(ATerm term, pOFP_Traverse IoImpliedDoObjectList)
{
#ifdef DEBUG_PRINT
   printf("IoImpliedDoObjectList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "IoImpliedDoObjectList(<term>)", &IoImpliedDoObjectList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_IoImpliedDoObject(ATerm term, pOFP_Traverse IoImpliedDoObject)
{
#ifdef DEBUG_PRINT
   printf("IoImpliedDoObject: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "IoImpliedDoObject(<term>)", &IoImpliedDoObject->term)) {
//....... ofp_uniqueSymbol: "OutputItem"
   OFP_Traverse OutputItem;
   if (ofp_traverse_OutputItem(IoImpliedDoObject->term, &OutputItem)) {
      // MATCHED OutputItem
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "InputItem"
   OFP_Traverse InputItem;
   if (ofp_traverse_InputItem(IoImpliedDoObject->term, &InputItem)) {
      // MATCHED InputItem
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_IoImpliedDo(ATerm term, pOFP_Traverse IoImpliedDo)
{
#ifdef DEBUG_PRINT
   printf("IoImpliedDo: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "IoImpliedDo(<term>)", &IoImpliedDo->term)) {
//....... ofp_uniqueSymbol: "IoImpliedDoObjectList"
   OFP_Traverse IoImpliedDoObjectList;
   if (ofp_traverse_IoImpliedDoObjectList(IoImpliedDo->term, &IoImpliedDoObjectList)) {
      // MATCHED IoImpliedDoObjectList
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_OutputItemList(ATerm term, pOFP_Traverse OutputItemList)
{
#ifdef DEBUG_PRINT
   printf("OutputItemList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "OutputItemList(<term>)", &OutputItemList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_OutputItem(ATerm term, pOFP_Traverse OutputItem)
{
#ifdef DEBUG_PRINT
   printf("OutputItem: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "OutputItem(<term>)", &OutputItem->term)) {
//....... ofp_uniqueSymbol: "IoImpliedDo"
   OFP_Traverse IoImpliedDo;
   if (ofp_traverse_IoImpliedDo(OutputItem->term, &IoImpliedDo)) {
      // MATCHED IoImpliedDo
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "Expr"
   OFP_Traverse Expr;
   if (ofp_traverse_Expr(OutputItem->term, &Expr)) {
      // MATCHED Expr
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_InputItemList(ATerm term, pOFP_Traverse InputItemList)
{
#ifdef DEBUG_PRINT
   printf("InputItemList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "InputItemList(<term>)", &InputItemList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_InputItem(ATerm term, pOFP_Traverse InputItem)
{
#ifdef DEBUG_PRINT
   printf("InputItem: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "InputItem(<term>)", &InputItem->term)) {
//....... ofp_uniqueSymbol: "IoImpliedDo"
   OFP_Traverse IoImpliedDo;
   if (ofp_traverse_IoImpliedDo(InputItem->term, &IoImpliedDo)) {
      // MATCHED IoImpliedDo
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "Variable"
   OFP_Traverse Variable;
   if (ofp_traverse_Variable(InputItem->term, &Variable)) {
      // MATCHED Variable
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_Format(ATerm term, pOFP_Traverse Format)
{
#ifdef DEBUG_PRINT
   printf("Format: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "Format(<term>)", &Format->term)) {
 }

//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ATmatch(term, "Format_L(<term>)", &Label.term)) {
      if (ofp_traverse_Label(Label.term, &Label)) {
         // MATCHED Label
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
   OFP_Traverse DefaultCharExpr;
   if (ATmatch(term, "Format_DCE(<term>)", &DefaultCharExpr.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr.term, &DefaultCharExpr)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

   if (ATmatch(term, "Format_STAR")) {
      // MATCHED Format_STAR
      return ATtrue;
   }

   return ATfalse;
}

ATbool ofp_traverse_IdVariable(ATerm term, pOFP_Traverse IdVariable)
{
#ifdef DEBUG_PRINT
   printf("IdVariable: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "IdVariable(<term>)", &IdVariable->term)) {
//....... ofp_uniqueSymbol: "IntVariable"
   OFP_Traverse IntVariable;
   if (ofp_traverse_IntVariable(IdVariable->term, &IntVariable)) {
      // MATCHED IntVariable
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_IoControlSpecList(ATerm term, pOFP_Traverse IoControlSpecList)
{
#ifdef DEBUG_PRINT
   printf("IoControlSpecList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "IoControlSpecList(<term>)", &IoControlSpecList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_IoControlSpec(ATerm term, pOFP_Traverse IoControlSpec)
{
#ifdef DEBUG_PRINT
   printf("IoControlSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "IoControlSpec(<term>)", &IoControlSpec->term)) {
 }

//....... ofp_uniqueSymbol: "IntVariable"
   OFP_Traverse IntVariable;
   if (ATmatch(term, "IoControlSpec_SIZE(<term>)", &IntVariable.term)) {
      if (ofp_traverse_IntVariable(IntVariable.term, &IntVariable)) {
         // MATCHED IntVariable
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
   OFP_Traverse DefaultCharExpr;
   if (ATmatch(term, "IoControlSpec_SIGN(<term>)", &DefaultCharExpr.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr.term, &DefaultCharExpr)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "DefaultCharExpr1"
   OFP_Traverse DefaultCharExpr1;
   if (ATmatch(term, "IoControlSpec_ROUND(<term>)", &DefaultCharExpr1.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr1.term, &DefaultCharExpr1)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
   OFP_Traverse Expr;
   if (ATmatch(term, "IoControlSpec_REC(<term>)", &Expr.term)) {
      if (ofp_traverse_Expr(Expr.term, &Expr)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "Expr1"
   OFP_Traverse Expr1;
   if (ATmatch(term, "IoControlSpec_POS(<term>)", &Expr1.term)) {
      if (ofp_traverse_Expr(Expr1.term, &Expr1)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 1
//.......               id: 2
//.......       unique sym: "DefaultCharExpr2"
   OFP_Traverse DefaultCharExpr2;
   if (ATmatch(term, "IoControlSpec_PAD(<term>)", &DefaultCharExpr2.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr2.term, &DefaultCharExpr2)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "IntVariable"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "IntVariable1"
   OFP_Traverse IntVariable1;
   if (ATmatch(term, "IoControlSpec_IOSTAT(<term>)", &IntVariable1.term)) {
      if (ofp_traverse_IntVariable(IntVariable1.term, &IntVariable1)) {
         // MATCHED IntVariable
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "IomsgVariable"
   OFP_Traverse IomsgVariable;
   if (ATmatch(term, "IoControlSpec_IOMSG(<term>)", &IomsgVariable.term)) {
      if (ofp_traverse_IomsgVariable(IomsgVariable.term, &IomsgVariable)) {
         // MATCHED IomsgVariable
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "IdVariable"
   OFP_Traverse IdVariable;
   if (ATmatch(term, "IoControlSpec_ID(<term>)", &IdVariable.term)) {
      if (ofp_traverse_IdVariable(IdVariable.term, &IdVariable)) {
         // MATCHED IdVariable
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "LblRef"
   OFP_Traverse LblRef;
   if (ATmatch(term, "IoControlSpec_ERR(<term>)", &LblRef.term)) {
      if (ofp_traverse_LblRef(LblRef.term, &LblRef)) {
         // MATCHED LblRef
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "LblRef"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "LblRef1"
   OFP_Traverse LblRef1;
   if (ATmatch(term, "IoControlSpec_EOR(<term>)", &LblRef1.term)) {
      if (ofp_traverse_LblRef(LblRef1.term, &LblRef1)) {
         // MATCHED LblRef
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "LblRef"
//.......       from table: 1
//.......               id: 2
//.......       unique sym: "LblRef2"
   OFP_Traverse LblRef2;
   if (ATmatch(term, "IoControlSpec_END(<term>)", &LblRef2.term)) {
      if (ofp_traverse_LblRef(LblRef2.term, &LblRef2)) {
         // MATCHED LblRef
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 2
//.......               id: 3
//.......       unique sym: "DefaultCharExpr3"
   OFP_Traverse DefaultCharExpr3;
   if (ATmatch(term, "IoControlSpec_DELIM(<term>)", &DefaultCharExpr3.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr3.term, &DefaultCharExpr3)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 3
//.......               id: 4
//.......       unique sym: "DefaultCharExpr4"
   OFP_Traverse DefaultCharExpr4;
   if (ATmatch(term, "IoControlSpec_DECIMAL(<term>)", &DefaultCharExpr4.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr4.term, &DefaultCharExpr4)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 4
//.......               id: 5
//.......       unique sym: "DefaultCharExpr5"
   OFP_Traverse DefaultCharExpr5;
   if (ATmatch(term, "IoControlSpec_BLANK(<term>)", &DefaultCharExpr5.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr5.term, &DefaultCharExpr5)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 5
//.......               id: 6
//.......       unique sym: "DefaultCharExpr6"
   OFP_Traverse DefaultCharExpr6;
   if (ATmatch(term, "IoControlSpec_ASYNCHRONOUS(<term>)", &DefaultCharExpr6.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr6.term, &DefaultCharExpr6)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 6
//.......               id: 7
//.......       unique sym: "DefaultCharExpr7"
   OFP_Traverse DefaultCharExpr7;
   if (ATmatch(term, "IoControlSpec_ADVANCE(<term>)", &DefaultCharExpr7.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr7.term, &DefaultCharExpr7)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "NamelistGroupName"
   OFP_Traverse NamelistGroupName;
   if (ATmatch(term, "IoControlSpec_NML(<term>)", &NamelistGroupName.term)) {
      if (ofp_traverse_NamelistGroupName(NamelistGroupName.term, &NamelistGroupName)) {
         // MATCHED NamelistGroupName
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Format"
   OFP_Traverse Format;
   if (ATmatch(term, "IoControlSpec_FMT(<term>)", &Format.term)) {
      if (ofp_traverse_Format(Format.term, &Format)) {
         // MATCHED Format
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "IoUnit"
   OFP_Traverse IoUnit;
   if (ATmatch(term, "IoControlSpec_UNIT(<term>)", &IoUnit.term)) {
      if (ofp_traverse_IoUnit(IoUnit.term, &IoUnit)) {
         // MATCHED IoUnit
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_PrintStmt(ATerm term, pOFP_Traverse PrintStmt)
{
#ifdef DEBUG_PRINT
   printf("PrintStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "PrintStmt(<term>)", &PrintStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(PrintStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_WriteStmt(ATerm term, pOFP_Traverse WriteStmt)
{
#ifdef DEBUG_PRINT
   printf("WriteStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "WriteStmt(<term>)", &WriteStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(WriteStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ReadStmt(ATerm term, pOFP_Traverse ReadStmt)
{
#ifdef DEBUG_PRINT
   printf("ReadStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ReadStmt(<term>)", &ReadStmt->term)) {
 }

//....... ofp_uniqueSymbol: "Format"
   OFP_Traverse Format;
   if (ATmatch(term, "ReadStmt_F(<term>)", &Format.term)) {
      if (ofp_traverse_Format(Format.term, &Format)) {
         // MATCHED Format
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "EOS"
   OFP_Traverse EOS;
   if (ATmatch(term, "ReadStmt_F(<term>)", &EOS.term)) {
      if (ofp_traverse_EOS(EOS.term, &EOS)) {
         // MATCHED EOS
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "IoControlSpecList"
   OFP_Traverse IoControlSpecList;
   if (ATmatch(term, "ReadStmt_ICSL(<term>)", &IoControlSpecList.term)) {
      if (ofp_traverse_IoControlSpecList(IoControlSpecList.term, &IoControlSpecList)) {
         // MATCHED IoControlSpecList
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "EOS"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "EOS1"
   OFP_Traverse EOS1;
   if (ATmatch(term, "ReadStmt_ICSL(<term>)", &EOS1.term)) {
      if (ofp_traverse_EOS(EOS1.term, &EOS1)) {
         // MATCHED EOS
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_CloseSpecList(ATerm term, pOFP_Traverse CloseSpecList)
{
#ifdef DEBUG_PRINT
   printf("CloseSpecList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "CloseSpecList(<term>)", &CloseSpecList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_CloseSpec(ATerm term, pOFP_Traverse CloseSpec)
{
#ifdef DEBUG_PRINT
   printf("CloseSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "CloseSpec(<term>)", &CloseSpec->term)) {
 }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
   OFP_Traverse DefaultCharExpr;
   if (ATmatch(term, "CloseSpec_STATUS(<term>)", &DefaultCharExpr.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr.term, &DefaultCharExpr)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "LblRef"
   OFP_Traverse LblRef;
   if (ATmatch(term, "CloseSpec_ERR(<term>)", &LblRef.term)) {
      if (ofp_traverse_LblRef(LblRef.term, &LblRef)) {
         // MATCHED LblRef
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "IomsgVariable"
   OFP_Traverse IomsgVariable;
   if (ATmatch(term, "CloseSpec_IOMSG(<term>)", &IomsgVariable.term)) {
      if (ofp_traverse_IomsgVariable(IomsgVariable.term, &IomsgVariable)) {
         // MATCHED IomsgVariable
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "IntVariable"
   OFP_Traverse IntVariable;
   if (ATmatch(term, "CloseSpec_IOSTAT(<term>)", &IntVariable.term)) {
      if (ofp_traverse_IntVariable(IntVariable.term, &IntVariable)) {
         // MATCHED IntVariable
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "FileUnitNumber"
   OFP_Traverse FileUnitNumber;
   if (ATmatch(term, "CloseSpec_UNIT(<term>)", &FileUnitNumber.term)) {
      if (ofp_traverse_FileUnitNumber(FileUnitNumber.term, &FileUnitNumber)) {
         // MATCHED FileUnitNumber
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_CloseStmt(ATerm term, pOFP_Traverse CloseStmt)
{
#ifdef DEBUG_PRINT
   printf("CloseStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "CloseStmt(<term>)", &CloseStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(CloseStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_IomsgVariable(ATerm term, pOFP_Traverse IomsgVariable)
{
#ifdef DEBUG_PRINT
   printf("IomsgVariable: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "IomsgVariable(<term>)", &IomsgVariable->term)) {
//....... ofp_uniqueSymbol: "DefaultCharExpr"
   OFP_Traverse DefaultCharExpr;
   if (ofp_traverse_DefaultCharExpr(IomsgVariable->term, &DefaultCharExpr)) {
      // MATCHED DefaultCharExpr
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_FileNameExpr(ATerm term, pOFP_Traverse FileNameExpr)
{
#ifdef DEBUG_PRINT
   printf("FileNameExpr: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "FileNameExpr(<term>)", &FileNameExpr->term)) {
//....... ofp_uniqueSymbol: "DefaultCharExpr"
   OFP_Traverse DefaultCharExpr;
   if (ofp_traverse_DefaultCharExpr(FileNameExpr->term, &DefaultCharExpr)) {
      // MATCHED DefaultCharExpr
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ConnectSpecList(ATerm term, pOFP_Traverse ConnectSpecList)
{
#ifdef DEBUG_PRINT
   printf("ConnectSpecList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ConnectSpecList(<term>)", &ConnectSpecList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_ConnectSpec(ATerm term, pOFP_Traverse ConnectSpec)
{
#ifdef DEBUG_PRINT
   printf("ConnectSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ConnectSpec(<term>)", &ConnectSpec->term)) {
 }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
   OFP_Traverse DefaultCharExpr;
   if (ATmatch(term, "ConnectSpec_STATUS(<term>)", &DefaultCharExpr.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr.term, &DefaultCharExpr)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "DefaultCharExpr1"
   OFP_Traverse DefaultCharExpr1;
   if (ATmatch(term, "ConnectSpec_SIGN(<term>)", &DefaultCharExpr1.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr1.term, &DefaultCharExpr1)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 1
//.......               id: 2
//.......       unique sym: "DefaultCharExpr2"
   OFP_Traverse DefaultCharExpr2;
   if (ATmatch(term, "ConnectSpec_ROUND(<term>)", &DefaultCharExpr2.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr2.term, &DefaultCharExpr2)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "IntExpr"
   OFP_Traverse IntExpr;
   if (ATmatch(term, "ConnectSpec_RECL(<term>)", &IntExpr.term)) {
      if (ofp_traverse_IntExpr(IntExpr.term, &IntExpr)) {
         // MATCHED IntExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 2
//.......               id: 3
//.......       unique sym: "DefaultCharExpr3"
   OFP_Traverse DefaultCharExpr3;
   if (ATmatch(term, "ConnectSpec_POSITION(<term>)", &DefaultCharExpr3.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr3.term, &DefaultCharExpr3)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 3
//.......               id: 4
//.......       unique sym: "DefaultCharExpr4"
   OFP_Traverse DefaultCharExpr4;
   if (ATmatch(term, "ConnectSpec_PAD(<term>)", &DefaultCharExpr4.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr4.term, &DefaultCharExpr4)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "IntVariable"
   OFP_Traverse IntVariable;
   if (ATmatch(term, "ConnectSpec_NEWUNIT(<term>)", &IntVariable.term)) {
      if (ofp_traverse_IntVariable(IntVariable.term, &IntVariable)) {
         // MATCHED IntVariable
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "IntVariable"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "IntVariable1"
   OFP_Traverse IntVariable1;
   if (ATmatch(term, "ConnectSpec_IOSTAT(<term>)", &IntVariable1.term)) {
      if (ofp_traverse_IntVariable(IntVariable1.term, &IntVariable1)) {
         // MATCHED IntVariable
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "IomsgVariable"
   OFP_Traverse IomsgVariable;
   if (ATmatch(term, "ConnectSpec_IOMSG(<term>)", &IomsgVariable.term)) {
      if (ofp_traverse_IomsgVariable(IomsgVariable.term, &IomsgVariable)) {
         // MATCHED IomsgVariable
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 4
//.......               id: 5
//.......       unique sym: "DefaultCharExpr5"
   OFP_Traverse DefaultCharExpr5;
   if (ATmatch(term, "ConnectSpec_FORM(<term>)", &DefaultCharExpr5.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr5.term, &DefaultCharExpr5)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "FileNameExpr"
   OFP_Traverse FileNameExpr;
   if (ATmatch(term, "ConnectSpec_FILE(<term>)", &FileNameExpr.term)) {
      if (ofp_traverse_FileNameExpr(FileNameExpr.term, &FileNameExpr)) {
         // MATCHED FileNameExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "LblRef"
   OFP_Traverse LblRef;
   if (ATmatch(term, "ConnectSpec_ERR(<term>)", &LblRef.term)) {
      if (ofp_traverse_LblRef(LblRef.term, &LblRef)) {
         // MATCHED LblRef
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 5
//.......               id: 6
//.......       unique sym: "DefaultCharExpr6"
   OFP_Traverse DefaultCharExpr6;
   if (ATmatch(term, "ConnectSpec_ENCODING(<term>)", &DefaultCharExpr6.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr6.term, &DefaultCharExpr6)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 6
//.......               id: 7
//.......       unique sym: "DefaultCharExpr7"
   OFP_Traverse DefaultCharExpr7;
   if (ATmatch(term, "ConnectSpec_DELIM(<term>)", &DefaultCharExpr7.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr7.term, &DefaultCharExpr7)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 7
//.......               id: 8
//.......       unique sym: "DefaultCharExpr8"
   OFP_Traverse DefaultCharExpr8;
   if (ATmatch(term, "ConnectSpec_DECIMAL(<term>)", &DefaultCharExpr8.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr8.term, &DefaultCharExpr8)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 8
//.......               id: 9
//.......       unique sym: "DefaultCharExpr9"
   OFP_Traverse DefaultCharExpr9;
   if (ATmatch(term, "ConnectSpec_BLANK(<term>)", &DefaultCharExpr9.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr9.term, &DefaultCharExpr9)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 9
//.......               id: 10
//.......       unique sym: "DefaultCharExpr10"
   OFP_Traverse DefaultCharExpr10;
   if (ATmatch(term, "ConnectSpec_ASYNCHRONOUS(<term>)", &DefaultCharExpr10.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr10.term, &DefaultCharExpr10)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 10
//.......               id: 11
//.......       unique sym: "DefaultCharExpr11"
   OFP_Traverse DefaultCharExpr11;
   if (ATmatch(term, "ConnectSpec_ACTION(<term>)", &DefaultCharExpr11.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr11.term, &DefaultCharExpr11)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DefaultCharExpr"
//.......       from table: 11
//.......               id: 12
//.......       unique sym: "DefaultCharExpr12"
   OFP_Traverse DefaultCharExpr12;
   if (ATmatch(term, "ConnectSpec_ACCESS(<term>)", &DefaultCharExpr12.term)) {
      if (ofp_traverse_DefaultCharExpr(DefaultCharExpr12.term, &DefaultCharExpr12)) {
         // MATCHED DefaultCharExpr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "FileUnitNumber"
   OFP_Traverse FileUnitNumber;
   if (ATmatch(term, "ConnectSpec_UNIT(<term>)", &FileUnitNumber.term)) {
      if (ofp_traverse_FileUnitNumber(FileUnitNumber.term, &FileUnitNumber)) {
         // MATCHED FileUnitNumber
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_OpenStmt(ATerm term, pOFP_Traverse OpenStmt)
{
#ifdef DEBUG_PRINT
   printf("OpenStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "OpenStmt(<term>)", &OpenStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(OpenStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_FileUnitNumber(ATerm term, pOFP_Traverse FileUnitNumber)
{
#ifdef DEBUG_PRINT
   printf("FileUnitNumber: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "FileUnitNumber(<term>)", &FileUnitNumber->term)) {
//....... ofp_uniqueSymbol: "IntExpr"
   OFP_Traverse IntExpr;
   if (ofp_traverse_IntExpr(FileUnitNumber->term, &IntExpr)) {
      // MATCHED IntExpr
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_IoUnit(ATerm term, pOFP_Traverse IoUnit)
{
#ifdef DEBUG_PRINT
   printf("IoUnit: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "IoUnit(<term>)", &IoUnit->term)) {
 }

//....... ofp_uniqueSymbol: "CharVariable"
   OFP_Traverse CharVariable;
   if (ATmatch(term, "IoUnit_IFV(<term>)", &CharVariable.term)) {
      if (ofp_traverse_CharVariable(CharVariable.term, &CharVariable)) {
         // MATCHED CharVariable
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "IntExpr"
   OFP_Traverse IntExpr;
   if (ATmatch(term, "IoUnit_FUN(<term>)", &IntExpr.term)) {
      if (ofp_traverse_IntExpr(IntExpr.term, &IntExpr)) {
         // MATCHED IntExpr
         return ATtrue;
      } else return ATfalse;
   }

   if (ATmatch(term, "IoUnit_STAR")) {
      // MATCHED IoUnit_STAR
      return ATtrue;
   }

   return ATfalse;
}

ATbool ofp_traverse_DeallocOptList(ATerm term, pOFP_Traverse DeallocOptList)
{
#ifdef DEBUG_PRINT
   printf("DeallocOptList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DeallocOptList(<term>)", &DeallocOptList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_DeallocOpt(ATerm term, pOFP_Traverse DeallocOpt)
{
#ifdef DEBUG_PRINT
   printf("DeallocOpt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DeallocOpt(<term>)", &DeallocOpt->term)) {
//....... ofp_uniqueSymbol: "ErrmsgVariable"
   OFP_Traverse ErrmsgVariable;
   if (ofp_traverse_ErrmsgVariable(DeallocOpt->term, &ErrmsgVariable)) {
      // MATCHED ErrmsgVariable
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "StatVariable"
   OFP_Traverse StatVariable;
   if (ofp_traverse_StatVariable(DeallocOpt->term, &StatVariable)) {
      // MATCHED StatVariable
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_DeallocateStmt(ATerm term, pOFP_Traverse DeallocateStmt)
{
#ifdef DEBUG_PRINT
   printf("DeallocateStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DeallocateStmt(<term>)", &DeallocateStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(DeallocateStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_PointerObjectList(ATerm term, pOFP_Traverse PointerObjectList)
{
#ifdef DEBUG_PRINT
   printf("PointerObjectList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "PointerObjectList(<term>)", &PointerObjectList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_PointerObject(ATerm term, pOFP_Traverse PointerObject)
{
#ifdef DEBUG_PRINT
   printf("PointerObject: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "PointerObject(<term>)", &PointerObject->term)) {
//....... ofp_uniqueSymbol: "ProcPointerName"
   OFP_Traverse ProcPointerName;
   if (ofp_traverse_ProcPointerName(PointerObject->term, &ProcPointerName)) {
      // MATCHED ProcPointerName
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "StructureComponent"
   OFP_Traverse StructureComponent;
   if (ofp_traverse_StructureComponent(PointerObject->term, &StructureComponent)) {
      // MATCHED StructureComponent
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "VariableName"
   OFP_Traverse VariableName;
   if (ofp_traverse_VariableName(PointerObject->term, &VariableName)) {
      // MATCHED VariableName
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_NullifyStmt(ATerm term, pOFP_Traverse NullifyStmt)
{
#ifdef DEBUG_PRINT
   printf("NullifyStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "NullifyStmt(<term>)", &NullifyStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(NullifyStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_AllocateCoshapeSpecList(ATerm term, pOFP_Traverse AllocateCoshapeSpecList)
{
#ifdef DEBUG_PRINT
   printf("AllocateCoshapeSpecList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AllocateCoshapeSpecList(<term>)", &AllocateCoshapeSpecList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_AllocateCoshapeSpec(ATerm term, pOFP_Traverse AllocateCoshapeSpec)
{
#ifdef DEBUG_PRINT
   printf("AllocateCoshapeSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AllocateCoshapeSpec(<term>)", &AllocateCoshapeSpec->term)) {
//....... ofp_uniqueSymbol: "LowerBoundExpr0"
   OFP_Traverse LowerBoundExpr0;
   if (ofp_traverse_LowerBoundExpr0(AllocateCoshapeSpec->term, &LowerBoundExpr0)) {
      // MATCHED LowerBoundExpr0
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_AllocateCoarraySpec(ATerm term, pOFP_Traverse AllocateCoarraySpec)
{
#ifdef DEBUG_PRINT
   printf("AllocateCoarraySpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AllocateCoarraySpec(<term>)", &AllocateCoarraySpec->term)) {
//....... ofp_uniqueSymbol: "AllocateCoshapeSpecList0"
   OFP_Traverse AllocateCoshapeSpecList0;
   if (ofp_traverse_AllocateCoshapeSpecList0(AllocateCoarraySpec->term, &AllocateCoshapeSpecList0)) {
      // MATCHED AllocateCoshapeSpecList0
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_UpperBoundExpr(ATerm term, pOFP_Traverse UpperBoundExpr)
{
#ifdef DEBUG_PRINT
   printf("UpperBoundExpr: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "UpperBoundExpr(<term>)", &UpperBoundExpr->term)) {
//....... ofp_uniqueSymbol: "IntExpr"
   OFP_Traverse IntExpr;
   if (ofp_traverse_IntExpr(UpperBoundExpr->term, &IntExpr)) {
      // MATCHED IntExpr
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_LowerBoundExpr(ATerm term, pOFP_Traverse LowerBoundExpr)
{
#ifdef DEBUG_PRINT
   printf("LowerBoundExpr: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "LowerBoundExpr(<term>)", &LowerBoundExpr->term)) {
//....... ofp_uniqueSymbol: "IntExpr"
   OFP_Traverse IntExpr;
   if (ofp_traverse_IntExpr(LowerBoundExpr->term, &IntExpr)) {
      // MATCHED IntExpr
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_AllocateShapeSpecList(ATerm term, pOFP_Traverse AllocateShapeSpecList)
{
#ifdef DEBUG_PRINT
   printf("AllocateShapeSpecList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AllocateShapeSpecList(<term>)", &AllocateShapeSpecList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_AllocateShapeSpec(ATerm term, pOFP_Traverse AllocateShapeSpec)
{
#ifdef DEBUG_PRINT
   printf("AllocateShapeSpec: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AllocateShapeSpec(<term>)", &AllocateShapeSpec->term)) {
//....... ofp_uniqueSymbol: "LowerBoundExpr0"
   OFP_Traverse LowerBoundExpr0;
   if (ofp_traverse_LowerBoundExpr0(AllocateShapeSpec->term, &LowerBoundExpr0)) {
      // MATCHED LowerBoundExpr0
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_AllocateObjectList(ATerm term, pOFP_Traverse AllocateObjectList)
{
#ifdef DEBUG_PRINT
   printf("AllocateObjectList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AllocateObjectList(<term>)", &AllocateObjectList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_AllocateObject(ATerm term, pOFP_Traverse AllocateObject)
{
#ifdef DEBUG_PRINT
   printf("AllocateObject: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AllocateObject(<term>)", &AllocateObject->term)) {
 }

//....... ofp_uniqueSymbol: "StructureComponent"
   OFP_Traverse StructureComponent;
   if (ATmatch(term, "AllocateObject_AMB(<term>)", &StructureComponent.term)) {
      if (ofp_traverse_StructureComponent(StructureComponent.term, &StructureComponent)) {
         // MATCHED StructureComponent
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_AllocationList(ATerm term, pOFP_Traverse AllocationList)
{
#ifdef DEBUG_PRINT
   printf("AllocationList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AllocationList(<term>)", &AllocationList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_Allocation(ATerm term, pOFP_Traverse Allocation)
{
#ifdef DEBUG_PRINT
   printf("Allocation: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "Allocation(<term>)", &Allocation->term)) {
//....... ofp_uniqueSymbol: "AllocateObject"
   OFP_Traverse AllocateObject;
   if (ofp_traverse_AllocateObject(Allocation->term, &AllocateObject)) {
      // MATCHED AllocateObject
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ErrmsgVariable(ATerm term, pOFP_Traverse ErrmsgVariable)
{
#ifdef DEBUG_PRINT
   printf("ErrmsgVariable: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ErrmsgVariable(<term>)", &ErrmsgVariable->term)) {
//....... ofp_uniqueSymbol: "DefaultCharVariable"
   OFP_Traverse DefaultCharVariable;
   if (ofp_traverse_DefaultCharVariable(ErrmsgVariable->term, &DefaultCharVariable)) {
      // MATCHED DefaultCharVariable
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_StatVariable(ATerm term, pOFP_Traverse StatVariable)
{
#ifdef DEBUG_PRINT
   printf("StatVariable: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "StatVariable(<term>)", &StatVariable->term)) {
//....... ofp_uniqueSymbol: "IntVariable"
   OFP_Traverse IntVariable;
   if (ofp_traverse_IntVariable(StatVariable->term, &IntVariable)) {
      // MATCHED IntVariable
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_AllocOptList(ATerm term, pOFP_Traverse AllocOptList)
{
#ifdef DEBUG_PRINT
   printf("AllocOptList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AllocOptList(<term>)", &AllocOptList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_AllocOpt(ATerm term, pOFP_Traverse AllocOpt)
{
#ifdef DEBUG_PRINT
   printf("AllocOpt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AllocOpt(<term>)", &AllocOpt->term)) {
 }

//....... ofp_uniqueSymbol: "StatVariable"
   OFP_Traverse StatVariable;
   if (ATmatch(term, "AllocOpt_STAT(<term>)", &StatVariable.term)) {
      if (ofp_traverse_StatVariable(StatVariable.term, &StatVariable)) {
         // MATCHED StatVariable
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
   OFP_Traverse Expr;
   if (ATmatch(term, "AllocOpt_SRC(<term>)", &Expr.term)) {
      if (ofp_traverse_Expr(Expr.term, &Expr)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "Expr"
//.......       from table: 0
//.......               id: 1
//.......       unique sym: "Expr1"
   OFP_Traverse Expr1;
   if (ATmatch(term, "AllocOpt_MOLD(<term>)", &Expr1.term)) {
      if (ofp_traverse_Expr(Expr1.term, &Expr1)) {
         // MATCHED Expr
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "ErrmsgVariable"
   OFP_Traverse ErrmsgVariable;
   if (ATmatch(term, "AllocOpt_ERR(<term>)", &ErrmsgVariable.term)) {
      if (ofp_traverse_ErrmsgVariable(ErrmsgVariable.term, &ErrmsgVariable)) {
         // MATCHED ErrmsgVariable
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_AllocateStmt(ATerm term, pOFP_Traverse AllocateStmt)
{
#ifdef DEBUG_PRINT
   printf("AllocateStmt: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "AllocateStmt(<term>)", &AllocateStmt->term)) {
//....... ofp_uniqueSymbol: "Label"
   OFP_Traverse Label;
   if (ofp_traverse_Label(AllocateStmt->term, &Label)) {
      // MATCHED Label
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_CosubscriptList(ATerm term, pOFP_Traverse CosubscriptList)
{
#ifdef DEBUG_PRINT
   printf("CosubscriptList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "CosubscriptList(<term>)", &CosubscriptList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_Cosubscript(ATerm term, pOFP_Traverse Cosubscript)
{
#ifdef DEBUG_PRINT
   printf("Cosubscript: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "Cosubscript(<term>)", &Cosubscript->term)) {
//....... ofp_uniqueSymbol: "IntExpr"
   OFP_Traverse IntExpr;
   if (ofp_traverse_IntExpr(Cosubscript->term, &IntExpr)) {
      // MATCHED IntExpr
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ImageSelector(ATerm term, pOFP_Traverse ImageSelector)
{
#ifdef DEBUG_PRINT
   printf("ImageSelector: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ImageSelector(<term>)", &ImageSelector->term)) {
//....... ofp_uniqueSymbol: "CosubscriptList"
   OFP_Traverse CosubscriptList;
   if (ofp_traverse_CosubscriptList(ImageSelector->term, &CosubscriptList)) {
      // MATCHED CosubscriptList
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_Stride(ATerm term, pOFP_Traverse Stride)
{
#ifdef DEBUG_PRINT
   printf("Stride: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "Stride(<term>)", &Stride->term)) {
//....... ofp_uniqueSymbol: "IntExpr"
   OFP_Traverse IntExpr;
   if (ofp_traverse_IntExpr(Stride->term, &IntExpr)) {
      // MATCHED IntExpr
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_SubscriptTriplet(ATerm term, pOFP_Traverse SubscriptTriplet)
{
#ifdef DEBUG_PRINT
   printf("SubscriptTriplet: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "SubscriptTriplet(<term>)", &SubscriptTriplet->term)) {
//....... ofp_uniqueSymbol: "Subscript"
   OFP_Traverse Subscript;
   if (ofp_traverse_Subscript(SubscriptTriplet->term, &Subscript)) {
      // MATCHED Subscript
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_SectionSubscriptList(ATerm term, pOFP_Traverse SectionSubscriptList)
{
#ifdef DEBUG_PRINT
   printf("SectionSubscriptList: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "SectionSubscriptList(<term>)", &SectionSubscriptList->term)) {
 }

   return ATfalse;
}

ATbool ofp_traverse_SectionSubscript(ATerm term, pOFP_Traverse SectionSubscript)
{
#ifdef DEBUG_PRINT
   printf("SectionSubscript: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "SectionSubscript(<term>)", &SectionSubscript->term)) {
//....... ofp_uniqueSymbol: "SubscriptTriplet"
   OFP_Traverse SubscriptTriplet;
   if (ofp_traverse_SubscriptTriplet(SectionSubscript->term, &SubscriptTriplet)) {
      // MATCHED SubscriptTriplet
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "Subscript"
   OFP_Traverse Subscript;
   if (ofp_traverse_Subscript(SectionSubscript->term, &Subscript)) {
      // MATCHED Subscript
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_Subscript(ATerm term, pOFP_Traverse Subscript)
{
#ifdef DEBUG_PRINT
   printf("Subscript: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "Subscript(<term>)", &Subscript->term)) {
//....... ofp_uniqueSymbol: "IntExpr"
   OFP_Traverse IntExpr;
   if (ofp_traverse_IntExpr(Subscript->term, &IntExpr)) {
      // MATCHED IntExpr
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ArrayElement(ATerm term, pOFP_Traverse ArrayElement)
{
#ifdef DEBUG_PRINT
   printf("ArrayElement: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ArrayElement(<term>)", &ArrayElement->term)) {
//....... ofp_uniqueSymbol: "DataRef"
   OFP_Traverse DataRef;
   if (ofp_traverse_DataRef(ArrayElement->term, &DataRef)) {
      // MATCHED DataRef
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_TypeParamInquiry(ATerm term, pOFP_Traverse TypeParamInquiry)
{
#ifdef DEBUG_PRINT
   printf("TypeParamInquiry: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "TypeParamInquiry(<term>)", &TypeParamInquiry->term)) {
//....... ofp_uniqueSymbol: "Designator"
   OFP_Traverse Designator;
   if (ofp_traverse_Designator(TypeParamInquiry->term, &Designator)) {
      // MATCHED Designator
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_CoindexedNamedObject(ATerm term, pOFP_Traverse CoindexedNamedObject)
{
#ifdef DEBUG_PRINT
   printf("CoindexedNamedObject: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "CoindexedNamedObject(<term>)", &CoindexedNamedObject->term)) {
//....... ofp_uniqueSymbol: "DataRef"
   OFP_Traverse DataRef;
   if (ofp_traverse_DataRef(CoindexedNamedObject->term, &DataRef)) {
      // MATCHED DataRef
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_StructureComponent(ATerm term, pOFP_Traverse StructureComponent)
{
#ifdef DEBUG_PRINT
   printf("StructureComponent: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "StructureComponent(<term>)", &StructureComponent->term)) {
//....... ofp_uniqueSymbol: "DataRef"
   OFP_Traverse DataRef;
   if (ofp_traverse_DataRef(StructureComponent->term, &DataRef)) {
      // MATCHED DataRef
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_PartRef(ATerm term, pOFP_Traverse PartRef)
{
#ifdef DEBUG_PRINT
   printf("PartRef: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "PartRef(<term>)", &PartRef->term)) {
//....... ofp_uniqueSymbol: "PartName"
   OFP_Traverse PartName;
   if (ofp_traverse_PartName(PartRef->term, &PartName)) {
      // MATCHED PartName
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_DataRef(ATerm term, pOFP_Traverse DataRef)
{
#ifdef DEBUG_PRINT
   printf("DataRef: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DataRef(<term>)", &DataRef->term)) {
//....... ofp_uniqueSymbol: "PartRef"
   OFP_Traverse PartRef;
   if (ofp_traverse_PartRef(DataRef->term, &PartRef)) {
      // MATCHED PartRef
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_SubstringRange(ATerm term, pOFP_Traverse SubstringRange)
{
#ifdef DEBUG_PRINT
   printf("SubstringRange: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "SubstringRange(<term>)", &SubstringRange->term)) {
//....... ofp_uniqueSymbol: "IntExpr"
   OFP_Traverse IntExpr;
   if (ofp_traverse_IntExpr(SubstringRange->term, &IntExpr)) {
      // MATCHED IntExpr
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_ParentString(ATerm term, pOFP_Traverse ParentString)
{
#ifdef DEBUG_PRINT
   printf("ParentString: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ParentString(<term>)", &ParentString->term)) {
//....... ofp_uniqueSymbol: "Constant"
   OFP_Traverse Constant;
   if (ofp_traverse_Constant(ParentString->term, &Constant)) {
      // MATCHED Constant
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "StructureComponent"
   OFP_Traverse StructureComponent;
   if (ofp_traverse_StructureComponent(ParentString->term, &StructureComponent)) {
      // MATCHED StructureComponent
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "CoindexedNamedObject"
   OFP_Traverse CoindexedNamedObject;
   if (ofp_traverse_CoindexedNamedObject(ParentString->term, &CoindexedNamedObject)) {
      // MATCHED CoindexedNamedObject
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "ArrayElement"
   OFP_Traverse ArrayElement;
   if (ofp_traverse_ArrayElement(ParentString->term, &ArrayElement)) {
      // MATCHED ArrayElement
      return ATtrue;
   } 
//....... ofp_uniqueSymbol: "ScalarVariableName"
   OFP_Traverse ScalarVariableName;
   if (ofp_traverse_ScalarVariableName(ParentString->term, &ScalarVariableName)) {
      // MATCHED ScalarVariableName
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_Substring(ATerm term, pOFP_Traverse Substring)
{
#ifdef DEBUG_PRINT
   printf("Substring: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "Substring(<term>)", &Substring->term)) {
//....... ofp_uniqueSymbol: "ParentString"
   OFP_Traverse ParentString;
   if (ofp_traverse_ParentString(Substring->term, &ParentString)) {
      // MATCHED ParentString
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_IntVariable(ATerm term, pOFP_Traverse IntVariable)
{
#ifdef DEBUG_PRINT
   printf("IntVariable: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "IntVariable(<term>)", &IntVariable->term)) {
//....... ofp_uniqueSymbol: "Variable"
   OFP_Traverse Variable;
   if (ofp_traverse_Variable(IntVariable->term, &Variable)) {
      // MATCHED Variable
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_DefaultCharVariable(ATerm term, pOFP_Traverse DefaultCharVariable)
{
#ifdef DEBUG_PRINT
   printf("DefaultCharVariable: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "DefaultCharVariable(<term>)", &DefaultCharVariable->term)) {
//....... ofp_uniqueSymbol: "Variable"
   OFP_Traverse Variable;
   if (ofp_traverse_Variable(DefaultCharVariable->term, &Variable)) {
      // MATCHED Variable
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_CharVariable(ATerm term, pOFP_Traverse CharVariable)
{
#ifdef DEBUG_PRINT
   printf("CharVariable: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "CharVariable(<term>)", &CharVariable->term)) {
//....... ofp_uniqueSymbol: "Variable"
   OFP_Traverse Variable;
   if (ofp_traverse_Variable(CharVariable->term, &Variable)) {
      // MATCHED Variable
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_LogicalVariable(ATerm term, pOFP_Traverse LogicalVariable)
{
#ifdef DEBUG_PRINT
   printf("LogicalVariable: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "LogicalVariable(<term>)", &LogicalVariable->term)) {
//....... ofp_uniqueSymbol: "Variable"
   OFP_Traverse Variable;
   if (ofp_traverse_Variable(LogicalVariable->term, &Variable)) {
      // MATCHED Variable
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_VariableName(ATerm term, pOFP_Traverse VariableName)
{
#ifdef DEBUG_PRINT
   printf("VariableName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "VariableName(<term>)", &VariableName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(VariableName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_Variable(ATerm term, pOFP_Traverse Variable)
{
#ifdef DEBUG_PRINT
   printf("Variable: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "Variable(<term>)", &Variable->term)) {
//....... ofp_uniqueSymbol: "Designator"
   OFP_Traverse Designator;
   if (ofp_traverse_Designator(Variable->term, &Designator)) {
      // MATCHED Designator
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_Designator(ATerm term, pOFP_Traverse Designator)
{
#ifdef DEBUG_PRINT
   printf("Designator: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "Designator(<term>)", &Designator->term)) {
 }

//....... ofp_uniqueSymbol: "Substring"
   OFP_Traverse Substring;
   if (ATmatch(term, "Designator_AMB(<term>)", &Substring.term)) {
      if (ofp_traverse_Substring(Substring.term, &Substring)) {
         // MATCHED Substring
         return ATtrue;
      } else return ATfalse;
   }

//....... ofp_uniqueSymbol: "DataRef"
   OFP_Traverse DataRef;
   if (ATmatch(term, "Designator_AMB(<term>)", &DataRef.term)) {
      if (ofp_traverse_DataRef(DataRef.term, &DataRef)) {
         // MATCHED DataRef
         return ATtrue;
      } else return ATfalse;
   }

   return ATfalse;
}

ATbool ofp_traverse_ScalarVariableName(ATerm term, pOFP_Traverse ScalarVariableName)
{
#ifdef DEBUG_PRINT
   printf("ScalarVariableName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "ScalarVariableName(<term>)", &ScalarVariableName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(ScalarVariableName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

ATbool ofp_traverse_PartName(ATerm term, pOFP_Traverse PartName)
{
#ifdef DEBUG_PRINT
   printf("PartName: %s\n", ATwriteToString(term));
#endif

 // This match may not be required for some productions.
 if (ATmatch(term, "PartName(<term>)", &PartName->term)) {
//....... ofp_uniqueSymbol: "Ident"
   OFP_Traverse Ident;
   if (ofp_traverse_Ident(PartName->term, &Ident)) {
      // MATCHED Ident
      return ATtrue;
   } 
 }

   return ATfalse;
}

#endif
