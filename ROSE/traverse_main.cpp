#include <aterm2.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>

//#include "SgUntypedNodes.hpp"
#include "traverse_SgUntypedNodes.hpp"

#define PRINT_DEBUG

//ATbool ofp_traverse_init();

int main(int argc, char * argv[])
{
   SgUntypedFile* SgUntypedFile;
   ATerm SgUntypedFile_term;

   FILE * file = stdin;
   
   for (int i = 1; i < argc; i++) {
      std::string arg = argv[i];
      if (arg == "-i") {
         file = fopen(argv[++i], "r");
      }
      if (file == NULL) {
         fprintf(stderr, "ERROR: Unable to open file %s\n", argv[i]);
         exit(-1);
      }
   }
   if (file == NULL) {
      fprintf(stderr, "WARNING: Input file not specified\n");
      exit(-1);
   }

   ATinitialize(argc, argv);

   //   if (ofp_traverse_init() != ATtrue) exit(1);

   SgUntypedFile_term = ATreadFromTextFile(file);

#ifdef PRINT_DEBUG
   printf("\n%s\n\n", ATwriteToString(SgUntypedFile_term));
#endif

   if (traverse_SgUntypedFile(SgUntypedFile_term, &SgUntypedFile) != ATtrue) {
      printf("..............\nFAILED: traverse_main: SgUntypedFile == %p\n\n", SgUntypedFile);
      return 1;
   }

   if (SgUntypedFile != NULL) {
#ifdef NO_NO_NO
      printf("..............\ntraverse_main: SgUntypedFile == %p  global scope ==%p\n\n",
             SgUntypedFile, SgUntypedFile->p_SgUntypedGlobalScope);
#endif
   } else {
      printf("..............\ntraverse_main: SgUntypedFile == %p\n\n", SgUntypedFile);
   }

#ifdef NOT_YET
   delete SgUntypedFile;
#endif

   return 0;
}
