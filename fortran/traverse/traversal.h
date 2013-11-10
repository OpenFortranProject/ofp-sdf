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


/** Identifier aliases
 */

ATbool ofp_traverse_ObjectName(ATerm term, pOFP_Traverse ObjectName);
ATbool ofp_traverse_ProgramName(ATerm term, pOFP_Traverse ProgramName);

#endif
