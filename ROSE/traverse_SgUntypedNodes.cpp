//TODO
// 1. sage:bool -> bool
// 2. Turn build functions back on using BuildStmt in sage-to-traverse.str
// 3. Fix SgUntypedType and remove SgUntypedTypeFloat, ...
// 4. Fix SgUntypedExpression
// - SgUntypedType and SgUntypedExpression should be fixed in new grammar

//========================================================================================
// SgUntypedFile
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedFile(ATerm term, SgUntypedFile** var_SgUntypedFile)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedFile: %s\n", ATwriteToString(term));
#endif

  ATerm term1;
  SgUntypedGlobalScope* arg1;
  
  *var_SgUntypedFile = NULL;
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
ATbool traverse_SgUntypedGlobalScope(ATerm term, SgUntypedGlobalScope** var_SgUntypedGlobalScope)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedGlobalScope: %s\n", ATwriteToString(term));
#endif

  ATerm term3, term4, term5;
  char* arg1;
  int arg2;
  SgUntypedDeclarationList* arg3;
  SgUntypedStatementList* arg4;
  SgUntypedFunctionDeclarationList* arg5;
  
  *var_SgUntypedGlobalScope = NULL;
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
ATbool traverse_SgUntypedAttribute(ATerm term, SgUntypedAttribute** var_SgUntypedAttribute)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedAttribute: %s\n", ATwriteToString(term));
#endif

  int arg1;
  char* arg2;
  
  *var_SgUntypedAttribute = NULL;
  if (ATmatch(term, "SgUntypedAttribute(<int>,<str>)", &arg1,&arg2)) {
  } else return ATfalse;

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedInitializedName
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedInitializedName(ATerm term, SgUntypedInitializedName** var_SgUntypedInitializedName)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedInitializedName: %s\n", ATwriteToString(term));
#endif

  ATerm term1;
  SgUntypedType* arg1;
  char* arg2;
  
  *var_SgUntypedInitializedName = NULL;
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
ATbool traverse_SgUntypedStatementList(ATerm term, SgUntypedStatementList** var_SgUntypedStatementList)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedStatementList: %s\n", ATwriteToString(term));
#endif

  ATerm term1;
  
  *var_SgUntypedStatementList = NULL;
  if (ATmatch(term, "SgUntypedStatementList(<term>)", &term1)) {
     SgUntypedStatementList* plist = new SgUntypedStatementList();

     ATermList tail = (ATermList) ATmake("<term>", term1);
     while (! ATisEmpty(tail)) {
        ATerm head = ATgetFirst(tail);
        tail = ATgetNext(tail);
        {
           SgUntypedScope* arg;
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
           SgUntypedOtherStatement* arg;
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
           SgUntypedNamedStatement* arg;
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
           SgUntypedBlockStatement* arg;
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
           SgUntypedFunctionCallStatement* arg;
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
           SgUntypedAssignmentStatement* arg;
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
           SgUntypedDeclarationStatement* arg;
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
     *var_SgUntypedStatementList = plist;
  }
  else return ATfalse;
  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedDeclarationList
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedDeclarationList(ATerm term, SgUntypedDeclarationList** var_SgUntypedDeclarationList)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedDeclarationList: %s\n", ATwriteToString(term));
#endif

  ATerm term1;
  
  *var_SgUntypedDeclarationList = NULL;
  if (ATmatch(term, "SgUntypedDeclarationList(<term>)", &term1)) {
     SgUntypedDeclarationList* plist = new SgUntypedDeclarationList();

     ATermList tail = (ATermList) ATmake("<term>", term1);
     while (! ATisEmpty(tail)) {
        ATerm head = ATgetFirst(tail);
        tail = ATgetNext(tail);
        {
           SgUntypedDeclaration* arg;
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
     *var_SgUntypedDeclarationList = plist;
  }
  else return ATfalse;
  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedFunctionDeclarationList
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedFunctionDeclarationList(ATerm term, SgUntypedFunctionDeclarationList** var_SgUntypedFunctionDeclarationList)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedFunctionDeclarationList: %s\n", ATwriteToString(term));
#endif

  ATerm term1;
  
  *var_SgUntypedFunctionDeclarationList = NULL;
  if (ATmatch(term, "SgUntypedFunctionDeclarationList(<term>)", &term1)) {
     SgUntypedFunctionDeclarationList* plist = new SgUntypedFunctionDeclarationList();

     ATermList tail = (ATermList) ATmake("<term>", term1);
     while (! ATisEmpty(tail)) {
        ATerm head = ATgetFirst(tail);
        tail = ATgetNext(tail);
        {
           SgUntypedSubroutineDeclaration* arg;
           if (traverse_SgUntypedSubroutineDeclaration(head, &arg)) {
              // SgUntypedSubroutineDeclaration
              plist->push_back(arg);
           }
           else {
              delete plist;
              return ATfalse;
           }
        }
        {
           SgUntypedProgramHeaderDeclaration* arg;
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
     *var_SgUntypedFunctionDeclarationList = plist;
  }
  else return ATfalse;
  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedInitializedNameList
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedInitializedNameList(ATerm term, SgUntypedInitializedNameList** var_SgUntypedInitializedNameList)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedInitializedNameList: %s\n", ATwriteToString(term));
#endif

  ATerm term1;
  
  *var_SgUntypedInitializedNameList = NULL;
  if (ATmatch(term, "SgUntypedInitializedNameList(<term>)", &term1)) {
     SgUntypedInitializedNameList* plist = new SgUntypedInitializedNameList();

     ATermList tail = (ATermList) ATmake("<term>", term1);
     while (! ATisEmpty(tail)) {
        ATerm head = ATgetFirst(tail);
        tail = ATgetNext(tail);
        {
           SgUntypedInitializedName* arg;
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
     *var_SgUntypedInitializedNameList = plist;
  }
  else return ATfalse;
  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedValueExpression
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedValueExpression(ATerm term, SgUntypedValueExpression** var_SgUntypedValueExpression)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedValueExpression: %s\n", ATwriteToString(term));
#endif

  ATerm term3;
  int arg1;
  char* arg2;
  SgUntypedType* arg3;
  
  *var_SgUntypedValueExpression = NULL;
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
ATbool traverse_SgUntypedArrayReferenceExpression(ATerm term, SgUntypedArrayReferenceExpression** var_SgUntypedArrayReferenceExpression)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedArrayReferenceExpression: %s\n", ATwriteToString(term));
#endif

  int arg1;
  
  *var_SgUntypedArrayReferenceExpression = NULL;
  if (ATmatch(term, "SgUntypedArrayReferenceExpression(<int>)", &arg1)) {
  } else return ATfalse;

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedOtherExpression
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedOtherExpression(ATerm term, SgUntypedOtherExpression** var_SgUntypedOtherExpression)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedOtherExpression: %s\n", ATwriteToString(term));
#endif

  int arg1;
  
  *var_SgUntypedOtherExpression = NULL;
  if (ATmatch(term, "SgUntypedOtherExpression(<int>)", &arg1)) {
  } else return ATfalse;

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedFunctionCallOrArrayReferenceExpression
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedFunctionCallOrArrayReferenceExpression(ATerm term, SgUntypedFunctionCallOrArrayReferenceExpression** var_SgUntypedFunctionCallOrArrayReferenceExpression)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedFunctionCallOrArrayReferenceExpression: %s\n", ATwriteToString(term));
#endif

  int arg1;
  
  *var_SgUntypedFunctionCallOrArrayReferenceExpression = NULL;
  if (ATmatch(term, "SgUntypedFunctionCallOrArrayReferenceExpression(<int>)", &arg1)) {
  } else return ATfalse;

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedReferenceExpression
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedReferenceExpression(ATerm term, SgUntypedReferenceExpression** var_SgUntypedReferenceExpression)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedReferenceExpression: %s\n", ATwriteToString(term));
#endif

  int arg1;
  char* arg2;
  
  *var_SgUntypedReferenceExpression = NULL;
  if (ATmatch(term, "SgUntypedReferenceExpression(<int>,<str>)", &arg1,&arg2)) {
  } else return ATfalse;

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedAssignmentStatement
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedAssignmentStatement(ATerm term, SgUntypedAssignmentStatement** var_SgUntypedAssignmentStatement)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedAssignmentStatement: %s\n", ATwriteToString(term));
#endif

  ATerm term3, term4;
  char* arg1;
  int arg2;
  SgUntypedExpression* arg3;
  SgUntypedExpression* arg4;
  
  *var_SgUntypedAssignmentStatement = NULL;
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
ATbool traverse_SgUntypedFunctionCallStatement(ATerm term, SgUntypedFunctionCallStatement** var_SgUntypedFunctionCallStatement)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedFunctionCallStatement: %s\n", ATwriteToString(term));
#endif

  char* arg1;
  int arg2;
  
  *var_SgUntypedFunctionCallStatement = NULL;
  if (ATmatch(term, "SgUntypedFunctionCallStatement(<str>,<int>)", &arg1,&arg2)) {
  } else return ATfalse;

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedNamedStatement
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedNamedStatement(ATerm term, SgUntypedNamedStatement** var_SgUntypedNamedStatement)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedNamedStatement: %s\n", ATwriteToString(term));
#endif

  char* arg1;
  int arg2;
  char* arg3;
  
  *var_SgUntypedNamedStatement = NULL;
  if (ATmatch(term, "SgUntypedNamedStatement(<str>,<int>,<str>)", &arg1,&arg2,&arg3)) {
  } else return ATfalse;

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedOtherStatement
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedOtherStatement(ATerm term, SgUntypedOtherStatement** var_SgUntypedOtherStatement)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedOtherStatement: %s\n", ATwriteToString(term));
#endif

  char* arg1;
  int arg2;
  
  *var_SgUntypedOtherStatement = NULL;
  if (ATmatch(term, "SgUntypedOtherStatement(<str>,<int>)", &arg1,&arg2)) {
  } else return ATfalse;

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedImplicitDeclaration
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedImplicitDeclaration(ATerm term, SgUntypedImplicitDeclaration** var_SgUntypedImplicitDeclaration)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedImplicitDeclaration: %s\n", ATwriteToString(term));
#endif

  char* arg1;
  int arg2;
  
  *var_SgUntypedImplicitDeclaration = NULL;
  if (ATmatch(term, "SgUntypedImplicitDeclaration(<str>,<int>)", &arg1,&arg2)) {
  } else return ATfalse;

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedVariableDeclaration
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedVariableDeclaration(ATerm term, SgUntypedVariableDeclaration** var_SgUntypedVariableDeclaration)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedVariableDeclaration: %s\n", ATwriteToString(term));
#endif

  ATerm term3, term4;
  char* arg1;
  int arg2;
  SgUntypedType* arg3;
  SgUntypedInitializedNameList* arg4;
  
  *var_SgUntypedVariableDeclaration = NULL;
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
ATbool traverse_SgUntypedModuleDeclaration(ATerm term, SgUntypedModuleDeclaration** var_SgUntypedModuleDeclaration)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedModuleDeclaration: %s\n", ATwriteToString(term));
#endif

  ATerm term4, term5;
  char* arg1;
  int arg2;
  char* arg3;
  SgUntypedModuleScope* arg4;
  SgUntypedNamedStatement* arg5;
  
  *var_SgUntypedModuleDeclaration = NULL;
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
ATbool traverse_SgUntypedProgramHeaderDeclaration(ATerm term, SgUntypedProgramHeaderDeclaration** var_SgUntypedProgramHeaderDeclaration)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedProgramHeaderDeclaration: %s\n", ATwriteToString(term));
#endif

  ATerm term4, term5, term6, term7;
  char* arg1;
  int arg2;
  char* arg3;
  SgUntypedInitializedNameList* arg4;
  SgUntypedType* arg5;
  SgUntypedFunctionScope* arg6;
  SgUntypedNamedStatement* arg7;
  
  *var_SgUntypedProgramHeaderDeclaration = NULL;
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
ATbool traverse_SgUntypedSubroutineDeclaration(ATerm term, SgUntypedSubroutineDeclaration** var_SgUntypedSubroutineDeclaration)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedSubroutineDeclaration: %s\n", ATwriteToString(term));
#endif

  ATerm term4, term5, term6, term7;
  char* arg1;
  int arg2;
  char* arg3;
  SgUntypedInitializedNameList* arg4;
  SgUntypedType* arg5;
  SgUntypedFunctionScope* arg6;
  SgUntypedNamedStatement* arg7;
  
  *var_SgUntypedSubroutineDeclaration = NULL;
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
ATbool traverse_SgUntypedFunctionScope(ATerm term, SgUntypedFunctionScope** var_SgUntypedFunctionScope)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedFunctionScope: %s\n", ATwriteToString(term));
#endif

  ATerm term3, term4, term5;
  char* arg1;
  int arg2;
  SgUntypedDeclarationList* arg3;
  SgUntypedStatementList* arg4;
  SgUntypedFunctionDeclarationList* arg5;
  
  *var_SgUntypedFunctionScope = NULL;
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
ATbool traverse_SgUntypedModuleScope(ATerm term, SgUntypedModuleScope** var_SgUntypedModuleScope)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedModuleScope: %s\n", ATwriteToString(term));
#endif

  ATerm term3, term4, term5;
  char* arg1;
  int arg2;
  SgUntypedDeclarationList* arg3;
  SgUntypedStatementList* arg4;
  SgUntypedFunctionDeclarationList* arg5;
  
  *var_SgUntypedModuleScope = NULL;
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
ATbool traverse_SgUntypedArrayType(ATerm term, SgUntypedArrayType** var_SgUntypedArrayType)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedArrayType: %s\n", ATwriteToString(term));
#endif

  ATerm term2, term3, term4, term5, term6, term7, term8, term9, term11;
  char* arg1;
  SgUntypedExpression* arg2;
  bool* arg3;
  bool* arg4;
  bool* arg5;
  bool* arg6;
  bool* arg7;
  bool* arg8;
  SgUntypedExpression* arg9;
  char* arg10;
  bool* arg11;
  
  *var_SgUntypedArrayType = NULL;
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

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedTypeVoid
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedTypeVoid(ATerm term, SgUntypedTypeVoid** var_SgUntypedTypeVoid)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedTypeVoid: %s\n", ATwriteToString(term));
#endif

  
  *var_SgUntypedTypeVoid = NULL;
  if (ATmatch(term, "SgUntypedTypeVoid()", )) {
  } else return ATfalse;

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedTypeUnknown
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedTypeUnknown(ATerm term, SgUntypedTypeUnknown** var_SgUntypedTypeUnknown)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedTypeUnknown: %s\n", ATwriteToString(term));
#endif

  
  *var_SgUntypedTypeUnknown = NULL;
  if (ATmatch(term, "SgUntypedTypeUnknown()", )) {
  } else return ATfalse;

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedTypeInt
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedTypeInt(ATerm term, SgUntypedTypeInt** var_SgUntypedTypeInt)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedTypeInt: %s\n", ATwriteToString(term));
#endif

  
  *var_SgUntypedTypeInt = NULL;
  if (ATmatch(term, "SgUntypedTypeInt()", )) {
  } else return ATfalse;

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedTypeFloat
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedTypeFloat(ATerm term, SgUntypedTypeFloat** var_SgUntypedTypeFloat)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedTypeFloat: %s\n", ATwriteToString(term));
#endif

  
  *var_SgUntypedTypeFloat = NULL;
  if (ATmatch(term, "SgUntypedTypeFloat()", )) {
  } else return ATfalse;

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedTypeDouble
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedTypeDouble(ATerm term, SgUntypedTypeDouble** var_SgUntypedTypeDouble)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedTypeDouble: %s\n", ATwriteToString(term));
#endif

  
  *var_SgUntypedTypeDouble = NULL;
  if (ATmatch(term, "SgUntypedTypeDouble()", )) {
  } else return ATfalse;

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedTypeBool
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedTypeBool(ATerm term, SgUntypedTypeBool** var_SgUntypedTypeBool)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedTypeBool: %s\n", ATwriteToString(term));
#endif

  
  *var_SgUntypedTypeBool = NULL;
  if (ATmatch(term, "SgUntypedTypeBool()", )) {
  } else return ATfalse;

  // turn on build functions (using BuildStmt) in sage-to-traverse.str

  return ATtrue;
}

//========================================================================================
// SgUntypedBlockScope
//----------------------------------------------------------------------------------------
ATbool traverse_SgUntypedBlockScope(ATerm term, SgUntypedBlockScope** var_SgUntypedBlockScope)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedBlockScope: %s\n", ATwriteToString(term));
#endif

  ATerm term3, term4, term5;
  char* arg1;
  int arg2;
  SgUntypedDeclarationList* arg3;
  SgUntypedStatementList* arg4;
  SgUntypedFunctionDeclarationList* arg5;
  
  *var_SgUntypedBlockScope = NULL;
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
ATbool traverse_SgUntypedBlockStatement(ATerm term, SgUntypedBlockStatement** var_SgUntypedBlockStatement)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedBlockStatement: %s\n", ATwriteToString(term));
#endif

  ATerm term4, term5;
  char* arg1;
  int arg2;
  char* arg3;
  SgUntypedBlockScope* arg4;
  SgUntypedNamedStatement* arg5;
  
  *var_SgUntypedBlockStatement = NULL;
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
ATbool traverse_SgUntypedUnaryOperator(ATerm term, SgUntypedUnaryOperator** var_SgUntypedUnaryOperator)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedUnaryOperator: %s\n", ATwriteToString(term));
#endif

  ATerm term4;
  int arg1;
  int arg2;
  char* arg3;
  SgUntypedExpression* arg4;
  
  *var_SgUntypedUnaryOperator = NULL;
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
ATbool traverse_SgUntypedBinaryOperator(ATerm term, SgUntypedBinaryOperator** var_SgUntypedBinaryOperator)
{
#ifdef DEBUG_PRINT
  printf("... traverse_SgUntypedBinaryOperator: %s\n", ATwriteToString(term));
#endif

  ATerm term4, term5;
  int arg1;
  int arg2;
  char* arg3;
  SgUntypedExpression* arg4;
  SgUntypedExpression* arg5;
  
  *var_SgUntypedBinaryOperator = NULL;
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

