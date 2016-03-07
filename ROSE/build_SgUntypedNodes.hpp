#include "rosePublicConfig.h"
#include "sage3basic.h"

SgLocatedNode* build_SgLocatedNode();

SgLocatedNodeSupport* build_SgLocatedNodeSupport();

SgUntypedNode* build_SgUntypedNode();

SgUntypedExpression* build_SgUntypedExpression(SgToken_ROSE_Fortran_Keywords* arg1);

SgToken_ROSE_Fortran_Keywords* build_SgToken_ROSE_Fortran_Keywords(int arg1);

SgToken_ROSE_Fortran_Operators* build_SgToken_ROSE_Fortran_Operators(int arg1);

SgUntypedType_type_enum* build_SgUntypedType_type_enum(int arg1);

bool* build_bool(int arg1);

SgUntypedUnaryOperator* build_SgUntypedUnaryOperator(SgToken_ROSE_Fortran_Keywords* arg1, SgToken_ROSE_Fortran_Operators* arg2, char* arg3, SgUntypedExpression* arg4);

SgUntypedBinaryOperator* build_SgUntypedBinaryOperator(SgToken_ROSE_Fortran_Keywords* arg1, SgToken_ROSE_Fortran_Operators* arg2, char* arg3, SgUntypedExpression* arg4, SgUntypedExpression* arg5);

SgUntypedValueExpression* build_SgUntypedValueExpression(SgToken_ROSE_Fortran_Keywords* arg1, char* arg2, SgUntypedType* arg3);

SgUntypedArrayReferenceExpression* build_SgUntypedArrayReferenceExpression(SgToken_ROSE_Fortran_Keywords* arg1);

SgUntypedOtherExpression* build_SgUntypedOtherExpression(SgToken_ROSE_Fortran_Keywords* arg1);

SgUntypedFunctionCallOrArrayReferenceExpression* build_SgUntypedFunctionCallOrArrayReferenceExpression(SgToken_ROSE_Fortran_Keywords* arg1);

SgUntypedReferenceExpression* build_SgUntypedReferenceExpression(SgToken_ROSE_Fortran_Keywords* arg1, char* arg2);

SgUntypedImplicitDeclaration* build_SgUntypedImplicitDeclaration();

SgUntypedVariableDeclaration* build_SgUntypedVariableDeclaration(SgUntypedType* arg1);

SgUntypedFunctionDeclaration* build_SgUntypedFunctionDeclaration(char* arg1);

SgUntypedModuleDeclaration* build_SgUntypedModuleDeclaration();

SgUntypedProgramHeaderDeclaration* build_SgUntypedProgramHeaderDeclaration(char* arg1);

SgUntypedSubroutineDeclaration* build_SgUntypedSubroutineDeclaration(char* arg1);

SgUntypedStatement* build_SgUntypedStatement(char* arg1, SgToken_ROSE_Fortran_Keywords* arg2);

SgUntypedType* build_SgUntypedType(char* arg1, SgUntypedExpression* arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, SgUntypedExpression* arg9, char* arg10, int arg11, SgUntypedType_type_enum* arg12);

SgUntypedAttribute* build_SgUntypedAttribute(SgToken_ROSE_Fortran_Keywords* arg1, char* arg2);

SgUntypedInitializedName* build_SgUntypedInitializedName(SgUntypedType* arg1, char* arg2);

SgUntypedFile* build_SgUntypedFile(SgUntypedGlobalScope* arg1);

SgUntypedStatementList* build_SgUntypedStatementList();

SgUntypedDeclarationStatementList* build_SgUntypedDeclarationStatementList();

SgUntypedFunctionDeclarationList* build_SgUntypedFunctionDeclarationList();

SgUntypedInitializedNameList* build_SgUntypedInitializedNameList();

SgUntypedDeclarationStatement* build_SgUntypedDeclarationStatement(char* arg1, SgToken_ROSE_Fortran_Keywords* arg2);

SgUntypedAssignmentStatement* build_SgUntypedAssignmentStatement(char* arg1, SgToken_ROSE_Fortran_Keywords* arg2, SgUntypedExpression* arg3, SgUntypedExpression* arg4);

SgUntypedFunctionCallStatement* build_SgUntypedFunctionCallStatement(char* arg1, SgToken_ROSE_Fortran_Keywords* arg2);

SgUntypedBlockStatement* build_SgUntypedBlockStatement(char* arg1, SgToken_ROSE_Fortran_Keywords* arg2, SgUntypedScope* arg3);

SgUntypedNamedStatement* build_SgUntypedNamedStatement(char* arg1, SgToken_ROSE_Fortran_Keywords* arg2, char* arg3);

SgUntypedOtherStatement* build_SgUntypedOtherStatement(char* arg1, SgToken_ROSE_Fortran_Keywords* arg2);

SgUntypedScope* build_SgUntypedScope(char* arg1, SgToken_ROSE_Fortran_Keywords* arg2, SgUntypedDeclarationStatementList* arg3, SgUntypedStatementList* arg4, SgUntypedFunctionDeclarationList* arg5);

SgUntypedFunctionScope* build_SgUntypedFunctionScope(char* arg1, SgToken_ROSE_Fortran_Keywords* arg2, SgUntypedDeclarationStatementList* arg3, SgUntypedStatementList* arg4, SgUntypedFunctionDeclarationList* arg5);

SgUntypedModuleScope* build_SgUntypedModuleScope(char* arg1, SgToken_ROSE_Fortran_Keywords* arg2, SgUntypedDeclarationStatementList* arg3, SgUntypedStatementList* arg4, SgUntypedFunctionDeclarationList* arg5);

SgUntypedGlobalScope* build_SgUntypedGlobalScope(char* arg1, SgToken_ROSE_Fortran_Keywords* arg2, SgUntypedDeclarationStatementList* arg3, SgUntypedStatementList* arg4, SgUntypedFunctionDeclarationList* arg5);

SgUntypedArrayType* build_SgUntypedArrayType(char* arg1, SgUntypedExpression* arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, SgUntypedExpression* arg9, char* arg10, int arg11, SgUntypedType_type_enum* arg12, SgUntypedExpression* arg13);

