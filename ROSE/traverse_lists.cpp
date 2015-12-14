#include "traverse_SgUntypedNodes.hpp"

#define DEBUG_PRINT

#ifdef MOVED_BACK_TO_GENERATED

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

  return ATtrue;
}

#endif
