#ifndef	OFP_UNPARSER_HPP
#define	OFP_UNPARSER_HPP

#include "OFPNodes.h"
#include <string>
#include <iostream>
#include <sstream>

namespace OFP {

class Unparser;

void setUnparser(Unparser* u);

class UnparseInfo
{
 public:
   UnparseInfo() : level(0)  {}
   virtual ~UnparseInfo()    {}

   int indentLevel() {return level;}

 private:
   int level;
};

class Unparser
{
 public:
   Unparser() : oss(std::cout) {}
   Unparser(UnparseInfo & infoObj) : oss(std::cout) {info = infoObj;}
   virtual ~Unparser() {}

   virtual void unparseExpr(SgUntypedExpression * expr) = 0;
   virtual void unparseStmt(SgUntypedStatement  * stmt) = 0;
   virtual void unparseOpEnum(SgToken::ROSE_Fortran_Operators e) = 0;

 protected:
   std::ostream & oss;

 private:
   UnparseInfo info;
};

class FortranTextUnparser : public Unparser
{
 public:
   FortranTextUnparser()                      {}
   FortranTextUnparser(UnparseInfo & infoObj) {}
  ~FortranTextUnparser()                      {}

   void unparseExpr(SgUntypedExpression * expr);
   void unparseStmt(SgUntypedStatement  * stmt);
   void unparseOpEnum(SgToken::ROSE_Fortran_Operators e);

 private:
   
};

} // namespace OFP

#endif
