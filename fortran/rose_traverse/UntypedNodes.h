#include <string>
#include <vector>

// Forward declarations
class SgUntypedUnaryOperator;
class SgUntypedBinaryOperator;
class SgUntypedValueExpression;
class SgUntypedArrayReferenceExpression;
class SgUntypedOtherExpression;
class SgUntypedFunctionCallOrArrayReferenceExpression;
class SgUntypedExpression;
class SgUntypedImplicitDeclaration;
class SgUntypedVariableDeclaration;
class SgUntypedProcedureHeaderDeclaration;
class SgUntypedFunctionDeclaration;
class SgUntypedSubroutineDeclaration;
class SgUntypedDeclarationStatement;
class SgUntypedAssignmentStatement;
class SgUntypedFunctionCallStatement;
class SgUntypedBlockStatement;
class SgUntypedStatement;
class SgUntypedNode;
// CER
class SgUntypedStatementList;
class SgUntypedInitializedName;
class SgUntypedRefExpression;
class SgUntypedBlockStatement;

class Sg_File_Info
   {
   };

class SgLocatedNode
   {
   };

class SgLocatedNodeSupport: public SgLocatedNode
   {
   };

   
class SgToken : public SgLocatedNodeSupport
   {
     public: 

enum ROSE_Fortran_Keywords
   {
      FORTRAN_ABSTRACT = 0 + 0,
      FORTRAN_ACCESS = 1 + 0,
      FORTRAN_ACTION = 2 + 0,
      FORTRAN_ALLOCATE = 3 + 0,
      FORTRAN_ALLOCATABLE = 4 + 0,
      FORTRAN_ASSIGN = 5 + 0,
      FORTRAN_ASSOCIATE = 6 + 0,
      FORTRAN_ASYNCHRONOUS = 7 + 0,
      FORTRAN_BACKSPACE = 8 + 0,
      FORTRAN_BIND = 9 + 0,
      FORTRAN_BLANK = 10 + 0,
      FORTRAN_BLOCK_DATA = 11 + 0,
      FORTRAN_CALL = 12 + 0,
      FORTRAN_CHARACTER = 13 + 0,
      FORTRAN_CLASS = 14 + 0,
      FORTRAN_CLOSE = 15 + 0,
      FORTRAN_CONTINUE = 16 + 0,
      FORTRAN_CYCLE = 17 + 0,
      FORTRAN_CASE = 18 + 0,
      FORTRAN_COMMON = 19 + 0,
      FORTRAN_COMPLEX = 20 + 0,
      FORTRAN_CONTAINS = 21 + 0,
      FORTRAN_DEALLOCATE = 22 + 0,
      FORTRAN_DATA = 23 + 0,
      FORTRAN_DEFERRED = 24 + 0,
      FORTRAN_DELIM = 25 + 0,
      FORTRAN_DIMENSION = 26 + 0,
      FORTRAN_DO = 27 + 0,
      FORTRAN_DT = 28 + 0,
      FORTRAN_DOUBLEPRECISION = 29 + 0,
      FORTRAN_ENCODING = 30 + 0,
      FORTRAN_END_CASE = 31 + 0,
      FORTRAN_ENDDO = 32 + 0,
      FORTRAN_END_FILE = 33 + 0,
      FORTRAN_END_ENUM = 34 + 0,
      FORTRAN_END_INTERFACE = 35 + 0,
      FORTRAN_END_TYPE = 36 + 0,
      FORTRAN_ERR = 37 + 0,
      FORTRAN_ERRMSG = 38 + 0,
      FORTRAN_EXIT = 39 + 0,
      FORTRAN_ELSE = 40 + 0,
      FORTRAN_ELSEWHERE = 41 + 0,
      FORTRAN_ELSEIF = 42 + 0,
      FORTRAN_ENDIF = 43 + 0,
      FORTRAN_ENTRY = 44 + 0,
      FORTRAN_END = 45 + 0,
      FORTRAN_ENUM = 46 + 0,
      FORTRAN_ENUMERATOR = 47 + 0,
      FORTRAN_EQUIVALENCE = 48 + 0,
      FORTRAN_EXTERNAL = 49 + 0,
      FORTRAN_EXTENDS = 50 + 0,
      FORTRAN_FILE = 51 + 0,
      FORTRAN_FINAL = 52 + 0,
      FORTRAN_FMT = 53 + 0,
      FORTRAN_FORALL = 54 + 0,
      FORTRAN_FORM = 55 + 0,
      FORTRAN_FORMATTED = 56 + 0,
      FORTRAN_FORMAT = 57 + 0,
      FORTRAN_FLUSH = 58 + 0,
      FORTRAN_FUNCTION = 59 + 0,
      FORTRAN_GENERIC = 60 + 0,
      FORTRAN_GOTO = 61 + 0,
      FORTRAN_ID = 62 + 0,
      FORTRAN_IF = 63 + 0,
      FORTRAN_INQUIRE = 64 + 0,
      FORTRAN_INTEGER = 65 + 0,
      FORTRAN_IOMSG = 66 + 0,
      FORTRAN_IOSTAT = 67 + 0,
      FORTRAN_IMPLICIT = 68 + 0,
      FORTRAN_IMPLICIT_NONE = 69 + 0,
      FORTRAN_IMPORT = 70 + 0,
      FORTRAN_INTERFACE = 71 + 0,
      FORTRAN_INTENT = 72 + 0,
      FORTRAN_INTRINSIC = 73 + 0,
      FORTRAN_LEN = 74 + 0,
      FORTRAN_LOGICAL = 75 + 0,
      FORTRAN_KIND = 76 + 0,
      FORTRAN_MODULE_PROC = 77 + 0,
      FORTRAN_MODULE = 78 + 0,
      FORTRAN_NON_INTRINSIC = 79 + 0,
      FORTRAN_NON_OVERRIDABLE = 80 + 0,
      FORTRAN_NULL = 81 + 0,
      FORTRAN_NULLIFY = 82 + 0,
      FORTRAN_NAMELIST = 83 + 0,
      FORTRAN_NML = 84 + 0,
      FORTRAN_NONE = 85 + 0,
      FORTRAN_NOPASS = 86 + 0,
      FORTRAN_ONLY = 87 + 0,
      FORTRAN_OPEN = 88 + 0,
      FORTRAN_OPTIONAL = 89 + 0,
      FORTRAN_PARAMETER = 90 + 0,
      FORTRAN_PASS = 91 + 0,
      FORTRAN_PAUSE = 92 + 0,
      FORTRAN_POINTER = 93 + 0,
      FORTRAN_PRINT = 94 + 0,
      FORTRAN_PRIVATE = 95 + 0,
      FORTRAN_PROCEDURE = 96 + 0,
      FORTRAN_PROGRAM = 97 + 0,
      FORTRAN_PROTECTED = 98 + 0,
      FORTRAN_READ = 99 + 0,
      FORTRAN_REAL = 100 + 0,
      FORTRAN_RETURN = 101 + 0,
      FORTRAN_REWIND = 102 + 0,
      FORTRAN_ROUND = 103 + 0,
      FORTRAN_SELECTCASE = 104 + 0,
      FORTRAN_SELECTTYPE = 105 + 0,
      FORTRAN_SEQUENCE = 106 + 0,
      FORTRAN_SAVE = 107 + 0,
      FORTRAN_SIGN = 108 + 0,
      FORTRAN_SIZE = 109 + 0,
      FORTRAN_SOURCE = 110 + 0,
      FORTRAN_STAT = 111 + 0,
      FORTRAN_STOP = 112 + 0,
      FORTRAN_SUBROUTINE = 113 + 0,
      FORTRAN_TARGET = 114 + 0,
      FORTRAN_THEN = 115 + 0,
      FORTRAN_DERIVED_DECL = 116 + 0,
      FORTRAN_TYPEIS = 117 + 0,
      FORTRAN_UNFORMATTED = 118 + 0,
      FORTRAN_UNIT = 119 + 0,
      FORTRAN_USE = 120 + 0,
      FORTRAN_VALUE = 121 + 0,
      FORTRAN_VOLATILE = 122 + 0,
      FORTRAN_WAIT = 123 + 0,
      FORTRAN_WHERE = 124 + 0,
      FORTRAN_WRITE = 125 + 0,
      // CER
      FORTRAN_VARIABLE = 126 + 0,
      // CER
      FORTRAN_VARIABLE_REF = 127 + 0,
      // CER
      FORTRAN_SPECIFICATION_PART = 128 + 0,
      // CER
      FORTRAN_UNKNOWN_TYPE = 129 + 0,
      // CER
      FORTRAN_MAIN_PROGRAM = 130 + 0,
      FORTRAN_PROGRAM_STMT = 131 + 0,
      FORTRAN_END_PROGRAM_STMT = 132 + 0,
      FORTRAN_TYPE_DECLARATION_STMT = 133 + 0
   };

enum ROSE_Fortran_Operators
   {
      FORTRAN_INTRINSIC_PLUS = 0 + 10000,
      FORTRAN_INTRINSIC_MINUS = 1 + 10000,
      FORTRAN_INTRINSIC_POWER = 2 + 10000,
      FORTRAN_INTRINSIC_CONCAT = 3 + 10000,
      FORTRAN_INTRINSIC_TIMES = 4 + 10000,
      FORTRAN_INTRINSIC_DIVIDE = 5 + 10000,
      FORTRAN_INTRINSIC_AND = 6 + 10000,
      FORTRAN_INTRINSIC_OR = 7 + 10000,
      FORTRAN_INTRINSIC_EQV = 8 + 10000,
      FORTRAN_INTRINSIC_NEQV = 9 + 10000,
      FORTRAN_INTRINSIC_EQ = 10 + 10000,
      FORTRAN_INTRINSIC_NE = 11 + 10000,
      FORTRAN_INTRINSIC_GE = 12 + 10000,
      FORTRAN_INTRINSIC_LE = 13 + 10000,
      FORTRAN_INTRINSIC_LT = 14 + 10000,
      FORTRAN_INTRINSIC_GT = 15 + 10000,
      FORTRAN_INTRINSIC_NOT = 16 + 10000,
      FORTRAN_INTRINSIC_OLDEQ = 17 + 10000,
      FORTRAN_INTRINSIC_OLDNE = 18 + 10000,
      FORTRAN_INTRINSIC_OLDGE = 19 + 10000,
      FORTRAN_INTRINSIC_OLDLE = 20 + 10000,
      FORTRAN_INTRINSIC_OLDLT = 21 + 10000,
      FORTRAN_INTRINSIC_OLDGT = 22 + 10000
   };

   };


// Class Definition for SgUntypedNode
class SgUntypedNode  : public SgLocatedNodeSupport
   {
     public: 

      enum SgNodeType
        {
           UNKNOWN = 0 + 20000,

           T_UntypedRefExpr      = 1 + 20000,
           T_UntypedValueExpr    = 2 + 20000,
           T_UntypedBinaryOp     = 3 + 20000,

           T_UntypedAssignmentStmt  = 1 + 30000

        };

         virtual ~SgUntypedNode() {}

         SgUntypedNode(Sg_File_Info* startOfConstruct ); 
         SgUntypedNode() {} 

         virtual SgNodeType typeId() {return UNKNOWN;}
   };

class SgUntypedStatementList : public SgUntypedNode
   {
     public: 
       SgUntypedStatementList(std::vector<SgUntypedStatement*>* list) : p_stmt_list(list) {}

       virtual ~SgUntypedStatementList()
          {
             // TODO - what about content of list
             if (p_stmt_list) delete p_stmt_list;
          }

       std::vector<SgUntypedStatement*>* get_statement_list() {return p_stmt_list;}
       std::vector<SgUntypedStatement*>* take_statement_list()
          {
             std::vector<SgUntypedStatement*>* stmt_list = p_stmt_list;
             p_stmt_list = NULL;
             return stmt_list;
          }
       //TODO delete void set_statement_list(std::vector<SgUntypedStatement*>* list) {p_stmt_list = list;}

     private: 
       std::vector<SgUntypedStatement*>* p_stmt_list;
   };

class SgUntypedExpression : public SgUntypedNode
   {
     public: 
         virtual ~SgUntypedExpression() {}

         SgUntypedExpression(Sg_File_Info* startOfConstruct ); 
         SgUntypedExpression() {}
   };

class SgUntypedUnaryOperator  : public SgUntypedExpression
   {
     public: 
          SgToken::ROSE_Fortran_Operators get_operator_enum() const;
          void set_operator_enum(SgToken::ROSE_Fortran_Operators operator_enum);

          std::string get_operator_name() const;
          void set_operator_name(std::string operator_name);

          SgUntypedExpression* get_operand() const;
          void set_operand(SgUntypedExpression* operand);

          virtual ~SgUntypedUnaryOperator() {}

     public: 
          SgUntypedUnaryOperator(Sg_File_Info* startOfConstruct , SgToken::ROSE_Fortran_Operators operator_enum = SgToken::FORTRAN_INTRINSIC_PLUS, std::string operator_name = "", SgUntypedExpression* operand = NULL); 
          SgUntypedUnaryOperator(SgToken::ROSE_Fortran_Operators operator_enum, std::string operator_name, SgUntypedExpression* operand); 

    protected:
          SgToken::ROSE_Fortran_Operators p_operator_enum;
          std::string p_operator_name;
          SgUntypedExpression* p_operand;
   };

class SgUntypedBinaryOperator  : public SgUntypedExpression
   {
     public: 
         SgToken::ROSE_Fortran_Operators get_operator_enum() const {return p_operator_enum;}
         void set_operator_enum(SgToken::ROSE_Fortran_Operators operator_enum);

         std::string get_operator_name() const;
         void set_operator_name(std::string operator_name);

         SgUntypedExpression* get_lhs_operand() const {return p_lhs_operand;}
         void set_lhs_operand(SgUntypedExpression* lhs_operand);

         SgUntypedExpression* get_rhs_operand() const {return p_rhs_operand;}
         void set_rhs_operand(SgUntypedExpression* rhs_operand);

         virtual ~SgUntypedBinaryOperator() {}

         virtual SgNodeType typeId() {return T_UntypedBinaryOp;}

         SgUntypedBinaryOperator(Sg_File_Info* startOfConstruct , SgToken::ROSE_Fortran_Operators operator_enum = SgToken::FORTRAN_INTRINSIC_PLUS, std::string operator_name = "", SgUntypedExpression* lhs_operand = NULL, SgUntypedExpression* rhs_operand = NULL); 

         SgUntypedBinaryOperator(SgToken::ROSE_Fortran_Operators operator_enum, std::string operator_name, SgUntypedExpression* lhs_operand, SgUntypedExpression* rhs_operand)
            {
               p_operator_enum = operator_enum;
               p_operator_name = operator_name;
               p_lhs_operand = lhs_operand;
               p_rhs_operand = rhs_operand;
            }

    protected:
          SgToken::ROSE_Fortran_Operators p_operator_enum;
          std::string p_operator_name;
          SgUntypedExpression* p_lhs_operand;
          SgUntypedExpression* p_rhs_operand;
   };

class SgUntypedValueExpression  : public SgUntypedExpression
   {
     public: 
         virtual ~SgUntypedValueExpression() {}
         SgUntypedValueExpression(Sg_File_Info* startOfConstruct ); 
         SgUntypedValueExpression();

         SgUntypedValueExpression(const char* val) : value(val), has_kind(false),
                                                     type(SgToken::FORTRAN_UNKNOWN_TYPE),
                                                     is_constant(false), is_literal(false) {}

         virtual SgNodeType typeId() {return T_UntypedValueExpr;}

         std::string get_value() const     {return value;}
         void set_value(std::string& val)  {value = val;}

         // TODO--------------
         // TODO - kind should be an expression
         std::string get_kind() const      {return kind;}
         void set_kind(std::string& k)     {kind = k;  has_kind=true;}
         bool hasKind()                    {return has_kind;}

         bool isConstant()                 {return is_constant;}
         void set_constant_flag(bool flag) {is_constant = flag;}

         bool isLiteral()                  {return is_literal;}
         void set_literal_flag(bool flag)  {is_literal  = flag;}

         SgToken::ROSE_Fortran_Keywords get_type()             {return type;}
         void set_type(SgToken::ROSE_Fortran_Keywords t)       {type = t;}

    protected:
         std::string value;
         std::string kind;
         SgToken::ROSE_Fortran_Keywords type;            // e.g., FORTRAN_INTEGER
         bool has_kind;
         bool is_constant;
         bool is_literal;
   };

class SgUntypedRefExpression  : public SgUntypedExpression
   {
     public: 
         virtual ~SgUntypedRefExpression() {}
         SgUntypedRefExpression();

         SgUntypedRefExpression(const char* str) : name(str), has_kind(false),
                                                   is_variable(false), is_constant(false)
            {
            }

         virtual SgNodeType typeId() {return T_UntypedRefExpr;}

         // TODO - need component and array elements

         std::string get_name() const      {return name;}
         void set_name(std::string& str)   {name = str;}

         std::string get_kind() const      {return kind;}
         void set_kind(std::string& k)     {kind = k;  has_kind=true;}
         bool hasKind()                    {return has_kind;}

         bool isConstant()                 {return is_constant;}
         void set_constant_flag(bool flag) {is_constant = flag;}

         bool isVariable()                 {return is_variable;}
         void set_variable_flag(bool flag) {is_variable = flag;}

    protected:
         std::string name;
         std::string kind;
         bool has_kind;
         bool is_variable;
         bool is_constant;
   };

class SgUntypedArrayReferenceExpression  : public SgUntypedExpression
   {
     public: 
         virtual ~SgUntypedArrayReferenceExpression() {}
         SgUntypedArrayReferenceExpression(Sg_File_Info* startOfConstruct ); 
         SgUntypedArrayReferenceExpression();
   };

class SgUntypedOtherExpression  : public SgUntypedExpression
   {
     public: 
         virtual ~SgUntypedOtherExpression() {}
         SgUntypedOtherExpression(Sg_File_Info* startOfConstruct ); 
         SgUntypedOtherExpression();
         SgUntypedOtherExpression(std::string expression_name, enum SgToken::ROSE_Fortran_Keywords expression_enum) {}
   };

class SgUntypedFunctionCallOrArrayReferenceExpression  : public SgUntypedExpression
   {
     public: 
         virtual ~SgUntypedFunctionCallOrArrayReferenceExpression() {}
         SgUntypedFunctionCallOrArrayReferenceExpression(Sg_File_Info* startOfConstruct ); 
         SgUntypedFunctionCallOrArrayReferenceExpression(); 

   };

class SgUntypedStatement  : public SgUntypedNode
   {
     public: 
         unsigned int get_numeric_label() const;
         void set_numeric_label(unsigned int numeric_label);
         // CER
         std::string & get_string_label() {return p_string_label;}
         SgToken::ROSE_Fortran_Keywords get_statement_enum() const;
         void set_statement_enum(SgToken::ROSE_Fortran_Keywords statement_enum);

         // CER
         void set_statement_name(std::string name) {p_statement_name = name;}
         std::string & get_statement_name() {return p_statement_name;}

         virtual ~SgUntypedStatement() {}
         // CER
         SgUntypedStatement() {}

         SgUntypedStatement(Sg_File_Info* startOfConstruct , unsigned int numeric_label = 0, SgToken::ROSE_Fortran_Keywords statement_enum = SgToken::FORTRAN_ABSTRACT); 
         SgUntypedStatement(unsigned int numeric_label, SgToken::ROSE_Fortran_Keywords statement_enum); 

         // CER
         SgUntypedStatement(std::string string_label, SgToken::ROSE_Fortran_Keywords statement_enum)
            {
               p_string_label = string_label;
               p_statement_enum = statement_enum;
            }

    protected:
         unsigned int p_numeric_label;
         std::string  p_string_label;
         std::string  p_statement_name;
         SgToken::ROSE_Fortran_Keywords p_statement_enum;
   };

class SgUntypedDeclarationStatement  : public SgUntypedStatement
   {
     public: 
         virtual ~SgUntypedDeclarationStatement() {}
         SgUntypedDeclarationStatement(Sg_File_Info* startOfConstruct , unsigned int numeric_label = 0, SgToken::ROSE_Fortran_Keywords statement_enum = SgToken::FORTRAN_ABSTRACT); 
         SgUntypedDeclarationStatement(unsigned int numeric_label, SgToken::ROSE_Fortran_Keywords statement_enum);
         // CER
         SgUntypedDeclarationStatement(std::string string_label, SgToken::ROSE_Fortran_Keywords statement_enum)
            : SgUntypedStatement(string_label, statement_enum)
            {
            }
         SgUntypedDeclarationStatement() {}

         void appendExecPart(SgUntypedStatement* stmt) {exec_part_list.push_back(stmt);}

     protected:
         std::vector<SgUntypedStatement*> spec_part_list;
         std::vector<SgUntypedStatement*> exec_part_list;
   };

class SgUntypedImplicitDeclaration  : public SgUntypedDeclarationStatement
   {
     public: 
         virtual ~SgUntypedImplicitDeclaration() {}
         SgUntypedImplicitDeclaration(Sg_File_Info* startOfConstruct , unsigned int numeric_label = 0, SgToken::ROSE_Fortran_Keywords statement_enum = SgToken::FORTRAN_ABSTRACT); 
         SgUntypedImplicitDeclaration(unsigned int numeric_label, SgToken::ROSE_Fortran_Keywords statement_enum); 
         // CER
         SgUntypedImplicitDeclaration(std::string label, SgToken::ROSE_Fortran_Keywords statement_enum) {} 
   };

class SgUntypedVariableDeclaration  : public SgUntypedDeclarationStatement
   {
     public: 
         virtual ~SgUntypedVariableDeclaration() {}
         SgUntypedVariableDeclaration(Sg_File_Info* startOfConstruct , unsigned int numeric_label = 0, SgToken::ROSE_Fortran_Keywords statement_enum = SgToken::FORTRAN_ABSTRACT); 
         SgUntypedVariableDeclaration(unsigned int numeric_label, SgToken::ROSE_Fortran_Keywords statement_enum); 

         // CER
         SgUntypedVariableDeclaration(std::string string_label, SgToken::ROSE_Fortran_Keywords statement_enum)
            : SgUntypedDeclarationStatement(string_label, statement_enum)
            {
            }

   };

class SgUntypedProcedureHeaderDeclaration  : public SgUntypedDeclarationStatement
   {
     public: 
         virtual ~SgUntypedProcedureHeaderDeclaration() {}
         SgUntypedProcedureHeaderDeclaration(Sg_File_Info* startOfConstruct , unsigned int numeric_label = 0, SgToken::ROSE_Fortran_Keywords statement_enum = SgToken::FORTRAN_ABSTRACT); 
         SgUntypedProcedureHeaderDeclaration(unsigned int numeric_label, SgToken::ROSE_Fortran_Keywords statement_enum); 
   };

class SgUntypedFunctionDeclaration  : public SgUntypedDeclarationStatement
   {
     public: 
      virtual ~SgUntypedFunctionDeclaration();
         SgUntypedFunctionDeclaration(Sg_File_Info* startOfConstruct , unsigned int numeric_label = 0, SgToken::ROSE_Fortran_Keywords statement_enum = SgToken::FORTRAN_ABSTRACT); 
         SgUntypedFunctionDeclaration(unsigned int numeric_label, SgToken::ROSE_Fortran_Keywords statement_enum); 
   };

class SgUntypedSubroutineDeclaration  : public SgUntypedDeclarationStatement
   {
     public: 
      virtual ~SgUntypedSubroutineDeclaration() {}
      SgUntypedSubroutineDeclaration(Sg_File_Info* startOfConstruct , unsigned int numeric_label = 0, SgToken::ROSE_Fortran_Keywords statement_enum = SgToken::FORTRAN_ABSTRACT); 
      SgUntypedSubroutineDeclaration(unsigned int numeric_label, SgToken::ROSE_Fortran_Keywords statement_enum); 
      // CER
      SgUntypedSubroutineDeclaration(std::string str_label, SgToken::ROSE_Fortran_Keywords statement_enum)
         : SgUntypedDeclarationStatement(str_label, statement_enum)
         {
            p_begin_stmt = NULL;
            p_end_stmt = NULL;
            p_spec_part_list = NULL;
            p_exec_part_list = NULL;
            p_subprogram_part_list = NULL;
         }

      // CER
      void set_begin_statement(SgUntypedStatement* stmt) {p_begin_stmt = stmt;}
      void set_end_statement  (SgUntypedStatement* stmt) {p_end_stmt   = stmt;}

      std::vector<SgUntypedStatement*>* get_spec_part_list() {return p_spec_part_list;}
      std::vector<SgUntypedStatement*>* get_exec_part_list() {return p_exec_part_list;}

      void set_spec_part_list (std::vector<SgUntypedStatement*>* list) {p_spec_part_list = list;}
      void set_exec_part_list (std::vector<SgUntypedStatement*>* list) {p_exec_part_list = list;}
      // CER - TODO - don't know what type this is (statement list?)
      void set_subprogram_part(std::vector<SgUntypedStatement*>* list) {p_subprogram_part_list = list;}

     protected:
      SgUntypedStatement* p_begin_stmt;
      SgUntypedStatement* p_end_stmt;
      std::vector<SgUntypedStatement*>* p_spec_part_list;
      std::vector<SgUntypedStatement*>* p_exec_part_list;
      std::vector<SgUntypedStatement*>* p_subprogram_part_list;
   };

class SgUntypedAssignmentStatement  : public SgUntypedStatement
   {
     public: 
         virtual ~SgUntypedAssignmentStatement() {}
         SgUntypedAssignmentStatement(Sg_File_Info* startOfConstruct , unsigned int numeric_label = 0, SgToken::ROSE_Fortran_Keywords statement_enum = SgToken::FORTRAN_ABSTRACT); 
         SgUntypedAssignmentStatement(unsigned int numeric_label, SgToken::ROSE_Fortran_Keywords statement_enum); 
         // TODO - CER
         SgUntypedAssignmentStatement(std::string str_label, SgUntypedExpression* lhs, SgUntypedExpression* rhs)
            {
               // TODO - what about statement_enum?
               p_string_label = str_label;
               p_lhs = lhs;
               p_rhs = rhs;
            }

         virtual SgNodeType typeId() {return T_UntypedAssignmentStmt;}

         // TODO - CER
         SgUntypedExpression* get_lhs() {return p_lhs;}
         SgUntypedExpression* get_rhs() {return p_rhs;}

     // TODO - CER
     protected:
         SgUntypedExpression* p_lhs;
         SgUntypedExpression* p_rhs;
   };

class SgUntypedFunctionCallStatement  : public SgUntypedStatement
   {
     public: 
         virtual ~SgUntypedFunctionCallStatement();
         SgUntypedFunctionCallStatement(Sg_File_Info* startOfConstruct , unsigned int numeric_label = 0, SgToken::ROSE_Fortran_Keywords statement_enum = SgToken::FORTRAN_ABSTRACT); 
         SgUntypedFunctionCallStatement(unsigned int numeric_label, SgToken::ROSE_Fortran_Keywords statement_enum); 
   };

// TODO - CER
class SgUntypedInitializedName  : public SgUntypedExpression
   {
     public: 
         virtual ~SgUntypedInitializedName() {}
         SgUntypedInitializedName(Sg_File_Info* startOfConstruct ); 
         SgUntypedInitializedName();
         // TODO - CER         
         SgUntypedInitializedName(const char* pname) : name(pname) {}

         const std::string& getName() {return name;}

    protected:
         std::string name;
   };

// CER
class SgUntypedBlockStatement  : public SgUntypedStatement
   {
     public: 
        virtual ~SgUntypedBlockStatement();
        SgUntypedBlockStatement(Sg_File_Info* startOfConstruct , unsigned int numeric_label = 0, SgToken::ROSE_Fortran_Keywords statement_enum = SgToken::FORTRAN_ABSTRACT); 
        // CER  SgUntypedBlockStatement(Sg_File_Info* startOfConstruct , std::string numeric_label = 0, SgToken::ROSE_Fortran_Keywords statement_enum = SgToken::FORTRAN_ABSTRACT, std::vector<SgUntypedStatement*> statement_list );
        SgUntypedBlockStatement(unsigned int numeric_label, SgToken::ROSE_Fortran_Keywords statement_enum); 
        SgUntypedBlockStatement(std::string numeric_label, SgToken::ROSE_Fortran_Keywords statement_enum, std::vector<SgUntypedStatement*> statement_list);

        std::vector<SgUntypedStatement*> get_statement_list();
        void set_statement_list (std::vector<SgUntypedStatement*> s);

     protected:
         std::vector<SgUntypedStatement*> statement_list;

   };
