#ifndef	OFP_TRAVERSAL_H
#define	OFP_TRAVERSAL_H

#define DEBUG_PRINT

#include <aterm2.h>

enum DataType
{
   UNKNOWN,
   STRING,
   IDENT,
   LIST,
   OPTION,
   CONST,
   OR
};

typedef struct OFP_Traverse_struct
{
   ATerm       term;
   void*       pre;
   void*       post;

}
   OFP_Traverse, * pOFP_Traverse;

/**                                                                                             
 * Section/Clause 2: Fortran concepts
 */

/* R201 */
ATbool ofp_traverse_Program(ATerm term, pOFP_Traverse Program);

/* R202 */
ATbool ofp_traverse_ProgramUnit(ATerm term, pOFP_Traverse ProgramUnit);

/* R203 */
ATbool ofp_traverse_ExternalSubprogram(ATerm term, pOFP_Traverse ExternalSubprogram);

/* R204 */
ATbool ofp_traverse_SpecificationPart(ATerm term, pOFP_Traverse SpecificationPart);

/* R205 */
ATbool ofp_traverse_ImplicitPart(ATerm term, pOFP_Traverse ImplicitPart);

/* R206 */
ATbool ofp_traverse_ImplicitPartStmt(ATerm term, pOFP_Traverse ImplicitPartStmt);

/* R207 */
ATbool ofp_traverse_DeclarationConstruct(ATerm term, pOFP_Traverse DeclarationConstruct);

/* R208 */
ATbool ofp_traverse_ExecutionPart(ATerm term, pOFP_Traverse ExecutionPart);

/* R209 */
ATbool ofp_traverse_ExecutionPartConstruct(ATerm term, pOFP_Traverse ExecutionPartConstruct);

/* R210 */
ATbool ofp_traverse_InternalSubprogramPart(ATerm term, pOFP_Traverse InternalSubprogramPart);

/* R211 */
ATbool ofp_traverse_InternalSubprogram(ATerm term, pOFP_Traverse InternalSubprogram);

/* R212 */
ATbool ofp_traverse_OtherSpecificationStmt(ATerm term, pOFP_Traverse OtherSpecificationStmt);

/* R213 */
ATbool ofp_traverse_ExecutableConstruct(ATerm term, pOFP_Traverse ExecutableConstruct);

/* R214 */
ATbool ofp_traverse_ActionStmt(ATerm term, pOFP_Traverse ActionStmt);

/* R215 */
ATbool ofp_traverse_Keyword(ATerm term, pOFP_Traverse Keyword);

/**                                                                                             
 * Section/Clause 3: Lexical tokens and source form
 */

/* R304 */
ATbool ofp_traverse_Constant(ATerm term, pOFP_Traverse Constant);

/* R305 */
ATbool ofp_traverse_LiteralConstant(ATerm term, pOFP_Traverse LiteralConstant);

/* R306 */
ATbool ofp_traverse_NamedConstant(ATerm term, pOFP_Traverse NamedConstant);

/**                                                                                             
 * Section/Clause 4: Types                                                                      
 */

/* R401 */
ATbool ofp_traverse_TypeParamValue(ATerm term, pOFP_Traverse TypeParamValue);

/* R402 */
ATbool ofp_traverse_TypeSpec(ATerm term, pOFP_Traverse TypeSpec);

/* R403 */
ATbool ofp_traverse_DeclarationTypeSpec(ATerm term, pOFP_Traverse DeclarationTypeSpec);

/* R404 */
ATbool ofp_traverse_IntrinsicTypeSpec(ATerm term, pOFP_Traverse IntrinsicTypeSpec);

/* R405 */
ATbool ofp_traverse_KindSelector(ATerm term, pOFP_Traverse KindSelector);

/* R406 */
ATbool ofp_traverse_SignedIntLiteralConstant(ATerm term, pOFP_Traverse SignedIntLiteralConstant);

/* R407 */
ATbool ofp_traverse_IntLiteralConstant(ATerm term, pOFP_Traverse IntLiteralConstant);

/* R408 */
ATbool ofp_traverse_KindParam(ATerm term, pOFP_Traverse KindParam);

/* R409 */

/* R410 */
ATbool ofp_traverse_DigitString(ATerm term, pOFP_Traverse DigitString);

/* R411 */
ATbool ofp_traverse_Sign(ATerm term, pOFP_Traverse Sign);

/* R412 */
ATbool ofp_traverse_SignedRealLiteralConstant(ATerm term, pOFP_Traverse SignedRealLiteralConstant);

/* R413 */
ATbool ofp_traverse_RealLiteralConstant(ATerm term, pOFP_Traverse RealLiteralConstant);

/* R417 */
ATbool ofp_traverse_ComplexLiteralConstant(ATerm term, pOFP_Traverse ComplexLiteralConstant);

/* R418 */
ATbool ofp_traverse_RealPart(ATerm term, pOFP_Traverse RealPart);

/* R419 */
ATbool ofp_traverse_ImagPart(ATerm term, pOFP_Traverse ImagPart);

/* R420 */
ATbool ofp_traverse_CharSelector(ATerm term, pOFP_Traverse CharSelector);

/* R421 */
ATbool ofp_traverse_LengthSelector(ATerm term, pOFP_Traverse LengthSelector);

/* R422 */
ATbool ofp_traverse_CharLength(ATerm term, pOFP_Traverse CharLength);

/* R423 */
ATbool ofp_traverse_CharLiteralConstant(ATerm term, pOFP_Traverse CharLiteralConstant);

/* R424 */
ATbool ofp_traverse_LogicalLiteralConstant(ATerm term, pOFP_Traverse LogicalLiteralConstant);

/* R425 */
ATbool ofp_traverse_DerivedTypeDef(ATerm term, pOFP_Traverse DerivedTypeDef);

/* R426 */
ATbool ofp_traverse_DerivedTypeStmt(ATerm term, pOFP_Traverse DerivedTypeStmt);
ATbool ofp_traverse_OptTypeAttrSpecList(ATerm term, pOFP_Traverse OptTypeAttrSpecList);
ATbool ofp_traverse_OptTypeParamNameList(ATerm term, pOFP_Traverse OptTypeParamNameList);

/* R427 */
ATbool ofp_traverse_TypeAttrSpec(ATerm term, pOFP_Traverse TypeAttrSpec);
ATbool ofp_traverse_TypeAttrSpecList(ATerm term, pOFP_Traverse TypeAttrSpecList);
ATbool ofp_traverse_TypeParamNameList(ATerm term, pOFP_Traverse TypeParamNameList);

/* R428 */
ATbool ofp_traverse_PrivateOrSequence(ATerm term, pOFP_Traverse PrivateOrSequence);

/* R429 */
ATbool ofp_traverse_EndTypeStmt(ATerm term, pOFP_Traverse EndTypeStmt);

/* R430 */
ATbool ofp_traverse_SequenceStmt(ATerm term, pOFP_Traverse SequenceStmt);

/* R431 */
ATbool ofp_traverse_TypeParamDefStmt(ATerm term, pOFP_Traverse TypeParamDefStmt);

/* R432 */
ATbool ofp_traverse_TypeParamDecl(ATerm term, pOFP_Traverse TypeParamDecl);
ATbool ofp_traverse_TypeParamDeclList(ATerm term, pOFP_Traverse TypeParamDeclList);

/* R433 */
ATbool ofp_traverse_TypeParamAttrSpec(ATerm term, pOFP_Traverse TypeParamAttrSpec);

/* R434 */
ATbool ofp_traverse_ComponentPart(ATerm term, pOFP_Traverse ComponentPart);

/* R435 */
ATbool ofp_traverse_ComponentDefStmt(ATerm term, pOFP_Traverse ComponentDefStmt);

/* R436 */
ATbool ofp_traverse_DataComponentDefStmt(ATerm term, pOFP_Traverse DataComponentDefStmt);
ATbool ofp_traverse_OptComponentAttrSpecList(ATerm term, pOFP_Traverse OptComponentAttrSpecList);

/* R437 */
ATbool ofp_traverse_ComponentAttrSpec(ATerm term, pOFP_Traverse ComponentAttrSpec);
ATbool ofp_traverse_ComponentAttrSpecList(ATerm term, pOFP_Traverse ComponentAttrSpecList);

/* R438 */
ATbool ofp_traverse_ComponentDecl(ATerm term, pOFP_Traverse ComponentDecl);
ATbool ofp_traverse_ComponentDeclList(ATerm term, pOFP_Traverse ComponentDeclList);

/* R439 */
ATbool ofp_traverse_ComponentArraySpec(ATerm term, pOFP_Traverse ComponentArraySpec);

/* R440 */
ATbool ofp_traverse_ProcComponentDefStmt(ATerm term, pOFP_Traverse ProcComponentDefStmt);

/* R441 */
ATbool ofp_traverse_ProcComponentAttrSpec(ATerm term, pOFP_Traverse ProcComponentAttrSpec);
ATbool ofp_traverse_ProcComponentAttrSpecList(ATerm term, pOFP_Traverse ProcComponentAttrSpecList);

/* R442 */
ATbool ofp_traverse_ComponentInitialization(ATerm term, pOFP_Traverse ComponentInitialization);

/* R443 */
ATbool ofp_traverse_InitialDataTarget(ATerm term, pOFP_Traverse InitialDataTarget);

/* R444 */
ATbool ofp_traverse_PrivateComponentsStmt(ATerm term, pOFP_Traverse PrivateComponentsStmt);

/* R445 */
ATbool ofp_traverse_TypeBoundProcedurePart(ATerm term, pOFP_Traverse TypeBoundProcedurePart);

/* R446 */
ATbool ofp_traverse_BindingPrivateStmt(ATerm term, pOFP_Traverse BindingPrivateStmt);

/* R447 */
ATbool ofp_traverse_TypeBoundProcBinding(ATerm term, pOFP_Traverse TypeBoundProcBinding);

/* R448 */
ATbool ofp_traverse_TypeBoundProcedureStmt(ATerm term, pOFP_Traverse TypeBoundProcedureStmt);
ATbool ofp_traverse_BindingNameList(ATerm term, pOFP_Traverse BindingNameList);
ATbool ofp_traverse_BindingAttrList(ATerm term, pOFP_Traverse BindingAttrList);

/* R449 */
ATbool ofp_traverse_TypeBoundProcDecl(ATerm term, pOFP_Traverse TypeBoundProcDecl);
ATbool ofp_traverse_TypeBoundProcDeclList(ATerm term, pOFP_Traverse TypeBoundProcDeclList);

/* R450 */
ATbool ofp_traverse_TypeBoundGenericStmt(ATerm term, pOFP_Traverse TypeBoundGenericStmt);

/* R451 */
ATbool ofp_traverse_BindingAttr(ATerm term, pOFP_Traverse BindingAttr);

/* R452 */
ATbool ofp_traverse_FinalProcedureStmt(ATerm term, pOFP_Traverse FinalProcedureStmt);
ATbool ofp_traverse_FinalSubroutineNameList(ATerm term, pOFP_Traverse FinalSubroutineNameList);

/* R453 */
ATbool ofp_traverse_DerivedTypeSpec(ATerm term, pOFP_Traverse DerivedTypeSpec);

/* R454 */
ATbool ofp_traverse_TypeParamSpec(ATerm term, pOFP_Traverse TypeParamSpec);
ATbool ofp_traverse_TypeParamSpecList(ATerm term, pOFP_Traverse TypeParamSpecList);

/* R455 */
ATbool ofp_traverse_StructureConstructor(ATerm term, pOFP_Traverse StructureConstructor);

/* R456 */
ATbool ofp_traverse_ComponentSpec(ATerm term, pOFP_Traverse ComponentSpec);

/* R457 */
ATbool ofp_traverse_ComponentDataSource(ATerm term, pOFP_Traverse ComponentDataSource);

/* R458 */
ATbool ofp_traverse_EnumDef(ATerm term, pOFP_Traverse EnumDef);

/* R459 */
ATbool ofp_traverse_EnumDefStmt(ATerm term, pOFP_Traverse EnumDefStmt);

/* R460 */
ATbool ofp_traverse_EnumeratorDefStmt(ATerm term, pOFP_Traverse EnumeratorDefStmt);

/* R461 */
ATbool ofp_traverse_Enumerator(ATerm term, pOFP_Traverse Enumerator);
ATbool ofp_traverse_EnumeratorList(ATerm term, pOFP_Traverse EnumeratorList);

/* R462 */
ATbool ofp_traverse_EndEnumStmt(ATerm term, pOFP_Traverse EndEnumStmt);

/* R463 */
ATbool ofp_traverse_BozLiteralConstant(ATerm term, pOFP_Traverse BozLiteralConstant);

/* R464 */
/* R465 */
/* R466 */
/* R467 */

/* R468 */
ATbool ofp_traverse_ArrayConstructor(ATerm term, pOFP_Traverse ArrayConstructor);

/* R469 */
ATbool ofp_traverse_AcSpec(ATerm term, pOFP_Traverse AcSpec);

/* R470 */
ATbool ofp_traverse_AcValue(ATerm term, pOFP_Traverse AcValue);

/* R471 */
ATbool ofp_traverse_AcValueList(ATerm term, pOFP_Traverse AcValueList);

/* R472 */
ATbool ofp_traverse_AcImpliedDo(ATerm term, pOFP_Traverse AcImpliedDo);

/* R473 */
ATbool ofp_traverse_AcImpliedDoControl(ATerm term, pOFP_Traverse AcImpliedDoControl);

/* R474 */
ATbool ofp_traverse_AcDoVariable(ATerm term, pOFP_Traverse AcDoVariable);

/* R501 */
ATbool ofp_traverse_TypeDeclarationStmt(ATerm term, pOFP_Traverse TypeDeclarationStmt);

/* R503 */
ATbool ofp_traverse_EntityDecl(ATerm term, pOFP_Traverse EntityDecl);

/* R601 */
ATbool ofp_traverse_Designator(ATerm term, pOFP_Traverse Designator);

/* R602 */
ATbool ofp_traverse_Variable(ATerm term, pOFP_Traverse Variable);

/* R603 */
ATbool ofp_traverse_VariableName(ATerm term, pOFP_Traverse VariableName);

/* R604 */
ATbool ofp_traverse_LogicalVariable(ATerm term, pOFP_Traverse LogicalVariable);

/* R605 */
ATbool ofp_traverse_CharVariable(ATerm term, pOFP_Traverse CharVariable);

/* R606 */
ATbool ofp_traverse_DefaultCharVariable(ATerm term, pOFP_Traverse DefaultCharVariable);

/* R607 */
ATbool ofp_traverse_IntVariable(ATerm term, pOFP_Traverse IntVariable);

/* R608 */
ATbool ofp_traverse_Substring(ATerm term, pOFP_Traverse Substring);

/* R609 */
ATbool ofp_traverse_ParentString(ATerm term, pOFP_Traverse ParentString);

/* R610 */
ATbool ofp_traverse_SubstringRange(ATerm term, pOFP_Traverse SubstringRange);

/* R611 */
ATbool ofp_traverse_DataRef(ATerm term, pOFP_Traverse DataRef);

/* R612 */
ATbool ofp_traverse_PartRef(ATerm term, pOFP_Traverse PartRef);

/* R613 */
ATbool ofp_traverse_StructureComponent(ATerm term, pOFP_Traverse StructureComponent);

/* R614 */
ATbool ofp_traverse_CoindexedNamedObject(ATerm term, pOFP_Traverse CoindexedNamedObject);

/* R615 ComplexPartDesignator */

/* R616 */
ATbool ofp_traverse_TypeParamInquiry(ATerm term, pOFP_Traverse TypeParamInquiry);


/* R722 */
ATbool ofp_traverse_Expr(ATerm term, pOFP_Traverse Expr);

/* R732 */
ATbool ofp_traverse_AssignmentStmt(ATerm term, pOFP_Traverse AssignmentStmt);

/* R801 */
ATbool ofp_traverse_Block(ATerm term, pOFP_Traverse Block);

/* R802 */
ATbool ofp_traverse_AssociateConstruct(ATerm term, pOFP_Traverse AssociateConstruct);

/* R803 */
ATbool ofp_traverse_AssociateStmt(ATerm term, pOFP_Traverse AssociateStmt);

/* R804 */
ATbool ofp_traverse_Association(ATerm term, pOFP_Traverse Association);
ATbool ofp_traverse_AssociationList(ATerm term, pOFP_Traverse AssociationList);

/* R805 */
ATbool ofp_traverse_Selector(ATerm term, pOFP_Traverse Selector);

/* R806 */
ATbool ofp_traverse_EndAssociateStmt(ATerm term, pOFP_Traverse EndAssociateStmt);

/* R807 */
ATbool ofp_traverse_BlockConstruct(ATerm term, pOFP_Traverse BlockConstruct);

/* R808 */
ATbool ofp_traverse_BlockStmt(ATerm term, pOFP_Traverse BlockStmt);

/* R809 */
ATbool ofp_traverse_EndBlockStmt(ATerm term, pOFP_Traverse EndBlockStmt);

/* R810 */
ATbool ofp_traverse_CriticalConstruct(ATerm term, pOFP_Traverse CriticalConstruct);

/* R811 */
ATbool ofp_traverse_CriticalStmt(ATerm term, pOFP_Traverse CriticalStmt);

/* R812 */
ATbool ofp_traverse_EndCriticalStmt(ATerm term, pOFP_Traverse EndCriticalStmt);

/* R813 */
/* R814 */
/* R815 */

/* R816 */
ATbool ofp_traverse_LabelDoStmt(ATerm term, pOFP_Traverse LabelDoStmt);

/* R817 */
ATbool ofp_traverse_NonlabelDoStmt(ATerm term, pOFP_Traverse NonlabelDoStmt);

/* R818 */
ATbool ofp_traverse_LoopControl(ATerm term, pOFP_Traverse LoopControl);

/* R819 */
ATbool ofp_traverse_DoVariable(ATerm term, pOFP_Traverse DoVariable);

/* R820 */
/* R821 */

/* R822 */
ATbool ofp_traverse_EndDoStmt(ATerm term, pOFP_Traverse EndDoStmt);

/* R823 */
/* R824 */
/* R825 */
/* R826 */
/* R827 */
/* R828 */
/* R829 */
/* R830 */

/* R831 */
ATbool ofp_traverse_CycleStmt(ATerm term, pOFP_Traverse CycleStmt);

/* R832 TODO: IfConstruct */

/* R833 */
ATbool ofp_traverse_IfThenStmt(ATerm term, pOFP_Traverse IfThenStmt);

/* R834 */
ATbool ofp_traverse_ElseIfStmt(ATerm term, pOFP_Traverse ElseIfStmt);

/* R835 */
ATbool ofp_traverse_ElseStmt(ATerm term, pOFP_Traverse ElseStmt);

/* R836 */
ATbool ofp_traverse_EndIfStmt(ATerm term, pOFP_Traverse EndIfStmt);

/* R837 */
ATbool ofp_traverse_IfStmt(ATerm term, pOFP_Traverse IfStmt);

/* R838 TODO: CaseConstruct */

/* R839 */
ATbool ofp_traverse_SelectCaseStmt(ATerm term, pOFP_Traverse SelectCaseStmt);

/* R840 */
ATbool ofp_traverse_CaseStmt(ATerm term, pOFP_Traverse CaseStmt);

/* R841 */
ATbool ofp_traverse_EndSelectStmt(ATerm term, pOFP_Traverse EndSelectStmt);

/* R842 */
ATbool ofp_traverse_CaseExpr(ATerm term, pOFP_Traverse CaseExpr);

/* R843 */
ATbool ofp_traverse_CaseSelector(ATerm term, pOFP_Traverse CaseSelector);

/* R844 */
ATbool ofp_traverse_CaseValueRange(ATerm term, pOFP_Traverse CaseValueRange);
ATbool ofp_traverse_CaseValueRangeList(ATerm term, pOFP_Traverse CaseValueRangeList);

/* R845 */
ATbool ofp_traverse_CaseValue(ATerm term, pOFP_Traverse CaseValue);

/* R846 TODO: SelectTypeConstruct */

/* R847 */
ATbool ofp_traverse_SelectTypeStmt(ATerm term, pOFP_Traverse SelectTypeStmt);

/* R848 */
ATbool ofp_traverse_TypeGuardStmt(ATerm term, pOFP_Traverse TypeGuardStmt);

/* R849 */
ATbool ofp_traverse_EndSelectTypeStmt(ATerm term, pOFP_Traverse EndSelectTypeStmt);

/* R850 */
ATbool ofp_traverse_ExitStmt(ATerm term, pOFP_Traverse ExitStmt);

/* R851 */
ATbool ofp_traverse_GotoStmt(ATerm term, pOFP_Traverse GotoStmt);

/* R852 */
ATbool ofp_traverse_ComputedGotoStmt(ATerm term, pOFP_Traverse ComputedGotoStmt);

/* R853 */
ATbool ofp_traverse_ArithmeticIfStmt(ATerm term, pOFP_Traverse ArithmeticIfStmt);

/* R854 */
ATbool ofp_traverse_ContinueStmt(ATerm term, pOFP_Traverse ContinueStmt);

/* R855 */
ATbool ofp_traverse_StopStmt(ATerm term, pOFP_Traverse StopStmt);

/* R856 */
ATbool ofp_traverse_ErrorStopStmt(ATerm term, pOFP_Traverse ErrorStopStmt);

/* R857 */
ATbool ofp_traverse_StopCode(ATerm term, pOFP_Traverse StopCode);

/* R858 */
ATbool ofp_traverse_SyncAllStmt(ATerm term, pOFP_Traverse SyncAllStmt);

/* R859 */
ATbool ofp_traverse_SyncStat(ATerm term, pOFP_Traverse SyncStat);
ATbool ofp_traverse_SyncStatList(ATerm term, pOFP_Traverse SyncStatList);

/* R860 */
ATbool ofp_traverse_SyncImagesStmt(ATerm term, pOFP_Traverse SyncImagesStmt);

/* R861 */
ATbool ofp_traverse_ImageSet(ATerm term, pOFP_Traverse ImageSet);

/* R862 */
ATbool ofp_traverse_SyncMemoryStmt(ATerm term, pOFP_Traverse SyncMemoryStmt);

/* R863 */
ATbool ofp_traverse_LockStmt(ATerm term, pOFP_Traverse LockStmt);

/* R864 */
ATbool ofp_traverse_LockStat(ATerm term, pOFP_Traverse LockStat);
ATbool ofp_traverse_LockStatList(ATerm term, pOFP_Traverse LockStatList);

/* R865 */
ATbool ofp_traverse_UnlockStmt(ATerm term, pOFP_Traverse UnlockStmt);

/* R866 */
ATbool ofp_traverse_LockVariable(ATerm term, pOFP_Traverse LockVariable);

/* Obsolete feature */
ATbool ofp_traverse_PauseStmt(ATerm term, pOFP_Traverse PauseStmt);

/* R901 */
ATbool ofp_traverse_IoUnit(ATerm term, pOFP_Traverse IoUnit);

/* R902 */
ATbool ofp_traverse_FileUnitNumber(ATerm term, pOFP_Traverse FileUnitNumber);

/* R904 */
ATbool ofp_traverse_OpenStmt(ATerm term, pOFP_Traverse OpenStmt);

/* R905 */
ATbool ofp_traverse_ConnectSpec(ATerm term, pOFP_Traverse ConnectSpec);
ATbool ofp_traverse_ConnectSpecList(ATerm term, pOFP_Traverse ConnectSpecList);

/* R906 */
ATbool ofp_traverse_FileNameExpr(ATerm term, pOFP_Traverse FileNameExpr);

/* R907 */
ATbool ofp_traverse_IomsgVariable(ATerm term, pOFP_Traverse IomsgVariable);

/* R908 */
ATbool ofp_traverse_CloseStmt(ATerm term, pOFP_Traverse CloseStmt);

/* R909 */
ATbool ofp_traverse_CloseSpec(ATerm term, pOFP_Traverse CloseSpec);
ATbool ofp_traverse_CloseSpecList(ATerm term, pOFP_Traverse CloseSpecList);

/* R910 */
ATbool ofp_traverse_ReadStmt(ATerm term, pOFP_Traverse ReadStmt);

/* R911 */
ATbool ofp_traverse_WriteStmt(ATerm term, pOFP_Traverse WriteStmt);

/* R912 */
ATbool ofp_traverse_PrintStmt(ATerm term, pOFP_Traverse PrintStmt);

/* R913 */
ATbool ofp_traverse_IoControlSpec(ATerm term, pOFP_Traverse IoControlSpec);
ATbool ofp_traverse_IoControlSpecList(ATerm term, pOFP_Traverse IoControlSpecList);

/* R914 */
ATbool ofp_traverse_IdVariable(ATerm term, pOFP_Traverse IdVariable);

/* R915 */
ATbool ofp_traverse_Format(ATerm term, pOFP_Traverse Format);

/* R916 */
ATbool ofp_traverse_InputItem(ATerm term, pOFP_Traverse InputItem);
ATbool ofp_traverse_InputItemList(ATerm term, pOFP_Traverse InputItemList);

/* R917 */
ATbool ofp_traverse_OutputItem(ATerm term, pOFP_Traverse OutputItem);
ATbool ofp_traverse_OutputItemList(ATerm term, pOFP_Traverse OutputItemList);

/* R918 */
ATbool ofp_traverse_IoImpliedDo(ATerm term, pOFP_Traverse IoImpliedDo);

/* R919 */
ATbool ofp_traverse_IoImpliedDoObject(ATerm term, pOFP_Traverse IoImpliedDoObject);
ATbool ofp_traverse_IoImpliedDoObjectList(ATerm term, pOFP_Traverse IoImpliedDoObjectList);

/* R921 */
ATbool ofp_traverse_IoImpliedDoControl(ATerm term, pOFP_Traverse IoImpliedDoControl);

/* R922 */
ATbool ofp_traverse_WaitStmt(ATerm term, pOFP_Traverse WaitStmt);

/* R923 */
ATbool ofp_traverse_WaitSpec(ATerm term, pOFP_Traverse WaitSpec);
ATbool ofp_traverse_WaitSpecList(ATerm term, pOFP_Traverse WaitSpecList);

/* R924 */
ATbool ofp_traverse_BackspaceStmt(ATerm term, pOFP_Traverse BackspaceStmt);

/* R925 */
ATbool ofp_traverse_EndfileStmt(ATerm term, pOFP_Traverse EndfileStmt);

/* R926 */
ATbool ofp_traverse_RewindStmt(ATerm term, pOFP_Traverse RewindStmt);

/* R927 */
ATbool ofp_traverse_PositionSpec(ATerm term, pOFP_Traverse PositionSpec);
ATbool ofp_traverse_PositionSpecList(ATerm term, pOFP_Traverse PositionSpecList);

/* R928 */
ATbool ofp_traverse_FlushStmt(ATerm term, pOFP_Traverse FlushStmt);

/* R929 */
ATbool ofp_traverse_FlushSpec(ATerm term, pOFP_Traverse FlushSpec);
ATbool ofp_traverse_FlushSpecList(ATerm term, pOFP_Traverse FlushSpecList);

/* R930 */
ATbool ofp_traverse_InquireStmt(ATerm term, pOFP_Traverse InquireStmt);

/* R931 */
ATbool ofp_traverse_InquireSpec(ATerm term, pOFP_Traverse InquireSpec);
ATbool ofp_traverse_InquireSpecList(ATerm term, pOFP_Traverse InquireSpecList);

/* R1101 */
ATbool ofp_traverse_MainProgram(ATerm term, pOFP_Traverse MainProgram);

/* R1102 */
ATbool ofp_traverse_ProgramStmt(ATerm term, pOFP_Traverse ProgramStmt);

/* R1103 */
ATbool ofp_traverse_EndProgramStmt(ATerm term, pOFP_Traverse EndProgramStmt);

/* R1104 */
ATbool ofp_traverse_Module(ATerm term, pOFP_Traverse Module);

/* R1105 */
ATbool ofp_traverse_ModuleStmt(ATerm term, pOFP_Traverse ModuleStmt);

/* R1106 */
ATbool ofp_traverse_EndModuleStmt(ATerm term, pOFP_Traverse EndModuleStmt);

/* R1107 */
ATbool ofp_traverse_ModuleSubprogramPart(ATerm term, pOFP_Traverse ModuleSubprogramPart);

/* R1108 */
ATbool ofp_traverse_ModuleSubprogram(ATerm term, pOFP_Traverse ModuleSubprogram);

/* R1109 */
ATbool ofp_traverse_UseStmt(ATerm term, pOFP_Traverse UseStmt);

/* R1110 */
ATbool ofp_traverse_ModuleNature(ATerm term, pOFP_Traverse ModuleNature);

/* R1111 */
ATbool ofp_traverse_Rename(ATerm term, pOFP_Traverse Rename);
ATbool ofp_traverse_RenameList(ATerm term, pOFP_Traverse RenameList);

/* R1112 */
ATbool ofp_traverse_Only(ATerm term, pOFP_Traverse Only);
ATbool ofp_traverse_OnlyList(ATerm term, pOFP_Traverse OnlyList);

/* R1113 */
ATbool ofp_traverse_OnlyUseName(ATerm term, pOFP_Traverse OnlyUseName);

/* R1114 */
ATbool ofp_traverse_LocalDefinedOperator(ATerm term, pOFP_Traverse LocalDefinedOperator);

/* R1115 */
ATbool ofp_traverse_UseDefinedOperator(ATerm term, pOFP_Traverse UseDefinedOperator);

/* R1116 */
ATbool ofp_traverse_Submodule(ATerm term, pOFP_Traverse Submodule);

/* R1117 */
ATbool ofp_traverse_SubmoduleStmt(ATerm term, pOFP_Traverse SubmoduleStmt);

/* R1118 */
ATbool ofp_traverse_ParentIdentifier(ATerm term, pOFP_Traverse ParentIdentifier);

/* R1119 */
ATbool ofp_traverse_EndSubmoduleStmt(ATerm term, pOFP_Traverse EndSubmoduleStmt);

/* R1120 */
ATbool ofp_traverse_BlockData(ATerm term, pOFP_Traverse BlockData);

/* R1121 */
ATbool ofp_traverse_BlockDataStmt(ATerm term, pOFP_Traverse BlockDataStmt);

/* R1122 */
ATbool ofp_traverse_EndBlockDataStmt(ATerm term, pOFP_Traverse EndBlockDataStmt);

/* R1201 */
ATbool ofp_traverse_InterfaceBlock(ATerm term, pOFP_Traverse InterfaceBlock);

/* R1202 */
ATbool ofp_traverse_InterfaceSpecification(ATerm term, pOFP_Traverse InterfaceSpecification);

/* R1203 */
ATbool ofp_traverse_InterfaceStmt(ATerm term, pOFP_Traverse InterfaceStmt);

/* R1204 */
ATbool ofp_traverse_EndInterfaceStmt(ATerm term, pOFP_Traverse EndInterfaceStmt);

/* R1205 */
ATbool ofp_traverse_InterfaceBody(ATerm term, pOFP_Traverse InterfaceBody);

/* R1206 */
ATbool ofp_traverse_ProcedureStmt(ATerm term, pOFP_Traverse ProcedureStmt);
ATbool ofp_traverse_ProcedureNameList(ATerm term, pOFP_Traverse ProcedureNameList);

/* R1207 */
ATbool ofp_traverse_GenericSpec(ATerm term, pOFP_Traverse GenericSpec);

/* R1208 */
ATbool ofp_traverse_DefinedIoGenericSpec(ATerm term, pOFP_Traverse DefinedIoGenericSpec);

/* R1209 */
ATbool ofp_traverse_ImportStmt(ATerm term, pOFP_Traverse ImportStmt);
ATbool ofp_traverse_ImportNameList(ATerm term, pOFP_Traverse ImportNameList);

/* R1210 */
ATbool ofp_traverse_ExternalStmt(ATerm term, pOFP_Traverse ExternalStmt);

/* R1211 */
ATbool ofp_traverse_ProcedureDeclarationStmt(ATerm term, pOFP_Traverse ProcedureDeclarationStmt);

/* R1212 */
ATbool ofp_traverse_ProcInterface(ATerm term, pOFP_Traverse ProcInterface);

/* R1213 */
ATbool ofp_traverse_ProcAttrSpec(ATerm term, pOFP_Traverse ProcAttrSpec);
ATbool ofp_traverse_ProcAttrSpecList(ATerm term, pOFP_Traverse ProcAttrSpecList);

/* R1214 */
ATbool ofp_traverse_ProcDecl(ATerm term, pOFP_Traverse ProcDecl);
ATbool ofp_traverse_ProcDeclList(ATerm term, pOFP_Traverse ProcDeclList);

/* R1215 */
ATbool ofp_traverse_InterfaceName(ATerm term, pOFP_Traverse InterfaceName);

/* R1216 */
ATbool ofp_traverse_ProcPointerInit(ATerm term, pOFP_Traverse ProcPointerInit);

/* R1217 */
ATbool ofp_traverse_InitialProcTarget(ATerm term, pOFP_Traverse InitialProcTarget);

/* R1218 */
ATbool ofp_traverse_IntrinsicStmt(ATerm term, pOFP_Traverse IntrinsicStmt);
ATbool ofp_traverse_IntrinsicProcedureNameList(ATerm term, pOFP_Traverse IntrinsicProcedureNameList);

/* R1219 */
ATbool ofp_traverse_FunctionReference(ATerm term, pOFP_Traverse FunctionReference);

/* R1220 */
ATbool ofp_traverse_CallStmt(ATerm term, pOFP_Traverse CallStmt);

/* R1221 */
ATbool ofp_traverse_ProcedureDesignator(ATerm term, pOFP_Traverse ProcedureDesignator);

/* R1222 */
ATbool ofp_traverse_ActualArgSpec(ATerm term, pOFP_Traverse ActualArgSpec);
ATbool ofp_traverse_ActualArgSpecList(ATerm term, pOFP_Traverse ActualArgSpecList);

/* R1223 */
ATbool ofp_traverse_ActualArg(ATerm term, pOFP_Traverse ActualArg);

/* R1224 */
ATbool ofp_traverse_AltReturnSpec(ATerm term, pOFP_Traverse AltReturnSpec);

/* R1225 */
ATbool ofp_traverse_Prefix(ATerm term, pOFP_Traverse Prefix);

/* R1226 */
ATbool ofp_traverse_PrefixSpec(ATerm term, pOFP_Traverse PrefixSpec);

/* R1227 */
ATbool ofp_traverse_FunctionSubprogram(ATerm term, pOFP_Traverse FunctionSubprogram);

/* R1228 */
ATbool ofp_traverse_FunctionStmt(ATerm term, pOFP_Traverse FunctionStmt);

/* R1229 */
ATbool ofp_traverse_ProcLanguageBindingSpec(ATerm term, pOFP_Traverse ProcLanguageBindingSpec);

/* R1230 */
ATbool ofp_traverse_DummyArgName(ATerm term, pOFP_Traverse DummyArgName);

/* R1231 */
ATbool ofp_traverse_Suffix(ATerm term, pOFP_Traverse Suffix);

/* R1232 */
ATbool ofp_traverse_EndFunctionStmt(ATerm term, pOFP_Traverse EndFunctionStmt);

/* R1233 */
ATbool ofp_traverse_SubroutineSubprogram(ATerm term, pOFP_Traverse SubroutineSubprogram);

/* R1234 */
ATbool ofp_traverse_SubroutineStmt(ATerm term, pOFP_Traverse SubroutineStmt);

/* R1235 */
ATbool ofp_traverse_DummyArg(ATerm term, pOFP_Traverse DummyArg);
ATbool ofp_traverse_DummyArgList(ATerm term, pOFP_Traverse DummyArgList);

/* R1236 */
ATbool ofp_traverse_EndSubroutineStmt(ATerm term, pOFP_Traverse EndSubroutineStmt);

/* R1237 */
ATbool ofp_traverse_SeparateModuleSubprogram(ATerm term, pOFP_Traverse SeparateModuleSubprogram);

/* R1238 */
ATbool ofp_traverse_MpSubprogramStmt(ATerm term, pOFP_Traverse MpSubprogramStmt);

/* R1239 */
ATbool ofp_traverse_EndMpSubprogramStmt(ATerm term, pOFP_Traverse EndMpSubprogramStmt);

/* R1240 */
ATbool ofp_traverse_EntryStmt(ATerm term, pOFP_Traverse EntryStmt);

/* R1241 */
ATbool ofp_traverse_ReturnStmt(ATerm term, pOFP_Traverse ReturnStmt);

/* R1242 */
ATbool ofp_traverse_ContainsStmt(ATerm term, pOFP_Traverse ContainsStmt);

/* R1243 */
ATbool ofp_traverse_StmtFunctionStmt(ATerm term, pOFP_Traverse StmtFunctionStmt);


/** Identifier aliases
 */

ATbool ofp_traverse_AncestorModuleName(ATerm term, pOFP_Traverse AncestorModuleName);
ATbool ofp_traverse_ArgName(ATerm term, pOFP_Traverse ArgName);
ATbool ofp_traverse_AssociateConstructName(ATerm term, pOFP_Traverse AssociateConstructName);
ATbool ofp_traverse_AssociateName(ATerm term, pOFP_Traverse AssociateName);
ATbool ofp_traverse_BindingName(ATerm term, pOFP_Traverse BindingName);
ATbool ofp_traverse_BlockConstructName(ATerm term, pOFP_Traverse BlockConstructName);
ATbool ofp_traverse_BlockDataName(ATerm term, pOFP_Traverse BlockDataName);
ATbool ofp_traverse_CaseConstructName(ATerm term, pOFP_Traverse CaseConstructName);
ATbool ofp_traverse_ComponentName(ATerm term, pOFP_Traverse ComponentName);
ATbool ofp_traverse_ConstructName(ATerm term, pOFP_Traverse ConstructName);
ATbool ofp_traverse_CriticalConstructName(ATerm term, pOFP_Traverse CriticalConstructName);
ATbool ofp_traverse_DoConstructName(ATerm term, pOFP_Traverse DoConstructName);
ATbool ofp_traverse_IfConstructName(ATerm term, pOFP_Traverse IfConstructName);
ATbool ofp_traverse_EntryName(ATerm term, pOFP_Traverse EntryName);
ATbool ofp_traverse_ExternalName(ATerm term, pOFP_Traverse ExternalName);
ATbool ofp_traverse_FinalSubroutineName(ATerm term, pOFP_Traverse FinalSubroutineName);
ATbool ofp_traverse_FunctionName(ATerm term, pOFP_Traverse FunctionName);
ATbool ofp_traverse_GenericName(ATerm term, pOFP_Traverse GenericName);
ATbool ofp_traverse_ImportName(ATerm term, pOFP_Traverse ImportName);
ATbool ofp_traverse_InterfaceName(ATerm term, pOFP_Traverse InterfaceName);
ATbool ofp_traverse_IntrinsicProcedureName(ATerm term, pOFP_Traverse IntrinsicProcedureName);
ATbool ofp_traverse_LocalName(ATerm term, pOFP_Traverse LocalName);
ATbool ofp_traverse_ModuleName(ATerm term, pOFP_Traverse ModuleName);
ATbool ofp_traverse_Name(ATerm term, pOFP_Traverse Name);
ATbool ofp_traverse_NamelistGroupName(ATerm term, pOFP_Traverse NamelistGroupName);
ATbool ofp_traverse_ObjectName(ATerm term, pOFP_Traverse ObjectName);
ATbool ofp_traverse_ParentSubmoduleName(ATerm term, pOFP_Traverse ParentSubmoduleName);
ATbool ofp_traverse_ParentTypeName(ATerm term, pOFP_Traverse ParentTypeName);
ATbool ofp_traverse_PartName(ATerm term, pOFP_Traverse PartName);
ATbool ofp_traverse_ProcedureEntityName(ATerm term, pOFP_Traverse ProcedureEntityName);
ATbool ofp_traverse_ProcedureName(ATerm term, pOFP_Traverse ProcedureName);
ATbool ofp_traverse_ProgramName(ATerm term, pOFP_Traverse ProgramName);
ATbool ofp_traverse_ResultName(ATerm term, pOFP_Traverse ResultName);
ATbool ofp_traverse_ScalarIntConstantName(ATerm term, pOFP_Traverse ScalarIntConstantName);
ATbool ofp_traverse_ScalarIntVariableName(ATerm term, pOFP_Traverse ScalarIntVariableName);
ATbool ofp_traverse_SelectConstructName(ATerm term, pOFP_Traverse SelectConstructName);
ATbool ofp_traverse_SubmoduleName(ATerm term, pOFP_Traverse SubmoduleName);
ATbool ofp_traverse_SubroutineName(ATerm term, pOFP_Traverse SubroutineName);
ATbool ofp_traverse_TypeName(ATerm term, pOFP_Traverse TypeName);
ATbool ofp_traverse_TypeParamName(ATerm term, pOFP_Traverse TypeParamName);
ATbool ofp_traverse_UseName(ATerm term, pOFP_Traverse UseName);


/** Lists
 */

ATbool ofp_traverse_ExternalNameList(ATerm term, pOFP_Traverse ExternalNameList);
ATbool ofp_traverse_DummyArgNameList(ATerm term, pOFP_Traverse DummyArgNameList);
ATbool ofp_traverse_LabelList(ATerm term, pOFP_Traverse LabelList);


#endif /* OFP_TRAVERSAL_H */
