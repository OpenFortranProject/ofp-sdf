#include "traverse_SgUntypedNodes.hpp"

#define DEBUG_PRINT


#ifdef NOT_YET
ATbool ofp_traverse_AttrSpecList(ATerm term, sage::AttrSpecList** AttrSpecList)
{
#ifdef DEBUG_PRINT
   printf("traverse_AttrSpecList: %s\n", ATwriteToString(term));
#endif

   if (! ATmatch(term, "AttrSpecList(<term>)", &AttrSpecList->term)) {
      return ATfalse;
   }

   OFP_Traverse AttrSpec;
   ATermList AttrSpec_tail = (ATermList) ATmake("<term>", AttrSpecList->term);
   while (! ATisEmpty(AttrSpec_tail)) {
      AttrSpec.term = ATgetFirst(AttrSpec_tail);
      AttrSpec_tail = ATgetNext (AttrSpec_tail);
      if (ofp_traverse_AttrSpec(AttrSpec.term, &AttrSpec)) {
         // MATCHED AttrSpec                                                              
      } else return ATfalse;
   }
   return ATtrue;
}
#endif



ATbool traverse_SgUntypedStatementList(ATerm term, sage::SgUntypedStatementList** SgUntypedStatementList)
{
#ifdef DEBUG_PRINT
   printf("traverse_SgUntypedStatementList: %s\n", ATwriteToString(term));
#endif

  ATerm term1;
  sage::SgUntypedStatement* arg1;

  *SgUntypedStatementList = NULL;

  if (ATmatch(term, "SgUntypedStatementList(<term>)", &term1)) {
     std::list<sage::SgUntypedStatement*>* plist = new std::list<sage::SgUntypedStatement*>();

#ifdef NOT_YET

     ATermList tail = (ATermList) ATmake("<term>", term1);
     while (! ATisEmpty(tail)) {
        ATerm head = ATgetFirst(tail);
        tail = ATgetNext(tail);
        if (traverse_SgUntypedDeclarationStatement(term1, &arg1)) {
           // MATCHED SgUntypedDeclarationStatement
        }
        else if (traverse_SgUntypedAssignmentStatement(term1, &arg1)) {
           // MATCHED SgUntypedAssignmentStatement
        }
        else if (traverse_SgUntypedFunctionCallStatement(term1, &arg1)) {
           // MATCHED SgUntypedFunctionCallStatement
        }
        else if (traverse_SgUntypedBlockStatement(term1, &arg1)) {
           // MATCHED SgUntypedBlockStatement
        }
        else if (traverse_SgUntypedNamedStatement(term1, &arg1)) {
           // MATCHED SgUntypedNamedStatement
        }
`        else if (traverse_SgUntypedOtherStatement(term1, &arg1)) {
           // MATCHED SgUntypedOtherStatement
        }
        else if (traverse_SgUntypedScope(term1, &arg1)) {
           // MATCHED SgUntypedScope
        }
        else {
           delete plist;
           *SgUntypedStatementList = NULL;
           return ATfalse;
        }

        plist->push_back(arg1);
     }
#endif

  }
  else return ATfalse;

#ifdef NOT_YET
  *SgUntypedStatementList = plist;
#endif

  return ATtrue;
}


ATbool traverse_SgUntypedDeclarationList(ATerm term, sage::SgUntypedDeclarationList** SgUntypedDeclarationList)
{
#ifdef DEBUG_PRINT
   printf("traverse_SgUntypedDeclarationList: %s\n", ATwriteToString(term));
#endif

  *SgUntypedDeclarationList = NULL;

  return ATtrue;
}

ATbool traverse_SgUntypedFunctionDeclarationList(ATerm term, sage::SgUntypedFunctionDeclarationList** SgUntypedFunctionDeclarationList)
{
#ifdef DEBUG_PRINT
   printf("traverse_SgUntypedFunctionDeclarationList: %s\n", ATwriteToString(term));
#endif

  ATerm term1;
  *SgUntypedFunctionDeclarationList = NULL;

  if (ATmatch(term, "SgUntypedFunctionDeclarationList(<term>)", &term1)) {
     std::list<sage::SgUntypedFunctionDeclaration*>* plist = new std::list<sage::SgUntypedFunctionDeclaration*>();

     ATermList tail = (ATermList) ATmake("<term>", term1);
     while (! ATisEmpty(tail)) {
        ATerm head = ATgetFirst(tail);
        tail = ATgetNext(tail);
        {
           sage::SgUntypedProgramHeaderDeclaration* arg1;
           if (traverse_SgUntypedProgramHeaderDeclaration(head, &arg1)) {
              // MATCHED SgUntypedProgramHeaderDeclaration
              plist->push_back(arg1);
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


ATbool traverse_SgUntypedInitializedNameList(ATerm term, sage::SgUntypedInitializedNameList** SgUntypedInitializedNameList)
{
#ifdef DEBUG_PRINT
   printf("traverse_SgUntypedInitializedNameList: %s\n", ATwriteToString(term));
#endif

  ATerm term1;
  *SgUntypedInitializedNameList = NULL;

  if (ATmatch(term, "SgUntypedInitializedNameList(<term>)", &term1)) {
     std::list<sage::SgUntypedInitializedName*>* plist = new std::list<sage::SgUntypedInitializedName*>();

     ATermList tail = (ATermList) ATmake("<term>", term1);
     while (! ATisEmpty(tail)) {
        ATerm head = ATgetFirst(tail);
        tail = ATgetNext(tail);

        sage::SgUntypedInitializedName* arg1;
        if (traverse_SgUntypedInitializedName(head, &arg1)) {
           // MATCHED SgUntypedInitializedName
        }
        else {
           delete plist;
           return ATfalse;
        }
        plist->push_back(arg1);
     }

     *SgUntypedInitializedNameList = plist;
  }
  else return ATfalse;

  return ATtrue;
}
