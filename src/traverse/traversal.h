#ifndef	OFP_TRAVERSAL_H
#define	OFP_TRAVERSAL_H

#include <aterm2.h>

typedef struct OFP_Traverse_struct
{
   ATerm       term;
   void*       pre;
   void*       post;

}
   OFP_Traverse, * pOFP_Traverse;

/* R201 */
ATbool ofp_traverse_Program(ATerm term, pOFP_Traverse StartCommentBlock_opt, pOFP_Traverse ProgramUnit_list);

/* R202 */
ATbool ofp_traverse_ProgramUnit(ATerm term, pOFP_Traverse ProgramUnit);

/* R204 */
ATbool ofp_traverse_SpecificationPart(ATerm term, pOFP_Traverse UseStmt_list, pOFP_Traverse ImportStmt_list, pOFP_Traverse ImplicitPart_opt, pOFP_Traverse DeclarationConstruct_list);

ATbool ofp_traverse_declaration_construct         (ATerm term);       // R207-F08
ATbool ofp_traverse_declaration_construct_list    (ATerm term);

/* R208 */
ATbool ofp_traverse_ExecutionPart(ATerm term, pOFP_Traverse ExecutionPartConstruct_list);

ATbool ofp_traverse_execution_part_construct      (ATerm term);       // R209-F08
ATbool ofp_traverse_executable_part_construct_list(ATerm term);

/* R210 */
ATbool ofp_traverse_InternalSubprogramPart(ATerm term, pOFP_Traverse ContainsStmt, pOFP_Traverse InternalSubprogram_list);

ATbool ofp_traverse_executable_construct          (ATerm term);       // R213-F08
ATbool ofp_traverse_action_stmt                   (ATerm term);       // R214-F08

ATbool ofp_traverse_declaration_type_spec        (ATerm term);        // R403-F08
ATbool ofp_traverse_intrinsic_type_spec          (ATerm term);        // R404-F08
ATbool ofp_traverse_int_literal_constant         (ATerm term);        // R407-F08

ATbool ofp_traverse_type_declaration_stmt        (ATerm term);        // R501-F08
ATbool ofp_traverse_entity_decl                  (ATerm term);        // R503-F08
ATbool ofp_traverse_entity_decl_list             (ATerm term);

ATbool ofp_traverse_designator                   (ATerm term);        // R601-F08
ATbool ofp_traverse_variable                     (ATerm term);        // R602-F08
ATbool ofp_traverse_data_ref                     (ATerm term);        // R611-F08
ATbool ofp_traverse_part_ref                     (ATerm term);        // R612-F08

ATbool ofp_traverse_expr                         (ATerm term);        // R722-F08
ATbool ofp_traverse_assignment_stmt              (ATerm term);        // R732-F08

/* R1101 */
ATbool ofp_traverse_MainProgram(ATerm term, pOFP_Traverse ProgramStmt_opt, pOFP_Traverse SpecificationPart, pOFP_Traverse ExecutionPart, pOFP_Traverse InternalSubprogramPart_opt, pOFP_Traverse EndProgramStmt);

/* R1102 */
ATbool ofp_traverse_ProgramStmt(ATerm term, pOFP_Traverse Label_opt, pOFP_Traverse ProgramName, pOFP_Traverse EOS);

/* R1103 */
ATbool ofp_traverse_EndProgramStmt(ATerm term, pOFP_Traverse Label_opt, pOFP_Traverse ProgramName_opt, pOFP_Traverse EOS);

#endif
