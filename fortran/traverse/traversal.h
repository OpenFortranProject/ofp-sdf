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

/* R403 */
ATbool ofp_traverse_DeclarationTypeSpec(ATerm term, pOFP_Traverse DeclarationTypeSpec);

/* R404 */
ATbool ofp_traverse_IntrinsicTypeSpec(ATerm term, pOFP_Traverse IntrinsicTypeSpec);

/* R405 */
ATbool ofp_traverse_KindSelector(ATerm term, pOFP_Traverse KindSelector);

/* R407 */
ATbool ofp_traverse_IntLiteralConstant(ATerm term, pOFP_Traverse IntLiteralConstant);

/* R420 */
ATbool ofp_traverse_CharSelector(ATerm term, pOFP_Traverse CharSelector);

/* R421 */
ATbool ofp_traverse_LengthSelector(ATerm term, pOFP_Traverse LengthSelector);

/* R501 */
ATbool ofp_traverse_TypeDeclarationStmt(ATerm term, pOFP_Traverse TypeDeclarationStmt);

/* R503 */
ATbool ofp_traverse_EntityDecl(ATerm term, pOFP_Traverse EntityDecl);

/* R601 */
ATbool ofp_traverse_Designator(ATerm term, pOFP_Traverse Designator);

/* R602 */
ATbool ofp_traverse_Variable(ATerm term, pOFP_Traverse Variable);

/* R611 */
ATbool ofp_traverse_DataRef(ATerm term, pOFP_Traverse DataRef);

/* R612 */
ATbool ofp_traverse_PartRef(ATerm term, pOFP_Traverse PartRef);

/* R722 */
ATbool ofp_traverse_Expr(ATerm term, pOFP_Traverse Expr);

/* R732 */
ATbool ofp_traverse_AssignmentStmt(ATerm term, pOFP_Traverse AssignmentStmt);

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


/** Identifier aliases
 */

ATbool ofp_traverse_AncestorModuleName(ATerm term, pOFP_Traverse AncestorModuleName);
ATbool ofp_traverse_ArgName(ATerm term, pOFP_Traverse ArgName);
ATbool ofp_traverse_BindingName(ATerm term, pOFP_Traverse BindingName);
ATbool ofp_traverse_BlockDataName(ATerm term, pOFP_Traverse BlockDataName);
ATbool ofp_traverse_ComponentName(ATerm term, pOFP_Traverse ComponentName);
ATbool ofp_traverse_FinalSubroutineName(ATerm term, pOFP_Traverse FinalSubroutineName);
ATbool ofp_traverse_InterfaceName(ATerm term, pOFP_Traverse InterfaceName);
ATbool ofp_traverse_LocalName(ATerm term, pOFP_Traverse LocalName);
ATbool ofp_traverse_ModuleName(ATerm term, pOFP_Traverse ModuleName);
ATbool ofp_traverse_Name(ATerm term, pOFP_Traverse Name);
ATbool ofp_traverse_ObjectName(ATerm term, pOFP_Traverse ObjectName);
ATbool ofp_traverse_ParentSubmoduleName(ATerm term, pOFP_Traverse ParentSubmoduleName);
ATbool ofp_traverse_ParentTypeName(ATerm term, pOFP_Traverse ParentTypeName);
ATbool ofp_traverse_ProcedureName(ATerm term, pOFP_Traverse ProcedureName);
ATbool ofp_traverse_ProgramName(ATerm term, pOFP_Traverse ProgramName);
ATbool ofp_traverse_ScalarIntConstantName(ATerm term, pOFP_Traverse ScalarIntConstantName);
ATbool ofp_traverse_SubmoduleName(ATerm term, pOFP_Traverse SubmoduleName);
ATbool ofp_traverse_TypeName(ATerm term, pOFP_Traverse TypeName);
ATbool ofp_traverse_TypeParamName(ATerm term, pOFP_Traverse TypeParamName);
ATbool ofp_traverse_UseName(ATerm term, pOFP_Traverse UseName);

#endif /* OFP_TRAVERSAL_H */
