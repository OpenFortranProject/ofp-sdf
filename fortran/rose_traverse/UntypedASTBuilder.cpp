#include "UntypedASTBuilder.hpp"
#include <assert.h>
#include <stdio.h>

extern OFP::Unparser* unparser;

namespace OFP {

UntypedASTBuilder::UntypedASTBuilder()
{
}

UntypedASTBuilder::~UntypedASTBuilder()
{
}

//========================================================================================
// R204 specification-part
//----------------------------------------------------------------------------------------
void UntypedASTBuilder::build_SpecificationPart(SpecificationPart * specificationPart)
{
   SgUntypedStatement * stmt;
   std::vector<SgUntypedStatement*>* stmtList = new std::vector<SgUntypedStatement*>();

   std::vector<UseStmt*>* useList = specificationPart->getUseStmtList();
   for (int i = 0; i < useList->size(); i++) {
      stmt = dynamic_cast<SgUntypedStatement*>(useList->at(i)->getPayload());  assert(stmt);
      stmtList->push_back(stmt);
   }

   std::vector<ImportStmt*>* importList = specificationPart->getImportStmtList();
   for (int i = 0; i < importList->size(); i++) {
      stmt = dynamic_cast<SgUntypedStatement*>(importList->at(i)->getPayload());  assert(stmt);
      stmtList->push_back(stmt);
   }

   ImplicitPart* implicitPart = specificationPart->getImplicitPart();
   if (implicitPart) {
      SgUntypedStatementList * sgStmtList;
      sgStmtList = dynamic_cast<SgUntypedStatementList*>(implicitPart->getPayload());  assert(sgStmtList);
      std::vector<SgUntypedStatement*>* implList = sgStmtList->get_statement_list();
      for (int i = 0; i < implList->size(); i++) {
         stmt = dynamic_cast<SgUntypedStatement*>(implList->at(i));  assert(stmt);
         stmtList->push_back(stmt);
      }
   }

   std::vector<DeclarationConstruct*>* declList = specificationPart->getDeclarationConstructList();
   for (int i = 0; i < declList->size(); i++) {
      stmt = dynamic_cast<SgUntypedStatement*>(declList->at(i)->getPayload());  assert(stmt);
      stmtList->push_back(stmt);
   }

   specificationPart->setPayload(new SgUntypedStatementList(stmtList));
   
   printf("build_SpecificationPart: ........... %lu\n", stmtList->size());

}

//========================================================================================
// R205 implicit-part
//----------------------------------------------------------------------------------------
void UntypedASTBuilder::build_ImplicitPart(ImplicitPart* implicitPart)
{
   SgUntypedStatement * stmt;

   std::vector<SgUntypedStatement*>* specList = new std::vector<SgUntypedStatement*>();
   std::vector<ImplicitPartStmt*>*  ipartList = implicitPart->getImplicitPartStmtList();

   for (int i = 0; i < ipartList->size(); i++) {
      stmt = dynamic_cast<SgUntypedStatement*>(ipartList->at(i)->getPayload());  assert(stmt);
      specList->push_back(stmt);
   }
   stmt = dynamic_cast<SgUntypedStatement*>(implicitPart->getImplicitStmt()->getPayload());  assert(stmt);
   specList->push_back(stmt);

   implicitPart->setPayload(new SgUntypedStatementList(specList));

   printf("build_ImplicitPart: .............. %lu\n", specList->size());
}

//========================================================================================
// R208 execution-part
//----------------------------------------------------------------------------------------
void UntypedASTBuilder::build_ExecutionPart(ExecutionPart * executionPart)
{
   SgUntypedStatement * stmt;

   std::vector<ExecutionPartConstruct*>* execList = executionPart->getExecutionPartConstructList();
   std::vector<SgUntypedStatement*>* sgStmtList = new std::vector<SgUntypedStatement*>();

   for (int i = 0; i < execList->size(); i++) {
      stmt = dynamic_cast<SgUntypedStatement*>(execList->at(i)->getPayload());  assert(stmt);
      sgStmtList->push_back(stmt);
   }
   executionPart->setPayload(new SgUntypedStatementList(sgStmtList));

   printf("build_ExecutionPart: ............... %lu\n", sgStmtList->size());
}

//========================================================================================
// R501 type-declaration-stmt
//----------------------------------------------------------------------------------------
void UntypedASTBuilder::build_TypeDeclarationStmt(TypeDeclarationStmt * typeDeclarationStmt)
{
   SgUntypedStatement * stmt;
   std::string label = (typeDeclarationStmt->getLabel()) ? *typeDeclarationStmt->getLabel()->getValue() : "";

   stmt = new SgUntypedVariableDeclaration(label, SgToken::FORTRAN_TYPE_DECLARATION_STMT);

   DeclarationTypeSpec * declSpec = typeDeclarationStmt->getDeclarationTypeSpec();
   // OFP::OptAttrSpecList OptAttrSpecList;

   std::vector<EntityDecl*>* declList = typeDeclarationStmt->getEntityDeclList()->getEntityDeclList();

   // OFP::EntityDeclList EntityDeclList;

   printf("build_TypeDeclarationStmt: .........\n");

   if (declSpec->getOptionType() == DeclarationTypeSpec::DeclarationTypeSpec_ITS) {
      IntrinsicTypeSpec* ispec = declSpec->getIntrinsicTypeSpec();
      if (ispec->getOptionType() == IntrinsicTypeSpec::IntrinsicTypeSpec_INT) {
         printf("                type_spec: ......... INTEGER\n");
      }
   }

   printf("                variables: ......... ");
   for (int i = 0; i < declList->size(); i++) {
      std::string * name = declList->at(i)->getObjectName()->getIdent()->getValue();
      printf("%s ", name->c_str());
   }
   printf("\n");

   typeDeclarationStmt->setPayload(stmt);
}

//========================================================================================
// R560 implicit-stmt
//----------------------------------------------------------------------------------------
void UntypedASTBuilder::build_ImplicitStmt(ImplicitStmt * implicitStmt)
{
   SgUntypedStatement * stmt;
   std::string label = (implicitStmt->getLabel()) ? *implicitStmt->getLabel()->getValue() : "";

   switch (implicitStmt->getOptionType()) {
     case ImplicitStmt::ImplicitStmt_NONE:
        stmt = new SgUntypedStatement(label, SgToken::FORTRAN_IMPLICIT_NONE);
        printf("build_ImplicitStmt: NONE .........\n");
        break;
     case ImplicitStmt::ImplicitStmt_ISL:
        stmt = new SgUntypedStatement(label, SgToken::FORTRAN_IMPLICIT);
        printf("build_ImplicitStmt: ISL  .........\n");
        break;
   }

   implicitStmt->setPayload(stmt);
}

//========================================================================================
// R1101 main-program
//----------------------------------------------------------------------------------------
void UntypedASTBuilder::build_MainProgram(MainProgram * mainProgram)
{
   SgUntypedStatement * stmt;
   SgUntypedStatementList* sgStmtList;
   SgUntypedSubroutineDeclaration * program;

   program = new SgUntypedSubroutineDeclaration("", SgToken::FORTRAN_MAIN_PROGRAM);

   stmt = dynamic_cast<SgUntypedStatement*>(mainProgram->getProgramStmt()->getPayload());  assert(stmt);
   program->set_begin_statement(stmt);

   printf("build_MainProgram label: ........... %s\n", stmt->get_string_label().c_str());
   printf("             begin name: ........... %s\n", stmt->get_statement_name().c_str());

   // SpecificationPart
   //
   SpecificationPart * specPart = mainProgram->getSpecificationPart();
   sgStmtList = dynamic_cast<SgUntypedStatementList*>(specPart->getPayload());  assert(sgStmtList);
   specPart->setPayload(NULL);  //TODO - consider takePayload() method instead
   program->set_spec_part_list(sgStmtList->take_statement_list());

   std::vector<SgUntypedStatement*>* list = program->get_spec_part_list();
   printf("         spec_list_size: ........... %lu\n", list->size());

   // ExecutionPart
   //
   ExecutionPart * execPart = mainProgram->getExecutionPart();
   sgStmtList = dynamic_cast<SgUntypedStatementList*>(execPart->getPayload());  assert(sgStmtList);
   execPart->setPayload(NULL);  //TODO - consider takePayload() method instead
   program->set_exec_part_list(sgStmtList->take_statement_list());

   list = program->get_exec_part_list();
   printf("         exec_list_size: ........... %lu\n", list->size());

   // InternalSubprogramPart
   // TODO
   // 
   InternalSubprogramPart * subPart = mainProgram->getInternalSubprogramPart();

   stmt = dynamic_cast<SgUntypedStatement*>(mainProgram->getEndProgramStmt()->getPayload());  assert(stmt);
   program->set_end_statement(stmt);

   printf("              end label: ........... %s\n", stmt->get_string_label().c_str());
   printf("              end  name: ........... %s\n", stmt->get_statement_name().c_str());
}
   
//========================================================================================
// R1102 program-stmt
//----------------------------------------------------------------------------------------
void UntypedASTBuilder::build_ProgramStmt(ProgramStmt * programStmt)
{
   SgUntypedStatement * stmt;
   std::string label = (programStmt->getLabel()) ? *programStmt->getLabel()->getValue() : "";
   stmt = new SgUntypedStatement(label, SgToken::FORTRAN_PROGRAM_STMT);
   stmt->set_statement_name(*programStmt->getProgramName()->getIdent()->getValue());
   programStmt->setPayload(stmt);
}

//========================================================================================
// R1103 end-program-stmt
//----------------------------------------------------------------------------------------
void UntypedASTBuilder::build_EndProgramStmt(EndProgramStmt * endProgramStmt)
{
   SgUntypedStatement * stmt;
   std::string label = (endProgramStmt->getLabel())       ? *endProgramStmt->getLabel()->getValue() : "";
   std::string name  = (endProgramStmt->getProgramName()) ? *endProgramStmt->getProgramName()->getIdent()->getValue() : "";
   stmt = new SgUntypedStatement(label, SgToken::FORTRAN_END_PROGRAM_STMT);
   stmt->set_statement_name(name);
   endProgramStmt->setPayload(stmt);
}

}; // namespace OFP


