#ifndef	OFP_TRAVERSAL_H
#define	OFP_TRAVERSAL_H

#include <aterm2.h>

typedef struct OFP_Traverse_struct
{
   ATerm       term;
   void*       pre;
   void*       post;

}
   OFP_Traverse, * pOFP_Traverse;

ATbool ofp_traverse_Module(ATerm term, pOFP_Traverse Module);

#endif
