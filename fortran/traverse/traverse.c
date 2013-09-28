#include "traversal.h"

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[])
{
   OFP_Traverse Program;
   
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

   if (ofp_traverse_init() != ATtrue) exit(1);

   Program.term = ATreadFromTextFile(file);

   printf("\n%s\n\n", ATwriteToString(Program.term));

   if (ofp_traverse_Program(Program.term, &Program)) {
      printf("\nWoot!\n");
   } else return 1;

   return 0;
}
