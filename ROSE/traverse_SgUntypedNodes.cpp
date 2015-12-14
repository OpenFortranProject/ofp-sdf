//TODO
// 1. sage:bool -> bool
// 2. Turn build functions back on using BuildStmt in sage-to-traverse.str
// 3. Fix SgUntypedType and remove SgUntypedTypeFloat, ...
// 4. Fix SgUntypedExpression
// - SgUntypedType and SgUntypedExpression should be fixed in new grammar

#include "traverse_SgUntypedNodes.hpp"

#define DEBUG_PRINT


//========================================================================================
// SgUntypedFile
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedFile(ATerm term, sage::SgUntypedFile** SgUntypedFile)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedFile: %s\n", ATwriteToString(term));
#endif

  ATerm term1;
  sage::SgUntypedGlobalScope* arg1;
  
  *SgUntypedFile = NULL;
  if (ATmatch(term, "SgUntypedFile(<term>)", &term1)) {
    if (traverse_SgUntypedGlobalScope(term1, &arg1)) {
      // SgUntypedGlobalScope
    } else return ATfalse;
  } else return ATfalse;

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedGlobalScope
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedGlobalScope(ATerm term, sage::SgUntypedGlobalScope** SgUntypedGlobalScope)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedGlobalScope: %s\n", ATwriteToString(term));
#endif

  ATerm term3, term4, term5;
  char* arg1;
  int arg2;
  sage::SgUntypedDeclarationList* arg3;
  sage::SgUntypedStatementList* arg4;
  sage::SgUntypedFunctionDeclarationList* arg5;
  
  *SgUntypedGlobalScope = NULL;
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

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedAttribute
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedAttribute(ATerm term, sage::SgUntypedAttribute** SgUntypedAttribute)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedAttribute: %s\n", ATwriteToString(term));
#endif

  int arg1;
  char* arg2;
  
  *SgUntypedAttribute = NULL;
  if (ATmatch(term, "SgUntypedAttribute(<int>,<str>)", &arg1,&arg2)) {
  } else return ATfalse;

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedInitializedName
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedInitializedName(ATerm term, sage::SgUntypedInitializedName** SgUntypedInitializedName)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedInitializedName: %s\n", ATwriteToString(term));
#endif

  ATerm term1;
  sage::SgUntypedType* arg1;
  char* arg2;
  
  *SgUntypedInitializedName = NULL;
  if (ATmatch(term, "SgUntypedInitializedName(<term>,<str>)", &term1,&arg2)) {
    if (traverse_SgUntypedType(term1, &arg1)) {
      // SgUntypedType
    } else return ATfalse;
  } else return ATfalse;

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedStatementList
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedStatementList(ATerm term, sage::SgUntypedStatementList** SgUntypedStatementList)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedStatementList: %s\n", ATwriteToString(term));
#endif

  ATerm term1;
  
  *SgUntypedStatementList = NULL;
  if (ATmatch(term, "SgUntypedStatementList(<term>)", &term1)) {
#ifdef NOT_YET
     sage::SgUntypedStatementList* plist = new sage::SgUntypedStatementList();

     ATermList tail = (ATermList) ATmake("<term>", term1);
     while (! ATisEmpty(tail)) {
        ATerm head = ATgetFirst(tail);
        tail = ATgetNext(tail);
        {
           sage::SgUntypedScope* arg;
           if (traverse_SgUntypedScope(head, &arg)) {
              // SgUntypedScope
              plist->push_back(arg);
           }
           else {
              delete plist;
              return ATfalse;
           }
        }
        {
           sage::SgUntypedOtherStatement* arg;
           if (traverse_SgUntypedOtherStatement(head, &arg)) {
              // SgUntypedOtherStatement
              plist->push_back(arg);
           }
           else {
              delete plist;
              return ATfalse;
           }
        }
        {
           sage::SgUntypedNamedStatement* arg;
           if (traverse_SgUntypedNamedStatement(head, &arg)) {
              // SgUntypedNamedStatement
              plist->push_back(arg);
           }
           else {
              delete plist;
              return ATfalse;
           }
        }
        {
           sage::SgUntypedBlockStatement* arg;
           if (traverse_SgUntypedBlockStatement(head, &arg)) {
              // SgUntypedBlockStatement
              plist->push_back(arg);
           }
           else {
              delete plist;
              return ATfalse;
           }
        }
        {
           sage::SgUntypedFunctionCallStatement* arg;
           if (traverse_SgUntypedFunctionCallStatement(head, &arg)) {
              // SgUntypedFunctionCallStatement
              plist->push_back(arg);
           }
           else {
              delete plist;
              return ATfalse;
           }
        }
        {
           sage::SgUntypedAssignmentStatement* arg;
           if (traverse_SgUntypedAssignmentStatement(head, &arg)) {
              // SgUntypedAssignmentStatement
              plist->push_back(arg);
           }
           else {
              delete plist;
              return ATfalse;
           }
        }
        {
           sage::SgUntypedDeclarationStatement* arg;
           if (traverse_SgUntypedDeclarationStatement(head, &arg)) {
              // SgUntypedDeclarationStatement
              plist->push_back(arg);
           }
           else {
              delete plist;
              return ATfalse;
           }
        }
     }
     *SgUntypedStatementList = plist;
#endif
  }
  else return ATfalse;
  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedDeclarationList
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedDeclarationList(ATerm term, sage::SgUntypedDeclarationList** SgUntypedDeclarationList)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedDeclarationList: %s\n", ATwriteToString(term));
#endif

  ATerm term1;
  
  *SgUntypedDeclarationList = NULL;
  if (ATmatch(term, "SgUntypedDeclarationList(<term>)", &term1)) {
#ifdef NOT_YET
     sage::SgUntypedDeclarationList* plist = new sage::SgUntypedDeclarationList();

     ATermList tail = (ATermList) ATmake("<term>", term1);
     while (! ATisEmpty(tail)) {
        ATerm head = ATgetFirst(tail);
        tail = ATgetNext(tail);
        {
           sage::SgUntypedDeclaration* arg;
           if (traverse_SgUntypedDeclaration(head, &arg)) {
              // SgUntypedDeclaration
              plist->push_back(arg);
           }
           else {
              delete plist;
              return ATfalse;
           }
        }
     }
     *SgUntypedDeclarationList = plist;
#endif
  }
  else return ATfalse;
  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedFunctionDeclarationList
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedFunctionDeclarationList(ATerm term, sage::SgUntypedFunctionDeclarationList** SgUntypedFunctionDeclarationList)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedFunctionDeclarationList: %s\n", ATwriteToString(term));
#endif

  ATerm term1;
  
  *SgUntypedFunctionDeclarationList = NULL;
  if (ATmatch(term, "SgUntypedFunctionDeclarationList(<term>)", &term1)) {
     sage::SgUntypedFunctionDeclarationList* plist = new sage::SgUntypedFunctionDeclarationList();

     ATermList tail = (ATermList) ATmake("<term>", term1);
     while (! ATisEmpty(tail)) {
        ATerm head = ATgetFirst(tail);
        tail = ATgetNext(tail);
        {
#ifdef NOT_YET
           sage::SgUntypedSubroutineDeclaration* arg;
           if (traverse_SgUntypedSubroutineDeclaration(head, &arg)) {
              // SgUntypedSubroutineDeclaration
              plist->push_back(arg);
           }
           else {
              delete plist;
              return ATfalse;
           }
#endif
        }
        {
           sage::SgUntypedProgramHeaderDeclaration* arg;
           if (traverse_SgUntypedProgramHeaderDeclaration(head, &arg)) {
              // SgUntypedProgramHeaderDeclaration
              plist->push_back(arg);
           }
           else {
              delete plist;
              return ATfalse;
           }
        }
     }
     *SgUntypedFunctionDeclarationList = plist;
  }
  else return ATfalse;
  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedInitializedNameList
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedInitializedNameList(ATerm term, sage::SgUntypedInitializedNameList** SgUntypedInitializedNameList)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedInitializedNameList: %s\n", ATwriteToString(term));
#endif

  ATerm term1;
  
  *SgUntypedInitializedNameList = NULL;
  if (ATmatch(term, "SgUntypedInitializedNameList(<term>)", &term1)) {
     sage::SgUntypedInitializedNameList* plist = new sage::SgUntypedInitializedNameList();

     ATermList tail = (ATermList) ATmake("<term>", term1);
     while (! ATisEmpty(tail)) {
        ATerm head = ATgetFirst(tail);
        tail = ATgetNext(tail);
        {
           sage::SgUntypedInitializedName* arg;
           if (traverse_SgUntypedInitializedName(head, &arg)) {
              // SgUntypedInitializedName
              plist->push_back(arg);
           }
           else {
              delete plist;
              return ATfalse;
           }
        }
     }
     *SgUntypedInitializedNameList = plist;
  }
  else return ATfalse;
  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedValueExpression
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedValueExpression(ATerm term, sage::SgUntypedValueExpression** SgUntypedValueExpression)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedValueExpression: %s\n", ATwriteToString(term));
#endif

  ATerm term3;
  int arg1;
  char* arg2;
  sage::SgUntypedType* arg3;
  
  *SgUntypedValueExpression = NULL;
  if (ATmatch(term, "SgUntypedValueExpression(<int>,<str>,<term>)", &arg1,&arg2,&term3)) {
    if (traverse_SgUntypedType(term3, &arg3)) {
      // SgUntypedType
    } else return ATfalse;
  } else return ATfalse;

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedArrayReferenceExpression
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedArrayReferenceExpression(ATerm term, sage::SgUntypedArrayReferenceExpression** SgUntypedArrayReferenceExpression)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedArrayReferenceExpression: %s\n", ATwriteToString(term));
#endif

  int arg1;
  
  *SgUntypedArrayReferenceExpression = NULL;
  if (ATmatch(term, "SgUntypedArrayReferenceExpression(<int>)", &arg1)) {
  } else return ATfalse;

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedOtherExpression
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedOtherExpression(ATerm term, sage::SgUntypedOtherExpression** SgUntypedOtherExpression)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedOtherExpression: %s\n", ATwriteToString(term));
#endif

  int arg1;
  
  *SgUntypedOtherExpression = NULL;
  if (ATmatch(term, "SgUntypedOtherExpression(<int>)", &arg1)) {
  } else return ATfalse;

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedFunctionCallOrArrayReferenceExpression
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedFunctionCallOrArrayReferenceExpression(ATerm term, sage::SgUntypedFunctionCallOrArrayReferenceExpression** SgUntypedFunctionCallOrArrayReferenceExpression)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedFunctionCallOrArrayReferenceExpression: %s\n", ATwriteToString(term));
#endif

  int arg1;
  
  *SgUntypedFunctionCallOrArrayReferenceExpression = NULL;
  if (ATmatch(term, "SgUntypedFunctionCallOrArrayReferenceExpression(<int>)", &arg1)) {
  } else return ATfalse;

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedReferenceExpression
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedReferenceExpression(ATerm term, sage::SgUntypedReferenceExpression** SgUntypedReferenceExpression)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedReferenceExpression: %s\n", ATwriteToString(term));
#endif

  int arg1;
  char* arg2;
  
  *SgUntypedReferenceExpression = NULL;
  if (ATmatch(term, "SgUntypedReferenceExpression(<int>,<str>)", &arg1,&arg2)) {
  } else return ATfalse;

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedAssignmentStatement
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedAssignmentStatement(ATerm term, sage::SgUntypedAssignmentStatement** SgUntypedAssignmentStatement)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedAssignmentStatement: %s\n", ATwriteToString(term));
#endif

  ATerm term3, term4;
  char* arg1;
  int arg2;
  sage::SgUntypedExpression* arg3;
  sage::SgUntypedExpression* arg4;
  
  *SgUntypedAssignmentStatement = NULL;
  if (ATmatch(term, "SgUntypedAssignmentStatement(<str>,<int>,<term>,<term>)", &arg1,&arg2,&term3,&term4)) {
    if (traverse_SgUntypedExpression(term3, &arg3)) {
      // SgUntypedExpression
    } else return ATfalse;
    if (traverse_SgUntypedExpression(term4, &arg4)) {
      // SgUntypedExpression
    } else return ATfalse;
  } else return ATfalse;

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedFunctionCallStatement
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedFunctionCallStatement(ATerm term, sage::SgUntypedFunctionCallStatement** SgUntypedFunctionCallStatement)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedFunctionCallStatement: %s\n", ATwriteToString(term));
#endif

  char* arg1;
  int arg2;
  
  *SgUntypedFunctionCallStatement = NULL;
  if (ATmatch(term, "SgUntypedFunctionCallStatement(<str>,<int>)", &arg1,&arg2)) {
  } else return ATfalse;

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedNamedStatement
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedNamedStatement(ATerm term, sage::SgUntypedNamedStatement** SgUntypedNamedStatement)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedNamedStatement: %s\n", ATwriteToString(term));
#endif

  char* arg1;
  int arg2;
  char* arg3;
  
  *SgUntypedNamedStatement = NULL;
  if (ATmatch(term, "SgUntypedNamedStatement(<str>,<int>,<str>)", &arg1,&arg2,&arg3)) {
  } else return ATfalse;

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedOtherStatement
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedOtherStatement(ATerm term, sage::SgUntypedOtherStatement** SgUntypedOtherStatement)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedOtherStatement: %s\n", ATwriteToString(term));
#endif

  char* arg1;
  int arg2;
  
  *SgUntypedOtherStatement = NULL;
  if (ATmatch(term, "SgUntypedOtherStatement(<str>,<int>)", &arg1,&arg2)) {
  } else return ATfalse;

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedImplicitDeclaration
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedImplicitDeclaration(ATerm term, sage::SgUntypedImplicitDeclaration** SgUntypedImplicitDeclaration)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedImplicitDeclaration: %s\n", ATwriteToString(term));
#endif

  char* arg1;
  int arg2;
  
  *SgUntypedImplicitDeclaration = NULL;
  if (ATmatch(term, "SgUntypedImplicitDeclaration(<str>,<int>)", &arg1,&arg2)) {
  } else return ATfalse;

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedVariableDeclaration
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedVariableDeclaration(ATerm term, sage::SgUntypedVariableDeclaration** SgUntypedVariableDeclaration)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedVariableDeclaration: %s\n", ATwriteToString(term));
#endif

  ATerm term3, term4;
  char* arg1;
  int arg2;
  sage::SgUntypedType* arg3;
  sage::SgUntypedInitializedNameList* arg4;
  
  *SgUntypedVariableDeclaration = NULL;
  if (ATmatch(term, "SgUntypedVariableDeclaration(<str>,<int>,<term>,<term>)", &arg1,&arg2,&term3,&term4)) {
    if (traverse_SgUntypedType(term3, &arg3)) {
      // SgUntypedType
    } else return ATfalse;
    if (traverse_SgUntypedInitializedNameList(term4, &arg4)) {
      // SgUntypedInitializedNameList
    } else return ATfalse;
  } else return ATfalse;

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedModuleDeclaration
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedModuleDeclaration(ATerm term, sage::SgUntypedModuleDeclaration** SgUntypedModuleDeclaration)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedModuleDeclaration: %s\n", ATwriteToString(term));
#endif

  ATerm term4, term5;
  char* arg1;
  int arg2;
  char* arg3;
  sage::SgUntypedModuleScope* arg4;
  sage::SgUntypedNamedStatement* arg5;
  
  *SgUntypedModuleDeclaration = NULL;
  if (ATmatch(term, "SgUntypedModuleDeclaration(<str>,<int>,<str>,<term>,<term>)", &arg1,&arg2,&arg3,&term4,&term5)) {
    if (traverse_SgUntypedModuleScope(term4, &arg4)) {
      // SgUntypedModuleScope
    } else return ATfalse;
    if (traverse_SgUntypedNamedStatement(term5, &arg5)) {
      // SgUntypedNamedStatement
    } else return ATfalse;
  } else return ATfalse;

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedProgramHeaderDeclaration
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedProgramHeaderDeclaration(ATerm term, sage::SgUntypedProgramHeaderDeclaration** SgUntypedProgramHeaderDeclaration)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedProgramHeaderDeclaration: %s\n", ATwriteToString(term));
#endif

  ATerm term4, term5, term6, term7;
  char* arg1;
  int arg2;
  char* arg3;
  sage::SgUntypedInitializedNameList* arg4;
  sage::SgUntypedType* arg5;
  sage::SgUntypedFunctionScope* arg6;
  sage::SgUntypedNamedStatement* arg7;
  
  *SgUntypedProgramHeaderDeclaration = NULL;
  if (ATmatch(term, "SgUntypedProgramHeaderDeclaration(<str>,<int>,<str>,<term>,<term>,<term>,<term>)", &arg1,&arg2,&arg3,&term4,&term5,&term6,&term7)) {
    if (traverse_SgUntypedInitializedNameList(term4, &arg4)) {
      // SgUntypedInitializedNameList
    } else return ATfalse;
    if (traverse_SgUntypedType(term5, &arg5)) {
      // SgUntypedType
    } else return ATfalse;
    if (traverse_SgUntypedFunctionScope(term6, &arg6)) {
      // SgUntypedFunctionScope
    } else return ATfalse;
    if (traverse_SgUntypedNamedStatement(term7, &arg7)) {
      // SgUntypedNamedStatement
    } else return ATfalse;
  } else return ATfalse;

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedSubroutineDeclaration
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedSubroutineDeclaration(ATerm term, sage::SgUntypedSubroutineDeclaration** SgUntypedSubroutineDeclaration)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedSubroutineDeclaration: %s\n", ATwriteToString(term));
#endif

  ATerm term4, term5, term6, term7;
  char* arg1;
  int arg2;
  char* arg3;
  sage::SgUntypedInitializedNameList* arg4;
  sage::SgUntypedType* arg5;
  sage::SgUntypedFunctionScope* arg6;
  sage::SgUntypedNamedStatement* arg7;
  
  *SgUntypedSubroutineDeclaration = NULL;
  if (ATmatch(term, "SgUntypedSubroutineDeclaration(<str>,<int>,<str>,<term>,<term>,<term>,<term>)", &arg1,&arg2,&arg3,&term4,&term5,&term6,&term7)) {
    if (traverse_SgUntypedInitializedNameList(term4, &arg4)) {
      // SgUntypedInitializedNameList
    } else return ATfalse;
    if (traverse_SgUntypedType(term5, &arg5)) {
      // SgUntypedType
    } else return ATfalse;
    if (traverse_SgUntypedFunctionScope(term6, &arg6)) {
      // SgUntypedFunctionScope
    } else return ATfalse;
    if (traverse_SgUntypedNamedStatement(term7, &arg7)) {
      // SgUntypedNamedStatement
    } else return ATfalse;
  } else return ATfalse;

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedFunctionScope
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedFunctionScope(ATerm term, sage::SgUntypedFunctionScope** SgUntypedFunctionScope)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedFunctionScope: %s\n", ATwriteToString(term));
#endif

  ATerm term3, term4, term5;
  char* arg1;
  int arg2;
  sage::SgUntypedDeclarationList* arg3;
  sage::SgUntypedStatementList* arg4;
  sage::SgUntypedFunctionDeclarationList* arg5;
  
  *SgUntypedFunctionScope = NULL;
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

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedModuleScope
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedModuleScope(ATerm term, sage::SgUntypedModuleScope** SgUntypedModuleScope)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedModuleScope: %s\n", ATwriteToString(term));
#endif

  ATerm term3, term4, term5;
  char* arg1;
  int arg2;
  sage::SgUntypedDeclarationList* arg3;
  sage::SgUntypedStatementList* arg4;
  sage::SgUntypedFunctionDeclarationList* arg5;
  
  *SgUntypedModuleScope = NULL;
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

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedArrayType
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedArrayType(ATerm term, sage::SgUntypedArrayType** SgUntypedArrayType)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedArrayType: %s\n", ATwriteToString(term));
#endif

  ATerm term2, term3, term4, term5, term6, term7, term8, term9, term11;
  char* arg1;
  sage::SgUntypedExpression* arg2;
  bool* arg3;
  bool* arg4;
  bool* arg5;
  bool* arg6;
  bool* arg7;
  bool* arg8;
  sage::SgUntypedExpression* arg9;
  char* arg10;
  bool* arg11;
  
  *SgUntypedArrayType = NULL;
  if (ATmatch(term, "SgUntypedArrayType(<str>,<term>,<term>,<term>,<term>,<term>,<term>,<term>,<term>,<str>,<term>)", &arg1,&term2,&term3,&term4,&term5,&term6,&term7,&term8,&term9,&arg10,&term11)) {
    if (traverse_SgUntypedExpression(term2, &arg2)) {
      // SgUntypedExpression
    } else return ATfalse;
#ifdef FIXME
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
#endif
  } else return ATfalse;

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}


//========================================================================================
// SgUntypedBlockScope
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedBlockScope(ATerm term, sage::SgUntypedBlockScope** SgUntypedBlockScope)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedBlockScope: %s\n", ATwriteToString(term));
#endif

  ATerm term3, term4, term5;
  char* arg1;
  int arg2;
  sage::SgUntypedDeclarationList* arg3;
  sage::SgUntypedStatementList* arg4;
  sage::SgUntypedFunctionDeclarationList* arg5;
  
  *SgUntypedBlockScope = NULL;
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

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedBlockStatement
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedBlockStatement(ATerm term, sage::SgUntypedBlockStatement** SgUntypedBlockStatement)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedBlockStatement: %s\n", ATwriteToString(term));
#endif

  ATerm term4, term5;
  char* arg1;
  int arg2;
  char* arg3;
  sage::SgUntypedBlockScope* arg4;
  sage::SgUntypedNamedStatement* arg5;
  
  *SgUntypedBlockStatement = NULL;
  if (ATmatch(term, "SgUntypedBlockStatement(<str>,<int>,<str>,<term>,<term>)", &arg1,&arg2,&arg3,&term4,&term5)) {
    if (traverse_SgUntypedBlockScope(term4, &arg4)) {
      // SgUntypedBlockScope
    } else return ATfalse;
    if (traverse_SgUntypedNamedStatement(term5, &arg5)) {
      // SgUntypedNamedStatement
    } else return ATfalse;
  } else return ATfalse;

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedUnaryOperator
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedUnaryOperator(ATerm term, sage::SgUntypedUnaryOperator** SgUntypedUnaryOperator)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedUnaryOperator: %s\n", ATwriteToString(term));
#endif

  ATerm term4;
  int arg1;
  int arg2;
  char* arg3;
  sage::SgUntypedExpression* arg4;
  
  *SgUntypedUnaryOperator = NULL;
  if (ATmatch(term, "SgUntypedUnaryOperator(<int>,<int>,<str>,<term>)", &arg1,&arg2,&arg3,&term4)) {
    if (traverse_SgUntypedExpression(term4, &arg4)) {
      // SgUntypedExpression
    } else return ATfalse;
  } else return ATfalse;

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedBinaryOperator
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedBinaryOperator(ATerm term, sage::SgUntypedBinaryOperator** SgUntypedBinaryOperator)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedBinaryOperator: %s\n", ATwriteToString(term));
#endif

  ATerm term4, term5;
  int arg1;
  int arg2;
  char* arg3;
  sage::SgUntypedExpression* arg4;
  sage::SgUntypedExpression* arg5;
  
  *SgUntypedBinaryOperator = NULL;
  if (ATmatch(term, "SgUntypedBinaryOperator(<int>,<int>,<str>,<term>,<term>)", &arg1,&arg2,&arg3,&term4,&term5)) {
    if (traverse_SgUntypedExpression(term4, &arg4)) {
      // SgUntypedExpression
    } else return ATfalse;
    if (traverse_SgUntypedExpression(term5, &arg5)) {
      // SgUntypedExpression
    } else return ATfalse;
  } else return ATfalse;

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}


//========================================================================================
// TODO - FIXME
// SgUntypedType
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedType(ATerm term, sage::SgUntypedType** SgUntypedType)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedType: %s\n", ATwriteToString(term));
#endif
  
#ifdef FIXME
  *SgUntypedType = NULL;
  if (ATmatch(term, "SgUntypedType()")) {
  } else return ATfalse;
#endif

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}


//========================================================================================
// TODO - FIXME
// SgUntypedExpression
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedExpression(ATerm term, sage::SgUntypedExpression** SgUntypedExpression)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedExpression: %s\n", ATwriteToString(term));
#endif
  
#ifdef FIXME
  *SgUntypedExpression = NULL;
  if (ATmatch(term, "SgUntypedExpression()")) {
  } else return ATfalse;
#endif

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}
