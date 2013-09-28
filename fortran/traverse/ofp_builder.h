#ifndef OFP_BUILDER_H
#define OFP_BUILDER_H

ATbool        ofp_isStringType(ATerm term);
ATbool        ofp_isIdentType(ATerm term);
enum DataType ofp_getDataType(ATerm term);
ATbool        ofp_isPrimitiveType(ATerm term);
ATermList     ofp_coalesceAliasTable(ATermList table);
ATbool        ofp_traverse_Module(ATerm term, pOFP_Traverse Module);
ATbool        ofp_traverse_Signature(ATerm term, pOFP_Traverse Signature);
ATbool        ofp_traverse_init();

#endif // OFP_BUILDER_H
