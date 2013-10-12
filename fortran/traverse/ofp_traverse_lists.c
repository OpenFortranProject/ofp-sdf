#include "traversal.h"

#ifdef NOT_YET
ATbool ofp_traverse_AcValueList(ATerm term, pOFP_Traverse AcValueList)
{
#ifdef DEBUG_PRINT
   printf("AcValueList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "AcValueList(<term>)", &AcValueList->term)) {
      return ATfalse;
   }

   OFP_Traverse AcValue;
   ATermList AcValue_tail = (ATermList) ATmake("<term>", AcValueList->term);
   while (! ATisEmpty(AcValue_tail)) {
      AcValue.term = ATgetFirst(AcValue_tail);
      AcValue_tail = ATgetNext (AcValue_tail);
      if (ofp_traverse_AcValue(AcValue.term, &AcValue)) {
         // MATCHED AcValue
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_EnumeratorList(ATerm term, pOFP_Traverse EnumeratorList)
{
#ifdef DEBUG_PRINT
   printf("EnumeratorList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "EnumeratorList(<term>)", &EnumeratorList->term)) {
      return ATfalse;
   }

   OFP_Traverse Enumerator;
   ATermList Enumerator_tail = (ATermList) ATmake("<term>", EnumeratorList->term);
   while (! ATisEmpty(Enumerator_tail)) {
      Enumerator.term = ATgetFirst(Enumerator_tail);
      Enumerator_tail = ATgetNext (Enumerator_tail);
      if (ofp_traverse_Enumerator(Enumerator.term, &Enumerator)) {
         // MATCHED Enumerator
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_TypeParamSpecList(ATerm term, pOFP_Traverse TypeParamSpecList)
{
#ifdef DEBUG_PRINT
   printf("TypeParamSpecList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "TypeParamSpecList(<term>)", &TypeParamSpecList->term)) {
      return ATfalse;
   }

   OFP_Traverse TypeParamSpec;
   ATermList TypeParamSpec_tail = (ATermList) ATmake("<term>", TypeParamSpecList->term);
   while (! ATisEmpty(TypeParamSpec_tail)) {
      TypeParamSpec.term = ATgetFirst(TypeParamSpec_tail);
      TypeParamSpec_tail = ATgetNext (TypeParamSpec_tail);
      if (ofp_traverse_TypeParamSpec(TypeParamSpec.term, &TypeParamSpec)) {
         // MATCHED TypeParamSpec
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_FinalSubroutineNameList(ATerm term, pOFP_Traverse FinalSubroutineNameList)
{
#ifdef DEBUG_PRINT
   printf("FinalSubroutineNameList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "FinalSubroutineNameList(<term>)", &FinalSubroutineNameList->term)) {
      return ATfalse;
   }

   OFP_Traverse FinalSubroutineName;
   ATermList FinalSubroutineName_tail = (ATermList) ATmake("<term>", FinalSubroutineNameList->term);
   while (! ATisEmpty(FinalSubroutineName_tail)) {
      FinalSubroutineName.term = ATgetFirst(FinalSubroutineName_tail);
      FinalSubroutineName_tail = ATgetNext (FinalSubroutineName_tail);
      if (ofp_traverse_FinalSubroutineName(FinalSubroutineName.term, &FinalSubroutineName)) {
         // MATCHED FinalSubroutineName
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_TypeBoundProcDeclList(ATerm term, pOFP_Traverse TypeBoundProcDeclList)
{
#ifdef DEBUG_PRINT
   printf("TypeBoundProcDeclList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "TypeBoundProcDeclList(<term>)", &TypeBoundProcDeclList->term)) {
      return ATfalse;
   }

   OFP_Traverse TypeBoundProcDecl;
   ATermList TypeBoundProcDecl_tail = (ATermList) ATmake("<term>", TypeBoundProcDeclList->term);
   while (! ATisEmpty(TypeBoundProcDecl_tail)) {
      TypeBoundProcDecl.term = ATgetFirst(TypeBoundProcDecl_tail);
      TypeBoundProcDecl_tail = ATgetNext (TypeBoundProcDecl_tail);
      if (ofp_traverse_TypeBoundProcDecl(TypeBoundProcDecl.term, &TypeBoundProcDecl)) {
         // MATCHED TypeBoundProcDecl
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_BindingNameList(ATerm term, pOFP_Traverse BindingNameList)
{
#ifdef DEBUG_PRINT
   printf("BindingNameList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "BindingNameList(<term>)", &BindingNameList->term)) {
      return ATfalse;
   }

   OFP_Traverse BindingName;
   ATermList BindingName_tail = (ATermList) ATmake("<term>", BindingNameList->term);
   while (! ATisEmpty(BindingName_tail)) {
      BindingName.term = ATgetFirst(BindingName_tail);
      BindingName_tail = ATgetNext (BindingName_tail);
      if (ofp_traverse_BindingName(BindingName.term, &BindingName)) {
         // MATCHED BindingName
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_BindingAttrList(ATerm term, pOFP_Traverse BindingAttrList)
{
#ifdef DEBUG_PRINT
   printf("BindingAttrList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "BindingAttrList(<term>)", &BindingAttrList->term)) {
      return ATfalse;
   }

   OFP_Traverse BindingAttr;
   ATermList BindingAttr_tail = (ATermList) ATmake("<term>", BindingAttrList->term);
   while (! ATisEmpty(BindingAttr_tail)) {
      BindingAttr.term = ATgetFirst(BindingAttr_tail);
      BindingAttr_tail = ATgetNext (BindingAttr_tail);
      if (ofp_traverse_BindingAttr(BindingAttr.term, &BindingAttr)) {
         // MATCHED BindingAttr
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_ProcComponentAttrSpecList(ATerm term, pOFP_Traverse ProcComponentAttrSpecList)
{
#ifdef DEBUG_PRINT
   printf("ProcComponentAttrSpecList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "ProcComponentAttrSpecList(<term>)", &ProcComponentAttrSpecList->term)) {
      return ATfalse;
   }

   OFP_Traverse ProcComponentAttrSpec;
   ATermList ProcComponentAttrSpec_tail = (ATermList) ATmake("<term>", ProcComponentAttrSpecList->term);
   while (! ATisEmpty(ProcComponentAttrSpec_tail)) {
      ProcComponentAttrSpec.term = ATgetFirst(ProcComponentAttrSpec_tail);
      ProcComponentAttrSpec_tail = ATgetNext (ProcComponentAttrSpec_tail);
      if (ofp_traverse_ProcComponentAttrSpec(ProcComponentAttrSpec.term, &ProcComponentAttrSpec)) {
         // MATCHED ProcComponentAttrSpec
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_ComponentDeclList(ATerm term, pOFP_Traverse ComponentDeclList)
{
#ifdef DEBUG_PRINT
   printf("ComponentDeclList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "ComponentDeclList(<term>)", &ComponentDeclList->term)) {
      return ATfalse;
   }

   OFP_Traverse ComponentDecl;
   ATermList ComponentDecl_tail = (ATermList) ATmake("<term>", ComponentDeclList->term);
   while (! ATisEmpty(ComponentDecl_tail)) {
      ComponentDecl.term = ATgetFirst(ComponentDecl_tail);
      ComponentDecl_tail = ATgetNext (ComponentDecl_tail);
      if (ofp_traverse_ComponentDecl(ComponentDecl.term, &ComponentDecl)) {
         // MATCHED ComponentDecl
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_ComponentAttrSpecList(ATerm term, pOFP_Traverse ComponentAttrSpecList)
{
#ifdef DEBUG_PRINT
   printf("ComponentAttrSpecList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "ComponentAttrSpecList(<term>)", &ComponentAttrSpecList->term)) {
      return ATfalse;
   }

   OFP_Traverse ComponentAttrSpec;
   ATermList ComponentAttrSpec_tail = (ATermList) ATmake("<term>", ComponentAttrSpecList->term);
   while (! ATisEmpty(ComponentAttrSpec_tail)) {
      ComponentAttrSpec.term = ATgetFirst(ComponentAttrSpec_tail);
      ComponentAttrSpec_tail = ATgetNext (ComponentAttrSpec_tail);
      if (ofp_traverse_ComponentAttrSpec(ComponentAttrSpec.term, &ComponentAttrSpec)) {
         // MATCHED ComponentAttrSpec
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_TypeParamDeclList(ATerm term, pOFP_Traverse TypeParamDeclList)
{
#ifdef DEBUG_PRINT
   printf("TypeParamDeclList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "TypeParamDeclList(<term>)", &TypeParamDeclList->term)) {
      return ATfalse;
   }

   OFP_Traverse TypeParamDecl;
   ATermList TypeParamDecl_tail = (ATermList) ATmake("<term>", TypeParamDeclList->term);
   while (! ATisEmpty(TypeParamDecl_tail)) {
      TypeParamDecl.term = ATgetFirst(TypeParamDecl_tail);
      TypeParamDecl_tail = ATgetNext (TypeParamDecl_tail);
      if (ofp_traverse_TypeParamDecl(TypeParamDecl.term, &TypeParamDecl)) {
         // MATCHED TypeParamDecl
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_TypeAttrSpecList(ATerm term, pOFP_Traverse TypeAttrSpecList)
{
#ifdef DEBUG_PRINT
   printf("TypeAttrSpecList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "TypeAttrSpecList(<term>)", &TypeAttrSpecList->term)) {
      return ATfalse;
   }

   OFP_Traverse TypeAttrSpec;
   ATermList TypeAttrSpec_tail = (ATermList) ATmake("<term>", TypeAttrSpecList->term);
   while (! ATisEmpty(TypeAttrSpec_tail)) {
      TypeAttrSpec.term = ATgetFirst(TypeAttrSpec_tail);
      TypeAttrSpec_tail = ATgetNext (TypeAttrSpec_tail);
      if (ofp_traverse_TypeAttrSpec(TypeAttrSpec.term, &TypeAttrSpec)) {
         // MATCHED TypeAttrSpec
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_TypeParamNameList(ATerm term, pOFP_Traverse TypeParamNameList)
{
#ifdef DEBUG_PRINT
   printf("TypeParamNameList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "TypeParamNameList(<term>)", &TypeParamNameList->term)) {
      return ATfalse;
   }

   OFP_Traverse TypeParamName;
   ATermList TypeParamName_tail = (ATermList) ATmake("<term>", TypeParamNameList->term);
   while (! ATisEmpty(TypeParamName_tail)) {
      TypeParamName.term = ATgetFirst(TypeParamName_tail);
      TypeParamName_tail = ATgetNext (TypeParamName_tail);
      if (ofp_traverse_TypeParamName(TypeParamName.term, &TypeParamName)) {
         // MATCHED TypeParamName
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_CommonBlockObjectList(ATerm term, pOFP_Traverse CommonBlockObjectList)
{
#ifdef DEBUG_PRINT
   printf("CommonBlockObjectList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "CommonBlockObjectList(<term>)", &CommonBlockObjectList->term)) {
      return ATfalse;
   }

   OFP_Traverse CommonBlockObject;
   ATermList CommonBlockObject_tail = (ATermList) ATmake("<term>", CommonBlockObjectList->term);
   while (! ATisEmpty(CommonBlockObject_tail)) {
      CommonBlockObject.term = ATgetFirst(CommonBlockObject_tail);
      CommonBlockObject_tail = ATgetNext (CommonBlockObject_tail);
      if (ofp_traverse_CommonBlockObject(CommonBlockObject.term, &CommonBlockObject)) {
         // MATCHED CommonBlockObject
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_EquivalenceObjectList(ATerm term, pOFP_Traverse EquivalenceObjectList)
{
#ifdef DEBUG_PRINT
   printf("EquivalenceObjectList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "EquivalenceObjectList(<term>)", &EquivalenceObjectList->term)) {
      return ATfalse;
   }

   OFP_Traverse EquivalenceObject;
   ATermList EquivalenceObject_tail = (ATermList) ATmake("<term>", EquivalenceObjectList->term);
   while (! ATisEmpty(EquivalenceObject_tail)) {
      EquivalenceObject.term = ATgetFirst(EquivalenceObject_tail);
      EquivalenceObject_tail = ATgetNext (EquivalenceObject_tail);
      if (ofp_traverse_EquivalenceObject(EquivalenceObject.term, &EquivalenceObject)) {
         // MATCHED EquivalenceObject
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_EquivalenceSetList(ATerm term, pOFP_Traverse EquivalenceSetList)
{
#ifdef DEBUG_PRINT
   printf("EquivalenceSetList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "EquivalenceSetList(<term>)", &EquivalenceSetList->term)) {
      return ATfalse;
   }

   OFP_Traverse EquivalenceSet;
   ATermList EquivalenceSet_tail = (ATermList) ATmake("<term>", EquivalenceSetList->term);
   while (! ATisEmpty(EquivalenceSet_tail)) {
      EquivalenceSet.term = ATgetFirst(EquivalenceSet_tail);
      EquivalenceSet_tail = ATgetNext (EquivalenceSet_tail);
      if (ofp_traverse_EquivalenceSet(EquivalenceSet.term, &EquivalenceSet)) {
         // MATCHED EquivalenceSet
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_NamelistGroupObjectList(ATerm term, pOFP_Traverse NamelistGroupObjectList)
{
#ifdef DEBUG_PRINT
   printf("NamelistGroupObjectList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "NamelistGroupObjectList(<term>)", &NamelistGroupObjectList->term)) {
      return ATfalse;
   }

   OFP_Traverse NamelistGroupObject;
   ATermList NamelistGroupObject_tail = (ATermList) ATmake("<term>", NamelistGroupObjectList->term);
   while (! ATisEmpty(NamelistGroupObject_tail)) {
      NamelistGroupObject.term = ATgetFirst(NamelistGroupObject_tail);
      NamelistGroupObject_tail = ATgetNext (NamelistGroupObject_tail);
      if (ofp_traverse_NamelistGroupObject(NamelistGroupObject.term, &NamelistGroupObject)) {
         // MATCHED NamelistGroupObject
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_LetterSpecList(ATerm term, pOFP_Traverse LetterSpecList)
{
#ifdef DEBUG_PRINT
   printf("LetterSpecList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "LetterSpecList(<term>)", &LetterSpecList->term)) {
      return ATfalse;
   }

   OFP_Traverse LetterSpec;
   ATermList LetterSpec_tail = (ATermList) ATmake("<term>", LetterSpecList->term);
   while (! ATisEmpty(LetterSpec_tail)) {
      LetterSpec.term = ATgetFirst(LetterSpec_tail);
      LetterSpec_tail = ATgetNext (LetterSpec_tail);
      if (ofp_traverse_LetterSpec(LetterSpec.term, &LetterSpec)) {
         // MATCHED LetterSpec
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_ImplicitSpecList(ATerm term, pOFP_Traverse ImplicitSpecList)
{
#ifdef DEBUG_PRINT
   printf("ImplicitSpecList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "ImplicitSpecList(<term>)", &ImplicitSpecList->term)) {
      return ATfalse;
   }

   OFP_Traverse ImplicitSpec;
   ATermList ImplicitSpec_tail = (ATermList) ATmake("<term>", ImplicitSpecList->term);
   while (! ATisEmpty(ImplicitSpec_tail)) {
      ImplicitSpec.term = ATgetFirst(ImplicitSpec_tail);
      ImplicitSpec_tail = ATgetNext (ImplicitSpec_tail);
      if (ofp_traverse_ImplicitSpec(ImplicitSpec.term, &ImplicitSpec)) {
         // MATCHED ImplicitSpec
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_TargetDeclList(ATerm term, pOFP_Traverse TargetDeclList)
{
#ifdef DEBUG_PRINT
   printf("TargetDeclList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "TargetDeclList(<term>)", &TargetDeclList->term)) {
      return ATfalse;
   }

   OFP_Traverse TargetDecl;
   ATermList TargetDecl_tail = (ATermList) ATmake("<term>", TargetDeclList->term);
   while (! ATisEmpty(TargetDecl_tail)) {
      TargetDecl.term = ATgetFirst(TargetDecl_tail);
      TargetDecl_tail = ATgetNext (TargetDecl_tail);
      if (ofp_traverse_TargetDecl(TargetDecl.term, &TargetDecl)) {
         // MATCHED TargetDecl
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_SavedEntityList(ATerm term, pOFP_Traverse SavedEntityList)
{
#ifdef DEBUG_PRINT
   printf("SavedEntityList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "SavedEntityList(<term>)", &SavedEntityList->term)) {
      return ATfalse;
   }

   OFP_Traverse SavedEntity;
   ATermList SavedEntity_tail = (ATermList) ATmake("<term>", SavedEntityList->term);
   while (! ATisEmpty(SavedEntity_tail)) {
      SavedEntity.term = ATgetFirst(SavedEntity_tail);
      SavedEntity_tail = ATgetNext (SavedEntity_tail);
      if (ofp_traverse_SavedEntity(SavedEntity.term, &SavedEntity)) {
         // MATCHED SavedEntity
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_EntityNameList(ATerm term, pOFP_Traverse EntityNameList)
{
#ifdef DEBUG_PRINT
   printf("EntityNameList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "EntityNameList(<term>)", &EntityNameList->term)) {
      return ATfalse;
   }

   OFP_Traverse EntityName;
   ATermList EntityName_tail = (ATermList) ATmake("<term>", EntityNameList->term);
   while (! ATisEmpty(EntityName_tail)) {
      EntityName.term = ATgetFirst(EntityName_tail);
      EntityName_tail = ATgetNext (EntityName_tail);
      if (ofp_traverse_EntityName(EntityName.term, &EntityName)) {
         // MATCHED EntityName
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_PointerDeclList(ATerm term, pOFP_Traverse PointerDeclList)
{
#ifdef DEBUG_PRINT
   printf("PointerDeclList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "PointerDeclList(<term>)", &PointerDeclList->term)) {
      return ATfalse;
   }

   OFP_Traverse PointerDecl;
   ATermList PointerDecl_tail = (ATermList) ATmake("<term>", PointerDeclList->term);
   while (! ATisEmpty(PointerDecl_tail)) {
      PointerDecl.term = ATgetFirst(PointerDecl_tail);
      PointerDecl_tail = ATgetNext (PointerDecl_tail);
      if (ofp_traverse_PointerDecl(PointerDecl.term, &PointerDecl)) {
         // MATCHED PointerDecl
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_NamedConstantDefList(ATerm term, pOFP_Traverse NamedConstantDefList)
{
#ifdef DEBUG_PRINT
   printf("NamedConstantDefList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "NamedConstantDefList(<term>)", &NamedConstantDefList->term)) {
      return ATfalse;
   }

   OFP_Traverse NamedConstantDef;
   ATermList NamedConstantDef_tail = (ATermList) ATmake("<term>", NamedConstantDefList->term);
   while (! ATisEmpty(NamedConstantDef_tail)) {
      NamedConstantDef.term = ATgetFirst(NamedConstantDef_tail);
      NamedConstantDef_tail = ATgetNext (NamedConstantDef_tail);
      if (ofp_traverse_NamedConstantDef(NamedConstantDef.term, &NamedConstantDef)) {
         // MATCHED NamedConstantDef
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_DataStmtValueList(ATerm term, pOFP_Traverse DataStmtValueList)
{
#ifdef DEBUG_PRINT
   printf("DataStmtValueList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "DataStmtValueList(<term>)", &DataStmtValueList->term)) {
      return ATfalse;
   }

   OFP_Traverse DataStmtValue;
   ATermList DataStmtValue_tail = (ATermList) ATmake("<term>", DataStmtValueList->term);
   while (! ATisEmpty(DataStmtValue_tail)) {
      DataStmtValue.term = ATgetFirst(DataStmtValue_tail);
      DataStmtValue_tail = ATgetNext (DataStmtValue_tail);
      if (ofp_traverse_DataStmtValue(DataStmtValue.term, &DataStmtValue)) {
         // MATCHED DataStmtValue
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_DataIDoObjectList(ATerm term, pOFP_Traverse DataIDoObjectList)
{
#ifdef DEBUG_PRINT
   printf("DataIDoObjectList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "DataIDoObjectList(<term>)", &DataIDoObjectList->term)) {
      return ATfalse;
   }

   OFP_Traverse DataIDoObject;
   ATermList DataIDoObject_tail = (ATermList) ATmake("<term>", DataIDoObjectList->term);
   while (! ATisEmpty(DataIDoObject_tail)) {
      DataIDoObject.term = ATgetFirst(DataIDoObject_tail);
      DataIDoObject_tail = ATgetNext (DataIDoObject_tail);
      if (ofp_traverse_DataIDoObject(DataIDoObject.term, &DataIDoObject)) {
         // MATCHED DataIDoObject
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_DataStmtObjectList(ATerm term, pOFP_Traverse DataStmtObjectList)
{
#ifdef DEBUG_PRINT
   printf("DataStmtObjectList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "DataStmtObjectList(<term>)", &DataStmtObjectList->term)) {
      return ATfalse;
   }

   OFP_Traverse DataStmtObject;
   ATermList DataStmtObject_tail = (ATermList) ATmake("<term>", DataStmtObjectList->term);
   while (! ATisEmpty(DataStmtObject_tail)) {
      DataStmtObject.term = ATgetFirst(DataStmtObject_tail);
      DataStmtObject_tail = ATgetNext (DataStmtObject_tail);
      if (ofp_traverse_DataStmtObject(DataStmtObject.term, &DataStmtObject)) {
         // MATCHED DataStmtObject
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_ObjectNameList(ATerm term, pOFP_Traverse ObjectNameList)
{
#ifdef DEBUG_PRINT
   printf("ObjectNameList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "ObjectNameList(<term>)", &ObjectNameList->term)) {
      return ATfalse;
   }

   OFP_Traverse ObjectName;
   ATermList ObjectName_tail = (ATermList) ATmake("<term>", ObjectNameList->term);
   while (! ATisEmpty(ObjectName_tail)) {
      ObjectName.term = ATgetFirst(ObjectName_tail);
      ObjectName_tail = ATgetNext (ObjectName_tail);
      if (ofp_traverse_ObjectName(ObjectName.term, &ObjectName)) {
         // MATCHED ObjectName
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_CodimensionDeclList(ATerm term, pOFP_Traverse CodimensionDeclList)
{
#ifdef DEBUG_PRINT
   printf("CodimensionDeclList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "CodimensionDeclList(<term>)", &CodimensionDeclList->term)) {
      return ATfalse;
   }

   OFP_Traverse CodimensionDecl;
   ATermList CodimensionDecl_tail = (ATermList) ATmake("<term>", CodimensionDeclList->term);
   while (! ATisEmpty(CodimensionDecl_tail)) {
      CodimensionDecl.term = ATgetFirst(CodimensionDecl_tail);
      CodimensionDecl_tail = ATgetNext (CodimensionDecl_tail);
      if (ofp_traverse_CodimensionDecl(CodimensionDecl.term, &CodimensionDecl)) {
         // MATCHED CodimensionDecl
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_BindEntityList(ATerm term, pOFP_Traverse BindEntityList)
{
#ifdef DEBUG_PRINT
   printf("BindEntityList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "BindEntityList(<term>)", &BindEntityList->term)) {
      return ATfalse;
   }

   OFP_Traverse BindEntity;
   ATermList BindEntity_tail = (ATermList) ATmake("<term>", BindEntityList->term);
   while (! ATisEmpty(BindEntity_tail)) {
      BindEntity.term = ATgetFirst(BindEntity_tail);
      BindEntity_tail = ATgetNext (BindEntity_tail);
      if (ofp_traverse_BindEntity(BindEntity.term, &BindEntity)) {
         // MATCHED BindEntity
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_AllocatableDeclList(ATerm term, pOFP_Traverse AllocatableDeclList)
{
#ifdef DEBUG_PRINT
   printf("AllocatableDeclList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "AllocatableDeclList(<term>)", &AllocatableDeclList->term)) {
      return ATfalse;
   }

   OFP_Traverse AllocatableDecl;
   ATermList AllocatableDecl_tail = (ATermList) ATmake("<term>", AllocatableDeclList->term);
   while (! ATisEmpty(AllocatableDecl_tail)) {
      AllocatableDecl.term = ATgetFirst(AllocatableDecl_tail);
      AllocatableDecl_tail = ATgetNext (AllocatableDecl_tail);
      if (ofp_traverse_AllocatableDecl(AllocatableDecl.term, &AllocatableDecl)) {
         // MATCHED AllocatableDecl
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_AccessIdList(ATerm term, pOFP_Traverse AccessIdList)
{
#ifdef DEBUG_PRINT
   printf("AccessIdList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "AccessIdList(<term>)", &AccessIdList->term)) {
      return ATfalse;
   }

   OFP_Traverse AccessId;
   ATermList AccessId_tail = (ATermList) ATmake("<term>", AccessIdList->term);
   while (! ATisEmpty(AccessId_tail)) {
      AccessId.term = ATgetFirst(AccessId_tail);
      AccessId_tail = ATgetNext (AccessId_tail);
      if (ofp_traverse_AccessId(AccessId.term, &AccessId)) {
         // MATCHED AccessId
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_ImpliedShapeSpecList(ATerm term, pOFP_Traverse ImpliedShapeSpecList)
{
#ifdef DEBUG_PRINT
   printf("ImpliedShapeSpecList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "ImpliedShapeSpecList(<term>)", &ImpliedShapeSpecList->term)) {
      return ATfalse;
   }

   OFP_Traverse ImpliedShapeSpec;
   ATermList ImpliedShapeSpec_tail = (ATermList) ATmake("<term>", ImpliedShapeSpecList->term);
   while (! ATisEmpty(ImpliedShapeSpec_tail)) {
      ImpliedShapeSpec.term = ATgetFirst(ImpliedShapeSpec_tail);
      ImpliedShapeSpec_tail = ATgetNext (ImpliedShapeSpec_tail);
      if (ofp_traverse_ImpliedShapeSpec(ImpliedShapeSpec.term, &ImpliedShapeSpec)) {
         // MATCHED ImpliedShapeSpec
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_DeferredShapeSpecList(ATerm term, pOFP_Traverse DeferredShapeSpecList)
{
#ifdef DEBUG_PRINT
   printf("DeferredShapeSpecList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "DeferredShapeSpecList(<term>)", &DeferredShapeSpecList->term)) {
      return ATfalse;
   }

   OFP_Traverse DeferredShapeSpec;
   ATermList DeferredShapeSpec_tail = (ATermList) ATmake("<term>", DeferredShapeSpecList->term);
   while (! ATisEmpty(DeferredShapeSpec_tail)) {
      DeferredShapeSpec.term = ATgetFirst(DeferredShapeSpec_tail);
      DeferredShapeSpec_tail = ATgetNext (DeferredShapeSpec_tail);
      if (ofp_traverse_DeferredShapeSpec(DeferredShapeSpec.term, &DeferredShapeSpec)) {
         // MATCHED DeferredShapeSpec
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_AssumedShapeSpecList(ATerm term, pOFP_Traverse AssumedShapeSpecList)
{
#ifdef DEBUG_PRINT
   printf("AssumedShapeSpecList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "AssumedShapeSpecList(<term>)", &AssumedShapeSpecList->term)) {
      return ATfalse;
   }

   OFP_Traverse AssumedShapeSpec;
   ATermList AssumedShapeSpec_tail = (ATermList) ATmake("<term>", AssumedShapeSpecList->term);
   while (! ATisEmpty(AssumedShapeSpec_tail)) {
      AssumedShapeSpec.term = ATgetFirst(AssumedShapeSpec_tail);
      AssumedShapeSpec_tail = ATgetNext (AssumedShapeSpec_tail);
      if (ofp_traverse_AssumedShapeSpec(AssumedShapeSpec.term, &AssumedShapeSpec)) {
         // MATCHED AssumedShapeSpec
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_ExplicitShapeSpecList(ATerm term, pOFP_Traverse ExplicitShapeSpecList)
{
#ifdef DEBUG_PRINT
   printf("ExplicitShapeSpecList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "ExplicitShapeSpecList(<term>)", &ExplicitShapeSpecList->term)) {
      return ATfalse;
   }

   OFP_Traverse ExplicitShapeSpec;
   ATermList ExplicitShapeSpec_tail = (ATermList) ATmake("<term>", ExplicitShapeSpecList->term);
   while (! ATisEmpty(ExplicitShapeSpec_tail)) {
      ExplicitShapeSpec.term = ATgetFirst(ExplicitShapeSpec_tail);
      ExplicitShapeSpec_tail = ATgetNext (ExplicitShapeSpec_tail);
      if (ofp_traverse_ExplicitShapeSpec(ExplicitShapeSpec.term, &ExplicitShapeSpec)) {
         // MATCHED ExplicitShapeSpec
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_DeferredCoshapeSpecList(ATerm term, pOFP_Traverse DeferredCoshapeSpecList)
{
#ifdef DEBUG_PRINT
   printf("DeferredCoshapeSpecList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "DeferredCoshapeSpecList(<term>)", &DeferredCoshapeSpecList->term)) {
      return ATfalse;
   }

   OFP_Traverse DeferredCoshapeSpec;
   ATermList DeferredCoshapeSpec_tail = (ATermList) ATmake("<term>", DeferredCoshapeSpecList->term);
   while (! ATisEmpty(DeferredCoshapeSpec_tail)) {
      DeferredCoshapeSpec.term = ATgetFirst(DeferredCoshapeSpec_tail);
      DeferredCoshapeSpec_tail = ATgetNext (DeferredCoshapeSpec_tail);
      if (ofp_traverse_DeferredCoshapeSpec(DeferredCoshapeSpec.term, &DeferredCoshapeSpec)) {
         // MATCHED DeferredCoshapeSpec
      } else return ATfalse;
   }
   return ATtrue;
}
#endif

ATbool ofp_traverse_EntityDeclList(ATerm term, pOFP_Traverse EntityDeclList)
{
#ifdef DEBUG_PRINT
   printf("EntityDeclList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "EntityDeclList(<term>)", &EntityDeclList->term)) {
      return ATfalse;
   }

   OFP_Traverse EntityDecl;
   ATermList EntityDecl_tail = (ATermList) ATmake("<term>", EntityDeclList->term);
   while (! ATisEmpty(EntityDecl_tail)) {
      EntityDecl.term = ATgetFirst(EntityDecl_tail);
      EntityDecl_tail = ATgetNext (EntityDecl_tail);
      if (ofp_traverse_EntityDecl(EntityDecl.term, &EntityDecl)) {
         // MATCHED EntityDecl
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_AttrSpecList(ATerm term, pOFP_Traverse AttrSpecList)
{
#ifdef DEBUG_PRINT
   printf("AttrSpecList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "AttrSpecList(<term>)", &AttrSpecList->term)) {
      return ATfalse;
   }

   OFP_Traverse AttrSpec;
   ATermList AttrSpec_tail = (ATermList) ATmake("<term>", AttrSpecList->term);
   while (! ATisEmpty(AttrSpec_tail)) {
      AttrSpec.term = ATgetFirst(AttrSpec_tail);
      AttrSpec_tail = ATgetNext (AttrSpec_tail);
      if (ofp_traverse_AttrSpec(AttrSpec.term, &AttrSpec)) {
         // MATCHED AttrSpec
      } else return ATfalse;
   }
   return ATtrue;
}

#ifdef NOT_YET
ATbool ofp_traverse_ForallTripletSpecList(ATerm term, pOFP_Traverse ForallTripletSpecList)
{
#ifdef DEBUG_PRINT
   printf("ForallTripletSpecList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "ForallTripletSpecList(<term>)", &ForallTripletSpecList->term)) {
      return ATfalse;
   }

   OFP_Traverse ForallTripletSpec;
   ATermList ForallTripletSpec_tail = (ATermList) ATmake("<term>", ForallTripletSpecList->term);
   while (! ATisEmpty(ForallTripletSpec_tail)) {
      ForallTripletSpec.term = ATgetFirst(ForallTripletSpec_tail);
      ForallTripletSpec_tail = ATgetNext (ForallTripletSpec_tail);
      if (ofp_traverse_ForallTripletSpec(ForallTripletSpec.term, &ForallTripletSpec)) {
         // MATCHED ForallTripletSpec
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_BoundsRemappingList(ATerm term, pOFP_Traverse BoundsRemappingList)
{
#ifdef DEBUG_PRINT
   printf("BoundsRemappingList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "BoundsRemappingList(<term>)", &BoundsRemappingList->term)) {
      return ATfalse;
   }

   OFP_Traverse BoundsRemapping;
   ATermList BoundsRemapping_tail = (ATermList) ATmake("<term>", BoundsRemappingList->term);
   while (! ATisEmpty(BoundsRemapping_tail)) {
      BoundsRemapping.term = ATgetFirst(BoundsRemapping_tail);
      BoundsRemapping_tail = ATgetNext (BoundsRemapping_tail);
      if (ofp_traverse_BoundsRemapping(BoundsRemapping.term, &BoundsRemapping)) {
         // MATCHED BoundsRemapping
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_BoundsSpecList(ATerm term, pOFP_Traverse BoundsSpecList)
{
#ifdef DEBUG_PRINT
   printf("BoundsSpecList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "BoundsSpecList(<term>)", &BoundsSpecList->term)) {
      return ATfalse;
   }

   OFP_Traverse BoundsSpec;
   ATermList BoundsSpec_tail = (ATermList) ATmake("<term>", BoundsSpecList->term);
   while (! ATisEmpty(BoundsSpec_tail)) {
      BoundsSpec.term = ATgetFirst(BoundsSpec_tail);
      BoundsSpec_tail = ATgetNext (BoundsSpec_tail);
      if (ofp_traverse_BoundsSpec(BoundsSpec.term, &BoundsSpec)) {
         // MATCHED BoundsSpec
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_DummyArgList(ATerm term, pOFP_Traverse DummyArgList)
{
#ifdef DEBUG_PRINT
   printf("DummyArgList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "DummyArgList(<term>)", &DummyArgList->term)) {
      return ATfalse;
   }

   OFP_Traverse DummyArg;
   ATermList DummyArg_tail = (ATermList) ATmake("<term>", DummyArgList->term);
   while (! ATisEmpty(DummyArg_tail)) {
      DummyArg.term = ATgetFirst(DummyArg_tail);
      DummyArg_tail = ATgetNext (DummyArg_tail);
      if (ofp_traverse_DummyArg(DummyArg.term, &DummyArg)) {
         // MATCHED DummyArg
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_DummyArgNameList(ATerm term, pOFP_Traverse DummyArgNameList)
{
#ifdef DEBUG_PRINT
   printf("DummyArgNameList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "DummyArgNameList(<term>)", &DummyArgNameList->term)) {
      return ATfalse;
   }

   OFP_Traverse DummyArgName;
   ATermList DummyArgName_tail = (ATermList) ATmake("<term>", DummyArgNameList->term);
   while (! ATisEmpty(DummyArgName_tail)) {
      DummyArgName.term = ATgetFirst(DummyArgName_tail);
      DummyArgName_tail = ATgetNext (DummyArgName_tail);
      if (ofp_traverse_DummyArgName(DummyArgName.term, &DummyArgName)) {
         // MATCHED DummyArgName
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_ActualArgSpecList(ATerm term, pOFP_Traverse ActualArgSpecList)
{
#ifdef DEBUG_PRINT
   printf("ActualArgSpecList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "ActualArgSpecList(<term>)", &ActualArgSpecList->term)) {
      return ATfalse;
   }

   OFP_Traverse ActualArgSpec;
   ATermList ActualArgSpec_tail = (ATermList) ATmake("<term>", ActualArgSpecList->term);
   while (! ATisEmpty(ActualArgSpec_tail)) {
      ActualArgSpec.term = ATgetFirst(ActualArgSpec_tail);
      ActualArgSpec_tail = ATgetNext (ActualArgSpec_tail);
      if (ofp_traverse_ActualArgSpec(ActualArgSpec.term, &ActualArgSpec)) {
         // MATCHED ActualArgSpec
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_IntrinsicProcedureNameList(ATerm term, pOFP_Traverse IntrinsicProcedureNameList)
{
#ifdef DEBUG_PRINT
   printf("IntrinsicProcedureNameList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "IntrinsicProcedureNameList(<term>)", &IntrinsicProcedureNameList->term)) {
      return ATfalse;
   }

   OFP_Traverse IntrinsicProcedureName;
   ATermList IntrinsicProcedureName_tail = (ATermList) ATmake("<term>", IntrinsicProcedureNameList->term);
   while (! ATisEmpty(IntrinsicProcedureName_tail)) {
      IntrinsicProcedureName.term = ATgetFirst(IntrinsicProcedureName_tail);
      IntrinsicProcedureName_tail = ATgetNext (IntrinsicProcedureName_tail);
      if (ofp_traverse_IntrinsicProcedureName(IntrinsicProcedureName.term, &IntrinsicProcedureName)) {
         // MATCHED IntrinsicProcedureName
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_ProcDeclList(ATerm term, pOFP_Traverse ProcDeclList)
{
#ifdef DEBUG_PRINT
   printf("ProcDeclList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "ProcDeclList(<term>)", &ProcDeclList->term)) {
      return ATfalse;
   }

   OFP_Traverse ProcDecl;
   ATermList ProcDecl_tail = (ATermList) ATmake("<term>", ProcDeclList->term);
   while (! ATisEmpty(ProcDecl_tail)) {
      ProcDecl.term = ATgetFirst(ProcDecl_tail);
      ProcDecl_tail = ATgetNext (ProcDecl_tail);
      if (ofp_traverse_ProcDecl(ProcDecl.term, &ProcDecl)) {
         // MATCHED ProcDecl
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_ProcAttrSpecList(ATerm term, pOFP_Traverse ProcAttrSpecList)
{
#ifdef DEBUG_PRINT
   printf("ProcAttrSpecList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "ProcAttrSpecList(<term>)", &ProcAttrSpecList->term)) {
      return ATfalse;
   }

   OFP_Traverse ProcAttrSpec;
   ATermList ProcAttrSpec_tail = (ATermList) ATmake("<term>", ProcAttrSpecList->term);
   while (! ATisEmpty(ProcAttrSpec_tail)) {
      ProcAttrSpec.term = ATgetFirst(ProcAttrSpec_tail);
      ProcAttrSpec_tail = ATgetNext (ProcAttrSpec_tail);
      if (ofp_traverse_ProcAttrSpec(ProcAttrSpec.term, &ProcAttrSpec)) {
         // MATCHED ProcAttrSpec
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_ExternalNameList(ATerm term, pOFP_Traverse ExternalNameList)
{
#ifdef DEBUG_PRINT
   printf("ExternalNameList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "ExternalNameList(<term>)", &ExternalNameList->term)) {
      return ATfalse;
   }

   OFP_Traverse ExternalName;
   ATermList ExternalName_tail = (ATermList) ATmake("<term>", ExternalNameList->term);
   while (! ATisEmpty(ExternalName_tail)) {
      ExternalName.term = ATgetFirst(ExternalName_tail);
      ExternalName_tail = ATgetNext (ExternalName_tail);
      if (ofp_traverse_ExternalName(ExternalName.term, &ExternalName)) {
         // MATCHED ExternalName
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_ImportNameList(ATerm term, pOFP_Traverse ImportNameList)
{
#ifdef DEBUG_PRINT
   printf("ImportNameList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "ImportNameList(<term>)", &ImportNameList->term)) {
      return ATfalse;
   }

   OFP_Traverse ImportName;
   ATermList ImportName_tail = (ATermList) ATmake("<term>", ImportNameList->term);
   while (! ATisEmpty(ImportName_tail)) {
      ImportName.term = ATgetFirst(ImportName_tail);
      ImportName_tail = ATgetNext (ImportName_tail);
      if (ofp_traverse_ImportName(ImportName.term, &ImportName)) {
         // MATCHED ImportName
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_ProcedureNameList(ATerm term, pOFP_Traverse ProcedureNameList)
{
#ifdef DEBUG_PRINT
   printf("ProcedureNameList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "ProcedureNameList(<term>)", &ProcedureNameList->term)) {
      return ATfalse;
   }

   OFP_Traverse ProcedureName;
   ATermList ProcedureName_tail = (ATermList) ATmake("<term>", ProcedureNameList->term);
   while (! ATisEmpty(ProcedureName_tail)) {
      ProcedureName.term = ATgetFirst(ProcedureName_tail);
      ProcedureName_tail = ATgetNext (ProcedureName_tail);
      if (ofp_traverse_ProcedureName(ProcedureName.term, &ProcedureName)) {
         // MATCHED ProcedureName
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_LockStatList(ATerm term, pOFP_Traverse LockStatList)
{
#ifdef DEBUG_PRINT
   printf("LockStatList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "LockStatList(<term>)", &LockStatList->term)) {
      return ATfalse;
   }

   OFP_Traverse LockStat;
   ATermList LockStat_tail = (ATermList) ATmake("<term>", LockStatList->term);
   while (! ATisEmpty(LockStat_tail)) {
      LockStat.term = ATgetFirst(LockStat_tail);
      LockStat_tail = ATgetNext (LockStat_tail);
      if (ofp_traverse_LockStat(LockStat.term, &LockStat)) {
         // MATCHED LockStat
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_SyncStatList(ATerm term, pOFP_Traverse SyncStatList)
{
#ifdef DEBUG_PRINT
   printf("SyncStatList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "SyncStatList(<term>)", &SyncStatList->term)) {
      return ATfalse;
   }

   OFP_Traverse SyncStat;
   ATermList SyncStat_tail = (ATermList) ATmake("<term>", SyncStatList->term);
   while (! ATisEmpty(SyncStat_tail)) {
      SyncStat.term = ATgetFirst(SyncStat_tail);
      SyncStat_tail = ATgetNext (SyncStat_tail);
      if (ofp_traverse_SyncStat(SyncStat.term, &SyncStat)) {
         // MATCHED SyncStat
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_CaseValueRangeList(ATerm term, pOFP_Traverse CaseValueRangeList)
{
#ifdef DEBUG_PRINT
   printf("CaseValueRangeList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "CaseValueRangeList(<term>)", &CaseValueRangeList->term)) {
      return ATfalse;
   }

   OFP_Traverse CaseValueRange;
   ATermList CaseValueRange_tail = (ATermList) ATmake("<term>", CaseValueRangeList->term);
   while (! ATisEmpty(CaseValueRange_tail)) {
      CaseValueRange.term = ATgetFirst(CaseValueRange_tail);
      CaseValueRange_tail = ATgetNext (CaseValueRange_tail);
      if (ofp_traverse_CaseValueRange(CaseValueRange.term, &CaseValueRange)) {
         // MATCHED CaseValueRange
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_AssociationList(ATerm term, pOFP_Traverse AssociationList)
{
#ifdef DEBUG_PRINT
   printf("AssociationList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "AssociationList(<term>)", &AssociationList->term)) {
      return ATfalse;
   }

   OFP_Traverse Association;
   ATermList Association_tail = (ATermList) ATmake("<term>", AssociationList->term);
   while (! ATisEmpty(Association_tail)) {
      Association.term = ATgetFirst(Association_tail);
      Association_tail = ATgetNext (Association_tail);
      if (ofp_traverse_Association(Association.term, &Association)) {
         // MATCHED Association
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_OnlyList(ATerm term, pOFP_Traverse OnlyList)
{
#ifdef DEBUG_PRINT
   printf("OnlyList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "OnlyList(<term>)", &OnlyList->term)) {
      return ATfalse;
   }

   OFP_Traverse Only;
   ATermList Only_tail = (ATermList) ATmake("<term>", OnlyList->term);
   while (! ATisEmpty(Only_tail)) {
      Only.term = ATgetFirst(Only_tail);
      Only_tail = ATgetNext (Only_tail);
      if (ofp_traverse_Only(Only.term, &Only)) {
         // MATCHED Only
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_RenameList(ATerm term, pOFP_Traverse RenameList)
{
#ifdef DEBUG_PRINT
   printf("RenameList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "RenameList(<term>)", &RenameList->term)) {
      return ATfalse;
   }

   OFP_Traverse Rename;
   ATermList Rename_tail = (ATermList) ATmake("<term>", RenameList->term);
   while (! ATisEmpty(Rename_tail)) {
      Rename.term = ATgetFirst(Rename_tail);
      Rename_tail = ATgetNext (Rename_tail);
      if (ofp_traverse_Rename(Rename.term, &Rename)) {
         // MATCHED Rename
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_VEditDescList(ATerm term, pOFP_Traverse VEditDescList)
{
#ifdef DEBUG_PRINT
   printf("VEditDescList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "VEditDescList(<term>)", &VEditDescList->term)) {
      return ATfalse;
   }

   OFP_Traverse VEditDesc;
   ATermList VEditDesc_tail = (ATermList) ATmake("<term>", VEditDescList->term);
   while (! ATisEmpty(VEditDesc_tail)) {
      VEditDesc.term = ATgetFirst(VEditDesc_tail);
      VEditDesc_tail = ATgetNext (VEditDesc_tail);
      if (ofp_traverse_VEditDesc(VEditDesc.term, &VEditDesc)) {
         // MATCHED VEditDesc
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_InquireSpecList(ATerm term, pOFP_Traverse InquireSpecList)
{
#ifdef DEBUG_PRINT
   printf("InquireSpecList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "InquireSpecList(<term>)", &InquireSpecList->term)) {
      return ATfalse;
   }

   OFP_Traverse InquireSpec;
   ATermList InquireSpec_tail = (ATermList) ATmake("<term>", InquireSpecList->term);
   while (! ATisEmpty(InquireSpec_tail)) {
      InquireSpec.term = ATgetFirst(InquireSpec_tail);
      InquireSpec_tail = ATgetNext (InquireSpec_tail);
      if (ofp_traverse_InquireSpec(InquireSpec.term, &InquireSpec)) {
         // MATCHED InquireSpec
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_FlushSpecList(ATerm term, pOFP_Traverse FlushSpecList)
{
#ifdef DEBUG_PRINT
   printf("FlushSpecList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "FlushSpecList(<term>)", &FlushSpecList->term)) {
      return ATfalse;
   }

   OFP_Traverse FlushSpec;
   ATermList FlushSpec_tail = (ATermList) ATmake("<term>", FlushSpecList->term);
   while (! ATisEmpty(FlushSpec_tail)) {
      FlushSpec.term = ATgetFirst(FlushSpec_tail);
      FlushSpec_tail = ATgetNext (FlushSpec_tail);
      if (ofp_traverse_FlushSpec(FlushSpec.term, &FlushSpec)) {
         // MATCHED FlushSpec
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_PositionSpecList(ATerm term, pOFP_Traverse PositionSpecList)
{
#ifdef DEBUG_PRINT
   printf("PositionSpecList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "PositionSpecList(<term>)", &PositionSpecList->term)) {
      return ATfalse;
   }

   OFP_Traverse PositionSpec;
   ATermList PositionSpec_tail = (ATermList) ATmake("<term>", PositionSpecList->term);
   while (! ATisEmpty(PositionSpec_tail)) {
      PositionSpec.term = ATgetFirst(PositionSpec_tail);
      PositionSpec_tail = ATgetNext (PositionSpec_tail);
      if (ofp_traverse_PositionSpec(PositionSpec.term, &PositionSpec)) {
         // MATCHED PositionSpec
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_WaitSpecList(ATerm term, pOFP_Traverse WaitSpecList)
{
#ifdef DEBUG_PRINT
   printf("WaitSpecList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "WaitSpecList(<term>)", &WaitSpecList->term)) {
      return ATfalse;
   }

   OFP_Traverse WaitSpec;
   ATermList WaitSpec_tail = (ATermList) ATmake("<term>", WaitSpecList->term);
   while (! ATisEmpty(WaitSpec_tail)) {
      WaitSpec.term = ATgetFirst(WaitSpec_tail);
      WaitSpec_tail = ATgetNext (WaitSpec_tail);
      if (ofp_traverse_WaitSpec(WaitSpec.term, &WaitSpec)) {
         // MATCHED WaitSpec
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_IoImpliedDoObjectList(ATerm term, pOFP_Traverse IoImpliedDoObjectList)
{
#ifdef DEBUG_PRINT
   printf("IoImpliedDoObjectList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "IoImpliedDoObjectList(<term>)", &IoImpliedDoObjectList->term)) {
      return ATfalse;
   }

   OFP_Traverse IoImpliedDoObject;
   ATermList IoImpliedDoObject_tail = (ATermList) ATmake("<term>", IoImpliedDoObjectList->term);
   while (! ATisEmpty(IoImpliedDoObject_tail)) {
      IoImpliedDoObject.term = ATgetFirst(IoImpliedDoObject_tail);
      IoImpliedDoObject_tail = ATgetNext (IoImpliedDoObject_tail);
      if (ofp_traverse_IoImpliedDoObject(IoImpliedDoObject.term, &IoImpliedDoObject)) {
         // MATCHED IoImpliedDoObject
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_OutputItemList(ATerm term, pOFP_Traverse OutputItemList)
{
#ifdef DEBUG_PRINT
   printf("OutputItemList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "OutputItemList(<term>)", &OutputItemList->term)) {
      return ATfalse;
   }

   OFP_Traverse OutputItem;
   ATermList OutputItem_tail = (ATermList) ATmake("<term>", OutputItemList->term);
   while (! ATisEmpty(OutputItem_tail)) {
      OutputItem.term = ATgetFirst(OutputItem_tail);
      OutputItem_tail = ATgetNext (OutputItem_tail);
      if (ofp_traverse_OutputItem(OutputItem.term, &OutputItem)) {
         // MATCHED OutputItem
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_InputItemList(ATerm term, pOFP_Traverse InputItemList)
{
#ifdef DEBUG_PRINT
   printf("InputItemList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "InputItemList(<term>)", &InputItemList->term)) {
      return ATfalse;
   }

   OFP_Traverse InputItem;
   ATermList InputItem_tail = (ATermList) ATmake("<term>", InputItemList->term);
   while (! ATisEmpty(InputItem_tail)) {
      InputItem.term = ATgetFirst(InputItem_tail);
      InputItem_tail = ATgetNext (InputItem_tail);
      if (ofp_traverse_InputItem(InputItem.term, &InputItem)) {
         // MATCHED InputItem
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_IoControlSpecList(ATerm term, pOFP_Traverse IoControlSpecList)
{
#ifdef DEBUG_PRINT
   printf("IoControlSpecList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "IoControlSpecList(<term>)", &IoControlSpecList->term)) {
      return ATfalse;
   }

   OFP_Traverse IoControlSpec;
   ATermList IoControlSpec_tail = (ATermList) ATmake("<term>", IoControlSpecList->term);
   while (! ATisEmpty(IoControlSpec_tail)) {
      IoControlSpec.term = ATgetFirst(IoControlSpec_tail);
      IoControlSpec_tail = ATgetNext (IoControlSpec_tail);
      if (ofp_traverse_IoControlSpec(IoControlSpec.term, &IoControlSpec)) {
         // MATCHED IoControlSpec
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_CloseSpecList(ATerm term, pOFP_Traverse CloseSpecList)
{
#ifdef DEBUG_PRINT
   printf("CloseSpecList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "CloseSpecList(<term>)", &CloseSpecList->term)) {
      return ATfalse;
   }

   OFP_Traverse CloseSpec;
   ATermList CloseSpec_tail = (ATermList) ATmake("<term>", CloseSpecList->term);
   while (! ATisEmpty(CloseSpec_tail)) {
      CloseSpec.term = ATgetFirst(CloseSpec_tail);
      CloseSpec_tail = ATgetNext (CloseSpec_tail);
      if (ofp_traverse_CloseSpec(CloseSpec.term, &CloseSpec)) {
         // MATCHED CloseSpec
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_ConnectSpecList(ATerm term, pOFP_Traverse ConnectSpecList)
{
#ifdef DEBUG_PRINT
   printf("ConnectSpecList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "ConnectSpecList(<term>)", &ConnectSpecList->term)) {
      return ATfalse;
   }

   OFP_Traverse ConnectSpec;
   ATermList ConnectSpec_tail = (ATermList) ATmake("<term>", ConnectSpecList->term);
   while (! ATisEmpty(ConnectSpec_tail)) {
      ConnectSpec.term = ATgetFirst(ConnectSpec_tail);
      ConnectSpec_tail = ATgetNext (ConnectSpec_tail);
      if (ofp_traverse_ConnectSpec(ConnectSpec.term, &ConnectSpec)) {
         // MATCHED ConnectSpec
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_DeallocOptList(ATerm term, pOFP_Traverse DeallocOptList)
{
#ifdef DEBUG_PRINT
   printf("DeallocOptList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "DeallocOptList(<term>)", &DeallocOptList->term)) {
      return ATfalse;
   }

   OFP_Traverse DeallocOpt;
   ATermList DeallocOpt_tail = (ATermList) ATmake("<term>", DeallocOptList->term);
   while (! ATisEmpty(DeallocOpt_tail)) {
      DeallocOpt.term = ATgetFirst(DeallocOpt_tail);
      DeallocOpt_tail = ATgetNext (DeallocOpt_tail);
      if (ofp_traverse_DeallocOpt(DeallocOpt.term, &DeallocOpt)) {
         // MATCHED DeallocOpt
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_PointerObjectList(ATerm term, pOFP_Traverse PointerObjectList)
{
#ifdef DEBUG_PRINT
   printf("PointerObjectList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "PointerObjectList(<term>)", &PointerObjectList->term)) {
      return ATfalse;
   }

   OFP_Traverse PointerObject;
   ATermList PointerObject_tail = (ATermList) ATmake("<term>", PointerObjectList->term);
   while (! ATisEmpty(PointerObject_tail)) {
      PointerObject.term = ATgetFirst(PointerObject_tail);
      PointerObject_tail = ATgetNext (PointerObject_tail);
      if (ofp_traverse_PointerObject(PointerObject.term, &PointerObject)) {
         // MATCHED PointerObject
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_AllocateCoshapeSpecList(ATerm term, pOFP_Traverse AllocateCoshapeSpecList)
{
#ifdef DEBUG_PRINT
   printf("AllocateCoshapeSpecList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "AllocateCoshapeSpecList(<term>)", &AllocateCoshapeSpecList->term)) {
      return ATfalse;
   }

   OFP_Traverse AllocateCoshapeSpec;
   ATermList AllocateCoshapeSpec_tail = (ATermList) ATmake("<term>", AllocateCoshapeSpecList->term);
   while (! ATisEmpty(AllocateCoshapeSpec_tail)) {
      AllocateCoshapeSpec.term = ATgetFirst(AllocateCoshapeSpec_tail);
      AllocateCoshapeSpec_tail = ATgetNext (AllocateCoshapeSpec_tail);
      if (ofp_traverse_AllocateCoshapeSpec(AllocateCoshapeSpec.term, &AllocateCoshapeSpec)) {
         // MATCHED AllocateCoshapeSpec
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_AllocateShapeSpecList(ATerm term, pOFP_Traverse AllocateShapeSpecList)
{
#ifdef DEBUG_PRINT
   printf("AllocateShapeSpecList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "AllocateShapeSpecList(<term>)", &AllocateShapeSpecList->term)) {
      return ATfalse;
   }

   OFP_Traverse AllocateShapeSpec;
   ATermList AllocateShapeSpec_tail = (ATermList) ATmake("<term>", AllocateShapeSpecList->term);
   while (! ATisEmpty(AllocateShapeSpec_tail)) {
      AllocateShapeSpec.term = ATgetFirst(AllocateShapeSpec_tail);
      AllocateShapeSpec_tail = ATgetNext (AllocateShapeSpec_tail);
      if (ofp_traverse_AllocateShapeSpec(AllocateShapeSpec.term, &AllocateShapeSpec)) {
         // MATCHED AllocateShapeSpec
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_AllocateObjectList(ATerm term, pOFP_Traverse AllocateObjectList)
{
#ifdef DEBUG_PRINT
   printf("AllocateObjectList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "AllocateObjectList(<term>)", &AllocateObjectList->term)) {
      return ATfalse;
   }

   OFP_Traverse AllocateObject;
   ATermList AllocateObject_tail = (ATermList) ATmake("<term>", AllocateObjectList->term);
   while (! ATisEmpty(AllocateObject_tail)) {
      AllocateObject.term = ATgetFirst(AllocateObject_tail);
      AllocateObject_tail = ATgetNext (AllocateObject_tail);
      if (ofp_traverse_AllocateObject(AllocateObject.term, &AllocateObject)) {
         // MATCHED AllocateObject
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_AllocationList(ATerm term, pOFP_Traverse AllocationList)
{
#ifdef DEBUG_PRINT
   printf("AllocationList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "AllocationList(<term>)", &AllocationList->term)) {
      return ATfalse;
   }

   OFP_Traverse Allocation;
   ATermList Allocation_tail = (ATermList) ATmake("<term>", AllocationList->term);
   while (! ATisEmpty(Allocation_tail)) {
      Allocation.term = ATgetFirst(Allocation_tail);
      Allocation_tail = ATgetNext (Allocation_tail);
      if (ofp_traverse_Allocation(Allocation.term, &Allocation)) {
         // MATCHED Allocation
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_AllocOptList(ATerm term, pOFP_Traverse AllocOptList)
{
#ifdef DEBUG_PRINT
   printf("AllocOptList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "AllocOptList(<term>)", &AllocOptList->term)) {
      return ATfalse;
   }

   OFP_Traverse AllocOpt;
   ATermList AllocOpt_tail = (ATermList) ATmake("<term>", AllocOptList->term);
   while (! ATisEmpty(AllocOpt_tail)) {
      AllocOpt.term = ATgetFirst(AllocOpt_tail);
      AllocOpt_tail = ATgetNext (AllocOpt_tail);
      if (ofp_traverse_AllocOpt(AllocOpt.term, &AllocOpt)) {
         // MATCHED AllocOpt
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_CosubscriptList(ATerm term, pOFP_Traverse CosubscriptList)
{
#ifdef DEBUG_PRINT
   printf("CosubscriptList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "CosubscriptList(<term>)", &CosubscriptList->term)) {
      return ATfalse;
   }

   OFP_Traverse Cosubscript;
   ATermList Cosubscript_tail = (ATermList) ATmake("<term>", CosubscriptList->term);
   while (! ATisEmpty(Cosubscript_tail)) {
      Cosubscript.term = ATgetFirst(Cosubscript_tail);
      Cosubscript_tail = ATgetNext (Cosubscript_tail);
      if (ofp_traverse_Cosubscript(Cosubscript.term, &Cosubscript)) {
         // MATCHED Cosubscript
      } else return ATfalse;
   }
   return ATtrue;
}

ATbool ofp_traverse_SectionSubscriptList(ATerm term, pOFP_Traverse SectionSubscriptList)
{
#ifdef DEBUG_PRINT
   printf("SectionSubscriptList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "SectionSubscriptList(<term>)", &SectionSubscriptList->term)) {
      return ATfalse;
   }

   OFP_Traverse SectionSubscript;
   ATermList SectionSubscript_tail = (ATermList) ATmake("<term>", SectionSubscriptList->term);
   while (! ATisEmpty(SectionSubscript_tail)) {
      SectionSubscript.term = ATgetFirst(SectionSubscript_tail);
      SectionSubscript_tail = ATgetNext (SectionSubscript_tail);
      if (ofp_traverse_SectionSubscript(SectionSubscript.term, &SectionSubscript)) {
         // MATCHED SectionSubscript
      } else return ATfalse;
   }
   return ATtrue;
}
#endif
