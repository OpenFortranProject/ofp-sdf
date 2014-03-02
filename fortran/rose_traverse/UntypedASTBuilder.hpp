#ifndef	ROSE_BUILDER_HPP
#define	ROSE_BUILDER_HPP

#include "ASTBuilder.hpp"

namespace OFP {

class UntypedASTBuilder : public ASTBuilder
{
 public:
   UntypedASTBuilder();
  ~UntypedASTBuilder();

   virtual void build_SpecificationPart(SpecificationPart * specificationPart);
   virtual void build_ImplicitPart(ImplicitPart * implicitPart);
   virtual void build_ExecutionPart(ExecutionPart * executionPart);
   virtual void build_TypeDeclarationStmt(TypeDeclarationStmt * typeDeclarationStmt);
   virtual void build_ImplicitStmt(ImplicitStmt * implicitStmt);

   virtual void build_MainProgram(MainProgram * main);
   virtual void build_ProgramStmt(ProgramStmt * programStmt);
   virtual void build_EndProgramStmt(EndProgramStmt * endProgramStmt);
   
 private:
   
};

} // namespace OFP

#endif
