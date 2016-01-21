#include "build_SgUntypedNodes.hpp"
//========================================================================================
// SgUntypedAttribute
//----------------------------------------------------------------------------------------
SgUntypedAttribute* build_SgUntypedAttribute(int arg1, char* arg2)
{
#ifdef DEBUG_PRINT
  printf("... build_SgUntypedAttribute()");
#endif

  return new SgUntypedAttribute();
}

//========================================================================================
// SgUntypedInitializedName
//----------------------------------------------------------------------------------------
SgUntypedInitializedName* build_SgUntypedInitializedName(SgUntypedType* arg1, char* arg2)
{
#ifdef DEBUG_PRINT
  printf("... build_SgUntypedInitializedName()");
#endif

  return new SgUntypedInitializedName();
}

//========================================================================================
// SgUntypedFile
//----------------------------------------------------------------------------------------
SgUntypedFile* build_SgUntypedFile(SgUntypedGlobalScope* arg1)
{
#ifdef DEBUG_PRINT
  printf("... build_SgUntypedFile()");
#endif

  return new SgUntypedFile();
}

//========================================================================================
// SgUntypedStatementList
//----------------------------------------------------------------------------------------
SgUntypedStatementList* build_SgUntypedStatementList()
{
#ifdef DEBUG_PRINT
  printf("... build_SgUntypedStatementList()");
#endif

  return new SgUntypedStatementList();
}

//========================================================================================
// SgUntypedFunctionDeclarationList
//----------------------------------------------------------------------------------------
SgUntypedFunctionDeclarationList* build_SgUntypedFunctionDeclarationList()
{
#ifdef DEBUG_PRINT
  printf("... build_SgUntypedFunctionDeclarationList()");
#endif

  return new SgUntypedFunctionDeclarationList();
}

//========================================================================================
// SgUntypedInitializedNameList
//----------------------------------------------------------------------------------------
SgUntypedInitializedNameList* build_SgUntypedInitializedNameList()
{
#ifdef DEBUG_PRINT
  printf("... build_SgUntypedInitializedNameList()");
#endif

  return new SgUntypedInitializedNameList();
}

//========================================================================================
// SgUntypedValueExpression
//----------------------------------------------------------------------------------------
SgUntypedValueExpression* build_SgUntypedValueExpression(int arg1, char* arg2, SgUntypedType* arg3)
{
#ifdef DEBUG_PRINT
  printf("... build_SgUntypedValueExpression()");
#endif

  return new SgUntypedValueExpression();
}

//========================================================================================
// SgUntypedArrayReferenceExpression
//----------------------------------------------------------------------------------------
SgUntypedArrayReferenceExpression* build_SgUntypedArrayReferenceExpression(int arg1)
{
#ifdef DEBUG_PRINT
  printf("... build_SgUntypedArrayReferenceExpression()");
#endif

  return new SgUntypedArrayReferenceExpression();
}

//========================================================================================
// SgUntypedOtherExpression
//----------------------------------------------------------------------------------------
SgUntypedOtherExpression* build_SgUntypedOtherExpression(int arg1)
{
#ifdef DEBUG_PRINT
  printf("... build_SgUntypedOtherExpression()");
#endif

  return new SgUntypedOtherExpression();
}

//========================================================================================
// SgUntypedFunctionCallOrArrayReferenceExpression
//----------------------------------------------------------------------------------------
SgUntypedFunctionCallOrArrayReferenceExpression* build_SgUntypedFunctionCallOrArrayReferenceExpression(int arg1)
{
#ifdef DEBUG_PRINT
  printf("... build_SgUntypedFunctionCallOrArrayReferenceExpression()");
#endif

  return new SgUntypedFunctionCallOrArrayReferenceExpression();
}

//========================================================================================
// SgUntypedReferenceExpression
//----------------------------------------------------------------------------------------
SgUntypedReferenceExpression* build_SgUntypedReferenceExpression(int arg1, char* arg2)
{
#ifdef DEBUG_PRINT
  printf("... build_SgUntypedReferenceExpression()");
#endif

  return new SgUntypedReferenceExpression();
}

//========================================================================================
// SgUntypedAssignmentStatement
//----------------------------------------------------------------------------------------
SgUntypedAssignmentStatement* build_SgUntypedAssignmentStatement(char* arg1, int arg2, SgUntypedExpression* arg3, SgUntypedExpression* arg4)
{
#ifdef DEBUG_PRINT
  printf("... build_SgUntypedAssignmentStatement()");
#endif

  return new SgUntypedAssignmentStatement();
}

//========================================================================================
// SgUntypedFunctionCallStatement
//----------------------------------------------------------------------------------------
SgUntypedFunctionCallStatement* build_SgUntypedFunctionCallStatement(char* arg1, int arg2)
{
#ifdef DEBUG_PRINT
  printf("... build_SgUntypedFunctionCallStatement()");
#endif

  return new SgUntypedFunctionCallStatement();
}

//========================================================================================
// SgUntypedNamedStatement
//----------------------------------------------------------------------------------------
SgUntypedNamedStatement* build_SgUntypedNamedStatement(char* arg1, int arg2, char* arg3)
{
#ifdef DEBUG_PRINT
  printf("... build_SgUntypedNamedStatement()");
#endif

  return new SgUntypedNamedStatement();
}

//========================================================================================
// SgUntypedOtherStatement
//----------------------------------------------------------------------------------------
SgUntypedOtherStatement* build_SgUntypedOtherStatement(char* arg1, int arg2)
{
#ifdef DEBUG_PRINT
  printf("... build_SgUntypedOtherStatement()");
#endif

  return new SgUntypedOtherStatement();
}

//========================================================================================
// SgUntypedImplicitDeclaration
//----------------------------------------------------------------------------------------
SgUntypedImplicitDeclaration* build_SgUntypedImplicitDeclaration(char* arg1, int arg2)
{
#ifdef DEBUG_PRINT
  printf("... build_SgUntypedImplicitDeclaration()");
#endif

  return new SgUntypedImplicitDeclaration();
}

//========================================================================================
// SgUntypedVariableDeclaration
//----------------------------------------------------------------------------------------
SgUntypedVariableDeclaration* build_SgUntypedVariableDeclaration(char* arg1, int arg2, SgUntypedType* arg3, SgUntypedInitializedNameList* arg4)
{
#ifdef DEBUG_PRINT
  printf("... build_SgUntypedVariableDeclaration()");
#endif

  return new SgUntypedVariableDeclaration();
}

//========================================================================================
// SgUntypedModuleDeclaration
//----------------------------------------------------------------------------------------
SgUntypedModuleDeclaration* build_SgUntypedModuleDeclaration(char* arg1, int arg2, char* arg3, SgUntypedModuleScope* arg4, SgUntypedNamedStatement* arg5)
{
#ifdef DEBUG_PRINT
  printf("... build_SgUntypedModuleDeclaration()");
#endif

  return new SgUntypedModuleDeclaration();
}

//========================================================================================
// SgUntypedProgramHeaderDeclaration
//----------------------------------------------------------------------------------------
SgUntypedProgramHeaderDeclaration* build_SgUntypedProgramHeaderDeclaration(char* arg1, int arg2, char* arg3, SgUntypedInitializedNameList* arg4, SgUntypedType* arg5, SgUntypedFunctionScope* arg6, SgUntypedNamedStatement* arg7)
{
#ifdef DEBUG_PRINT
  printf("... build_SgUntypedProgramHeaderDeclaration()");
#endif

  return new SgUntypedProgramHeaderDeclaration();
}

//========================================================================================
// SgUntypedSubroutineDeclaration
//----------------------------------------------------------------------------------------
SgUntypedSubroutineDeclaration* build_SgUntypedSubroutineDeclaration(char* arg1, int arg2, char* arg3, SgUntypedInitializedNameList* arg4, SgUntypedType* arg5, SgUntypedFunctionScope* arg6, SgUntypedNamedStatement* arg7)
{
#ifdef DEBUG_PRINT
  printf("... build_SgUntypedSubroutineDeclaration()");
#endif

  return new SgUntypedSubroutineDeclaration();
}

//========================================================================================
// SgUntypedFunctionScope
//----------------------------------------------------------------------------------------
SgUntypedFunctionScope* build_SgUntypedFunctionScope(char* arg1, int arg2, SgUntypedDeclarationStatementList* arg3, SgUntypedStatementList* arg4, SgUntypedFunctionDeclarationList* arg5)
{
#ifdef DEBUG_PRINT
  printf("... build_SgUntypedFunctionScope()");
#endif

  return new SgUntypedFunctionScope();
}

//========================================================================================
// SgUntypedModuleScope
//----------------------------------------------------------------------------------------
SgUntypedModuleScope* build_SgUntypedModuleScope(char* arg1, int arg2, SgUntypedDeclarationStatementList* arg3, SgUntypedStatementList* arg4, SgUntypedFunctionDeclarationList* arg5)
{
#ifdef DEBUG_PRINT
  printf("... build_SgUntypedModuleScope()");
#endif

  return new SgUntypedModuleScope();
}

//========================================================================================
// SgUntypedGlobalScope
//----------------------------------------------------------------------------------------
SgUntypedGlobalScope* build_SgUntypedGlobalScope(char* arg1, int arg2, SgUntypedDeclarationStatementList* arg3, SgUntypedStatementList* arg4, SgUntypedFunctionDeclarationList* arg5)
{
#ifdef DEBUG_PRINT
  printf("... build_SgUntypedGlobalScope()");
#endif

  return new SgUntypedGlobalScope();
}

//========================================================================================
// SgUntypedArrayType
//----------------------------------------------------------------------------------------
SgUntypedArrayType* build_SgUntypedArrayType(char* arg1, SgUntypedExpression* arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, SgUntypedExpression* arg9, char* arg10, int arg11)
{
#ifdef DEBUG_PRINT
  printf("... build_SgUntypedArrayType()");
#endif

  return new SgUntypedArrayType();
}

//========================================================================================
// SgUntypedDeclarationStatementList
//----------------------------------------------------------------------------------------
SgUntypedDeclarationStatementList* build_SgUntypedDeclarationStatementList()
{
#ifdef DEBUG_PRINT
  printf("... build_SgUntypedDeclarationStatementList()");
#endif

  return new SgUntypedDeclarationStatementList();
}

//========================================================================================
// SgUntypedScope
//----------------------------------------------------------------------------------------
SgUntypedScope* build_SgUntypedScope(char* arg1, int arg2, SgUntypedDeclarationStatementList* arg3, SgUntypedStatementList* arg4, SgUntypedFunctionDeclarationList* arg5)
{
#ifdef DEBUG_PRINT
  printf("... build_SgUntypedScope()");
#endif

  return new SgUntypedScope();
}

//========================================================================================
// SgUntypedBlockStatement
//----------------------------------------------------------------------------------------
SgUntypedBlockStatement* build_SgUntypedBlockStatement(char* arg1, int arg2, char* arg3, SgUntypedScope* arg4, SgUntypedNamedStatement* arg5)
{
#ifdef DEBUG_PRINT
  printf("... build_SgUntypedBlockStatement()");
#endif

  return new SgUntypedBlockStatement();
}

//========================================================================================
// SgUntypedUnaryOperator
//----------------------------------------------------------------------------------------
SgUntypedUnaryOperator* build_SgUntypedUnaryOperator(int arg1, int arg2, char* arg3, SgUntypedExpression* arg4)
{
#ifdef DEBUG_PRINT
  printf("... build_SgUntypedUnaryOperator()");
#endif

  return new SgUntypedUnaryOperator();
}

//========================================================================================
// SgUntypedBinaryOperator
//----------------------------------------------------------------------------------------
SgUntypedBinaryOperator* build_SgUntypedBinaryOperator(int arg1, int arg2, char* arg3, SgUntypedExpression* arg4, SgUntypedExpression* arg5)
{
#ifdef DEBUG_PRINT
  printf("... build_SgUntypedBinaryOperator()");
#endif

  return new SgUntypedBinaryOperator();
}

//========================================================================================
// SgUntypedType
//----------------------------------------------------------------------------------------
SgUntypedType* build_SgUntypedType(char* arg1)
{
#ifdef DEBUG_PRINT
  printf("... build_SgUntypedType()");
#endif

  return new SgUntypedType();
}

