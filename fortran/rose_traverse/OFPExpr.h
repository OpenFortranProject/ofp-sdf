#ifndef	OFP_EXPR_H
#define	OFP_EXPR_H

#include "traversal.h"

namespace OFP {

class Expr : public Node
{
 public:
    Expr()
      {
         pExpr1 = NULL;
         pExpr2 = NULL;
         pPrimary = NULL;
         pDefinedBinaryOp = NULL;
         pDefinedUnaryOp = NULL;
      }
   ~Expr();

   enum OptionType
     {
        DEFAULT = 0,
        DefBinExpr,
        NotEqvExpr,
        EqvExpr,
        OrExpr,
        AndExpr,
        NotExpr,
        GE_Expr,
        GT_Expr,
        LE_Expr,
        LT_Expr,
        NE_Expr,
        EQ_Expr,
        ConcatExpr,
        MinusExpr,
        PlusExpr,
        UnaryMinusExpr,
        UnaryPlusExpr,
        DivExpr,
        MultExpr,
        PowerExpr,
        DefUnaryExpr,
        Expr_P
     };

    Expr* newExpr()
      {
         Expr* node = new Expr();
         node->pExpr1 = pExpr1;  pExpr1 = NULL;
         node->pExpr2 = pExpr1;  pExpr2 = NULL;
         node->pPrimary = pPrimary;  pPrimary = NULL;
         node->pDefinedBinaryOp = pDefinedBinaryOp;  pDefinedBinaryOp = NULL;
         node->pDefinedUnaryOp = pDefinedUnaryOp;  pDefinedUnaryOp = NULL;
         return node;
      }

    Expr* getExpr1() {return pExpr1;}
    Expr* getExpr2() {return pExpr2;}
    Primary* getPrimary() {return pPrimary;}
    DefinedBinaryOp* getDefinedBinaryOp() {return pDefinedBinaryOp;}
    DefinedUnaryOp* getDefinedUnaryOp() {return pDefinedUnaryOp;}

    void setExpr1(Expr* expr1) {pExpr1 = expr1;}
    void setExpr2(Expr* expr2) {pExpr1 = expr2;}
    void setPrimary(Primary* primary) {pPrimary = primary;}
    void setDefinedBinaryOp(DefinedBinaryOp* definedbinaryop) {pDefinedBinaryOp = definedbinaryop;}
    void setDefinedUnaryOp(DefinedUnaryOp* definedunaryop) {pDefinedUnaryOp = definedunaryop;}

 private:
    Expr* pExpr1;
    Expr* pExpr2;
    Primary* pPrimary;
    DefinedBinaryOp* pDefinedBinaryOp;
    DefinedUnaryOp* pDefinedUnaryOp;
};

} // namespace OFP

#endif
