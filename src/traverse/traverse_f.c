#include "traversal_f.h"

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[])
{
   OFP_Traverse Module;
   
   if (argc < 2) {
      fprintf(stderr, "usage: traverse_f filename\n");
      exit(-1);
   }

   FILE * file = fopen(argv[1], "r");
   if (file == NULL) {
      fprintf(stderr, "Failed to open file\n");
      exit(-1);
   }

   ATinitialize(argc, argv); 

   Module.term = ATreadFromTextFile(file);

   printf("\n%s\n\n", ATwriteToString(Module.term));

   if (ofp_traverse_Module(Module.term, &Module)) {
      printf("\nWoot!\n");
   } else return 1;

   return 0;
}
