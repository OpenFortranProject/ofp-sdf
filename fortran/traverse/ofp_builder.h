#ifndef OFP_BUILDER_H
#define OFP_BUILDER_H

#include "traversal.h"

// global variables
//
FILE * fpc;
FILE * fph;

/* Table for storing productions (prodName, [(consName, [symType]]) */
ATermList gProdTable;

ATbool        ofp_isStringType(ATerm term);
ATbool        ofp_isIdentType(ATerm term);
enum DataType ofp_getDataType(ATerm term);
ATbool        ofp_isPrimitiveType(ATerm term);
ATermList     ofp_coalesceAliasTable(ATermList table);

ATbool        ofp_traverse_Module(ATerm term, pOFP_Traverse Module);
ATbool        ofp_traverse_Signature(ATerm term, pOFP_Traverse Signature);

ATbool        ofp_traverse_init();
ATbool        ofp_traverse_finalize();

// build functions
//
ATermList     ofp_build_production_table(ATerm term);
ATermList     ofp_coalesceProdTable(ATermList table);

ATbool        ofp_build_match_terminal           (ATerm terminal);
ATbool        ofp_build_match_begin              (ATerm symbol);
ATbool        ofp_build_match_end                (ATerm symbol);
ATbool        ofp_build_match_nonterminal_begin  (ATerm constructor, ATerm symbol);
ATbool        ofp_build_match_nonterminal_end    (ATerm constructor, ATerm symbol);

ATbool        ofp_build_traversal_string_match(ATerm name);

ATbool        ofp_build_traversal_func_begin    (ATerm name);
ATbool        ofp_build_traversal_func_end      (ATerm name, ATbool returnTrue);
ATbool        ofp_build_traversal_nonterminal   (ATerm symbol);
ATbool        ofp_build_traversal_nonterminals  (ATerm name, ATermList prod_symbols);
ATbool        ofp_build_traversal_nonterminal_common  (ATerm symbol, ATerm prod_symbol);
ATbool        ofp_build_traversal_nonterminals_common (ATerm symbol, ATerm constructor, ATermList prod_symbols);
ATbool        ofp_build_string_traversal        (ATerm type, ATerm name);
ATbool        ofp_build_list_traversal          (ATerm name);

#endif // OFP_BUILDER_H