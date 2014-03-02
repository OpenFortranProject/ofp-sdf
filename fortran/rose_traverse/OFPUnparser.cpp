#include "OFPUnparser.hpp"

void OFP::FortranTextUnparser::unparseExpr(SgUntypedExpression* expr)
{
   if (!expr) return;

   switch (expr->typeId())
      {
        case SgUntypedNode::T_UntypedRefExpr:
           {
              SgUntypedRefExpression * e = dynamic_cast<SgUntypedRefExpression*>(expr);
              if (e) {
                 oss << e->get_name();
              }
              break;
           }
        case SgUntypedNode::T_UntypedValueExpr:
           {
              SgUntypedValueExpression * e = dynamic_cast<SgUntypedValueExpression*>(expr);
              if (e) {
                 oss << e->get_value();
                 if (e->hasKind()) {
                    // TODO kind should be an expression
                    oss << "_" << e->get_kind();
                 }
              }
              break;
           }
        case SgUntypedNode::T_UntypedBinaryOp:
           {
              SgUntypedBinaryOperator * binop = dynamic_cast<SgUntypedBinaryOperator*>(expr);
              if (binop) {
                 unparseExpr   (binop->get_lhs_operand());
                 unparseOpEnum (binop->get_operator_enum());
                 unparseExpr   (binop->get_rhs_operand());
              }
              break;
           }

        default:
           oss << "FortranTextUnparser::UnparseUnknownExpr::::::::::::::::::::::::\n";
      }
}

void OFP::FortranTextUnparser::unparseOpEnum(SgToken::ROSE_Fortran_Operators e)
{
   switch (e)
      {
         case SgToken::FORTRAN_INTRINSIC_PLUS:    oss << " + ";      break;
         case SgToken::FORTRAN_INTRINSIC_MINUS:   oss << " - ";      break;
         case SgToken::FORTRAN_INTRINSIC_POWER:   oss << " ** ";     break;
         case SgToken::FORTRAN_INTRINSIC_CONCAT:  oss << " // ";     break;
         case SgToken::FORTRAN_INTRINSIC_TIMES:   oss << " * ";      break;
         case SgToken::FORTRAN_INTRINSIC_DIVIDE:  oss << " / ";      break;
         case SgToken::FORTRAN_INTRINSIC_AND:     oss << " .AND. ";  break;
         case SgToken::FORTRAN_INTRINSIC_OR:      oss << " .OR.  ";  break;
         case SgToken::FORTRAN_INTRINSIC_EQV:     oss << " .EQV. ";  break;
         case SgToken::FORTRAN_INTRINSIC_NEQV:    oss << " .NEQV. "; break;
         case SgToken::FORTRAN_INTRINSIC_EQ:      oss << " = ";      break;
         case SgToken::FORTRAN_INTRINSIC_NE:      oss << " /= ";     break;
         case SgToken::FORTRAN_INTRINSIC_GE:      oss << " >= ";     break;
         case SgToken::FORTRAN_INTRINSIC_LE:      oss << " <= ";     break;
         case SgToken::FORTRAN_INTRINSIC_LT:      oss << " < ";      break;
         case SgToken::FORTRAN_INTRINSIC_GT:      oss << " > ";      break;
         case SgToken::FORTRAN_INTRINSIC_NOT:     oss << " .NOT. ";  break;
         case SgToken::FORTRAN_INTRINSIC_OLDEQ:   oss << " .EQ. ";   break;
         case SgToken::FORTRAN_INTRINSIC_OLDNE:   oss << " .NE. ";   break;
         case SgToken::FORTRAN_INTRINSIC_OLDGE:   oss << " .GE. ";   break;
         case SgToken::FORTRAN_INTRINSIC_OLDLE:   oss << " .LE. ";   break;
         case SgToken::FORTRAN_INTRINSIC_OLDLT:   oss << " .LT. ";   break;
         case SgToken::FORTRAN_INTRINSIC_OLDGT:   oss << " .GT. ";   break;
      }
}

void OFP::FortranTextUnparser::unparseStmt(SgUntypedStatement* stmt)
{
   if (!stmt) return;

   switch (stmt->typeId())
      {
        case SgUntypedNode::T_UntypedAssignmentStmt:
           {
              SgUntypedAssignmentStatement * s = dynamic_cast<SgUntypedAssignmentStatement*>(stmt);
              if (s) {
                 unparseExpr(s->get_lhs());
                 oss << " = ";
                 unparseExpr(s->get_rhs());
                 oss << "\n";
              }
              break;
           }
        default:
           oss << "FortranTextUnparser::UnparseUnknownStmt::::::::::::::::::::::::\n";
      }
}
