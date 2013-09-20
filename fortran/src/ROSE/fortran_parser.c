#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[])
{
   int i, err;
   char cmd[256], parse_table[128];

   parse_table[0] = '\0';

   if (argc < 4) {
      printf("usage: fortran_parser --parseTable parse_table_path filename(s)\n");
      return 1;
   }

   /* Parse each filename (args not associated with "--parseTable", "--" or "-I")
    */
   for (i = 1; i < argc; i++) {
      if (strncmp(argv[i], "--parseTable", 12) == 0) {
         sprintf(parse_table, "%s", argv[i+1]);
         i += 1;
         continue;
      }
      else if (strncmp(argv[i], "--", 2) == 0) {
         /* skip args that are not files
          */
         i += 1;
         continue;
      }
      else if (strncmp(argv[i], "-I", 2) == 0) {
         /* Skip the include dir stuff; it's handled by the lexer. */
         /* TODO - not currently true, so skip arg for now? */
         i += 1;
         continue;
      }

      /* make sure there is a parse table
       */
      if (parse_table[0] == '\0') {
         fprintf(stderr, "fortran_parser: no parse table provided, use option --parseTable\n");
         return -1;
      }

      /* parse the file
       */
      sprintf(cmd, "sglri -p %s -i %s -o %s.ptree", parse_table, argv[i], argv[i]);
      err = system(cmd);
      if (err) {
         fprintf(stderr, "fortran_parser: error parsing file %s\n", argv[i]);
         return err;
      }
   }

   return 0;
}
