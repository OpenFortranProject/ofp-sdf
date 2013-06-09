#include "traversal.h"

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[])
{
   ATbool success;
   ATerm term;
   OFP_Traverse StartCommentBlock_opt, Program;
   
   if (argc < 2) {
      fprintf(stderr, "usage: traverse filename\n");
      exit(-1);
   }

   FILE * file = fopen(argv[1], "r");
   if (file == NULL) {
      fprintf(stderr, "Failed to open file\n");
      exit(-1);
   }

   ATinitialize(argc, argv); 

   term = ATreadFromTextFile(file);

   printf("\n%s\n\n", ATwriteToString(term));

   success = ofp_traverse_Program(term, &StartCommentBlock_opt, &Program);

   if (success) printf("\nWoot!\n");

   return 0;
}
