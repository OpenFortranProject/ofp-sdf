#include "traverse_SgUntypedNodes.hpp"

#define DEBUG_PRINT


//========================================================================================
// TODO: SgUntypedExpression
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedExpression(ATerm term, sage::SgUntypedExpression** SgUntypedExpression)
{
#ifdef DEBUG_PRINT
  printf("SgUntypedExpression %s\n", ATwriteToString(term));
#endif

  char* arg1;
  
  if (ATmatch(term, "SgUntypedExpression(<str>)", &arg1)) {
  } else return ATfalse;

#ifdef NOT_YET
  *SgUntypedExpression = new sage::SgUntypedExpression(arg1,arg2,arg3,arg4);
#endif

  return ATtrue;
}





//========================================================================================
// SgUntypedFile
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedFile(ATerm term, sage::SgUntypedFile** SgUntypedFile)
{
#ifdef DEBUG_PRINT
  printf("traverse_SgUntypedFile: %s\n", ATwriteToString(term));
#endif

  ATerm term1;
  sage::SgUntypedGlobalScope* arg1;
  
  if (ATmatch(term, "SgUntypedFile(<term>)", &term1)) {
    if (traverse_SgUntypedGlobalScope(term1, &arg1)) {
      // SgUntypedGlobalScope
    } else return ATfalse;
  } else return ATfalse;

#ifdef NOT_YET
  *SgUntypedFile = new sage::SgUntypedFile(arg1);
#endif

  return ATtrue;
}

//========================================================================================
// SgUntypedGlobalScope
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedGlobalScope(ATerm term, sage::SgUntypedGlobalScope** SgUntypedGlobalScope)
{
#ifdef DEBUG_PRINT
  printf("traverse_SgUntypedGlobalScope: %s\n", ATwriteToString(term));
#endif

  ATerm term3, term4, term5;
  char* arg1;
  int arg2;
  sage::SgUntypedDeclarationList* arg3;
  sage::SgUntypedStatementList* arg4;
  sage::SgUntypedFunctionDeclarationList* arg5;
  
  if (ATmatch(term, "SgUntypedGlobalScope(<str>,<int>,<term>,<term>,<term>)", &arg1,&arg2,&term3,&term4,&term5)) {

    if (traverse_SgUntypedDeclarationList(term3, &arg3)) {
      // SgUntypedDeclarationList
    } else return ATfalse;
    if (traverse_SgUntypedStatementList(term4, &arg4)) {
      // SgUntypedStatementList
    } else return ATfalse;
    if (traverse_SgUntypedFunctionDeclarationList(term5, &arg5)) {
      // SgUntypedFunctionDeclarationList
    } else return ATfalse;
  } else return ATfalse;

#ifdef NOT_YET
  *SgUntypedGlobalScope = new sage::SgUntypedGlobalScope(arg1,arg2,arg3,arg4,arg5);
#endif

  return ATtrue;
}

//========================================================================================
// SgUntypedAttribute
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedAttribute(ATerm term, sage::SgUntypedAttribute** SgUntypedAttribute)
{
#ifdef DEBUG_PRINT
  printf("SgUntypedAttribute %s\n", ATwriteToString(term));
#endif

  int arg1;
  char* arg2;
  
  if (ATmatch(term, "SgUntypedAttribute(<int>,<str>)", &arg1,&arg2)) {
  } else return ATfalse;

#ifdef NOT_YET
  *SgUntypedAttribute = new sage::SgUntypedAttribute(arg1,arg2);
#endif

  return ATtrue;
}

//========================================================================================
// SgUntypedInitializedName
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedInitializedName(ATerm term, sage::SgUntypedInitializedName** SgUntypedInitializedName)
{
#ifdef DEBUG_PRINT
  printf("SgUntypedInitializedName %s\n", ATwriteToString(term));
#endif

  ATerm term1;
  sage::SgUntypedType* arg1;
  char* arg2;
  
  if (ATmatch(term, "SgUntypedInitializedName(<term>,<str>)", &term1,&arg2)) {
#ifdef NOT_YET
    if (traverse_SgUntypedType(term1, &arg1)) {
      // SgUntypedType
    } else return ATfalse;
#endif
  } else return ATfalse;

#ifdef NOT_YET
  *SgUntypedInitializedName = new sage::SgUntypedInitializedName(arg1,arg2);
#endif

  return ATtrue;
}

#ifdef HAS_LISTS

//========================================================================================
// SgUntypedStatementList
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedStatementList(ATerm term, sage::SgUntypedStatementList** SgUntypedStatementList)
{
#ifdef DEBUG_PRINT
  printf("SgUntypedStatementList %s\n", ATwriteToString(term));
#endif

  ATerm term1;
  sage::SgUntypedStatement* arg1;
  
  if (ATmatch(term, "SgUntypedStatementList(<term>)", &term1)) {
    if (traverse_ListStarOfSgUntypedStatement(term1, &arg1)) {
      // ListStarOfSgUntypedStatement
    } else return ATfalse;
  } else return ATfalse;

#ifdef NOT_YET
  *SgUntypedStatementList = new sage::SgUntypedStatementList(arg1);
#endif

  return ATtrue;
}


//========================================================================================
// SgUntypedDeclarationList
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedDeclarationList(ATerm term, sage::SgUntypedDeclarationList** SgUntypedDeclarationList)
{
#ifdef DEBUG_PRINT
  printf("SgUntypedDeclarationList %s\n", ATwriteToString(term));
#endif

  ATerm term1;
  sage::ListStarOfSgUntypedDeclarationStatement* arg1;
  
  if (ATmatch(term, "SgUntypedDeclarationList(<term>)", &term1)) {
    if (traverse_ListStarOfSgUntypedDeclarationStatement(term1, &arg1)) {
      // ListStarOfSgUntypedDeclarationStatement
    } else return ATfalse;
  } else return ATfalse;

#ifdef NOT_YET
  *SgUntypedDeclarationList = new sage::SgUntypedDeclarationList(arg1);
#endif

  return ATtrue;
}

//========================================================================================
// SgUntypedFunctionDeclarationList
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedFunctionDeclarationList(ATerm term, sage::SgUntypedFunctionDeclarationList** SgUntypedFunctionDeclarationList)
{
#ifdef DEBUG_PRINT
  printf("SgUntypedFunctionDeclarationList %s\n", ATwriteToString(term));
#endif

  ATerm term1;
  sage::ListStarOfSgUntypedFunctionDeclaration* arg1;
  
  if (ATmatch(term, "SgUntypedFunctionDeclarationList(<term>)", &term1)) {
    if (traverse_ListStarOfSgUntypedFunctionDeclaration(term1, &arg1)) {
      // ListStarOfSgUntypedFunctionDeclaration
    } else return ATfalse;
  } else return ATfalse;

#ifdef NOT_YET
  *SgUntypedFunctionDeclarationList = new sage::SgUntypedFunctionDeclarationList(arg1);
#endif

  return ATtrue;
}

//========================================================================================
// SgUntypedInitializedNameList
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedInitializedNameList(ATerm term, sage::SgUntypedInitializedNameList** SgUntypedInitializedNameList)
{
#ifdef DEBUG_PRINT
  printf("traverse_SgUntypedInitializedNameList: %s\n", ATwriteToString(term));
#endif

  ATerm term1;
  sage::ListStarOfSgUntypedInitializedName* arg1;
  
  if (ATmatch(term, "SgUntypedInitializedNameList(<term>)", &term1)) {
    if (traverse_ListStarOfSgUntypedInitializedName(term1, &arg1)) {
      // ListStarOfSgUntypedInitializedName
    } else return ATfalse;
  } else return ATfalse;

#ifdef NOT_YET
  *SgUntypedInitializedNameList = new sage::SgUntypedInitializedNameList(arg1);
#endif

  return ATtrue;
}
#endif

//========================================================================================
// SgUntypedValueExpression
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedValueExpression(ATerm term, sage::SgUntypedValueExpression** SgUntypedValueExpression)
{
#ifdef DEBUG_PRINT
  printf("SgUntypedValueExpression %s\n", ATwriteToString(term));
#endif

  ATerm term3;
  int arg1;
  char* arg2;
  sage::SgUntypedType* arg3;
  
  if (ATmatch(term, "SgUntypedValueExpression(<int>,<str>,<term>)", &arg1,&arg2,&term3)) {
#ifdef NOT_YET
    if (traverse_SgUntypedType(term3, &arg3)) {
      // SgUntypedType
    } else return ATfalse;
#endif
  } else return ATfalse;

#ifdef NOT_YET
  *SgUntypedValueExpression = new sage::SgUntypedValueExpression(arg1,arg2,arg3);
#endif

  return ATtrue;
}

//========================================================================================
// SgUntypedArrayReferenceExpression
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedArrayReferenceExpression(ATerm term, sage::SgUntypedArrayReferenceExpression** SgUntypedArrayReferenceExpression)
{
#ifdef DEBUG_PRINT
  printf("SgUntypedArrayReferenceExpression %s\n", ATwriteToString(term));
#endif

  int arg1;
  
  if (ATmatch(term, "SgUntypedArrayReferenceExpression(<int>)", &arg1)) {
  } else return ATfalse;

#ifdef NOT_YET
  *SgUntypedArrayReferenceExpression = new sage::SgUntypedArrayReferenceExpression(arg1);
#endif

  return ATtrue;
}

//========================================================================================
// SgUntypedOtherExpression
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedOtherExpression(ATerm term, sage::SgUntypedOtherExpression** SgUntypedOtherExpression)
{
#ifdef DEBUG_PRINT
  printf("SgUntypedOtherExpression %s\n", ATwriteToString(term));
#endif

  int arg1;
  
  if (ATmatch(term, "SgUntypedOtherExpression(<int>)", &arg1)) {
  } else return ATfalse;

#ifdef NOT_YET
  *SgUntypedOtherExpression = new sage::SgUntypedOtherExpression(arg1);
#endif

  return ATtrue;
}

//========================================================================================
// SgUntypedFunctionCallOrArrayReferenceExpression
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedFunctionCallOrArrayReferenceExpression(ATerm term, sage::SgUntypedFunctionCallOrArrayReferenceExpression** SgUntypedFunctionCallOrArrayReferenceExpression)
{
#ifdef DEBUG_PRINT
  printf("SgUntypedFunctionCallOrArrayReferenceExpression %s\n", ATwriteToString(term));
#endif

  int arg1;
  
  if (ATmatch(term, "SgUntypedFunctionCallOrArrayReferenceExpression(<int>)", &arg1)) {
  } else return ATfalse;

#ifdef NOT_YET
  *SgUntypedFunctionCallOrArrayReferenceExpression = new sage::SgUntypedFunctionCallOrArrayReferenceExpression(arg1);
#endif

  return ATtrue;
}

//========================================================================================
// SgUntypedReferenceExpression
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedReferenceExpression(ATerm term, sage::SgUntypedReferenceExpression** SgUntypedReferenceExpression)
{
#ifdef DEBUG_PRINT
  printf("SgUntypedReferenceExpression %s\n", ATwriteToString(term));
#endif

  int arg1;
  char* arg2;
  
  if (ATmatch(term, "SgUntypedReferenceExpression(<int>,<str>)", &arg1,&arg2)) {
  } else return ATfalse;

#ifdef NOT_YET
  *SgUntypedReferenceExpression = new sage::SgUntypedReferenceExpression(arg1,arg2);
#endif

  return ATtrue;
}

//========================================================================================
// SgUntypedAssignmentStatement
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedAssignmentStatement(ATerm term, sage::SgUntypedAssignmentStatement** SgUntypedAssignmentStatement)
{
#ifdef DEBUG_PRINT
  printf("SgUntypedAssignmentStatement %s\n", ATwriteToString(term));
#endif

  ATerm term3, term4;
  char* arg1;
  int arg2;
  sage::SgUntypedExpression* arg3;
  sage::SgUntypedExpression* arg4;
  
  if (ATmatch(term, "SgUntypedAssignmentStatement(<str>,<int>,<term>,<term>)", &arg1,&arg2,&term3,&term4)) {
    if (traverse_SgUntypedExpression(term3, &arg3)) {
      // SgUntypedExpression
    } else return ATfalse;
    if (traverse_SgUntypedExpression(term4, &arg4)) {
      // SgUntypedExpression
    } else return ATfalse;
  } else return ATfalse;

#ifdef NOT_YET
  *SgUntypedAssignmentStatement = new sage::SgUntypedAssignmentStatement(arg1,arg2,arg3,arg4);
#endif

  return ATtrue;
}

//========================================================================================
// SgUntypedFunctionCallStatement
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedFunctionCallStatement(ATerm term, sage::SgUntypedFunctionCallStatement** SgUntypedFunctionCallStatement)
{
#ifdef DEBUG_PRINT
  printf("SgUntypedFunctionCallStatement %s\n", ATwriteToString(term));
#endif

  char* arg1;
  int arg2;
  
  if (ATmatch(term, "SgUntypedFunctionCallStatement(<str>,<int>)", &arg1,&arg2)) {
  } else return ATfalse;

#ifdef NOT_YET
  *SgUntypedFunctionCallStatement = new sage::SgUntypedFunctionCallStatement(arg1,arg2);
#endif

  return ATtrue;
}

//========================================================================================
// SgUntypedNamedStatement
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedNamedStatement(ATerm term, sage::SgUntypedNamedStatement** SgUntypedNamedStatement)
{
#ifdef DEBUG_PRINT
  printf("traverse_SgUntypedNamedStatement: %s\n", ATwriteToString(term));
#endif

  char* arg1;
  int arg2;
  char* arg3;
  
  if (ATmatch(term, "SgUntypedNamedStatement(<str>,<int>,<str>)", &arg1,&arg2,&arg3)) {
  } else return ATfalse;

#ifdef NOT_YET
  *SgUntypedNamedStatement = new sage::SgUntypedNamedStatement(arg1,arg2,arg3);
#endif

  return ATtrue;
}

//========================================================================================
// SgUntypedOtherStatement
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedOtherStatement(ATerm term, sage::SgUntypedOtherStatement** SgUntypedOtherStatement)
{
#ifdef DEBUG_PRINT
  printf("SgUntypedOtherStatement %s\n", ATwriteToString(term));
#endif

  char* arg1;
  int arg2;
  
  if (ATmatch(term, "SgUntypedOtherStatement(<str>,<int>)", &arg1,&arg2)) {
  } else return ATfalse;

#ifdef NOT_YET
  *SgUntypedOtherStatement = new sage::SgUntypedOtherStatement(arg1,arg2);
#endif

  return ATtrue;
}

//========================================================================================
// SgUntypedImplicitDeclaration
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedImplicitDeclaration(ATerm term, sage::SgUntypedImplicitDeclaration** SgUntypedImplicitDeclaration)
{
#ifdef DEBUG_PRINT
  printf("SgUntypedImplicitDeclaration %s\n", ATwriteToString(term));
#endif

  char* arg1;
  int arg2;
  
  if (ATmatch(term, "SgUntypedImplicitDeclaration(<str>,<int>)", &arg1,&arg2)) {
  } else return ATfalse;

#ifdef NOT_YET
  *SgUntypedImplicitDeclaration = new sage::SgUntypedImplicitDeclaration(arg1,arg2);
#endif

  return ATtrue;
}

//========================================================================================
// SgUntypedVariableDeclaration
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedVariableDeclaration(ATerm term, sage::SgUntypedVariableDeclaration** SgUntypedVariableDeclaration)
{
#ifdef DEBUG_PRINT
  printf("SgUntypedVariableDeclaration %s\n", ATwriteToString(term));
#endif

  ATerm term3, term4;
  char* arg1;
  int arg2;
  sage::SgUntypedType* arg3;
  sage::SgUntypedInitializedNameList* arg4;
  
  if (ATmatch(term, "SgUntypedVariableDeclaration(<str>,<int>,<term>,<term>)", &arg1,&arg2,&term3,&term4)) {
#ifdef NOT_YET
    if (traverse_SgUntypedType(term3, &arg3)) {
      // SgUntypedType
    } else return ATfalse;
#endif
    if (traverse_SgUntypedInitializedNameList(term4, &arg4)) {
      // SgUntypedInitializedNameList
    } else return ATfalse;
  } else return ATfalse;

#ifdef NOT_YET
  *SgUntypedVariableDeclaration = new sage::SgUntypedVariableDeclaration(arg1,arg2,arg3,arg4);
#endif

  return ATtrue;
}

//========================================================================================
// SgUntypedModuleDeclaration
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedModuleDeclaration(ATerm term, sage::SgUntypedModuleDeclaration** SgUntypedModuleDeclaration)
{
#ifdef DEBUG_PRINT
  printf("SgUntypedModuleDeclaration %s\n", ATwriteToString(term));
#endif

  ATerm term4, term5;
  char* arg1;
  int arg2;
  char* arg3;
  sage::SgUntypedModuleScope* arg4;
  sage::SgUntypedNamedStatement* arg5;
  
  if (ATmatch(term, "SgUntypedModuleDeclaration(<str>,<int>,<str>,<term>,<term>)", &arg1,&arg2,&arg3,&term4,&term5)) {
    if (traverse_SgUntypedModuleScope(term4, &arg4)) {
      // SgUntypedModuleScope
    } else return ATfalse;
    if (traverse_SgUntypedNamedStatement(term5, &arg5)) {
      // SgUntypedNamedStatement
    } else return ATfalse;
  } else return ATfalse;

#ifdef NOT_YET
  *SgUntypedModuleDeclaration = new sage::SgUntypedModuleDeclaration(arg1,arg2,arg3,arg4,arg5);
#endif

  return ATtrue;
}

//========================================================================================
// SgUntypedProgramHeaderDeclaration
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedProgramHeaderDeclaration(ATerm term, sage::SgUntypedProgramHeaderDeclaration** SgUntypedProgramHeaderDeclaration)
{
#ifdef DEBUG_PRINT
  printf("traverse_SgUntypedProgramHeaderDeclaration: %s\n", ATwriteToString(term));
#endif

  ATerm term4, term5, term6, term7;
  char* arg1;
  int arg2;
  char* arg3;
  sage::SgUntypedInitializedNameList* arg4;
  sage::SgUntypedType* arg5;
  sage::SgUntypedFunctionScope* arg6;
  sage::SgUntypedNamedStatement* arg7;

  if (ATmatch(term, "SgUntypedProgramHeaderDeclaration(<str>,<int>,<str>,<term>,<term>,<term>,<term>)", &arg1,&arg2,&arg3,&term4,&term5,&term6,&term7)) {

    if (traverse_SgUntypedInitializedNameList(term4, &arg4)) {
      // SgUntypedInitializedNameList
    } else return ATfalse;
#ifdef NOT_YET
    if (traverse_SgUntypedType(term5, &arg5)) {
      // SgUntypedType
    } else return ATfalse;
#endif
    if (traverse_SgUntypedFunctionScope(term6, &arg6)) {
      // SgUntypedFunctionScope
    } else return ATfalse;
    if (traverse_SgUntypedNamedStatement(term7, &arg7)) {
      // SgUntypedNamedStatement
    } else return ATfalse;
  } else return ATfalse;

#ifdef NOT_YET
  *SgUntypedProgramHeaderDeclaration = new sage::SgUntypedProgramHeaderDeclaration(arg1,arg2,arg3,arg4,arg5,arg6,arg7);
#endif

  return ATtrue;
}

//========================================================================================
// SgUntypedSubroutineDeclaration
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedSubroutineDeclaration(ATerm term, sage::SgUntypedSubroutineDeclaration** SgUntypedSubroutineDeclaration)
{
#ifdef DEBUG_PRINT
  printf("SgUntypedSubroutineDeclaration %s\n", ATwriteToString(term));
#endif

  ATerm term4, term5, term6, term7;
  char* arg1;
  int arg2;
  char* arg3;
  sage::SgUntypedInitializedNameList* arg4;
  sage::SgUntypedType* arg5;
  sage::SgUntypedFunctionScope* arg6;
  sage::SgUntypedNamedStatement* arg7;
  
  if (ATmatch(term, "SgUntypedSubroutineDeclaration(<str>,<int>,<str>,<term>,<term>,<term>,<term>)", &arg1,&arg2,&arg3,&term4,&term5,&term6,&term7)) {
    if (traverse_SgUntypedInitializedNameList(term4, &arg4)) {
      // SgUntypedInitializedNameList
    } else return ATfalse;
#ifdef NOT_YET
    if (traverse_SgUntypedType(term5, &arg5)) {
      // SgUntypedType
    } else return ATfalse;
#endif
    if (traverse_SgUntypedFunctionScope(term6, &arg6)) {
      // SgUntypedFunctionScope
    } else return ATfalse;
    if (traverse_SgUntypedNamedStatement(term7, &arg7)) {
      // SgUntypedNamedStatement
    } else return ATfalse;
  } else return ATfalse;

#ifdef NOT_YET
  *SgUntypedSubroutineDeclaration = new sage::SgUntypedSubroutineDeclaration(arg1,arg2,arg3,arg4,arg5,arg6,arg7);
#endif

  return ATtrue;
}

//========================================================================================
// SgUntypedFunctionScope
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedFunctionScope(ATerm term, sage::SgUntypedFunctionScope** SgUntypedFunctionScope)
{
#ifdef DEBUG_PRINT
  printf("traverse_SgUntypedFunctionScope: %s\n", ATwriteToString(term));
#endif

  ATerm term3, term4, term5;
  char* arg1;
  int arg2;
  sage::SgUntypedDeclarationList* arg3;
  sage::SgUntypedStatementList* arg4;
  sage::SgUntypedFunctionDeclarationList* arg5;
  
  if (ATmatch(term, "SgUntypedFunctionScope(<str>,<int>,<term>,<term>,<term>)", &arg1,&arg2,&term3,&term4,&term5)) {
    if (traverse_SgUntypedDeclarationList(term3, &arg3)) {
      // SgUntypedDeclarationList
    } else return ATfalse;
    if (traverse_SgUntypedStatementList(term4, &arg4)) {
      // SgUntypedStatementList
    } else return ATfalse;
    if (traverse_SgUntypedFunctionDeclarationList(term5, &arg5)) {
      // SgUntypedFunctionDeclarationList
    } else return ATfalse;
  } else return ATfalse;

#ifdef NOT_YET
  *SgUntypedFunctionScope = new sage::SgUntypedFunctionScope(arg1,arg2,arg3,arg4,arg5);
#endif

  return ATtrue;
}

//========================================================================================
// SgUntypedModuleScope
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedModuleScope(ATerm term, sage::SgUntypedModuleScope** SgUntypedModuleScope)
{
#ifdef DEBUG_PRINT
  printf("SgUntypedModuleScope %s\n", ATwriteToString(term));
#endif

  ATerm term3, term4, term5;
  char* arg1;
  int arg2;
  sage::SgUntypedDeclarationList* arg3;
  sage::SgUntypedStatementList* arg4;
  sage::SgUntypedFunctionDeclarationList* arg5;
  
  if (ATmatch(term, "SgUntypedModuleScope(<str>,<int>,<term>,<term>,<term>)", &arg1,&arg2,&term3,&term4,&term5)) {
    if (traverse_SgUntypedDeclarationList(term3, &arg3)) {
      // SgUntypedDeclarationList
    } else return ATfalse;
    if (traverse_SgUntypedStatementList(term4, &arg4)) {
      // SgUntypedStatementList
    } else return ATfalse;
    if (traverse_SgUntypedFunctionDeclarationList(term5, &arg5)) {
      // SgUntypedFunctionDeclarationList
    } else return ATfalse;
  } else return ATfalse;

#ifdef NOT_YET
  *SgUntypedModuleScope = new sage::SgUntypedModuleScope(arg1,arg2,arg3,arg4,arg5);
#endif

  return ATtrue;
}

//========================================================================================
// SgUntypedArrayType
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedArrayType(ATerm term, sage::SgUntypedArrayType** SgUntypedArrayType)
{
#ifdef DEBUG_PRINT
  printf("SgUntypedArrayType %s\n", ATwriteToString(term));
#endif

  ATerm term2, term3, term4, term5, term6, term7, term8, term9, term11;
  char* arg1;
  sage::SgUntypedExpression* arg2;
#ifdef NOT_YET
  sage::bool* arg3;
  sage::bool* arg4;
  sage::bool* arg5;
  sage::bool* arg6;
  sage::bool* arg7;
  sage::bool* arg8;
#endif
  sage::SgUntypedExpression* arg9;
  char* arg10;
#ifdef NOT_YET
  sage::bool* arg11;
#endif

  ATbool *arg3, *arg4, *arg5, * arg6, * arg7, * arg8, *arg11;

#ifdef NOT_YET
  
  if (ATmatch(term, "SgUntypedArrayType(<str>,<term>,<term>,<term>,<term>,<term>,<term>,<term>,<term>,<str>,<term>)", &arg1,&term2,&term3,&term4,&term5,&term6,&term7,&term8,&term9,&arg10,&term11)) {
    if (traverse_SgUntypedExpression(term2, &arg2)) {
      // SgUntypedExpression
    } else return ATfalse;
    if (traverse_bool(term3, &arg3)) {
      // bool
    } else return ATfalse;
    if (traverse_bool(term4, &arg4)) {
      // bool
    } else return ATfalse;
    if (traverse_bool(term5, &arg5)) {
      // bool
    } else return ATfalse;
    if (traverse_bool(term6, &arg6)) {
      // bool
    } else return ATfalse;
    if (traverse_bool(term7, &arg7)) {
      // bool
    } else return ATfalse;
    if (traverse_bool(term8, &arg8)) {
      // bool
    } else return ATfalse;
    if (traverse_SgUntypedExpression(term9, &arg9)) {
      // SgUntypedExpression
    } else return ATfalse;
    if (traverse_bool(term11, &arg11)) {
      // bool
    } else return ATfalse;
  } else return ATfalse;

  *SgUntypedArrayType = new sage::SgUntypedArrayType(arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11);
#endif

  return ATtrue;
}

//========================================================================================
// SgUntypedTypeVoid
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedTypeVoid(ATerm term, sage::SgUntypedTypeVoid** SgUntypedTypeVoid)
{
#ifdef DEBUG_PRINT
  printf("SgUntypedTypeVoid %s\n", ATwriteToString(term));
#endif

  if (ATmatch(term, "SgUntypedTypeVoid()")) {
  } else return ATfalse;

#ifdef NOT_YET
  *SgUntypedTypeVoid = new sage::SgUntypedTypeVoid();
#endif

  return ATtrue;
}

//========================================================================================
// SgUntypedTypeUnknown
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedTypeUnknown(ATerm term, sage::SgUntypedTypeUnknown** SgUntypedTypeUnknown)
{
#ifdef DEBUG_PRINT
  printf("SgUntypedTypeUnknown %s\n", ATwriteToString(term));
#endif
  
  if (ATmatch(term, "SgUntypedTypeUnknown()")) {
  } else return ATfalse;

#ifdef NOT_YET
  *SgUntypedTypeUnknown = new sage::SgUntypedTypeUnknown();
#endif

  return ATtrue;
}

//========================================================================================
// SgUntypedTypeInt
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedTypeInt(ATerm term, sage::SgUntypedTypeInt** SgUntypedTypeInt)
{
#ifdef DEBUG_PRINT
  printf("SgUntypedTypeInt %s\n", ATwriteToString(term));
#endif

  if (ATmatch(term, "SgUntypedTypeInt()")) {
  } else return ATfalse;

#ifdef NOT_YET
  *SgUntypedTypeInt = new sage::SgUntypedTypeInt();
#endif

  return ATtrue;
}

//========================================================================================
// SgUntypedTypeFloat
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedTypeFloat(ATerm term, sage::SgUntypedTypeFloat** SgUntypedTypeFloat)
{
#ifdef DEBUG_PRINT
  printf("SgUntypedTypeFloat %s\n", ATwriteToString(term));
#endif

  if (ATmatch(term, "SgUntypedTypeFloat()")) {
  } else return ATfalse;

#ifdef NOT_YET
  *SgUntypedTypeFloat = new sage::SgUntypedTypeFloat();
#endif

  return ATtrue;
}

//========================================================================================
// SgUntypedTypeDouble
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedTypeDouble(ATerm term, sage::SgUntypedTypeDouble** SgUntypedTypeDouble)
{
#ifdef DEBUG_PRINT
  printf("SgUntypedTypeDouble %s\n", ATwriteToString(term));
#endif
 
  if (ATmatch(term, "SgUntypedTypeDouble()")) {
  } else return ATfalse;

#ifdef NOT_YET
  *SgUntypedTypeDouble = new sage::SgUntypedTypeDouble();
#endif

  return ATtrue;
}

//========================================================================================
// SgUntypedTypeBool
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedTypeBool(ATerm term, sage::SgUntypedTypeBool** SgUntypedTypeBool)
{
#ifdef DEBUG_PRINT
  printf("SgUntypedTypeBool %s\n", ATwriteToString(term));
#endif

  if (ATmatch(term, "SgUntypedTypeBool()")) {
  } else return ATfalse;

#ifdef NOT_YET
  *SgUntypedTypeBool = new sage::SgUntypedTypeBool();
#endif

  return ATtrue;
}

//========================================================================================
// SgUntypedBlockScope
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedBlockScope(ATerm term, sage::SgUntypedBlockScope** SgUntypedBlockScope)
{
#ifdef DEBUG_PRINT
  printf("SgUntypedBlockScope %s\n", ATwriteToString(term));
#endif

  ATerm term3, term4, term5;
  char* arg1;
  int arg2;
  sage::SgUntypedDeclarationList* arg3;
  sage::SgUntypedStatementList* arg4;
  sage::SgUntypedFunctionDeclarationList* arg5;
  
  if (ATmatch(term, "SgUntypedBlockScope(<str>,<int>,<term>,<term>,<term>)", &arg1,&arg2,&term3,&term4,&term5)) {
    if (traverse_SgUntypedDeclarationList(term3, &arg3)) {
      // SgUntypedDeclarationList
    } else return ATfalse;
    if (traverse_SgUntypedStatementList(term4, &arg4)) {
      // SgUntypedStatementList
    } else return ATfalse;
    if (traverse_SgUntypedFunctionDeclarationList(term5, &arg5)) {
      // SgUntypedFunctionDeclarationList
    } else return ATfalse;
  } else return ATfalse;

#ifdef NOT_YET
  *SgUntypedBlockScope = new sage::SgUntypedBlockScope(arg1,arg2,arg3,arg4,arg5);
#endif

  return ATtrue;
}

//========================================================================================
// SgUntypedBlockStatement
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedBlockStatement(ATerm term, sage::SgUntypedBlockStatement** SgUntypedBlockStatement)
{
#ifdef DEBUG_PRINT
  printf("SgUntypedBlockStatement %s\n", ATwriteToString(term));
#endif

  ATerm term4, term5;
  char* arg1;
  int arg2;
  char* arg3;
  sage::SgUntypedBlockScope* arg4;
  sage::SgUntypedNamedStatement* arg5;
  
  if (ATmatch(term, "SgUntypedBlockStatement(<str>,<int>,<str>,<term>,<term>)", &arg1,&arg2,&arg3,&term4,&term5)) {
    if (traverse_SgUntypedBlockScope(term4, &arg4)) {
      // SgUntypedBlockScope
    } else return ATfalse;
    if (traverse_SgUntypedNamedStatement(term5, &arg5)) {
      // SgUntypedNamedStatement
    } else return ATfalse;
  } else return ATfalse;

#ifdef NOT_YET
  *SgUntypedBlockStatement = new sage::SgUntypedBlockStatement(arg1,arg2,arg3,arg4,arg5);
#endif

  return ATtrue;
}

//========================================================================================
// SgUntypedUnaryOperator
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedUnaryOperator(ATerm term, sage::SgUntypedUnaryOperator** SgUntypedUnaryOperator)
{
#ifdef DEBUG_PRINT
  printf("SgUntypedUnaryOperator %s\n", ATwriteToString(term));
#endif

  ATerm term4;
  int arg1;
  int arg2;
  char* arg3;
  sage::SgUntypedExpression* arg4;
  
  if (ATmatch(term, "SgUntypedUnaryOperator(<int>,<int>,<str>,<term>)", &arg1,&arg2,&arg3,&term4)) {
    if (traverse_SgUntypedExpression(term4, &arg4)) {
      // SgUntypedExpression
    } else return ATfalse;
  } else return ATfalse;

#ifdef NOT_YET
  *SgUntypedUnaryOperator = new sage::SgUntypedUnaryOperator(arg1,arg2,arg3,arg4);
#endif

  return ATtrue;
}

//========================================================================================
// SgUntypedBinaryOperator
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedBinaryOperator(ATerm term, sage::SgUntypedBinaryOperator** SgUntypedBinaryOperator)
{
#ifdef DEBUG_PRINT
  printf("SgUntypedBinaryOperator %s\n", ATwriteToString(term));
#endif

  ATerm term4, term5;
  int arg1;
  int arg2;
  char* arg3;
  sage::SgUntypedExpression* arg4;
  sage::SgUntypedExpression* arg5;
  
  if (ATmatch(term, "SgUntypedBinaryOperator(<int>,<int>,<str>,<term>,<term>)", &arg1,&arg2,&arg3,&term4,&term5)) {
    if (traverse_SgUntypedExpression(term4, &arg4)) {
      // SgUntypedExpression
    } else return ATfalse;
    if (traverse_SgUntypedExpression(term5, &arg5)) {
      // SgUntypedExpression
    } else return ATfalse;
  } else return ATfalse;

#ifdef NOT_YET
  *SgUntypedBinaryOperator = new sage::SgUntypedBinaryOperator(arg1,arg2,arg3,arg4,arg5);
#endif

  return ATtrue;
}

