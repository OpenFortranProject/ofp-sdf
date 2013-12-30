#ifndef	OFP_TRAVERSAL_H
#define	OFP_TRAVERSAL_H

#define DEBUG_PRINT

#include <aterm2.h>

//#include "OFPNodes.h"
//#include "ofp_traverse.hpp"

namespace OFP {

   class EOS;
   class Ident;
   class Label;

   class StmtFunctionStmt;
   class ContainsStmt;
   class ReturnStmt;
   class EntryStmt;
   class EndMpSubprogramStmt;
   class MpSubprogramStmt;
   class SeparateModuleSubprogram;
   class EndSubroutineStmt;
   class DummyArgList;
   class DummyArg;
   class SubroutineStmt;
   class SubroutineSubprogram;
   class EndFunctionStmt;
   class Suffix;
   class DummyArgName;
   class ProcLanguageBindingSpec;
   class FunctionStmt;
   class FunctionSubprogram;
   class PrefixSpec;
   class Prefix;
   class AltReturnSpec;
   class ActualArg;
   class ActualArgSpecList;
   class ActualArgSpec;
   class ProcedureDesignator;
   class CallStmt;
   class FunctionReference;
   class IntrinsicProcedureNameList;
   class IntrinsicStmt;
   class InitialProcTarget;
   class ProcPointerInit;
   class InterfaceName;
   class ProcDeclList;
   class ProcDecl;
   class ProcAttrSpecList;
   class ProcAttrSpec;
   class ProcInterface;
   class ProcedureDeclarationStmt;
   class ExternalNameList;
   class ExternalStmt;
   class ImportNameList;
   class ImportStmt;
   class DefinedIoGenericSpec;
   class GenericSpec;
   class ProcedureNameList;
   class ProcedureStmt;
   class InterfaceBody;
   class EndInterfaceStmt;
   class InterfaceStmt;
   class InterfaceSpecification;
   class InterfaceBlock;
   class SubroutineName;
   class ResultName;
   class ProgramName;
   class ProcedureEntityName;
   class IntrinsicProcedureName;
   class ImportName;
   class GenericName;
   class FunctionName;
   class ExternalName;
   class EntryName;
   class EndBlockDataStmt;
   class BlockDataStmt;
   class BlockData;
   class EndSubmoduleStmt;
   class ParentIdentifier;
   class SubmoduleStmt;
   class Submodule;
   class UseDefinedOperator;
   class LocalDefinedOperator;
   class OnlyUseName;
   class OnlyList;
   class Only;
   class RenameList;
   class Rename;
   class ModuleNature;
   class UseStmt;
   class ModuleSubprogram;
   class ModuleSubprogramPart;
   class EndModuleStmt;
   class ModuleStmt;
   class Module;
   class EndProgramStmt;
   class ProgramStmt;
   class MainProgram;
   class Keyword;
   class ActionStmt;
   class ExecutableConstruct;
   class OtherSpecificationStmt;
   class InternalSubprogram;
   class InternalSubprogramPart;
   class ExecutionPartConstruct;
   class ExecutionPart;
   class DeclarationConstruct;
   class ImplicitPartStmt;
   class ImplicitPart;
   class SpecificationPart;
   class ExternalSubprogram;
   class ProgramUnit;
   class Program;
   class UseName;
   class SubmoduleName;
   class ParentSubmoduleName;
   class ModuleName;
   class LocalName;
   class BlockDataName;
   class AncestorModuleName;
   class DecimalEditDesc;
   class RoundEditDesc;
   class BlankInterpEditDesc;
   class SignEditDesc;
   class PositionEditDesc;
   class ControlEditDesc;
   class VEditDescList;
   class DataEditDesc;
   class UnlimitedFormatItem;
   class FormatItem;
   class FormatItems;
   class FormatSpecification;
   class FormatStmt;
   class InquireSpecList;
   class InquireSpec;
   class InquireStmt;
   class FlushSpecList;
   class FlushSpec;
   class FlushStmt;
   class PositionSpecList;
   class PositionSpec;
   class RewindStmt;
   class EndfileStmt;
   class BackspaceStmt;
   class WaitSpecList;
   class WaitSpec;
   class WaitStmt;
   class IoImpliedDoControl;
   class IoImpliedDoObjectList;
   class IoImpliedDoObject;
   class IoImpliedDo;
   class OutputItemList;
   class OutputItem;
   class InputItemList;
   class InputItem;
   class Format;
   class IdVariable;
   class IoControlSpecList;
   class IoControlSpec;
   class PrintStmt;
   class WriteStmt;
   class ReadStmt;
   class CloseSpecList;
   class CloseSpec;
   class CloseStmt;
   class IomsgVariable;
   class FileNameExpr;
   class ConnectSpecList;
   class ConnectSpec;
   class OpenStmt;
   class FileUnitNumber;
   class IoUnit;
   class PauseStmt;
   class LockVariable;
   class UnlockStmt;
   class LockStatList;
   class LockStat;
   class LockStmt;
   class SyncMemoryStmt;
   class ImageSet;
   class SyncImagesStmt;
   class SyncStatList;
   class SyncStat;
   class SyncAllStmt;
   class StopCode;
   class ErrorStopStmt;
   class StopStmt;
   class ContinueStmt;
   class ArithmeticIfStmt;
   class LabelList;
   class ComputedGotoStmt;
   class GotoStmt;
   class ExitStmt;
   class EndSelectTypeStmt;
   class TypeGuardStmt;
   class SelectTypeStmt;
   class TypeGuardStmtAndBlock;
   class SelectTypeConstruct;
   class CaseValue;
   class CaseValueRangeList;
   class CaseValueRange;
   class CaseSelector;
   class CaseExpr;
   class EndSelectStmt;
   class CaseStmt;
   class SelectCaseStmt;
   class CaseStmtAndBlock;
   class CaseConstruct;
   class IfStmt;
   class EndIfStmt;
   class ElseStmt;
   class ElseIfStmt;
   class IfThenStmt;
   class ElseStmtAndBlock;
   class ElseIfStmtAndBlock;
   class IfConstruct;
   class CycleStmt;
   class EndDoStmt;
   class DoVariable;
   class LoopControl;
   class NonlabelDoStmt;
   class LabelDoStmt;
   class EndCriticalStmt;
   class CriticalStmt;
   class CriticalConstruct;
   class EndBlockStmt;
   class BlockStmt;
   class BlockConstruct;
   class EndAssociateStmt;
   class Selector;
   class AssociationList;
   class Association;
   class AssociateStmt;
   class AssociateConstruct;
   class Block;
   class SelectConstructName;
   class ScalarIntVariableName;
   class IfConstructName;
   class DoConstructName;
   class CriticalConstructName;
   class ConstructName;
   class CaseConstructName;
   class BlockConstructName;
   class AssociateName;
   class AssociateConstructName;
   class ForallStmt;
   class EndForallStmt;
   class ForallAssignmentStmt;
   class ForallBodyConstruct;
   class ForallStep;
   class ForallLimit;
   class ForallTripletSpecList;
   class ForallTripletSpec;
   class ForallHeader;
   class ForallConstructStmt;
   class ForallConstruct;
   class EndWhereStmt;
   class ElsewhereStmt;
   class MaskedElsewhereStmt;
   class MaskExpr;
   class WhereAssignmentStmt;
   class WhereBodyConstruct;
   class WhereConstructStmt;
   class ElsewhereClause;
   class MaskedElsewhereClause;
   class WhereConstruct;
   class WhereStmt;
   class ProcTarget;
   class ProcComponentRef;
   class ProcPointerObject;
   class DataTarget;
   class BoundsRemappingList;
   class BoundsRemapping;
   class BoundsSpecList;
   class BoundsSpec;
   class DataPointerObject;
   class PointerAssignmentStmt;
   class AssignmentStmt;
   class IntConstantExpr;
   class ConstantExpr;
   class SpecificationExpr;
   class IntExpr;
   class DefaultCharExpr;
   class LogicalExpr;
   class DefinedBinaryOp;
   class Expr;
   class EquivOp;
   class OrOp;
   class AndOp;
   class NotOp;
   class RelOp;
   class ConcatOp;
   class AddOp;
   class MultOp;
   class PowerOp;
   class DefinedUnaryOp;
   class Primary;
   class ExtendedIntrinsicOp;
   class DefinedOperator;
   class IntrinsicOperator;
   class ProcedureComponentName;
   class IndexName;
   class ForallConstructName;
   class DataPointerComponentName;
   class DeallocOptList;
   class DeallocOpt;
   class DeallocateStmt;
   class PointerObjectList;
   class PointerObject;
   class NullifyStmt;
   class AllocateCoshapeSpecList;
   class AllocateCoshapeSpec;
   class AllocateCoarraySpec;
   class UpperBoundExpr;
   class LowerBoundExpr;
   class AllocateShapeSpecList;
   class AllocateShapeSpec;
   class AllocateObjectList;
   class AllocateObject;
   class AllocationList;
   class Allocation;
   class ErrmsgVariable;
   class StatVariable;
   class AllocOptList;
   class AllocOpt;
   class AllocateStmt;
   class CosubscriptList;
   class Cosubscript;
   class ImageSelector;
   class Stride;
   class SubscriptTriplet;
   class SectionSubscriptList;
   class SectionSubscript;
   class Subscript;
   class ArrayElement;
   class TypeParamInquiry;
   class CoindexedNamedObject;
   class StructureComponent;
   class PartRef;
   class DataRef;
   class SubstringRange;
   class ParentString;
   class Substring;
   class IntVariable;
   class DefaultCharVariable;
   class CharVariable;
   class LogicalVariable;
   class VariableName;
   class Variable;
   class Designator;
   class ScalarVariableName;
   class PartName;
   class CommonBlockObjectList;
   class CommonBlockObject;
   class CommonBlockEntry;
   class CommonBlockEntry1;
   class CommonStmt;
   class EquivalenceObjectList;
   class EquivalenceObject;
   class EquivalenceSetList;
   class EquivalenceSet;
   class EquivalenceStmt;
   class NamelistGroupObjectList;
   class NamelistGroupObject;
   class NamelistEntryList;
   class NamelistEntry;
   class NamelistStmt;
   class LetterSpecList;
   class LetterSpec;
   class ImplicitSpecList;
   class ImplicitSpec;
   class ImplicitStmt;
   class VolatileStmt;
   class ValueStmt;
   class TargetDeclList;
   class TargetDecl;
   class TargetStmt;
   class ProcPointerName;
   class SavedEntityList;
   class SavedEntity;
   class SaveStmt;
   class EntityNameList;
   class ProtectedStmt;
   class PointerDeclList;
   class PointerDecl;
   class PointerStmt;
   class NamedConstantDefList;
   class NamedConstantDef;
   class ParameterStmt;
   class OptionalStmt;
   class DummyArgNameList;
   class IntentStmt;
   class ArrayNameSpecList;
   class ArrayNameSpec;
   class DimensionStmt;
   class ConstantSubobject;
   class IntConstantSubobject;
   class DataStmtConstant;
   class DataStmtRepeat;
   class DataStmtValueList;
   class DataStmtValue;
   class DataIDoVariable;
   class DataIDoObjectList;
   class DataIDoObject;
   class DataImpliedDo;
   class DataStmtObjectList;
   class DataStmtObject;
   class DataStmtSetList;
   class DataStmtSet;
   class DataStmt;
   class ObjectNameList;
   class ContiguousStmt;
   class CodimensionDeclList;
   class CodimensionDecl;
   class CodimensionStmt;
   class BindEntityList;
   class BindEntity;
   class BindStmt;
   class AsynchronousStmt;
   class AllocatableDeclList;
   class AllocatableDecl;
   class AllocatableStmt;
   class AccessIdList;
   class AccessId;
   class AccessStmt;
   class IntentSpec;
   class ImpliedShapeSpecList;
   class ImpliedShapeSpec;
   class AssumedRankSpec;
   class AssumedSizeSpec;
   class DeferredShapeSpecList;
   class DeferredShapeSpec;
   class AssumedShapeSpecList;
   class AssumedShapeSpec;
   class UpperBound;
   class LowerBound;
   class ExplicitShapeSpecList;
   class ExplicitShapeSpec;
   class ArraySpec;
   class UpperCobound;
   class LowerCobound;
   class CoboundsEntry;
   class ExplicitCoshapeSpec;
   class DeferredCoshapeSpecList;
   class DeferredCoshapeSpec;
   class CoarraySpec;
   class LanguageBindingSpec;
   class AccessSpec;
   class NullInit;
   class Initialization;
   class EntityDeclList;
   class EntityDecl;
   class AttrSpecList;
   class AttrSpec;
   class OptAttrSpecList;
   class TypeDeclarationStmt;
   class ProcEntityName;
   class ObjectName;
   class NamelistGroupName;
   class EntityName;
   class CoarrayName;
   class CommonBlockName;
   class ArrayName;
   class AcDoVariable;
   class AcImpliedDoControl;
   class AcImpliedDo;
   class AcValue;
   class AcValueList;
   class AcSpec;
   class ArrayConstructor;
   class BozLiteralConstant;
   class EndEnumStmt;
   class EnumeratorList;
   class Enumerator;
   class EnumeratorDefStmt;
   class EnumDefStmt;
   class EnumDef;
   class ComponentDataSource;
   class ComponentSpec;
   class StructureConstructor;
   class TypeParamSpecList;
   class TypeParamSpec;
   class DerivedTypeSpec;
   class FinalSubroutineNameList;
   class FinalProcedureStmt;
   class BindingAttr;
   class TypeBoundGenericStmt;
   class TypeBoundProcDeclList;
   class TypeBoundProcDecl;
   class BindingNameList;
   class BindingAttrList;
   class TypeBoundProcedureStmt;
   class TypeBoundProcBinding;
   class BindingPrivateStmt;
   class TypeBoundProcedurePart;
   class PrivateComponentsStmt;
   class InitialDataTarget;
   class ComponentInitialization;
   class ProcComponentAttrSpecList;
   class ProcComponentAttrSpec;
   class ProcComponentDefStmt;
   class ComponentArraySpec;
   class ComponentDeclList;
   class ComponentDecl;
   class ComponentAttrSpecList;
   class ComponentAttrSpec;
   class OptComponentAttrSpecList;
   class DataComponentDefStmt;
   class ComponentDefStmt;
   class ComponentPart;
   class TypeParamAttrSpec;
   class TypeParamDeclList;
   class TypeParamDecl;
   class TypeParamDefStmt;
   class SequenceStmt;
   class EndTypeStmt;
   class PrivateOrSequence;
   class TypeAttrSpecList;
   class TypeAttrSpec;
   class TypeParamNameList;
   class OptTypeParamNameList;
   class OptTypeAttrSpecList;
   class DerivedTypeStmt;
   class DerivedTypeDef;
   class LogicalLiteralConstant;
   class CharLiteralConstant;
   class CharLength;
   class LengthSelector;
   class CharSelector;
   class ImagPart;
   class RealPart;
   class ComplexLiteralConstant;
   class RealLiteralConstant;
   class SignedRealLiteralConstant;
   class Sign;
   class DigitString;
   class KindParam;
   class IntLiteralConstant;
   class SignedIntLiteralConstant;
   class KindSelector;
   class IntrinsicTypeSpec;
   class DeclarationTypeSpec;
   class TypeSpec;
   class TypeParamValue;
   class NamedConstant;
   class LiteralConstant;
   class Constant;
   class TypeParamName;
   class TypeName;
   class ScalarIntConstantName;
   class ProcedureName;
   class ParentTypeName;
   class Name;
   class FinalSubroutineName;
   class ComponentName;
   class BindingName;
   class ArgName;
   class LblRef;

}

enum DataType
{
   UNKNOWN,
   STRING,
   IDENT,
   LIST,
   OPTION,
   CONST,
   OR
};

typedef struct OFP_Traverse_struct
{
   ATerm   term;
   void *  pre;
   void *  post;
}
   OFP_Traverse, * pOFP_Traverse;


/**                                                                                             
 * Section/Clause 2: Fortran concepts
 */

/* R201 */
ATbool ofp_traverse_Program(ATerm term, pOFP_Traverse Program);

/* R202 */
ATbool ofp_traverse_ProgramUnit(ATerm term, pOFP_Traverse ProgramUnit);

/* R203 */
ATbool ofp_traverse_ExternalSubprogram(ATerm term, pOFP_Traverse ExternalSubprogram);

/* R204 */
ATbool ofp_traverse_SpecificationPart(ATerm term, OFP::SpecificationPart* SpecificationPart);
ATbool ofp_traverse_SpecificationPart(ATerm term, pOFP_Traverse SpecificationPart);

/* R205 */
ATbool ofp_traverse_ImplicitPart(ATerm term, OFP::ImplicitPart* ImplicitPart);
ATbool ofp_traverse_ImplicitPart(ATerm term, pOFP_Traverse ImplicitPart);

/* R206 */
ATbool ofp_traverse_ImplicitPartStmt(ATerm term, OFP::ImplicitPartStmt* ImplicitPartStmt);
ATbool ofp_traverse_ImplicitPartStmt(ATerm term, pOFP_Traverse ImplicitPartStmt);

/* R207 */
ATbool ofp_traverse_DeclarationConstruct(ATerm term, OFP::DeclarationConstruct* DeclarationConstruct);
ATbool ofp_traverse_DeclarationConstruct(ATerm term, pOFP_Traverse DeclarationConstruct);

/* R208 */
ATbool ofp_traverse_ExecutionPart(ATerm term, pOFP_Traverse ExecutionPart);

/* R209 */
ATbool ofp_traverse_ExecutionPartConstruct(ATerm term, pOFP_Traverse ExecutionPartConstruct);

/* R210 */
ATbool ofp_traverse_InternalSubprogramPart(ATerm term, pOFP_Traverse InternalSubprogramPart);

/* R211 */
ATbool ofp_traverse_InternalSubprogram(ATerm term, pOFP_Traverse InternalSubprogram);

/* R212 */
ATbool ofp_traverse_OtherSpecificationStmt(ATerm term, pOFP_Traverse OtherSpecificationStmt);

/* R213 */
ATbool ofp_traverse_ExecutableConstruct(ATerm term, pOFP_Traverse ExecutableConstruct);

/* R214 */
ATbool ofp_traverse_ActionStmt(ATerm term, pOFP_Traverse ActionStmt);

/* R215 */
ATbool ofp_traverse_Keyword(ATerm term, pOFP_Traverse Keyword);

/**                                                                                             
 * Section/Clause 3: Lexical tokens and source form
 */

/* R304 */
ATbool ofp_traverse_Constant(ATerm term, pOFP_Traverse Constant);

/* R305 */
ATbool ofp_traverse_LiteralConstant(ATerm term, pOFP_Traverse LiteralConstant);

/* R306 */
ATbool ofp_traverse_NamedConstant(ATerm term, pOFP_Traverse NamedConstant);

/* R312 */
ATbool ofp_traverse_Label(ATerm term, OFP::Label * Label);
ATbool ofp_traverse_LblRef(ATerm term, pOFP_Traverse LblRef);

/**                                                                                             
 * Section/Clause 4: Types                                                                      
 */

/* R401 */
ATbool ofp_traverse_TypeParamValue(ATerm term, pOFP_Traverse TypeParamValue);

/* R402 */
ATbool ofp_traverse_TypeSpec(ATerm term, pOFP_Traverse TypeSpec);

/* R403 */
ATbool ofp_traverse_DeclarationTypeSpec(ATerm term, OFP::DeclarationTypeSpec* DeclarationTypeSpec);
ATbool ofp_traverse_DeclarationTypeSpec(ATerm term, pOFP_Traverse DeclarationTypeSpec);

/* R404 */
ATbool ofp_traverse_IntrinsicTypeSpec(ATerm term, OFP::IntrinsicTypeSpec* IntrinsicTypeSpec);
ATbool ofp_traverse_IntrinsicTypeSpec(ATerm term, pOFP_Traverse IntrinsicTypeSpec);

/* R405 */
ATbool ofp_traverse_KindSelector(ATerm term, pOFP_Traverse KindSelector);

/* R406 */
ATbool ofp_traverse_SignedIntLiteralConstant(ATerm term, pOFP_Traverse SignedIntLiteralConstant);

/* R407 */
ATbool ofp_traverse_IntLiteralConstant(ATerm term, pOFP_Traverse IntLiteralConstant);

/* R408 */
ATbool ofp_traverse_KindParam(ATerm term, pOFP_Traverse KindParam);

/* R409 */

/* R410 */
ATbool ofp_traverse_DigitString(ATerm term, pOFP_Traverse DigitString);

/* R411 */
ATbool ofp_traverse_Sign(ATerm term, pOFP_Traverse Sign);

/* R412 */
ATbool ofp_traverse_SignedRealLiteralConstant(ATerm term, pOFP_Traverse SignedRealLiteralConstant);

/* R413 */
ATbool ofp_traverse_RealLiteralConstant(ATerm term, pOFP_Traverse RealLiteralConstant);

/* R417 */
ATbool ofp_traverse_ComplexLiteralConstant(ATerm term, pOFP_Traverse ComplexLiteralConstant);

/* R418 */
ATbool ofp_traverse_RealPart(ATerm term, pOFP_Traverse RealPart);

/* R419 */
ATbool ofp_traverse_ImagPart(ATerm term, pOFP_Traverse ImagPart);

/* R420 */
ATbool ofp_traverse_CharSelector(ATerm term, pOFP_Traverse CharSelector);

/* R421 */
ATbool ofp_traverse_LengthSelector(ATerm term, pOFP_Traverse LengthSelector);

/* R422 */
ATbool ofp_traverse_CharLength(ATerm term, pOFP_Traverse CharLength);

/* R423 */
ATbool ofp_traverse_CharLiteralConstant(ATerm term, pOFP_Traverse CharLiteralConstant);

/* R424 */
ATbool ofp_traverse_LogicalLiteralConstant(ATerm term, pOFP_Traverse LogicalLiteralConstant);

/* R425 */
ATbool ofp_traverse_DerivedTypeDef(ATerm term, pOFP_Traverse DerivedTypeDef);

/* R426 */
ATbool ofp_traverse_DerivedTypeStmt(ATerm term, pOFP_Traverse DerivedTypeStmt);
ATbool ofp_traverse_OptTypeAttrSpecList(ATerm term, pOFP_Traverse OptTypeAttrSpecList);
ATbool ofp_traverse_OptTypeParamNameList(ATerm term, pOFP_Traverse OptTypeParamNameList);

/* R427 */
ATbool ofp_traverse_TypeAttrSpec(ATerm term, pOFP_Traverse TypeAttrSpec);
ATbool ofp_traverse_TypeAttrSpecList(ATerm term, pOFP_Traverse TypeAttrSpecList);
ATbool ofp_traverse_TypeParamNameList(ATerm term, pOFP_Traverse TypeParamNameList);

/* R428 */
ATbool ofp_traverse_PrivateOrSequence(ATerm term, pOFP_Traverse PrivateOrSequence);

/* R429 */
ATbool ofp_traverse_EndTypeStmt(ATerm term, pOFP_Traverse EndTypeStmt);

/* R430 */
ATbool ofp_traverse_SequenceStmt(ATerm term, pOFP_Traverse SequenceStmt);

/* R431 */
ATbool ofp_traverse_TypeParamDefStmt(ATerm term, pOFP_Traverse TypeParamDefStmt);

/* R432 */
ATbool ofp_traverse_TypeParamDecl(ATerm term, pOFP_Traverse TypeParamDecl);
ATbool ofp_traverse_TypeParamDeclList(ATerm term, pOFP_Traverse TypeParamDeclList);

/* R433 */
ATbool ofp_traverse_TypeParamAttrSpec(ATerm term, pOFP_Traverse TypeParamAttrSpec);

/* R434 */
ATbool ofp_traverse_ComponentPart(ATerm term, pOFP_Traverse ComponentPart);

/* R435 */
ATbool ofp_traverse_ComponentDefStmt(ATerm term, pOFP_Traverse ComponentDefStmt);

/* R436 */
ATbool ofp_traverse_DataComponentDefStmt(ATerm term, pOFP_Traverse DataComponentDefStmt);
ATbool ofp_traverse_OptComponentAttrSpecList(ATerm term, pOFP_Traverse OptComponentAttrSpecList);

/* R437 */
ATbool ofp_traverse_ComponentAttrSpec(ATerm term, pOFP_Traverse ComponentAttrSpec);
ATbool ofp_traverse_ComponentAttrSpecList(ATerm term, pOFP_Traverse ComponentAttrSpecList);

/* R438 */
ATbool ofp_traverse_ComponentDecl(ATerm term, pOFP_Traverse ComponentDecl);
ATbool ofp_traverse_ComponentDeclList(ATerm term, pOFP_Traverse ComponentDeclList);

/* R439 */
ATbool ofp_traverse_ComponentArraySpec(ATerm term, pOFP_Traverse ComponentArraySpec);

/* R440 */
ATbool ofp_traverse_ProcComponentDefStmt(ATerm term, pOFP_Traverse ProcComponentDefStmt);

/* R441 */
ATbool ofp_traverse_ProcComponentAttrSpec(ATerm term, pOFP_Traverse ProcComponentAttrSpec);
ATbool ofp_traverse_ProcComponentAttrSpecList(ATerm term, pOFP_Traverse ProcComponentAttrSpecList);

/* R442 */
ATbool ofp_traverse_ComponentInitialization(ATerm term, pOFP_Traverse ComponentInitialization);

/* R443 */
ATbool ofp_traverse_InitialDataTarget(ATerm term, pOFP_Traverse InitialDataTarget);

/* R444 */
ATbool ofp_traverse_PrivateComponentsStmt(ATerm term, pOFP_Traverse PrivateComponentsStmt);

/* R445 */
ATbool ofp_traverse_TypeBoundProcedurePart(ATerm term, pOFP_Traverse TypeBoundProcedurePart);

/* R446 */
ATbool ofp_traverse_BindingPrivateStmt(ATerm term, pOFP_Traverse BindingPrivateStmt);

/* R447 */
ATbool ofp_traverse_TypeBoundProcBinding(ATerm term, pOFP_Traverse TypeBoundProcBinding);

/* R448 */
ATbool ofp_traverse_TypeBoundProcedureStmt(ATerm term, pOFP_Traverse TypeBoundProcedureStmt);
ATbool ofp_traverse_BindingNameList(ATerm term, pOFP_Traverse BindingNameList);
ATbool ofp_traverse_BindingAttrList(ATerm term, pOFP_Traverse BindingAttrList);

/* R449 */
ATbool ofp_traverse_TypeBoundProcDecl(ATerm term, pOFP_Traverse TypeBoundProcDecl);
ATbool ofp_traverse_TypeBoundProcDeclList(ATerm term, pOFP_Traverse TypeBoundProcDeclList);

/* R450 */
ATbool ofp_traverse_TypeBoundGenericStmt(ATerm term, pOFP_Traverse TypeBoundGenericStmt);

/* R451 */
ATbool ofp_traverse_BindingAttr(ATerm term, pOFP_Traverse BindingAttr);

/* R452 */
ATbool ofp_traverse_FinalProcedureStmt(ATerm term, pOFP_Traverse FinalProcedureStmt);
ATbool ofp_traverse_FinalSubroutineNameList(ATerm term, pOFP_Traverse FinalSubroutineNameList);

/* R453 */
ATbool ofp_traverse_DerivedTypeSpec(ATerm term, pOFP_Traverse DerivedTypeSpec);

/* R454 */
ATbool ofp_traverse_TypeParamSpec(ATerm term, pOFP_Traverse TypeParamSpec);
ATbool ofp_traverse_TypeParamSpecList(ATerm term, pOFP_Traverse TypeParamSpecList);

/* R455 */
ATbool ofp_traverse_StructureConstructor(ATerm term, pOFP_Traverse StructureConstructor);

/* R456 */
ATbool ofp_traverse_ComponentSpec(ATerm term, pOFP_Traverse ComponentSpec);

/* R457 */
ATbool ofp_traverse_ComponentDataSource(ATerm term, pOFP_Traverse ComponentDataSource);

/* R458 */
ATbool ofp_traverse_EnumDef(ATerm term, pOFP_Traverse EnumDef);

/* R459 */
ATbool ofp_traverse_EnumDefStmt(ATerm term, pOFP_Traverse EnumDefStmt);

/* R460 */
ATbool ofp_traverse_EnumeratorDefStmt(ATerm term, pOFP_Traverse EnumeratorDefStmt);

/* R461 */
ATbool ofp_traverse_Enumerator(ATerm term, pOFP_Traverse Enumerator);
ATbool ofp_traverse_EnumeratorList(ATerm term, pOFP_Traverse EnumeratorList);

/* R462 */
ATbool ofp_traverse_EndEnumStmt(ATerm term, pOFP_Traverse EndEnumStmt);

/* R463 */
ATbool ofp_traverse_BozLiteralConstant(ATerm term, pOFP_Traverse BozLiteralConstant);

/* R464 */
/* R465 */
/* R466 */
/* R467 */

/* R468 */
ATbool ofp_traverse_ArrayConstructor(ATerm term, pOFP_Traverse ArrayConstructor);

/* R469 */
ATbool ofp_traverse_AcSpec(ATerm term, pOFP_Traverse AcSpec);

/* R470 */
ATbool ofp_traverse_AcValue(ATerm term, pOFP_Traverse AcValue);

/* R471 */
ATbool ofp_traverse_AcValueList(ATerm term, pOFP_Traverse AcValueList);

/* R472 */
ATbool ofp_traverse_AcImpliedDo(ATerm term, pOFP_Traverse AcImpliedDo);

/* R473 */
ATbool ofp_traverse_AcImpliedDoControl(ATerm term, pOFP_Traverse AcImpliedDoControl);

/* R474 */
ATbool ofp_traverse_AcDoVariable(ATerm term, pOFP_Traverse AcDoVariable);

/* R501 */
ATbool ofp_traverse_TypeDeclarationStmt(ATerm term, OFP::TypeDeclarationStmt* TypeDeclarationStmt);
ATbool ofp_traverse_TypeDeclarationStmt(ATerm term, pOFP_Traverse TypeDeclarationStmt);

/* R502 */
ATbool ofp_traverse_AttrSpec(ATerm term, pOFP_Traverse AttrSpec);
ATbool ofp_traverse_AttrSpecList(ATerm term, OFP::AttrSpecList* AttrSpecList);
ATbool ofp_traverse_AttrSpecList(ATerm term, pOFP_Traverse AttrSpecList);
ATbool ofp_traverse_OptAttrSpecList(ATerm term, OFP::OptAttrSpecList* OptAttrSpecList);
ATbool ofp_traverse_OptAttrSpecList(ATerm term, pOFP_Traverse OptAttrSpecList);

/* R503 */
ATbool ofp_traverse_EntityDecl(ATerm term, OFP::EntityDecl* EntityDecl);
ATbool ofp_traverse_EntityDecl(ATerm term, pOFP_Traverse EntityDecl);
ATbool ofp_traverse_EntityDeclList(ATerm term, OFP::EntityDeclList* EntityDeclList);
ATbool ofp_traverse_EntityDeclList(ATerm term, pOFP_Traverse EntityDeclList);
ATbool ofp_traverse_Initialization(ATerm term, pOFP_Traverse Initialization);
ATbool ofp_traverse_NullInit(ATerm term, pOFP_Traverse NullInit);
ATbool ofp_traverse_AccessSpec(ATerm term, pOFP_Traverse AccessSpec);
ATbool ofp_traverse_LanguageBindingSpec(ATerm term, pOFP_Traverse LanguageBindingSpec);
ATbool ofp_traverse_CoarraySpec(ATerm term, pOFP_Traverse CoarraySpec);
ATbool ofp_traverse_DeferredCoshapeSpec(ATerm term, pOFP_Traverse DeferredCoshapeSpec);
ATbool ofp_traverse_DeferredCoshapeSpecList(ATerm term, pOFP_Traverse DeferredCoshapeSpecList);
ATbool ofp_traverse_ExplicitCoshapeSpec(ATerm term, pOFP_Traverse ExplicitCoshapeSpec);
ATbool ofp_traverse_CoboundsEntry(ATerm term, pOFP_Traverse CoboundsEntry);
ATbool ofp_traverse_LowerCobound(ATerm term, pOFP_Traverse LowerCobound);
ATbool ofp_traverse_UpperCobound(ATerm term, pOFP_Traverse UpperCobound);
ATbool ofp_traverse_ArraySpec(ATerm term, pOFP_Traverse ArraySpec);
ATbool ofp_traverse_ExplicitShapeSpec(ATerm term, pOFP_Traverse ExplicitShapeSpec);
ATbool ofp_traverse_ExplicitShapeSpecList(ATerm term, pOFP_Traverse ExplicitShapeSpecList);
ATbool ofp_traverse_LowerBound(ATerm term, pOFP_Traverse LowerBound);
ATbool ofp_traverse_UpperBound(ATerm term, pOFP_Traverse UpperBound);
ATbool ofp_traverse_AssumedShapeSpec(ATerm term, pOFP_Traverse AssumedShapeSpec);
ATbool ofp_traverse_AssumedShapeSpecList(ATerm term, pOFP_Traverse AssumedShapeSpecList);
ATbool ofp_traverse_DeferredShapeSpec(ATerm term, pOFP_Traverse DeferredShapeSpec);
ATbool ofp_traverse_DeferredShapeSpecList(ATerm term, pOFP_Traverse DeferredShapeSpecList);
ATbool ofp_traverse_AssumedSizeSpec(ATerm term, pOFP_Traverse AssumedSizeSpec);
ATbool ofp_traverse_AssumedRankSpec(ATerm term, pOFP_Traverse AssumedRankSpec);
ATbool ofp_traverse_ImpliedShapeSpec(ATerm term, pOFP_Traverse ImpliedShapeSpec);
ATbool ofp_traverse_ImpliedShapeSpecList(ATerm term, pOFP_Traverse ImpliedShapeSpecList);
ATbool ofp_traverse_IntentSpec(ATerm term, pOFP_Traverse IntentSpec);
ATbool ofp_traverse_AccessStmt(ATerm term, pOFP_Traverse AccessStmt);
ATbool ofp_traverse_AccessId(ATerm term, pOFP_Traverse AccessId);
ATbool ofp_traverse_AccessIdList(ATerm term, pOFP_Traverse AccessIdList);
ATbool ofp_traverse_AllocatableStmt(ATerm term, pOFP_Traverse AllocatableStmt);
ATbool ofp_traverse_AllocatableDecl(ATerm term, pOFP_Traverse AllocatableDecl);
ATbool ofp_traverse_AllocatableDeclList(ATerm term, pOFP_Traverse AllocatableDeclList);
ATbool ofp_traverse_AsynchronousStmt(ATerm term, pOFP_Traverse AsynchronousStmt);
ATbool ofp_traverse_BindStmt(ATerm term, pOFP_Traverse BindStmt);
ATbool ofp_traverse_BindEntity(ATerm term, pOFP_Traverse BindEntity);
ATbool ofp_traverse_BindEntityList(ATerm term, pOFP_Traverse BindEntityList);
ATbool ofp_traverse_CodimensionStmt(ATerm term, pOFP_Traverse CodimensionStmt);
ATbool ofp_traverse_CodimensionDecl(ATerm term, pOFP_Traverse CodimensionDecl);
ATbool ofp_traverse_CodimensionDeclList(ATerm term, pOFP_Traverse CodimensionDeclList);
ATbool ofp_traverse_ContiguousStmt(ATerm term, pOFP_Traverse ContiguousStmt);
ATbool ofp_traverse_ObjectNameList(ATerm term, pOFP_Traverse ObjectNameList);
ATbool ofp_traverse_DataStmt(ATerm term, pOFP_Traverse DataStmt);
ATbool ofp_traverse_DataStmtSet(ATerm term, pOFP_Traverse DataStmtSet);
ATbool ofp_traverse_DataStmtSetList(ATerm term, pOFP_Traverse DataStmtSetList);
ATbool ofp_traverse_DataStmtObject(ATerm term, pOFP_Traverse DataStmtObject);
ATbool ofp_traverse_DataStmtObjectList(ATerm term, pOFP_Traverse DataStmtObjectList);
ATbool ofp_traverse_DataImpliedDo(ATerm term, pOFP_Traverse DataImpliedDo);
ATbool ofp_traverse_DataIDoObject(ATerm term, pOFP_Traverse DataIDoObject);
ATbool ofp_traverse_DataIDoObjectList(ATerm term, pOFP_Traverse DataIDoObjectList);
ATbool ofp_traverse_DataIDoVariable(ATerm term, pOFP_Traverse DataIDoVariable);
ATbool ofp_traverse_DataStmtValue(ATerm term, pOFP_Traverse DataStmtValue);
ATbool ofp_traverse_DataStmtValueList(ATerm term, pOFP_Traverse DataStmtValueList);
ATbool ofp_traverse_DataStmtRepeat(ATerm term, pOFP_Traverse DataStmtRepeat);
ATbool ofp_traverse_DataStmtConstant(ATerm term, pOFP_Traverse DataStmtConstant);
ATbool ofp_traverse_IntConstantSubobject(ATerm term, pOFP_Traverse IntConstantSubobject);
ATbool ofp_traverse_ConstantSubobject(ATerm term, pOFP_Traverse ConstantSubobject);
ATbool ofp_traverse_DimensionStmt(ATerm term, pOFP_Traverse DimensionStmt);
ATbool ofp_traverse_ArrayNameSpec(ATerm term, pOFP_Traverse ArrayNameSpec);
ATbool ofp_traverse_ArrayNameSpecList(ATerm term, pOFP_Traverse ArrayNameSpecList);
ATbool ofp_traverse_IntentStmt(ATerm term, pOFP_Traverse IntentStmt);
ATbool ofp_traverse_DummyArgNameList(ATerm term, pOFP_Traverse DummyArgNameList);
ATbool ofp_traverse_OptionalStmt(ATerm term, pOFP_Traverse OptionalStmt);
ATbool ofp_traverse_ParameterStmt(ATerm term, pOFP_Traverse ParameterStmt);
ATbool ofp_traverse_NamedConstantDef(ATerm term, pOFP_Traverse NamedConstantDef);
ATbool ofp_traverse_NamedConstantDefList(ATerm term, pOFP_Traverse NamedConstantDefList);
ATbool ofp_traverse_PointerStmt(ATerm term, pOFP_Traverse PointerStmt);
ATbool ofp_traverse_PointerDecl(ATerm term, pOFP_Traverse PointerDecl);
ATbool ofp_traverse_PointerDeclList(ATerm term, pOFP_Traverse PointerDeclList);
ATbool ofp_traverse_ProtectedStmt(ATerm term, pOFP_Traverse ProtectedStmt);
ATbool ofp_traverse_EntityNameList(ATerm term, pOFP_Traverse EntityNameList);
ATbool ofp_traverse_SaveStmt(ATerm term, pOFP_Traverse SaveStmt);
ATbool ofp_traverse_SavedEntity(ATerm term, pOFP_Traverse SavedEntity);
ATbool ofp_traverse_SavedEntityList(ATerm term, pOFP_Traverse SavedEntityList);
ATbool ofp_traverse_ProcPointerName(ATerm term, pOFP_Traverse ProcPointerName);
ATbool ofp_traverse_TargetStmt(ATerm term, pOFP_Traverse TargetStmt);
ATbool ofp_traverse_TargetDecl(ATerm term, pOFP_Traverse TargetDecl);
ATbool ofp_traverse_TargetDeclList(ATerm term, pOFP_Traverse TargetDeclList);
ATbool ofp_traverse_ValueStmt(ATerm term, pOFP_Traverse ValueStmt);
ATbool ofp_traverse_VolatileStmt(ATerm term, pOFP_Traverse VolatileStmt);
ATbool ofp_traverse_ImplicitStmt(ATerm term, OFP::ImplicitStmt * ImplicitStmt);
ATbool ofp_traverse_ImplicitStmt(ATerm term, pOFP_Traverse ImplicitStmt);
ATbool ofp_traverse_ImplicitSpec(ATerm term, pOFP_Traverse ImplicitSpec);
ATbool ofp_traverse_ImplicitSpecList(ATerm term, pOFP_Traverse ImplicitSpecList);
ATbool ofp_traverse_LetterSpec(ATerm term, pOFP_Traverse LetterSpec);
ATbool ofp_traverse_LetterSpecList(ATerm term, pOFP_Traverse LetterSpecList);
ATbool ofp_traverse_NamelistStmt(ATerm term, pOFP_Traverse NamelistStmt);
ATbool ofp_traverse_NamelistEntry(ATerm term, pOFP_Traverse NamelistEntry);
ATbool ofp_traverse_NamelistEntryList(ATerm term, pOFP_Traverse NamelistEntryList);
ATbool ofp_traverse_NamelistGroupObject(ATerm term, pOFP_Traverse NamelistGroupObject);
ATbool ofp_traverse_NamelistGroupObjectList(ATerm term, pOFP_Traverse NamelistGroupObjectList);
ATbool ofp_traverse_EquivalenceStmt(ATerm term, pOFP_Traverse EquivalenceStmt);
ATbool ofp_traverse_EquivalenceSet(ATerm term, pOFP_Traverse EquivalenceSet);
ATbool ofp_traverse_EquivalenceSetList(ATerm term, pOFP_Traverse EquivalenceSetList);
ATbool ofp_traverse_EquivalenceObject(ATerm term, pOFP_Traverse EquivalenceObject);
ATbool ofp_traverse_EquivalenceObjectList(ATerm term, pOFP_Traverse EquivalenceObjectList);
ATbool ofp_traverse_CommonStmt(ATerm term, pOFP_Traverse CommonStmt);
ATbool ofp_traverse_CommonBlockEntry1(ATerm term, pOFP_Traverse CommonBlockEntry1);
ATbool ofp_traverse_CommonBlockEntry(ATerm term, pOFP_Traverse CommonBlockEntry);
ATbool ofp_traverse_CommonBlockObject(ATerm term, pOFP_Traverse CommonBlockObject);
ATbool ofp_traverse_CommonBlockObjectList(ATerm term, pOFP_Traverse CommonBlockObjectList);

/* R601 */
ATbool ofp_traverse_Designator(ATerm term, pOFP_Traverse Designator);

/* R602 */
ATbool ofp_traverse_Variable(ATerm term, pOFP_Traverse Variable);
ATbool ofp_traverse_Variable(ATerm term, OFP::Variable * Variable);

/* R603 */
ATbool ofp_traverse_VariableName(ATerm term, pOFP_Traverse VariableName);

/* R604 */
ATbool ofp_traverse_LogicalVariable(ATerm term, pOFP_Traverse LogicalVariable);

/* R605 */
ATbool ofp_traverse_CharVariable(ATerm term, pOFP_Traverse CharVariable);

/* R606 */
ATbool ofp_traverse_DefaultCharVariable(ATerm term, pOFP_Traverse DefaultCharVariable);

/* R607 */
ATbool ofp_traverse_IntVariable(ATerm term, pOFP_Traverse IntVariable);

/* R608 */
ATbool ofp_traverse_Substring(ATerm term, pOFP_Traverse Substring);

/* R609 */
ATbool ofp_traverse_ParentString(ATerm term, pOFP_Traverse ParentString);

/* R610 */
ATbool ofp_traverse_SubstringRange(ATerm term, pOFP_Traverse SubstringRange);

/* R611 */
ATbool ofp_traverse_DataRef(ATerm term, pOFP_Traverse DataRef);

/* R612 */
ATbool ofp_traverse_PartRef(ATerm term, pOFP_Traverse PartRef);

/* R613 */
ATbool ofp_traverse_StructureComponent(ATerm term, pOFP_Traverse StructureComponent);

/* R614 */
ATbool ofp_traverse_CoindexedNamedObject(ATerm term, pOFP_Traverse CoindexedNamedObject);

/* R615 ComplexPartDesignator */

/* R616 */
ATbool ofp_traverse_TypeParamInquiry(ATerm term, pOFP_Traverse TypeParamInquiry);

ATbool ofp_traverse_ArrayElement(ATerm term, pOFP_Traverse ArrayElement);
ATbool ofp_traverse_Subscript(ATerm term, pOFP_Traverse Subscript);
ATbool ofp_traverse_SectionSubscript(ATerm term, pOFP_Traverse SectionSubscript);
ATbool ofp_traverse_SectionSubscriptList(ATerm term, pOFP_Traverse SectionSubscriptList);
ATbool ofp_traverse_SubscriptTriplet(ATerm term, pOFP_Traverse SubscriptTriplet);
ATbool ofp_traverse_Stride(ATerm term, pOFP_Traverse Stride);
ATbool ofp_traverse_ImageSelector(ATerm term, pOFP_Traverse ImageSelector);
ATbool ofp_traverse_Cosubscript(ATerm term, pOFP_Traverse Cosubscript);
ATbool ofp_traverse_CosubscriptList(ATerm term, pOFP_Traverse CosubscriptList);
ATbool ofp_traverse_AllocateStmt(ATerm term, pOFP_Traverse AllocateStmt);
ATbool ofp_traverse_AllocOpt(ATerm term, pOFP_Traverse AllocOpt);
ATbool ofp_traverse_AllocOptList(ATerm term, pOFP_Traverse AllocOptList);
ATbool ofp_traverse_StatVariable(ATerm term, pOFP_Traverse StatVariable);
ATbool ofp_traverse_ErrmsgVariable(ATerm term, pOFP_Traverse ErrmsgVariable);
ATbool ofp_traverse_Allocation(ATerm term, pOFP_Traverse Allocation);
ATbool ofp_traverse_AllocationList(ATerm term, pOFP_Traverse AllocationList);
ATbool ofp_traverse_AllocateObject(ATerm term, pOFP_Traverse AllocateObject);
ATbool ofp_traverse_AllocateObjectList(ATerm term, pOFP_Traverse AllocateObjectList);
ATbool ofp_traverse_AllocateShapeSpec(ATerm term, pOFP_Traverse AllocateShapeSpec);
ATbool ofp_traverse_AllocateShapeSpecList(ATerm term, pOFP_Traverse AllocateShapeSpecList);
ATbool ofp_traverse_LowerBoundExpr(ATerm term, pOFP_Traverse LowerBoundExpr);
ATbool ofp_traverse_UpperBoundExpr(ATerm term, pOFP_Traverse UpperBoundExpr);
ATbool ofp_traverse_AllocateCoarraySpec(ATerm term, pOFP_Traverse AllocateCoarraySpec);
ATbool ofp_traverse_AllocateCoshapeSpec(ATerm term, pOFP_Traverse AllocateCoshapeSpec);
ATbool ofp_traverse_AllocateCoshapeSpecList(ATerm term, pOFP_Traverse AllocateCoshapeSpecList);
ATbool ofp_traverse_NullifyStmt(ATerm term, pOFP_Traverse NullifyStmt);
ATbool ofp_traverse_PointerObject(ATerm term, pOFP_Traverse PointerObject);
ATbool ofp_traverse_PointerObjectList(ATerm term, pOFP_Traverse PointerObjectList);
ATbool ofp_traverse_DeallocateStmt(ATerm term, pOFP_Traverse DeallocateStmt);
ATbool ofp_traverse_DeallocOpt(ATerm term, pOFP_Traverse DeallocOpt);
ATbool ofp_traverse_DeallocOptList(ATerm term, pOFP_Traverse DeallocOptList);

ATbool ofp_traverse_IntrinsicOperator(ATerm term, pOFP_Traverse IntrinsicOperator);
ATbool ofp_traverse_DefinedOperator(ATerm term, pOFP_Traverse DefinedOperator);
ATbool ofp_traverse_ExtendedIntrinsicOp(ATerm term, pOFP_Traverse ExtendedIntrinsicOp);
ATbool ofp_traverse_Primary(ATerm term, pOFP_Traverse Primary);
ATbool ofp_traverse_DefinedUnaryOp(ATerm term, pOFP_Traverse DefinedUnaryOp);

/* R722 */
ATbool ofp_traverse_Expr(ATerm term, pOFP_Traverse Expr);
ATbool ofp_traverse_Expr(ATerm term, OFP::Expr * Expr);

ATbool ofp_traverse_DefinedBinaryOp(ATerm term, pOFP_Traverse DefinedBinaryOp);
ATbool ofp_traverse_LogicalExpr(ATerm term, pOFP_Traverse LogicalExpr);
ATbool ofp_traverse_DefaultCharExpr(ATerm term, pOFP_Traverse DefaultCharExpr);
ATbool ofp_traverse_IntExpr(ATerm term, pOFP_Traverse IntExpr);
ATbool ofp_traverse_SpecificationExpr(ATerm term, pOFP_Traverse SpecificationExpr);
ATbool ofp_traverse_ConstantExpr(ATerm term, pOFP_Traverse ConstantExpr);
ATbool ofp_traverse_IntConstantExpr(ATerm term, pOFP_Traverse IntConstantExpr);

/* R732 */
ATbool ofp_traverse_AssignmentStmt(ATerm term, pOFP_Traverse AssignmentStmt);

ATbool ofp_traverse_PointerAssignmentStmt(ATerm term, pOFP_Traverse PointerAssignmentStmt);
ATbool ofp_traverse_DataPointerObject(ATerm term, pOFP_Traverse DataPointerObject);
ATbool ofp_traverse_BoundsSpec(ATerm term, pOFP_Traverse BoundsSpec);
ATbool ofp_traverse_BoundsSpecList(ATerm term, pOFP_Traverse BoundsSpecList);
ATbool ofp_traverse_BoundsRemapping(ATerm term, pOFP_Traverse BoundsRemapping);
ATbool ofp_traverse_BoundsRemappingList(ATerm term, pOFP_Traverse BoundsRemappingList);
ATbool ofp_traverse_DataTarget(ATerm term, pOFP_Traverse DataTarget);
ATbool ofp_traverse_ProcPointerObject(ATerm term, pOFP_Traverse ProcPointerObject);
ATbool ofp_traverse_ProcComponentRef(ATerm term, pOFP_Traverse ProcComponentRef);
ATbool ofp_traverse_ProcTarget(ATerm term, pOFP_Traverse ProcTarget);
ATbool ofp_traverse_WhereStmt(ATerm term, pOFP_Traverse WhereStmt);

/* R742 */
ATbool ofp_traverse_WhereConstruct(ATerm term, pOFP_Traverse WhereConstruct);
ATbool ofp_traverse_MaskedElsewhereClause(ATerm term, pOFP_Traverse MaskedElsewhereClause);
ATbool ofp_traverse_ElsewhereClause(ATerm term, pOFP_Traverse ElsewhereClause);

ATbool ofp_traverse_WhereConstructStmt(ATerm term, pOFP_Traverse WhereConstructStmt);
ATbool ofp_traverse_WhereBodyConstruct(ATerm term, pOFP_Traverse WhereBodyConstruct);
ATbool ofp_traverse_WhereAssignmentStmt(ATerm term, pOFP_Traverse WhereAssignmentStmt);
ATbool ofp_traverse_MaskExpr(ATerm term, pOFP_Traverse MaskExpr);
ATbool ofp_traverse_MaskedElsewhereStmt(ATerm term, pOFP_Traverse MaskedElsewhereStmt);
ATbool ofp_traverse_ElsewhereStmt(ATerm term, pOFP_Traverse ElsewhereStmt);
ATbool ofp_traverse_EndWhereStmt(ATerm term, pOFP_Traverse EndWhereStmt);
ATbool ofp_traverse_ForallConstruct(ATerm term, pOFP_Traverse ForallConstruct);
ATbool ofp_traverse_ForallConstructStmt(ATerm term, pOFP_Traverse ForallConstructStmt);
ATbool ofp_traverse_ForallHeader(ATerm term, pOFP_Traverse ForallHeader);
ATbool ofp_traverse_ForallTripletSpec(ATerm term, pOFP_Traverse ForallTripletSpec);
ATbool ofp_traverse_ForallTripletSpecList(ATerm term, pOFP_Traverse ForallTripletSpecList);
ATbool ofp_traverse_ForallLimit(ATerm term, pOFP_Traverse ForallLimit);
ATbool ofp_traverse_ForallStep(ATerm term, pOFP_Traverse ForallStep);
ATbool ofp_traverse_ForallBodyConstruct(ATerm term, pOFP_Traverse ForallBodyConstruct);
ATbool ofp_traverse_ForallAssignmentStmt(ATerm term, pOFP_Traverse ForallAssignmentStmt);
ATbool ofp_traverse_EndForallStmt(ATerm term, pOFP_Traverse EndForallStmt);
ATbool ofp_traverse_ForallStmt(ATerm term, pOFP_Traverse ForallStmt);

/* R801 */
ATbool ofp_traverse_Block(ATerm term, pOFP_Traverse Block);

/* R802 */
ATbool ofp_traverse_AssociateConstruct(ATerm term, pOFP_Traverse AssociateConstruct);

/* R803 */
ATbool ofp_traverse_AssociateStmt(ATerm term, pOFP_Traverse AssociateStmt);

/* R804 */
ATbool ofp_traverse_Association(ATerm term, pOFP_Traverse Association);
ATbool ofp_traverse_AssociationList(ATerm term, pOFP_Traverse AssociationList);

/* R805 */
ATbool ofp_traverse_Selector(ATerm term, pOFP_Traverse Selector);

/* R806 */
ATbool ofp_traverse_EndAssociateStmt(ATerm term, pOFP_Traverse EndAssociateStmt);

/* R807 */
ATbool ofp_traverse_BlockConstruct(ATerm term, pOFP_Traverse BlockConstruct);

/* R808 */
ATbool ofp_traverse_BlockStmt(ATerm term, pOFP_Traverse BlockStmt);

/* R809 */
ATbool ofp_traverse_EndBlockStmt(ATerm term, pOFP_Traverse EndBlockStmt);

/* R810 */
ATbool ofp_traverse_CriticalConstruct(ATerm term, pOFP_Traverse CriticalConstruct);

/* R811 */
ATbool ofp_traverse_CriticalStmt(ATerm term, pOFP_Traverse CriticalStmt);

/* R812 */
ATbool ofp_traverse_EndCriticalStmt(ATerm term, pOFP_Traverse EndCriticalStmt);

/* R813 */
/* R814 */
/* R815 */

/* R816 */
ATbool ofp_traverse_LabelDoStmt(ATerm term, pOFP_Traverse LabelDoStmt);

/* R817 */
ATbool ofp_traverse_NonlabelDoStmt(ATerm term, pOFP_Traverse NonlabelDoStmt);

/* R818 */
ATbool ofp_traverse_LoopControl(ATerm term, pOFP_Traverse LoopControl);

/* R819 */
ATbool ofp_traverse_DoVariable(ATerm term, pOFP_Traverse DoVariable);

/* R820 */
/* R821 */

/* R822 */
ATbool ofp_traverse_EndDoStmt(ATerm term, pOFP_Traverse EndDoStmt);

/* R823 */
/* R824 */
/* R825 */
/* R826 */
/* R827 */
/* R828 */
/* R829 */
/* R830 */

/* R831 */
ATbool ofp_traverse_CycleStmt(ATerm term, pOFP_Traverse CycleStmt);

/* R832 */
ATbool ofp_traverse_IfConstruct(ATerm term, pOFP_Traverse IfConstruct);
ATbool ofp_traverse_ElseIfStmtAndBlock(ATerm term, pOFP_Traverse ElseIfStmtAndBlock);
ATbool ofp_traverse_ElseStmtAndBlock(ATerm term, pOFP_Traverse ElseStmtAndBlock);

/* R833 */
ATbool ofp_traverse_IfThenStmt(ATerm term, pOFP_Traverse IfThenStmt);

/* R834 */
ATbool ofp_traverse_ElseIfStmt(ATerm term, pOFP_Traverse ElseIfStmt);

/* R835 */
ATbool ofp_traverse_ElseStmt(ATerm term, pOFP_Traverse ElseStmt);

/* R836 */
ATbool ofp_traverse_EndIfStmt(ATerm term, pOFP_Traverse EndIfStmt);

/* R837 */
ATbool ofp_traverse_IfStmt(ATerm term, pOFP_Traverse IfStmt);

/* R838 */
ATbool ofp_traverse_CaseConstruct(ATerm term, pOFP_Traverse CaseConstruct);
ATbool ofp_traverse_CaseStmtAndBlock(ATerm term, pOFP_Traverse CaseStmtAndBlock);

/* R839 */
ATbool ofp_traverse_SelectCaseStmt(ATerm term, pOFP_Traverse SelectCaseStmt);

/* R840 */
ATbool ofp_traverse_CaseStmt(ATerm term, pOFP_Traverse CaseStmt);

/* R841 */
ATbool ofp_traverse_EndSelectStmt(ATerm term, pOFP_Traverse EndSelectStmt);

/* R842 */
ATbool ofp_traverse_CaseExpr(ATerm term, pOFP_Traverse CaseExpr);

/* R843 */
ATbool ofp_traverse_CaseSelector(ATerm term, pOFP_Traverse CaseSelector);

/* R844 */
ATbool ofp_traverse_CaseValueRange(ATerm term, pOFP_Traverse CaseValueRange);
ATbool ofp_traverse_CaseValueRangeList(ATerm term, pOFP_Traverse CaseValueRangeList);

/* R845 */
ATbool ofp_traverse_CaseValue(ATerm term, pOFP_Traverse CaseValue);

/* R846 */
ATbool ofp_traverse_SelectTypeConstruct(ATerm term, pOFP_Traverse SelectTypeConstruct);
ATbool ofp_traverse_TypeGuardStmtAndBlock(ATerm term, pOFP_Traverse TypeGuardStmtAndBlock);

/* R847 */
ATbool ofp_traverse_SelectTypeStmt(ATerm term, pOFP_Traverse SelectTypeStmt);

/* R848 */
ATbool ofp_traverse_TypeGuardStmt(ATerm term, pOFP_Traverse TypeGuardStmt);

/* R849 */
ATbool ofp_traverse_EndSelectTypeStmt(ATerm term, pOFP_Traverse EndSelectTypeStmt);

/* R850 */
ATbool ofp_traverse_ExitStmt(ATerm term, pOFP_Traverse ExitStmt);

/* R851 */
ATbool ofp_traverse_GotoStmt(ATerm term, pOFP_Traverse GotoStmt);

/* R852 */
ATbool ofp_traverse_ComputedGotoStmt(ATerm term, pOFP_Traverse ComputedGotoStmt);

/* R853 */
ATbool ofp_traverse_ArithmeticIfStmt(ATerm term, pOFP_Traverse ArithmeticIfStmt);

/* R854 */
ATbool ofp_traverse_ContinueStmt(ATerm term, pOFP_Traverse ContinueStmt);

/* R855 */
ATbool ofp_traverse_StopStmt(ATerm term, pOFP_Traverse StopStmt);

/* R856 */
ATbool ofp_traverse_ErrorStopStmt(ATerm term, pOFP_Traverse ErrorStopStmt);

/* R857 */
ATbool ofp_traverse_StopCode(ATerm term, pOFP_Traverse StopCode);

/* R858 */
ATbool ofp_traverse_SyncAllStmt(ATerm term, pOFP_Traverse SyncAllStmt);

/* R859 */
ATbool ofp_traverse_SyncStat(ATerm term, pOFP_Traverse SyncStat);
ATbool ofp_traverse_SyncStatList(ATerm term, pOFP_Traverse SyncStatList);

/* R860 */
ATbool ofp_traverse_SyncImagesStmt(ATerm term, pOFP_Traverse SyncImagesStmt);

/* R861 */
ATbool ofp_traverse_ImageSet(ATerm term, pOFP_Traverse ImageSet);

/* R862 */
ATbool ofp_traverse_SyncMemoryStmt(ATerm term, pOFP_Traverse SyncMemoryStmt);

/* R863 */
ATbool ofp_traverse_LockStmt(ATerm term, pOFP_Traverse LockStmt);

/* R864 */
ATbool ofp_traverse_LockStat(ATerm term, pOFP_Traverse LockStat);
ATbool ofp_traverse_LockStatList(ATerm term, pOFP_Traverse LockStatList);

/* R865 */
ATbool ofp_traverse_UnlockStmt(ATerm term, pOFP_Traverse UnlockStmt);

/* R866 */
ATbool ofp_traverse_LockVariable(ATerm term, pOFP_Traverse LockVariable);

/* Obsolete feature */
ATbool ofp_traverse_PauseStmt(ATerm term, pOFP_Traverse PauseStmt);

/* R901 */
ATbool ofp_traverse_IoUnit(ATerm term, pOFP_Traverse IoUnit);

/* R902 */
ATbool ofp_traverse_FileUnitNumber(ATerm term, pOFP_Traverse FileUnitNumber);

/* R904 */
ATbool ofp_traverse_OpenStmt(ATerm term, pOFP_Traverse OpenStmt);

/* R905 */
ATbool ofp_traverse_ConnectSpec(ATerm term, pOFP_Traverse ConnectSpec);
ATbool ofp_traverse_ConnectSpecList(ATerm term, pOFP_Traverse ConnectSpecList);

/* R906 */
ATbool ofp_traverse_FileNameExpr(ATerm term, pOFP_Traverse FileNameExpr);

/* R907 */
ATbool ofp_traverse_IomsgVariable(ATerm term, pOFP_Traverse IomsgVariable);

/* R908 */
ATbool ofp_traverse_CloseStmt(ATerm term, pOFP_Traverse CloseStmt);

/* R909 */
ATbool ofp_traverse_CloseSpec(ATerm term, pOFP_Traverse CloseSpec);
ATbool ofp_traverse_CloseSpecList(ATerm term, pOFP_Traverse CloseSpecList);

/* R910 */
ATbool ofp_traverse_ReadStmt(ATerm term, pOFP_Traverse ReadStmt);

/* R911 */
ATbool ofp_traverse_WriteStmt(ATerm term, pOFP_Traverse WriteStmt);

/* R912 */
ATbool ofp_traverse_PrintStmt(ATerm term, pOFP_Traverse PrintStmt);

/* R913 */
ATbool ofp_traverse_IoControlSpec(ATerm term, pOFP_Traverse IoControlSpec);
ATbool ofp_traverse_IoControlSpecList(ATerm term, pOFP_Traverse IoControlSpecList);

/* R914 */
ATbool ofp_traverse_IdVariable(ATerm term, pOFP_Traverse IdVariable);

/* R915 */
ATbool ofp_traverse_Format(ATerm term, pOFP_Traverse Format);

/* R916 */
ATbool ofp_traverse_InputItem(ATerm term, pOFP_Traverse InputItem);
ATbool ofp_traverse_InputItemList(ATerm term, pOFP_Traverse InputItemList);

/* R917 */
ATbool ofp_traverse_OutputItem(ATerm term, pOFP_Traverse OutputItem);
ATbool ofp_traverse_OutputItemList(ATerm term, pOFP_Traverse OutputItemList);

/* R918 */
ATbool ofp_traverse_IoImpliedDo(ATerm term, pOFP_Traverse IoImpliedDo);

/* R919 */
ATbool ofp_traverse_IoImpliedDoObject(ATerm term, pOFP_Traverse IoImpliedDoObject);
ATbool ofp_traverse_IoImpliedDoObjectList(ATerm term, pOFP_Traverse IoImpliedDoObjectList);

/* R921 */
ATbool ofp_traverse_IoImpliedDoControl(ATerm term, pOFP_Traverse IoImpliedDoControl);

/* R922 */
ATbool ofp_traverse_WaitStmt(ATerm term, pOFP_Traverse WaitStmt);

/* R923 */
ATbool ofp_traverse_WaitSpec(ATerm term, pOFP_Traverse WaitSpec);
ATbool ofp_traverse_WaitSpecList(ATerm term, pOFP_Traverse WaitSpecList);

/* R924 */
ATbool ofp_traverse_BackspaceStmt(ATerm term, pOFP_Traverse BackspaceStmt);

/* R925 */
ATbool ofp_traverse_EndfileStmt(ATerm term, pOFP_Traverse EndfileStmt);

/* R926 */
ATbool ofp_traverse_RewindStmt(ATerm term, pOFP_Traverse RewindStmt);

/* R927 */
ATbool ofp_traverse_PositionSpec(ATerm term, pOFP_Traverse PositionSpec);
ATbool ofp_traverse_PositionSpecList(ATerm term, pOFP_Traverse PositionSpecList);

/* R928 */
ATbool ofp_traverse_FlushStmt(ATerm term, pOFP_Traverse FlushStmt);

/* R929 */
ATbool ofp_traverse_FlushSpec(ATerm term, pOFP_Traverse FlushSpec);
ATbool ofp_traverse_FlushSpecList(ATerm term, pOFP_Traverse FlushSpecList);

/* R930 */
ATbool ofp_traverse_InquireStmt(ATerm term, pOFP_Traverse InquireStmt);

/* R931 */
ATbool ofp_traverse_InquireSpec(ATerm term, pOFP_Traverse InquireSpec);
ATbool ofp_traverse_InquireSpecList(ATerm term, pOFP_Traverse InquireSpecList);

ATbool ofp_traverse_FormatStmt(ATerm term, pOFP_Traverse FormatStmt);
ATbool ofp_traverse_FormatSpecification(ATerm term, pOFP_Traverse FormatSpecification);
ATbool ofp_traverse_FormatItems(ATerm term, pOFP_Traverse FormatItems);
ATbool ofp_traverse_FormatItem(ATerm term, pOFP_Traverse FormatItem);
ATbool ofp_traverse_UnlimitedFormatItem(ATerm term, pOFP_Traverse UnlimitedFormatItem);
ATbool ofp_traverse_REditDesc(ATerm term, pOFP_Traverse REditDesc);
ATbool ofp_traverse_DataEditDesc(ATerm term, pOFP_Traverse DataEditDesc);
ATbool ofp_traverse_WEditDesc(ATerm term, pOFP_Traverse WEditDesc);
ATbool ofp_traverse_MEditDesc(ATerm term, pOFP_Traverse MEditDesc);
ATbool ofp_traverse_DEditDesc(ATerm term, pOFP_Traverse DEditDesc);
ATbool ofp_traverse_EEditDesc(ATerm term, pOFP_Traverse EEditDesc);
ATbool ofp_traverse_VEditDesc(ATerm term, pOFP_Traverse VEditDesc);
ATbool ofp_traverse_VEditDescList(ATerm term, pOFP_Traverse VEditDescList);
ATbool ofp_traverse_ControlEditDesc(ATerm term, pOFP_Traverse ControlEditDesc);
ATbool ofp_traverse_KEditDesc(ATerm term, pOFP_Traverse KEditDesc);
ATbool ofp_traverse_PositionEditDesc(ATerm term, pOFP_Traverse PositionEditDesc);
ATbool ofp_traverse_NEditDesc(ATerm term, pOFP_Traverse NEditDesc);
ATbool ofp_traverse_SignEditDesc(ATerm term, pOFP_Traverse SignEditDesc);
ATbool ofp_traverse_BlankInterpEditDesc(ATerm term, pOFP_Traverse BlankInterpEditDesc);
ATbool ofp_traverse_RoundEditDesc(ATerm term, pOFP_Traverse RoundEditDesc);
ATbool ofp_traverse_DecimalEditDesc(ATerm term, pOFP_Traverse DecimalEditDesc);
ATbool ofp_traverse_CharStringEditDesc(ATerm term, pOFP_Traverse CharStringEditDesc);

/* R1101 */
ATbool ofp_traverse_MainProgram(ATerm term, OFP::MainProgram * MainProgram);

/* R1102 */
ATbool ofp_traverse_ProgramStmt(ATerm term, OFP::ProgramStmt * ProgramStmt);
ATbool ofp_traverse_ProgramStmt(ATerm term, pOFP_Traverse ProgramStmt);

/* R1103 */
ATbool ofp_traverse_EndProgramStmt(ATerm term, OFP::EndProgramStmt * EndProgramStmt);
ATbool ofp_traverse_EndProgramStmt(ATerm term, pOFP_Traverse EndProgramStmt);

/* R1104 */
ATbool ofp_traverse_Module(ATerm term, pOFP_Traverse Module);

/* R1105 */
ATbool ofp_traverse_ModuleStmt(ATerm term, pOFP_Traverse ModuleStmt);

/* R1106 */
ATbool ofp_traverse_EndModuleStmt(ATerm term, pOFP_Traverse EndModuleStmt);

/* R1107 */
ATbool ofp_traverse_ModuleSubprogramPart(ATerm term, pOFP_Traverse ModuleSubprogramPart);

/* R1108 */
ATbool ofp_traverse_ModuleSubprogram(ATerm term, pOFP_Traverse ModuleSubprogram);

/* R1109 */
ATbool ofp_traverse_UseStmt(ATerm term, pOFP_Traverse UseStmt);

/* R1110 */
ATbool ofp_traverse_ModuleNature(ATerm term, pOFP_Traverse ModuleNature);

/* R1111 */
ATbool ofp_traverse_Rename(ATerm term, pOFP_Traverse Rename);
ATbool ofp_traverse_RenameList(ATerm term, pOFP_Traverse RenameList);

/* R1112 */
ATbool ofp_traverse_Only(ATerm term, pOFP_Traverse Only);
ATbool ofp_traverse_OnlyList(ATerm term, pOFP_Traverse OnlyList);

/* R1113 */
ATbool ofp_traverse_OnlyUseName(ATerm term, pOFP_Traverse OnlyUseName);

/* R1114 */
ATbool ofp_traverse_LocalDefinedOperator(ATerm term, pOFP_Traverse LocalDefinedOperator);

/* R1115 */
ATbool ofp_traverse_UseDefinedOperator(ATerm term, pOFP_Traverse UseDefinedOperator);

/* R1116 */
ATbool ofp_traverse_Submodule(ATerm term, pOFP_Traverse Submodule);

/* R1117 */
ATbool ofp_traverse_SubmoduleStmt(ATerm term, pOFP_Traverse SubmoduleStmt);

/* R1118 */
ATbool ofp_traverse_ParentIdentifier(ATerm term, pOFP_Traverse ParentIdentifier);

/* R1119 */
ATbool ofp_traverse_EndSubmoduleStmt(ATerm term, pOFP_Traverse EndSubmoduleStmt);

/* R1120 */
ATbool ofp_traverse_BlockData(ATerm term, pOFP_Traverse BlockData);

/* R1121 */
ATbool ofp_traverse_BlockDataStmt(ATerm term, pOFP_Traverse BlockDataStmt);

/* R1122 */
ATbool ofp_traverse_EndBlockDataStmt(ATerm term, pOFP_Traverse EndBlockDataStmt);

/* R1201 */
ATbool ofp_traverse_InterfaceBlock(ATerm term, pOFP_Traverse InterfaceBlock);

/* R1202 */
ATbool ofp_traverse_InterfaceSpecification(ATerm term, pOFP_Traverse InterfaceSpecification);

/* R1203 */
ATbool ofp_traverse_InterfaceStmt(ATerm term, pOFP_Traverse InterfaceStmt);

/* R1204 */
ATbool ofp_traverse_EndInterfaceStmt(ATerm term, pOFP_Traverse EndInterfaceStmt);

/* R1205 */
ATbool ofp_traverse_InterfaceBody(ATerm term, pOFP_Traverse InterfaceBody);

/* R1206 */
ATbool ofp_traverse_ProcedureStmt(ATerm term, pOFP_Traverse ProcedureStmt);
ATbool ofp_traverse_ProcedureNameList(ATerm term, pOFP_Traverse ProcedureNameList);

/* R1207 */
ATbool ofp_traverse_GenericSpec(ATerm term, pOFP_Traverse GenericSpec);

/* R1208 */
ATbool ofp_traverse_DefinedIoGenericSpec(ATerm term, pOFP_Traverse DefinedIoGenericSpec);

/* R1209 */
ATbool ofp_traverse_ImportStmt(ATerm term, pOFP_Traverse ImportStmt);
ATbool ofp_traverse_ImportNameList(ATerm term, pOFP_Traverse ImportNameList);

/* R1210 */
ATbool ofp_traverse_ExternalStmt(ATerm term, pOFP_Traverse ExternalStmt);

/* R1211 */
ATbool ofp_traverse_ProcedureDeclarationStmt(ATerm term, pOFP_Traverse ProcedureDeclarationStmt);

/* R1212 */
ATbool ofp_traverse_ProcInterface(ATerm term, pOFP_Traverse ProcInterface);

/* R1213 */
ATbool ofp_traverse_ProcAttrSpec(ATerm term, pOFP_Traverse ProcAttrSpec);
ATbool ofp_traverse_ProcAttrSpecList(ATerm term, pOFP_Traverse ProcAttrSpecList);

/* R1214 */
ATbool ofp_traverse_ProcDecl(ATerm term, pOFP_Traverse ProcDecl);
ATbool ofp_traverse_ProcDeclList(ATerm term, pOFP_Traverse ProcDeclList);

/* R1215 */
ATbool ofp_traverse_InterfaceName(ATerm term, pOFP_Traverse InterfaceName);

/* R1216 */
ATbool ofp_traverse_ProcPointerInit(ATerm term, pOFP_Traverse ProcPointerInit);

/* R1217 */
ATbool ofp_traverse_InitialProcTarget(ATerm term, pOFP_Traverse InitialProcTarget);

/* R1218 */
ATbool ofp_traverse_IntrinsicStmt(ATerm term, pOFP_Traverse IntrinsicStmt);
ATbool ofp_traverse_IntrinsicProcedureNameList(ATerm term, pOFP_Traverse IntrinsicProcedureNameList);

/* R1219 */
ATbool ofp_traverse_FunctionReference(ATerm term, pOFP_Traverse FunctionReference);

/* R1220 */
ATbool ofp_traverse_CallStmt(ATerm term, pOFP_Traverse CallStmt);

/* R1221 */
ATbool ofp_traverse_ProcedureDesignator(ATerm term, pOFP_Traverse ProcedureDesignator);

/* R1222 */
ATbool ofp_traverse_ActualArgSpec(ATerm term, pOFP_Traverse ActualArgSpec);
ATbool ofp_traverse_ActualArgSpecList(ATerm term, pOFP_Traverse ActualArgSpecList);

/* R1223 */
ATbool ofp_traverse_ActualArg(ATerm term, pOFP_Traverse ActualArg);

/* R1224 */
ATbool ofp_traverse_AltReturnSpec(ATerm term, pOFP_Traverse AltReturnSpec);

/* R1225 */
ATbool ofp_traverse_Prefix(ATerm term, pOFP_Traverse Prefix);

/* R1226 */
ATbool ofp_traverse_PrefixSpec(ATerm term, pOFP_Traverse PrefixSpec);

/* R1227 */
ATbool ofp_traverse_FunctionSubprogram(ATerm term, pOFP_Traverse FunctionSubprogram);

/* R1228 */
ATbool ofp_traverse_FunctionStmt(ATerm term, pOFP_Traverse FunctionStmt);

/* R1229 */
ATbool ofp_traverse_ProcLanguageBindingSpec(ATerm term, pOFP_Traverse ProcLanguageBindingSpec);

/* R1230 */
ATbool ofp_traverse_DummyArgName(ATerm term, pOFP_Traverse DummyArgName);

/* R1231 */
ATbool ofp_traverse_Suffix(ATerm term, pOFP_Traverse Suffix);

/* R1232 */
ATbool ofp_traverse_EndFunctionStmt(ATerm term, pOFP_Traverse EndFunctionStmt);

/* R1233 */
ATbool ofp_traverse_SubroutineSubprogram(ATerm term, pOFP_Traverse SubroutineSubprogram);

/* R1234 */
ATbool ofp_traverse_SubroutineStmt(ATerm term, pOFP_Traverse SubroutineStmt);

/* R1235 */
ATbool ofp_traverse_DummyArg(ATerm term, pOFP_Traverse DummyArg);
ATbool ofp_traverse_DummyArgList(ATerm term, pOFP_Traverse DummyArgList);

/* R1236 */
ATbool ofp_traverse_EndSubroutineStmt(ATerm term, pOFP_Traverse EndSubroutineStmt);

/* R1237 */
ATbool ofp_traverse_SeparateModuleSubprogram(ATerm term, pOFP_Traverse SeparateModuleSubprogram);

/* R1238 */
ATbool ofp_traverse_MpSubprogramStmt(ATerm term, pOFP_Traverse MpSubprogramStmt);

/* R1239 */
ATbool ofp_traverse_EndMpSubprogramStmt(ATerm term, pOFP_Traverse EndMpSubprogramStmt);

/* R1240 */
ATbool ofp_traverse_EntryStmt(ATerm term, pOFP_Traverse EntryStmt);

/* R1241 */
ATbool ofp_traverse_ReturnStmt(ATerm term, pOFP_Traverse ReturnStmt);

/* R1242 */
ATbool ofp_traverse_ContainsStmt(ATerm term, pOFP_Traverse ContainsStmt);

/* R1243 */
ATbool ofp_traverse_StmtFunctionStmt(ATerm term, pOFP_Traverse StmtFunctionStmt);


/** Identifier aliases
 */

ATbool ofp_traverse_AncestorModuleName(ATerm term, pOFP_Traverse AncestorModuleName);
ATbool ofp_traverse_ArgName(ATerm term, pOFP_Traverse ArgName);
ATbool ofp_traverse_ArrayName(ATerm term, pOFP_Traverse ArrayName);
ATbool ofp_traverse_AssociateConstructName(ATerm term, pOFP_Traverse AssociateConstructName);
ATbool ofp_traverse_AssociateName(ATerm term, pOFP_Traverse AssociateName);
ATbool ofp_traverse_BindingName(ATerm term, pOFP_Traverse BindingName);
ATbool ofp_traverse_BlockConstructName(ATerm term, pOFP_Traverse BlockConstructName);
ATbool ofp_traverse_BlockDataName(ATerm term, pOFP_Traverse BlockDataName);
ATbool ofp_traverse_CaseConstructName(ATerm term, pOFP_Traverse CaseConstructName);
ATbool ofp_traverse_CoarrayName(ATerm term, pOFP_Traverse CoarrayName);
ATbool ofp_traverse_CommonBlockName(ATerm term, pOFP_Traverse CommonBlockName);
ATbool ofp_traverse_ComponentName(ATerm term, pOFP_Traverse ComponentName);
ATbool ofp_traverse_ConstructName(ATerm term, pOFP_Traverse ConstructName);
ATbool ofp_traverse_CriticalConstructName(ATerm term, pOFP_Traverse CriticalConstructName);
ATbool ofp_traverse_DataPointerComponentName(ATerm term, pOFP_Traverse DataPointerComponentName);
ATbool ofp_traverse_DoConstructName(ATerm term, pOFP_Traverse DoConstructName);
ATbool ofp_traverse_IfConstructName(ATerm term, pOFP_Traverse IfConstructName);
ATbool ofp_traverse_EntityName(ATerm term, pOFP_Traverse EntityName);
ATbool ofp_traverse_EntryName(ATerm term, pOFP_Traverse EntryName);
ATbool ofp_traverse_ExternalName(ATerm term, pOFP_Traverse ExternalName);
ATbool ofp_traverse_FinalSubroutineName(ATerm term, pOFP_Traverse FinalSubroutineName);
ATbool ofp_traverse_ForallConstructName(ATerm term, pOFP_Traverse ForallConstructName);
ATbool ofp_traverse_FunctionName(ATerm term, pOFP_Traverse FunctionName);
ATbool ofp_traverse_GenericName(ATerm term, pOFP_Traverse GenericName);
ATbool ofp_traverse_ImportName(ATerm term, pOFP_Traverse ImportName);
ATbool ofp_traverse_IndexName(ATerm term, pOFP_Traverse IndexName);
ATbool ofp_traverse_InterfaceName(ATerm term, pOFP_Traverse InterfaceName);
ATbool ofp_traverse_IntrinsicProcedureName(ATerm term, pOFP_Traverse IntrinsicProcedureName);
ATbool ofp_traverse_LocalName(ATerm term, pOFP_Traverse LocalName);
ATbool ofp_traverse_ModuleName(ATerm term, pOFP_Traverse ModuleName);
ATbool ofp_traverse_Name(ATerm term, pOFP_Traverse Name);
ATbool ofp_traverse_NamelistGroupName(ATerm term, pOFP_Traverse NamelistGroupName);
ATbool ofp_traverse_ObjectName(ATerm term, OFP::Name* ObjectName);
ATbool ofp_traverse_ObjectName(ATerm term, pOFP_Traverse ObjectName);
ATbool ofp_traverse_ParentSubmoduleName(ATerm term, pOFP_Traverse ParentSubmoduleName);
ATbool ofp_traverse_ParentTypeName(ATerm term, pOFP_Traverse ParentTypeName);
ATbool ofp_traverse_PartName(ATerm term, pOFP_Traverse PartName);
ATbool ofp_traverse_ProcedureComponentName(ATerm term, pOFP_Traverse ProcedureComponentName);
ATbool ofp_traverse_ProcedureEntityName(ATerm term, pOFP_Traverse ProcedureEntityName);
ATbool ofp_traverse_ProcedureName(ATerm term, pOFP_Traverse ProcedureName);
ATbool ofp_traverse_ProcEntityName(ATerm term, pOFP_Traverse ProcEntityName);
ATbool ofp_traverse_ProgramName(ATerm term, OFP::Name * ProgramName);
ATbool ofp_traverse_ProgramName(ATerm term, pOFP_Traverse ProgramName);
ATbool ofp_traverse_ResultName(ATerm term, pOFP_Traverse ResultName);
ATbool ofp_traverse_ScalarIntConstantName(ATerm term, pOFP_Traverse ScalarIntConstantName);
ATbool ofp_traverse_ScalarIntVariableName(ATerm term, pOFP_Traverse ScalarIntVariableName);
ATbool ofp_traverse_ScalarVariableName(ATerm term, pOFP_Traverse ScalarVariableName);
ATbool ofp_traverse_SelectConstructName(ATerm term, pOFP_Traverse SelectConstructName);
ATbool ofp_traverse_SubmoduleName(ATerm term, pOFP_Traverse SubmoduleName);
ATbool ofp_traverse_SubroutineName(ATerm term, pOFP_Traverse SubroutineName);
ATbool ofp_traverse_TypeName(ATerm term, pOFP_Traverse TypeName);
ATbool ofp_traverse_TypeParamName(ATerm term, pOFP_Traverse TypeParamName);
ATbool ofp_traverse_UseName(ATerm term, pOFP_Traverse UseName);


/** Lists
 */

ATbool ofp_traverse_ExternalNameList(ATerm term, pOFP_Traverse ExternalNameList);
ATbool ofp_traverse_DummyArgNameList(ATerm term, pOFP_Traverse DummyArgNameList);
ATbool ofp_traverse_LabelList(ATerm term, pOFP_Traverse LabelList);

/** Terminals
 */

ATbool ofp_traverse_Dop(ATerm term, pOFP_Traverse Dop);
ATbool ofp_traverse_HexConstant(ATerm term, pOFP_Traverse HexConstant);
ATbool ofp_traverse_OctalConstant(ATerm term, pOFP_Traverse OctalConstant);
ATbool ofp_traverse_BinaryConstant(ATerm term, pOFP_Traverse BinaryConstant);
ATbool ofp_traverse_Rcon(ATerm term, pOFP_Traverse Rcon);
ATbool ofp_traverse_Scon(ATerm term, pOFP_Traverse Scon);
ATbool ofp_traverse_Icon(ATerm term, pOFP_Traverse Icon);
ATbool ofp_traverse_Ident(ATerm term, OFP::Ident * Ident);
ATbool ofp_traverse_Ident(ATerm term, pOFP_Traverse Ident);
ATbool ofp_traverse_Letter(ATerm term, pOFP_Traverse Letter);
ATbool ofp_traverse_Label(ATerm term, pOFP_Traverse Label);
ATbool ofp_traverse_Label(ATerm term, OFP::Label * Label);
ATbool ofp_traverse_LblRef(ATerm term, pOFP_Traverse LblRef);
ATbool ofp_traverse_StartCommentBlock(ATerm term, pOFP_Traverse StartCommentBlock);
ATbool ofp_traverse_EOS(ATerm term, pOFP_Traverse EOS);
ATbool ofp_traverse_EOS(ATerm term, OFP::EOS * EOS);

#endif /* OFP_TRAVERSAL_H */
