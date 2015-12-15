#ifndef TRAVERSE_SG_UNTYPED_NODES_HPP
#define TRAVERSE_SG_UNTYPED_NODES_HPP

#include <aterm2.h>
#include "SgUntypedNodes.hpp"


ATbool traverse_SgLocatedNode(ATerm, sage::SgLocatedNode**);
ATbool traverse_SgLocatedNodeSupport(ATerm, sage::SgLocatedNodeSupport**);
ATbool traverse_SgUntypedNode(ATerm, sage::SgUntypedNode**);
ATbool traverse_SgUntypedExpression(ATerm, sage::SgUntypedExpression**);
ATbool traverse_SgUntypedStatement(ATerm, sage::SgUntypedStatement**);
ATbool traverse_SgUntypedType(ATerm, sage::SgUntypedType**);
ATbool traverse_SgUntypedAttribute(ATerm, sage::SgUntypedAttribute**);
ATbool traverse_SgUntypedInitializedName(ATerm, sage::SgUntypedInitializedName**);
ATbool traverse_SgUntypedFile(ATerm, sage::SgUntypedFile**);
ATbool traverse_SgUntypedStatementList(ATerm, sage::SgUntypedStatementList**);
ATbool traverse_SgUntypedDeclarationList(ATerm, sage::SgUntypedDeclarationList**);
ATbool traverse_SgUntypedFunctionDeclarationList(ATerm, sage::SgUntypedFunctionDeclarationList**);
ATbool traverse_SgUntypedInitializedNameList(ATerm, sage::SgUntypedInitializedNameList**);
ATbool traverse_SgUntypedUnaryOperator(ATerm, sage::SgUntypedUnaryOperator**);
ATbool traverse_SgUntypedBinaryOperator(ATerm, sage::SgUntypedBinaryOperator**);
ATbool traverse_SgUntypedValueExpression(ATerm, sage::SgUntypedValueExpression**);
ATbool traverse_SgUntypedArrayReferenceExpression(ATerm, sage::SgUntypedArrayReferenceExpression**);
ATbool traverse_SgUntypedOtherExpression(ATerm, sage::SgUntypedOtherExpression**);
ATbool traverse_SgUntypedFunctionCallOrArrayReferenceExpression(ATerm, sage::SgUntypedFunctionCallOrArrayReferenceExpression**);
ATbool traverse_SgUntypedReferenceExpression(ATerm, sage::SgUntypedReferenceExpression**);
ATbool traverse_SgUntypedDeclarationStatement(ATerm, sage::SgUntypedDeclarationStatement**);
ATbool traverse_SgUntypedAssignmentStatement(ATerm, sage::SgUntypedAssignmentStatement**);
ATbool traverse_SgUntypedFunctionCallStatement(ATerm, sage::SgUntypedFunctionCallStatement**);
ATbool traverse_SgUntypedBlockStatement(ATerm, sage::SgUntypedBlockStatement**);
ATbool traverse_SgUntypedNamedStatement(ATerm, sage::SgUntypedNamedStatement**);
ATbool traverse_SgUntypedOtherStatement(ATerm, sage::SgUntypedOtherStatement**);
ATbool traverse_SgUntypedScope(ATerm, sage::SgUntypedScope**);
ATbool traverse_SgUntypedImplicitDeclaration(ATerm, sage::SgUntypedImplicitDeclaration**);
ATbool traverse_SgUntypedVariableDeclaration(ATerm, sage::SgUntypedVariableDeclaration**);
ATbool traverse_SgUntypedFunctionDeclaration(ATerm, sage::SgUntypedFunctionDeclaration**);
ATbool traverse_SgUntypedModuleDeclaration(ATerm, sage::SgUntypedModuleDeclaration**);
ATbool traverse_SgUntypedProgramHeaderDeclaration(ATerm, sage::SgUntypedProgramHeaderDeclaration**);
ATbool traverse_SgUntypedSubroutineDeclaration(ATerm, sage::SgUntypedSubroutineDeclaration**);
ATbool traverse_SgUntypedFunctionScope(ATerm, sage::SgUntypedFunctionScope**);
ATbool traverse_SgUntypedModuleScope(ATerm, sage::SgUntypedModuleScope**);
ATbool traverse_SgUntypedGlobalScope(ATerm, sage::SgUntypedGlobalScope**);
ATbool traverse_SgUntypedArrayType(ATerm, sage::SgUntypedArrayType**);
ATbool traverse_SgUntypedTypeVoid(ATerm, sage::SgUntypedTypeVoid**);
ATbool traverse_SgUntypedTypeUnknown(ATerm, sage::SgUntypedTypeUnknown**);
ATbool traverse_SgUntypedTypeInt(ATerm, sage::SgUntypedTypeInt**);
ATbool traverse_SgUntypedTypeFloat(ATerm, sage::SgUntypedTypeFloat**);
ATbool traverse_SgUntypedTypeDouble(ATerm, sage::SgUntypedTypeDouble**);
ATbool traverse_SgUntypedTypeBool(ATerm, sage::SgUntypedTypeBool**);
ATbool traverse_SgUntypedBlockScope(ATerm, sage::SgUntypedBlockScope**);

#endif // TRAVERSE_SG_UNTYPED_NODES_HPP
