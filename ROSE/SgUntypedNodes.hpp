#ifndef SG_UNTYPED_NODES_HPP
#define SG_UNTYPED_NODES_HPP

#include <string>
#include <list>


namespace sage {

class SgNode;
class SgLocatedNode;
class SgLocatedNodeSupport;
class SgUntypedNode;
class SgUntypedExpression;
class SgUntypedStatement;
class SgUntypedDeclaration;
class SgUntypedType;
class SgUntypedAttribute;


   //class SgUntypedDeclarationStatement;
class SgUntypedFunctionDeclaration;
class SgUntypedScope;
class SgUntypedModuleScope;
class SgUntypedFunctionScope;
   //class SgUntypedTypeUnknown;

class SgUntypedUnknown;
class SgUntypedGlobalScope;

  
class SgUntypedAttribute {
   public:
   SgUntypedAttribute(int, std::string);
};

class SgUntypedInitializedName {
   public:
   SgUntypedInitializedName(SgUntypedType*, std::string);
};

class SgUntypedFile
{
 public:

   SgUntypedFile(SgUntypedGlobalScope*);
   ~SgUntypedFile();

   // protected:
   SgUntypedGlobalScope * p_SgUntypedGlobalScope;   
};

class SgUntypedDeclarationStatement;

class SgUntypedStatementList {
   SgUntypedStatementList(std::list<SgUntypedStatement> *);
};

class SgUntypedDeclarationList {
   SgUntypedDeclarationList(std::list<SgUntypedDeclarationStatement> *);
};

typedef std::list<SgUntypedFunctionDeclaration*> SgUntypedFunctionDeclarationList;
   //class SgUntypedFunctionDeclarationList {
   //   SgUntypedFunctionDeclarationList(std::list<SgUntypedFunctionDeclaration> *);
   //};

typedef std::list<SgUntypedInitializedName*> SgUntypedInitializedNameList;
   //class SgUntypedInitializedNameList {
   //   SgUntypedInitializedNameList(std::list<SgUntypedInitializedName> *);
   //};

class SgUntypedValueExpression {
    SgUntypedValueExpression(int, std::string, SgUntypedType);
};

class SgUntypedArrayReferenceExpression {
    SgUntypedArrayReferenceExpression(int);
};

class SgUntypedOtherExpression {
    SgUntypedOtherExpression(int);
};

class SgUntypedFunctionCallOrArrayReferenceExpression {
    SgUntypedFunctionCallOrArrayReferenceExpression(int);
};

class SgUntypedReferenceExpression {
    SgUntypedReferenceExpression(int, std::string);
};

class SgUntypedAssignmentStatement {
    SgUntypedAssignmentStatement(std::string, int, SgUntypedExpression, SgUntypedExpression);
};

class SgUntypedFunctionCallStatement {
    SgUntypedFunctionCallStatement(std::string, int);
};

class SgUntypedNamedStatement {
    SgUntypedNamedStatement(std::string, int, std::string);
};

class SgUntypedOtherStatement {
    SgUntypedOtherStatement(std::string, int);
};

class SgUntypedImplicitDeclaration {
    SgUntypedImplicitDeclaration(std::string, int);
};

class SgUntypedVariableDeclaration {
    SgUntypedVariableDeclaration(std::string, int, SgUntypedType, SgUntypedInitializedNameList);
};

class SgUntypedModuleDeclaration {
    SgUntypedModuleDeclaration(std::string, int, std::string, SgUntypedModuleScope, SgUntypedNamedStatement);
};

class SgUntypedDeclaration {
    public:
    SgUntypedDeclaration();
};

class SgUntypedFunctionDeclaration : public SgUntypedDeclaration {
    public:
    SgUntypedFunctionDeclaration();
};

class SgUntypedProgramHeaderDeclaration : public SgUntypedFunctionDeclaration {
    SgUntypedProgramHeaderDeclaration(std::string, int, std::string, SgUntypedInitializedNameList, SgUntypedType, SgUntypedFunctionScope, SgUntypedNamedStatement);
};

class SgUntypedSubroutineDeclaration {
    SgUntypedSubroutineDeclaration(std::string, int, std::string, SgUntypedInitializedNameList, SgUntypedType, SgUntypedFunctionScope, SgUntypedNamedStatement);
};

class SgUntypedFunctionScope {
    SgUntypedFunctionScope(std::string, int, SgUntypedDeclarationList, SgUntypedStatementList, SgUntypedFunctionDeclarationList);
};

class SgUntypedModuleScope {
    SgUntypedModuleScope(std::string, int, SgUntypedDeclarationList, SgUntypedStatementList, SgUntypedFunctionDeclarationList);
};

class SgUntypedGlobalScope {
   public:
   SgUntypedGlobalScope(std::string, int, SgUntypedDeclarationList*, SgUntypedStatementList*, SgUntypedFunctionDeclarationList*);
};

class SgUntypedArrayType {
    SgUntypedArrayType(std::string, SgUntypedExpression, bool, bool, bool, bool, bool, bool, SgUntypedExpression, std::string, bool);
};

class SgUntypedTypeVoid;
class SgUntypedTypeUnknown;

class SgUntypedTypeInt {
    SgUntypedTypeInt();
};

class SgUntypedTypeFloat {
    SgUntypedTypeFloat();
};

class SgUntypedTypeDouble {
    SgUntypedTypeDouble();
};

class SgUntypedTypeBool {
    SgUntypedTypeBool();
};

class SgUntypedBlockScope {
    SgUntypedBlockScope(std::string, int, SgUntypedDeclarationList, SgUntypedStatementList, SgUntypedFunctionDeclarationList);
};

class SgUntypedBlockStatement {
    SgUntypedBlockStatement(std::string, int, std::string, SgUntypedBlockScope, SgUntypedNamedStatement);
};

class SgUntypedUnaryOperator {
    SgUntypedUnaryOperator(int, int, std::string, SgUntypedExpression);
};

class SgUntypedBinaryOperator {
    SgUntypedBinaryOperator(int, int, std::string, SgUntypedExpression, SgUntypedExpression);
};

} // namespace sage

#endif //SG_UNTYPED_NODES_HPP
